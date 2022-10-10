#include "../include/AVL.h"
#include <iostream>

// Rotations from Stepik problems
// printInorder is based on lecture slides

int AVL::getHeight(TreeNode* helpRoot) {
    if (helpRoot == nullptr)
        return 0;
    return helpRoot->height;
}

int AVL::getBalance(TreeNode* helpRoot) {
    if (helpRoot == nullptr)
        return 0;
    return getHeight(helpRoot->left) - getHeight(helpRoot->right);
}

AVL::TreeNode* AVL::rotateLeft(TreeNode* helpRoot) {
    // Stepik
    TreeNode* rightChild = helpRoot->right;
    helpRoot->right = rightChild->left;
    rightChild->left = helpRoot;
    rightChild->left->height = 1 + std::max(getHeight(rightChild->left->left), getHeight(rightChild->left->right));
    return rightChild;
}

AVL::TreeNode* AVL::rotateRight(TreeNode* helpRoot) {
    // Stepik
    TreeNode* leftChild = helpRoot->left;
    helpRoot->left = leftChild->right;
    leftChild->right = helpRoot;
    leftChild->right->height = 1 + std::max(getHeight(leftChild->right->left), getHeight(leftChild->right->right));
    return leftChild;
}

AVL::TreeNode* AVL::rotateLeftRight(TreeNode* helpRoot) {
    // Stepik
    helpRoot->left = rotateLeft(helpRoot->left);
    return rotateRight(helpRoot);
}

AVL::TreeNode* AVL::rotateRightLeft(TreeNode* helpRoot) {
    // Stepik
    helpRoot->right = rotateRight(helpRoot->right);
    return rotateLeft(helpRoot);
}

