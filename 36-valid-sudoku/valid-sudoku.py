class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        ans = True
        for i in range(0,9):
            mySet = set()
            mySet2 = set()
            for j in range(0,9):
                # print(i, j)
                # print(j, 0)
                if board[i][j] in mySet:
                    # print('in row', i, j, board[i][j])
                    ans = False
                    break
                if board[j][i] in mySet2:
                    # print('in col', j, i, board[j][i])
                    ans = False
                    break

                if board[i][j]!='.':
                    mySet.add(board[i][j])
                if board[j][i]!='.':
                    # print(j, i)
                    mySet2.add(board[j][i])

            if ans==False:
                break
            # mySet.clear()
            # mySet2.clear()
        

        if ans != True:
            return ans
        
        i = 0
        while(i<9):
            j = 0
            
            while(j<9):
                mySet = set()
                print (i, j, ans)

                # first row
                if board[i][j] not in mySet:
                    if board[i][j]!='.': mySet.add(board[i][j])
                else: ans=False

                if board[i][j+1] not in mySet:
                    if board[i][j+1]!='.': mySet.add(board[i][j+1])
                else: ans=False

                if board[i][j+2] not in mySet:
                    if board[i][j+2]!='.': mySet.add(board[i][j+2])
                else: ans=False

                # second row
                if board[i+1][j] not in mySet:
                    if board[i+1][j]!='.': mySet.add(board[i+1][j])
                else: ans=False

                if board[i+1][j+1] not in mySet:
                    if board[i+1][j+1]!='.': mySet.add(board[i+1][j+1])
                else: ans=False

                if board[i+1][j+2] not in mySet:
                    if board[i+1][j+2]!='.': mySet.add(board[i+1][j+2])
                else: ans=False

                # second row
                if board[i+2][j] not in mySet:
                    if board[i+2][j]!='.': mySet.add(board[i+2][j])
                else: ans=False

                if board[i+2][j+1] not in mySet:
                    if board[i+2][j+1]!='.': mySet.add(board[i+2][j+1])
                else: ans=False

                if board[i+2][j+2] not in mySet:
                    if board[i+2][j+2]!='.': mySet.add(board[i+2][j+2])
                else: ans=False


                

                if ans == False:break
                j+=3
            if ans == False:break
            i+=3

        return ans
        