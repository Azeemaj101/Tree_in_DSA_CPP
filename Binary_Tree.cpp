#include <iostream>
#define SPACE 10
using namespace std;

class BinaryTree
{
public:
    int Data;
    BinaryTree *left;
    BinaryTree *right;
};

class BinaryTree_Fun
{
public:
    BinaryTree *Root = NULL;
    void insertion(int Data)
    {
        BinaryTree *ptr;
        BinaryTree *NewNode = new BinaryTree();
        NewNode->Data = Data;
        NewNode->left = NULL;
        NewNode->right = NULL;
        if (Root == NULL)
        {
            Root = NewNode;
        }
        else
        {
            ptr = Root;
            while (ptr != NULL)
            {
                if (ptr->Data > Data)
                {
                    if (ptr->left == NULL)
                    {
                        ptr->left = NewNode;
                        break;
                    }
                    ptr = ptr->left;
                }
                else if (ptr->Data < Data)
                {
                    if (ptr->right == NULL)
                    {
                        ptr->right = NewNode;
                        break;
                    }
                    ptr = ptr->right;
                }
            }
        }
    }
    BinaryTree *TreeRoot()
    {
        return Root;
    }
    BinaryTree *Delete(BinaryTree *root, int Data)
    {
        BinaryTree *temp;
        if (root == NULL)
        {
            cout << "NO such element exists\n";
        }
        else if (Data < root->Data)
        {
            root->left = Delete(root->left, Data);
        }
        else if (Data > root->Data)
        {
            root->right = Delete(root->right, Data);
        }
        else
        {
            if (root->left && root->right)
            {
                temp = findMinimum(root->left);
                root->Data = temp->Data;
                root->left = Delete(root->left, root->Data);
            }
            else
            {
                temp = root;
                if (root->left == NULL)
                {
                    root = root->right;
                }
                else if (root->right == NULL)
                {
                    root = root->left;
                }
                delete (temp);
            }
        }
        Root = root;
        return root;
    }
    BinaryTree *Search(BinaryTree *root, int Data)
    {
        if (root == NULL || root->Data == Data)
            return root;
        if (root->Data < Data)
            return Search(root->right, Data);
        return Search(root->left, Data);
    }
    int inorder(BinaryTree *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        inorder(root->left);
        cout << root->Data << "   ";
        inorder(root->right);
        return 1;
    }
    int preorder(BinaryTree *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        cout << root->Data << "   ";
        preorder(root->left);
        preorder(root->right);
        return 1;
    }
    int postorder(BinaryTree *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->Data << "   ";
        return 1;
    }
    BinaryTree *findMinimum(BinaryTree *cur)
    {
        while (cur->left != NULL)
        {
            cur = cur->left;
        }
        return cur;
    }
    void print2D(BinaryTree *r, int space) {
    if (r == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> Data << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
  }
    int height(BinaryTree *r) {
    if (r == NULL)
      return -1;
    else {
      /* compute the height of each subtree */
      int lheight = height(r -> left);
      int rheight = height(r -> right);

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }
};
int main()
{
    system("color 0A");
    BinaryTree_Fun Obj;
    bool Goto = true;
    while (Goto == true)
    {
        system("CLS");
        int val;
        cout << "Press 1  For Insert\n";
        cout << "Press 2  For View   Root\n";
        cout << "Press 3  For View   Inorder\n";
        cout << "Press 4  For View   Preorder\n";
        cout << "Press 5  For View   Postorder\n";
        cout << "Press 6  For Search Data\n";
        cout << "Press 7  For Delete Data\n";
        cout << "Press 8  For 2D     View\n";
        cout << "Press 9  For Height\n";
        cout << "Press 10 For Exit\n";
        cout << "Input = ";
        cin >> val;
        switch (val)
        {
        case 1:
        {
            int DF;
            cout << "Enter int Data\n";
            cin >> DF;
            Obj.insertion(DF);
            system("PAUSE");
            break;
        }
        case 2:
        {
            BinaryTree *DL;
            cout << "Root Data is = ";
            DL = Obj.TreeRoot();
            if(DL != NULL)
            {
                cout<<DL->Data<<endl;
            }
            else
            {
                cout<<"Empty\n";
            }
            system("PAUSE");
            break;
        }
        case 3:
        {
            int DA;
            cout << "Inorder Traversing = ";
            DA = Obj.inorder(Obj.Root);
            if(DA == 0)
            {
                cout<<"Empty\n";
            }
            else
            {
                cout<<" .\n";
            }
            system("PAUSE");
            break;
        }
        case 4:
        {
            int DA;
            cout << "preorder Traversing = ";
            DA = Obj.preorder(Obj.Root);
            if(DA == 0)
            {
                cout<<"Empty\n";
            }
            else
            {
                cout<<" .\n";
            }
            system("PAUSE");
            break;
        }
        case 5:
        {
            int DA;
            cout << "Postorder Traversing = ";
            DA = Obj.postorder(Obj.Root);
            if(DA == 0)
            {
                cout<<"Empty\n";
            }
            else
            {
                cout<<" .\n";
            }
            system("PAUSE");
            break;
        }
        case 6:
        {
            int DA;
            BinaryTree *DA1;
            cout << "Enter Data For Search = ";
            cin>>DA;
            DA1 = Obj.Search(Obj.Root,DA);
            if(DA1 != NULL)
            {
                cout<<DA1->Data<<" Value is Found \n";
            }
            else
            {
                cout<<"Not Found\n";
            }
            system("PAUSE");
            break;
        }
        case 7:
        {
            int DA1;
            int DA;
            BinaryTree *DA2;
            cout << "Inorder Traversing = ";
            DA1 = Obj.inorder(Obj.Root);
            if(DA1 == 0)
            {
                cout<<"Empty\n";
            }
            else
            {
                cout<<" .\n";
            }
            cout << "Enter Data For Delete = ";
            cin>>DA;
            DA2 =Obj.Delete(Obj.Root,DA);
            if (DA2 != NULL)
            {
                cout<<"Process...\n";
            }
            
            system("PAUSE");
            break;
        }
        case 8:
        {
            cout << "2D Traversing = ";
            Obj.print2D(Obj.Root, 5);
            system("PAUSE");
            break;
        }
        case 9:
        {
            int DA;
            DA = Obj.height(Obj.Root);
            cout<<"Height is "<<DA<<endl;
            system("PAUSE");
            break;
        }
        case 10:
        {
            Goto = false;
            break;
        }
        default:
            break;
        }
    }
}