#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::pair;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main(void) {
    int totalCaseN;
    int numOfP;
    int s1, s2;
    int standard;
    int employed;
    cin >> totalCaseN;
    vector<pair<int, int> > v;
    for(int i=0; i<totalCaseN; i++) {
        employed=0;
        cin >> numOfP;
        for(int j=0; j<numOfP; j++) {
            cin >> s1 >> s2;
            v.push_back(pair<int, int>(s1, s2));
        }
        sort(v.begin(), v.end(), compare);
        standard = v[0].second;
        employed++;
        for(int j=1; j<numOfP; j++) {
            if(v[j].second < standard) {
                employed++;
                standard = v[j].second;
            }
        }
        cout << employed<<endl;
        v.clear();
    }
    return 0;
}
