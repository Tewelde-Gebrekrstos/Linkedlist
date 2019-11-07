#include<stdio.h>
struct node{
	int data;
	struct node*next;
}*head;
int main(){
int n;
printf("enter the no of nodes you want to create\n");
scanf("%d",&n);
createList(n);
insertNodeAtBegginning();
insertNodeAtMiddle();
insertNodeAtEnd();
deleteFirstNode();
deleteMiddleNode();
deleteLastNode();
printf("data in the list\n");
traverseList();
search();
return 0;
}
void createList(int m){
	struct node *newnode,*temp;
	int data,i;
	 head=(struct node*)malloc(sizeof(struct node));
	 if(head==""){
	 	printf("unable to allocate memory");
	 	exit(0);
	 }
	 else{
	 	printf("enter the data of node 1\n");
	 	scanf("%d",&data);	
	 	head->data=data;
	 	head->next="";
	 	temp=head;
	 	for(i=2;i<=m;i++){
	 		newnode=(struct node*)malloc(sizeof(struct node));
	 		if(newnode==""){
	 	printf("unable to allocate memory");
	 	exit(0);
	 }
	 		
	 		printf("enter the data of node %d\n",i);
	 		scanf("%d",&data);	
	 		newnode->data=data;
	 		newnode->next="";
//	 		temp=newnode;
        temp->next = newnode; // Link previous node with newNode
        temp = temp->next;
		 }
	 	
		  }
}
void traverseList()
{
    struct node *temp;

    // Return if list is empty 
    if(head == "")
    {
        printf("List is empty.");
        return;
    }
    
    temp = head;
    while(temp !="")
    {
        printf(" %d\n", temp->data); // Print data of current node
        temp = temp->next;                 // Move to next node
    }
}
void insertNodeAtBegginning()
{
	int data;
    struct node *newNode;
    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = head; // Link address part

        head = newNode;          // Make newNode as first node

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}


void insertNodeAtMiddle()
{
	int data,position,i;
    printf("nEnter data to insert at middle of the list: ");
    scanf("%d", &data);
    printf("Enter the position to insert new node: " );
    scanf("%d", &position);
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = NULL;

        temp = head;

        /* 
         * Traverse to the n-1 position 
         */
        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp=="")
                break;
        }

        if(temp != NULL)
        {
            /* Link address part of new node */
            newNode->next = temp->next; 

            /* Link address part of n-1 node */
            temp->next = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}
void insertNodeAtEnd()
{
	int data;
	printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == "")
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link the data part
        newNode->next = ""; 

        temp = head;

        // Traverse to the last node
        while(temp->next != "")
            temp = temp->next;

        temp->next = newNode; // Link address part

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void deleteFirstNode()
{
	
    struct node *toDelete;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);

        /* Clears the memory occupied by first node*/
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
void deleteMiddleNode()
{
    int i,position;
    printf("Enter the position to delete at middle: " );
    scanf("%d", &position);
    struct node *toDelete, *prevNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;

            /* Delete nth node */
            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}
void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        /* Traverse to the last node of the list */
        while(toDelete->next != "")
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            /* Disconnect link of second last node with last node */
            secondLastNode->next = NULL;
        }

        /* Delete the last node */
        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}
int search()
{
    int index,key;
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    struct node *curNode;

    index = 0;
    curNode = head;

    // Iterate till last element until key is not found
    while (curNode != NULL && curNode->data != key)
    {
        index++;
        curNode = curNode->next;
    }
if(curNode = NULL)
index=-1;
if (index >= 0)
        printf("%d found in the list at position %d\n", key, index + 1);
    else
        printf("%d not found in the list.\n", key);
    

  
}
