from collections import deque

# Initialize the matrix and the queue
matrix = [
    ['X', 'G', 'G', 'X', 'X', 'X', 'G', 'G'],
    ['X', '*', 'X', '*', '*', '*', '*', 'G'],
    ['X', '*', '*', '*', '*', '*', 'X', 'G'],
    ['X', 'X', 'X', '*', '*', '*', 'X', 'G'],
    ['G', 'X', '*', '*', 'R', 'X', 'X', 'G'],
    ['G', '*', '*', 'X', 'X', 'X', 'X', 'G'],
    ['G', '*', '*', '*', '*', '*', '*', 'X'],
    ['X', 'X', 'X', 'X', 'X', 'X', 'X', 'X']
]
queue = deque([(4, 4)])

# Initialize the distances matrix
distances = [[float('inf') for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
distances[4][4] = 0

# Perform BFS
while queue:
    x, y = queue.popleft()
    for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        nx, ny = x + dx, y + dy
        if 0 <= nx < len(matrix) and 0 <= ny < len(matrix[0]) and matrix[nx][ny] != 'X' and distances[nx][ny] == float(
                'inf'):
            distances[nx][ny] = distances[x][y] + 1
            if matrix[nx][ny] == 'G':
                print("Shortest path:", distances[nx][ny])
                exit()
            queue.append((nx, ny))
