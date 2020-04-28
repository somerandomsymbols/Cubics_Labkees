#include <bits/stdc++.h>

using namespace std;

struct BusesForStopResponse
{
    vector<string> B;

    BusesForStopResponse();
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse
{
    vector<vector<string>> S;

    StopsForBusResponse();
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse
{
    vector<vector<string>> B;

    AllBusesResponse();
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
