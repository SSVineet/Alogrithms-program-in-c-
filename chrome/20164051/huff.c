// C program for Huffman Coding   ... BUGGY HAI ABHI YE THODA SA...INPUT ME PROBLEM HAI
#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 100
struct MinHeapNode      // defintion for a single node of the huffman tree  
{ 
    char data;
    int freq;
    struct MinHeapNode *left, *right;
};
struct MinHeap     // it will contain the nodes of the huffman tree 
{
    int size;
    int capacity;
    struct MinHeapNode ** array;   // array of pointers for MinHeapNode
};
struct MinHeapNode * newNode(char data, int freq)   // allocate memory for a node of huffman tree 
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
struct MinHeap * createMinHeap(int capacity)    // create the min. heap here ......
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;    // make current size of heap as 0
    minHeap->capacity = capacity;
    minHeap->array= (struct MinHeapNode**)malloc(minHeap->capacity*sizeof(struct MinHeapNode*));
    
    return minHeap;
}
void swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
// function for creating the minimum heapify 
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
 
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
 
    if (smallest != idx) 
    {
        swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// check size of heap if it is 1 or not 
int isSizeOne(struct MinHeap* minHeap)   
{ 
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0]  = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// insertion in the min. heap 
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) 
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}


int isLeaf(struct MinHeapNode* root)    // check if node is leaf or not 
{
    return !(root->left) && !(root->right);
}
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
 
    return minHeap;
}
// THIS IS THE MAIN FUNCTION TO  BUILD THE HUFFMAN TREE 
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)   // for building Huffman tree
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    // Iterate while size of heap doesn't become 1
    while (!isSizeOne(minHeap)) 
   {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
 
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
    if (root->left) 
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) 
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
   // if leaf found print that character
    if (isLeaf(root)) 
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}
int main()
{ 
   // char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
  //  int freq[] = { 5, 9, 12, 13, 16, 45 };
  	char arr[100];
  	int freq[100],n;
  	printf("\n Enter the number of the characters in the huffman code :");
  	scanf("%d", &n);
  	printf("\n Enter a character and its corrosponding frquency :");
  	for(int i=0;i<n;i++) 
  	{
  		scanf("%c%*c",&arr[i]);
  		scanf("%d%*c",&freq[i]);
  	}
   // int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, n);
    return 0;
}
