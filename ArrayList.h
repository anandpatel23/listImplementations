/* Anand Patel
CS 260 - HW 2
Array Implementation on a sorted list
INSERT, DELETE, & LOCATE
*/
#include <iostream>
using namespace std;

#ifndef ARRAYLIST
#define ARRAYLIST

template <typename E>
class List{
	private:
		E *items;
		int lastItem;
		int MAX;
	public:
		List();
		List(int size);
		void INSERT(E x, int p);
		void DELETE(int p);
		void LOCATE(E x) const;
		int FIRST() const;
		int END() const;
		E RETRIEVE(int p) const;
		int NEXT(int p) const;
		void PRINTLIST() const;
		
};

// INSERT 
template <typename E>
void List<E>::INSERT(E x, int p){
	// determine if the list is full
	if(MAX > lastItem){
		cout << "That's a full list!" << endl;
	}
	
	// determine is p is a valid position
	if((p < 1) || (p > lastItem + 1)){
		cout << "The position is invalid!" << endl;
	} else{
		for(int i = lastItem; i >= p; i--){
			items[i+1] = items[i];
		}
		items[p] = x;
		lastItem = lastItem + 1;
	}
}

// DELETE
template <typename E>
void List<E>::DELETE(int p){
	if((p < 1) || (p > lastItem + 1)){
		cout << "The position is invalid!" << endl;
	} else{
		// removing process
		lastItem = lastItem - 1;
		for(int i = p; i <= lastItem; i++){
			// items to be moved 1 position down
			items[i] = items[i+1]; 
		}
	}
}

// LOCATE
template <typename E>
void List<E>::LOCATE(E x) const{
	int i = 1;
	for(i = 1; i <= lastItem; i++){
		if(items[i] == x)
			return i;
	}
	
	// if doesn't return i, not found
	return lastItem + 1;
}

/////////////////////////////////////////////////////////////////////
/////// Concatenating a list of lists implementation (# 2.4) ////////
/////////////////////////////////////////////////////////////////////
template <typename E>
int List<E>::FIRST() const{ return 1; }

template <typename E>
int List<E>::END() const{ return lastItem + 1; }

template <typename E>
E List<E>::RETRIEVE(int p) const{
	if((last > p) && (1 <= p)){ return items[p]; }
}

template <typename E>
int List<E>::NEXT(int p) const{ return p + 1; }

template <typename E>
void List<E>::PRINTLIST() const{
	int i = 1;
	for(i = 1; i <= last; i++){
		cout << items[i] << " ";
	}
}
#endif