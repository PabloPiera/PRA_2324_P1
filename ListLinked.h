#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
	    Node<T>* first;
	    int max;
	    int n;

    public:
	    ListLinked(){
		    first = nullptr;
		    n=0;
	    }
	    ~ListLinked(){
		    do{
			    Node<T>* aux = first->next;
			    delete first;
			    first = aux;
		    }while(first!=nullptr);
	    }
	    T operator[](int pos){
		    if(pos < 0 || pos > size()-1){
			    throw std::out_of_range ("Posición invalida");
		    }
		    else{
			    Node<T>* actual = first;
			    int aux = 0;
			    while(aux < pos){
				    actual = actual->next;
				    aux++;
			    }
			    return actual->data;
		    }
	    }
	    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
    Node<T>* actual = list.first;
    
    if (actual == nullptr) {  
        out << "La lista está vacía.";
        return out;
    }
    
    while (actual != nullptr) {
        out << actual->data; 
        if (actual->next != nullptr) {
            out << " -> ";  
        }
        actual = actual->next;  
    }
    return out;
}


	    int size() const{
                return n;
	    }
	    bool empty(){
                if(size()==0){
                        return true;
                }
                else{
                        return false;
                }
	    }
	    void insert(int pos, T e){
		    int aux = 0;
		    if(pos < 0 || pos > size()){
			    	throw std::out_of_range("Fuera de rango");
		    }
		    else{
			Node<T>* newNode = new Node<T>{e, nullptr};
			if(pos == 0){
				newNode->next = first;
				first = newNode;
				n++;
			}
			else{
				Node<T>* prev = nullptr;
				Node<T>* aux = first;
				int i = 0;
				while (aux != nullptr && i < pos){
					prev = aux;
					aux = aux->next;
					i++;
				}
				prev->next = newNode;
				newNode->next = aux;
				n++;
			}
		
	    	}
	    }
	    void append(T e){
		insert(n, e);
	    }

	   void prepend(T e){
		   insert(0, e);
	   }
	   int search(T e){
		  int pos = 0;
		  int aux = -1;
		  Node<T>* actual = first;
		  while(actual != nullptr && pos < n){
			  if(actual->data == e){
				  aux = pos;
				  break;
			  }
			 actual = actual->next;
			 pos++;
		  }
		  return aux;
	   }
	   T get(int pos){
		   Node<T>* actual = first;
		   int aux = 0;
		   T valor;
		   if(pos < 0 || pos >= size()){
			   throw std:: out_of_range("Fuera de rango");
		   }
		   else if(pos == aux){
			   valor = actual->data;
		   }
		   else{
			   do{
				   actual = actual->next;
				   aux++;
				   if(aux == pos){
					   valor = actual->data;
				   }
			   }while(aux!=pos);
		   }
		   return valor;
	   }
	   T remove (int pos){
  		Node<T>* actual = first;
		Node<T>* prev = nullptr;
		int aux1=0;
		T aux;
		if(pos < 0 || pos >= size()){
                           throw std:: out_of_range("Fuera de rango");
                }
		else if(pos==0){
			first=first->next;
			aux = actual->data;
			delete actual;
		}
		else{
			while(aux1 < pos){
				prev = actual;
				actual = actual->next;
				aux1++;
			}
				aux = actual->data;
				prev->next = actual->next;
				delete actual;
		}
		n--;
		return aux;
	   }	
			


};
