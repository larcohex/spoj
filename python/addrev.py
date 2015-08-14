N = int (raw_input())
while N:
	line = raw_input()
	line = line.split()
	num1 = (line[0])[::-1]
	num2 = (line[1])[::-1]
	print int ((str ( int ((line[0])[::-1]) + int ((line[1])[::-1]) ))[::-1])
	N -= 1
