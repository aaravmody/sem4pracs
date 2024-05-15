def twos(num):
    ones=''
    for i in num:
        if i=='1':
            ones+='0'
        else:
            ones+='1'
    return bin(int(ones,2)+int('1',2)).replace('0b','')

num1=int(input("Enter num1: "))
num2=int(input("Enter num2: "))

binnum1=bin(abs(num1)).replace('0b','')
binnum2=bin(abs(num2)).replace('0b','')

print(binnum1,binnum2)

if len(binnum1)>len(binnum2):
    maxlen=len(binnum1)
else:
    maxlen=len(binnum2)

maxlen+=1
print(maxlen)

binnum1 = binnum1.zfill(maxlen)
binnum2 = binnum2.zfill(maxlen)

if(num1<0):
    binnum1=twos(binnum1)
if(num2<0):
    binnum2=twos(binnum2)

print(binnum2)

bincompnum1=twos(binnum1)
bincompnum1=bincompnum1.zfill(maxlen)

bincompnum2=twos(binnum1)
bincompnum2=bincompnum2.zfill(maxlen)

print(bincompnum2)

count=maxlen
q1='0'
a='0'
a = a.zfill(maxlen)
m = binnum1
minusm=bincompnum1
q=binnum2
print(q[maxlen-1])

rightshift=''
print('A    Q   Q-1')
print(a,q,q1)

while(count>0):
    if q[maxlen-1]=='0' and q1=='1':
        a=bin(int(a,2)+int(m,2)).replace('0b','')
        if (len(a)>maxlen):
            a=a[1:]
        a=a.zfill(maxlen)

    if(q[maxlen-1]=='1' and q1=='0'):
        a=bin(int(a,2)+int(minusm,2)).replace('0b','')
        if (len(a)>maxlen):
            a=a[1:]
        a=a.zfill(maxlen)

    merged = a+q+q1
    rightshift=merged[0]
    for i in range(maxlen-1):
        rightshift+=merged[i]

    a=rightshift[:maxlen]
    q=rightshift[maxlen:maxlen*2]
    q1=rightshift[-1]

    count-=1

    print(a,q,q1)


