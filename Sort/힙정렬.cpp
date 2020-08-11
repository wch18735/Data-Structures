#include <stdio.h>

// First, Tree -> Binary Tree -> Complete Binary Tree
// Second, apply Heapify Algorithm
// Height Heapify algorithm Complexity: (log_2)N
// Number of node: N
// so, Actual Complexity is N/2*(log_2)N -> O(N*log(N))

// �޸� ���鿡�� �������ĺ��� ȿ����
// �׻� O(N*log_2_^N)�� ������ 

int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void) {
	// �ִ� �� ������ ����� ����
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) { 
				// root < child
				// swap root and child
				int tmp = heap[c];
				heap[c] = heap[root];
				heap[root] = tmp;
			}
			c = root;
		} while (c != 0);
	}

	// ũ�⸦ ���̸� �ݺ������� �� ����
	for (int i = number - 1; i >= 0; i--) {
		// i: right endline 
		// ��ȯ
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;

		int root = 0;
		int c = 1;
		do {
			// root * 2 + 1 -> left child node
			c = 2 * root + 1;

			// �ڽ� ��
			if (heap[c] < heap[c + 1] && c < i-1) {
				c++;
			}
			// �ڽ� �� ū ���� �θ�� �� �� �ڽ��� ũ�� swap
			if (heap[root] < heap[c] && c < i) {
				int tmp = heap[c];
				heap[c] = heap[root];
				heap[root] = tmp;
			}

			// �ٲ� ���κ��� right endline ���� Heapify ����
			root = c;
		} while (c < i);
	}

	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}