/*
Cho một sinh viên có cấu trúc: mã (int), tên (char *). 
Dùng danh sách liên kết đơn với con trỏ phead để thao tác:

Khởi tạo list dạng con trỏ
Thêm node vào cuối danh sách
Sắp xếp theo mã
Xóa node
*/

#include <iostream>
#include <string>
using namespace std;
struct SinhVien
{
	int ID;
	char Name[150];
};
struct node
{
	SinhVien* data;
	node* next;
};
SinhVien *Nhap()
{
	SinhVien* sv = new SinhVien;
	cout << "nhap ma: ";
	cin >> sv->ID;
	cout << "nhap ten: ";
	cin.ignore();
	gets_s(sv->Name);
	return sv;
}
node* MakeNode(SinhVien* sv)
{
	node* newnode = new node();
	
	newnode->data = sv;
	newnode->next = NULL;
	return newnode;
}
void Push_Back(node*& head, SinhVien *sv)
{
	node* temp = head;
	node* newnode = MakeNode(sv);

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
void duyet(node* head)
{
	while (head != NULL)
	{
		cout << head->data->ID << ", " << head->data->Name << endl;
		head = head->next;
	}
}
void hoanvi(node*& a, node*& b)
{
	node* temp = a;
	a = b;
	b = temp;
}
void SortList(node*& head)
{
	for (node* temp = head->next; temp->next != NULL; temp = temp->next)
	{
		for (node* temp2 = temp->next; temp2->next != NULL; temp2 = temp2->next)
		{
			SinhVien* svtemp = temp->data;
			SinhVien* svtemp2 = temp2->data;
			if (svtemp2->ID < svtemp->ID)
			{
				hoanvi(temp, temp2);
			}

		}
	}
}
int main()
{
	node* head = NULL;
	SinhVien *sv;
	int n;
	cout << "nhap n sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		SinhVien* temp;
		temp = Nhap();
		Push_Back(head,temp);
	}
	duyet(head);
	cout << "\ndanh sach da sap xep" << endl;
	SortList(head);
	duyet(head);
	return 0;
}