#include <iostream>
#include <queue> 


template<class T> 
class Node {
public: 
    Node* next; 
    T value; 
    
    Node(const T &value)
    : value(value) {
        next = nullptr; 
    }
}; 

template<class T> 
class Queue {
    Node<T> *first, *last; 
    int length; 

public: 
    Queue(const T &value = NULL) {
        Node* newNode = new Node(value); 
        first = newNode; 
        last = newNode;
        
        length = 1; 
    }

    void Enqueue(const T &value) {
        Node* newNode = new Node(value); 

        if(length == 0) {
            first = newNode; 
            last = newNode; 
        }
        else {
            last->next = newNode; 
            last = newNode; 
        }

        length++; 
    }

    int Dequeue() {
        if(length == 0)
            return INT32_MIN; 
        
        Node* temp = first; 
        int dequeuedValue = temp->value; 

        if(length == 1) {
            first = nullptr; 
            last = nullptr;    
        }
        else {
            first = temp->next; 
            temp->next = nullptr; 
        }
        delete temp; 
        length--; 
        return dequeuedValue; 
    }

    void printQueue() {
        Node* temp = first; 
        for(int i = 0; temp != nullptr; i++) {
            std::cout << temp->value << ' '; 
            temp = temp->next; 
        }
        std::cout << '\n'; 
    }

    bool isEmpty() {
        if(!first && !last) 
            return true; 

        return false; 
    }

    ~Queue() {
        Node* temp = first; 

        while(first != nullptr) {
            first = temp->next; 
            temp->next = nullptr; 
            delete temp; 
            temp = first; 
        }
    }
};


consteval int add(int a, int b) {
    return a + b; 
}

int main(void) {
    constexpr int a = add(5, 10); 

    Queue<std::string> queue; 

    std::cin.get(); 
}
