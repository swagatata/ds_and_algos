import sys

class Person:
    def __init__(self,pos):
        self.pos = pos
        self.alive = 1

    def __str__(self):
        return "Person #%d" % (self.pos)
    
    # Creates a chain of linked people
    # Returns the last one in the chain
    def createChain(self,n):
        if n>0:
            self.succ = Person(self.pos+1)
            return self.succ.createChain(n-1)
        else:
            return self

    # Kills in a circle, getting every nth living person
    # When there is only one remaining, the lone survivor is returned
    def kill(self,pos,nth,remaining):
        if self.alive == 0: return self.succ.kill(pos,nth,remaining)
        if remaining == 1: return self
        if pos == nth:
            self.alive = 0
            pos=0
            remaining-=1
        return self.succ.kill(pos+1,nth,remaining)



# n people in a circle
# kill every mth person

def josephus(self, m, n):
	first = Person(1)
	last = first.createChain(n - 1)
	last.succ = first

	return first.kill(1, m, n)

def main():
	if len(sys.argv) != 3:
		n = int(raw_input('Enter number of people : '))
		m = int(raw_input('Enter kill-interval    : '))
	else:
		n = int(sys.argv[1])
		m = int(sys.argv[2])

	print "In a circle of %d people, killing number %d" % (n,m)
	winner = josephus(1,m,n)
	print "Winner: ", winner

if __name__ == '__main__':
	main()