AVL::TreeNode* AVL::getInorderSuccessor(TreeNode* helpRoot) {
    // loop through nodes to get leftmost leaf
    TreeNode* current = helpRoot;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

AVL::TreeNode* AVL::helperInsert(TreeNode* helpRoot, std::string name, std::string id) {
    if (helpRoot == nullptr) {
        std::cout << "successful" << std::endl;
        size++;
        return new TreeNode(name, id);
    } else if (id == helpRoot->id) {
        std::cout << "unsuccessful" << std::endl;
        return helpRoot;
    } else if (id < helpRoot->id) {
        helpRoot->left = helperInsert(helpRoot->left, name, id);
    } else {
        helpRoot->right = helperInsert(helpRoot->right, name, id);
    }
    // update height
    helpRoot->height = 1 + std::max(getHeight(helpRoot->left), getHeight(helpRoot->right));
    
    // check balance factor and rotate if needed
    int balance = getBalance(helpRoot);

    // left left case
    if (balance > 1 && getBalance(helpRoot->left) == 1) {
        helpRoot = rotateRight(helpRoot);
    // right right case
    } else if (balance < -1 && getBalance(helpRoot->right) == -1) {
        helpRoot = rotateLeft(helpRoot);
    // left right case
    } else if (balance > 1 && getBalance(helpRoot->left) == -1) {
        helpRoot = rotateLeftRight(helpRoot);
    // right left case
    } else if (balance < -1 && getBalance(helpRoot->right) == 1) {
        helpRoot = rotateRightLeft(helpRoot);
    }

    return helpRoot;
}

AVL::TreeNode* AVL::helperRemove(TreeNode* helpRoot, std::string id) {
    if (helpRoot == nullptr)
        return helpRoot;
    if (id < helpRoot->id)
        helpRoot->left = helperRemove(helpRoot->left, id);
    else if (id > helpRoot->id)
        helpRoot->right = helperRemove(helpRoot->right, id);
    else {
        // 0 children or 1 child
        if ((helpRoot->left == nullptr) || (helpRoot->right == nullptr)) {
            TreeNode* temp = helpRoot->left ? helpRoot->left : helpRoot->right;

            // 0 children
            if (temp == nullptr) {
                temp = helpRoot;
                helpRoot = nullptr;
            // 1 child
            } else {
                // copy child
                *helpRoot = *temp;
            }
            delete temp;
        // 2 children
        } else {
            // get inorder successor or smallest in right subtree
            TreeNode* temp = getInorderSuccessor(helpRoot->right);

            // copy data
            helpRoot->id = temp->id;
            helpRoot->name = temp->name;

            // delete successor
            helpRoot->right = helperRemove(helpRoot->right, temp->id);
        }
    }

    if (helpRoot == nullptr) return helpRoot;   // one node in tree

    // update height
    helpRoot->height = 1 + std::max(getHeight(helpRoot->left), getHeight(helpRoot->right));
    
    return helpRoot;
}

void AVL::helperSearchName(TreeNode* helpRoot, std::string name) {
    // check if name is in tree and print id
    if (helpRoot) {
        if (helpRoot->name == name) {
            std::cout << helpRoot->id << std::endl;
            flag = true;        // true if one name is in tree, could be multiple
        }
        if (helpRoot->left) {
            helperSearchName(helpRoot->left, name);
        }
        if (helpRoot->right) {
            helperSearchName(helpRoot->right, name);
        }
    }
}

bool AVL::helperSearchId(TreeNode* helpRoot, std::string id) {
    // check if id is in tree and print name
    if (helpRoot == nullptr)
        return false;
    else if (helpRoot->id == id) {
        std::cout << helpRoot->name << std::endl;
        return true;
    } else if (id < helpRoot->id) {
        bool result = helperSearchId(helpRoot->left, id);
        return result;
    } else {
        bool result = helperSearchId(helpRoot->right, id);
        return result;
    }
}

bool AVL::helperRemoveSearch(TreeNode* helpRoot, std::string id) {
    // check if id is in tree before removing
    if (helpRoot == nullptr)
        return false;
    else if (helpRoot->id == id) {
        return true;
    } else if (id < helpRoot->id) {
        bool result = helperRemoveSearch(helpRoot->left, id);
        return result;
    } else {
        bool result = helperRemoveSearch(helpRoot->right, id);
        return result;
    }
}

void AVL::helperInorder(TreeNode* helpRoot) {
    if (helpRoot) {
        if (helpRoot->left) {
            helperInorder(helpRoot->left);
            std::cout << ", ";
        }
        std::cout << helpRoot->name;
        if (helpRoot->right) {
            std::cout << ", ";
            helperInorder(helpRoot->right);
        }
    }
}

void AVL::helperPreorder(TreeNode* helpRoot) {
    if (helpRoot) {
        std::cout << helpRoot->name;
        if (helpRoot->left) {
            std::cout << ", ";
            helperPreorder(helpRoot->left);
        }
        if (helpRoot->right) {
            std::cout << ", ";
            helperPreorder(helpRoot->right);
        }
    }
}

void AVL::helperPostorder(TreeNode* helpRoot) {
    if (helpRoot) {
        if (helpRoot->left) {
            helperPostorder(helpRoot->left);
            std::cout << ", ";
        }
        if (helpRoot->right) {
            helperPostorder(helpRoot->right);
            std::cout << ", ";
        }
        std::cout << helpRoot->name;
    }
}

void AVL::getInorderList(TreeNode* helpRoot) {
    // populate inorder vector
    if (helpRoot) {
        if (helpRoot->left) {
            getInorderList(helpRoot->left);
        }
        inorder.push_back(helpRoot);
        if (helpRoot->right) {
            getInorderList(helpRoot->right);
        }
    }
}

AVL::TreeNode* AVL::helperRemoveInorder(TreeNode* helpRoot, int n) {
    // find Nth node and remove
    getInorderList(helpRoot);
    std::vector<TreeNode*>::iterator it;
    int i = 0;
    for (it = inorder.begin(); it != inorder.end(); it++) {
        if (n == i)
            helpRoot = helperRemove(helpRoot, (*it)->id);
        i++;
    }
    return helpRoot;
}

void AVL::destroyTree(TreeNode* helpRoot) {
    if (helpRoot) {
        destroyTree(helpRoot->left);
        destroyTree(helpRoot->right);
        delete helpRoot;
    }
}

AVL::~AVL() {
    destroyTree(this->root);
}

void AVL::insert(std::string name, std::string id) {
    this->root = helperInsert(this->root, name, id);
}

void AVL::remove(std::string id) {
    if (!helperRemoveSearch(this->root, id))
        std::cout << "unsuccessful" << std::endl;
    else {
        size--;
        this->root = helperRemove(this->root, id);
        std::cout << "successful" << std::endl;
    }
}

void AVL::searchName(std::string name) {
    helperSearchName(this->root, name);
    if (!flag)
        std::cout << "unsuccessful" << std::endl;
    flag = false;
}

void AVL::searchId(std::string id) {
    if (!helperSearchId(this->root, id))
        std::cout << "unsuccessful" << std::endl;
}

void AVL::printInorder() {
    helperInorder(this->root);
    std::cout << std::endl;
}

void AVL::printPreorder() {
    helperPreorder(this->root);
    std::cout << std::endl;
}

void AVL::printPostorder() {
    helperPostorder(this->root);
    std::cout << std::endl;
}

void AVL::printLevelCount() {
    std::cout << getHeight(this->root) << std::endl;
}

void AVL::removeInorder(int n) {
    if (n > -1 && n < size) {
        inorder = {};
        this->root = helperRemoveInorder(this->root, n);
        std::cout << "successful" << std::endl;
    } else {
        std::cout << "unsuccessful" << std::endl;
    }
}