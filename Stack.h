#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include <iostream>

class StackArray{
private:
    int size;
    int top ;
    int* stackArr;

    //call this function when there is no more empty space in the stack
    void resize(){
        int newSize = size * 2;
        int *newStackArr = new int[newSize];
        for (int i = 0; i < size; ++i) {
            newStackArr[i] = stackArr[i];
        }

        delete[](stackArr);
        stackArr = newStackArr;
        size = newSize;
    }

public:
    StackArray(int size){
        this->size = size;
        this->top = -1;
        this->stackArr = new int[size];
    }

    ~StackArray(){
        delete [] stackArr;
    }


    void push(int data){
        //there is no more space
        if(top == size -1){
            this->resize();
        }
        stackArr[++top] = data;
    }

    int pop(){
        //if the stack is empty
        if(top == -1){
            std::cout << "Stack id empty" << std::endl;
            return -1;
        }

        return stackArr[top--];
    }
};


class StackLinkedList{
public:
    class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
    };

private:
    Node* top;

public:
    StackLinkedList(){
        this->top = NULL;
    }

    ~StackLinkedList(){
        while(top != NULL){
            Node* temp = top;
            top = top->next;
            delete(temp);
        }
    }

    void push(int data){
        Node* newData = new Node(data);

        //add first
        if(top == NULL)
            top = newData;
        else{
            newData->next = top;
            top = newData;
        }
    }

    int pop(){
        //if stack is empty
        if(top == NULL){
            std::cout << "Stack id empty" << std::endl;
            return -1;
        }
        int Data = top->data;
        Node* temp = top;
        top = top->next;
        delete(temp);
        return Data;
    }
};

#endif //DATASTRUCTURE_STACK_H
