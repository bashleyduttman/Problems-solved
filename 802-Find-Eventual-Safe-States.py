class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        # adj=[[] for i in range(len(graph))]
        # for i in range(len(graph)):
        #     ad[i].append(graph[i])
        visited=[0]*len(graph)
        path=[0]*len(graph)
        li=[]
        def dfs(i):
            visited[i]=1
            path[i]=1
            for node in graph[i]:
                if visited[node]==0:
                    if dfs(node) is False:
                        return False
                elif path[node]==1:
                    return False
            path[i]=0
            li.append(i)
            return
        for i in range(len(graph)):
            if visited[i]==0:
                dfs(i)
        li.sort()
        return li