#include "treeNode.h"

TreeNode* TreeNode::getLeft() const
{
    return left;
}

TreeNode* TreeNode::getRight() const
{
    return right;
}

TreeNode* TreeNode::getTwin() const
{
    return twin;
}

const Item& TreeNode::getData() const
{
    return data;
}


void TreeNode::setLeft(TreeNode* const left)
{
    this->left = left;
}
void TreeNode::setRight(TreeNode* const right)
{
    this->right = right;
}
void TreeNode::setData(const Item& data)
{
    this->data = data;
}
void TreeNode::setTwin(TreeNode* const twin)
{
    this->twin = twin;
}

