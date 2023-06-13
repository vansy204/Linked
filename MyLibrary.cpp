#include "MyLibrary.h"

node* MakeNode(int x)
{
	node* newnode = new node();
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void duyet(node* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}
void Push_Front(node*& head, int x)
{
	node* newnode = MakeNode(x);
	newnode->next = head;
	head = newnode;
}
void Push_Back(node*& head, int x)
{
	node* temp = head;
	node* newnode = MakeNode(x);
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
void insert(node*& head, int k, int x)
{
	int n = sizeof(head);
	if (k<1 || k > n + 1)return;
	if (k == 1)
	{
		Push_Front(head, x);
	}
	else
	{
		node* temp = head;
		for (int i = 1; i <= k - 1; i++)
		{
			temp = temp->next;
		}
		node* newnode = MakeNode(x);
		newnode->next = temp->next;
		temp->next = newnode;
	}
}
int sum(node *&head)
{
	int dem = 0;
	int s = 0;
	while (head != NULL)
	{
		++dem;
		s += pow(head->data,dem);
		head = head->next;

	}
	return s;
}