#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first > b.first) return false;
    else if(a.first < b.first) return true;
    else if(a.first==b.first) return (a.second < b.second);
}

int simpleD(pair<int, int>a, pair<int, int> b) {
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second-b.second);
}

int main(void) {
    vector<pair<int, int> > v;
    int x, y;
    int caseN;
    int d[6];
    bool isSquare;
    cin >> caseN;
    for(int i=0; i<caseN; i++) {
        isSquare=0;
        for(int j=0; j<4; j++) {
            cin >> x >> y;
            v.push_back(pair<int, int>(x, y));
        }
        sort(v.begin(), v.end(), compare);
        d[0] = simpleD(v[0],v[1]);
        d[1] = simpleD(v[1],v[3]);
        d[2] = simpleD(v[3],v[2]);
        d[3] = simpleD(v[2],v[0]);
        d[4] = simpleD(v[1],v[2]);
        d[5] = simpleD(v[0],v[3]);
        if(d[0]==d[1] && d[1]==d[2] && d[2]==d[3] && d[4]== d[5])
            isSquare = 1;
        cout << isSquare <<endl;
        v.clear();
    }
}
