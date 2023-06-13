#include <iostream>
using namespace std;
//// cach 1 su dung mang 1 chieu
//int a[100000], maxN = 100000;
//int n = 0;
//int size()
//{
//	return n;
//}
//bool empty()
//{
//	return n == 0;
//}
//void push(int x)
//{
//	if (n == maxN)return;
//	a[n] = x;
//	++n;
//}
//void pop()
//{
//	if (n == 0)return;
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = a[i + 1];
//	}
//	--n;
//}
//int front()
//{
//	return a[0];
//}


// cach 2 su dung dslk
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
void push(node*& queue,int x)
{	
	node* newnode = makenode(x);
	if (queue == NULL)
	{
		queue = newnode; return;
	}
	node* temp = queue;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}
void pop(node*& queue)
{
	if (queue == NULL) return;
	node* temp = queue;
	(queue) = (queue)->next;
	delete(temp);
}
int size(node* queue)
{
	int ans = 0;
	while(queue != NULL)
	{
		++ans;
		queue = queue->next;
	}
	return ans;
}
bool empty(node* queue)
{
	return queue == NULL;
}
int front(node* queue)
{
	return queue->data;
}
void duyet(node* queue)
{
	while (queue != NULL)
	{
		cout << queue->data << " ";
		queue = queue->next;
	}
}
int main()
{
	node* queue = NULL;
	while (true)
	{
		cout << "=========================\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Front\n";
		cout << "4. Size\n";
		cout << "5. Empty\n";
		cout << "6. Duyet\n";
		cout << "0. Exit\n";
		cout << "========================\n";
		int lc;
		cout << "nhap lua chon cua ban: ";
		cin >> lc;
		if (lc == 1)
		{
			int x;
			cout << "nhap x= ";
			cin >> x;
			push(queue,x);
		}
		else if (lc == 2)
		{
			pop(queue);
		}
		else if (lc == 3)
		{
			cout << front(queue) << endl;
		}
		else if (lc == 4)
		{
			cout << size(queue) << endl;
		}
		else if (lc == 5)
		{
			if (empty(queue))
			{
				cout << "EMPTY\n";
			}
			else
			{
				cout << "NOT EMPTY\n";
			}
		}
		else if (lc == 6)
		{
			duyet(queue);
		}
		else
		{
			break;
		}


	}
	return 0;
}
