#pragma once
#include <string>
#include <vector>

class AVL {
    private:
        struct TreeNode {
            std::string name;
            std::string id;
            int height;
            TreeNode *left;
            TreeNode *right;
            TreeNode(std::string name, std::string id) : name(name), id(id), height(1), left(nullptr), right(nullptr) {}
        };

        TreeNode* root = nullptr;
        bool flag = false;                  // searchName if name exists
        int size = 0;                       // total nodes
        std::vector<TreeNode*> inorder;     // list of inorder nodes
        // helper functions
        int getHeight(TreeNode* helpRoot);
        int getBalance(TreeNode* helpRoot);
        AVL::TreeNode* rotateLeft(TreeNode* helpRoot);
        AVL::TreeNode* rotateRight(TreeNode* helpRoot);
        AVL::TreeNode* rotateLeftRight(TreeNode* helpRoot);
        AVL::TreeNode* rotateRightLeft(TreeNode* helpRoot);
        AVL::TreeNode* getInorderSuccessor(TreeNode* helpRoot);
        AVL::TreeNode* helperInsert(TreeNode* helpRoot, std::string name, std::string id);
        AVL::TreeNode* helperRemove(TreeNode* helpRoot, std::string id);
        void helperSearchName(TreeNode* helpRoot, std::string name);
        bool helperSearchId(TreeNode* helpRoot, std::string id);
        bool helperRemoveSearch(TreeNode* helpRoot, std::string id);
        void helperInorder(TreeNode* helpRoot);
        void helperPreorder(TreeNode* helpRoot);
        void helperPostorder(TreeNode* helpRoot);
        void getInorderList(TreeNode* helpRoot);
        AVL::TreeNode* helperRemoveInorder(TreeNode* helpRoot, int n);

        // Destroy tree
        void destroyTree(TreeNode* helpRoot);

    public:
        AVL() {};
        ~AVL();
        void insert(std::string name, std::string id);
        void remove(std::string id);
        void searchName(std::string name);
        void searchId(std::string id);
        void printInorder();
        void printPreorder();
        void printPostorder();
        void printLevelCount();
        void removeInorder(int n);
};