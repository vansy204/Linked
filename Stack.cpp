#include <iostream>
using namespace std;
// cách 1
//int n = 0, stack[10001];
//void push(int x)
//{
//	stack[n];
//	++n;
//}
//void pop()
//{
//	if (n >= 1)
//	{
//		--n;
//	}
//}
//int top()
//{
//	return stack[n - 1];
//}
//int size()
//{
//	return n;
//}
//int main()
//{
//	while (true)
//	{
//		cout << "=============================" << endl;
//		cout << "1. Push\n";
//		cout << "2. Pop\n";
//		cout << "3. Top\n";
//		cout << "4. Size\n";
//		cout << "0. Exit\n";
//		cout << "=============================" << endl;
//		int luachon;
//		cout << "nhap lua chon cua ban: "; cin >> luachon;
//		if (luachon == 1)
//		{
//			int x;
//			cout << "nhap x= ";
//			cin >> x;
//			push(x);
//		}
//		else if (luachon == 2)
//		{
//			pop();
//		}
//		else if (luachon == 3)
//		{
//			if (n == 0) cout << "EMPTY\n";
//			cout << top() << endl;
//		}
//		else if (luachon == 4)
//		{
//			cout << size() << endl;
//		}
//		else
//		{
//			break;
//		}
//	}
//	return 0;
//}
// cách 2


// cach 2 bang dslk
struct node
{
	int data;
	struct node* next;
};
node* makenode(int x)
{
	node* newnode = new node();
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void push(node*& top, int x)
{
	node* newnode = makenode(x);
	if (top == NULL)
	{
		top = newnode; return;
	}
	newnode->next = top;
	top = newnode;
}
void pop(node*& top)
{
	if (pop != NULL)
	{
		node* temp = top;
		top = temp->next;
		delete(temp);
	}
}
int Top(node*& top)
{
	if (top != NULL)
	{
		return top->data;
	}
}
int size(node* top)
{
	int ans = 0;
	while (top != NULL)
	{
		++ans;
		top = top->next;
	}
	return ans;
}
int main()
{
	node* st = NULL;
	while (true)
	{
		cout << "=============================" << endl;
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Top\n";
		cout << "4. Size\n";
		cout << "0. Exit\n";
		cout << "=============================" << endl;
		int luachon;
		cout << "nhap lua chon cua ban: "; cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "nhap x: "; cin >> x;
			push(st, x);
		}
		else if (luachon == 2)
		{
			pop(st);
		}
		else if (luachon == 3)
		{
			if (st == NULL) cout << "EMPTY" << endl;
			else
			{
				cout << Top(st) << endl;

			}
		}
		else if (luachon == 4)
		{
			cout << size(st) << endl;
		}
		else
		{
			break;
		}

		
	}
	return 0;
}