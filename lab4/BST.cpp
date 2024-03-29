// Lab 04
// Bryan Chan and Ali Halmamat  
// The purpose of this assignment is to implement a binary tree ADT which will take in Krone objects.

#ifndef BST_H
#define BST_H

#include <iostream>
#include "krone.cpp"
using namespace std;


class BST
{
public:
    void find(double, node **, node **);
    void search(node *, double);
    void insert(node *, node *);
    void del(double);
    void case_a(node *, node *);
    void case_b(node *, node *);
    void case_c(node *, node *);
    void preorder(node *);
    void inorder(node *);
    void postorder(node *);
    void display(node *, int);
    BST()
    {
        root = NULL;
    }
};

/*
 * Find Element in the Tree
 */

// for find()
    // Pre:      item - the given user input which is used to compare to the
    //                  contents of the binary search tree.
    //           par - a double pointer from the node class (parent node)
    //           loc - a double pointer from the node class (location of the node)
    // Post:     Used as a helper function for the delete method, but does not affect 
    //           the content of the tree.
    // Return:   void (returns nothing, searches through the entire binary tree)
void BST::find(double item, node **par, node **loc)
{
    node *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->info)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    *loc = NULL;
    *par = ptrsave;
}

/*
 * Inserting Element into the Tree
 */
// for insert()
    // Pre:      tree - a pointer to the binary tree
    //           newnode - a pointer to the new node
    // Post:     Affects the contents of the BST by adding a new node
    // Return:   void (returns nothing, just adds a new node to the binary tree)
void BST::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout << "Root Node is Added" << endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout << "Element already in the tree" << endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);
        }
        else
        {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout << "Node Added To Left" << endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout << "Node Added To Right" << endl;
            return;
        }
    }
}
/*
search method

*/

// for search()
    // Pre:      tree - a pointer to the binary tree
    //           item - the given user input which is used for comparison
    // Post:     Does not affect the contents of the BST. It just searches
    //           through the entire BST to check and see if the input is found.
    // Return:   void (displays a message on whether or not the input was found
    //                 in the BST)
void BST::search(node* tree, double item)
{
    if (tree == NULL)
    {
        cout << "Element not found in tree." << endl;
        return;
    }
    if (tree->info == item)
    {
        cout << "Element found in tree." << endl;
        return;
    }
    if (tree->info > item)
        search(tree->left, item);
    else
        search(tree->right, item);
}


// for del()
    // Pre:      item - the given user input
    // Post:     Affects the contents of the BST by removing the input from the BST if present
    // Return:   void (returns nothing, but if node is empty or if the item is not found in the BST, a message is displayed)
void BST::del(double item)
{
    node *parent, *location;
    if (root == NULL)
    {
        cout << "Tree empty" << endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout << "Item not present in tree" << endl;
        return;
    }
    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);
    free(location);
}

/*
 * Case A
 */
 // for case_a()
    // Pre:      par - a pointer from the node class
    //           loc - a pointer from the node class
    // Post:     Affects the contents of the BST by checking if parent node is NULL. 
    // Return:   void (returns nothing, checks if parent node is empty, which sets root to NULL.)
void BST::case_a(node *par, node *loc)
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}

/*
 * Case B
 */
 // for case_b()
    // Pre:      par - a pointer from the node class
    //           loc - a pointer from the node class
    // Post:     Affects the contents of the BST by checking if parent node is NULL. 
    // Return:   void (returns nothing, checks if parent node is empty, which sets root to NULL.)
void BST::case_b(node *par, node *loc)
{
    node *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}

/*
 * Case C
 */
  // for case_c()
    // Pre:      par - a pointer from the node class
    //           loc - a pointer from the node class
    // Post:     Affects the contents of the BST by checking if parent node is NULL. 
    // Return:   void (returns nothing, checks if parent node is empty, which sets root to NULL.)
void BST::case_c(node *par, node *loc)
{
    node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}

/*
 * Pre Order Traversal
 */
 // for preorder()
    // Pre:      ptr - a pointer from the node class
    // Post:     Doesn't affect the content of the BST. It only outputs the nodes from least to greatest.
    // Return:   void (returns nothing, but outputs the nodes from least to greatest.)
void BST::preorder(node *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        cout << ptr->info << "  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
/*
 * In Order Traversal
 */
 // for inorder()
    // Pre:      ptr - a pointer from the node class
    // Post:     Doesn't affect the content of the BST.
    // Return:   void (returns nothing)
void BST::inorder(node *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout << ptr->info << "  ";
        inorder(ptr->right);
    }
}

/*
 * Postorder Traversal
 */
 // for inorder()
    // Pre:      ptr - a pointer from the node class
    // Post:     Doesn't affect the content of the BST. It only outputs the nodes from greatest to least.
    // Return:   void (returns nothing, but outputs the nodes from greatest to least.)
void BST::postorder(node *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->info << "  ";
    }
}

 // for display()
    // Pre:      ptr - a pointer from the node class
    //           level - a int var representing the level of the node
    // Post:     Doesn't affect the content of the BST. It only outputs all of the nodes from the BST.
    // Return:   void (returns nothing, but outputs all of the nodes from the BST)
void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        cout << endl;
        if (ptr == root)
            cout << "Root->:  ";
        else
        {
            for (i = 0; i < level; i++)
                cout << "        ";
        }
        cout << "Kr " << ptr->info;
        display(ptr->left, level + 1);
    }
}

#endif