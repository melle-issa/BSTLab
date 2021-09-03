#include "Node.h"

Node::Node(string key){
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
    this->Parent = nullptr;
    this->count = 1;
}

int Node::getCount(){

    //cout<<"count: " << this->count<<endl;
    return this->count;
}

string Node::getKey(){
    //cout<< "key: "<< this->key << endl;
    return this->key;
}

void Node::increaseCount(){
    int currCount = this->getCount();
    this->count = currCount + 1;
    
}

void Node::decreaseCount(){
    int currCount = this->getCount();
    this->count = currCount - 1;
}

bool Node::isLeaf(){
    if(this->left == nullptr && this->right == nullptr){
        return true;
    }
    return false;
}




bool Node::hasMultiples(){
    if(this->count > 1){
        return true;
    }
    return false;
}

void Node::setParent(Node* par){
    this->Parent = par;
}

Node* Node::getParent(){
    return this->Parent;
}

void Node::printNode(){
    cout<< this->getKey() << "("<< this->count<<"), ";
}
