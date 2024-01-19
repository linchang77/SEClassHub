# -*- coding: utf-8 -*-
"""
Created on Sat Dec  3 20:03:20 2022

@author: 86152
"""

import math
a=int(input("输入斜边："))
b=int(input("输入直角边："))
if a>b  :
    c=math.sqrt(a*a-b*b)
    print("另一条直角边=",c)
    l=a+b+c
    print("周长=",l)
    t=(a+b+c)/2
    s=math.sqrt(t*(t-a)*(t-b)*(t-c))
    print("面积=",s)
