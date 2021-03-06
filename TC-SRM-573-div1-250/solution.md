#Team Contest


###题目简述
从一些数中每三个一组选出尽量多组大于某给定值。

###思路
这是一道贪心题。let s  = max(max(f0, f1), f2) + min(min(f0, f1), f2) + 1;
我们要尽可能创造更多满足要求的小组，使得这个小组的力量值能不小于s。

令n个小组为 ($$a_i$$, $$b_i$$, $$c_i) 其中  a < b < c， $$$$1\le i \le n$$
我们考虑选择c的策略， 我们肯定会从大到小选择（如果不然我可以用大的换小的结果不会变差）。
在选择c 的同时，我们考虑最大值为 $$x$$ 的小组的最好选法，我们寻找一个最小的 $$y$$使得 $$s \le x + y$$. 同理可证。
接下来我们考虑$$b$$的选法，$$b$$只需要比$$y$$大即可。我们可以选择目前大于$$y$$的最小的$$b$$

###算法
去掉前三个对其排序。可以证明任意时刻可选的数组成一个区间，我们从大到小枚举$$c$$，按照刚才的思路找到$$a$$对应的取值，再选择此时$$a$$的下标 $$+1$$的数作为$$b$$即可。当区间 $$\le2$$返回答案即可。