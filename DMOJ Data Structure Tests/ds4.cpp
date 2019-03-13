#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <deque>
#define SET(x,y) x |= (1 << y)
#define CLEAR(x,y) x &= ~(1<< y)
#define READ(x,y) ((0u == (x & (1<<y)))?0u:1u)
#define TOGGLE(x,y) (x ^= (1<<y))
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pF first
#define pS second
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORI(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define CL(a,b) memset(a,b,sizeof(a))
#define sqr(x) ((x)*(x))
#define intLIMIT numeric_limits<int>
#define longLIMIT numeric_limits<long long>
#define dbl(x) (double)(x)
#define vi vector <int>
#define vii vector < pair <int, int> >
#define vll vector <long long>
#define fastCin cin.sync_with_stdio(0);cin.tie(0)
#define scanUnsigned(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define printArr(a,l) cout<<#a<<": ";for(int i=0;i<(l);i++){cout<<a[i]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i=0;i<(r);i++){for(int j=0;j<(c);j++){cout<<a[i][j]<<" ";}cout<<endl;}
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

struct treap {
    int val, pri = rand()%1000000, sz = 1, L = 0, R = 0, tot = 1;
    treap * l = NULL, * r = NULL;
};

treap * root;
int greaterThan = 0;

void rr (treap *node) {
    treap * nodeLR = node->l->r;
    node->l->r = node;
    node->l = nodeLR;
}

int getSize (treap *node) {
    if (node==NULL) {
        return 0;
    } else {
        return node->sz + node->L + node->R;
    }
}

void updateSize (treap * node) {
    if (node==NULL) {
        return;
    } else {
        node->L = getSize (node->l);
        node->R = getSize (node->r);
        node->tot = node->sz + node->L + node->R;
    }
}

void rl (treap *node) {
    treap * nodeRL = node->r->l;
    node->r->l = node;
    node->r = nodeRL;
}

treap * find (treap *node, int fVal) {
    if (node != NULL) {
        if (node->val == fVal) {
            greaterThan += getSize (node->l) + 1;
            return node;
        } else if (node->l != NULL && node->val > fVal) {
            return find (node->l, fVal);
        } else if (node->r != NULL && node->val < fVal) {
            greaterThan += node->sz + getSize (node->l);
            return find (node->r, fVal);
        }
    }
    greaterThan = -1;
    return NULL;
}

int findSmallest (treap *node, int curRank, int fRank) {
    if (getSize (node->l) + curRank < fRank && getSize (node->l) + curRank + node->sz >= fRank) {
        return node->val;
    } else if (getSize (node->l) + curRank >= fRank) {
        return findSmallest (node->l, curRank, fRank);
    } else {
        return findSmallest (node->r, curRank + getSize(node->l) + node->sz, fRank);
    }
}

treap * insert (treap *node, int fVal) {
    if (root == NULL) {
        root = new treap;
        root->val = fVal;
        return root;
    }
    treap *child;
    if (node->val == fVal) {
        node->sz++;
        updateSize (node);
        return node;
    } else if (fVal < node->val) {
        if (node->l == NULL) {
            node->l = new treap;
            node->l->val = fVal;
            child = node->l;
        } else {
            child = insert (node->l, fVal);
        }
        node->l = child;
        if (child->pri < node->pri) {
            rr (node);
            updateSize (node);
            updateSize (child);
            return child;
        }
        updateSize (node);
        return node;
    } else if (fVal > node->val) {
        if (node->r == NULL) {
            node->r = new treap;
            node->r->val = fVal;
            child = node->r;
        } else {
            child = insert (node->r, fVal);
        }
        node->r = child;
        if (child->pri < node->pri) {
            rl (node);
            updateSize (node);
            updateSize (child);
            return child;
        }
        updateSize (node);
        return node;
    }
}

void inOrder (treap *node) {
    if (node == NULL) {
        return;
    }
    if (node->l != NULL) {
        inOrder (node->l);
    }
    REP (x, node->sz) {
        printf ("%d ", node->val);
        //cout << node->val << " " << getSize (node) << endl;
    }
    if (node->r != NULL) {
        inOrder (node->r);
    }
}

void dfs (treap *node, int par) {
    cout << node->val << " " << par << ": " << getSize (node) << "!" << endl;
    if (node->l != NULL) {
        dfs (node->l, node->val);
    }
    if (node->r != NULL) {
        dfs (node->r, node->val);
    }
}

treap * del (treap * node, int dVal) {
    treap * curNode = node;
    if (node == NULL) {
        return NULL;
    }
    if (node->val < dVal) {
        node->r = del (node->r, dVal);
    } else if (node->val > dVal) {
        node->l = del (node->l, dVal);
    } else {
        if (node->sz > 1) {
            node->sz--;
            updateSize (node);
            return node;
        } else {
            if (node->l == NULL) {
                curNode = node->r;
                updateSize (curNode);
                delete node;
            } else if (node->r == NULL) {
                curNode = node->l;
                updateSize (curNode);
                delete node;
            } else {
                if (node->l->pri < node->r->pri) {
                    curNode = node->l;
                    rr (node);
                    curNode->r = del (curNode->r, dVal);
                    updateSize (curNode);
                } else {
                    curNode = node->r;
                    rl (node);
                    curNode->l = del (curNode->l, dVal);
                    updateSize (curNode);
                }
            }
        }
    }
    updateSize (curNode);
    return curNode;
}

int main () {
    int n, m, cur, lastAns = 0;
    char cmd;
    si (n); si (m);
    REP(x, n) {
        si (cur);
        root = insert (root, cur);
    }
    REP (x, m) {
        scanf (" %c", &cmd); si (cur);
        cur ^= lastAns;
        if (cmd== 'L') {
            greaterThan = 0;
            find (root, cur);
            lastAns = greaterThan;
            printf ("%d\n", lastAns);
        } else if (cmd == 'I') {
            root = insert (root, cur);
        } else if (cmd == 'R') {
            root = del (root, cur);
        } else {
            lastAns = findSmallest (root, 0, cur);
            printf ("%d\n", lastAns);
        }
    }
    inOrder (root);
}
