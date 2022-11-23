#define _USE_MATH_DEFINES

#include <bits/stdc++.h>

using namespace std;

class maxHeap<int>
{
    private:
        vector<int> elements;
    int size = 0;
    public:
        Add(int value)
        {
            int len = elements.size();
            elements.push_back(value);
            int cur = len;
            while(true)
            {
                if(cur==0)
                {
                    return;
                }

                int parent = (cur-1)/2;
                if(elements.at(cur) > elements.at(parent))
                {
                    int bla =  elements.at(cur);
                    elements.at(cur) = elements.at(parent);
                    elements.at(parent) = bla;
                    cur = parent;
                }
            }
        }
        Remove(int value)
        {

        }
};
