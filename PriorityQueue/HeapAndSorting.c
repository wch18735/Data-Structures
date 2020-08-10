#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define MAX_ELEMENT 200
#define SIZE 8
typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// ���� �Լ�
HeapType *create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// �ʱ�ȭ �Լ�
void init(HeapType *h) {
	h->heap_size = 0;
}

// ���� �Լ�
void insert_max_heap(HeapType *h, element item) {
	int i;
	i = ++(h->heap_size);

	// Ʈ���� �Ž��� �ö󰡸� �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {	// �Ǵ�
		h->heap[i] = h->heap[i / 2];	// �θ� ����� key���� ������ �߰�
		i /= 2;							// �θ� ���� index�� Update
	}	// Index ��ġ�� ����� (�̹� �Է��� key���� �˰������� ��� ����)
	// while�� ���� i ���� heap�� �����ϴ� index��
	h->heap[i] = item;
}

// ���� �Լ�
element delete_max_heap(HeapType *h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];	// root��� ����
	temp = h->heap[(h->heap_size)--];	// ���� ������ ��� temp�� �ְ�, size ����
	parent = 1;
	child = 2;
	while (child <= h->heap_size){	// �Ǵ��Ϸ��� �ڽ� ��尡 ������ index�� ����� break
		// ���� ����� �ڽĳ�� �� �� ū �ڽĳ�� ã��
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++;	// �������� �� ũ�� ������, �ƴϸ� �״�� ����
		if (temp.key >= h->heap[child].key) break; // �����ϸ� �״�� break;

		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];	// �θ� ��ġ�� �ڽ� ����
		parent = child;	// �θ� ��带 update;
		child *= 2;		// �ش� ����� ���� �ڽĳ�� index�� update
	}
	h->heap[parent] = temp;	// �θ��� �ڸ��� temp�� ����
	return item;
}

void heap_sort(element a[], int n) {
	int i;
	HeapType *h;

	h = create();
	init(h);
	for (i = 0; i < n; i++)
		insert_max_heap(h, a[i]);
	for (i = (n - 1); i >= 0; i--)
		a[i] = delete_max_heap(h);	// �̷��� �ϸ� ������������
	/*
	for (i = 0; i < n; i++)
		a[i] = delete_max_heap(h);	// �̷��� �ϸ� ��������
	*/
	free(h);	// �޸� �Ҵ� ����
}

int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;
	heap = create(); // ���� ����
	init(heap); // �ʱ�ȭ
				// ����
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	// ����
	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > \n", e6.key);
	free(heap);

	element list[SIZE] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	heap_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}