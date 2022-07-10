using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    int countSum = 0;
    for (int i = 1; i <= count; i++) countSum += i;

    if (money >= price * countSum) answer = 0;
    else answer = price * (long long)countSum - money;


    return answer;
}