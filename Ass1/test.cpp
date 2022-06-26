// #include <iostream>
// #include <fstream>
// #include <string>
// #include <stack>
// using namespace std;
// //./main testcase/test000.txt1
// int recur(int n){
//     if (n == 0) return 1;
//     if (n == 1) return 4;
//     cout << "in recur: " << 3 * recur(n-1) + 4*recur(n-2) << endl;
//     return 3 * recur(n-1) + 4*recur(n-2);
    
// }
// #define STRING(variable) #variable
// int main(){
//     int n = 5;
//     //cout << recur(5) << endl;

//     // float a = 3.1415926;
//     // string s ="";
//     // s += to_string(a);
//     // cout << s;

//     // float a = 6;
//     // string num_str(STRING(a));
//     // num_str.empty() ? cout << "empty\n" :
//     //                     cout << num_str << endl;

//     // float a[100];
//     // int b = 3;
//     // a[0] = b;
//     // a[1] = 4;
//     // int sum;
//     // sum = a[0] + a[1];
//     // cout << sum << endl;    

//     stack <int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     //s.pop();
//     s.push(4);
//     cout << s.top();

//     for (int i = 0; i < s.size(); i++){
//         cout << s.top() << " ";
//         s.pop();
//     }
    



//     // string array[256] = {"anc", "abc", "cba"};
//     // string s = "iconst 3";
//     // string s1 = "";
//     // string s2 = "";
//     // for (int i = 0; i < s.length(); i++){
//     //     if (s[i] == ' '){
//     //         s1 += s[i + 1]; //s1: parameter
//     //         break;
//     //     }
//     //     else{   
//     //         s2 += s[i]; //s2: lenh ko co parameter
//     //     }
//     // }
//     // int n = sizeof array/sizeof array[0];

//     // cout << array[2];
    
//     return 0;
// }



/* C++ program to construct tree using
inorder and preorder traversals */
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

// /* A binary tree node has data, pointer to left child
// and a pointer to right child */
// class node
// {
// 	public:
// 	char data;
// 	node* left;
// 	node* right;
// };

// /* Prototypes for utility functions */
// int search(char arr[], int strt, int end, char value);
// node* newNode(char data);

// /* Recursive function to construct binary
// of size len from Inorder traversal in[]
// and Preorder traversal pre[]. Initial values
// of inStrt and inEnd should be 0 and len -1.
// The function doesn't do any error checking
// for cases where inorder and preorder do not
// form a tree */
// node* buildTree(char in[], char pre[], int inStrt, int inEnd)
// {
// 	static int preIndex = 0;

// 	if (inStrt > inEnd)
// 		return NULL;

// 	/* Pick current node from Preorder
// 	traversal using preIndex
// 	and increment preIndex */
// 	node* tNode = newNode(pre[preIndex++]);

// 	/* If this node has no children then return */
// 	if (inStrt == inEnd)
// 		return tNode;

// 	/* Else find the index of this node in Inorder traversal */
// 	int inIndex = search(in, inStrt, inEnd, tNode->data);

// 	/* Using index in Inorder traversal, construct left and
// 	right subtress */
// 	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
// 	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

// 	return tNode;
// }

// /* UTILITY FUNCTIONS */
// /* Function to find index of value in arr[start...end]
// The function assumes that value is present in in[] */
// int search(char arr[], int strt, int end, char value)
// {
// 	int i;
// 	for (i = strt; i <= end; i++)
// 	{
// 		if (arr[i] == value)
// 			return i;
// 	}
// }

// /* Helper function that allocates a new node with the
// given data and NULL left and right pointers. */
// node* newNode(char data)
// {
// 	node* Node = new node();
// 	Node->data = data;
// 	Node->left = NULL;
// 	Node->right = NULL;

// 	return (Node);
// }

// /* This function is here just to test buildTree() */
// void printInorder(node* node)
// {
// 	if (node == NULL)
// 		return;

// 	/* first recur on left child */
// 	printInorder(node->left);

// 	/* then print the data of node */
// 	cout<<node->data<<" ";

// 	/* now recur on right child */
// 	printInorder(node->right);
// }

// /* Driver code */


#include <stack>
#include <string>

int main()
{
	// int a = 5;
	// float b = a;
	// cout << b << endl;

	float a = -2.5;
	int b = a;
	cout << b << endl;

	std::string str1 ("green apple");
  std::string str2 ("red apple");

  if (str1.compare(str2) == 0)
    std::cout << str1 << " is not " << str2 << '\n';
else cout << "done";

	//cout << stack_demo1(input); cout << endl;
	// char in[] = { '9', '11', '15', '17', '29', '19' };
	// char pre[] = { '11', '17', '15', '9', '29', '19' };
	// int len = sizeof(in) / sizeof(in[0]);
	// node* root = buildTree(in, pre, 0, len - 1);

	// /* Let us test the built tree by
	// printing Inorder traversal */
	// cout << "Inorder traversal of the constructed tree is \n";
	// printInorder(root);
}

// This is code is contributed by rathbhupendra
