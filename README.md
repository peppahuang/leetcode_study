# leetcode_study
学习leetcode，跟代码随想录学习

2023.06.11
1、学习二分法，遇到有序、无重复数组中的查找，考虑二分法，#704 二分法查找
  n>>1 = n/2
2、快慢指针，双指针, #27 删除元素
3、双指针，减小时间复杂度。什么是时间复杂度？#977 有序数组的平方
  递归的时间复杂度 = 递归的次数 * 每次递归之后 执行的次数；
  二分法时间复杂度O(log2N)；
4、滑动窗口，先移动右区间再动左区间，就不用循环两次了，#209

2023.06.12
1、tips：数组的定义 char temp[4]{ 0 }; // 后面的0代表初始化全部为0

2023.06.14
完成螺旋矩阵生成，模拟过程，#59

2023.06.17
学习链表，链表生成，链表删除，#203

2023.06.25
1、设计链表#707
删除添加链表的时候，要主役移动next节点的顺序
2、反转链表
空链表[]指的是head == nullptr而不是head -> next == nullptr
我写的代码用的是循环一次一个vector存储所有数字，再循环一次进行反赋值。但是最快捷的方法是使用两个pointer，一个用来移动，一个记录上一个结点，使得不丢失上一个结点的位置。
反转完毕后，要将最后一个结点的next赋值Nullptr

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

2023.06.28
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

3、寻找环（注意其中的数学关系，很巧妙。https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.md）
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
