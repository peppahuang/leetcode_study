#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    // vector<vector<int>> flags(n)(n);
    int flag[n][n];
    for (int a = 0; a < n; a ++) {
        for (int b = 0; b < n; b ++) {
            flag[a][b] = 0;
        }
    }
    vector<vector<int>> result;
    int count2 = 1;
    int i = 0;
    int j = 0;
    int up_max = 0, down_min = n;
    int right_max = n, left_min = -1;
    int up = 0, down = 0, left = 0, right = 0;
    while (count2 <= n * n) {

        while (true) {
            flag[i][j] = count2;
            count2 ++;
            j ++;
            if (j == right_max) {
                break;
            }
        }
        if (count2 > n * n) {
            break;
        }
        right_max --;
        i ++;
        j --;
        while (true) {
            flag[i][j] = count2;
            count2 ++;
            i ++;
            if (i == down_min) {
                break;
            }
        }
        if (count2 > n * n) {
            break;
        }
        down_min --;
        j --;
        i --;
        while (true) {
            flag[i][j] = count2;
            count2 ++;
            j --;
            if (j == left_min) {
                break;
            }
        }
        if (count2 > n * n) {
            break;
        }
        left_min ++;
        i --;
        j ++;
        while (true) {
            flag[i][j] = count2;
            count2 ++;
            i --;
            if (i == up_max) {
                break;
            }
        }
        if (count2 > n * n) {
            break;
        }
        up_max ++;
        j ++;
        i ++;
    }
    for (int a = 0; a < n; a ++) {
        vector<int> aa(n);
        for (int b = 0; b < n; b ++) {
            aa[b] = flag[a][b];
        }
        result.push_back(aa);
    }
    return result;
}
struct  ListNode {
    double value;
    ListNode *next;
    // 构造函数
    ListNode (double value1,ListNode *next1 = nullptr) {
        value = value1;
        next = next1;
    }
};

int main()
{
//    vector<vector<int>> a = generateMatrix(3);

//    ListNode *head = nullptr;

//    head = new ListNode;
//    head->value = 12.5;
//    head->next = nullptr;

//    ListNode *SecondNode = new ListNode;
//    SecondNode->value = 13.5;
//    SecondNode->next = nullptr;
//    head->next = SecondNode;

//    cout << "first:" << head->value << endl;
//    cout << "second:" << head->next->value << endl;
//    ListNode *SecondNode = new ListNode(13.5);
//    ListNode *head = new ListNode(12.5,SecondNode);
    ListNode *head = new ListNode(12.5);
    ListNode *Second = new ListNode(13.5);
    head->next = Second;
    ListNode *Third = new ListNode(14.5);
    Second->next = Third;
    ListNode *Fourth = new ListNode(15.5);
    Third->next = Fourth;

    Second->next = Fourth;
    ListNode *ptr = head;
    while (ptr != nullptr) {
        cout << ptr->value <<endl;
        ptr = ptr->next;
    }
    cout << "Hello World!" << endl;
    return 0;
}
