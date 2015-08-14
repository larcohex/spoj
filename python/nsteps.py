N = int (raw_input())
while N:
	line = raw_input()
	line = line.split()
	num1 = int (line[0])
	num2 = int (line[1])
	if num1 - num2 != 0 and num1 - num2 != 2:
		print "No Number"
	else:
		if num1 == num2:
			if num1 % 2:
				print 2 * num1 - 1
			else:
				print 2 * num1
		else:
			if num1 % 2:
				print 2 * num1 - 3
			else:
				print 2 * num1 - 2
	N -= 1
