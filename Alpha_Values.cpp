#include <iostream>
using namespace std;

class BinaryTree
{
public:
    int Data;
    string Alpha;
    BinaryTree *left;
    BinaryTree *right;
};

class BinaryTree_Fun
{
public:
    BinaryTree *Root = NULL;
    void insertion(string alpha, int Data)
    {
        BinaryTree *ptr;
        BinaryTree *NewNode = new BinaryTree();
        NewNode->Data = Data;
        NewNode->Alpha = alpha;
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
    int inorder(BinaryTree *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        inorder(root->left);
        cout << root->Alpha << "   ";
        inorder(root->right);
        return 1;
    }
    int preorder(BinaryTree *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        cout << root->Alpha << "   ";
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
        cout << root->Alpha << "   ";
        return 1;
    }
};
int main()
{
    system("color 0A");
    BinaryTree_Fun Obj;
    int count1 = 0;
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
        cout << "Press 6 For Exit\n";
        cout << "Input = ";
        cin >> val;
        switch (val)
        {
        case 1:
        {
            string DF;
            cout<<"A=87, B=16, C=91, D=70, E=71, F=38, G=81, H=21, I=28, J=32, K=65, L=10, M=43, N= 97, O=0\n";
            if (count1 == 0)
            {
                Obj.insertion("A", 87); //Root By default
                count1++;
            }
            cout << "Enter int Data\n";
            cin >> DF;
            if (DF == "B")
            {
                Obj.insertion(DF, 16);
            }
            else if (DF == "C")
            {
                Obj.insertion(DF, 91);
            }
            else if (DF == "D")
            {
                Obj.insertion(DF, 70);
            }
            else if (DF == "E")
            {
                Obj.insertion(DF, 71);
            }
            else if (DF == "F")
            {
                Obj.insertion(DF, 38);
            }
            else if (DF == "G")
            {
                Obj.insertion(DF, 81);
            }
            else if (DF == "H")
            {
                Obj.insertion(DF, 21);
            }
            else if (DF == "I")
            {
                Obj.insertion(DF, 28);
            }
            else if (DF == "J")
            {
                Obj.insertion(DF, 32);
            }
            else if (DF == "K")
            {
                Obj.insertion(DF, 65);
            }
            else if (DF == "L")
            {
                Obj.insertion(DF, 10);
            }
            else if (DF == "M")
            {
                Obj.insertion(DF, 43);
            }
            else if (DF == "N")
            {
                Obj.insertion(DF, 97);
            }
            else if (DF == "O")
            {
                Obj.insertion(DF, 0);
            }
            else
            {
                cout << "Again Try Enter Between B to O (ALL in capital)\n";
            }
            system("PAUSE");
            break;
        }
        case 2:
        {
            BinaryTree *DL;
            cout << "Root Data is = ";
            DL = Obj.TreeRoot();
            if (DL != NULL)
            {
                cout << DL->Data << endl;
            }
            else
            {
                cout << "Empty\n";
            }
            system("PAUSE");
            break;

        case 3:
        {
            int DA;
            cout << "Inorder Traversing = ";
            DA = Obj.inorder(Obj.Root);
            if (DA == 0)
            {
                cout << "Empty\n";
            }
            else
            {
                cout << " .\n";
            }
            system("PAUSE");
            break;
        }
        case 4:
        {
            int DA;
            cout << "preorder Traversing = ";
            DA = Obj.preorder(Obj.Root);
            if (DA == 0)
            {
                cout << "Empty\n";
            }
            else
            {
                cout << " .\n";
            }
            system("PAUSE");
            break;
        case 5:
        {
            int DA;
            cout << "Postorder Traversing = ";
            DA = Obj.postorder(Obj.Root);
            if (DA == 0)
            {
                cout << "Empty\n";
            }
            else
            {
                cout << " .\n";
            }
            system("PAUSE");
            break;
        }
        case 6:
        {
            Goto = false;
            break;
        }
        default:
            break;
        }
        }
        }
    }
}
