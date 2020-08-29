#include<iostream>
using namespace std;

class Deque {
	int data;
	Deque* next;
	Deque* rear,*prev, *preCur, *front;
public:
	Deque():data(0),next(NULL),rear(NULL),prev(NULL),preCur(NULL),front(NULL){}
	void pushRear(int);
	void pushFront(int);
	int popRear();
	int popFront();
};
int main() {
	Deque D;
	D.pushRear(10);
	D.pushRear(20);
	D.pushRear(30);
	D.pushRear(40);
	D.pushRear(50);
	cout << D.popFront() << endl;
	cout << D.popRear() << endl;
	cout << D.popFront() << endl;


	system("pause");
	return 0;
}

void Deque::pushRear(int value)
{
	rear = new Deque;
	rear->next = NULL;
	rear->data = value;
	if (!front)
		front=prev = rear;
	else {
		prev->next = rear;
		preCur = prev;
		prev = rear;
	}


}

void Deque::pushFront(int value)
{
	rear = new Deque;
	rear->data = value;
	if (!front)
		front = prev = rear;
	else {
		rear->next = front;
		front = rear;

	}

}

int Deque::popFront()
{
	int temp = -999;
	if (front) {
		temp=front->data;
		front = front->next;
	}
	return temp;
}
int Deque::popRear()
{
	int temp = -999;
	if (!front->next) {
		temp = front->data;
		front =prev=rear= NULL;
	}
	else {
		temp = rear->data;
		preCur->next = NULL;
		rear =prev= preCur;
	}
	return temp;

}
