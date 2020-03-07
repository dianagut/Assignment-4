// ------------------------------------------------ BinTree.cpp -------------------------------------------------------
//
// Diana Gutierrez CSS 343
// Date Created: 1/20/2020
// Date last modified: 2/1/2020
//--------------------------------------------------------------------------------------------------------------------
// Purpose - Implementation of BinTree class
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "BinTree2.h"
using namespace std;

//-------------------------------------default constructor----------------------------
//default constructor:function to create an empty tree
//Postconditions: an empty tree will be created with a root = NULL
BinTree2:: BinTree2(){
    root = NULL;
}

//----------------------------------------copy constructor-------------------------------
//copy constructor: function to create a deep copy of an already existing bintree
//Preconditions: The bintree being copied is not equal to the existing bintree
//Postcondition: A deep copy of the given bintree will be created
BinTree2:: BinTree2(const BinTree2& other)
{
    if(root != other.root)
        root = copy(other.root); // calls helper function
    
}

//-----------------------------------------destructor------------------------------
//destructor: deletes all objects created in the program to free resourses that it may have aquired
//Precondition: There is an object created in the program
//Postcondition: When the program has ended all object will be deleted to free resources and avoid memory leaks
BinTree2:: ~BinTree2(){
    makeEmpty();
}

//-----------------------------------------makeEmpty---------------------------------------
//makeEmpty: calls private helper function
//Precondition: bintree should have at least one term
//Postcondition: the bintree will be emptied and deleted
void BinTree2::makeEmpty()
{
    makeEmptyHelper(root);
}

//-----------------------------------------makeEmptyHelper---------------------------------------
//makeEmptyHelper: helper function to empty out and delete a bintree
//Precondition: bintree should have at least one term
//Postcondition: bintree will be emptied
void BinTree2::makeEmptyHelper(Node*& current)
{
    if(current != NULL){
        makeEmptyHelper(current->left); //recursive call to delete data from left side of tree
        makeEmptyHelper(current->right); //recursive call to delete data from right side of tree
        if (current->data != NULL){
            delete current->data;   // deletes the data
            current->data = NULL;
        }
        delete current; // sets pointer to NULL
        current = NULL;
    }
}

//-----------------------------------------isEmpty---------------------------------------
//isEmpty: returns true if a bintree is empty
//Precondition: A bintree object must exist
//Postcondition: If a bintree is empty will return true, otherwise it will return false
bool BinTree2:: isEmpty()
{
    if(this -> root == NULL)
        return true;
    else
        return false;
}

//-----------------------------------------insert---------------------------------------
//insert: returns the degree of a polynomial
//Precondition: NodeData cannot be NULL
//Postcondition: will return true if insertHelper function returns true
bool BinTree2::insert(NodeData * data)
{
    if(root == NULL)//if the tree is empty
    {
        root = new Node(data);// make root a new node and give it the value of data
        return true;
    }
    if(*root -> data == *data) // if data at root is a duplicate, ignore
        return false;
    return insertHelper(root, data);//return helper function
}

//-----------------------------------------insertHelper---------------------------------------
//insertHelper: inserts a new node in a tree
//Precondition: bintree object must exist and data cannot be NULL
//Postcondition: will return true if the node was successfully inserted in the tree
bool BinTree2::insertHelper(Node*& current, NodeData* data)
{
    if(*current -> data == *data) // if data is a duplicate , ignore
        return false;
    
    if(*data < *current -> data) //if data is less than current node data
    {
        if(current -> left == NULL) // if there is no node to the left of current node
        {
            current -> left = new Node(data); // create a new node with value of data
            return true;
        }
        return insertHelper(current -> left, data); // if there is a node to the left of current and it is not NULL; keep traversing to the left
    }
    else // if data is greater than current node data
    {
        if(current -> right == NULL)// there is no node to the right of current node
        {
            current -> right = new Node(data); //create a new node with the value of data
            return true;
        }
        return insertHelper(current -> right, data); //if there is a node to the right keep traversing to the right
    }
    return false; // return false if data was not successfully inserted
}

//-----------------------------------------getHeight---------------------------------------
//getHeight: returns the height of a given value in the tree
//Precondition: A bintree object must exist
//Postcondition: If the object is not found or the tree is empty, will return 0
int BinTree2:: getHeight(NodeData& target)
{
    if(this -> isEmpty()) // if there is no root return height zero
        return 0;
    else
        return getHeightHelper(root, target); // use helper funtion to find height
}

//-----------------------------------------getHeightHelper---------------------------------------
//getHeightHelper: helper function used to find the object in the tree
//Precondition: bintree object must exist
//Postcondition: if the object is found will call calcHeight helper function, otherwise return 0
int BinTree2:: getHeightHelper(Node* current, NodeData& target)
{
    if(current != NULL)
    {
        if(*current -> data == target)// if the current node is equal to target
            return 1 + calcHeight(current); // add 1(root) and calculate how many leafs it has
    
        int lhs = 0, rhs = 0;
        //if target is not root
        if(current -> right)
        { // traverse through right side of tree
            rhs = getHeightHelper(current -> right, target);
            if(rhs > 0)
                return rhs;
        }
        if(current -> left)
        { //traverse through left side of tree
            lhs = getHeightHelper(current -> left, target);
            if(lhs > 0)
                return lhs;
        }
    }
    return 0; // if target does not exist in tree return 0
}

