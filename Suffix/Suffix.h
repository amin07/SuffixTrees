#include<string>
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
    vector <TreeNode* > childs;
    int nodeMark;
    string edge_label;
    TreeNode(){nodeMark=-1;edge_label="";}
    TreeNode(int n, string label):nodeMark(n),edge_label(label){}
    void addChild(TN *node){this->childs.push_back(node);}
};
typedef TreeNode TN;
