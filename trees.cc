// 1 indexed updates and query
struct fenwick {
    int n;
    vector <int> tree;
    void BIT(int SZ){tree.resize(SZ+1);n = SZ;
    }
    // a[x] += delta
    void update(int x, int delta) {
        for(; x <= n; x += x & -x) tree[x] += delta;
    }
    // sum from a[1] to a[x]
    int query(int x) {int sum = 0;
        for(; x > 0; x -= x & -x) sum += tree[x];
        return sum;
    }
};
class fenwick
{
private:
    vi fw;
    int n;
    fenwick(vi arr,int n)
    {
        fw.resize(n+1,0);
        for(int i=0;i<n;i++)
            update(i,arr[i]);
    }
    void update(int i,int newval)
    {
        i++;
        while(i<=n)
        {
            fw[i]+=newval;
            i += i & (-i);
        }
    }
    ll sum(int i)
    {
        ll res=0;
        i++;
        while(i>0)
        {
            res+=fw[i];
            i-=i&(-i);
        }
        return res;
    }
};

class segmentree { 
public:
    vector<int> tree;
    int sz;
    segmentree(int n)
    {
        sz=n;
        tree.clear();
        tree.resize(4*n + 5);
    }
    int buildutil(vi &curr,int l,int r, int ind)
    {
        // deb2(l,r);
        if(l>r)
            return 0;
        if(l==r)
        {
            return tree[ind]=curr[l];
        }
        int mid=l+(r-l)/2;
        int left=buildutil(curr,l,mid,ind*2);
        int right=buildutil(curr,mid+1,r,ind*2 + 1);
        return tree[ind]=max(left,right);
    }
    void build(vi curr)
    {
        buildutil(curr,0,sz-1,1);
    }

    int queryutil(int l,int r,int i,int j,int curr)// l,r are treeind, i,j are query ind
    {
        // deb2(l,r);
        if(l>r or i>j)
            return 0;
        if(i==l and j==r)
        {
            return tree[curr];
        }
        int mid=l+(r-l)/2;
        return max( queryutil(l,mid,i,min(j,mid),curr*2 ) , 
            queryutil( mid+1,r,max(i,mid+1),j,curr*2 + 1 ) );

    }   

    int query(int l,int r)
    {
        return queryutil(0,sz-1,l,r,1);
    }

    void updateutil(int curr,int l,int r,int pos,int newval)
    {
        if(l==r)
            tree[curr]=newval;
        else
        {
            int mid=l+(r-l)/2;
            if(pos<=mid)
                updateutil(curr*2,l,mid,pos,newval);
            else 
                updateutil(curr*2 +1,mid+1,r,pos,newval);
            tree[curr]=max(tree[curr*2],tree[curr*2 + 1]);
        }
    }
    void update(int pos,int newval)
    {
        updateutil(1,0,sz-1,pos,newval);
    }

};


class trie{
public:
    bool endword;
    trie *child[256];
    trie()
    {
        this->endword=false;
        for(int i=0;i<256;i++)
            this->child[i]=NULL;
    }
    void insert(string);
    bool search(string );
    bool havechild(trie *);
};

void trie::insert(string str)
{
    trie* temp=this;
    for(int i=0;i<str.length();i++)
    {
        int pos=str[i];
        if(temp->child[pos]==NULL)
            temp->child[pos]=new trie();
        temp=temp->child[pos];
    }
    temp->endword=true;
}   

bool trie::search(string str)
{
    trie* temp=this;
    for(int i=0;i<str.length();i++)
    {
        int pos=str[i];
        if(temp->child[pos]==NULL)
            return false;
        temp=temp->child[pos];
    }
    return temp->endword;
}

bool trie::havechild(trie *temp)
{
    for(int i=0;i<256;i++)
    {
        if(temp->child[i]!=NULL)
            return true;
    }
    return false;
}

//tree class
struct Node { 
  int key; 
  Node *left, *right; 
  Node (int x) 
  { 
     key = x; 
     left = right = NULL; 
  } 
}; 
//insert function
void insert(Node* temp, int key) 
{ 
    queue<Node*> q; 
    q.push(temp); 
    while (!q.empty()) { 
        Node* temp = q.front(); 
        q.pop(); 
  
        if (!temp->left) { 
            temp->left = new Node(key); 
            break; 
        } else
            q.push(temp->left); 
  
        if (!temp->right) { 
            temp->right = new Node(key); 
            break; 
        } else
            q.push(temp->right); 
    } 
}

//delete node
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
}
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->key = temp->key; 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
}

//traversal
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
    printPostorder(node->left); 
    printPostorder(node->right); ode 
    cout << node->data << " "; 
} 
void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
    cout << node->data << " "; 
    printPreorder(node->left);  
    printPreorder(node->right); 
}  
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    cout << node->data << " "; 
    printInorder(node->right); 
}

//find height
int maxDepth(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
} 

//leafcount
unsigned int getLeafCount(struct node* node)  
{  
    if(node == NULL)      
        return 0;  
    if(node->left == NULL && node->right == NULL)  
        return 1;          
    else
        return getLeafCount(node->left)+  
            getLeafCount(node->right);  
} 

//