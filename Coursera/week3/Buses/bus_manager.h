#include "responses.h"

class BusManager
{
    map<string, vector<string>> B, S;

    public:

    void AddBus(const string& bus, const vector<string>& stops);

    BusesForStopResponse GetBusesForStop(const string& stop) const;

    StopsForBusResponse GetStopsForBus(const string& bus) const;

    AllBusesResponse GetAllBuses() const;
};

