#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<string, pair<int, int>> a,
			 pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		// ������ ������ ������ � ���� �켱 ����
		// � -> �̾� �ٿ��� ��, �� ū ��
		return a.second.second > b.second.second;
	}
	else { // ������ �ٸ��� ���� ���� �켱 ����
		return a.second.first > b.second.first;
	}
}

int main(void) {
	// �̸�, ����, �������
	vector<pair<string,pair<int,int>>> v;

	v.push_back(pair<string, pair<int, int>>("��öȲ", pair<int, int>(95, 19960131)));
	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(98, 19930518)));
	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(95, 19930203)));
	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(90, 19921107)));
	v.push_back(pair<string, pair<int, int>>("�ڽ���", pair<int, int>(88, 19900302)));


	// vector �� ���۰� ������ sort
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
		// second: pair �� �� ��°
	}
}