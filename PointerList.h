/* Anand Patel
CS 260 - HW 2
Pointer Implementation on a sorted list
INSERT, DELETE, & LOCATE
*/
#include <iostream>
using namespace std;

#ifndef POINTERLIST
#define POINTERLIST

template <typename E>
class Node{
	public:
		E element;
		Node();
		Node* next;
}

template <typename E>
Node<E>::Node(){}

template <typename E>
class List{
	private:
		Node<E> *header;
	public:
		List();
		Node<E> *LOCATE(E ele);
		void INSERT(E x, Node<E> *p);
		void DELETE(Node<E> *p);
}

template <typename E>
List<E>::List(){ header = new Node<E>();}

// INSERT
template <typename E>
void List<E>::INSERT(E x, Node<E> *p){
	Node<E> *temp = new Node<E>();
	temp -> next = p -> next;
	temp -> element = x;
	p -> next = temp;
}

// DELETE
template <typename E>
void List<E>::DELETE(Node<E> *p){
	Node<E> *nextNode = p -> next;
	p -> next = p -> next -> next;
	delete(nextNode);
}

// LOCATE
template <typename E>
Node<E> *List<E>::LOCATE(E x){
	Node<E> *p = header;
	while(p -> next != NULL){
		if(p -> next -> element == x){
			// found it!
			return p;
		} else{
			// move onto the next one
			p = p -> next;
		}
	}
	
	//ah, we didn't find it
	return p;
}
#endif