#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};

typedef struct TNODE *TREE;

TREE CreateNode(int x)
{
    TREE p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void InsertNode(TREE &tree, int x)
{
    if (tree == NULL)
    {
        tree = CreateNode(x);
        return;
    }
    if (tree->key == x) return;
    if (x < tree->key) InsertNode(tree->pLeft, x);
    else InsertNode(tree->pRight, x);
}

void CreateTree(TREE &tree)
{
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1) break;
        InsertNode(tree, x);
    }
}

void NLR(TREE tree)
{
    if (tree == NULL) return;
    cout << tree->key << " ";
    NLR(tree->pLeft);
    NLR(tree->pRight);
}

void PrintTree(TREE tree)
{
    if (tree == NULL)
    {
        cout << "Empty Tree.";
        return;
    }

    NLR(tree);
}


int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);


	PrintTree(T);
	return 0;
}
