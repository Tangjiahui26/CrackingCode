#include <iostream>
#include <vector>

using namespace std;

class People {
public:
    int birthyear;
    int deathyear;
    People(int by, int dy){
        birthyear = by;
        deathyear = dy;
    }
};

// brute force
// runtime: O(YP)

int livingPeople(vector<People> people, int minyear, int maxyear){
    int maxAlive = 0;
    int maxAliveYear = minyear;

    for (int year = minyear; year <= maxyear; year++){
        int alive = 0;
        for (auto p : people){
            if (p.birthyear <= year && year <= p.deathyear) {
                alive++;
            }
        }

        if (alive > maxAlive){
            maxAlive = alive;
            maxAliveYear = year;
        }
    }
    return maxAliveYear;
}

// optimal
// runtime: O(nlogn)

vector<int> getSortedYears(vector<People> people, bool birthyearOrNot){
    vector<int> result;
    for (auto p : people){
        result.push_back(birthyearOrNot ? p.birthyear : p.deathyear);
    }
    sort(result.begin(), result.end());
    return result;
}

int livingPeopleOptimal(vector<People> people, int minyear, int maxyear){
    vector<int> births = getSortedYears(people, true);
    vector<int> deaths = getSortedYears(people, false);

    int birthIndex = 0;
    int deathIndex = 0;
    int currentlyAlive = 0;
    int maxAlive = 0;
    int maxAliveYear = minyear;

    while (birthIndex < births.size()){
        // less than or equals
        if (births[birthIndex] <= deaths[deathIndex]){
            currentlyAlive++;
        // update after currentlyAlive++ and before birthIndex++
            if (currentlyAlive > maxAlive){
                maxAlive = currentlyAlive;
                maxAliveYear = births[birthIndex];
            }
            birthIndex++;
        } else if (births[birthIndex] > deaths[deathIndex]){
            currentlyAlive--;
            deathIndex++;
        }
    }
    return maxAliveYear;
}

int main()
{
    vector<People> test = {People(1901, 1912), People(1912, 1913), People(1909, 1944)};
    cout << livingPeople(test, 1900, 2000) << endl;
    cout << livingPeopleOptimal(test, 1900, 2000) << endl;
    return 0;
}
