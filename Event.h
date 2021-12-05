#include <string>
#include <set>
#include <vector>

#include "DynamicArray.h"

using namespace std;

#ifndef EVENT_H
#define EVENT_H

struct Event {
    string sport;
    string date;
    string location;
    pair<string, string> teams;
public:
    static Event parse(const string&);
};

struct Ticket{
    string confirmation;
    string seat;
    Event event;
};

class EventController {
    int numEvents = 0;
    DynamicArray<Event> events;
public:
    void loadEvents(const string&);
    set<string> getLocations();
    vector<Event> getEventsByLocation(const string&);
    set<string> getSports();
    vector<Event> getEventsBySport(const string&);
    set<string> getAllTeams();
    vector<Event> getEventsByTeam(const string& team);
};
#endif //EVENT_H