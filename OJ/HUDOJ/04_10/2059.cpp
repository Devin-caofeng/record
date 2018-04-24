#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int L;
    int charge_cnt, dist, charge_time;
    int rabbit_race, car_race, bike_race;
    cin >> L
        >> charge_cnt >> dist >> charge_time
        >> rabbit_race >> car_race >> bike_race;
    vector<int> charge_pos(charge_cnt);
    for (int i = 0; i < charge_cnt; ++i) cin >> charge_pos[i];

    int rabbit_time = L / rabbit_race;
    int tortoise_time = 0;

    for (int tort_pos = 0; tort_pos < L; ) {
        tort_pos += dist;
    }

    if (rabbit_time > tortoise_time) {
        cout << "What a pity rabbit!\n";
    }
    else {
        cout << "Good job,rabbit!\n";
    }

    return 0;
}
