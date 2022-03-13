#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
     
   int i = 0; int j = people.size()-1;
    
    while(i<=j)
    {
        if(people[i]+people[j] <=limit)
        {
            i++; j--; 
        }
        else{
            j--;
        }
        answer++;
        //if the biggest man can't ride with the smallest man, then him ride alone.
        //so, if-else ->>>> else, then answer ++ -keon 
    }
    
    // time over
    /*  
    for(int i=0;i<people.size();i++)
    {
        for(int j=people.size()-1;j>i;j--)
        {
            if(people[i]+people[j]<=limit)
            {
                answer++;
                people[i] = 250;
                people[j] = 250;
                break;
            }
         }
        if(people[i] != 250) 
        {
            answer++;
        }
    }
   
*/
    return answer;
}