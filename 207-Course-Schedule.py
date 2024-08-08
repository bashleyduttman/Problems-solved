class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
            arr=[[] for _ in range(numCourses)]
            for pair in prerequisites:
                arr[pair[1]].append(pair[0])
            visited=[0]*numCourses
            path=[0]*numCourses
            def dfs(i):
               
                visited[i]=1
                path[i]=1
                for course in arr[i]:
                    if visited[course]==0:
                        if not dfs(course):
                            return False
                    else:
                        if path[course]==1:
                            return False
                path[i]=0
                return True
            print(arr)
            for i in range(numCourses):
                if visited[i]==0:
                    if not dfs(i):
                        return False
            return True

        