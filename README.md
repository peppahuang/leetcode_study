## leetcode_study
学习leetcode，跟代码随想录学习

## 2023.06.11
1、学习二分法，遇到有序、无重复数组中的查找，考虑二分法，#704 二分法查找
  n>>1 = n/2
2、快慢指针，双指针, #27 删除元素
3、双指针，减小时间复杂度。什么是时间复杂度？#977 有序数组的平方
  递归的时间复杂度 = 递归的次数 * 每次递归之后 执行的次数；
  二分法时间复杂度O(log2N)；
4、滑动窗口，先移动右区间再动左区间，就不用循环两次了，#209

## 2023.06.12
1、tips：数组的定义 char temp[4]{ 0 }; // 后面的0代表初始化全部为0

## 2023.06.14
完成螺旋矩阵生成，模拟过程，#59

## 2023.06.17
学习链表，链表生成，链表删除，#203

## 2023.06.25
1、设计链表#707
删除添加链表的时候，要主役移动next节点的顺序
2、反转链表
空链表[]指的是head == nullptr而不是head -> next == nullptr
我写的代码用的是循环一次一个vector存储所有数字，再循环一次进行反赋值。但是最快捷的方法是使用两个pointer，一个用来移动，一个记录上一个结点，使得不丢失上一个结点的位置。
反转完毕后，要将最后一个结点的next赋值Nullptr
```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
```
## 2023.06.28
1、交换链表 #24
使用虚拟头结点 dummyHead
要注意，定义的时候需要初始化
ListNode *dummyHead = new ListNode(0);

返回的时候return dummyHead -> next而不是dummyHead。

sample：
ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
ListNode* cur = dummyHead;

要注意，需要处理的一定是cur -> next而不是cur，也要注意while停止的条件，是cur -> next != nullptr；

2、#19. 删除链表的倒数第 N 个结点
可以使用一个n长的滑动窗口来完成倒数的任务。

3、寻找环（注意其中的数学关系，很巧妙。https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.md）、
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        while (fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow) {
                ListNode *p1, *p2;
                p1 = head;
                p2 = fast;
                while (p2 != p1) {
                    p1 = p1 -> next;
                    p2 = p2 -> next;
                }
                return p2;
            }
        }
        return NULL;
        
    }

};
```
## 2023.07.12
1、进入哈希表的学习。
如果想要搜索一个字符串或者一串xx里面是否有某个数字，可以用一组数列来把他们规整的装起来。
同时，如果想要排序，也可以用一个数组把所有数据的数量先放起来，然后挨个cout

* 0242 有效的字母异位词

* 1002 查找共用字符

其他：
memset是计算机中C/C++语言初始化函数。作用是将某一块内存中的内容全部设置为指定的值， 这个函数通常为新申请的内存做初始化工作。
简单来说，就是将某一块内存的全部内容设置为指定的值。
#include<cstring>
void *memset(void *s, int ch, size_t n);

memset(hashOtherStr, 0, 26 * sizeof(int)); //设置26格子都为0的int数组

* 349. 两个数组的交集

* 202.快乐数（下面为代码随想录解答，主要学习unordered_set使用，首次接触）
```
class Solution {
public:
    // 取数值各个位上的单数之和
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
            if (set.find(sum) != set.end()) { // 注意，找不到返回的不是false，而是返回set.end()
                return false;
            } else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};
```
## 2023.07.25
* 1.两数之和
首先我在强调一下 什么时候使用哈希法，当我们需要查询一个元素是否出现过，或者一个元素是否在集合里的时候，就要第一时间想到哈希法。

这道题我第一反应的解法就是遍历两层，来求和找到最终结果。但是代码随想录给出的方法就是，遍历，然后去剩下的元素里面寻找互补的那个数，看有没有。有互补的就输出。

学习map的用法（unordered_map）

## 2023.08.02
* 454.四数相加
4层遍历利用unordered_map变成2次2层的遍历

* 383.赎金信
也是利用哈希的想法，对数据出现次数进行累加搜索。
值得注意的是，经常会不记得将数据初始化，导致后续的计算出错
int count[26]{0}; 


## 2023.08.10
* 15.三数之和。使用了双指针的办法（值得继续琢磨的一道题）
* 18.四数之和类似

## 2023.08.11
* 344.反转字符串 双指针
* 541. 反转字符串 II循环 双指针，看题！

替换空格

## 2023.08.14
* 151. 反转字符串单词（删除空格部分需要斟酌）
  ```
    void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
        for (int i = 0; i < s.size(); ++i) { //
            if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
                if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小。
    }

* 左旋转字符串：重点是这个思路
这道题目也非常类似，依然可以通过局部反转+整体反转 达到左旋转的目的。

具体步骤为：

反转区间为前n的子串
反转区间为n到末尾的子串
反转整个字符串

reverse的区间左闭右开

* 28. 实现 strStr() 注意一下循环的开始和结束
代码随想录在这里写了KMP，注意学习。

## 2023.08.15
* KMP算法以及字符串后面两题待解决。
* 
## 2023.08.18
* 学习KMP算法
* https://www.bilibili.com/video/BV1jb411V78H/?spm_id_from=333.337.search-card.all.click&vd_source=57361abd4023827115c685feaf4ee90e
* 天勤考研讲述KMP算法
