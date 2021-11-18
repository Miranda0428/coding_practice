**Sort**

차이점
1.

#include <algorithm> : sort에서는 greater가 내림차순
#include <queue> : priority_queue의 sort에서는 greater가 오름차순
2.

#include <algorithm> : sort에서는 1번의 greater를 사용시에 greater<int>()와 같이 사용
#include <queue> : priority_queue의 sort에서는 1번의 greater를 사용시에 gerater<int>와 같이 사용
3. 

#include <algorithm> : sort에서는 cmp 함수를 만들때 인자의 왼쪽이 기준
#include <queue> : priority_queue의 sort에서는 cmp 함수를 만들때 인자의 오른쪽이 기준
 

추천방법
1. #include <algorithm> : 비교함수 cmp를 만들어서 사용

2. #include <algorithm> : greater<type>() 사용 -> 구조체는 1번, 어떤 원소를 비교할지 몰라 에러 발생

 

bool cmp(pair<int, string> v1, pair<int, string> v2)
{
    if(v1.first == v2.first)
    {
         sort는 왼쪽이 기준이기 때문에 second 오름차순 정렬 
        return v1.second < v2.second;
    }
    else
    {
         sort는 왼쪽이 기준이기 때문에 first 오름차순 정렬     
        return v1.first < v2.first;    
    }
}
vector<pair<int, string>> v;
sort(v.begin(), v.end(), cmp); 
 
 
sort(v.begin(), v.end()); // 오름차순
sort(v.begin(), v.end(), greater<int>()); // 내림차순
cs
 

3. #include <queue> : 클래스 cmp에 oeprator()를 만들어서 사용

4. #include <queue> : less<type>, greater<type> 사용

 

//struct cmp 
class cmp
{
    public:
        bool operator()(pair<int, int> pq1, pair<int, int> pq2)
        {
            if(pq1.first == pq2.first)
            {
                // priority_queue는 오른쪽이 기준이기 때문에 second 오름차순 정렬 
                return pq1.second > pq2.second;
            }
            else
            {
                // priority_queue는 오른쪽이 기준이기 때문에 first 오름차순 정렬     
                return pq1.first > pq2.first;   
            }
        }
};    
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
 
 
// 일반적인 사용법도 추천
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

**최소신장트리**

신장트리(spanniing tree) : 그래프에서 싸이클없이 모든 노드를 간선으로 연결할 수 있는 트리

최소신장트리 : 가중치의 합을 최소로 하는 신장트리

최소신장트리를 찾는 알고리즘 : Prim, Kruscal
