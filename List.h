#pragma once
#include<iostream>
template<class T> struct Node {

    T* Data;
    Node<T>* Next;
    Node<T> *Prev;
    Node(T* data) {
        this->Data = data;
        Next = NULL;

    }
};

template<class T> struct Value{
    T value;
    T* ptr = &value;
};

template<class T>
class List {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
protected:
    int size;
public:
    //Constructor without params
    List() {
        size = 0;
        head = NULL;
    }
    ~List(){
        if((head == nullptr) || (size == 0)){
            delete head;
            size = 0;
        }else{
            for(;head->Next != nullptr;){
                Node<T>* temp = head;
                head = temp->Next;
                delete temp;
            }
            delete head;
            size = 0;
        }
    }

    T* pop_back() {// Erases the element at the end of the list
        if (head) {
            Node<T>* tail = new Node<T>(NULL);
            for (Node<T>* i = head; i != NULL; i = i->Next) {
                if (i->Next == NULL)
                    tail = i;
            }
            T* temp = tail->Data;
            Node<T>* p = tail;
            tail = p->Prev;
            tail->Next = NULL;
            size--;
            return temp;
        } else
            return NULL;
    }
    T* pop_front(){ // Erases the element at the start of the list
        if (head) {
            T* temp = head->Data;
            Node<T>* p = head;
            head = p->Next;
            delete[] p;
            size--;
            return temp;
        } else
            return NULL;

    }
    friend bool operator +(List<T>& firstList, List<T>& secondList){
        int s = firstList.size;
        int s2 = secondList.size;
        T array[s+s2];
        int j=0;
        for(Node<T>* i = secondList.head; i != NULL; i = i->Next){
            array[j]=*i->Data;
            j++;
        }
        /*for(int i = 0 ; i < s2;i++){
            std::cout<<array[i]<<" ";
        }*/
        std::cout<<std::endl;
        List<T> resList;
        for(int i = 0; i < s2;i++){
            auto val = new Value<T>;
            val->value=array[i];
            firstList.push_back(val->ptr);
        }

        return true;
    }

    void push_front(T* data) {// Adds an element to the start of the list
        size++;
        if (head != NULL) {
            Node<T> *temp = new Node<T>(data);
            temp->Next = head;
            head->Prev = temp;
            head = temp;
        } else {
            head = new Node<T>(data);
        }
    }
    void push_back(T* data){ // Adds an element to the end of the list
        size++;
        if (head != NULL) {
            Node<T>* tail = new Node<T>(NULL);
            for (Node<T>* i = head; i != NULL; i = i->Next) {
                if (i->Next == NULL)
                    tail = i;
            }
            Node<T>* temp = new Node<T>(data);
            tail->Next = temp;
            temp->Prev = tail;
            tail = temp;
        } else {
            head = new Node<T>(data);
        }
    }

    int size_list() {// Returns the number of elements in the list
        return size;
    }

    const std::string isEmpty() {
        return size == 0?"true":"false";
    }

    T& operator= (const List& obj) {
        if (this == &obj)
            return *this;
        if (!obj.head)
            return *this;
        head = new Node<T>(obj.head->Data);
        Node<T>* temp = obj.head->Next;
        Node<T>* pnew = 0;
        Node<T>* pold = head;
        while (temp) {
            pnew = new Node<T>(temp->Data);
            pnew->Prev = pold;
            pold->Next = pnew;
            pold = pnew;
            temp = temp->Next;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const List<T>& obj) {
        for (Node<T>* i = obj.head; i != NULL; i = i->Next)
            os << *i->Data  << " ";
        return os;
    }
    friend std::istream& operator>> (std::istream& is, const List<T>& obj){
        obj.push_back();
    }

    T& operator[](const int x){
        int cnt = 0;
        for(Node<T>* i = this->head;i != nullptr;i = i->Next){
            if(cnt == x)
                return *i->Data;
            cnt++;
        }
    }
    T& createArray(T* array, int n){
        int j = 0;
        for(Node<T>* i = this->head ;i != NULL; i = i->Next){
            array[j] = *i->Data;
            j++;
        }
        return *array;
    }

};
