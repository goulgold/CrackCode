#include <ctime>
#include <cstdlib>

#define PROB 40

struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    int val;
    TreeNode(): val(1) {}
};

TreeNode* RandomBinaryTree (int n) {
    srand(time(NULL));
    if (n == 0) return NULL;
    TreeNode *root = new TreeNode();
    if (rand() % 100 < PROB) {
        root->left = RandomBinaryTree(n-1);
    }
    if (rand() % 100 < PROB) {
        root->left = RandomBinaryTree(n-1);
    }
    return root;
}
