#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// Node of a linked list
class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

// Linked list
class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

// Print linked list
void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

// Free singly linked list
void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}


/*
 * Problem : https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem
 *
 * Complete the 'reversePrint' function below.
 *
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.

 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void reversePrint(SinglyLinkedListNode* llist) {
    if (llist == NULL)
        return;
    reversePrint(llist->next);
    cout << llist->data << '\n';
}



/*
 * Problem : https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem
 *
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 * 
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* curr_node = llist;
    int pos = 0;
    while(pos < position-1)
    {
        curr_node = curr_node->next;
        pos++;
    }
    newNode->next = curr_node->next;
    curr_node->next = newNode;
    return llist;
}




/*
 * Problem : https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem
 *
 * Complete the insertNodeAtHead function below.
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    node->next = llist;
    return node;
}

/*
 * Problem: https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem
 *
 * Complete the insertNodeAtTail function below.
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if(head == NULL)
    {
        head = new SinglyLinkedListNode(data);
    }
    else {
        SinglyLinkedListNode* tail = head;
        while(tail->next != NULL)
            tail = tail->next;
        tail->next = new SinglyLinkedListNode(data);
    }
    return head;
}


/*
 * Problem: https://www.hackerrank.com/challenges/sparse-arrays/problem
 *
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY strings
 *  2. STRING_ARRAY queries
 */
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<int> Occurences;
    
    /*
        Compare each query with the strings.
        Time complexity O(n^2) but maybe I'll try to optimize after I'm done.
    */
    for(int i=0;i<queries.size();i++)
    {
        int occurences = 0;
        for(int j=0;j<strings.size();j++)
        {
            if(strings[j] == queries[i])
                occurences++;
        }
        Occurences.push_back(occurences);
    }
    return Occurences;
}

/*
 * Problem : https://www.hackerrank.com/challenges/between-two-sets/problem
 *
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int getTotalX(vector<int> a, vector<int> b) {
    int numbers = 0;
    
    //Code for arrays with sizes > 1
    for(int i=a[a.size()-1];i<=b[b.size()-1];i++)
    {
        bool check = true;
        for(int j=0;j<a.size();j++)
        {
            if(i%a[j] != 0)
                check = false;
        }
        for(int j=0;j<b.size();j++)
        {
            if(b[j]%i != 0)
                check = false;
        }
        if(check == true)
            numbers++;
    }
    return numbers;
}

/*
 * Problem : https://www.hackerrank.com/challenges/dynamic-array/problem
 *
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */
vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> arr;
    vector<int> answers;
    int lastAnswer = 0;
    
    for(int i=0;i<n;i++)
    {
        arr.push_back(vector<int>());
    }
    for(int i=0;i<queries.size();i++)
    {
        int idx = ((queries[i][1] ^ lastAnswer)%n);
        int x = queries[i][1], y = queries[i][2];
        
        if(queries[i][0] == 1)
        {
            arr[idx].push_back(y);
        }
        else if(queries[i][0] == 2)
        {
            int idx = ((queries[i][1]^lastAnswer)%n);
            lastAnswer = arr[idx][y%arr[idx].size()];
            answers.push_back(lastAnswer);
        }
    }
    return answers;
}

/*
 * Problem : https://www.hackerrank.com/challenges/2d-array/problem
 *
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int hourglassSum(vector<vector<int>> arr) {
    int maxSum = INT_MIN;
    
    
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            int sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            maxSum = max(sum,maxSum);
        }

    return maxSum;
}

/*
 * Problem : https://www.hackerrank.com/challenges/array-left-rotation/problem
 *
 * Complete the 'rotateLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

vector<int> rotateLeft(int d, vector<int> arr) {
    for(int i=0;i<d;i++)
    {
        arr.push_back(arr[0]);
        arr.erase(arr.begin());
    }
    return arr;
}


/*
 * Problem: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
 *
 * Complete the 'jumpingOnClouds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY c as parameter.
 */

