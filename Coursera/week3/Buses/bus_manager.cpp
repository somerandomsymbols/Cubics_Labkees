#include "bus_manager.h"

    void BusManager::AddBus(const string& bus, const vector<string>& stops)
    {
        BusManager::S[bus] = stops;

        for (string i : stops)
            BusManager::B[i].push_back(bus);
    }

    BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const
    {
        BusesForStopResponse x;

        if (BusManager::B.find(stop) != BusManager::B.end())
            x.B = get<1>(*BusManager::B.find(stop));
        else
            x.B = {"No stop"};

        return x;
    }

    StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const
    {
        StopsForBusResponse x;

        if (BusManager::S.find(bus) != BusManager::S.end())
        {
            for (string i : get<1>(*BusManager::S.find(bus)))
            {
                vector<string> h = get<1>(*BusManager::B.find(i));
                x.S.push_back({"Stop " + i + ":"});

                if (h.size() == 1)
                    x.S.back().push_back("no interchange");
                else
                    for (string j : h)
                        if (j != bus)
                            x.S.back().push_back(j);
            }

        }
        else
            x.S = {{"No bus"}};

        return x;
    }

    AllBusesResponse BusManager::GetAllBuses() const
    {
        AllBusesResponse x;

        if (BusManager::S.empty())
            x.B = {{"No buses"}};
        else
            for (pair<string, vector<string>> i : BusManager::S)
            {
                x.B.push_back({"Bus " + get<0>(i) + ":"});

                for (string j : get<1>(i))
                    x.B.back().push_back(j);
            }

        return x;
    }
