// 投篮大赛.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s)) {
        vector<int> ans;
        int tmp = 0;
        for (auto i : s) {
            if (i < +'9' && i >= '0') {
                tmp *= 10;
                tmp += (i - '0');
            }
            else if (i == ' ') {
                if (tmp) {
                    ans.emplace_back(tmp);
                    tmp = 0;
                }
            }
            else if (i == 'D') ans.emplace_back(ans.back() * 2);
            else if (i == 'C') ans.pop_back();
            else if (i == '+') {
                auto it = ans.end() - 2;
                ans.emplace_back(*it + ans.back());
            }
        }
        for (int i : ans) tmp += i;
        cout << tmp << endl;
    }
}
/*
你现在是一场采用特殊赛制投篮大赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。<br>
比赛开始时，记录是空白的。
你会得到一个记录操作的字符串列表
其中ops[i]是你需要记录的第i项操作，ops遵循下述规则：
整数x-表示本回合新获得分数x
“+” – 表示本回合新获得的得分是前两次得分的总和。
“D” – 表示本回合新获得的得分是前一次得分的两倍。
“C” – 表示本回合没有分数，并且前一次得分无效，将其从记录中移除。
*/
