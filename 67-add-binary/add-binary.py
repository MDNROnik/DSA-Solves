class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # minLength = min(len(a), len(b))
        a = a[::-1]
        b = b[::-1]
        carry = 0
        newString = ""
        i = 0

        # For Two Array
        for index in range ( min(len(a), len(b)) ) :
            
            if a[index]=='1' and b[index]=='1':
                if carry == 1:
                    newString = newString + '1'
                else:
                    newString = newString + '0'
                    carry = 1
            elif (a[index]=='1' and b[index]=='0') or (a[index]=='0' and b[index]=='1'):
                if carry == 1:
                    newString = newString + '0'
                    carry = 1
                else:
                    newString = newString + '1'
            else:
                if carry==1:
                    newString = newString + '1'
                    carry = 0
                else:
                    newString = newString + '0'
            i = i+1
            

        print (newString)
        for index in range(i, len(a)):
           if a[index]=='1':
                if carry == 1:
                    newString = newString + '0'
                    carry = 1
                else:
                    newString = newString + '1'
           else:
                if carry == 1:
                    newString = newString + '1'
                    carry = 0
                else:
                    newString = newString + '0'
        print (newString)
        for index in range(i, len(b)):
           if b[index]=='1':
                if carry == 1:
                    newString = newString + '0'
                    carry = 1
                else:
                    newString = newString + '1'
           else:
                if carry == 1:
                    newString = newString + '1'
                    carry = 0
                else:
                    newString = newString + '0'
        print (newString)
        if carry == 1:
            newString = newString + '1'
        
        newString = newString[::-1]
        return newString
        