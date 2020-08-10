// ���� Ž��: ���ĵ� �迭�� �߾ӿ� �ִ� ���� �����Ͽ� ã���� �ϴ� �׸��� 
//			  ���� �Ǵ� ������ �κ� �迭�� �ִ����� �˾Ƴ��� Ž�� ������ ������ �ٿ����� Ž�� ����
// ���ĵ� �迭�� �����Ѵ�

// ex) 10�� �� �߿��� Ư�� �̸� Ž��
// ���� Ž���� ��� 5��� �ʿ��ѵ� ����Ž���� 30���̸� �ȴ�

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 10000000L
int list[MAX_ELEMENTS];
int count;	// ����Ƚ��

			//
			// ���� Ž��
			//
int binsearch(int list[], int n, int searchnum)
{
	int left = 0;
	int right = n - 1;
	int middle;

	count = 0;
	while (left <= right) {		// ���� ���ڵ��� ���� ������
		count++;
		middle = (left + right) / 2;
		if (searchnum == list[middle]) {
			return middle;
		}
		else if (searchnum < list[middle]) {
			right = middle - 1;
		}
		else {
			left = middle + 1; break;
		}
	}
	return -1;		// �߰ߵ��� ���� 
}

//
// ���� Ž��
//
int seqsearch(int list[], int n, int searchnum)
{
	int i;

	count = 0;
	for (i = 0; i<n; i++) {
		count++;
		if (searchnum == list[i])
			return i;
	}
	return -1;		// �߰ߵ��� ���� 
}

int search_binary2(int key, int low, int high)
{
	int middle;
	while (low <= high) { // ���� ���ڵ��� ���� ������
		middle = (low + high) / 2;
		if (key == list[middle]) return middle; // Ž�� ����
		else if (key > list[middle]) low = middle + 1; // ���� �κи���Ʈ Ž��
		else high = middle - 1; // ������ �κи���Ʈ Ž��
	}
	return -1; // Ž�� ����
}

int main()
{
	int i;
	int search_number;
	int return_value;
	clock_t start, finish;
	clock_t  duration;

	for (i = 0; i<MAX_ELEMENTS; i++)
		list[i] = i;

	printf("���ڸ� �Է��Ͻÿ�.\n", &search_number);
	scanf("%d", &search_number);

	start = clock();
	return_value = seqsearch(list, MAX_ELEMENTS, search_number);
	finish = clock();

	duration = finish - start;
	printf("%d milliseconds\n", duration);
	printf("������ ����Ƚ��=%d\n ", count);

	start = clock();
	return_value = binsearch(list, MAX_ELEMENTS, search_number);
	finish = clock();

	duration = finish - start;
	printf("%d milliseconds\n", duration);
	printf("������ ����Ƚ��=%d\n ", count);

	if (return_value == -1) {
		printf("���ڰ� �߰ߵ��� �ʾ����ϴ�.\n", &search_number);
	}
	else {
		printf("���ڰ� ��ġ %d���� �߰ߵǾ����ϴ�.\n", return_value);
	}
	return 0;
}

