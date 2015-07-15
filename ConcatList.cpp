/* Anand Patel
CS 260 - HW 2
2.4 - concatenate a list of lists
*/
#include <iostream>
#include <ArrayList.h>
using namespace std;

List<int> ConcatList(List<List<int>> L){
	List<int> temp;
	List<int> num;
	int i = L.FIRST();
	
	// continue for list 
	while(i != L.END()){
		
		// retrieve elements
		temp = L.RETRIEVE(i);
		int j = temp.FIRST();
		
		// while second list is empty, insert into result 
		while(j != temp.END()){
			num.INSERT(temp.RETRIEVE(j), num.END());
			j = temp.NEXT(j);
		}
		
		// move on
		p = L.NEXT(p);
	}
	
	return num;
}

int main(){
	List<List<int>> L;
	List<int> result;
	List<int> List1;
	List<int> List2;
	
	// test with the first list 
	cout << "List1 = [123, 456]" << endl;
	List1.INSERT(123, List1.FIRST());
	List1.INSERT(456, List1.FIRST());
	
	// test with second list
	cout << "List2 = [789, 999, 1549]" << endl;
	List2.INSERT(789, List2.FIRST());
	List2.INSERT(999, List2.FIRST());
	List2.INSERT(1549, List2.FIRST());
	
	// combine lists 
	cout << "L1 and L2 are now to be concatenated into a list of lists" << endl;
	L.INSERT(List2, L.FIRST());
	L.INSERT(List1, L.FIRST());
	
	// print results 
	concatenatedList = ConcatList(L);
	concatenatedList.PRINTLIST();
	cout << endl;
}