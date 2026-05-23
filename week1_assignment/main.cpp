#include <iostream>

// Geeksforgeeks's implementation with some changes

struct Node
{
    int value{0};
    Node* left;
    Node* right;
};

enum Direction{
    LEFT,
    RIGHT
};

Node* create(int value){
    Node* new_node = new Node();
    new_node->value = value;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}


void insert(Node* &root, int value){
    if(root == nullptr){
        root = create(value);
    }else if (value < root->value){
        insert(root->left, value);
    }else{
        insert(root->right, value);
    }
}

void traverse(Node* root, Direction direction){
    if(root != nullptr){
        if(direction == LEFT){
            traverse(root->left, direction);
            std::cout << root->value << " ";
            traverse(root->right, direction);
        }else{
            traverse(root->right, direction);
            std::cout << root->value << " ";
            traverse(root->left, direction);
        }
    }
}

void delete_tree(Node* &root){
    if(root != nullptr){
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
        root = nullptr;
    }
}

void find_leafs(Node* root){
    if(root != nullptr){
        if(root->left == nullptr && root->right == nullptr){
            std::cout << root->value << " ";
        }

        find_leafs(root->left);
        find_leafs(root->right);
    }
}

void test_tree(int num_list[], int length){
    Node* root{nullptr};

    for(int i=0; i<length; i++){
        insert(root, num_list[i]);
    }

    traverse(root, Direction::LEFT);

    std::cout << '\n';

    find_leafs(root);

    std::cout << '\n';

    delete_tree(root);
}

int main(){
    int numbers_1[6]{20, 10, 30, 5, 15, 25};
    test_tree(numbers_1, 6);

    int numbers_2[7]{10, 5, 15, 2, 7, 12, 17};
    test_tree(numbers_2, 7);

    int numbers_3[8]{8, 3, 10, 1, 6, 14, 4, 13};
    test_tree(numbers_3, 8);
    return 0;
}