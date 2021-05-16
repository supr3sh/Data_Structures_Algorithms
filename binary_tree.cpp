#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
	cout<<"Enter root data: ";
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
		cout<<"\nEnter left child of "<<currentNode->data<<": ";
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
		cout<<"\nEnter right child of "<<currentNode->data<<": ";
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

void printLevelWise(BinaryTreeNode<int> *root) {
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	
	while(!q.empty())
	{
		BinaryTreeNode<int>* curNode = q.front();
		q.pop();
		cout<<"\n"<<curNode->data<<": ";
		if(curNode->left != NULL)
		{
			cout<<"L"<<curNode->left->data;
			q.push(curNode->left);
		}
		if(curNode->left != NULL && curNode->right != NULL)
		{
			cout<<", ";
		}
		if(curNode->right != NULL)
		{
			cout<<"R"<<curNode->right->data;
			q.push(curNode->right);
		}
	}
}

int height(BinaryTreeNode<int>* root) {
	if(root == NULL)
		return 0;
	
	return 1 + max(height(root->left), height(root->right));
}

void preOrder(BinaryTreeNode<int>* root) {
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(BinaryTreeNode<int>* root) {
	if(root == NULL)
		return;
	
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

void inOrder(BinaryTreeNode<int>* root) {
	if(root == NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

pair<int, int> heightAndDiameter(BinaryTreeNode<int>* root) {
	if(root == NULL)
	{
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	
	pair<int, int> leftAns = heightAndDiameter(root->left);
	pair<int, int> rightAns = heightAndDiameter(root->right);
	
	int lHeight = leftAns.first;
	int rHeight = rightAns.first;
	int lDia = leftAns.second;
	int rDia = rightAns.second;
	
	pair<int, int> p;
	p.first = 1 + max(lHeight, rHeight);
	p.second = max(lHeight + rHeight, max(lDia, rDia));
	
	return p;
	
}

pair<int, int> minAndMax(BinaryTreeNode<int>* root) {
	if(root == NULL)
	{
		pair<int, int> p;
		p.first = INT_MAX;
		p.second = INT_MIN;
		return p;
	}
	
	pair<int, int> lAns = minAndMax(root->left);
	pair<int, int> rAns = minAndMax(root->right);
	
	int lMin = lAns.first;
	int rMin = rAns.first;
	int lMax = lAns.second;
	int rMax = rAns.second;
	
	pair<int, int> ans;
	ans.first = min(root->data, min(lMin, rMin));
	ans.second = max(root->data, max(lMax, rMax));
	return ans;
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
    cout<<"\nHeight: "<<height(root);
    cout<<"\nPreOrder :\t";
	preOrder(root);
	cout<<"\nPostOrder :\t";
	postOrder(root);
	cout<<"\nInOrder :\t";
	inOrder(root);
	pair<int, int> hAndD = heightAndDiameter(root);
	cout<<"\nHeight :"<<hAndD.first;
	cout<<"\nDiameter:"<<hAndD.second;
	pair<int, int> minNdMax = minAndMax(root);
	cout<<"\nMin value: "<<minNdMax.first;
	cout<<"\nMax value: "<<minNdMax.second;
}
