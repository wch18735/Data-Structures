#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first > b.first;
}

int main(void) {
	vector<pair<int, string>> v;

	// int���� �������� ������ �̷���
	// vector�� ������� List
	// vector.push_back -> Vector list�� �߰��ϴ� ��
	v.push_back(pair<int, string>(90, "��öȲ"));
	v.push_back(pair<int, string>(85, "������"));
	v.push_back(pair<int, string>(82, "������"));
	v.push_back(pair<int, string>(98, "������"));
	v.push_back(pair<int, string>(79, "�ڽ���"));
	
	// vector �� ���۰� ������ sort
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
		// second: pair �� �� ��°
	}
}