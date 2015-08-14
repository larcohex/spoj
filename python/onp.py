import sys

def prec (ch):
	if ch == '(':
		return 0
	elif ch == '+' or ch == '-':
		return 1
	elif ch == '*' or ch == '/':
		return 2
	else:
		return 3



t = int (raw_input())
while t:
	expr = raw_input()
	stack = []
	result = []
	for i in expr:
		if i.isalpha():
			result.append (i)
		elif i == ')':
			j = len (stack) - 1
			while stack[j] != '(':
				result.append (stack[j])
				stack.pop()
				j -= 1
			stack.pop()
		else:
			if i == '^' or i == '(' or not stack or prec (i) > prec (stack[len (stack) - 1]):
				stack.append(i)
			else:
				j = len (stack) - 1
				while prec (i) <= prec (j):
					print ("Appending", stack[j])
					result.append (stack[j])
					stack.pop()
					j -= 1
	j = len (stack) - 1
	while stack:
		result.append (stack[j])
		stack.pop()
		j -= 1
 
	for i in result:
		sys.stdout.write(i)
	sys.stdout.flush()
	print
	t -= 1
