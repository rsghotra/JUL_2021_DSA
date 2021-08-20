#include "bt.h"
#define COUNT 10
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

BinaryTree::BinaryTree() {
    this->root = 0;
}

void BinaryTree::CreateTree() {
    queue<TreeNode*> queue;
    int x;
    TreeNode* ptr = 0;
    cout << "==>Enter root value: " << endl;
    cin >> x;
    this->root = new TreeNode(x);
    //see queue with root;
    queue.emplace(this->root);
    while(!queue.empty()) {
        ptr = queue.front();
        queue.pop();
        cout << "Enter left child of " << ptr->data << " node: ";
        cin >> x;
        if(x != -1) {
            ptr->left = new TreeNode(x);
            queue.push(ptr->left);
        }
        cout << "Enter right child of " << ptr->data << " node: ";
        cin >> x;
        if(x != -1) {
            ptr->right = new TreeNode(x);
            queue.push(ptr->right);
        }
    }
}

void BinaryTree::LevelOrder() {
    cout << "==>Printing Level Order traversal." << endl;
    if(this->root != 0) {
        queue<TreeNode*> queue;
        TreeNode* ptr = 0;
        queue.push(this->root);

        while(!queue.empty()) {
            ptr = queue.front();
            queue.pop();
            cout << ptr->data << " ";
            if(ptr->left) queue.push(ptr->left);
            if(ptr->right) queue.push(ptr->right);
        }
    }
}

void BinaryTree::PreOrder() {
    cout << "\n==>Preorder sequence:" << endl;
    PreOrder(this->root);
}

void BinaryTree::PreOrder(TreeNode* t) {
    stack<TreeNode*> stk;
    while(t != 0 || stk.empty() == false) {
        if(t!=0) {
            cout << t->data << " ";
            stk.push(t);
            t = t->left;
        } else {
            t = stk.top();
            stk.pop();
            t = t->right;
        }
    }
}

void BinaryTree::InOrder() {
    cout << "\n==>Inorder sequence: " << endl;
    InOrder(this->root);
}

void BinaryTree::InOrder(TreeNode* t) {
    stack<TreeNode*> stk;
    while(t != 0 || stk.empty() == false) {
        if(t!=0) {
            stk.push(t);
            t = t->left;
        } else {
            t = stk.top();
            stk.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }
}

void BinaryTree::PostOrder() {
    cout << "\n==>Postorder sequence: " << endl;
    PostOrder(this->root);
}

void BinaryTree::PostOrder(TreeNode* t) {
    stack<long int> stk;
    long int temp;
    while(t != 0 || stk.empty() == false) {
        if(t!=0) {
            stk.push((long int)(t));
            t = t->left;
        } else {
            temp= stk.top();
            stk.pop();
            if(temp > 0) {
                stk.push(-temp);
                t = ((TreeNode*)(temp))->right;
            } else {
                cout << ((TreeNode*)(-1 * temp))->data << " ";
                t = 0;
            }
        }
    }
}

void BinaryTree::CountNodes() {
    cout << "\n==>Number of nodes: " << CountNodes(this->root) << " in the tree." << endl;
}

int BinaryTree::CountNodes(TreeNode* ptr) {
    int x, y;
    if(ptr != 0) {
        x = CountNodes(ptr->left);
        y = CountNodes(ptr->right);
        return x+y+1;
    }   
    return 0;
}

void BinaryTree::Sum() {
    cout << "==>Sum of nodes: " << Sum(this->root) << " in the tree." << endl;
}

int BinaryTree::Sum(TreeNode* ptr) {
    int x, y;
    if(ptr != 0) {
        x = Sum(ptr->left);
        y = Sum(ptr->right);
        return x+y+ptr->data;
    }   
    return 0;
}

void BinaryTree::Height() {
    cout << "==>Height of tree: " << Height(this->root) << "." << endl;
}

int BinaryTree::Height(TreeNode* ptr) {
    int x, y;
    if(ptr == 0) return 0;
    if(ptr->left == 0 && ptr->right == 0) return 0;
    if(ptr!= 0) {
        x = Height(ptr->left);
        y = Height(ptr->right);
        if(x>y) return x+1;
        else return y+1;
    }
    return 0;
}

void BinaryTree::GenerateBTFromPreOrderAndInOrder(vector<int>& preorder, vector<int>& inorder) {
    cout << "==>Generating new Tree now: " << endl;
    this->root = GenerateBTFromPreOrderAndInOrder(preorder, inorder, 0, inorder.size() - 1);
}

int BinaryTree::SearchInOrder(vector<int>& inorder, int start, int end, int key) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == key) return i;
    }
    return -1;
}

