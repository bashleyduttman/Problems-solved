class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp=[]
        for i in range(len(coins)):
            arr=[]
            for j in range(amount+1):
                arr.append(-1)
            dp.append(arr)
        def f(ind,amt):
            if ind<0:
                return float('inf')
            if amt==0:
                return 0
            if dp[ind][amt]!=-1:
                return dp[ind][amt]
            pick=float('inf')
            
            if coins[ind]<=amt:
                pick=1+f(ind,amt-coins[ind])
            notpick=0+f(ind-1,amt)
            dp[ind][amt]=min(pick,notpick)
            return min(pick,notpick)
        value=f(len(coins)-1,amount)
        if value==float('inf'):
            return -1
        return value
        


        