#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right;
    return newNode;
}

Node* insertNode(Node* root, int data){
    if(root == nullptr){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }else{
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorder(Node* root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == nullptr){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool searchBST(Node* root, int key){
    if(root == nullptr){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return searchBST(root->left, key);
    }else{
        return searchBST(root->right, key);
    }
}

int main(){
    Node* root = nullptr;
    int choice, key;
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);

    do{
        cout << "\nBinary Search Tree Operations\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                for(int i = 0; i < n; i++){
                    root = insertNode(root, arr[i]);
                }
                cout << "Nodes inserted into BST." << endl;
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter key to search: ";
                cin >> key;
                if(searchBST(root, key)){
                    cout << "Key " << key << " found in BST." << endl;
                }else{
                    cout << "Key " << key << " not found in BST." << endl;
                }
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }while(choice!=6);


}