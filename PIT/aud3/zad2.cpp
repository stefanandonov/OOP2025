//
// Created by Stefan Andonov on 12.3.25.
//

#include<iostream>
#include <cstring>

using namespace std;

class Team {
private:
    char name[50];
    char city[50];
    int foundingYear;
public:
    Team(char *_name = "name", char *_city = "city", int _foundingYear = 2000) {
        strcpy(name, _name);
        strcpy(city, _city);
        foundingYear = _foundingYear;
    }

    void print() {
        cout << "Team: " << name << " - " << city << " (" << foundingYear << ")" << endl;
    }

    bool isEqual(const Team other) const {
//        return name == other.name; //NOT CORRECT - sporeduva memoriski adresi na dvete nizi od znaci
        return strcmp(name, other.name) == 0;
    }
};

class Match {
private:
    Team home;
    Team away;
    int homeGoals;
    int awayGoals;
public:
    Match(Team _home, Team _away, int _homeGoals, int _awayGoals) {
        home = _home;
        away = _away;
        homeGoals = _homeGoals;
        awayGoals = _awayGoals;
    }

    void print() {
        cout << "Match between:" << endl;
        home.print();
        cout << " & " << endl;
        away.print();
        cout << "Result - " << homeGoals << ":" << awayGoals << endl;
    }

    const Team &getHome() const {
        return home;
    }

    const Team &getAway() const {
        return away;
    }

    int getHomeGoals() const {
        return homeGoals;
    }

    int getAwayGoals() const {
        return awayGoals;
    }

};

bool isRematch(const Match m1, const Match m2) {
    return m1.getHome().isEqual(m2.getAway())
           && m1.getAway().isEqual(m2.getHome());
}

int main() {
    Team team; // default constructor
    team.print();


    Team team1("Barca", "Barcelona", 1899);
    Team team2("Real Madrid ", "Madrid", 1902);

    Team team3 ("Chelsea", "London", 1900);
    Match match1(team1, team2, 5, 2);
    Match match2(team2, team3, 5, 4);

    match1.print();
    match2.print();

    cout << isRematch(match1, match2);
    return 0;
}

