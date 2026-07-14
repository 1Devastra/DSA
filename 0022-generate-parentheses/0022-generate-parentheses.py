class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        A=[]
        def f(open,close,path):
            if len(path)==2*n:
                A.append(path)
                return
            if open<n:
                f(open+1,close,path+"(")
            if close<open:
                f(open,close+1,path+")")
        f(0,0,"")
        return A
        