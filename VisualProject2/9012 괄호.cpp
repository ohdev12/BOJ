#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	stack<int> st;
	int caseN;
	cin >> caseN;
	string str;
	bool no = false;
	for (int i = 0; i < caseN; i++) {
		no = false;
		cin >> str;
		while (!st.empty()) st.pop();
		for (int j = 0; j < str.length(); j++) {
			if(str[j]=='(') st.push(str[j]);
			else { // str[j] == '('
				if (st.empty()) {
					cout << "NO" << endl;
					no = true;
					break;
				}
				else st.pop();
			}
		}
		if (no) continue;
		if (!st.empty()) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}