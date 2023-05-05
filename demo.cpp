﻿#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* makeNode(int x)
{
	node* newnode = new node();
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
// thêm 1 node vào đầu danh sách
// hàm duyệt từ đầu danh sách
void duyet(node* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}
// hàm đếm số node trong danh sách
int count(node* head)
{
	int dem = 0;
	while (head != NULL)
	{
		++dem;
		head = head->next;
	}
	return dem;
}
//// thêm vào đầu danh sách
//// code chi dung c
//void pushFront(node** head, int x)
//{
//	node* newnode = makeNode(x);
//	// bước 1: phần next của newwnode => head
//	newnode->next = *head; // *head là địa chỉ của node head trong ds
//	// bước 2: cập nhật node head => newnode;
//	*head = newnode;
//}
// code chỉ dùng c++
void pushFront_2(node*& head, int x)
{
	node* newnode = makeNode(x);
	newnode->next = head;
	head = newnode;
}
// code c
//void pushback(node** head, int x)
//{
//	node* temp = *head;
//	node* newnode = makeNode(x);
//	if (*head == NULL)
//	{
//		*head = newnode;
//		return;
//	}
//	while (temp->next != NULL)
//	{
//		temp = temp->next;
//	}
//	temp->next = newnode;
//}
// code c++
// thêm vào cuối
void pushback2(node*& head, int x)
{
	node* temp = head;
	node* newnode = makeNode(x);
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
// thêm vào giữa
void insert(node *&head,int k,int x)
{
	int n = sizeof(head);
	if (k<1 || k > n + 1) return;
	if (k == 1)
	{
		pushFront_2(head, x);
	}
	node* temp = head;
	for (int i = 1; i <= k-1; i++)
	{
		temp = temp->next;
	}
	//after for loop temp = k-1;
	node* newnode = makeNode(x);
	newnode->next = temp->next;
	temp->next = newnode;
}
int main()
{
	node* head = NULL;
	while (true)
	{
		cout << "\n==============================" << endl;
		cout << "1.them vao dau" << endl;
		cout << "2.them vao cuoi" << endl;
		cout << "3.them vao giua" << endl;
		cout << "4.duyet" << endl;
		cout << "0.thoat" << endl;
		cout << "=============================" << endl;
		int lc;
		cout << "nhap lua chon: "; cin >> lc;
		if (lc == 1)
		{
			int x;
			cout << "nhap x: ";
			cin >> x;
			pushFront_2(head, x);
		}
		else if (lc == 2)
		{
			int x;
			cout << "nhap x: ";
			cin >> x;
			pushback2(head, x);
		}
		else if (lc == 3)
		{
			int x;
			int k;
			cout << "nhap x: ";
			cin >> x;
			cout << "nhap k: ";
			cin >> k;
			insert(head, k, x);
		}
		else if (lc == 4)
		{
			duyet(head);
		}
		else
		{
			break;
		}
	}
	return 0;
}