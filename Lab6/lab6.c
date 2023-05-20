/*
 This is lab 6, which uses a binary tree data structure. The program will allow the user to select menu options: add node,
 delete node, print the three types for traverse methods, print the file, run the file, and exit the program.
*/

//imported libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure
//====================================================================================================================
//Structure Node: contains num, left pointer, and right pointer
struct Node
{
    int num;
    struct Node *left;
    struct Node *right;
};

//Functions
//====================================================================================================================
//Function CreateTree0: create an empty binary tree with just root pointer
void createTree0(struct Node **root)
{
    *root = NULL;
}

//Function CreateTree1: create binary tree with 1 root node
void createTree1(struct Node **root, int num)
{
    if(*root != NULL)
    {
        printf("\nThe tree already has a root node!\n");
        return;
    }

    else
    {
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));    //create node/allocate space
        newNode->num = num;  //insert data
        newNode->left = NULL;   //left and right pointer to null
        newNode->right = NULL;
        *root = newNode;	//set root to new node address
    }
}

//Function TraverseFind: search tree, return:(true = found | false = not found)
int traverseFind(struct Node *root, int num)
{
    if(root == NULL)
        return 0;
    else if(root->num == num)
        return 1;
    else if(num < root->num)
        return traverseFind(root->left, num);
    else
        return traverseFind(root->right, num);
}

//Function AddNode: create node given an int value
struct Node *addInt(int num) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->num = num;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function AddNode: add node given a node
void addNode(struct Node **root, int num) {
    if (*root == NULL)
    {
        *root = addInt(num);
        return;
    }

    if(num < (*root)->num)
        addNode(&((*root)->left), num);
    else if (num > (*root)->num)
        addNode(&((*root)->right), num);
}

//Function DeleteNode: delete node
void deleteNode(struct Node **root, int num)
{
    if (num < (*root)->num) //if the key is smaller than the root's key,
        deleteNode(&((*root)->left), num);  //then it lies in the left subtree
    else if (num > (*root)->num)    //if the key is greater than the root's key,
        deleteNode(&((*root)->right), num); //then it lies in the right subtree
    else //if the key is the same as the root's key, then this is the node to be deleted
    {
        //node with only one child or no child
        if ((*root)->left == NULL)
        {
            struct Node *temp = (*root)->right;
            free(*root);
            *root = temp;
        }
        else if ((*root)->right == NULL)
        {
            struct Node *temp = (*root)->left;
            free(*root);
            *root = temp;
        }

        //node with two children
        else
        {
            struct Node *current = (*root)->right;

            while (current->left != NULL) //find the leftmost leaf in the right subtree
                current = current->left;
            (*root)->num = current->num;    //copy the value of the leftmost leaf to the current node
            deleteNode(&((*root)->right), current->num);//delete leftmost leaf in right subtree
        }
    }
}

//Function TraversePreOrderPrint: print all values in pre-order
void traversePreOrderPrint(struct Node *root)
{
    if(root == NULL)
        return;
    printf("%d ", root->num);    //print current node
    traversePreOrderPrint(root->left);   //travel left
    traversePreOrderPrint(root->right);  //travel right
}

//Function TraverseInOrderPrint: print all values in order
void traverseInOrderPrint(struct Node *root)
{
    if(root == NULL)
        return;
    traverseInOrderPrint(root->left);   //travel left subtree
    printf("%d ", root->num);    //print current node
    traverseInOrderPrint(root->right);   //travel right subtree
}

//Function TraversePostOrderPrint: print all values in post order
void traversePostOrderPrint(struct Node *root)
{
    if(root == NULL)
        return;
    traversePostOrderPrint(root->left);   //travel left
    traversePostOrderPrint(root->right);  //travel right
    printf("%d ", root->num);    //print current node
}

//Function OpenFile: creates a file stream
FILE *openFile()
{
    //open file stream
    FILE *inFile = fopen("testing.txt", "r");

    if(inFile == NULL)
    {
        printf("\nFile was not successfully opened!\n");
        exit(1);
    }
    return inFile;
}

//Function PrintFile: prints the contents of the file
void printFile(FILE *inFile)
{
    int c;
    while ((c = fgetc(inFile)) != EOF)
        putchar(c);
}

