#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string s[8];
	while(1){
		int cntX = 0;
		int cnt0 = 0;
		cin>>s[0];
		cin>>s[1];
		cin>>s[2];
		// 先手/后手不固定走X或者0
		// 存储8条状态
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				s[i+3] += s[j][i];
				if(s[i][j] == 'X')
					cntX++;
				else if(s[i][j] == '0')
					cnt0++;
			}
		}
		for (int i = 0; i < 3; ++i) {
			s[6]+=s[i][i];
		}
		s[7] += s[0][2];
		s[7] += s[1][1];
		s[7] += s[2][0];
		// count XXX and 000
		int count = 0;
		for (int i = 0; i < 8; ++i) {
			string::size_type idxX = s[i].find( "XXX" );
			string::size_type idx0 = s[i].find( "000" );
			if ( idxX != string::npos || idx0 != string::npos )
			{
				count++;
			}
		}
		if(count >= 2)
			cout<<
//		for (int k = 0; k < 8; ++k) {
//			cout<<s[k]<<endl;
//		}
//		cout<<flag<<endl;
//		cout<<cntO<<endl;
//		cout<<cntX<<endl;
	}
	return 0;
}
