#pragma once
#include "Node.h"

template <typename Type>
class SinglyLinkedList
{
	public:
		SinglyLinkedList();
		void add(Type data);
		void removeAll();
		~SinglyLinkedList();

	private:
		void removeAllR(Node<Type>*& head);
		Node<Type>* head;
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
		head = newNode;
	else
	{
		newNode->next = head;
		head = newNode;
	}

	newNode = nullptr;
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