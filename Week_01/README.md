学习笔记
观看视频的方法：1.5-2倍速观看，难点重点没有理解的点反复观看


1改变习惯，不要死磕一道题，五分钟想不到解决思路就去看题解
2五毒神掌，练习至少5遍，过数遍，不是 每次都花很长时间
3不死磕通过，要多看高质量题解

最大的误区：只做一遍题

实战题目练习方法：
1读题和思考 5-10分钟
2有思路就自己先试一下，
把所有的结题思路都写下来，尽量把自己的想法都实现一遍。
写完代码提交一下，测试一些特殊的测试用例
想不出来思路，不要耗费太多时间，没有思路就去看高质量题解
3查看最优解，默写、背诵最优解，直到自己能熟练写下来，看到别人代码的优点学习过来
4自己写出来，不要再看题解，多写几遍，直到熟练
5去国际站，看全世界的顶级程序员的解题思路

1移动零
//思路 记录0的位置，交换零
void moveZeroes(vector<int>& nums) {
        int j=0; //记录零元素位置
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != 0) {
                nums[j]=nums[i];
                if( i!=j ) {
                    nums[i]=0;
                }
                j++;
            } 
        }
    }


//双指针
 void moveZeroes(vector<int>& nums) {
       //双指针
       int j=0;//记录非零元素位置
       for(int i=0;i<nums.size();i++) {
           if(nums[i]!=0) {
               nums[j]=nums[i];
               j++;
           }
       }
       for(int i=j;i<nums.size();i++) {
           nums[i]=0;
       }
    }

2盛水最多容器
//思路 枚举
//自顶向下的编程思想
class Solution {
public:
    // int max(int i,int j);
    // int min(int i,int j);
    int Max(int i,int j) {
        return (i>j)?i:j; 
    }
    
    int Min(int i,int j) {
        return (i<j)?i:j;
    }
    int maxArea(vector<int>& height) {
        //枚举 找出最大面积:min(height[i],height[j])*(j-i)
        int area=0;
        int max=0;
        for(int i=0;i<height.size()-1;i++) { //i遍历到height.size()-1
            for(int j=i+1;j<height.size();j++) {
                area=Min(height[i],height[j])*(j-i);
                max=Max(max,area);
            }
        }
        return max;
    }
};


//左右端 向中间收敛：左右夹逼
//左i 右j 取min(height[i],height[j])向中间收敛 保持i<j
class Solution {
public:
    int max(int i,int j);
    int min(int i,int j);
    
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int area=0;
        int max=0;
        while(i<j) {
            area=Min(height[i],height[j])*(j-i);
            max=Max(max,area);
            if(height[i]<height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return max;
    }
    int Max(int i,int j) {
        return (i>j)?i:j; 
    }
    
    int Min(int i,int j) {
        return (i<j)?i:j;
    }
};

3爬楼梯
//没有解题思路的时候 1考虑最基本的情况 2使用暴力解法
//考虑最基本情况 然后泛化
//分析 归纳法 找最近重复子问题
//1 1
//2 1+1 2 f(1)+f(0)
//3 1+1+1 1+2 2+1  f(2)+f(1)
//最后一步 上一阶台阶或两阶台阶 n=f(n-1)+f(n-2);
int climbStairs(int n) {
        if(n<2) {
            return 1;
        }
        else {
            return climbStairs(n-1)+climbStairs(n-2);
        }
    }


//遍历 找到最底层 找
int climbStairs(int n) {
    res=0;
    for(int i=0;i<n-1;i++) {
        res=res+i;
    }
    return res;
}


4 2sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //两数之和 暴力求解 两次循环 O(n^2)
        for(int i=0;i<nums.size()-1;i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[j]==target-nums[i]) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};