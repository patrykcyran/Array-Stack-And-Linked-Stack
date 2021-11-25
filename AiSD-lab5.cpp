#include <iostream>

using namespace std;

//Zadanie 1
class ArrayStack
{
private:
	int* items;
	int capacity;
	int top;

public:
	ArrayStack(int c);
	bool empty();
	bool full();
	bool push(int x);
	int peek();
	bool pop();
	void clear();
	friend ostream& operator<<(ostream& out, ArrayStack& s);
	~ArrayStack();

};


//Zadanie 2
class Element
{
private:
	int v;
	Element* next;

public:
	Element(int x, Element* next);
	int getValue();
	Element* getNext();
	void setNext(Element* p);
};

class LinkedStack
{
private:
	Element* top;

public:
	LinkedStack();
	bool empty();
	bool push(int x);
	int peek();
	bool pop();
	void clear();
	friend ostream& operator<<(ostream& out, LinkedStack* s);
	~LinkedStack();
};


//Zadanie 3
class ArrayFifo
{
private:
	int* items;
	int capacity;
	int size;
	int head;
	int tail;

public:
	ArrayFifo(int c);
	bool empty();
	bool full();
	bool enqueue(int x);
	int peek();
	bool dequeue();
	void clear();
	friend ostream& operator<<(ostream & out, ArrayFifo & f);
	~ArrayFifo();
};


//Zadanie 4

class LinkedFifo
{
private:
	Element* head;
	Element* tail;

public:
	LinkedFifo();
	bool empty();
	bool enqueue(int x);
	int peek();
	bool dequeue();
	void clear();
	friend ostream& operator<<(ostream & out, LinkedFifo& f);
	~LinkedFifo();
};

int main()
{
	//Zadanie 1
	cout << "Zadanie 1\n\n";
	ArrayStack s(6);
	cout << "s.empty() [1]: " << s.empty() << "\n";
	cout << "s.push(4) [1]: " << s.push(4) << "\n";
	cout << "s.empty() [0]: " << s.empty() << "\n";
	cout << "s.push(6) [1]: " << s.push(6) << "\n";
	cout << "s.push(7) [1]: " << s.push(7) << "\n";
	cout << "s.push(8) [1]: " << s.push(8) << "\n";
	cout << "s.full() [0]: " << s.full() << "\n";
	cout << "s.push(10) [1]: " << s.push(10) << "\n";
	cout << "s.push(12) [1]: " << s.push(12) << "\n";
	cout << "s.push(15) [0]: " << s.push(15) << "\n";
	cout << s;
	cout << "s.full() [1]: " << s.full() << "\n";
	cout << "s.peek() [12]: " << s.peek() << "\n";
	cout << "s.pop() [1]: " << s.pop() << "\n";
	cout << "s.peek() [10]: " << s.peek() << "\n";
	cout << "s.clear()\n"; s.clear();
	cout << "s.pop() [0]: " << s.pop() << "\n";

	
	//Zadanie 2
	cout << "\nZadanie 2\n\n";
	LinkedStack* s1 = new LinkedStack();
	cout << "s1->empty() [1]: " << s1->empty() << "\n";
	cout << "s1->peek() [-1]: " << s1->peek() << "\n";
	cout << "s1->push(2) [1]: " << s1->push(2) << "\n";
	cout << "s1->push(4) [1]: " << s1->push(4) << "\n";
	cout << "s1->push(5) [1]: " << s1->push(5) << "\n";
	cout << s1;
	cout << "s1->peek() [5]: " << s1->peek() << "\n";
	cout << "s1->pop() [1]: " << s1->pop() << "\n";
	cout << "s1->peek() [4]: " << s1->peek() << "\n";
	cout << "s1->empty() [0]: " << s1->empty() << "\n";
	cout << "s1->clear()\n"; s1->clear();
	cout << "s1->empty() [1]: " << s1->empty() << "\n";
	cout << "s1->peek() [-1]: " << s1->peek() << "\n";


	//Zadanie 3
	cout << "\nZadanie 3\n\n";
	ArrayFifo f(6);
	cout << "f.empty() [1] : " << f.empty() << "\n";
	cout << "f.enqueue(3) [1] : " << f.enqueue(3) << "\n";
	cout << "f.enqueue(5) [1] : " << f.enqueue(5) << "\n";
	cout << "f.enqueue(6) [1] : " << f.enqueue(6) << "\n";
	cout << "f.enqueue(8) [1] : " << f.enqueue(8) << "\n";
	cout << f;
	cout << "f.peek() [8] : " << f.peek() << "\n";
	cout << "f.dequeue() [1] : " << f.dequeue() << "\n";
	cout << f;
	cout << "f.enqueue(9) [1] : " << f.enqueue(9) << "\n";
	cout << "f.enqueue(13) [1] : " << f.enqueue(13) << "\n";
	cout << "f.enqueue(15) [1] : " << f.enqueue(15) << "\n";
	cout << "f.enqueue(16) [0] : " << f.enqueue(16) << "\n";
	cout << f;
	cout << "f.clear()\n"; f.clear();
	cout << "f.empty() [1] : " << f.empty() << "\n";
	cout << "f.clear()\n"; f.clear();


	//Zadanie 4
	cout << "\nZadanie 4\n\n";
	LinkedFifo* f1 = new LinkedFifo();
	cout << "f1->empty() [1]: " << f1->empty() << "\n";
	cout << "f1->enqueue(1) [1] : " << f1->enqueue(1) << "\n";
	cout << "f1->enqueue(2) [1] : " << f1->enqueue(2) << "\n";
	cout << "f1->enqueue(4) [1] : " << f1->enqueue(4) << "\n";
	cout << "f1->empty() [0]: " << f1->empty() << "\n";
	cout << *f1;
	cout << "f1->peek() [1]: " << f1->peek() << "\n";
	cout << "f1->dequeue() [1] : " << f1->dequeue() << "\n";
	cout << *f1;
	cout << "f1->peek() [2]: " << f1->peek() << "\n";
	cout << "f1->clear()\n"; f1->clear();
	cout << "f1->empty() [1]: " << f1->empty() << "\n";
	cout << *f1;

	return 0;
}

