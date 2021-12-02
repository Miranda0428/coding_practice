#include <iostream>
#include <malloc.h>
#include <vector>
#include <string>
using namespace std;

#pragma warning(disable:4996)

typedef struct NODE {
    bool check;
    bool end;
    NODE* next[27];
}node;

int T, K, cnt, flag;
char str[402];
int len;
string answer;

node* makenode(){
    node* tmp = (node*)malloc(sizeof(node));
    for (int i = 0; i < 27; ++i)
        tmp->next[i] = 0;
    tmp->check = false;
    tmp->end = 0;
    return tmp;  
}

void insert(node* node, int st){
    if (st == len) {
        node->end = 1;
        return;
    }


    if (!node->next[str[st] - 'a']) {
        node->next[str[st] - 'a'] = makenode();
        insert(node->next[str[st] - 'a'], st + 1);
    }       
}

void solve(node* node){

    if (node->end) {
        answer.clear();
        //return;
    }
    if (cnt == K) {
        flag = 1;
        return;
    }
 
    for (int i = 0; i < 27; i++) {
        if ((node->next[i]!=0)&&(node->check==false)) {
            ++cnt;
            node->check = 1;
            answer += (i + 'a');
            solve(node->next[i]);
            if (flag) break;
        }
    }
}

void delnode(node* node){
    for (int i = 0; i < 27; ++i)
        if(node->next[i]) delnode(node->next[i]);
    node->check = false;
    free(node);
}

int main(void)
{
    freopen("test_input.txt", "r", stdin);
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        
        cnt = flag = 0;
        cin >> K >> str;
        len = strlen(str);
        node* root = makenode();
        for (int i = 0; i < len; i++)
            insert(root, i);
        solve(root);
        cout << "#" << tc << " " << answer << endl;
        delnode(root);
    }
    return 0;
}
