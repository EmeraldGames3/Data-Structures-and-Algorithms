from collections import deque

# Initialize the matrix and the queue
labyrinth = [
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

# Initialize the distances and path matrices
distances = [[float('inf') for _ in range(len(labyrinth[0]))] for _ in range(len(labyrinth))]
distances[4][4] = 0
path = [[' ' for _ in range(len(labyrinth[0]))] for _ in range(len(labyrinth))]

# Perform BFS
while queue:
    x, y = queue.popleft()
    for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        nx, ny = x + dx, y + dy
        if 0 <= nx < len(labyrinth) and 0 <= ny < len(labyrinth[0]) and labyrinth[nx][ny] != 'X' and distances[nx][ny] == float(
                'inf'):
            distances[nx][ny] = distances[x][y] + 1
            if labyrinth[nx][ny] == 'G':
                print("Shortest path:", distances[nx][ny])
                # Build the path
                px, py = x, y
                while (px, py) != (4, 4):
                    path[px][py] = 'P'
                    for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                        nx, ny = px + dx, py + dy
                        if 0 <= nx < len(labyrinth) and 0 <= ny < len(labyrinth[0]) and distances[nx][ny] == distances[px][
                            py] - 1:
                            px, py = nx, ny
                            break
                # Replace the exit 'G' with an 'E'
                path[4][7] = 'E'
                # Print the matrix with the path
                for i in range(len(labyrinth)):
                    for j in range(len(labyrinth[0])):
                        if (i, j) == (4, 4):
                            print('R', end=' ')
                        elif path[i][j] == 'P':
                            print('P', end=' ')
                        elif path[i][j] == 'E':
                            print('E', end=' ')
                        else:
                            print(labyrinth[i][j], end=' ')
                    print()
                exit()
            queue.append((nx, ny))
