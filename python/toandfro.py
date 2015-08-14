import sys


while True:
	n = int (raw_input())
	if not n:
		break
	else:
		line = raw_input()
		array = []
		i = 0
		while i < len (line):
			temp = ""
			j = 0
			while j < n:
				temp += line[i]
				i += 1
				j += 1
			array.append (temp)
		i = 0
		while i < n:
			j = 0
			while j < len (array):
				if j % 2:
					sys.stdout.write (array[j][n-1-i])
				else:
					sys.stdout.write (array[j][i])
				j += 1
			i += 1
		sys.stdout.flush()
		print
