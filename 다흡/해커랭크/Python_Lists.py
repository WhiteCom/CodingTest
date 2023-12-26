if __name__ == '__main__':
    N = int(input())
    
    myList = []
    
    for i in range(N):
        inputQuery = input().split()
        
        if(inputQuery[0] == 'insert'):
            index, value = map(int, inputQuery[1:])
            myList.insert(index, value)
            
        elif(inputQuery[0] == 'print'):
            print(myList)
            
        elif(inputQuery[0] == 'remove'):
            value = int(inputQuery[1])
            myList.remove(value)
            
        elif(inputQuery[0] == 'append'):
            value = int(inputQuery[1])
            myList.append(value)
            
        elif(inputQuery[0] == 'sort'):
            myList.sort()
            
        elif(inputQuery[0] == 'pop'):
            myList.pop()
            
        elif(inputQuery[0] == 'reverse'):
            myList.reverse()
            
        else:
            print("Error! Plase Add more Query!")
    