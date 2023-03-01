#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteRecursive(TreeNode* node, int value) {
        if (node == nullptr) return node;
        
        if (value < node->data) {
            node->left = deleteRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRecursive(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteRecursive(node->right, temp->data);
        }
        return node;
    }

    bool searchRecursive(TreeNode* node, int value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }

    void inorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            std::cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }

    void preorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }

    void postorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            std::cout << node->data << " ";
        }
    }

    void destroyTree(TreeNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}
    
    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    void inorder() {
        std::cout << "Inorder: ";
        inorderRecursive(root);
        std::cout << std::endl;
    }

    void preorder() {
        std::cout << "Preorder: ";
        preorderRecursive(root);
        std::cout << std::endl;
    }

    void postorder() {
        std::cout << "Postorder: ";
        postorderRecursive(root);
        std::cout << std::endl;
    }

    void levelOrder() {
        if (root == nullptr) return;
        std::queue<TreeNode*> q;
        q.push(root);
        std::cout << "Level Order: ";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            std::cout << node->data << " ";
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        std::cout << std::endl;
    }
};

#endif

