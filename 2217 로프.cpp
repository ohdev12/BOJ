#include <iostream>
#include <algorithm>
#define INF 10001

using namespace std;

int main(void) {
    int ropeN;
    int* ropes;
    int biggest;
    cin >> ropeN;
    ropes = new int[ropeN+1];
    ropes[0] = INF;
    for(int i=1; i<=ropeN; i++)
        cin >> ropes[i];
    sort(ropes, ropes+ropeN+1, greater<int>());
    biggest = ropes[1];
    for(int i=2; i<=ropeN; i++) {
        if(biggest < ropes[i]*i) biggest = ropes[i]*i;
    }
    cout << biggest <<endl;
    return 0;
}
