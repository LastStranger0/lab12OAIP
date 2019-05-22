#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct stack
{
	stack* next;
	int info;
};

stack* push(stack* p, int n) {
	stack *tem = new stack;
	tem->info = n;
	tem->next = p;
	return tem;
}

void view(stack *p) {
	stack *t = p;
	while (t != NULL) {
		cout << t->info << endl;
		t = t->next;
	}
}

stack* pop(stack *p ,int *out) {
	stack *t = p;
	*out = p->info;
	p = p->next;
	delete(t);
	return p;
}

void delAll(stack** p) {
	stack *t = new stack;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete (t);
	}
}

void sort_s(stack* p) {
	stack *t = NULL, *t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next) {
			if (t1->info > t1->next->info) {
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
			
		}
		t = t1;
	} while (p->next != t);
}

void sort_i(stack **p) {
	stack *t = NULL, *t1, *r;
	if ((*p)->next->next == NULL) return;
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next) {
			if (t1->next->info > t1->next->next->info) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		}
		t = t1->next;
	} while ((*p)->next->next != t);
}

stack* task(stack* p)
{
	stack* temp1 = p;
	stack* temp2 = p->next;

	while (temp2->next != NULL)
	{
		temp1->next = temp2->next;
		temp1 = temp2->next;
		delete temp2;
		if (temp1->next != NULL)
		{
			temp2 = temp1->next;
		}
		else return p;
		if (temp2->next == NULL)
		{
			temp1->next = temp2->next;
			delete temp2;
			return p;
		}
	}

}

int main() {
	srand(time(NULL));
	stack* Stack = NULL;
	setlocale(LC_ALL, "rus");
	int q,siz, n = 0,x, t;
	do {
		view(Stack);
		if (Stack == NULL) {
			cout << endl;
		}
		cout << "Стартуем?\n1.Заполнить стек элементами с клавиатуры\n2.Заполнить стек рандомными элементами\n3.Удалить 1 элемент стека\n4.Удалить все элементы стека\n5.Отсортировать стек\n6.Удалить каждый 2 элемент стека\n0.Выход\n";
		cin >> q;
		int siz;
		switch (q) {
		case 1:
			system("cls");
			cout << "\nВведите размер стека:\n";
			cin >> siz;
			cout << "\nВведите элементы:\n";
			for (int i = 0; i < siz; i++) {
				cin >> x;
				Stack = push(Stack, x);
			}
			n = n + siz;
			break;
		case 2:
			system("cls");
			cout << "\nВведите размер стека:\n";
			cin >> siz;
			for (int i = 0; i < siz; i++) {
				Stack = push(Stack, rand());
			}
			n = n+siz;
			break;
		case 3:
			system("cls");
			int a;
			Stack = pop(Stack, &a);
			cout << a << " было удалено\n";
			break;
			n++;
		case 4:
			system("cls");
			delAll(&Stack);
			break;
			n = 0;
		case 5:
			system("cls");
			Stack = push(Stack, 0);
			sort_i(&Stack);
			Stack = pop(Stack, &t);
			break;
		case 6:
			system("cls");
			cout << "Старый стек:" << endl;
			view(Stack);
			Stack = task(Stack);
			cout << endl << "Новый стек:" << endl;
			view(Stack);
			system("pause");
			break;
		case 0:
			system("cls");
			delAll(&Stack);
			break;
		}
	} while (q != 0);
}

//class node {
//public:
//	int data;
//	int number;
//	node *next;
//	node(int x) :number(0) {
//		data = x;
//		next = NULL;
//	}
//};
//
//class stack {
//public:
//	node *top;
//
//	void push(node *n) {
//		n->next = top;
//		top = n;
//	}
//
//	void pop() {
//		node *n = top;
//		top = top->next;
//		delete(n);
//	}
//
//	void print() {
//		node *ptr = top;
//		while (ptr != NULL) {
//			cout << ptr->data, ", ";
//			ptr = ptr->next;
//		}
//	}
//	void pr() {
//		node *p = top;
//		node *x = top;
//		int n = 0;
//		while (p != NULL) {
//			n++;
//			p = p->next;
//		}
//		for (int i = n; i <= 1; i--) {
//			if (i % 2 == 0) {
//				x = x->next;
//			}
//			else {
//				top = top->next;
//				delete(x);
//			}
//		}
//	}
//	stack() {
//		top = NULL;
//	}
//};
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	stack ob1;
//	
//	int i = 0;
//	int x;
//	do {
//		cout << "Чего желаете?\n1.Добавление 1 элемента\n2.Просмотр\n3.Сортировка\n4.Решение\n0.Выход\n";
//		cin >> i;
//		
//		if (i == 1) {
//			cin >> x;
//			node *q = new node(x);
//			cout << endl;
//			ob1.push(q);
//		}
//		else if (i == 2) {
//			ob1.print();
//		}
//		else if (i == 3) {
//		
//		}
//		else if (i == 4) {
//			ob1.pr();
//		}
//		/*case 0:
//			system("pause");
//			break;*/
//	} while (i != 0);
//}