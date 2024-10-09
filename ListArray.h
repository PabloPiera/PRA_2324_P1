#include <iostream>
#include "List.h"
#include <stdexcept>

using namespace std;
template <typename T>

class ListArray : public List<T> {

    private:
        T*arr;
	int max;
	int n;
	static const int MINSIZE = 2;
	void resize(int new_size){
                T *nuevo_array = new T[new_size];
                for(int i = 0; i < new_size;  i++){
                        nuevo_array[i] = arr[i];
                }
                delete[] arr;
                arr = nuevo_array;
                max = new_size;
        }
    public:
        ListArray(){
	arr = new T[MINSIZE];
	max = MINSIZE;

	}
    	~ListArray(){
		delete[] arr;
	}
	T& operator[](int pos){
	try{
		if(pos < 0 || pos > size()-1){
			throw out_of_range("Posición no valida");
		}
	}
	catch (const out_of_range &e) {
        	cout << "Excepción capturada: " << e.what() << endl;
   	}
	return arr[pos];
	}
	friend std::ostream&operator<<(std::ostream &out, const ListArray<T> &list){}
	
};
