#include <iostream>

using std::ostream;
using std::cout;

template<typename T>
class TreeNode 
{
private:
    T* data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *parent;
    TreeNode<T> *twin;
public:
    TreeNode(): left(nullptr), right(nullptr), parent(nullptr), twin(nullptr) {}
    TreeNode(TreeNode<T> *twin): left(nullptr), right(nullptr), parent(nullptr), twin(twin) {}
    TreeNode(TreeNode<T> *left, TreeNode<T> *right): left(left), right(right), parent(nullptr), twin(nullptr) {}
    
    TreeNode<T>* getLeft() const;
    TreeNode<T>* getRight() const;
    TreeNode<T>* getParent();
    TreeNode<T>* getTwin();
    T* getData() const;


    void setLeft(TreeNode<T>* const left);
    void setRight(TreeNode<T>* const right);
    void setData(T* data);
    void setParent(TreeNode<T>* const parent);
    void setTwin(TreeNode<T>* const parent);
    void print() const;
    void printInOrder() const;
};