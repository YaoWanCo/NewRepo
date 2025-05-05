// 模拟消息队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    while (getline(cin, a)) {
        getline(cin, b);
        map<int, int> event;
        vector<pair<int, int>> people;
        int x = 0 , y = 0;
        for (int k = 0; k < a.size(); k++) {
            char i = a[k];
            if (i == ' ' || k == a.size() - 1) {
                if (y == 0) {
                    y = x;
                    x = 0;
                }
                else if (k == a.size() - 1) {
                    x = x * 10 + (i - '0');
                    event[y] = x;
                    x = 0; y = 0;
                }
                else {
                    event[y] = x;
                    x = 0; y = 0;
                }
            }
            else x = x * 10 + (i - '0');
        }
        for (int k = 0; k < b.size(); k++) {
            char i = b[k];
            if (i == ' ' || k == b.size() - 1) {
                if (y == 0) {
                    y = x;
                    x = 0;
                }
                else if (k == b.size() - 1) {
                    x = x * 10 + (i - '0');
                    people.emplace_back(make_pair(y, x));
                    x = 0; y = 0;
                }
                else {
                    people.emplace_back(make_pair(y, x));
                    x = 0; y = 0;
                }
            }
            else x = x * 10 + (i - '0');
        }
        vector<vector<int>> ans(people.size());
        for (auto i : event) {
            for (int j = people.size() - 1; j >= 0; j--) {
                if (i.first >= people[j].first && i.first < people[j].second) {
                    ans[j].emplace_back(i.second);
                    break;
                }
            }
        }
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << ' ';
            }
            cout << endl;
        }
    }

}

/*
输入
2 22 1 11 4 44 5 55 3 33
1 7 2 3
输出
11 33 44 55
22
输入
5 64 11 64 9 97
9 11 4 9
输出
97
64
说明

消息11在1时刻到达，此时只有第一个消费者订阅，消息发送给它，
消息22在2时刻到达，此时两人消费者都订阅了，消息发送给优先级最高的第二个消费者 :
消息33在时刻3到达，此时只有第一个消费者订阅，消息发送给它;
余下的消息按规则也是发送给第一个消费者
*/ 