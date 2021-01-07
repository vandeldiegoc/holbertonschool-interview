def minOperations(n):
    """Minimum Operations"""
    if n <= 1:
        return 0

    mini = 0
    i = 2
    while i <= n:
        if n % i == 0:
            mini += i
            n /= i
        else:
            i += 1
    return(mini)
