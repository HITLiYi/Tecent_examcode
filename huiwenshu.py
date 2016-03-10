#coding:utf-8
__author__ = 'daged'
def ismirror(num):
    if not isinstance(num,int):
        return False
    if num<0:
        return False
    reversenum=0
    value=num
    while value>0:
        reversenum=reversenum*10+value%10
        value//=10
    return reversenum==num
if __name__=='__main__':
    n=int(input('输入需要判断的数'))
    print(ismirror(n))