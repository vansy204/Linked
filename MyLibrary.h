#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;

struct node
{
	int data;
	node* next;
};
node* MakeNode(int x);
void duyet(node* head);
void Push_Front(node*& head, int x);
void Push_Back(node*& head, int x);
void insert(node*& head, int k, int x);
int count(node*& head);
int sum(node*& head);
