class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        A=[]

        def f(i,target,path):
            if(target==0):
                A.append(path[:])
                return
            if(i==len(candidates) or target<0):
                return
            path.append((candidates[i]))
            f(i,target-candidates[i],path)
            path.pop()
            f(i+1,target,path)
        f(0,target,[])
        return A

        