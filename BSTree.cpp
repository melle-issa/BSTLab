#include <iostream>
#include <string>
#include "BSTree.h"
#include "Node.h"


BSTree::BSTree(){
    this->root = nullptr;
    this->size = 0;
}

void BSTree::insert(const string &k){
    if(this->root == nullptr){
        Node* n = new Node(k); // case i) tree is empty.
        this->root = n;
        return;
    }

    if(this->search(k)){//case ii) increase count of Node
        Node* c = this->root;
        while(c != nullptr){
            if(k == c->getKey())
            {
                c->increaseCount();
                break;
            }
            else if(k < c->getKey()){
                c = c->left;
            }
            else{
                c = c->right;
            }
        }
    }
    else
    {
        Node* curr = this->root;
        Node* n = new Node(k);
        while(curr != nullptr)
        {
            if(n->getKey() < curr->getKey()) 
            {
                if(curr->left == nullptr){ //assigning to left
                    n->setParent(curr);
                    curr->left = n;
                    curr = nullptr;
                }
                else
                {
                    curr = curr->left;
                }
            }

            else
            {
                if(curr->right == nullptr)
                {
                    n->setParent(curr);
                    curr->right = n;
                    curr = nullptr;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
    }
}

bool BSTree::search(const string &k) const{
    bool keyFound = false;
    Node* curr = this->root;
    while(curr != nullptr)
    {
        if(k == curr->getKey())
        {
            keyFound = true;
            curr = nullptr; 
        }
        else if(k < curr->getKey()){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        
        }
    }
    if(keyFound){
        cout<< k << " was found in list"<< endl;
    }
    else{
        cout<< "key not found"<< endl;
    }
    return keyFound;

}


string BSTree::largest() const{
    Node* curr = this->root;
    string largestStr = "";

    if(this->root == nullptr){
        return largestStr;
    }
    while(curr != nullptr){
        if(curr->right == nullptr){
            largestStr = curr->getKey();
            break;
        }
        else{
            curr = curr->right;
        }
    }
    return largestStr;
}

string BSTree::smallest() const{
    Node* curr = this->root;
    string smallestStr = "";

    if(this->root == nullptr){
        return smallestStr;
    }
    while(curr != nullptr){
        if(curr->left == nullptr){
            smallestStr = curr->getKey();
            break;
        }
        else{
            curr = curr->left;
        }
    }
    return smallestStr;
}


int BSTree::height(const string &k) const{
    Node* curr = this->root;
    while(curr != nullptr){
        if(k == curr->getKey()){
            break;
        }
        else if(k < curr->getKey()){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }

    return (this->getHeight(curr));
}
int BSTree::getHeight(Node* n) const{
    Node* curr = n;
    int leftHeight;
    int rightHeight;
    if(curr == nullptr){
        return -1;
    }
    leftHeight = getHeight(curr->left);
    rightHeight = getHeight(curr->right);
    return (1 + max(leftHeight,rightHeight));
}



void BSTree::inOrder(Node* n) const{
    if(n == nullptr){
        return;
    }
    inOrder(n->left);
    n->printNode();
    inOrder(n->right);
}

void BSTree::inOrder() const{
    inOrder(this->root);
}




void BSTree::postOrder(Node* n) const{
    if(n == nullptr){
        return;
    }
    postOrder(n->left);
    postOrder(n->right);
    n->printNode();
}

void BSTree::postOrder() const{
    postOrder(this->root);
}




void BSTree::preOrder(Node* n) const{
    if(n == nullptr){
        return;
    }
    n->printNode();
    preOrder(n->left);
    preOrder(n->right);

}

void BSTree::preOrder()const{
    preOrder(this->root);
    
}

void BSTree::remove(const string &key){
    //bool onlyRightChild = false;
   // bool onlyLeftChild = false;
    //bool hasTwoChildren = false;
    Node* curr = this->root;
    Node* prev = curr;
    // Node* temp = nullptr;

    // if(key == this->root->getKey()){
    //     string rkey;
    //     if(curr->right != nullptr){
    //         temp = this->root->left;
    //         this->root = curr->right;
    //         delete curr;
    //         curr == nullptr;
            
    //         this->insert(temp->getKey());

    //         while(temp != nullptr){
    //             if(temp->left != nullptr){
    //                 this->insert(temp->getKey());
    //                 temp = temp->left;
    //             }
    //             else{
                    
    //             }
    //         }
    //}


    

    while(curr != nullptr){
        if(key == curr->getKey()){
            if(curr->isLeaf()){
                if(curr->getKey() < prev->getKey()){
                    prev->left = nullptr;
                    delete curr;
                    curr = nullptr;
                }
                else{
                    prev->right = nullptr;
                    delete curr;
                    curr = nullptr;
                }
            }
            else if(curr->right != nullptr && curr->left == nullptr){
                //onlyRightChild = true;
                if(prev->right == nullptr && curr->right->getKey() > prev->getKey() ){
                    prev->right = curr->right;
                    delete curr;
                    curr = nullptr;
                }
                else if(prev->right != nullptr && prev->right->getKey() < curr->right->getKey()){
                    prev->right = curr->right;
                    delete curr;
                    curr = nullptr;
                }
                else{
                    prev->left = curr->right;
                    prev->left->left = curr->left;
                    delete curr;
                    curr = nullptr;
                }
            }
            else if(curr->right == nullptr && curr->left != nullptr){
                //onlyLeftChild = true;
                prev->left = curr->left;
                delete curr;
                curr = nullptr;
            }
            else{
                //hasTwoChildren = true;
                prev->left =curr->left;
                delete curr;
                curr = nullptr;
            }
        }

        else if(key < curr->getKey()){
            prev = curr;
            curr = curr->left;

        }
        else if(key > curr->getKey()){
            prev = curr;
            curr = curr->right;
        }
        else{
            curr = nullptr;
        }
    }





}


bool BSTree::isTreeEmpty(){
    if(this->root == nullptr){
        return true;
    }
    return false;
}
