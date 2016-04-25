#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	char tmp[1024];
	sprintf(tmp, "%d", b);
	string str(tmp);
	bool flag = true;
	int ret = 0;
	while (flag) {
		a++;
		ret = a;
		char temp[1024];
		sprintf(temp, "%d", ret);
		string s(temp);
		string vin = s.c_str();
		bool flagtmp = true;
		for (int i = 0; i < str.size(); i++){
			string::size_type idx = vin.find(str[i]);
			if (idx == string::npos) {
				flagtmp = false;
				break;
			}
		}
		if (flagtmp == false) continue;
		else flag = false;
	}
	cout << ret << endl;
}
