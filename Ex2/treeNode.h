#include <iostream>

using std::ostream;
using std::cout;

/* template<class T> class TreeNode;
template<class T> ostream& operator<<(ostream& cout, TreeNode<T>* h);
 */
template<typename T>
class TreeNode 
{
private:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *parent;
public:
    TreeNode(): left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(TreeNode<T> *left, TreeNode<T> *right): left(left), right(right), parent(nullptr) {}
    
    TreeNode<T>* getLeft() const;
    TreeNode<T>* getRight() const;
    const TreeNode<T>* getParent() const;
    const T& getData() const;


    void setLeft(TreeNode<T>* const left);
    void setRight(TreeNode<T>* const right);
    void setData(const T& data);
    void setParent(TreeNode<T>* const parent);
    void print() const;
    
    bool operator<(TreeNode<T>* t1) const;
};