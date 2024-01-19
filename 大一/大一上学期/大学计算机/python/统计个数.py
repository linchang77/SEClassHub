s=input("请输入一个字符串：")
sum=0
for i in range(0,len(s)):
    if "a"<=s[i]<="z" or "A"<=s[i]<="Z":
        sum=sum+1
print(sum)
    