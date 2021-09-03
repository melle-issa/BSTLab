#include <iostream>
#include <string>
#include <vector>

#ifndef NODE_H_
#define NODE_H_


using namespace std;


class Node{
    private:
        string key;
        int count;
    public:
        Node(string );
        Node* left;
        Node* right;
        Node* Parent;

        int getCount();
        string getKey();
        void increaseCount();
        void decreaseCount();
        bool isLeaf();
        void setParent(Node* );
        Node* getParent();
        bool hasMultiples();
        void printNode();
};

#endif