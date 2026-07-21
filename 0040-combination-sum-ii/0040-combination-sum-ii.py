class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        A=[]
        candidates.sort()

        def f(i,target,path):
            if(target==0):
                A.append(path[:])
                return
            if(i==len(candidates) or target<0):
                return
            path.append((candidates[i]))
            f(i+1,target-candidates[i],path)
            path.pop()
            while(i+1<len(candidates) and candidates[i]==candidates[i+1]):
                i=i+1
            f(i+1,target,path)
        f(0,target,[])
        return A
        
    