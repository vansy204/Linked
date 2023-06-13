/*
Trong bài tập này ta thực hiện một bài toán như sau:

S = x + x^n/n!

Tạo một cấu trúc phân số a/b.
Xây dựng danh sách liên kết đơn có pHead, pTail. Dùng vòng for để thêm các phân số vào danh sách.
Xuất danh sách theo dãy số.
Xuất kết quả cuối cùng.
*/
#include <iostream>
using namespace std;
struct PhanSo
{
	int tu;
	int mau;
};
struct node
{
	PhanSo* data;
	node* next;
	
};
node* MakeNode(int tuso, int mauso)
{
	
	node* newnode = new node();
	PhanSo* ps = new PhanSo;
	ps->tu = tuso;
	ps->mau = mauso;
	newnode->data = ps;
	newnode->next = NULL;
	return newnode;
}
void Push_Back(node*& head,int tuso, int mauso)
{
	node* temp = head;
	node* newnode = MakeNode(tuso, mauso);
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

float sum(node *head)
{
	float tong = 0;
	while (head != NULL)
	{
		tong = tong + (float)head->data->tu / (float)head->data->mau;
		head = head->next;
	}
	return tong;
}
void duyet(node* head)
{
	while (head != NULL)
	{
		cout << head->data->tu << " " << head->data->mau << endl;
		head = head->next;
	}
}
int giaithua(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * giaithua(n - 1);
}
int main()
{
	node* head = NULL;
	int tuso, mauso;
	cout << "nhap tu so: "; cin >> tuso;
	cout << "nhap mau so: "; cin >> mauso;
	for (int i = 1; i <= mauso; i++)
	{
		int tu = (int)pow(tuso, i);
		int mau = giaithua(i);
		Push_Back(head, tu, mau);
	}
	cout << "\ntong cua danh sach lien ket la: " << sum(head) << endl;

	duyet(head);
	
	return 0;
}