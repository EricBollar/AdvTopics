#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode *right;
};

int getMaxValue(TreeNode* tree) {
    if (tree->right != nullptr) {
        return getMaxValue(tree->right);
    } else {
        return tree->value;
    }
}

int getMinValue(TreeNode* tree) {
    if (tree->left != nullptr) {
        return getMinValue(tree->left);
    } else {
        return tree->value;
    }
}

bool isBST(TreeNode* tree) {
    if (tree == nullptr) {
        return true;
    } else if (tree->left != nullptr && tree->right != nullptr) {
        // these two check the leftmost/rightmost value follows BST
        bool leftWorks = getMaxValue(tree->left) <= tree->value;
        bool rightWorks = getMinValue(tree->right) >= tree->value;
        return leftWorks && rightWorks && (tree->left->value <= tree->value) && (tree->right->value >= tree->value)
                && isBST(tree->left) && isBST(tree->right);
    } else if (tree->left != nullptr) {
        bool leftWorks = getMaxValue(tree->left) <= tree->value;
        return leftWorks && (tree->left->value <= tree->value) && isBST(tree->left);
    } else if (tree->right != nullptr) {
        bool rightWorks = getMinValue(tree->right) >= tree->value;
        return rightWorks && (tree->right->value >= tree->value) && isBST(tree->right);
    } else {
        return true;
    }
}

TreeNode* getDuplicateCopy(TreeNode* tree) {
    if (tree == nullptr) {
        return nullptr;
    }
    TreeNode* curr = new TreeNode();
    curr->value = tree->value;
    if (tree->left != nullptr) {
        curr->left = getDuplicateCopy(tree->left);
    } else if (tree->right != nullptr) {
        curr->right = getDuplicateCopy(tree->right);
    } else {
        return curr;
    }
}

int getShortestPathLength(TreeNode* tree) {
    if (tree == nullptr) {
        return 0;
    }
    if (tree->left == nullptr || tree->right == nullptr) {
        return 1;
    }
    int left = getShortestPathLength(tree->left);
    int right = getShortestPathLength(tree->right);
    if (left < right) {
        return 1 + left;
    } else {
        return 1 + right;
    }
}

int main() {
    TreeNode* root = new TreeNode();
    root->value = 8;
    TreeNode* b = new TreeNode();
    b->value = 2;
    root->left = b;
    TreeNode* c = new TreeNode();
    c->value = 9;
    root->right = c;
    TreeNode* d = new TreeNode();
    d->value = 1;
    b->left = d;
    TreeNode* e = new TreeNode();
    e->value = 6;
    b->right = e;
    TreeNode* f = new TreeNode();
    f->value = 4;
    e->left = f;
    TreeNode* g = new TreeNode();
    g->value = 7;
    e->right = g;
    std::cout << getShortestPathLength(root);
    return 0;
}