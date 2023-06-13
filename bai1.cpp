#include <iostream>
using namespace std;
struct list
{
	float data;
	list* next;
};
list* MakeNode(int x)
{
	list* newnode = new list();
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void duyet(list* head)
{
	while (head != NULL)
	{
		cout << head->data << "\t";
		head = head->next;
	}
}
int count(list* head)
{
	int dem = 0;
	while (head != 0)
	{
		++dem;
		head = head->next;
	}
	return dem;
}
void Push_Front(list*& head, int x)
{
	list* newnode = MakeNode(x);
	newnode->next = head;
	head = newnode;
}
void Pust_Back(list*& head, int x)
{
	list* temp = head;
	list* newnode = MakeNode(x);
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
void insert(list*& head, int k, int x)
{
	int n = sizeof(head);
	if (k<1 || k>n + 1)return;
	if (k == 1)
	{
		Push_Front(head, x);
	}
	list* temp = head;
	for (int i = 1; i < k - 1; i++)
	{
		temp = temp->next;
	}
	list* newnode = MakeNode(x);
	newnode->next = temp->next;
	temp->next = newnode;
}
int tong_danh_sach(list* head)
{
	int tong = 0;
	while (head != NULL)
	{
		tong += head->data;
		head = head->next;
	}
	return tong;
}
int main()
{	
	list* head = NULL;
	while (true)
	{
		cout << "\n=================================================" << endl;
		cout << "1. Them vao dau danh sach" << endl;
		cout << "2. Them vao cuoi danh sach" << endl;
		cout << "3. Chen vao vi tri da chon " << endl;
		cout << "4. Duyet va in ra danh sach" << endl;
		cout << "5. tinh tong va in ra tong cua danh sach" << endl;
		cout << "0. Thoat" << endl;
		cout << "===================================================" << endl;;
		int luachon;
		cout << "nhap lua chon cua ban: "; cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "nhap so x muon them vao dau: ";
			cin >> x;
			Push_Front(head, x);
		}
		else if (luachon == 2)
		{
			int x;
			cout << "nhap so x muon them vao cuoi: ";
			cin >> x;
			Pust_Back(head, x);
		}
		else if (luachon == 3)
		{
			int k, x;
			cout << "nhap vi tri muon chen: ";
			cin >> k;
			cout << "nhap gia tri muon chen: ";
			cin >> x;
			insert(head, k, x);
		}
		else if (luachon == 4)
		{
			duyet(head);
		}
		else if (luachon == 5)
		{
			cout << "tong du lieu cua danh sach lien ket tren la: " << tong_danh_sach(head) << endl;
		}
		else
		{
			break;
		}
	}
	return 0;
}