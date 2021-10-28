#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
};
node *head = NULL;
node *tail = NULL;
void add(int data)
{
	node *ptr = new node;
	ptr->data = data;
	if (head == NULL)
	{
		head = ptr;
		ptr->prev = NULL;
		ptr->next = NULL;
		tail = ptr;
	}
	else
	{
		node*p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = ptr;
		ptr->prev = p;
		ptr->next = NULL;
		tail = ptr;
	}
}
void insert(int data,int n)
{
	node *p = head;
	while (p!= NULL)
	{
		if (p->data == data)
		{
			if (p->next == NULL)
			{

				node*ptr = new node;
				ptr->data = n;
				p->next = ptr;
				ptr->prev = p;
				ptr->next = NULL;
				tail = ptr;
			}
			else
			{
				node*ptr = new node;
				ptr->data = n;
				ptr->next = p->next;
				p->next->prev = ptr;
				ptr->prev = p;
				p->next = ptr;
			}
		}
		p = p->next;
	}
}
void del(int data)
{
	node *p = head;
	while (p!= NULL)
	{
		if (p->data == data)
		{
			if (p==tail)
			{
				tail = p->prev;
				p->prev->next= NULL;
				delete p;
				break;
			}
			else
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				delete p;
				break;
			}
		}
		p = p->next;
	}
}
void rev()
{

	node *curr = head;
	node*temp=head;
	head = tail;
	tail = temp;
	
	do
	{
		
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	} while (curr != NULL);
	
}
void display()
{
	cout << "NOW LINKLIST BECOMES \n";
	node *p = head;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}
int main()
{
	int x = -1;
	int data,n;
	while (x != 0)
	{
		cout << "press 1 for addition of node \n";
		cout << "press 2 for insertion \n";
		cout << "press 3 for deletion \n";
		cout << "press 4 for reverse \n";
		cout << "press 5 for display \n";
		cout << "enter 0 for exist \n";
		cin >> x;
		switch (x)
		{
		case 1:
		{

			cout << "enter data of new node \n";
			cin >> data;
			add(data);
			break;
		}
		case 2:
		{
			cout << "enter data for insertion of new node \n";
			cin >> data;
			cout << "enter the palce after which you want enter new node \n";
			cin >> n;
			insert(n, data);
			break;

		}
		case 3:
		{
			cout << "enter the data of the node you want to delete \n";
			cin >> data;
			del(data);
			break;
		}
		case 4:
		{
			rev();
			break;
		}
		case 5:
		{
			display();
			break;
		}
		default:
			break;
		}
	}
	system("pause");
}
