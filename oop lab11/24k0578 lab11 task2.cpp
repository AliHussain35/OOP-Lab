#include <iostream>
#include <string>
using namespace std;
class StackOverflowException : public exception{
    public:
        const char* what ()const noexcept override{
            return "Stack is full";
        }
};
class StackUnderflowException : public exception{
    public:
        const char* what ()const noexcept override{
            return "Stack is empty"<<endl;
        }
};
template<typename T>
class Stack{
    private:
        int capacity;
        T *elements;
        int index;
    public:
        Stack(int c) : index (0), capacity(c){
            elements = new T [capacity];
        }
        ~Stack (){
            delete [] elements;
        }
        void push(T item){
            if(index == capacity){
                throw StackOverflowException();
            } else {
                elements[index] = item;
                cout<<"Element "<<elements[index]<<" pushed at Index = "<<index<<endl;
                index++;
            }
        }

        void pop(){
            if(index == 0){
                throw StackUnderflowException();
            }else{
                cout<<"Element "<<elements[index - 1] <<" popped at index =  "<<index - 1<<endl;
                index--;
            }
        }
};

int main () {
    int capacity = 3;
    Stack<double>myStack(capacity);
    try{
        for(int i = 0; i < capacity + 1; i++){
            myStack.push(i + 2.4);
        }
    }catch(const StackOverflowException &e){
        cout<<"Pushing to a full Stack =  "<<e.what()<<endl;
    }
    try{
        for(int i = 0; i<capacity + 1; i++){
            myStack.pop();
        }
    }catch(const StackUnderflowException &e){
        cout<<"Popping from an empty Stack =  "<<e.what()<<endl;
    }
}
