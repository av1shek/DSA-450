#include<iostream>
using namespace std;
typedef struct Node  *lptr;

struct Node
{
    int data;
    Node *next;
    Node(int x){
    data = x;
    next = NULL;
    }
    Node(){next == NULL; };
};


void insert(lptr &P, int x)
{
    lptr temp = new Node;
    temp->data = x;

    if(P==NULL)
        P = temp;
    else
    {
        lptr T = P;
        while(T->next != NULL)
            T = T->next;
        T->next = temp;
    }

    return;
}

void takeInput(lptr &L)
{
    int n;
    cin>>n;
    while(n!=-1)
    {
        insert(L, n);
        cin>>n;
    }
    return;
}

void print(Node *l, string msg = "")
{
    cout<<"List( "<< msg <<" ) => ";
    while(l)
    {
        cout << l->data ;
        l = l->next;
    }
    cout << endl;
}

Node* reverse(Node *l)
{
    if(l==NULL) return l;
    Node* curr = l, *prev = NULL;
    while(curr)
    {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* add(Node* l1, Node* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    Node* head = new Node(0);
    Node* curr = head;
    int carry = 0;


    while(l1 || l2){
        int t1 = l1 ? l1->data : 0;
        int t2 = l2 ? l2->data : 0;

        int sum = t1 + t2 + carry;
        curr->next = new Node(sum%10);
        curr = curr->next;
        carry = sum/10;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    if(carry)
        curr->next = new Node(carry);

    return (head->next);
}

Node* mulitplySingle(Node* l, int x)
{
    if(l==NULL) return l;

    Node* head = new Node(0);
    Node* curr = head;
    int carry = 0;
    while(l){
        int num = l->data * x + carry;
        curr->next = new Node(num%10);
        curr = curr->next;
        l = l->next;
        carry = num/10;
    }
    if(carry)
        curr->next = new Node(carry);

    return (head->next);
}

Node* multiply(Node*l1, Node* l2)
{
    if(l1 == NULL || l2 ==NULL) return NULL;

    l1 = reverse(l1);
    l2 = reverse(l2);

    Node* headRef1 = l1;
    Node* headRef2 = l2;

    Node* ans = new Node(0);
    Node* currAns = ans;
    int cnt = 0;
    while(l1)
    {
        Node* temp = mulitplySingle(l2, l1->data);
        currAns->next = add(currAns->next, temp);

        currAns = currAns->next;
        l1 = l1->next;
    }
    return reverse(ans->next);
}
int main()
{
    Node *L1 = NULL, *L2 = NULL, *L3 = NULL;
    takeInput(L1);
    takeInput(L2);

    print(L1, "L1");
    print(L1, "L2");
    L3 = multiply(L1, L2);
    print(L3, "Mul = ");
    return 0;
}
