x=['1','2','3','4','5']
y=['garry','aron','mike','mani']
xint=[1,2,3,4,5]

print("integer list as string:",x)

print("integer list as numbers",xint)
# copy function
add=x.copy()+y.copy()
print("x",x)
print("y",y)
print("\naddition: add=x+y",add)
#append
y.append("math")
print("appending \"math\" into list Y:",y)
print("\n")
print("X:",x)
#clear
x=x.clear()
print("clear() forlist of X:",x)
print("\n")
fruit=["mango","mango","mango","apple","banannan"]
x=['1','2','3','4','5']
y=['garry','aron','mike','mani']
#count
print("fruit:",fruit)
print("count of mango  in fruit:",fruit.count("mango"))
news =["1","2","3","4"]
print("\n")
#extend func
y.extend(news)
print("extend() news with Y:: ",y)
print(y)

#insert
print("\n")
print(y)
y.insert(2,"lokesh")
print("insert lokesh into Y",y)

#sort
print("\n")
print("list of Y:",y)
y.sort()
print("sorted Y",y)
print("\n")

#reverse:
print("list of Y ",y)
y.reverse()
print("reverse of Y:",y)


