#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include <iostream>

class QueueArray{
private:
    int front, rear, numOfElements, size;
    int* QueueArr;

public:
    QueueArray(int size){
        this->front = this->rear = -1;
        this->numOfElements = 0;
        this->size = 0;
        this->QueueArr = new int[size];
    }

    ~QueueArray(){
        delete[](this->QueueArr);
    }


    void resize(){
        //allocate the new size
        int newSize = this->size * 2;
        int* newArr = new int[newSize];

        //copy the data
        for (int i = 0; i < this->size; ++i) {
            newArr[i]= this->QueueArr[(front + i) % this->size];
        }

        //delete older data
        delete [] this->QueueArr;
        this->QueueArr = newArr;
        front = 0;
        rear = numOfElements - 1;
        this->size = newSize;
    }


    void engueue(int data){

        //if there is no empty space in the queue, we should resize it.
        if(this->numOfElements == size){
            this->resize();
        }

        //if there is.
        //find the place of the element.
        //if its the first element to add
        if(front == -1 && rear == -1){
            front = rear = 0;
        }
        else{
            rear = (rear + 1) % this->size;
        }

        //add it
        this->QueueArr[rear] = data;
        this->numOfElements++;
        return;
    }


    int dequeue(){

        //if the queue is empty
        if(this->numOfElements == 0){
            std::cout << "The queue is empty" << std::endl;
            return -1;
        }

        //if we here the queue is not empty
        int element = this->QueueArr[front];

        //now we should update the front
        //check if it the last element in the queue
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % size;
        }

        this->numOfElements--;
        return element;
    }

    int getNumOfElements(){
        return this->numOfElements;
    }

};

class QueueLinkedList{

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
    Node* front;
    Node* rear;
    int numOfElements;

public:
    QueueLinkedList(){
        this->front = this->rear = NULL;
    }

    void engueue(int data){
        Node* newNode = new Node(data);

        //if its the first element
        if(rear = NULL){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        this->numOfElements++;
        return;
    }

    ~QueueLinkedList(){
        this->numOfElements = 0;
        Node* next;
        while(front != NULL){
            next = front->next;
            delete(front);
            front = next;
        }
    }

    int dequeue(){

        //if the list is empty
        if(front == NULL){
            std::cout << "The queue is empty" << std::endl;
            return -1;
        }

        //if we here the list contain at least one element
        Node* element = this->front;

        //update the queue
        //check if it the last element
        if(front == rear){
            front = rear = NULL;
        }
        else{
            front = front->next;
        }

        int elementData = element->data;
        delete(element);
        return elementData;
    }

    int getNumOfData(){
        return this->numOfElements;
    }
};

#endif //DATASTRUCTURE_QUEUE_H
