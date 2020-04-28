#include "query.h"

istream& operator >> (istream& is, Query& q)
{
    string s;
    is >> s;

    if (s == "ALL_BUSES")
        q.type = QueryType::AllBuses;
    else if (s == "STOPS_FOR_BUS")
        q.type = QueryType::StopsForBus;
    else if (s == "BUSES_FOR_STOP")
        q.type = QueryType::BusesForStop;
    else
        q.type = QueryType::NewBus;

    if (q.type == QueryType::BusesForStop)
        is >> q.stop;
    else if (q.type == QueryType::StopsForBus)
        is >> q.bus;
    else if (q.type == QueryType::NewBus)
    {
        int c;
        string s;
        is >> q.bus >> c;
        q.stops.clear();

        for (int i = 0; i < c; ++i)
            is >> s,
            q.stops.push_back(s);
    }

    return is;
}
