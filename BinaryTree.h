#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include <crtdbg.h>
#include <iostream>

class BinaryTree{
public:
    class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
    };


private:
    Node* root;
    int size;

public:
    BinaryTree(){
        this->root = NULL;
    }

    ~BinaryTree(){
        this->deleteTree(this->root);
    }

    void insertTemp(int data, Node* root){
        if(root == NULL){
            root = new Node(data);
            return;
        }

        if(data < root->data){
            if(root->left != NULL){
                insertTemp(data, root->left);
            } else{
                root->left = new Node(data);
                this->size++;
            }
        }
        else if(data > root->data){
            if(root->right != NULL){
                insertTemp(data, root->right);
            } else{
                root->right = new Node(data);
                this->size++;
            }
        }
    }

    void insert(int data){
        this->insertTemp(data, this->root);
    }

    Node* findNext(Node* root){
        while(root->left != NULL)
            root = root->left;
        return root;
    }


    void removeTemp(int data, Node* root){
        if(root == NULL)
            return;

        if(data < root->data)
            removeTemp(data, root->left);

        else if(data > root->data)
            removeTemp(data, root->right);

        //find the data
        else{
            //no sons
            if(root->left == NULL && root->right == NULL){
                delete root;
                root = NULL;
            }

            else if(root->left == NULL){
                Node* temp = root;
                root = root->right;
                delete temp;
            }

            else if(root->right == NULL){
                Node* temp = root;
                root = root->left;
                delete temp;
            }

            else{
                Node* temp = findNext(root->right);
                root->data = temp->data;
                removeTemp(temp->data, root->right);
            }
            this->size--;
        }
    }

    void remove(int data){
        this->removeTemp(data, this->root);
    }

    void deleteTree(Node* root){
        while(root != NULL){
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }

    void preorder(Node* root)
    {
        if(root != NULL)
        {
            std::cout << "Node key: " << root->data << std::endl;
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node* root)
    {
        if(root != NULL)
        {
            inorder(root->left);
            std::cout << "Node key: " << root->data << std::endl;
            inorder(root->right);
        }
    }

    void postorde(Node* root)
    {
        if(root != NULL)
        {
            postorde(root->left);
            postorde(root->right);
            std::cout << "Node key: " << root->data << std::endl;
        }
    }

    int getSize(){
        return this->size;
    }

};

#endif //DATASTRUCTURE_BINARYTREE_H
