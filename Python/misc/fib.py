def fib(n):
	"""Return the n-th Fibonacci number."""
	a, b, i = 0, 1, 0
	while i < n:
		a, b = b, a + b
		i = i + 1
	return a

print(fib(20))
