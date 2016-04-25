#include <iostream>
#include <vector>

using namespace std;

class Partition {
public:
	vector<int> getPartition(const vector<vector<int> >& land, int n, int m) {
		vector<int> t, res; // count 1
		int cnt = 0; // total 0
		for (int i = 0; i < n; ++i) {
			int cnt_tmp = 0;
			for (int j = 0; j < m; ++j) {
				if (land[j][i] == 0) {
					cnt++;
					cnt_tmp++;
				}
			}
			t.push_back(cnt_tmp);
		}
		int ind = 0;
		int count = cnt;
		for (int i = 0; i < n; ++i) {
			count += m - 2 * t[i]; // 加1数量,减0数量
			if (count < cnt) {
				ind = i + 1;
				cnt = count;
			}
		}
		res.push_back(ind);
		res.push_back(ind + 1);
		return res;
	}
};

int main(){
	Partition obj;
	vector<int> ret;
	vector<vector<int> > land={{0,0,1,1}, {0,1,0,0}, {0,0,1,1}};
	ret = obj.getPartition(land, 4, 3);
	vector<int>::iterator wrap_iter;
	for (auto wrap_iter = ret.begin(); wrap_iter != ret.end(); ++wrap_iter) {
		cout << *wrap_iter<<endl;
	}
}
