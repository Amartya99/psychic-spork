/* Name Aditya Panda
Roll Cs1723
Assignmet 4
Prog  1*/

/********************* The prtogram is done in o(logn+l) complexity*************************/


#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

void showstack(stack <long long int> gq)
{
    stack <long long int> g = gq;
    while (!g.empty())
    {
        cout << ' ' << g.top();
        g.pop();
    }
    cout << '\n';
}
 stack <long long int> gquiz;
 
struct node{
    long long int data;
    struct node* left;
    struct node* right;};

long long int max(long long int inorder[],long long  int strt,long long  int end);
 int p=0;
/*function to allocate memory for a node */
struct node* newNode(long long int data);
 
struct node* buildTree (long long int inorder[],long long int start,long long int end)
{
    if (start > end)
        return NULL;
 
    /* Find index of the maximum element from Binary Tree */
    long long int i = max (inorder, start, end);
 
    /* Pick the maximum value and make it root */
    struct node *root = newNode(inorder[i]);
 
    /* If this is the only element in inorder[start..end],
       then return it */
    if (start == end)
        return root;
 
    /* Using index in Inorder traversal, construct left and
       right subtress */
    root->left  = buildTree (inorder, start, i-1);
    root->right = buildTree (inorder, i+1, end);
 
    return root;
}
long long int max (long long int arr[],long long  int strt,long long int end)
{
    long long int i, max = arr[strt], maxind = strt;
    for(i = strt+1; i <= end; i++)
    {
        if(arr[i] > max){
            max = arr[i];
            maxind = i;}}
    return maxind;
}
struct node* newNode (long long int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
/*void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}*/
long long int getCount(node *root, long long int low,long long int high)
{
    // Base case
    if (!root) return 0;
 
    // Special Optional case for improving efficiency
    if (root->data == high && root->data == low){
    //printf("%lld ",root->data);
     gquiz.push(root->data);
    //fprintf(fp,"%lld ",root->data);
    //alloc[p]=root->data;
   // p++;
   // alloc=(long long int *)realloc(alloc, sizeof(long long int));
        return 1;}
    if (root->data <= high && root->data >= low){
   // alloc[p]=root->data;
     //fprintf(fp,"%lld ",root->data);
    //p++;
    //printf("%lld ",root->data);
    gquiz.push(root->data);
     //alloc=(long long int *)realloc(alloc, sizeof(long long int));
         return 1 + getCount(root->left, low, high) +
                    getCount(root->right, low, high);}
    else if (root->data > high)
         return getCount(root->left,low, high);
     // Else recur for left child
    else if (root->data<low)
   	return getCount(root->right,low, high);
   	else
   	 return 0;
}
 
int main(int argc, char **argv){
//FILE *fp;
//fp=fopen("temp.txt","w");	
long long int i,x;
	if(argc<2){
		printf("Insufficient argument");
		return 0;
	}
	//alloc=(int*)malloc(sizeof(int));
    long long int *arr;
    long long int n =(argc-1);
    arr=(long long int*)malloc(n*sizeof(long long int));
    //alloc=(long long int*)malloc(sizeof(long long int));;

    for(i=0;i<n;i++)
    arr[i]=atoi(argv[i+1]);
    sort(arr, arr+n);
    //cout << "\nArray after sorting using "
    //     "default sort is : \n";
    //for (int i = 0; i < n; ++i)
    //    cout << arr[i] << " ";
        struct node *root = buildTree(arr, 0, n - 1);
 
    /* Let us test the built tree by printing Insorder traversal */
    //printf("\n Inorder traversal of the constructed tree is \n");
    //printInorder(root);
    long long int l, h;// = 45;//= 5;
    scanf("%lld %lld",&l,&h);
    if(h<l)
    {
    	cout<<"enter proper hgher and lower limits"<<endl;
    	return 0;
	}
    x=getCount(root, l, h);
    //cout << "Count of nodes between [" << l << ", " << h
        // << "] is " << getCount(root, l, h,p);
        
    //sort(alloc,alloc+sizeof(alloc));
    //for (int i = 0; i <sizeof(alloc); ++i)
      //cout << alloc[i] << " ";
      // cout << "The stack gquiz is : \n \n";
      if(x!=0){
	  showstack(gquiz);
	  }
	  if(x==0){
	  printf(" ");
	  }
    
      //free(alloc);
      free(arr);
      //fclose(fp);
    return 0;
}