//Zadanie 1
ArrayStack::ArrayStack(int c)
{
	items = new int[c];
	capacity = c;
	top = -1;
}

bool ArrayStack::empty()
{
	return top == -1;
}

bool ArrayStack::full()
{
	return top == capacity - 1;
}

bool ArrayStack::push(int x)
{
	if (!full())
	{
		top++;
		items[top] = x;
		return true;
	}
	return false;
}

int ArrayStack::peek()
{
	return items[top];
}

bool ArrayStack::pop()
{
	if (empty())
	{
		return false;
	}
	top--;
	return true;
}

void ArrayStack::clear()
{
	top = -1;
}

ostream& operator<<(ostream& out, ArrayStack& s)
{
	for (int i = s.top; i >= 0; i--)
	{
		out << s.items[i] << " ";
	}
	out << "\n";

	return out;
}

ArrayStack::~ArrayStack()
{
	delete[] items;
}


//Zadanie 2

Element::Element(int x, Element* next)
{
	v = x;
	setNext(next);
}

int Element::getValue()
{
	return v;
}

Element* Element::getNext()
{
	return next;
}

void Element::setNext(Element* p)
{
	next = p;
}

LinkedStack::LinkedStack()
{
	top = nullptr;
}

bool LinkedStack::empty()
{
	return top == nullptr;
}

bool LinkedStack::push(int x)
{
	Element* e = new Element(x, top);
	if (empty())
	{
		top = e;
	}
	else
	{
		Element* temp = top;
		top = e;
		e->setNext(temp);
	}

	return true;
}

int LinkedStack::peek()
{
	if (empty())
	{
		return -1;
	}
	return top->getValue();
	
}

bool LinkedStack::pop()
{
	if (!empty())
	{
		top = top->getNext();
		return true;
	}
	return false;
}

void LinkedStack::clear()
{
	top = nullptr;
}

ostream& operator<<(ostream& out, LinkedStack* s)
{
	Element* e = s->top;
	while (e != nullptr)
	{
		out << e->getValue() << " ";
		e = e->getNext();
	}
	out << "\n";

	return out;
}

LinkedStack::~LinkedStack()
{
	delete top;
}


//Zadanie 3
ArrayFifo::ArrayFifo(int c)
{
	items = new int[c];
	capacity = c;
	size = 0;
	head = 0;
	tail = -1;
}

bool ArrayFifo::empty()
{
	return size == 0;
}

bool ArrayFifo::full()
{
	return size == capacity;
}

bool ArrayFifo::enqueue(int x)
{
	if (!full())
	{
		tail = (tail + 1) % capacity;
		items[tail] = x;
		size++;
		return true;
	}
	return false;
}

int ArrayFifo::peek()
{
	return items[tail];
}

bool ArrayFifo::dequeue()
{
	if (!empty())
	{
		head = (head + 1) % capacity;
		size--;
		return true;
	}
	return false;
}

void ArrayFifo::clear()
{
	size = 0;
	head = 0;
	tail = -1;
}

ostream& operator<<(ostream& out, ArrayFifo& f)
{
	int h = f.head;

	for (int i = f.size; i > 0; i--)
	{
		out << f.items[h] << " ";
		h = (h + 1) % f.capacity;
	}
	out << "\n";

	return out;
}

ArrayFifo::~ArrayFifo()
{
	delete[] items;
}


//Zadanie 4

LinkedFifo::LinkedFifo()
{
	head = nullptr;
	tail = nullptr;
}

bool LinkedFifo::empty()
{
	return head == nullptr;
}

bool LinkedFifo::enqueue(int x)
{
	Element* e = new Element(x, nullptr);
	if (empty())
	{
		tail = e;
		head = e;
	}
	else
	{
		//Element* pom = tail;
		tail->setNext(e);
		tail = e;
	}

	return true;
}

int LinkedFifo::peek()
{
	if (empty())
	{
		return -1;
	}
	return head->getValue();
}

bool LinkedFifo::dequeue()
{
	if (!empty())
	{
		head = head->getNext();
		return true;
	}
	return false;
}

void LinkedFifo::clear()
{
	tail = nullptr;
	head = nullptr;
}

ostream& operator<<(ostream& out, LinkedFifo& f)
{
	Element* e = f.head;
	while (e != nullptr)
	{
		out << e->getValue() << " ";
		e = e->getNext();
	}
	out << "\n";

	return out;
}

LinkedFifo::~LinkedFifo()
{
	delete head;
	delete tail;
}