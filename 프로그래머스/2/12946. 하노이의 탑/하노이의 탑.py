
def hanoi(n, start, end, via, result):
    if n == 1:
        result.append([start, end])
    else:
        hanoi(n-1, start, via, end, result)  # n-1개의 원판을 start에서 via로 이동
        result.append([start, end])  # 가장 큰 원판을 start에서 end로 이동
        hanoi(n-1, via, end, start, result)  # via에 있는 n-1개의 원판을 end로 이동

def solution(n):
    answer = []
    hanoi(n, 1, 3, 2, answer)
    return answer