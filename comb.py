def combinacion(i,N,k):
    if k == 0: return [[]]
    if i > N: return []
    L = combinacion(i+1,N,k-1)
    for l in L:
	l.append(i)
    return L + combinacion(i+1,N,k)

def c(n,k):
 if k>n: return 0
 if k == n or k == 0: return 1
 return c(n-1,k-1) + c(n-1,k)

N = 15
i = 1
for k in range(1,16):
	if len(combinacion(i,N,k)) != c(N,k):
		print "nicagando te aceptan en google, aweonao ql"

print "wena wn, en vola ..."
