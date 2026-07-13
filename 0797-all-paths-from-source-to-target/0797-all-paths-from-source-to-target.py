class Solution(object):
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        A=[]
        def f(node,path):
            path.append(node)
            if(node==len(graph)-1):
                A.append(path[:])
            else:
                for k in graph[node]:
                    f(k,path)
            path.pop()
        f(0,[])
        return A