//-----------------------------------------calcHeight---------------------------------------
//calcHeight: calculates the depth / height at a given node
//Precondition: Node cannot be NULL
//Postcondition: will return the max depth of leafs
int BinTree2::calcHeight(Node * current)
{
    int lhs = 0, rhs = 0; //variables to keep track of height
    
    if(current -> right)//check if node has leafs to its right
       rhs = 1 + calcHeight(current -> right);//add one if it does and check again
    
    if(current -> left)//chech if the node has leafs to its left
        lhs = 1 + calcHeight(current -> left);//add one if it does and check again

    if(rhs > lhs)//return the max of the two to return the height at the given node
        return rhs;
    return lhs;
}

//-----------------------------------------retrieve---------------------------------------
//retrieve: gets the NodeData of a given object in the tree
//Precondition: bintree cannot be empty and NodeData cannot be NULL
//Postcondition: returns true if the NodeData object is found and asignes that value to another NodeData object
bool BinTree2::retrieve(const NodeData &target, NodeData* &answer)
{
    if(root) // if the tree is not empty
        return retrieveHelper(root, target, answer);//return helper function
    return false;
}

//-----------------------------------------retreiveHelper---------------------------------------
//retreiveHelper: searches for the NodeData object in the tree and assignes its value to another NodeData object
//Precondition: bintree cannot be empty
//Postcondition: will return true if the object was found and assigned successfully
bool BinTree2::retrieveHelper(Node *current, const NodeData &target, NodeData* &answer)
{
    if(*current -> data == target)//if target is found
    {
        answer = current -> data; // assign its value to another NodeData object
        return true;
    }
    if(target > *current -> data && current -> right)//if target is greater than current node data and current -> right is not NULL
        return retrieveHelper(current -> right, target , answer);//keep traversing through the right of the tree
    
    if(target < *current -> data && current -> left)//if target is less than current node data and current -> left is not NULL
        return retrieveHelper(current -> left, target , answer);//keep traversing through the left of the tree
    return false;//return false if object not found
}

//-----------------------------------------bstreeToArray---------------------------------------
//bstreeToArray: fills an array of NodeData objects using inorder traversal of the tree
//Precondition: tree cannot be empty
//Postcondition: will return true if successful
void BinTree2::bstreeToArray(NodeData* array[])
{
    bstreeToArray(array, 0);//calls helper function
}

//-----------------------------------------bstreeToArray---------------------------------------
//bstreeToArray: fills an array of NodeData objects using inorder traversal of the tree
//Precondition: tree cannot be empty
//Postcondition: returns the last index of the array
int BinTree2::bstreeToArray(NodeData* array[], int index)
{
    if(root)//if root is not equal to NULL / if tree is not empty
    {
        bstreeToArrayHelper(root, array, 0);//call helper function
        root = NULL;
    }
    return index;
}

//-----------------------------------------bstreeToArrayHelper---------------------------------------
//bstreeToArrayHelper: fills an array with objects from the bintree and leave the tree empty
//Precondition: tree cannont be empty
//Postcondition: returns the last index of the array
int BinTree2::bstreeToArrayHelper(Node *current, NodeData* array[], int index)
{
    if(current)//if current node is not NULL
    {
        if(current -> left)//if current has a left that is not NULL
            index = bstreeToArrayHelper(current -> left, array, index);//traverse through the left of the tree
        array[index] = current -> data;//assign that value to array
        index++;// move to next index
        if(current -> right)// if current has a right that is not NULL
            index = bstreeToArrayHelper(current -> right, array, index);//traverse through the right of the tree
      delete current;//delete the current node in tree
    }
    return index;
}

//-----------------------------------------arrayToBSTree---------------------------------------
//arrayToBSTree: builds a ballance bintree from a sorted array of NodeData objects
//Precondition: array cannot be empty
void BinTree2::arrayToBSTree(NodeData * array[])
{
    makeEmpty(); //empty out current tree
    int size = 0;
    while(array[size])//while there is an object in the array
        size ++;//increment size by 1
    root = new Node(); // make root a new node
    arrayToBSTree(root, array, 0, size - 1); // call helper function
}

