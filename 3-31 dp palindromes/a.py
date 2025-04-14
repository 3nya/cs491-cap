import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def inltchar():
    return(list(map(str,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))


def main():
    n = inp()
    a = inlt()
    o = inltchar()

    dp = [[0 for i in range(n)] for i in range(n)]

    for i in range(n):
        dp[i][i] = a[i]

    for length in range(2, n + 1): # interval length
        for l in range(n - length + 1): # left
            r = l + length - 1
            
            dp[l][r] = 0
            for k in range(l, r):
                if o[k] == "+":
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r])
                else:
                    dp[l][r] = max(dp[l][r], dp[l][k] * dp[k + 1][r])

    print(dp[0][n - 1])

    ## differences for the hard version
    ## keep track of maximum and minimum subarray

main()


