#include <iostream>
#include <string>
#include <algorithm> // ��ǥ���� STL

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) { // ������
		this->name = name;
		this->score = score;
	}
};

// ���� ������ "������ ���� ����"
bool compare(Student a, Student b) { 
	return a.score > b.score;
}

int main(void) {
	Student students[] = {
		Student(string::basic_string("��öȲ"),90),
		Student(string::basic_string("������"),93),
		Student(string::basic_string("������"),97),
		Student(string::basic_string("������"),87),
		Student(string::basic_string("������"),92)
	};

	sort(students, students + 5, compare);

	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}
