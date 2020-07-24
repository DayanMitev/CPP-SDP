
#pragma once
#include <iostream>	
#include <cassert>
#include <algorithm>
template <typename T>
struct Node
{
	Node* prev, *next;
	T val;

	Node() : prev(nullptr), next(nullptr) {}

	Node(const T& val, Node* prev = nullptr, Node* next = nullptr)
		: val(val) , prev(prev), next(next) 
	{}
};

template <typename T>
class List
{
public:
	List();
	List(const List<T>& rhs);
	~List();

	List& operator= (const List<T>& rhs);

	void Clear();
	void Assign(const List<T>& rhs);
	bool Empty() const;

	void InsertFront(const T& val);
	void InsertBack(const T& val);
	void InsertAfter(Node<T>* it, const T& val);
	void InsertBefore(Node<T>* it, const T& val);

	void RemoveFront();
	void RemoveBack();
	void RemoveAt(Node<T>* it);

	T& Front();
	const T& Front() const;
	T& Back();
	const T& Back() const;

	Node<T>* Begin();
	const Node<T>* ConstBegin() const;
	Node<T>* PastEnd();
	const Node<T>* ConstPastEnd() const;

	bool isLinked() const;
private:
	Node<T> dummy;

};

template <typename T>
List<T>::List()
{
	dummy.prev = &dummy;
	dummy.next = &dummy;
}

template <typename T>
List<T>::List(const List<T>& rhs) : List()
{
	Assign(rhs);
}

template <typename T>
List<T>::~List()
{
	Clear();
}

template <typename T>
List<T>& List<T>::operator= (const List<T>& rhs)
{
	Assign(rhs);
}

template <typename T>
void List<T>::Clear()
{
	while (!Empty()) RemoveFront();
}

template <typename T>
void List<T>::Assign(const List<T>& rhs)
{
	List<T> tmp;
	const Node<T>* it = rhs.dummy.next;

	while (it != &rhs.dummy)
	{
		tmp.InsertBack(it->val);
		it = it->next;
	}

	Clear();
	if (!tmp.Empty())
	{
		// code duplication
		// fix: create static void Link(Node<T>* node, Node<T>* prevNode, Node<T>* nextNode)
		// e.g: Link(&dummy, tmp.dummy.prev, tmp.dummy.next)
		dummy.next = tmp.dummy.next;
		dummy.prev = tmp.dummy.prev;
		dummy.next->prev = &dummy;
		dummy.prev->next = &dummy;

		tmp.dummy.next = &tmp.dummy;
		tmp.dummy.prev = &tmp.dummy;
	}
}

template <typename T>
bool List<T>::Empty() const
{
	return dummy.next == &dummy;
}


template <typename T>
void List<T>::InsertFront(const T& val)
{
	InsertAfter(&dummy, val);
}

template <typename T>
void List<T>::InsertBack(const T& val)
{
	InsertBefore(&dummy, val);
}

template <typename T>
void InsertAfter(Node<T>* it, const T& val)
{
	Node<T>* newNode = new Node<T>(val, it, it->next);
	it->next->prev = newNode;
	it->next = newNode;
}

template <typename T>
void List<T>::InsertBefore(Node<T>* it, const T& val)
{
	Node<T>* newNode = new Node<T>(val, it->prev, it);
	it->prev->next = newNode;
	it->prev = newNode;
}

template <typename T>
void List<T>::RemoveFront()
{
	RemoveAt(dummy.next);
}

template <typename T>
void List<T>::RemoveBack()
{
	RemoveAt(dummy.prev);
}

template <typename T>
void List<T>::RemoveAt(Node<T>* it)
{
	assert(it != &dummy);

	it->next->prev = it->prev;
	it->prev->next = it->next;
	delete[] it;
}

template <typename T>
T& List<T>::Front()
{
	assert(!Empty());
	return dummy.next->val;
}

template <typename T>
const T& List<T>::Front() const
{
	assert(!Empty());
	return dummy.next->val;
}

template <typename T>
T& List<T>::Back()
{
	assert(!Empty());
	return dummy.prev->val;
}

template <typename T>
const T& List<T>::Back() const
{
	assert(!Empty());
	return dummy.prev->val;
}

template <typename T>
Node<T>* List<T>::Begin()
{
	return dummy.next;
}

template <typename T>
const Node<T>* List<T>::ConstBegin() const
{
	return dummy.next;
}

template <typename T>
Node<T>* List<T>::PastEnd()
{
	return &dummy;
}

template <typename T>
const Node<T>* List<T>::ConstPastEnd() const
{
	return &dummy;
}
template <typename T>
bool List<T>::isLinked() const
{
	Node<T>* a = dummy.next;
	Node<T>* b = dummy.next;
	while (a->next != dummy.prev)
	{
		if (a->next->prev == b && b->next == a->next)
		{
			b = b->next;
			a = a->next;
		}
		else
			return false;
	}
	return true;

}

