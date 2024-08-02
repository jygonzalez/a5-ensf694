/**
 *  File Name: AVL_tree.cpp
 *  Assignment: ENSF 694 Summer 2024 - Lab 5 Exercise B
 *  Created by: Mahmood Moussavi on 2024-05-22
 *  Completed by: Yael Gonzalez
 *  Submission Date: August 2, 2024
 */

#include "AVL_tree.h"

AVLTree::AVLTree() : root(nullptr), cursor(nullptr) {}

int AVLTree::height(const Node *N)
{
    return (N == nullptr) ? 0 : N->height;
}

int AVLTree::getBalance(Node *N)
{
    return (N == nullptr) ? 0 : height(N->right) - height(N->left);
}

// Implemented based on: https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
Node *AVLTree::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update parent pointers
    if (T2 != nullptr)
    {
        T2->parent = y;
    }
    x->parent = y->parent;
    y->parent = x;

    // Update parent link to this node
    if (x->parent != nullptr)
    {
        if (x->parent->left == y)
        {
            x->parent->left = x;
        }
        else
        {
            x->parent->right = x;
        }
    }
    else
    {
        root = x;
    }

    // Update heights
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Implemented based on: https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
Node *AVLTree::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update parent pointers
    if (T2 != nullptr)
    {
        T2->parent = x;
    }
    y->parent = x->parent;
    x->parent = y;

    // Update parent link to this node
    if (y->parent != nullptr)
    {
        if (y->parent->left == x)
        {
            y->parent->left = y;
        }
        else
        {
            y->parent->right = y;
        }
    }
    else
    {
        root = y;
    }

    // Update heights
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

void AVLTree::insert(int key, Type value)
{
    root = insert(root, key, value, nullptr);
}

// Recursive function
// Implemented based on: https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
Node *AVLTree::insert(Node *node, int key, Type value, Node *parent)
{
    // 1. Do ordinary Binary Search Tree insertion
    if (node == nullptr)
    {
        return new Node(key, value, parent);
    }

    if (key < node->data.key)
    {
        node->left = insert(node->left, key, value, node);
    }
    else if (key > node->data.key)
    {
        node->right = insert(node->right, key, value, node);
    }
    else
    {
        return node;
    }

    // 2. Update height of this ancestor node
    node->height = 1 + std::max(height(node->left), height(node->right));

    // 3. Get balance factor of this ancestor node
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases
    // Case 1: Left-Left
    if (balance < -1 && key < node->left->data.key)
    {
        return rightRotate(node);
    }

    // Case 2: Right-Right
    if (balance > 1 && key > node->right->data.key)
    {
        return leftRotate(node);
    }

    // Case 3: Left-Right
    if (balance < -1 && key > node->left->data.key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right-Left
    if (balance > 1 && key < node->right->data.key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Otherwise, return (unchanged) node pointer
    return node;
}

// Recursive function
void AVLTree::inorder(const Node *root)
{
    if (root == nullptr)
        return;

    // LVR
    inorder(root->left);
    std::cout << "(" << root->data.key << ", " << root->data.value << ")" << " ";
    inorder(root->right);
}

// Recursive function
void AVLTree::preorder(const Node *root)
{
    if (root == nullptr)
        return;

    // VLR
    std::cout << "(" << root->data.key << ", " << root->data.value << ")" << " ";
    preorder(root->left);
    preorder(root->right);
}

// Recursive function
void AVLTree::postorder(const Node *root)
{
    if (root == nullptr)
        return;

    // LRV
    postorder(root->left);
    postorder(root->right);
    std::cout << "(" << root->data.key << ", " << root->data.value << ")" << " ";
}

const Node *AVLTree::getRoot()
{
    return root;
}

void AVLTree::find(int key)
{
    go_to_root();
    if (root != nullptr)
        find(root, key);
    else
        std::cout << "It seems that tree is empty, and key not found." << std::endl;
}

// Recursive funtion
void AVLTree::find(Node *root, int key)
{
    if (root == nullptr)
    {
        cursor = nullptr;
        return;
    }

    if (root->data.key == key)
    {
        cursor = root;
        return;
    }

    if (root->data.key > key)
    {
        find(root->left, key);
    }
    else
    {
        find(root->right, key);
    }
}

AVLTree::AVLTree(const AVLTree &other) : root(nullptr), cursor(nullptr)
{
    root = copy(other.root, nullptr);
    cursor = root;
}

AVLTree::~AVLTree()
{
    destroy(root);
}

AVLTree &AVLTree::operator=(const AVLTree &other)
{
    if (this == &other)
        return *this;
    destroy(root);
    root = copy(other.root, nullptr);
    cursor = root;
    return *this;
}

// Recursive funtion
Node *AVLTree::copy(Node *node, Node *parent)
{
    if (node)
    {
        Node *new_node = new Node(node->data.key, node->data.value, parent);
        new_node->left = copy(node->left, new_node);
        new_node->right = copy(node->right, new_node);
        new_node->height = node->height;
        return new_node;
    }

    return nullptr;
}

// Recusive function
void AVLTree::destroy(Node *node)
{
    if (node)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

const int &AVLTree::cursor_key() const
{
    if (cursor != nullptr)
        return cursor->data.key;
    else
    {
        std::cout << "looks like tree is empty, as cursor == Zero.\n";
        exit(1);
    }
}

const Type &AVLTree::cursor_datum() const
{
    if (cursor != nullptr)
        return cursor->data.value;
    else
    {
        std::cout << "looks like tree is empty, as cursor == Zero.\n";
        exit(1);
    }
}

int AVLTree::cursor_ok() const
{
    if (cursor == nullptr)
        return 0;
    return 1;
}

void AVLTree::go_to_root()
{
    if (!root)
        cursor = root;
    cursor = nullptr;
}
