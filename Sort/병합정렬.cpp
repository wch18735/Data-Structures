#include <stdio.h>

int number = 8;

int size;
int sorted[8];	// ���� �迭�� �ݵ�� ���� ������ ����
				// ���ʿ��� �޸� ��� ������
int count = 0;

void merge(int *a, int leftstart, int middle, int rightend) {
	// m: left start
	// n: right end
	// k: index of sorted array

	int left_idx = leftstart;
	int right_idx = middle + 1;
	int sorted_idx = leftstart;

	while (left_idx <= middle && right_idx <= rightend) {
		if (a[left_idx] <= a[right_idx]) {
			sorted[sorted_idx] = a[left_idx];
			left_idx++;
		}
		else {
			sorted[sorted_idx] = a[right_idx];
			right_idx++;
		}
		sorted_idx++;
	}

	// ���� ������ ����
	if (left_idx > middle) { // left is over
		for (int t = right_idx; t <= rightend; t++) {
			sorted[sorted_idx] = a[t];
			sorted_idx++;
		}
	}
	else {	// right is over
		for (int t = left_idx; t <= middle; t++) {
			sorted[sorted_idx] = a[t];
			sorted_idx++;
		}
	}

	// ���ĵ� �迭 ����
	for (int t = leftstart; t <= rightend; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	// ũ�Ⱑ 1���� ū ���
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main() {
	int numArr[8] = { 7,6,5,8,3,5,9,1 };
	mergeSort(numArr, 0, 7);
	for (int i = 0; i < 8; i++) {
		printf("%d ", numArr[i]);
	}
}