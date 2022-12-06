/**
 * test program for our ProductServices
 */

#include <iostream>
#include "products.hpp"
#include "productservice.hpp"

using namespace std;

int main()
{
    // Create the 10Y treasury note
    date maturityDate(2025, Nov, 16);
    string cusip = "912828M56";
    Bond treasuryBond(cusip, CUSIP, "T", 2.25, maturityDate);

    // Create the 2Y treasury note
    date maturityDate2(2017, Nov, 5);
    string cusip2 = "912828TW0";
    Bond treasuryBond2(cusip2, CUSIP, "T", 0.75, maturityDate2);

    // Create a BondProductService
    BondProductService *bondProductService = new BondProductService();

    // Add the 10Y note to the BondProductService and retrieve it from the service
    bondProductService->Add(treasuryBond);
    Bond bond = bondProductService->GetData(cusip);
    cout << "CUSIP: " << bond.GetProductId() << " ==> " << bond << endl;

    // Add the 2Y note to the BondProductService and retrieve it from the service
    bondProductService->Add(treasuryBond2);
    bond = bondProductService->GetData(cusip2);
    cout << "CUSIP: " << bond.GetProductId() << " ==> " << bond << endl;

    // Create the Spot 10Y Outright Swap
    date effectiveDate(2015, Nov, 16);
    date terminationDate(2025, Nov, 16);
    string outright10Y = "Spot-Outright-10Y";
    IRSwap outright10YSwap(outright10Y, THIRTY_THREE_SIXTY, THIRTY_THREE_SIXTY, SEMI_ANNUAL, LIBOR, TENOR_3M, effectiveDate, terminationDate, USD, 10, SPOT, OUTRIGHT);

    // Create the IMM 2Y Outright Swap
    date effectiveDate2(2015, Dec, 20);
    date terminationDate2(2017, Dec, 20);
    string imm2Y = "IMM-Outright-2Y";
    IRSwap imm2YSwap(imm2Y, THIRTY_THREE_SIXTY, THIRTY_THREE_SIXTY, SEMI_ANNUAL, LIBOR, TENOR_3M, effectiveDate2, terminationDate2, USD, 2, IMM, OUTRIGHT);

    // Create a IRSwapProductService
    IRSwapProductService *swapProductService = new IRSwapProductService();

    // Add the Spot 10Y Outright Swap to the IRSwapProductService and retrieve it from the service
    swapProductService->Add(outright10YSwap);
    IRSwap swap = swapProductService->GetData(outright10Y);
    cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;

    // Add the IMM 2Y Outright Swap to the IRSwapProductService and retrieve it from the service
    swapProductService->Add(imm2YSwap);
    swap = swapProductService->GetData(imm2Y);
    cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;

    // Create the SPX DEC future
    date maturityDateDec(2022, Dec, 16);
    string cusip3 = "912828F56";
    string ticker = "SPX DEC22 FUT";
    Future futurespx(cusip3, ticker, "SPX", 100, maturityDateDec, USD);

    // Create the NDX DEC future
    string cusip4 = "912828F57";
    string ticker2 = "NDX DEC22 FUT";
    Future futurendx(cusip4, ticker2, "NDX", 100, maturityDateDec, USD);

    // Create the DJI DEC future
    string cusip5 = "912828F58";
    string ticker3 = "DJI DEC22 FUT";
    Future futuredji(cusip5, ticker3, "DJI", 100, maturityDateDec, USD);

    // Create a FutureProductService
    FutureProductService *futureProductService = new FutureProductService();

    // 2)a) Write a Future class in the same way we have a Bond and IRSwap class (products.zip attached to the homework thread on the forum). Also write a FutureProductService like a BondProductService and IRSwapProductService with an example test program to retrieve three futures.
    cout << "2)a) Write a Future class in the same way we have a Bond and IRSwap class (products.zip attached to the homework thread on the forum). Also write a FutureProductService like a BondProductService and IRSwapProductService with an example test program to retrieve three futures." << endl;
    // Add the SPX DEC futures contract to the FutureProductService and retrieve it from the service
    futureProductService->Add(futurespx);
    Future future = futureProductService->GetData(cusip3);
    cout << "TICKER: " << future.GetTicker() << " ==> " << future << endl;

    // Add the NDX DEC futures contract to the FutureProductService and retrieve it from the service
    futureProductService->Add(futurendx);
    future = futureProductService->GetData(cusip4);
    cout << "TICKER: " << future.GetTicker() << " ==> " << future << endl;

    // Add the DJI DEC futures contract to the FutureProductService and retrieve it from the service
    futureProductService->Add(futuredji);
    future = futureProductService->GetData(cusip5);
    cout << "TICKER: " << future.GetTicker() << " ==> " << future << endl;
    cout << endl
         << endl
         << endl;

    // 2)b) Add EuroDollarFuture and BondFuture as subclasses of Future.
    cout << "2)b) EuroDollarFuture and BondFuture subclasses added in the code." << endl;
    cout << endl
         << endl
         << endl;

    // 3)a) Get all Bonds with the specified ticker
    cout << "Testing 3)a): Get all Bonds with the specified ticker" << endl;
    string bondTicker = "T";
    vector<Bond> bondVector = bondProductService->GetBonds(bondTicker);
    if (bondVector.size() > 0)
        cout << "Found these bonds with ticker = " << bondTicker << endl;
    else
        cout << "Found no bonds with ticker = " << bondTicker << endl;

    for (Bond bv : bondVector)
        cout << "CUSIP: " << bond.GetProductId() << " ==> " << bond << endl;
    cout << endl
         << endl
         << endl;

    // 3)b)i) Get all Swaps with the specified fixed leg day count convention
    cout << "Testing 3)b)i): Get all Swaps with the specified fixed leg day count convention" << endl;
    DayCountConvention fixedLegDayCountConvention = THIRTY_THREE_SIXTY;
    vector<IRSwap> IRswapVector = swapProductService->GetSwaps(fixedLegDayCountConvention);
    if (IRswapVector.size() > 0)
        cout << "Found these IRSwaps with fixed leg day count convention = " << fixedLegDayCountConvention << endl;
    else
        cout << "Found no bonds with fixed leg day count convention = " << fixedLegDayCountConvention << endl;

    for (IRSwap swap : IRswapVector)
        cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;
    cout << endl
         << endl
         << endl;

    // 3)b)ii) Get all Swaps with the specified fixed leg payment frequency
    cout << "Testing 3)b)ii): Get all Swaps with the specified fixed leg payment frequency" << endl;
    PaymentFrequency fixedLegPaymentFrequency = SEMI_ANNUAL;
    IRswapVector = swapProductService->GetSwaps(fixedLegPaymentFrequency);
    if (IRswapVector.size() > 0)
        cout << "Found these IRSwaps with fixed leg payment frequency = " << fixedLegPaymentFrequency << endl;
    else
        cout << "Found no bonds with fixed leg payment frequency = " << fixedLegPaymentFrequency << endl;

    for (IRSwap swap : IRswapVector)
        cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;
    cout << endl
         << endl
         << endl;

    // 3)b)iii) Get all Swaps with the specified floating index
    cout << "Testing 3)b)iii): Get all Swaps with the specified floating index" << endl;
    FloatingIndex floatingIndex = LIBOR;
    IRswapVector = swapProductService->GetSwaps(floatingIndex);
    if (IRswapVector.size() > 0)
        cout << "Found these IRSwaps with floating index = " << floatingIndex << endl;
    else
        cout << "Found no bonds with floating index = " << floatingIndex << endl;

    for (IRSwap swap : IRswapVector)
        cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;
    cout << endl
         << endl
         << endl;

    // 3)b)iv) Get all Swaps with a term in years greater than the specified value
    cout << "Testing 3)b)iv): Get all Swaps with a term in years greater than the specified value" << endl;
    int termYears = 3;
    IRswapVector = swapProductService->GetSwapsGreaterThan(termYears);
    if (IRswapVector.size() > 0)
        cout << "Found these IRSwaps with term greater than " << termYears << "y" << endl;
    else
        cout << "Found no IRSwaps with term greater than " << termYears << "y" << endl;

    for (IRSwap swap : IRswapVector)
        cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;
    cout << endl
         << endl
         << endl;

    // 3)b)v) Get all Swaps with a term in years less than the specified value
    cout << "Testing 3)b)v): Get all Swaps with a term in years less than the specified value" << endl;
    termYears = 9;
    IRswapVector = swapProductService->GetSwapsLessThan(termYears);
    if (IRswapVector.size() > 0)
        cout << "Found these IRSwaps with term less than " << termYears << "y" << endl;
    else
        cout << "Found no IRSwaps with term less than " << termYears << "y" << endl;

    for (IRSwap swap : IRswapVector)
        cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;
    cout << endl
         << endl
         << endl;

    // 3)b)vi) Get all Swaps with the specified swap type
    cout << "Testing 3)b)vi): Get all Swaps with the specified swap type" << endl;
    SwapType swapType = SPOT;
    IRswapVector = swapProductService->GetSwaps(swapType);
    if (IRswapVector.size() > 0)
        cout << "Found these IRSwaps with swap type = " << swapType << endl;
    else
        cout << "Found no bonds with swap type = " << swapType << endl;

    for (IRSwap swap : IRswapVector)
        cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;
    cout << endl
         << endl
         << endl;

    // 3)b)vii) Get all Swaps with the specified swap leg type
    cout << "Testing 3)b)vii): Get all Swaps with the specified swap leg type" << endl;
    SwapLegType swapLegType = OUTRIGHT;
    IRswapVector = swapProductService->GetSwaps(swapLegType);
    if (IRswapVector.size() > 0)
        cout << "Found these IRSwaps with swap leg type = " << swapLegType << endl;
    else
        cout << "Found no bonds with swap leg type = " << swapLegType << endl;

    for (IRSwap swap : IRswapVector)
        cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;
    cout << endl
         << endl
         << endl;

    cout << "All done!!!!!" << endl;
    return 0;
}
