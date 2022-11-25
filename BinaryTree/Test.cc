#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
using namespace std;

typedef struct BinaryTree
{
    int val;
    struct BinaryTree* left;
    struct BinaryTree* right;
}
BTNode;


void _PreOrder(BTNode* root)
{
    if (root == nullptr)
    {
        cout << "#" << " ";
        return;
    }

    cout << root->val << " ";
    _PreOrder(root->left);
    _PreOrder(root->right);
}
void PreOrder(BTNode* root)
{
    _PreOrder(root);
    cout << endl;
}

void _InOrder(BTNode* root)
{
    if (root == nullptr)
    {
        cout << "#" << " ";
        return;
    }

    _InOrder(root->left);
    cout << root->val << " ";
    _InOrder(root->right);
}
void InOrder(BTNode* root)
{
    _InOrder(root);
    cout << endl;
}

void _PostOrder(BTNode* root)
{
    if (root == nullptr)
    {
        cout << "#" << " ";
        return;
    }

    _PostOrder(root->left);
    _PostOrder(root->right);
    cout << root->val << " ";
}
void PostOrder(BTNode* root)
{
    _PostOrder(root);
    cout << endl;
}

BTNode* BuyBTNode(int val)
{
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    assert(root);

    root->val = val;
    root->left = root->right = nullptr;

    return root;
}

/*
void _TreeSize(BTNode* root, int* size)
{
    if (root == nullptr)
        return;

    (*size)++;

    _TreeSize(root->left, size);
    _TreeSize(root->right, size);
}
int TreeSize(BTNode* root)
{
    int size = 0;
    _TreeSize(root, &size);
    return size;
}*/

int TreeSize(BTNode* root)
{
    if (root == nullptr)
        return 0;

    return TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeHeight(BTNode* root)
{
    if (root == nullptr)
        return 0;

    return max(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}

int TreeKLevelSize(BTNode* root, int k)
{
    if (root == nullptr)
        return 0;
    if (k == 1)
        return 1;

    return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}


int main()
{
    BTNode* n1 = BuyBTNode(1);
    BTNode* n2 = BuyBTNode(2);
    BTNode* n3 = BuyBTNode(3);
    BTNode* n4 = BuyBTNode(4);
    BTNode* n5 = BuyBTNode(5);
    BTNode* n6 = BuyBTNode(6);
    n1->left = n2;
    n1->right = n4;
    n2->left = n3;
    n4->left = n5;
    n4->right = n6;

    PreOrder(n1);
    InOrder(n1);
    PostOrder(n1);

    // cout << TreeSize(n1) << endl;
    // cout << TreeLeafSize(n1) << endl;
    // cout << TreeHeight(n1) << endl;

    cout << TreeKLevelSize(n1, 1) << endl;
    cout << TreeKLevelSize(n1, 2) << endl;
    cout << TreeKLevelSize(n1, 3) << endl;
    cout << TreeKLevelSize(n1, 5) << endl;


    return 0;
}