#pragma once
#include "Node.h"

template <class Type>
class SinglyLinkedList
{
	public:
		SinglyLinkedList();
		void add(Type data);
		void sort();
		void removeAll();
		~SinglyLinkedList();

	private:
		void sortR(Node<Type>* head, Node<Type>* tail, int size);
		void removeAllR(Node<Type>*& head);
		void count();
		void merge2Into1(Node<Type>* head, Node<Type>* tail, Node<Type>* otherHead, Node<Type>* otherTail, Type* tempArrayAlreadySorted, int i);
		bool isFirstListDataLargerEqualThanSecondListData(Type firstListData, Type secondListData);
		Node<Type>* head;
		Node<Type>* tail;
		int size;
};

// template implementations cannot be placed in cpp files because they cannot be compiled because they are generic. They do not know what type they are
template <class Type>
SinglyLinkedList<Type>::SinglyLinkedList()
{
	head = nullptr;
}

template <class Type>
void SinglyLinkedList<Type>::add(Type data)
{
	Node<Type>* newNode = new Node<Type>;
	newNode->data = data;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}

	newNode = nullptr;

	increaseCount();
}

template <class Type>
void SinglyLinkedList<Type>::sort()
{
	sortR(head, tail, size);
}

template <class Type>
void SinglyLinkedList<Type>::removeAll()
{
	removeAllR(head);
}

template <class Type>
SinglyLinkedList<Type>::~SinglyLinkedList()
{
	removeAllR(head);

	size = 0;
	tail = nullptr;
}

template <class Type>
void SinglyLinkedList<Type>::removeAllR(Node<Type>*& head)
{
	if (head == nullptr)
		return;

	removeAllR(head->next);

	delete head;
	head = nullptr;
}

template <class Type>
void SinglyLinkedList<Type>::count()
{
	size++;
}

template <class Type>
void SinglyLinkedList<Type>::merge2Into1(Node<Type>* head, Node<Type>* tail, Node<Type>* otherHead, Node<Type>* otherTail, Type* tempArrayAlreadySorted, int i)
{
	if (head == tail && otherHead == otherHead)
		return;
	else if (head == tail)
	{
		dumpRemainingContentsIntoArrayFromSubList(otherHead, otherTail tempArrayAlreadySorted, i);
		return;
	}
	else if (otherHead == otherTail)
	{
		dumpRemainingContentsIntoArrayFromSubList(head, tail tempArrayAlreadySorted, i);
		return;
	}
	else if (head->data <= otherHead->data)
	{
		insertIntoTempArray(tempArrayAlreadySorted, i, head->data);
		merge2Into1(head->next, otherHead, tempArrayAlreadySorted, i + 1);
	}
	else
	{
		insertIntoTempArray(tempArrayAlreadySorted, i, otherHead->data);
		merge2Into1(head, otherHead->next, tempArrayAlreadySorted, i + 1);
	}

	insertIntoListFromTempArray(head, otherTail, i)
}

template <class Type>
bool SinglyLinkedList<Type>::isFirstListDataLargerEqualThanSecondListData(Type firstListData, Type secondListData)
{
	if (firstListData >= secondListData)
		return true;

	return false;
}

template <class Type>
bool SinglyLinkedList<Type>::insertIntoTempArray(Type* tempArrayAlreadySorted, int i, Type dataToInsert)
{
	tempArrayAlreadySorted[i] = dataToInsert;
}

template <class Type>
void SinglyLinkedList<Type>::dumpRemainingContentsIntoArrayFromSubList(Node<Type>* head, Node<Type>* tail, Type* tempArrayAlreadySorted, int i)
{

}
