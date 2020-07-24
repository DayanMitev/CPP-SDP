
#include <iostream>

template<typename T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T& dt, Node<T>* nxt = nullptr)
	{
		data = dt;
		next = nxt;
	}
};

template <typename T>
class Queue
{
private:
	Node<T>* first;
	Node<T>* last;
	size_t size;

	void copy(const Queue& other)
	{
		Node<T>* temp = other.first;
		for (int i = 0; i < other.getSize(); i++)
		{
			this->push(temp->data);
			temp = temp->next;
		}
	}
	void erase()
	{
		while (!empty())
		{
			this->pop();
		}
	}

public:
	Queue()
	{
		first = nullptr;
		last = nullptr;
		size = 0;
	}
	Queue(const Queue& other)
	{
		this->copy(other);
	}
	Queue& operator=(const Queue& other)
	{
		if (this != &other)
		{
			this->erase();
			this->copy(other);
		}
		return *this;
	}
	~Queue()
	{
		this->erase();
	}
	const T& front() const
	{
		if (this->first != nullptr)
		{
			return first->data;
		}
		throw "Empty Queue";
	}
	const T& back() const
	{
		if (this->last != nullptr)
		{
			return this->last;
		}
		throw "Empty Queue";
	}
	void pop()
	{
		if (!empty())
		{
			Node<T>* temp = first;
			this->first = first->next;
			delete temp;
			--size;
		}
	}
	void push(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (empty())
		{
			this->first = newNode;
			this->last = newNode;
		}
		else
		{
			this->last->next = newNode;
			last = newNode;
		}
		size++;
	}
	bool empty() const
	{
		return size == 0;
	}
	size_t getSize() const
	{
		return size;
	}
	void print() const
	{
		Node<T>* temp = first;
		while (temp)
		{
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}

};



int main()
{
	Queue<int> q;
	q.push(12);
	q.push(153);
	q.push(184);
	q.pop();
	q.push(15);
	q.push(25);
	q.pop();
	q.pop();
	q.print();

	
}