//-----------------------------------------arrayToBSTree---------------------------------------
//arrayToBSTree: helper function to buil a tree from the array and leave the array full of NULLs
//Precondition: tree must be empty and array cannot be empty
//Postcondition: creates a balanced bintree
void BinTree2::arrayToBSTree(Node *current, NodeData* array[], int low, int high)
{
    int middle = (low + high) / 2;// find the middle of the array
    current -> data = array[middle];//make that the root of the tree
    array[middle] = NULL;//fill that array index with NULL
    if(low < middle)//if low is less than middle
    {
        current -> left = new Node();//create a new node to the left of current node
        arrayToBSTree(current -> left, array, low, middle - 1);//traverse through the first half of the array
    }
    if((high) > middle)//if high is greater than middle to the right of the current node
    {
        current -> right = new Node();//create a new node
        arrayToBSTree(current -> right, array, middle + 1, high);//traverse through the last half of the array
    }
}

//-----------------------------------------displaySideways---------------------------------------
//displaySideways: displays a bintree as though you are viewing it from the side
//Precondition: NONE
//Postcondition: BinTree remains unchanged
void BinTree2::displaySideways()
{
    sideways(root, 0);//calls helper function
}

//-----------------------------------------sideways---------------------------------------
//sideways: helper function for displaySideways
//Precondition: NONE
//Postcondition: BinTree remains unchanged
void BinTree2::sideways(Node *current, int level)const
{
    if(current != NULL)
    {
        level++;
        sideways(current->right, level); // traverse through the right of tree
        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }
        cout << *current->data << endl;
        sideways(current->left, level);//traverse through the left of tree
        }
}

//-----------------------------------------operator = ---------------------------------------
//operator =: operator overload to assign the values of one BinTree to another
//Precondition: must be 2 existing bintrees
//Postcondition: will return the changed bintree
BinTree2& BinTree2::operator=(const BinTree2& other)
{
    if(*this != other)
    {
        if(other.root != NULL)
        {
            if(root != NULL)
                makeEmpty();//empty lhs bintree
            root = copy(other.root);//use helper function to copy data starting from root
        }
    }
    return *this;
}

//-----------------------------------------copy---------------------------------------
//copy: copys data from one node to another
//Precondition: must be an existing node
//Postcondition: will return new node
BinTree2::Node* BinTree2::copy(const Node* current)
{
    if(current == NULL)
        return NULL;
    Node* newNode = new Node();//create a new node
    newNode -> data = new NodeData(*current -> data);//create a new NodeData and give if value of current node data
    newNode -> left = newNode -> right = NULL; // make left and right NULL
    if(current -> left)//if the current node has a left
        newNode -> left = copy(current -> left);//traverse through left and copy
    if(current -> right)//if the current node has a right
        newNode -> right = copy(current -> right);//traverse through right and copy
    return newNode;
}

//-----------------------------------------operator == ---------------------------------------
//operator ==: compares to bintrees
//Precondition: must be comparing 2 bintrees
//Postcondition: will return true if bintrees are equal to each other
bool BinTree2:: operator==(const BinTree2& other)
{
    if(this -> root == NULL && other.root == NULL)
        return true; // return true if they are both empty
    return equalHelper(root, other.root);//call helper function
}

//-----------------------------------------equalHelper---------------------------------------
//equalHelper: helper function for operator ==
//Precondition: NONE
//Postcondition: will return true if both trees are equal to each other
bool BinTree2::equalHelper(Node* current, Node* otherCurrent)
{
    if(current == NULL && otherCurrent == NULL)
        return true; // considered true if both lists are empty
    
    if(current == NULL || otherCurrent == NULL)
        return false; //false if only one tree is empty
    
    if(*current -> data == *otherCurrent -> data)//if current data and other current data are equal
    {
        bool answer = true;
        if(current -> right && otherCurrent -> right)//if both trees have a right
            answer &= equalHelper(current -> right, otherCurrent -> right);//traverse through right and compare
        if(!answer)
            return false;
        if(current -> left && otherCurrent -> left)//if both trees have a left
            answer &= equalHelper(current -> left, otherCurrent -> left);//traverse through left and compare
        return answer;
    }
    return false;
}

//-----------------------------------------operator != ---------------------------------------
//operator != : compares 2 bintrees
//Precondition: must be comparing 2 existing bintrees
//Postcondition: will return true if the trees are NOT equal
bool BinTree2::operator!=(const BinTree2 &other)
{
    return !equalHelper(root, other.root);//return the negation of equalHelper function
}

//-----------------------------------------operator << ---------------------------------------
//operator << : output operator overload
//Precondition: NONE
//Postcondition: outputs a tree in inorder traversal
ostream& operator<< (ostream &out, const BinTree2& tree)
{
    tree.inOrderHelper(tree.root);//call helper function
    out << endl;
    return out;
}

//-----------------------------------------inOrderHelper---------------------------------------
//inOrderHelper: output operator overload helper function
//Precondition: NONE
//Postcondition: output a tree in inorder traversal
void BinTree2::inOrderHelper(Node* curr) const
{
    if (curr == NULL)// cannot be NULL
    {
        return;//doesn't return anything
    }
    if (curr != NULL)
    {
        inOrderHelper(curr->left);// recursive call to traverse through left of tree
        cout << *curr->data << " "; // print out data
        inOrderHelper(curr->right); // recursive call to traverse through right of tree
    }
}

