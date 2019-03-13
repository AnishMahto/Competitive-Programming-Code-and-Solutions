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
    int val, pri = rand()%1000000, sz = 1, idx;
    treap * l = NULL, * r = NULL;
};

treap * root = NULL;
int delIdx;

void rr (treap *node) {
    treap * nodeLR = node->l->r;
    node->l->r = node;
    node->l = nodeLR;
}

void rl (treap *node) {
    treap * nodeRL = node->r->l;
    node->r->l = node;
    node->r = nodeRL;
}

treap * find (treap *node, int fVal) {
    if (node == NULL) {
        return NULL;
    }
    if (node->val == fVal) {
        return node;
    } else if (node->l != NULL && node->val > fVal) {
        return find (node->l, fVal);
    } else if (node->r != NULL && node->val < fVal) {
        return find (node->r, fVal);
    }
    return NULL;
}

treap * insert (treap *node, int fVal, int IDX) {
    if (root == NULL) {
        root = new treap;
        root->val = fVal;
        root->idx = IDX;
        return root;
    }
    treap *child;
    if (node->val == fVal) {
        node->sz++;
        return node;
    } else if (fVal < node->val) {
        if (node->l == NULL) {
            node->l = new treap;
            node->l->val = fVal;
            node->l->idx = IDX;
            child = node->l;
        } else {
            child = insert (node->l, fVal, IDX);
        }
        node->l = child;
        if (child->pri < node->pri) {
            rr (node);
            return child;
        }
        return node;
    } else if (fVal > node->val) {
        if (node->r == NULL) {
            node->r = new treap;
            node->r->val = fVal;
            node->r->idx = IDX;
            child = node->r;
        } else {
            child = insert (node->r, fVal, IDX);
        }
        node->r = child;
        if (child->pri < node->pri) {
            rl (node);
            return child;
        }
        return node;
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
        delIdx = node->idx;
        if (node->sz > 1) {
            node->sz--;
            return node;
        } else {
            if (node->l == NULL) {
                curNode = node->r;
                delete node;
            } else if (node->r == NULL) {
                curNode = node->l;
                delete node;
            } else {
                if (node->l->pri < node->r->pri) {
                    curNode = node->l;
                    rr (node);
                    curNode->r = del (curNode->r, dVal);
                } else {
                    curNode = node->r;
                    rl (node);
                    curNode->l = del (curNode->l, dVal);
                }
            }
        }
    }
    return curNode;
}

void inOrder (treap *node) {
    if (node->l != NULL) {
        inOrder (node->l);
    }
    REP (x, node->sz) {
        cout << node->val << endl;
    }
    if (node->r != NULL) {
        inOrder (node->r);
    }
}

void dfs (treap *node, int par) {
    cout << node->val << " " << par << "!" << endl;
    if (node->l != NULL) {
        dfs (node->l, node->val);
    }
    if (node->r != NULL) {
        dfs (node->r, node->val);
    }
}

bool rem[2000001] = {0};

int main () {
    deque < pii > tmp;
    int n, cur;
    si (n);
    REP (x, n) {
        char cmd;
        scanf (" %c", &cmd);
        si (cur);
        if (cmd=='F') {
            root = insert (root, cur, x);
            tmp.push_front(mp (cur, x));
        } else if (cmd == 'E') {
            root = insert (root, cur, x);
            tmp.pb (mp(cur, x));
        } else {
            root = del (root, cur);
            rem[delIdx] = true;
        }
    }
    vi ans;
    REP (x, (int)tmp.size()) {
        if (!rem[tmp[x].second]) {
            cout << tmp[x].first << "\n";
        }
    }
}
