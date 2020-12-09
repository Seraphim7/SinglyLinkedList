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
		void removeAllR(Node<Type>* head);
		Node<Type>* head;
};