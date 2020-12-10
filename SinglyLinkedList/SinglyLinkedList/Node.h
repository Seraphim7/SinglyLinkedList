#pragma once

template <typename Type>
struct Node
{
	Type data;
	Node<Type>* next;
};