#include <boost/interprocess/managed_shared_memory.hpp>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cassert>
#include <utility>

#ifdef __unix__
#include <unistd.h>
#elif defined _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

using namespace std;

int main(int argc, char *argv[])
{
    using namespace boost::interprocess;

    if (argc == 1)
    {
        // Parent process
        // Remove shared memory on construction and destruction
        struct shm_remove
        {
            shm_remove() { shared_memory_object::remove("MySharedMemory"); }
            ~shm_remove() { shared_memory_object::remove("MySharedMemory"); }
        } remover;

        // Construct managed shared memory
        managed_shared_memory segment(create_only, "MySharedMemory", 65536);

        // Create an object of MyType initialized to 0
        cout << "Process 1: Initial value is 100" << endl;
        int *instance = segment.construct<int>("MyType instance") // name of the object
                        (100);                                    // ctor first argument

        // Launch child process
        string s(argv[0]);
        s += " child ";
        if (0 != system(s.c_str()))
            return 1;

        cout << "Process 1: Found updated value " << *instance << endl;

        // Check child has destroyed all objects
        if (segment.find<int>("MyType instance").first)
            return 1;
    }
    else
    {
        // Open managed shared memory
        managed_shared_memory segment(open_only, "MySharedMemory");

        pair<int *, managed_shared_memory::size_type> res;

        // Find the object
        res = segment.find<int>("MyType instance");
        // Length should be 1
        if (res.second != 1)
            return 1;

        cout << "Process 2: Found initial value " << *res.first << endl;
        *res.first = 200;
        cout << "Process 2: Updating value to " << *res.first << endl;

        // We're done, delete all the objects
        segment.destroy<int>("MyType instance");
    }

    return 0;
}