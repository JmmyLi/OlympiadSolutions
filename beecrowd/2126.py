# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2126
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
caso = 1
while True:
	try:
		subsequencia = raw_input()
	except EOFError:
		break
	sequencia = raw_input()
	print "Caso #%d:" % (caso)
	if subsequencia not in sequencia:
		print "Nao existe subsequencia\n"
	else:
		total = sequencia.count(subsequencia)
		print "Qtd.Subsequencias: %d" % total
		print "Pos: %d\n" % (sequencia.replace(subsequencia,"*"*len(subsequencia),total-1).index(subsequencia)+1)
	caso += 1
