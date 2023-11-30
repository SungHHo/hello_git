def solution(matrix_sizes):
    n = len(matrix_sizes)
    dp = [[0]*n for _ in range(n)]
    for r in range(1, n):
        for i in range(n-r):
            j = i + r
            dp[i][j] = min(dp[i][k] + dp[k+1][j] + matrix_sizes[i][0]*matrix_sizes[k][1]*matrix_sizes[j][1] for k in range(i, j))
    return dp[0][n-1]
