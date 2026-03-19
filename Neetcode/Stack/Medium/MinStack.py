// https://leetcode.com/problems/min-stack/

class MinStack:

    def __init__(self):
        self.nums = [] # contains pairs of num, previous min
        self.min_num = None

    def push(self, val: int) -> None:
        self.nums.append([val, self.min_num])
        print("Added ", [val, self.min_num])
        if self.min_num is None:
            self.min_num = val
        elif self.min_num > val:
            self.min_num = val
            print("New min:", val)

    def pop(self) -> None:
        if len(self.nums) > 0:
            print("Removing", self.nums[-1])
            self.min_num = self.nums[-1][1]
            print("New min:", self.min_num)
            self.nums.pop()
        
    def top(self) -> int:
        if len(self.nums) > 0:
            return self.nums[-1][0]
        return None

    def getMin(self) -> int:
        return self.min_num
        
