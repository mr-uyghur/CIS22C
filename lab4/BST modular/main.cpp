#include <iostream>
#include "bst.cpp"
#include "krone.cpp"
using namespace std;

int main()
{
    int choice;
    double  num;
    BST bst;
    node *temp;
    while (1)
    {
        cout << "-----------------" << endl;
        cout << "Operations on BST" << endl;
        cout << "-----------------" << endl;
        cout << "1.Insert Element " << endl;
        cout << "2.Delete Element " << endl;
        cout << "3.Inorder Traversal" << endl;
        cout << "4.Preorder Traversal" << endl;
        cout << "5.Postorder Traversal" << endl;
        cout << "6.Display" << endl;
        cout << "7.Search" << endl;
        cout << "8.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            temp = new node;
            cout << "Enter the number to be inserted : Kr  ";
            cin >> temp->info;
            bst.insert(root, temp);
            break;
        case 2:
            if (root == NULL)
            {
                cout << "Tree is empty, nothing to delete" << endl;
                continue;
            }
            cout << "Enter the number to be deleted : ";
            cin >> num;
            bst.del(num);
            break;
        case 3:
            cout << "Inorder Traversal of BST:" << endl;
            bst.inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal of BST:" << endl;
            bst.preorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal of BST:" << endl;
            bst.postorder(root);
            cout << endl;
            break;
        case 6:
            cout << "Display BST:" << endl;
            bst.display(root, 1);
            cout << endl;
            break;
        case 7:
            cout << "Search BST:" << endl;
            cin >> num;
            bst.search(root, num);
            break;
        case 8:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}