#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int a = 0;
 
    
    
    for(int i=0;i<lost.size();i++)
    {
        for(int j=0; j<reserve.size();j++)
        {
            if(lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                break;
            }
        }
    }
    
    
    answer = n - lost.size();
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    //정렬을 안써주면 틀리는 답안이 존재,,, but 왜일까..?


    for(int i=0;i<lost.size();i++)
    {
        for(int j=0; j<reserve.size();j++)
        {
            a = lost[i];
            if(a-1 == reserve[j] || a+1 == reserve[j])
            {
                answer++;
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }
   // lost 값을 갖고 resevr에 -1 or +1 한 값이 있는지 탐색 
    //if 있다면 그값을 reserve배열에서 삭제
    
    // then answer ++
    
    return answer;
}