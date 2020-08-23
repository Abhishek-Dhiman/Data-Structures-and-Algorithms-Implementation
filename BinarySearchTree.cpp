#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
node * create_new_node(int x)
{
    node *temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = x;

    return temp;
}
void insert_to_BST(struct node *root, int x)
{
    if (x <= root->data)
    {
        if (root->left == NULL)
        {
            root->left = create_new_node(x);
            return;
        }
        else
            insert_to_BST(root->left, x);
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = create_new_node(x);
            return;
        }
        else
            insert_to_BST(root->right, x);
    }
}
void inorder_traversal(struct node *root)
{
    if (root == NULL)
        return;

    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}
int min_BST(struct node *root)
{
    if (root->left == NULL)
        return root->data;

    return min_BST(root->left);
}
int max_BST(struct node *root)
{
    if (root->right == NULL)
        return root->data;

    return max_BST(root->right);
}
int main() {
    // Enter the number of elements to be added in BST
    int n;
    cin >> n;
    bool is_first = true;
    node *root = NULL;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (is_first)
        {
            root = create_new_node(arr[i]);
            is_first = false;
        }
        else
        {
            insert_to_BST(root, arr[i]);
        }
    }
    inorder_traversal(root);
    cout << "\n";
    cout << min_BST(root) << "\n";
    cout << max_BST(root) << "\n";
    return 0;
}
