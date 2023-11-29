import heapq
from collections import defaultdict

def solution(n, roads, sources, destination):
    graph = defaultdict(list)
    for a, b in roads:
        graph[a].append(b)
        graph[b].append(a)
    
    distances = [float('inf')]*(n+1)
    distances[destination] = 0

    queue = [(0, destination)]
    while queue:
        current_distance, current_node = heapq.heappop(queue)
        if distances[current_node] < current_distance:
            continue
        for adjacent in graph[current_node]:
            distance = current_distance + 1
            if distance < distances[adjacent]:
                distances[adjacent] = distance
                heapq.heappush(queue, (distance, adjacent))
                
    return [distances[source] if distances[source] != float('inf') else -1 for source in sources]



