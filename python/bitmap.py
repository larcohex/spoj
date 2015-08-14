def bfs (matrix, queue, n, m):
	while queue:
		temp = queue[0]
		queue.pop(0)
		nearxs = [0, 1, 0, -1]
		nearys = [1, 0, -1, 0]
		for i in range (0, 4):
			x = temp[0] + nearxs[i]
			y = temp[1] + nearys[i]
			if x < n and x >= 0 and y < m and y >= 0:
				if matrix[x][y] == -1 or matrix[temp[0]][temp[1]] + 1 < matrix[x][y]:
					matrix[x][y] = matrix[temp[0]][temp[1]] + 1
					queue.append ([x, y])





t = int (raw_input())
while (t):
	n, m = [int (x) for x in (raw_input()).split()]
	queue = []
	result = [[-1 for i in range (0, m)] for j in range (0, n)]
	for i in range (0, n):
		line = raw_input()
		for j in range (0, m):
			if line[j] == '1':
				queue.append ([i, j])
				result[i][j] = 0
	bfs (result, queue, n, m)
	for i in range (0, n):
		for j in range (0, m):
			print result[i][j],
		print
	t -= 1
