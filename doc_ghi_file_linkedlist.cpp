/*
	khai báo cấu trúc liên kết đơn quản lí danh sách sinh viên như sau
	dòng đầu tiên là thông tin của 1 sinh viên:
	+ họ tên
	+ mã sinh viên
	+ ngày tháng năm sinh chuỗi string định dạng dd/mm/yyyy
	+ điểm trung bình 1 học kỳ
	yêu cầu:
	1. Đọc dữ liệu từ file SinhVien.txt
	2. sắp xếp danh sách sinh viên tăng dần theo điểm trung bình và ghi vào file SAPXEPDIEMMAX.TXT
	3. in danh sách sinh viên có điểm trung bình cao nhất vào file DIEMTRUNGBINHMAX.TXT
	4. tìm kiếm thông tin sinh viên dựa vao mã số sinh viên
	5. tìm kiếm thông tin sinh viên dựa vào tên sinh viên
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
struct date
{
	int days;
	int months;
	int years;
};
struct SinhVien
{
	string Name;
	string ID;
	date birth;
	float point;
};
// hàm đọc dư xlieeuj ngày tháng năm
void Read_date(ifstream& filein, date& s)
{

	filein >> s.days;
	filein.seekg(1, 1);
	filein >> s.months;
	filein.seekg(1, 1);
	filein >> s.years;
}
struct node
{
	SinhVien data;
	node* next;
};
node* makenode(SinhVien SV)
{
	node* newnode = new node();
	newnode->data = SV;
	newnode->next = NULL;
	return newnode;
}
void Push_Front(node*& head, SinhVien SV)
{
	node* newnode = makenode(SV);
	newnode->next = head;
	head = newnode;
}
void Push_Back(node*& head, SinhVien SV)
{
	node* temp = head;
	node* newnode = makenode(SV);
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
// hàm đọc sinh viên từ file
void Read_data(ifstream& filein, SinhVien* SV)
{
	getline(filein, SV->Name, ',');
	filein.seekg(1, 1);
	getline(filein, SV->ID, ',');
	filein.seekg(1, 1);
	Read_date(filein, SV->birth);
	filein.seekg(2, 1);
	filein >> SV->point;
	string temp;
	getline(filein, temp);
}
void read_data_from_file(node*& head, ifstream& filein, SinhVien SV)
{
	while (!filein.eof())
	{
		Read_data(filein, &SV);
		Push_Back(head, SV);
	}
}
void duyet(node* head)
{
	int dem = 1;
	while (head != NULL)
	{
		cout << "\t\t\tSinh Vien thu:" << dem++ << endl << endl;
		cout << "ho ten: " << head->data.Name << endl;
		cout << "ma sinh vien: " << head->data.ID << endl;
		cout << "ngay sinh: " << head->data.birth.days << "/" << head->data.birth.months << "/" << head->data.birth.years << endl;
		cout << "diem trung binh: " << head->data.point << endl;
		head = head->next;
	}
}
void hoanvi(SinhVien& x, SinhVien& y)
{
	SinhVien temp = x;
	x = y;
	y = temp;
}
void Sort_point(node*& head)
{
	for (node* i = head; i != NULL; i = i->next)
	{
		node* minnode = i;
		for (node* j = i->next; j != NULL; j = j->next)
		{
			if (minnode->data.point > j->data.point)
			{
				minnode = j;
			}
		}
		hoanvi(minnode->data, i->data);
	}
}
void doc_thong_tin_1_sv_vao_file(ofstream& fileout, SinhVien& SV)
{
	fileout << SV.Name << ", ";
	fileout << SV.ID << ", ";
	fileout << SV.birth.days << "/" << SV.birth.months << "/" << SV.birth.years << ", ";
	fileout << SV.point;
}
void ghi_du_lieu(ofstream &fileout,node*& head)
{
	Sort_point(head);
	for (node* i = head; i != NULL; i = i->next)
	{
		doc_thong_tin_1_sv_vao_file(fileout, i->data);
		fileout << endl;
	}

}
void Sinh_Vien_Co_MAXPOINT(node* head, ofstream& fileout2)
{
	float max = 0;
	for (node* i = head; i != NULL; i = i->next)
	{
		if (i->data.point > max)
		{
			max = i->data.point;
		}
	}
	for (node* i = head; i != NULL; i = i->next)
	{
		if (i->data.point == max)
		{
			cout << "Sinh vien co diem cao nhat la: " << endl;
			doc_thong_tin_1_sv_vao_file(fileout2, i->data);
		}
	}
}
void xuat(SinhVien SV)
{
	cout << "Ho ten:" << SV.Name << endl;
	cout << "Ma so:" << SV.ID << endl;
	cout << "Ngay sinh:" << SV.birth.days << "/" << SV.birth.months << "/" << SV.birth.years << endl;
	cout << "Diem trung binh:" << SV.point << endl;
}
void tim_thong_tin_dua_vao_ma_so(node* head)
{
	string ma;
	bool check = false;
	cout << "nhap ma sinh vien ban muon tim: ";
	cin.ignore();
	getline(cin, ma);
	for (node* i = head; i != NULL; i = i->next)
	{
		if (i->data.ID == ma)
		{
			xuat(i->data);
			check = true;
		}
	}
	if (check == false)
	{
		cout << "khong tim thay sinh vien co ma: " << ma << endl;
	}
	
}
void tim_thong_tin_sinh_vien_theo_ten(node* head)
{
	string ten;
	bool check = false;
	cout << "nhapp ten ban muon tim: ";
	cin.ignore();
	getline(cin, ten);
	for (node* i = head; i != NULL; i = i->next)
	{
		if (i->data.Name == ten)
		{
			xuat(i->data);
			check = true;
		}
	}
	if (check == false)
	{
		cout << "Khong tim thay sinh vien co ten: " << ten << endl;
	}
}
int main()
{
	node* head = NULL;
	SinhVien SV;
	while (true)
	{
		cout << "==============================================================================" << endl;
		cout << "1. Doc du lieu tu file" << endl;
		cout << "2. Sap xep danh sach theo diem trung binh va ghi vao file SAPXEPDIEMMAX.TXT" << endl;
		cout << "3. In danh sach sinh vien co diem trung binh cao nhat vao file DIEMTRUNGBINHMAX.TXT" << endl;
		cout << "4. Tim kiem thong tin sinh vien dua vao ma so sinh vien" << endl;
		cout << "5. tim kiem thong tin sinh vien dua vao ten sinh vien" << endl;
		cout << "6. duyet" << endl;
		cout << "0. Thoat" << endl;
		cout << "==============================================================================" << endl;
		int luachon;
		cout << "nhap lua chon cua ban: ";
		cin >> luachon;
		if (luachon == 1)
		{
			ifstream filein;
			filein.open("SinhVien.txt", ios_base::in);
			if (!filein.is_open())
			{
				cerr << "FAIL TO OPEN FILE" << endl;
			}
			else
			{
				read_data_from_file(head, filein, SV);
				cout << "DOC DU LIEU TU FILE THANH CONG!!!" << endl;
			}
			filein.close();
		}
		else if (luachon == 2)
		{
			ofstream fileout;
			fileout.open("SAPXEPDIEMMAX.TXT", ios_base::out);
			if (!fileout.is_open())
			{
				cerr << "FAIL TO OPEN FILE" << endl;
			}
			else
			{
				ghi_du_lieu(fileout, head);
				cout << "GHI DU LIEU VAO FILE THANH CONG!!!" << endl;
			}
		}
		else if (luachon == 3)
		{
			ofstream fileout2;
			fileout2.open("DIEMTRUNGBINHMAX.txt", ios_base::out);
			if (!fileout2.is_open())
			{
				cerr << "FAIL TO OPEN FILE" << endl;
			}
			else
			{
				Sinh_Vien_Co_MAXPOINT(head, fileout2);
				cout << "GHI DU LIEU VAO FILE THANH CONG!!" << endl;
			}
			fileout2.close();
		}
		else if (luachon == 4)
		{
			tim_thong_tin_dua_vao_ma_so(head);
		}
		else if (luachon == 5)
		{
			tim_thong_tin_sinh_vien_theo_ten(head);
		}
		else if (luachon == 6)
		{
			duyet(head);
			int n = sizeof(head);
			cout << "\n" << n << endl;
		}
		else
		{
			break;
		}
	}
	return 0;
}