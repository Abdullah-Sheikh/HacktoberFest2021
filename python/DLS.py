visited = set()
end = set()
count = 0
def dfs(visited, graph, n, end, limit, count):
	if n == end or limit == count:
		exit()
	elif n not in visited:
		count = count + 1
		print(n)
		visited.add(n)
		for neighbour in graph[n]:
			dfs(visited, graph, neighbour, end, limit, count)
graph = {
	'1': ['2','3'],
	'2': ['4', '5'],
	'3': ['6','7'],
	'4': [],
	'5': [],
	'6': [],
	'7': []
}
# Driver Code
dfs(visited, graph, '1', 5, 3, 1)
