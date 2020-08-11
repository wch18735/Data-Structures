#include <stdio.h>

// QuickSort() �� ������ ����Լ��� �̿�
// �־��� ��� n^2 �� �� �� ���� (������ �̹� �Ǿ��ִ� ���)

int numArr[10] = { 3,7,8,1,5,9,6,10,2,4 };

void quickSort(int *data, int start, int end) {
	if (start >= end) { // ���Ұ� �� ���� ���
		return;
	}

	int key = start;
	int i = start + 1; // ���� �������
	int j = end; // ������ �������

	int tmp;

	while (i <= j) { // �������� ���� ������
		while (data[i] <= data[key]) { //key ������ ū �� ã�� ������
			i++;
		}
		while (data[j] >= data[key] && j > start) { //key ������ ���� �� ã�� ������
			j--;
		}
		if (i > j) { // �����ȴٸ�
			tmp = data[j];
			data[j] = data[key];
			data[key] = tmp;
		}
		else {
			tmp = data[j];
			data[j] = data[i];
			data[i] = tmp;
		}
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main() {
	quickSort(numArr, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d ", numArr[i]);
	}
}