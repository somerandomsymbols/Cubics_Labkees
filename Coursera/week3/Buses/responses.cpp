#include "responses.h"

BusesForStopResponse::BusesForStopResponse(){}

ostream& operator << (ostream& os, const BusesForStopResponse& r)
{
    for (string i : r.B)
        os << i << ' ';

    return os;
}

StopsForBusResponse::StopsForBusResponse(){}

ostream& operator << (ostream& os, const StopsForBusResponse& r)
{
    for (int i = 0; i < r.S.size(); ++i)
    {
        for (string j : r.S[i])
            os << j << ' ';

        os << endl;
    }

    return os;
}

AllBusesResponse::AllBusesResponse(){}

ostream& operator << (ostream& os, const AllBusesResponse& r)
{
    for (vector<string> i : r.B)
    {
        for (string j : i)
            os << j << ' ';

        os << endl;
    }

    return os;
}
