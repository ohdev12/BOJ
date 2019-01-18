#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void makePw(string current, char* alphs, int fIndex, int eIndex, int len_rem) {
	if (fIndex > eIndex) return;
	if (len_rem == 1 && eIndex - fIndex >= 0) {
		for (int i = fIndex; i <= eIndex; i++) {
			string res = current + alphs[i];
			int len = res.length();
			int ja = 0;
			int mo = 0;
			for (int j = 0; j < len; j++) {
				if (res[j] == 'a' || res[j] == 'e' || res[j] == 'i' || res[j] == 'o' || res[j] == 'u') mo++;
				else ja++;
			}
			if(mo>=1 && ja>=2) cout << current+alphs[i] << endl;
		}
		return;
	}
	makePw(current + alphs[fIndex], alphs, fIndex + 1, eIndex, len_rem - 1);
	makePw(current, alphs, fIndex + 1, eIndex, len_rem);
}

int main(void) {
	int length, alphN;
	char* alphabets;
	cin >> length >> alphN;
	alphabets = new char[alphN];
	for (int i = 0; i<alphN; i++)
		cin >> alphabets[i];
	sort(alphabets, alphabets + alphN);
	makePw("", alphabets, 0, alphN - 1, length);
	delete(alphabets);
	return 0;
}