int jumpingOnClouds(vector<int> c) {
    int jumps = 0;
    for(int i=0;i<c.size();i++)
    {
        if(i<=c.size()-2)
        {   jumps++;
            if(c[i+2] == 0)
            {
                i++;
                continue;
            }
            else if(c[i+2] == 1)
            {
                continue;
            }
        }
    }
    return jumps;
}

/*
 * Problem: https://www.hackerrank.com/challenges/repeated-string/problem
 *
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
    long occurences = 0, rep = n/s.size(), rem = n%s.size();
    if(s == "a")
        return n;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == 'a')
            occurences++;
    }
    occurences *= rep;
    for(int i=0;i<rem;i++)
    {
        if(s[i] == 'a')
            occurences++;
    }
    return occurences;
}


/*
 * Problem: https://www.hackerrank.com/challenges/funny-string/problem
 *
 * Complete the 'funnyString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string funnyString(string s){
    string s_copy = s;
    reverse(s_copy.begin(),s_copy.end());
    for(int i=0;i<s.length()-1;i++)
    {
        if(abs(s[i]-s[i+1]) != abs(s_copy[i]-s_copy[i+1]))
            return "Not Funny";
        else continue;
    }
    return "Funny";
}

/*
 * Problem: https://www.hackerrank.com/challenges/strange-advertising/problem
 *
 * Complete the 'viralAdvertising' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int viralAdvertising(int n) {
    int shared = 5;
    int liked = shared/2;
    int cumulative = liked;
    for(int i=1;i<n;i++)
    {
        shared = liked*3;
        liked = shared/2;
        cumulative += liked;
    }
    return cumulative;
}

/*
 * Problem: https://www.hackerrank.com/challenges/utopian-tree/problem
 *
 * Complete the 'utopianTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int utopianTree(int n) {
    int H=1;
    for(int i=0;i<n;i++)
        if(i>0 && i%2!=0)
            H++;
        else H*=2;
            
    return H;
}

/*
 * Problem: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
 * 
 * Complete the catAndMouse function below.
 */
string catAndMouse(int x, int y, int z) {
    if(abs(z-y) < abs(z-x))
        return "Cat B";
    else if(abs(z-y) > abs(z-x))
        return "Cat A";
    else if(abs(z-y) == abs(z-x))
        return "Mouse C";
    return " ";
}

/* 
 * Problem: https://www.hackerrank.com/challenges/angry-professor/problem
 *
 * Complete the angryProfessor function below.
 */
string angryProfessor(int k, vector<int> a) {
    int arrivedStud=0;
    for(int i=0;i<a.size();i++)
        {
            if(a[i] <= 0)
            arrivedStud++;
        }
    if(arrivedStud >= k)
    return "NO";
    else return "YES";
}

/*
 * Problem: https://www.hackerrank.com/challenges/kangaroo/problem
 * 
 * Complete the kangaroo function below. 
*/
string kangaroo(int x1, int v1, int x2, int v2) {
    string yn = "NO";
    bool can = (v2<v1);
    if(can == true){
        bool intersect = (x1-x2)%(v1-v2)==0;
        if(intersect == true)
            yn = "YES";
    }
    return yn;
}

/*
 * Problem: https://www.hackerrank.com/challenges/counting-valleys/problem
 *
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */
int countingValleys(int steps, string path) {
    int a=0,c=0;
    bool b = false;
    for(int i=0;i<path.length();i++)
    {
        if(path[i] == 'U')
            c+=1;
        else if(path[i] == 'D')
            c-=1;
        if(c<0)
            b = true;
        if(c==0 && b==true)
        {
            a++;
            b=false;
        }
    }
    return a;
}   

/*
 * Problem: https://www.hackerrank.com/challenges/bon-appetit/problem
 *
 *Complete the bonAppetit function below.
*/

void bonAppetit(vector<int> bill, int k, int b) {
    int bActual=0;
    for(int i=0;i<bill.size();i++)
        if(i!=k)
            bActual += bill[i];
    bActual /= 2;
    if(b - bActual == 0)
        cout << "Bon Appetit";
    else cout << b-bActual;
}