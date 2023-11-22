def find_group(cards, start):
    group = [start]
    next_card = cards[start] - 1
    while next_card not in group:
        group.append(next_card)
        next_card = cards[next_card] - 1
    return group

def solution(cards):
    n = len(cards)
    visited = [False] * n
    groups = []

    for i in range(n):
        if not visited[i]:
            group = find_group(cards, i)
            groups.append(len(group))
            for card in group:
                visited[card] = True

    groups.sort(reverse=True)
    if len(groups) >= 2:
        return groups[0] * groups[1]
    else:
        return 0
