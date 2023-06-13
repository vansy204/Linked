/*
Trong bài tập này chúng ta sẽ thực hiện giải một bài toán như sau:

s(x,n) = x1 + x2 + x3 + ... + xn
Xây dựng danh sách liên kết đơn có pHead, pTail.
Nhập x, n tạo thành danh sách liên kết( Mỗi nút có 2 giá trị x và i, i chạy từ 1 -> n),
dùng con trỏ để khai báo cho danh sách liên kết.

Viết hàm xuất ra tổng các phần tử trong danh sách liên kết.
*/
#include <iostream>
#include <math.h>
using namespace std;

struct node
{
	int data1;
	int data2;
	node* next;
};
node* MakeNode(int x,int n)
{
	node* newnode = new node();
	newnode->data1 = n;
	newnode->data2 = x;
	newnode->next = NULL;
	return newnode;
}
void duyet(node* head)
{
	int i = 1;
	while (head != NULL)
	{
		cout << "node thu " << i  <<": " << head->data1 << " " << head->data2 << endl;
		head = head->next;
		i++;
	}
}
void Push_Back(node*& head, int x, int n)
{
	node* temp = head;
	node* newnode = MakeNode(x, n);
	if (head == NULL)
	{
		head = newnode; return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}
int tong(node*& head, int x, int n)
{
	int sum = 0;
	while (head != NULL)
	{
		sum += pow(head->data2, head->data1);
		head = head->next;
	}
	return sum;
}
int main()
{
	
	node* head = NULL;
	int x;
	cout << "x= ";
	cin >> x;
	int n;
	cout << "n= ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		Push_Back(head, x, i);
	}
	duyet(head);
	cout << "\ntong mu cac node la: " << tong(head, x, n);
	return 0;
}