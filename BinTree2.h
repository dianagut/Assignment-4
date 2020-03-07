// ------------------------------------------------ BinTree.h -------------------------------------------------------
// Diana Gutierrez CSS 343
// Date Created: 1/20/2020
// Date last modified: 2/1/2020
//--------------------------------------------------------------------------------------------------------------------
// Purpose - BinTree class declaration
// --------------------------------------------------------------------------------------------------------------------

#ifndef BinTree_h
#define BinTree_h
#include <iostream>
#include <string>
using namespace std;
#include "nodedata.h"

class BinTree2{
    //*** Overload <<: prints tree in inorder traversal
    friend ostream& operator<< (ostream &, const BinTree2& );
    
public:
    //Member functions
    BinTree2();
    BinTree2(const BinTree2&);
    ~BinTree2();
    
    int getHeight(NodeData&);// returns the height of given value in a tree
    bool insert(NodeData*);//inserts a new NodeData in a tree
    void makeEmpty();//deletes a tree
    bool isEmpty(); // checks if a tree is empty
    void bstreeToArray(NodeData *[]); // fills an array of NodeData using in order traversal
    void arrayToBSTree(NodeData* []);//builds a balanced BinTree using sorted array of NodeData
    bool retrieve(const NodeData&, NodeData* &);//gets NodeData object from a given tree
    void displaySideways();//prints tree sideways
    
    //Assignment operators
    BinTree2& operator=(const BinTree2&);
    bool operator==(const BinTree2&);
    bool operator!=(const BinTree2&);
    
private:
     struct Node{       //a node in a tree
         NodeData* data;//the data of a node (type string)
         Node* left = NULL;//a pointer to the left of the node
         Node* right = NULL;//a pointer to the right of the node
         
         Node(){}//constructor
        Node(const NodeData*newData) { data = new NodeData(*newData);}//constructor to copy data into node
     };
     Node* root;//a pointer to the root of a tree

    // function helpers
    bool insertHelper(Node*&, NodeData*);
    void outputHelper(Node* )const;
    void makeEmptyHelper(Node*& );
    int getHeightHelper(Node*,NodeData&);
    int calcHeight(Node*);
    void inOrderHelper(Node*)const;
    void sideways(Node*, int) const;
    bool equalHelper(Node*, Node*);
    bool retrieveHelper(Node*, const NodeData&, NodeData*&);
    Node* copy(const Node*);
    int height; // height of a tree
    
    //helper functions
    int bstreeToArray(NodeData *[], int index);
    int bstreeToArrayHelper(Node*,NodeData* [], int);
    void arrayToBSTree(Node* , NodeData* [], int, int);
};

#endif /* BinTree_h */
