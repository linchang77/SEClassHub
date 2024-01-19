p=eval(input("the money you had used:"))
if p<1000:
    a=p
elif 1000<=p<2000:
    a=0.9*p
elif 2000<=p<3000:
    a=0.8*p
elif 3000<=p:
    a=0.7*p
print("what you should actually pay is:",a)
    