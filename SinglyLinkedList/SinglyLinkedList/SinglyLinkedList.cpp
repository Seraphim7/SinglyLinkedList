#include "SinglyLinkedList.h"

template <typename Type>
SinglyLinkedList<Type>::SinglyLinkedList()
{
	head = nullptr;
}

template <typename Type>
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

	delete newNode;
}

template <typename Type>
void SinglyLinkedList<Type>::removeAll()
{
	removeAllR(head);
}

template <typename Type>
SinglyLinkedList<Type>::~SinglyLinkedList()
{
	removeAllR(head);
}

template <typename Type>
void SinglyLinkedList<Type>::removeAllR(Node<Type>* head)
{
	if (head == nullptr)
		return;

	removeAllR(head->next);
	
	delete head;
	head = nullptr;
}