#include <iostream>

using namespace std;

void printTree(TreeNode *tree) {
    if (tree != nullptr) {
        printTree(tree->left);
        cout << tree->value << endl;
        printTree(tree->right);
    }
}

int main() {
    std::cout << "Binary Trees!" << std::endl;
    TreeNode *root = makeStudentTree()
    return 0;
}