//Function Menu: display menu options for the user
void menu()
{
    printf("\n\nSelect a menu option!\n");
    printf("=========================\n");
    printf("1. Add node\n");
    printf("2. Delete node.\n");
    printf("3. Print pre/in/post order.\n");
    printf("4. Print file.\n");
    printf("5. Run file\n");
    printf("6. Exit\n");
    printf("\nEnter a number between 1 and 6: ");
}

//main function
//====================================================================================================================
int main()
{
    //menu variables
    int choice;
    char temp;
    int num;
    char line[100];
    char command[20];
    int data;

    //open file stream
    FILE *inFile = openFile();

    //initialize root
    struct Node *root;
    createTree0(&root); //root is null

    //while loop in case user wants to run functions again
    do{
        menu();    //called menu function

        if(scanf("%d", &choice) != 1)    //input validation
        {
            printf("Please enter a number between (1-6).\n");
            scanf("%s", &temp);    //clear input buffer
            continue;
        }

        //switch case for menu options
        switch(choice)
        {
            //add node case
            case 1:
                printf("Enter a number to add: ");
                while(scanf("%d", &num) != 1)
                {
                    printf("\nInvalid input, enter a number: ");
                    while(getchar() != '\n');
                }

                if(root == NULL)
                    createTree1(&root, num);
                else if(traverseFind(root, num) == 1)
                {
                    printf("\nThis number already exists in the tree!\n");
                    break;
                }
                else
                    addNode(&root, num);
                break;

            //delete node case
            case 2:
                if(root == NULL)
                {
                    printf("\nThe tree is empty, add a node first!\n");
                    break;
                }

                printf("Enter a number to remove: ");
                while(scanf("%d", &num) != 1)
                {
                    printf("\nInvalid input, enter a number: ");
                    while(getchar() != '\n');
                }

                if(traverseFind(root, num) == 0)
                {
                    printf("\nThis number does not exists in the tree!\n");
                    break;
                }
                else
                    deleteNode(&root, num);
                break;

            //print pre/in/post order case
            case 3:
                printf("\nPre-order print!\n");
                printf("========================\n");
                traversePreOrderPrint(root);
                printf("\n\nIn-order print!\n");
                printf("========================\n");
                traverseInOrderPrint(root);
                printf("\n\nPost-order print!\n");
                printf("========================\n");
                traversePostOrderPrint(root);
                break;

            //print file case
            case 4:
                printFile(inFile);
                break;

            //run file case
            case 5:
                while (fgets(line, sizeof(line), inFile) != NULL)   //loop through the file by line
                {
                    sscanf(line, "%s %d", command, &data);
                    if (strcmp(command, "insert") == 0) //insert command
                    {
                        if(root == NULL)
                            createTree1(&root, data);
                        else if(traverseFind(root, data) == 1)
                            printf("\nCommand skipped!\nThis number already exists in the tree!\n");
                        else
                            addNode(&root, data);
                    }

                    else if (strcmp(command, "delete") == 0)    //delete command
                    {
                        if(root == NULL)
                            printf("\nThe tree is empty!\nCommand skipped!\n");
                        else if(traverseFind(root, data) == 0)
                            printf("\n\nCommand skipped!\n%d does not exist in the tree!\n", data);
                        else
                            deleteNode(&root, data);
                    }

                    else if (strcmp(command, "traverse") == 0)  //traverse command
                    {
                        char order[20];
                        if (sscanf(line, "%s %s", command, order) != 2)
                        {
                            printf("Missing traversal order.\n");
                            continue;
                        }

                        if(strcmp(order, "pre-order") == 0) //pre-order traverse
                        {
                            printf("\nPre-order print!\n");
                            printf("========================\n");
                            traversePreOrderPrint(root);
                        }

                        else if(strcmp(order, "in-order") == 0) //in-order traverse
                        {
                            printf("\n\nIn-order print!\n");
                            printf("========================\n");
                            traverseInOrderPrint(root);
                        }

                        else if(strcmp(order, "post-order") == 0)   //post order traverse
                        {
                            printf("\n\nPost-order print!\n");
                            printf("========================\n");
                            traversePostOrderPrint(root);
                        }
                        else
                            printf("Invalid traversal order: %s\n", order);
                    }
                }
                break;

            //exit program case
            case 6:
                printf("Exiting the program.\n\n");
                break;

            //if user selects invalid option
            default:
                printf("Please enter a number between (1-6).\n");
                break;

        }//end switch
    } while(choice != 6);

    fclose(inFile);
    return 0;
}//end main