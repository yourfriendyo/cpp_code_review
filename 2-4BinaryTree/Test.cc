#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}
TreeNode;


void _PreOrder(TreeNode* root)
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
void PreOrder(TreeNode* root)
{
    _PreOrder(root);
    cout << endl;
}

void _InOrder(TreeNode* root)
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
void InOrder(TreeNode* root)
{
    _InOrder(root);
    cout << endl;
}

void _PostOrder(TreeNode* root)
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
void PostOrder(TreeNode* root)
{
    _PostOrder(root);
    cout << endl;
}

void _LevelOrder(TreeNode* root)
{
    if (root == nullptr)
        return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* front = q.front();
        cout << front->val << " ";
        q.pop();
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
}
void LevelOrder(TreeNode* root)
{
    _LevelOrder(root);
    cout << endl;
}

TreeNode* BuyTreeNode(int val)
{
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    assert(root);

    root->val = val;
    root->left = root->right = nullptr;

    return root;
}

/*
void _TreeSize(TreeNode* root, int* size)
{
    if (root == nullptr)
        return;

    (*size)++;

    _TreeSize(root->left, size);
    _TreeSize(root->right, size);
}
int TreeSize(TreeNode* root)
{
    int size = 0;
    _TreeSize(root, &size);
    return size;
}*/

int TreeSize(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    return TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeHeight(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    return max(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}

int TreeKLevelSize(TreeNode* root, int k)
{
    if (root == nullptr)
        return 0;
    if (k == 1)
        return 1;

    return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}

bool TreeFind(TreeNode* root, int x)
{
    if (root == nullptr)
        return false;

    return root->val == x || TreeFind(root->left, x) || TreeFind(root->right, x);
}


int main()
{
    TreeNode* n1 = BuyTreeNode(1);
    TreeNode* n2 = BuyTreeNode(2);
    TreeNode* n3 = BuyTreeNode(3);
    TreeNode* n4 = BuyTreeNode(4);
    TreeNode* n5 = BuyTreeNode(5);
    TreeNode* n6 = BuyTreeNode(6);
    n1->left = n2;
    n1->right = n4;
    n2->left = n3;
    n4->left = n5;
    n4->right = n6;

    PreOrder(n1);
    InOrder(n1);
    PostOrder(n1);
    LevelOrder(n1);

    // cout << TreeSize(n1) << endl;
    // cout << TreeLeafSize(n1) << endl;
    // cout << TreeHeight(n1) << endl;

    // cout << TreeKLevelSize(n1, 1) << endl;
    // cout << TreeKLevelSize(n1, 2) << endl;
    // cout << TreeKLevelSize(n1, 3) << endl;
    // cout << TreeKLevelSize(n1, 5) << endl;

    // cout << TreeFind(n1, 1) << endl;
    // cout << TreeFind(n1, 3) << endl;
    // cout << TreeFind(n1, 7) << endl;

    return 0;
}