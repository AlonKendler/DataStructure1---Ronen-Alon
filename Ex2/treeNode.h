#include "item.h"

class TreeNode 
{
private:
    Item data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *twin;
public:
    TreeNode(): left(nullptr), right(nullptr), twin(nullptr){}
    TreeNode(TreeNode *left, TreeNode *right,TreeNode *twin): left(left), right(right), twin(twin){}
    TreeNode(TreeNode *twin): left(nullptr), right(nullptr), twin(twin){}

    TreeNode* getLeft() const;
    TreeNode* getRight() const;
    TreeNode* getTwin() const;
    const Item& getData() const;


    void setLeft(TreeNode* const left);
    void setRight(TreeNode* const right);
    void setData(const Item& data);
    void setTwin(TreeNode* const twin);
};