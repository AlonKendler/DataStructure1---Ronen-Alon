#include <iostream>

using std::ostream;

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
    TreeNode<T>* getParent() const;
    T& getData();


    void setLeft(TreeNode<T>* const left);
    void setRight(TreeNode<T>* const right);
    void setData(const T& data);
    void setParent(TreeNode<T>* const parent);

    template<typename U>
    friend ostream& operator<<(ostream& cout, const TreeNode<U>* h);
    
    bool operator<(TreeNode<T>* t1);
};