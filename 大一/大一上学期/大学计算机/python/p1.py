n=eval(input("请输入n的值： "))
i=1
t=1
sum=0
while t<=8 :
    sum=sum+1/(i*(i+1))
    i=i+2
    t=t+1
print("n的值为",n)
print("sum=",sum)
    