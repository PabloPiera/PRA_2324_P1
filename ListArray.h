#include <iostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T*arr;
	int max;
	int n;
	static const int MINSIZE = 2;

    public:
        ListArray(){
	
	}
    	~ListArray(){}
	T operator[](int pos){}
	friend std::ostream&operator<<(std::ostream &out, const ListArray<T> &list){}
	void resize(int new_size){
		T *nuevo_array = new array[new_size];
		for(int i = 0; i < new_size;  i++){
			nuevo_array[i] = arr[i];
		}
		delete[] arr;
		arr = nuevo_array;
		max = new_size
};
