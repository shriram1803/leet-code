#User function Template for python3

#User function Template for python3
class Solution:
    def armstrongNumber (ob, n):
        # code here
        save = n
        num = 0
        while n > 0:
            num += pow(n % 10, 3)
            n = n // 10
            
        if save == num:
            return "Yes"
            
        return "No"


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = input()
        n=int(n)
        ob = Solution()
        print(ob.armstrongNumber(n))
# } Driver Code Ends