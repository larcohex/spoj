import sys

t = int (raw_input())
while t:
	num = raw_input()
	if len (num) > 1:
		temp = []
		for i in num:
			temp.append (int (i))
		size = len (num)
		center = size // 2
		str1 = num [0:center]
		str2 = num [size-1:center:-1]
		if str2 > str1:
			for i in range (center + 1, size):
				temp[i] = 0
			for i in range (0, center + 1):
				temp[center - i] += 1
				if temp > 9:
					temp[center - i] = 0
					if i != center:
						temp[center - 1 - i] += 1
						if temp[center - 1 - i] <= 9:
							break
					else:
						temp.insert (0, 1)
				else:
					break
		result = temp[:]
		size = len (result)
		center = size // 2
		for i in range (0, center):
			result[size - 1 - i] = result[i]
		if result <= temp:
			result[center] += 1
			if not size % 2:
				result[center - 1] += 1
		for i in result:
			sys.stdout.write (str(i))
		sys.stdout.flush()
		print
	else:
		num = int (num[0]) + 1
		print num
	t -= 1
