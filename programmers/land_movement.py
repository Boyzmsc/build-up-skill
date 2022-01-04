# 사다리 문제
import heapq

def solution(land, height):
    N = len(land)

    visited = [[False for i in range(N)] for j in range(N)]
    move = [(1, 0), (0, 1), (-1, 0), (0, -1)]

    q = []

    visit_cnt = 0
    max_cnt = N*N
    rlt = 0

    # 비용, x, y
    q.append((0, 0, 0))

    while visit_cnt < max_cnt:
        val, x, y = heapq.heappop(q)

        if visited[x][y]:
            continue
        visited[x][y] = True

        visit_cnt += 1
        rlt += val

        curr_height = land[x][y]

        for dx, dy in move:
            nx = x + dx
            ny = y + dy

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue

            next_height = land[nx][ny]

            if abs(next_height - curr_height) > height:
                heapq.heappush(q, (abs(next_height - curr_height), nx, ny))
            else:
                heapq.heappush(q, (0, nx, ny))

    return rlt
