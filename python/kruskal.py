
class edge(object):
	def __init__(self, size, u, v):
		self.size = size
		self.u = u
		self.v = v

	def __lt__(self, other):
		return self.__cmp__(other) < 0

	def __eq__(self, other):
		return self.__cmp__(other) == 0
		
	def __cmp__(self, other):
		return self.size - other.size or self.u - other.u or self.v - other.v or 0

	def __repr__(self):
		return 'edge(' + repr(self.size) + ', ' + repr(self.u) + ', ' + repr(self.v) + ')'

class element(object):
	def __init__(self, parent, rank):
		if parent is not None:
			self.parent = parent
		else:
			self.parent = self
			
		self.rank = rank
	
	def union(self, other):
		if self.find() == other.find():
			return
		else:
			if self.rank < other.rank:
				self.parent.parent = other.parent
			else:
				other.parent.parent = self.parent
				if self.rank == other.rank:
					self.rank += 1
	
	def find(self):
		if self.parent != self:
			self.parent = self.parent.find()
		return self.parent

def read_input(inFileName):
	inFile = open(inFileName, 'r')

	n = int(inFile.readline())
	e = int(inFile.readline())
	edges = []
	for i in range(e):
		line = inFile.readline()
		u, v, size = [int(x) for x in line.split(" ", 3)]
		edges.append(edge(size, u, v))
	mstcost = int(inFile.readline())
	return (n, e, edges, mstcost)

def kruskal(n, e, edges):
	from heapq import heappop, heapify
	heapify(edges)
	
	mst = []
	sets = {}
	for vertex in range(n):
		sets[vertex] = element(None, 0)
	
	mstcost = 0
	for i in range(e):
		testedge = heappop(edges)
		if sets[testedge.u].find() == sets[testedge.v].find():
			continue
		else:
			mst.append(testedge)
			mstcost += testedge.size
			sets[testedge.u].union(sets[testedge.v])
					
	return (mstcost, mst)
		
def main():
	import sys
	from optparse import OptionParser
	from sys import argv
#	opts = OptionParser()
#	opts.add_option('-f', '--file', dest='filename', action='store', default=None, help="The file from which to read the input data")
#	(options, args) = opts.parse_args()
#	if options.filename is None:
#		inputfile = sys.stdin
#	else:
#		inputfile = open(options.filename, 'r')
	N,E,unsorted_edges,mstcost = read_input(argv[1])
	print kruskal(N, E, unsorted_edges)[0]
	

if __name__ == '__main__':
	main()
