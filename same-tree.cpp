/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return judgeSame(p, q);
    }
    
private:
    bool judgeSame(TreeNode *p, TreeNode *q) {
        if((NULL == p && NULL != q) || (NULL != p && NULL == q))
            return false;
        if(NULL == p && NULL == q)
            return true;
        if(!judgeSame(p->left, q->left))
            return false;
        if(!judgeSame(p->right, q->right))
            return false;
        return p->val == q->val;
    }
};


class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!isSameNode(p, q))
            return false;
        if(!p && !q)
            return true;

        queue<TreeNode*> lqueue;
        queue<TreeNode*> rqueue;
        lqueue.push(p);
        rqueue.push(q);
        while(!lqueue.empty() && !rqueue.empty())
        {
            TreeNode* lfront = lqueue.front();
            TreeNode* rfront = rqueue.front();

            lqueue.pop();
            rqueue.pop();

            if(!isSameNode(lfront->left, rfront->left))
                return false;
            if(lfront->left && rfront->left)
            {
                lqueue.push(lfront->left);
                rqueue.push(rfront->left);
            }

            if(!isSameNode(lfront->right, rfront->right))
                return false;
            if(lfront->right && rfront->right)
            {
                lqueue.push(lfront->right);
                rqueue.push(rfront->right);
            }
        }
        return true;
    }
    bool isSameNode(TreeNode* p, TreeNode *q)
    {
        if(!p && !q)
            return true;
        if((p && !q) || (!p && q) || (p->val != q->val))
            return false;
        return true;
    }
};