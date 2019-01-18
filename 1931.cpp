#include <iostream>
#include <algorithm>

using namespace std;

class Conference {
public:
    int beginT;
    int endT;
};

bool operator <(const Conference &a, const Conference &b) {
    if(a.endT < b.endT) return true;
    else if(a.endT == b.endT) return a.beginT < b.beginT;
    else return false;
}

//회의들을 끝나는 시간 순서대로 정렬하고/ 제일 빨리 끝나는 것부터 차례대로 이용
int main(void) {
    int numOfConf;
    int maxN=0;
    int curTime=0;
    cin >> numOfConf;
    Conference* confs = new Conference[numOfConf];
    for(int i=0; i<numOfConf; i++) {
        cin >> confs[i].beginT >> confs[i].endT;
    }
    sort(confs, confs+numOfConf);

    for(int i=0; i<numOfConf; i++) {
//        cout << confs[i].beginT <<" "<<confs[i].endT << endl;
        if(confs[i].beginT >= curTime) {
            maxN++;
            curTime = confs[i].endT;
        }
    }
    cout << maxN;
    return 0;
}
