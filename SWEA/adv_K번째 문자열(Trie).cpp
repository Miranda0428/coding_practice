/*Ʈ���̿� ���� �߸� �����ϰ� �־���. root�� �ְ� �� ������ �б���� ���ٷ� �� �̾����� ���� �ƴϰ�
�κ� ���ڿ��� �ٸ� ���ڰ� ������ �бⰡ �Ͼ�� Ʈ���� ����̴�.
���ۿ��� '���ڿ� Ʈ����'�� �˻��غ��� ���ڿ����� ���ڰ� �޶����� �κк��� �бⰡ �Ͼ�� �� �� �ִ�.
���� Ʈ���̸� ����� ����밡���� root �̰� ����ٸ����� �б���� �κ� ���ڿ��� ��Ÿ���ٰ� �����ߴ�.
�׷��� insert �κа� solve �κ��� �߸������ߴ�.*/

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
    insert(node->next[str[st] - 'a'], st + 1);    // Ʋ���κ�! if�� ������ ���� �ȵȴ�.
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
            answer.pop_back(); // Ʋ���κ�! answer.clear();�� �ϸ� ���� �ٸ���.
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