#include <string>
#include <set>
#include <vector>

#include "DynamicArray.h"

using namespace std;

#ifndef EVENT_H
#define EVENT_H

struct Event {
    int id;
    string sport;
    string date;
    string location;
    pair<string, string> teams;
    double baseTicketPrice = 10;
    double checkSeat(const string, const vector<string>);
    static Event parse(const string&);
};

class EventController {
    int numEvents = 0;
    DynamicArray<Event> events;
public:
    void loadEvents(const string&);
    set<int> getDates();
    vector<Event*> getEventsByDate(const string&);
    set<string> getLocations();
    vector<Event*> getEventsByLocation(const string&);
    set<string> getSports();
    vector<Event*> getEventsBySport(const string&);
    set<string> getAllTeams();
    vector<Event*> getEventsByTeam(const string& team);
    Event* getEventWithID(const int& id);

};
#endif //EVENT_H
