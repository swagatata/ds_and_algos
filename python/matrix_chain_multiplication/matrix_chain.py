def main():
    rf = open('matrix_chain_input')    
    numbers = [int(x) for x in rf.read().split()]
    index = 0
#    print numbers
    T = numbers[index]
    index += 1
    
    for i in range(T):
        N = numbers[index]
        index += 1
        matrix = []
        cost = []        

        #initialization
        matrix.append([])
        matrix[0].append(numbers[index])
        index += 1
        matrix[0].append(numbers[index])
        index += 1
        for j in range(1, N):
            matrix.append([])
            matrix[j].append(numbers[index])
            if matrix[j][0] != matrix[j-1][1]:
                print "Invalid matrix order : matrix " + (j+1)
                return
            index += 1
            matrix[j].append(numbers[index])
            index += 1
            
        cost.append([0] * N)
#        for j in range(N-1):
 #           cost[0].append(matrix[j][0] * matrix[j][1] * matrix[j+1][0])

        pivot = [[]]
        for j in range(2,N+1):#j represents the width in this level
#            print "In width : ", j
            cost.append([])
            pivot.append([])
            for k in range(0, N - j + 1):#start indices from 0 to last possible index
                minimum = 1e308
                minindex= 0
                for l in range(j - 1):#division occuring in <width> number of ways
                    temp = cost[l][k] + cost[j - (l + 1) - 1][k+l+1] + matrix[k][0] * matrix[k+l][1] * matrix[k + j - 1][1]
                    if temp < minimum:
                        minimum = temp
                        minindex = l+k                        
#                print "At index ", k, " the minimum is : ", minimum
                cost[j-1].append(minimum)
                pivot[j-1].append(minindex)
                
        print "Min cost of multiplication is : ", cost[N-1][0]

        print "Optimal order of excluding matrices is : ",
        printpivots(pivot, 0, N-1)

def printpivots(pivot, start, end):
    if start + 1 >= end:
        print start, 
        return
    
    p1 = pivot[end - start][start]
    if start == p1:
        print start,
        printpivots(pivot, p1+1, end)
        return
        
    printpivots(pivot, start, p1)
    print p1,
    printpivots(pivot, p1+1, end)

if __name__ == '__main__':
    main()
