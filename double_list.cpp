#include<iostream>
struct node
{
	int data;
	node *next;
	node *prev;
};
typedef node* list;
void print(list l);
list search(list l,int data);
void insert(list l, list x);
void delete_x(list l, list x);
int main()
{
	/*记得初始化指针*/
	list nil =new node;
	nil->next = nil->prev = nil;
	int x;
	std::cin >> x;
	while (x!=-1)
	{
		list temp = new node;
		temp->data = x;
		insert(nil, temp);
		std::cin >> x;
	}
	print(nil);
	std::cin >> x;
	list l = search(nil, x);
	delete_x(nil, l);
	print(nil);
}
void print(list l)
{
	list temp = l->next;
	while (temp!=l)
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;
}
list search(list l, int data)
{
	list temp = l->next;
	while (l!=temp&&temp->data!=data)
	{
		temp = temp->next;
	}
	if (temp == l)
		return nullptr;
	return temp;
}
void insert(list l, list x)
{
	x->next = l->next;
	l->next->prev = x;
	l->next = x;
	x->prev = l;
}
void delete_x(list l, list x)
{
	if (!x)
		return;
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}