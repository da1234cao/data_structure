struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    enum {NOT_COVERED,COVERED,MONITOR}; // 枚举三种类型：无覆盖，有覆盖，有摄像头
    int result;

public:
    int traverse(TreeNode* root){ 
        // 贪心思路：从下向上，不给叶子节点安装摄像头；向上过程中，给不在摄像头的覆盖范围内的节点安装摄像头。

        // 为了不使叶子节点安装摄像头，也不影响叶子是否覆盖情况。我们设所有叶子节点为“有覆盖情况”
        if(root == nullptr)
            return COVERED;
        

        int left_statue = traverse(root->left);
        int right_statue = traverse(root->right);

        // 如果左右孩子，都为“有覆盖”。由于下向上遍历，所以本节点必是“无覆盖”
        // 那这个节点是否需要安装摄像头呢？
        // 如果这个节点是叶子节点，不需要。
        // 唯二的另一种情况，该节点为根节点，则需要。
        // 所以，这里我们仅返回状态，不安装摄像头。当整个递归结束返回值，即为根节点的状态，如果此时它为“无覆盖”，我们再加一即可
        if(left_statue == COVERED && right_statue == COVERED)
            return NOT_COVERED;

        // 从下向上，如果左右孩子，存在一个都“无覆盖”，本节点需要安装一个摄像头
        if(left_statue == NOT_COVERED || right_statue == NOT_COVERED){
            result++;
            return MONITOR;
        }

        // 左右孩子，有一个安装了摄像头，本节点不用安装，状态返回为“有覆盖”
        if(left_statue == MONITOR || right_statue == MONITOR)
            return COVERED;

        // return -1; // 呆呆的letcode，这里没有return，不让提交。但代码不会走到这里
    }

    int minCameraCover(TreeNode* root) {
        if(traverse(root) == NOT_COVERED)
            result++;
        return result;
    }
};