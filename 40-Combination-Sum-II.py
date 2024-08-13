class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        n=len(candidates)
        s=0
        op=[]
        candidates.sort()
        def cs(ind,arr,s):
            if s==target:   
                op.append(arr.copy())
                return
            for i in range(ind,n):
                if i>ind and candidates[i]==candidates[i-1]:
                    continue
                if s+candidates[i]>target:
                    break
                arr.append(candidates[i])
                s+=candidates[i]
                cs(i+1,arr,s)
                arr.remove(candidates[i])
                s-=candidates[i]
        cs(0,[],s)
        return op
        