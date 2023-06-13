#include <iostream>
using namespace std;
struct SinhVien
{
	string name;
	double gpa;
	SinhVien()
	{

	}
	SinhVien(string ten, double diem)
	{
		name = ten;
		gpa = diem;
	}
};
struct node
{
	SinhVien data;
	node* next;
};
node* makenode(SinhVien s)
{
	node* newnode = new node();
	newnode->data = s;
	newnode->next = NULL;
	return newnode;
}
void push_back(node*& head,SinhVien s)
{
	node* newnode = makenode(s);
	if (head == NULL)
	{
		head = newnode; return;
	}
	node* temp = head;
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
		cout << head->data.name << " " <<  head->data.gpa << endl;
		head = head->next;
	}
}
void sapxep(node*& head)
{
	for (node* i = head; i != NULL; i = i->next)
	{
		node* minnode = i;
		for (node* j = i->next; j != NULL; j = j->next)
		{
			if (minnode->data.gpa > j->data.gpa)
			{
				minnode = j;
			}

		}
		SinhVien temp = minnode->data;
		minnode->data = i->data;
		i->data = temp;
	}
}
int main()
{
	node* head = NULL;
	int a[] = { 10,9,8,2,1,6,3,5,3,4,7 };
	SinhVien s("teo", 3.5);
	SinhVien t("ti", 3.7);
	SinhVien u("long", 2.5);
	push_back(head, s);
	push_back(head, t);
	push_back(head, u);
	sapxep(head);
	duyet(head);
	return 0;
}