TreeNode* BinaryTree::GenerateBTFromPreOrderAndInOrder(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
    static int preIndex = 0;
    if(inStart > inEnd) return nullptr;
    TreeNode* root = new TreeNode(preorder[preIndex]);
    preIndex++;
    if(inStart == inEnd) return root;
    int splitIndex = SearchInOrder(inorder, inStart, inEnd, root->data);
    root->left = GenerateBTFromPreOrderAndInOrder(preorder, inorder, inStart, splitIndex-1);
    root->right = GenerateBTFromPreOrderAndInOrder(preorder, inorder, splitIndex+1, inEnd);
    return root;
}

void BinaryTree::LevelOrderPattern() {
    cout << "==>Printing Levels in array" << endl;
    vector<vector<int>> result = LevelOrderPattern(this->root);
    for(auto vec: result) {
        for(auto num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> BinaryTree::LevelOrderPattern(TreeNode* ptr) {
    vector<vector<int>> result;
    if(ptr == 0) return result;
    queue<TreeNode*> queue;
    queue.push(ptr);
    while(!queue.empty()) {
        int levelSize = queue.size();
        vector<int> level;
        for(int i = 0; i < levelSize; i++) {
            TreeNode* node = queue.front(); queue.pop();
            level.push_back(node->data);
            if(node->left) {
                queue.push(node->left);
            }
            if(node->right) {
                queue.push(node->right);
            }
        }
        result.push_back(level);
    }
    return result;
}

void BinaryTree::ReverseLevelOrderPattern() {
    cout << "==>Printing Reverse Level Order Pattern" << endl;
    deque<vector<int>> result = ReverseLevelOrderPattern(this->root);
    for(auto vec: result) {
        for(auto num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

deque<vector<int>> BinaryTree::ReverseLevelOrderPattern(TreeNode* ptr) {
    deque<vector<int>> result;
    if(ptr == 0) return result;
    queue<TreeNode*> queue;
    queue.push(ptr);
    while(!queue.empty()) {
        int levelSize = queue.size();
        vector<int> currentLevel;
        for(int i = 0; i < levelSize; i++) {
            TreeNode* node = queue.front(); queue.pop();
            currentLevel.push_back(node->data);
            if(node->left) {
                queue.push(node->left);
            }
            if(node->right) {
                queue.push(node->right);
            }
        }
        result.push_front(currentLevel);
    }
    return result;
}

void BinaryTree::ZigZagTraversal() {
    cout << "==>Printing Zig-Zag Pattern" << endl;
    vector<vector<int>> result = ZigZagTraversal(this->root);
    for(auto vec: result) {
        for(auto num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> BinaryTree::ZigZagTraversal(TreeNode* ptr) {
    vector<vector<int>> result;
    bool leftToRight = true;
    queue<TreeNode*> queue;
    queue.push(this->root);

    while(!queue.empty()) {
        int levelSize = queue.size();
        vector<int> currentLevel(levelSize);
        for(int i = 0; i < levelSize; i++) {
            TreeNode* node = queue.front();
            queue.pop();
            if(leftToRight) {
                currentLevel[i] = node->data;
            } else {
                currentLevel[levelSize-i-1] = node->data;
            }
            if(node->left) {
                queue.push(node->left);
            }
            if(node->right) {
                queue.push(node->right);
            }
        }
        result.push_back(currentLevel);
        leftToRight = !leftToRight;
    }
    return result;
}

void BinaryTree::LevelAverage() {
    cout << "==>Printing LevelAverage" << endl;
    vector<double> result = LevelAverage(this->root);
    for(auto num: result) {
        cout << num << " ";
    }
    cout << endl;
}

vector<double> BinaryTree::LevelAverage(TreeNode* ptr) {
    vector<double> result;
    if(ptr == 0) return result;
    queue<TreeNode*> queue;
    queue.push(ptr);
    while(!queue.empty()) {
        int levelSize = queue.size();
        int levelSum = 0;
        for(int i = 0; i < levelSize; i++) {
            TreeNode* node = queue.front(); queue.pop();
            levelSum += node->data;
            if(node->left) {
                queue.push(node->left);
            }
            if(node->right) {
                queue.push(node->right);
            }
        }
        result.push_back((1.0*levelSum)/levelSize);
    }
    return result;
}

void BinaryTree::MinDepth() {
    cout << "Min depth of the tree " << MinDepth(this->root) << endl;
}

int BinaryTree::MinDepth(TreeNode* ptr) {
    int minDepth = 0;
    if(ptr == 0) return 0;
    queue<TreeNode*> queue;
    queue.push(ptr);
    while(queue.empty() == false) {
        minDepth++;
        int levelSize = queue.size();
        for(int i = 0; i < levelSize; i++) {
            TreeNode* node = queue.front();
            queue.pop();
            if(node->left == 0 && node->right == 0) return minDepth;
            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }
    }
    return minDepth;
}

void BinaryTree::LevelOrderSuccessor(int key) {
    TreeNode* ptr = this->root;
    if(ptr == 0) return;
    queue<TreeNode*> queue;
    queue.emplace(ptr);

    while(queue.empty() == false) {
        ptr = queue.front();
        queue.pop();
        if(ptr->left) {
            queue.push(ptr->left);
        }
        if(ptr->right) {
            queue.push(ptr->right);
        }
        if(ptr->data == key) {
            cout << "Level Order Successor: " << queue.front()->data << endl;
            return;
        }
    }
    cout << "No Level Order Successor Found" << endl;
}

void BinaryTree::ConnectLevelOrderSiblings() {
    if(this->root == 0) return;
    TreeNode* ptr = this->root;
    queue<TreeNode*> queue;
    queue.push(ptr);

    while(queue.empty() == false) {
        int levelSize = queue.size();
        TreeNode* previous = 0;
        for(int i = 0; i < levelSize; i++) {
            TreeNode* node = queue.front();
            queue.pop();
            if(previous != 0) {
                previous->next = node;
            }
            previous = node;
            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }
    }
}

void BinaryTree::ConnectLevelOrderSiblingsToNextLevel() {
    if(this->root == 0) return;
    TreeNode* ptr = this->root;
    queue<TreeNode*> queue;
    queue.push(this->root);

    TreeNode* previous = 0;
    //no level division is needed
    while(queue.empty() == false) {
        ptr = queue.front();
        queue.pop();
        if(previous != nullptr) {
            previous->next = ptr;
        }
        previous = ptr;
        if(ptr->left) queue.push(ptr->left);
        if(ptr->right) queue.push(ptr->right);
    }
}

void BinaryTree::RightView() {
    if(this->root == 0) return;
    TreeNode* ptr = this->root;
    queue<TreeNode*> queue;
    queue.push(ptr);
    cout << "Right view of the BT: " << endl;
    while(queue.empty() == false) {
        int levelSize = queue.size();
        for(int i = 0; i < levelSize; i++) {
            TreeNode* node = queue.front();
            queue.pop();
            if(i == levelSize - 1) {
                cout << node->data << " ";
            }
            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }
    }
    cout << endl;
}

void BinaryTree::HasPath() {
    int sum = 23;
    if(this->HasPath(this->root, sum)) {
        cout << "Path with sum " << sum << " found." << endl;
    } else {
        cout << "Path not found." << endl;
    }
}

bool BinaryTree::HasPath(TreeNode* ptr, int sum) {
    if(ptr == 0) return 0;
    if(ptr->left == 0 && ptr->right == 0) {
        if(ptr->data == sum) {
            return true;
        } else {
            return false;
        }
    }
    return HasPath(ptr->left, sum - ptr->data) || HasPath(ptr->right, sum - ptr->data);
}

/*
Given a BT and a sum S; return all paths from root to leaf which has sum: S
T: n nodes. For each node, path could be n-nodes long and it takes n-time to copy the current path to allPaths.
T: O(nxn) 
*/

void BinaryTree::AllPathsForSum() {
    vector<vector<int>> allPaths;
    vector<int> currentPath;
    int sum = 12;
    AllPathsForSum(this->root, sum, currentPath, allPaths);
    cout << "Printing all path from root to leaf SUMMING to " << sum << endl;
    for(auto vect: allPaths) {
        cout << "[";
        for(auto path: vect) {
            cout << path << "-->";
        }
        cout << "]";
        cout << endl;
    }
}

void BinaryTree::AllPathsForSum(TreeNode* current, int sum, vector<int>& currentPath, vector<vector<int>>& allPaths) {
    if(current == 0) return;
    currentPath.push_back(current->data);

    if(current->left == 0 && current->right == 0 && current->data == sum) {
        allPaths.push_back(currentPath);
    }
    else {
        AllPathsForSum(current->left, sum - current->data, currentPath, allPaths);
        AllPathsForSum(current->right, sum - current->data, currentPath, allPaths);
    }

    //backtracking
    currentPath.pop_back();
}

void BinaryTree::AllPaths() {
    vector<vector<int>> allPaths;
    vector<int> currentPath;
    AllPaths(this->root, currentPath, allPaths);
    cout << "Printing ALL from root to leaf"<< endl;
    for(auto vect: allPaths) {
        cout << "[";
        for(auto path: vect) {
            cout << path << "-->";
        }
        cout << "]";
        cout << endl;
    }
}

void BinaryTree::AllPaths(TreeNode* current, vector<int>& currentPath, vector<vector<int>>& allPaths) {
    if(current == 0) return;
    currentPath.push_back(current->data);

    if(current->left == 0 && current->right == 0) {
        allPaths.push_back(currentPath);
    }
    else {
        AllPaths(current->left, currentPath, allPaths);
        AllPaths(current->right,currentPath, allPaths);
    }
    currentPath.pop_back();
}

void BinaryTree::SumOfPathNumbers() {
    cout << "Total SUM of ALL paths found from pathSum = pathSum*10 + node->data is: " << SumOfPathNumbers(this->root, 0) << endl;
}

int BinaryTree::SumOfPathNumbers(TreeNode* current, int pathSum) {
    if(current == 0) return 0;
    pathSum = 10*pathSum + current->data;
    if(current->left == 0 && current->right == 0) {
        return pathSum;
    }
    return SumOfPathNumbers(current->left, pathSum) + SumOfPathNumbers(current->right, pathSum);
}

void BinaryTree::FindIfSequencePathExists() {
    vector<int> sequence{1,9,9};
    if(FindIfSequencePathExists(this->root, sequence, 0)) {
        cout << "Sequence found!" << endl;
    } else {
        cout << "Sequence not found!" << endl;
    }
}

bool BinaryTree::FindIfSequencePathExists(TreeNode* current, vector<int>& sequence, unsigned int idx) {
    if(current == 0) return sequence.empty();
    if(idx > sequence.size() - 1 || sequence[idx] != current->data) {
        return false;
    } else if(idx == sequence.size() -1 && sequence[idx] == current->data && current->left == 0 && current->right == 0) {
        return true;
    }
    return FindIfSequencePathExists(current->left, sequence, idx+1) || FindIfSequencePathExists(current->right, sequence, idx+1);
}

void BinaryTree::CountNonRootedPathsForSum() {
    int sum = 12;
    vector<int> currentPath;
    cout << "Total number of rooted/non-rooted path equal to sum " << CountNonRootedPathsForSum(this->root, currentPath, sum) << endl;
}

int BinaryTree::CountNonRootedPathsForSum(TreeNode* current, vector<int>& currentPath, int sum) {
    if(current == 0) return 0;
    currentPath.push_back(current->data);
    //new entry. Find all sub path sum
    int pathSum = 0, pathCount = 0;
    for(vector<int>::reverse_iterator itr = currentPath.rbegin(); itr != currentPath.rend(); itr++) {
        pathSum += *itr;
        if(pathSum == sum) {
            pathCount++;
        }
    }
    pathCount += CountNonRootedPathsForSum(current->left, currentPath, sum);
    pathCount += CountNonRootedPathsForSum(current->right, currentPath, sum);
    currentPath.pop_back();
    return pathCount;
}

void BinaryTree::Diameter() {
    cout << "Tree Diameter is: " << Diameter(this->root) << endl;
}

int BinaryTree::Diameter(TreeNode* ptr) {
    if(ptr == 0) return 0;
    int leftHeight = Height(ptr->left);
    int rightHeight = Height(ptr->right);

    int leftDia = Diameter(ptr->left);
    int rightDia = Diameter(ptr->right);

    int rootDia = max(leftHeight, rightHeight) + 1;

    return max(rootDia, max(leftDia, rightDia));
} 
