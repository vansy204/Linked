/*
1. Định nghĩa một cấu trúc Sinh viên bao gồm các trường thông tin như sau:
Mã Sinh viên (kiểu số nguyên), tên Sinh viên (kiểu chuỗi ký tự), lớp (kiểu chuỗi ký tự),
điểm tổng kết (kiểu số thực), hạnh kiểm (Tốt, khá, trung bình, yếu).
2. Cài đặt một cấu trúc danh sách liên kết đơn cho kiểu dữ liệu Sinh viên,
với các thao tác: 1) Khởi tạo danh sách; 2) kiểm tra rỗng 3) thêm phần tử vào cuối (hoặc đầu) danh sách 4)
Tìm kiếm phần tử trong danh sách; 5) Xóa )phần tử cuối cùng khỏi danh sách; 6) Duyệt danh sách; 7)
Sắp xếp danh sách
*/
#include <iostream>
#include <string>
using namespace std;
struct SinhVien
{
	int ID;
	char name[40];
	char lop[40];
	float diem;

};
struct node
{
	SinhVien* data;
	node* next;
};
SinhVien *nhap()
{
	SinhVien *s= new SinhVien;
	cout << "nhap ma: ";
	cin >> s->ID;
	cout << "nhap ten: ";
	cin.ignore();
	gets_s(s->name);
	cout << "nhap lop: ";
	gets_s(s->lop);
	cout << "nhap diem: ";
	cin >> s->diem;
	return s;
}
node* MakeNode(SinhVien* s)
{
	node* newnode = new node();
	newnode->data = s;
	newnode->next = NULL;
	return newnode;
}
void ktra(node*& head)
{
	if (head == NULL)
	{
		cout << "EMPTY";
	}
}
void Push_Back(node*& head, SinhVien *s)
{
	node* temp = head;
	node* newnode = MakeNode(s);
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
void duyet(node* head)
{
	while (head != NULL)
	{
		cout << head->data->ID << ", " << head->data->name << ", " << head->data->lop << ", " << head->data->diem << endl;
		head = head->next;
	}
}
void timkiem(node*& head, char* x)
{
	int check = 0;
	while (head != NULL)
	{
		if (strcmp(head->data->name, x) == 0)
		{
			cout << head->data->ID << ", " << head->data->name << ", " << head->data->lop << ", " << head->data->diem << endl;
			check = 1;
		}
		
		head = head->next;
	}
	if (check == 0)
	{
		cout << "khong tim thay sinh vien ten x" << endl;
	}
}
void xoa_cuoi(node*& head)
{
	if (head == NULL)return;
	node* temp = head;
	if (temp->next == NULL)
	{
		head = NULL;
		delete(temp);
		return;
	}
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	node* last = temp->next;
	temp->next = NULL;
	delete(last);
}
void hoanvi(node*& a, node*& b)
{
	node* temp = a;
	a = b;
	b = temp;
}
void sap_xep(node*& head)
{
	for (node* i = head; i != NULL; i = i->next)
	{
		node* minnode = i;
		{
			for (node* j = i->next; j != NULL; j = j->next)
			{
				if (minnode->data->diem > j->data->diem)
				{
					minnode = j;
				}
			}
		}
		SinhVien* temp = minnode->data;	
		minnode->data = i->data;
		i->data = temp;
	}
}
int main()
{
	node* head = NULL;
	SinhVien* s;
	while (true)
	{
		cout << "=====================================================" << endl;
		cout << "1. Kiem tra danh sach" << endl;
		cout << "2. Them phan tu vao cuoi danh sach" << endl;
		cout << "3. Tim Kiem phan tu trong danh sach" << endl;
		cout << "4. Xoa phan tu trong danh sach" << endl;
		cout << "5. Duyet" << endl;
		cout << "6. Sap xep danh sach" << endl;
		cout << "=====================================================" << endl;
		int luachon;
		cout << "nhap lua chon cua ban: ";
		cin >> luachon;
		if (luachon == 1)
		{
			ktra(head);
		}
		else if (luachon == 2)
		{
			s = nhap();
			Push_Back(head, s);
		}
		else if (luachon == 3)
		{
			char x[40];
			cout << "nhap ten ban can tim: ";
			cin.ignore();
			cin.getline(x,40);
			int vitri;
			timkiem(head, x);
		}
		else if (luachon == 4)
		{
			xoa_cuoi(head);
		}
		else if (luachon == 5)
		{
			duyet(head);
		}
		else if (luachon == 6)
		{
			sap_xep(head);
		}
		else
		{
			break;
		}
	}
	return 0;
}