class Solution:
    def findOrder(self, numCourses: int, pre: List[List[int]]) -> List[int]:
        indegree=[0 for i in range(numCourses)]
        adj=[[] for i in range(numCourses)]
        for pair in pre:
            adj[pair[0]].append(pair[1])
        for i in range(len(pre)):
            indegree[pre[i][1]]+=1
        q=[]
        queue=deque([])
        for i in range(len(indegree)):
            if indegree[i]==0:
                queue.append(i)
        while queue:
            value=queue.popleft()
            q.append(value)
            for node in adj[value]:
                indegree[node]-=1
                if indegree[node]==0:
                    queue.append(node)
        li=[]
        if len(q)!=numCourses:
            return []
        for i in range(len(q)):
            li.append(q.pop())
        return li


        