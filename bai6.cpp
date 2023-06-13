/*
*	Khai báo cấu trúc dữ liệu để tổ chức danh sách liên kết đơn quản lý các tỉnh/thành phố của Việt Nam.
	Thông tin của mỗi tỉnh/thành phố bao gồm: Mã tỉnh, tên tỉnh, diện tích, dân số.
	Cài đặt các thao tác cơ bản (thêm ở vị trí bất kỳ; sửa, xóa theo mã (code), duyệt danh sách).
	Tính tổng diện tích của tất cả các tỉnh thành.
	Tìm vị trí của node của tỉnh có diện tích lớn nhất.
	Tìm tỉnh/thành phố có dân số lớn nhất.
	Sắp xếp danh sách theo mã tỉnh/thành phố.
	Sắp xếp danh sách tăng dần theo diện tích.
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include<fstream>
using namespace std;

struct Province
{
	int ID;
	string Name;
	float Area;
	long long population;
};
struct node
{
	Province* data;
	node* next;
};
Province *Nhap()
{
	Province* city = new Province;
	cout << "input city ID: ";
	cin >> city->ID;
	cout << "input city name: ";
	cin.ignore();
	getline(cin,city->Name);
	cout << "input city area: ";
	cin >> city->Area;
	cout << "input city population: ";
	cin >> city->population;
	return city;
}
node* MakeNode(node*& head,Province *city)
{
	node* newnode = new node();
	newnode->data = city;
	newnode->next = NULL;
	return newnode;
}
void duyet(node* head)
{
	while (head != NULL)
	{
		cout << head->data->ID << " " << head->data->Name << " " << head->data->Area << " " << head->data->population << endl;
		head = head->next;
	}
}
void Push_Front(node*& head, Province* city)
{
	node* newnode = MakeNode(head, city);
	newnode->next = head;
	head = newnode;
}
void Push_Back(node*& head, Province* city)
{
	node* temp = head;
	node* newnode = MakeNode(head, city);
	if (head == NULL)
	{	
		head = newnode; return;
	}
	if (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}
void insert(node*& head, Province* city,int k)
{
	int n = sizeof(head);
	if (k<0 || k>n + 1)return;
	if (k == 1)
	{
		Push_Front(head, city);
	}
	node* temp = head;
	for (int i = 1; i < k - 1; i++)
	{
		temp = temp->next;
	}
	node* newnode = MakeNode(head, city);
	newnode->next = temp->next;
	temp->next = newnode;

}
void erase(node*& head, int k)
{
	int n = sizeof(head);
	if (k<1 || k>n) return;
	if (k == 1)
	{
		if (head == NULL)return;
		node* temp = head;
		head = head->next;
		delete(temp);
	}
	else
	{
		node* temp = head;
		for (int i = 1; i <= k - 2; i++)
		{
			temp = temp->next;
		}
		node* kth = temp->next;
		temp->next = kth->next;
		delete(kth);
	}
}
float Sum_Area(node*& head)
{
	float sum = 0;
	while (head != NULL)
	{
		sum += head->data->Area;
		head = head->next;
	}
	return sum;
}
int Index_Max_Area(node* head)
{
	float max = 0;
	int i = 0;
	int index = 1; 
	while (head != NULL)
	{
		i++;
		if (head->data->Area > max)
		{
			max = head->data->ID;
			index = i;
			
		}
		
		head = head->next;
	}
	return index;
}
void Sort_1(node*& head)
{
	for (node* i = head; i != NULL; i = i->next)
	{
		node* minnode = i;
		for (node* j = i->next; j != NULL; j = j->next)
		{
			if (minnode->data->Area > j->data->Area)
			{
				minnode = j;
			}
		}
		Province* temp = minnode->data;
		minnode->data = i->data;
		i->data = temp;
	}

}
int main()
{
	node* head = NULL;
	Province *city;
	while (true)
	{
		cout << "===================================================" << endl;
		cout << "1. them mot tinh vao cuoi danh sach" << endl;
		cout << "2. them mot tinh vao dau danh sach" << endl;
		cout << "3. them mot tinh o vi tri bat ky" << endl;
		cout << "4. xoa mot tinh o vi tri bat ky" << endl;
		cout << "5. duyet" << endl;
		cout << "6. tinh tong dien tich tat ca cac tinh" << endl;
		cout << "7. tim tinh co dien tich lon nhat" << endl;
		cout << "8. sap xep theo dien tich tang dan" << endl;
		cout << "0. thoat" << endl;
		cout << "===================================================" << endl;
		int luachon;
		cout << "nhap lua chon cua ban: ";
		cin >> luachon;
		if (luachon == 1)
		{
			city = Nhap();
			Push_Back(head, city);
		}
		else if (luachon == 2)
		{
			city = Nhap();
			Push_Front(head, city);
		}
		else if (luachon == 3)
		{
			int k;
			cout << "nhap vi tri muon them: ";
			cin >> k;
			city = Nhap();
			insert(head, city, k);
		}
		else if (luachon == 4)
		{
			int k;
			cout << "nhap vi tri ban muon xoa: ";
			cin >> k;
			erase(head, k);
		}
		else if (luachon == 5)
		{
			duyet(head);
		}
		else if (luachon == 6)
		{
			float dientich;
			dientich = Sum_Area(head);
			cout << "tong dien tich tat ca cac tinh la: " << dientich << endl;
		}
		else if (luachon == 7)
		{
			int index;
			index = Index_Max_Area(head);
			cout << "tinh co dien tich lon nhat nam o vi tri: " << index << endl;
		}
		else if (luachon == 8)
		{
			Sort_1(head);
		}
		else
		{
			break;
		}
	}
	return 0;
}
