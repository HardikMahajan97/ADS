#include <iostream>
#include <queue>
using namespace std;

// Node structure for the binary search tree
class node
{
public:
  int data;
  node *left, *right;

  // Constructor to initialize node with data
  node(int d)
  {
    data = d;
    left = right = nullptr;
  }
};

// Function to insert a new node in the BST
node *insert_node(node *root, int data)
{
  if (!root)
  {
    return new node(data);
  }

  if (data < root->data)
  {
    root->left = insert_node(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insert_node(root->right, data);
  }
  return root;
}

// Function to take user input and construct the BST
void takeinput(node *&root)
{
  int data;
  cout << "Enter the node data (-1 to stop): ";
  cin >> data;

  while (data != -1)
  {
    root = insert_node(root, data);
    cout << "Enter the node data (-1 to stop): ";
    cin >> data;
  }
}

// Function to perform level-order traversal (BFS)
void levelorder(node *root)
{
  if (!root)
    return;
  queue<node *> q;
  q.push(root);
  q.push(nullptr);
  while (!q.empty())
  {
    node *temp = q.front();
    q.pop();
    if (!temp)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(nullptr);
      }
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }
}

// Function for inorder traversal (Left, Root, Right)
void inorder(node *root)
{
  if (!root)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

// Function for preorder traversal (Root, Left, Right)
void preorder(node *root)
{
  if (!root)
    return;
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

// Function for postorder traversal (Left, Right, Root)
void postorder(node *root)
{
  if (!root)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

// Recursive function to search for an element in the BST
bool search(node *root, int data)
{
  if (!root)
    return false;
  if (data < root->data)
    return search(root->left, data);
  if (data > root->data)
    return search(root->right, data);
  return true;
}

// Iterative function to search for an element in the BST
bool search_iterative(node *root, int data)
{
  while (root)
  {
    if (data < root->data)
      root = root->left;
    else if (data > root->data)
      root = root->right;
    else
      return true;
  }
  return false;
}

// Function to find the node with the minimum value in the BST
node *minval(node *root)
{
  while (root && root->left)
    root = root->left;
  return root;
}

// Function to find the node with the maximum value in the BST
node *maxval(node *root)
{
  while (root && root->right)
    root = root->right;
  return root;
}

// Function to delete a node from the BST
node *delete_node(node *&root, int key)
{
  if (!root)
    return root;
  if (key < root->data)
  {
    root->left = delete_node(root->left, key);
  }
  else if (key > root->data)
  {
    root->right = delete_node(root->right, key);
  }
  else
  {
    if (!root->left && !root->right) // No child case
    {
      delete root;
      return nullptr;
    }
    else if (!root->left) // One child (right) case
    {
      node *temp = root->right;
      delete root;
      return temp;
    }
    else if (!root->right) // One child (left) case
    {
      node *temp = root->left;
      delete root;
      return temp;
    }
    else // Two children case
    {
      // Inorder successor
      node *minNode = minval(root->right);
      root->data = minNode->data;
      root->right = delete_node(root->right, minNode->data);
    }
  }
  return root;
}

// Main function to test the BST implementation
int main()
{
  node *root = NULL;
  int data;
  takeinput(root);

  cout << "\nLevel Order Traversal:" << endl;
  levelorder(root);

  cout << "\nPreorder Traversal:" << endl;
  preorder(root);

  cout << "\nInorder Traversal:" << endl;
  inorder(root);

  cout << "\nPostorder Traversal:" << endl;
  postorder(root);

  cout << "\n\nEnter the element to search: ";
  cin >> data;
  if (search_iterative(root, data))
    cout << "Found" << endl;
  else
    cout << "Not Found" << endl;

  cout << "Minimum value node: " << minval(root)->data << endl;
  cout << "Maximum value node: " << maxval(root)->data << endl;

  cout << "Enter node value to delete: ";
  cin >> data;
  root = delete_node(root, data);
  cout << "Node deleted successfully!" << endl;

  cout << "\nInorder after deletion:" << endl;
  inorder(root);
  cout << "\nLevel Order after deletion:" << endl;
  levelorder(root);

  return 0;
}
