/* Bubble Sort */
// ������ 2���� ���ڵ带 ���Ͽ� ������� �Ǿ� ���� ������ ���� ��ȯ�Ѵ�

/* ���� ���� �˰��� */
/*
	for i <- n-1 to 1 do			// ~���� �� index i�� 1�� �پ���
		for j<-0 to i-1 do
			j�� j+1 ��°�� ��Ұ� ũ�� ���� �ƴϸ� ��ȯ
			j++;
		i--;
*/

#include<stdio.h>
#include<stdlib.h>

#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void bubble_sort(int list[], int n) {
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
		}
	}
}

// �� Ƚ�� (�ֻ�, ���, �־��� ��� ��� ����)
// O(n**2)

// �̵� Ƚ��
// �������� ���ĵ� ���: 3*��Ƚ��
// �̹� ���ĵ� ���: 0
// ����� ���: O(n**2)

// ���ڵ��� �̵� ����
// �̵������� �񱳿��꺸�� �� ���� �ð��� �ҿ�ȴ�
