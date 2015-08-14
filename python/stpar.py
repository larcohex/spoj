while True:
	n = int (raw_input())
	if not n:
		break

	else:
		init = [int (x) for x in (raw_input()).split()]
		order = True
		exit = []
		side = []


		while order and init:


			if (not exit and init[0] == 1) or (exit and init[0] == exit[0] + 1):
				exit.insert (0, init[0])
				init.pop (0)



			else:
				if not side or side[0] > init[0]:
					side.insert (0, init[0])
					init.pop (0)
				elif exit and side[0] == exit[0] + 1:
					exit.insert (0, side[0])
					side.pop (0)
				else:
					order = False

		if order:
			print "yes"
		else:
			print "no"
