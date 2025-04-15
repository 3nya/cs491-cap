import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return int(input())
def inlt():
    return list(map(int, input().split()))
def inltchar():
    return list(map(str, input().split()))

def main():
    n = inp()
    a = inlt()
    o = inltchar()

    a_ext = a + [a[0]]
    o_ext = o + [o[0]]

    max_result = float('-inf')
    results = []

    for start in range(n):
        # Subarrays of length n
        nums = a_ext[start:start + n]
        ops = o_ext[start:start + n - 1]

        dp_max = [[float('-inf')] * n for _ in range(n)]
        dp_min = [[float('inf')] * n for _ in range(n)]

        for i in range(n):
            dp_max[i][i] = nums[i]
            dp_min[i][i] = nums[i]

        for length in range(2, n + 1):  # interval length
            for l in range(n - length + 1):
                r = l + length - 1
                for k in range(l, r):
                    op = ops[k]
                    if op == '+':
                        dp_max[l][r] = max(dp_max[l][r], dp_max[l][k] + dp_max[k + 1][r])
                        dp_min[l][r] = min(dp_min[l][r], dp_min[l][k] + dp_min[k + 1][r])
                    else:
                        candidates = [
                            dp_max[l][k] * dp_max[k + 1][r],
                            dp_max[l][k] * dp_min[k + 1][r],
                            dp_min[l][k] * dp_max[k + 1][r],
                            dp_min[l][k] * dp_min[k + 1][r]
                        ]
                        dp_max[l][r] = max(dp_max[l][r], max(candidates))
                        dp_min[l][r] = min(dp_min[l][r], min(candidates))

        max_result = max(max_result, dp_max[0][n - 1])
        results.append(dp_max[0][n - 1])

    print(max_result)

main()
