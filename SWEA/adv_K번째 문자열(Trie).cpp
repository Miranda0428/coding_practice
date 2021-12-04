/*트라이에 대해 잘못 생각하고 있었다. root가 있고 그 밑으로 분기없이 한줄로 죽 이어지는 것이 아니고
부분 문자열중 다른 문자가 나오면 분기가 일어나는 트리의 모양이다.
구글에서 '문자열 트라이'를 검색해보면 문자열에서 문자가 달라지는 부분부터 분기가 일어남을 알 수 있다.
나는 트라이를 문어같이 문어대가리가 root 이고 문어다리들이 분기없이 부분 문자열을 나타낸다고 생각했다.
그래서 insert 부분과 solve 부분을 잘못구현했다.*/

#include <iostream>
#include <malloc.h>
#include <vector>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

typedef struct NODE {
    bool check;
    //bool end;
    NODE* next[27];
}node;

int T, K, cnt, flag;
char str[402];
int len;
string answer;

node* makenode() {
    node* tmp = (node*)malloc(sizeof(node));
    for (int i = 0; i < 27; ++i)
        tmp->next[i] = 0;
    tmp->check = false;
    //tmp->end = 0;
    return tmp;
}

void insert(node* node, int st) {
    if (st == len) {
        //node->end = 1;
        return;
    }

    if (!node->next[str[st] - 'a']) 
        node->next[str[st] - 'a'] = makenode();
    insert(node->next[str[st] - 'a'], st + 1);    // 틀린부분! if문 안으로 들어가면 안된다.
}

void solve(node* node) {

   /* if (node->end) {
        answer.clear();
        return;
    }*/

    if (cnt == K) {
        flag = 1;
        return;
    }

    for (int i = 0; i < 27; i++) {
        if (node->next[i]){
            answer += (i + 'a');
            if(node->next[i]->check == false) ++cnt;       
            solve(node->next[i]);
            if (flag) break;
            answer.pop_back(); // 틀린부분! answer.clear();로 하면 답이 다르다.
        }
    }
}

void delnode(node* node) {
    for (int i = 0; i < 27; ++i)
        if (node->next[i]) delnode(node->next[i]);
    free(node);
}

int main(void)
{
    freopen("input_K.txt", "r", stdin);
    //freopen("test_input.txt", "r", stdin);
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
        answer.clear();
    }
    return 0;
}