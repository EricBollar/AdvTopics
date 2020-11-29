#include <iostream>
using namespace std;

struct TreeNode {
    string value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        left = nullptr;
        right = nullptr;
    }
};

TreeNode * makeStudentTree() {
    TreeNode *temp = new TreeNode;
    temp->value = "Gus";
    temp->left = new TreeNode;
    temp->left->value = "Eliot";
    temp->left->right = new TreeNode;
    temp->left->right->value = "Eric";
    temp->left->right->left = new TreeNode;
    temp->left->right->left->value = "Elsie";
    temp->left->left = new TreeNode;
    temp->left->left->value = "Carter";
    temp->left->left->left = new TreeNode;
    temp->left->left->left->value = "Aidan";
    temp->right = new TreeNode;
    temp->right->value = "Michael";
    temp->right->left = new TreeNode;
    temp->right->left->value = "Jacqueline";
    temp->right->left->left = new TreeNode;
    temp->right->left->left->value = "Heather";
    temp->right->left->right = new TreeNode;
    temp->right->left->right->value = "Jane";
    temp->right->right = new TreeNode;
    temp->right->right->value = "Nikash";

    return temp;
}

void insert(TreeNode *& tree, string val) {
    if (tree == nullptr) {
        tree = new TreeNode;
        tree->value = val;
    } else if (val < tree->value) {
        insert(tree->left, val);
    } else {
        insert(tree->right, val);
    }
}

bool contains(TreeNode *tree, string val) {
    if (tree == nullptr) {
        return false;
    }
}

bool allEvenLength(TreeNode *tree) {
    if (tree == nullptr) {
        return true;
    } else {
        return tree->value.length() % 2 == 0 && allEvenLength(tree->left) && allEvenLength(tree->right);
    }
}

void printTree(TreeNode *tree) {
    if (tree != nullptr) {
        printTree(tree->left);
        cout << tree->value << endl;
        printTree(tree->right);
    }
}

int height(TreeNode *tree) {
    if (tree == nullptr) {
        return 0;
    }
    return 1 + max(height(tree->left), height(tree->right));
}

string getFirst(TreeNode *tree) {
    if (tree == nullptr) {
        return "";
    }
    TreeNode *temp = tree;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp->value;
}

bool isEqual(TreeNode *one, TreeNode *two) {
    if (one == nullptr && two == nullptr) {
        return true;
    } else if (one == nullptr || two == nullptr) {
        return false;
    }
    return one->value == two->value && isEqual(one->left, two->left) && isEqual(one->right, two-right);
}

void freeTree(TreeNode *tree) {
    if (tree != nullptr) {
        freeTree(tree->left);
        freeTree(tree->right);
        delete tree;
    }
}

int main() {
    cout << "Hello, Binary Trees!" << endl;
    TreeNode *root = makeStudentTree();

    cout << size(root) << endl;
    cout << countLetters(root) << endl;
    printTree(root);
    if (allEvenLength(root)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    if (contains(root, "Jane")) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    insert(root, "Kevin");
    printTree(root);
    cout << getFirst(root) << endl;
    if (isEqual(root, nullptr)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    freeTree(root);

    return 0;
}
