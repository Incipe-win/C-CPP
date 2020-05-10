---
title: Leetcode102. 二叉树的层次遍历题解(C++)
categories: 
- Algorithm
tags: 
- 博客
---
>世界以痛吻我，我却报之以歌
>
><p align="right">--泰戈尔</p>

[原题链接](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)
二叉树构造：
 ````cpp
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 ````

要求层次遍历二叉树，用一个二维数组存放每一层的数值！
层次遍历，一层一层的，所以很容易想到bfs，广度搜索遍历。
既然是bfs，肯定就想到递归。递归就是把复杂问题简单化！
我一直觉得打代码就是把自己想的换一种语言描述，可是做到这点很难！

话不多说，直接上代码，代码有注释，还有自己添加的辅助理解的语句。
````cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //我一直觉得代码就是做人之所想，可是要做到这一点很难！
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        bfs(root, res);
        return res;
    }
    void bfs(TreeNode* root, vector<vector<int>>& res) {
        //既然是层次遍历，就是一层一层的！
        queue<TreeNode*> que;
        que.push(root);//压入整个二叉树！
        while(!que.empty()) {
            vector<int> ans;
            int len = que.size();//根节点下有多少个子树
            //std::cout << "长度:" << len << std::endl;
            for(int i = 0; i < len; i++) {
                TreeNode* node = que.front();
                //std::cout << "树结构:";
                //Print(node);
                //std::cout << std::endl;
                que.pop();
                ans.push_back(node->val);
                if(node->left) {
                    //std::cout << "///////" << std::endl;
                    que.push(node->left);
                }
                if(node->right) {
                    //std::cout << "///////" << std::endl;
                    que.push(node->right);
                }
            }
            res.push_back(ans);
        }
    }
    // void Print(TreeNode* T) {
    //     if(T) {
    //         Print(T->left);
    //         std::cout << T->val <<" ";
    //         Print(T->right);
    //     }
    //     else {
    //         std::cout << "";
    //     }
    // }
};
````
代码本身没什么不好理解的，可是一到自己做就不会，还是缺乏练习导致！
[同类题](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)
**才疏学浅，望雅正***