# from math import * 

# print("hello world!")
# name="natiq"
# age="20"
# print("age of "+name+ "is "+age)
# print(len(name))
# print(name.upper()) 
# a=int(input("enter first number: "))
# b=int(input("enter second number: "))
# sum=a+b;
# print("sum of your numbers is: ",sum)
# color=input("Enter color: ")
# plural_noun=input("Enter Noun: ")
# celebrity=input("celebrity name: ")
# print("roses are "+color)
# print(plural_noun+" are blue")
# print("I love "+celebrity)
# friends =['babar','babi ','nats']
# print(friends)
# friends =("babar","nats")
# print(friends)

#functions in python

# def say_hi(name):
#     print("say hi "+name)

# print("top ")
# say_hi("nats")
# print(" Bottom")
# def sum(a,b):
#     sum=a+b
#     return sum

# print(sum(10,20))
# a = int(input("enter your choice num"))

# if a == 1:
#     print("you are hungry")
# elif a == 2:
#     print("you are gay")
# else:
#     print("fuck off")
# def largest(a,b,c):
#     if a>b and b>c:
#         print("a is the largest")
#     elif b>a and b>c:
#         print(" b is the largest")
#     else:
#         print(" c is the largest")        

# largest(10,20,30)

#dictionaries
 
# monthcoversion ={
#     "Jan":"January",
#     "Feb":"Febraury",
#     "Mar":"March",
#     "Apr":"April",
#     "May":"May"

# }
# print(monthcoversion["Mar"])

# print(monthcoversion.get("Luv","Not a valid key"))
# a=10
# i=0
# while i<=a :
#     print(i)
#     i+=1

#guessing game
# num=100
# a=int(input("Enter the number: "))
# while a!=num:
#     print("the number you entered is incorrect: ")
#     a=int(input("Enter your number again: "))

# print(" you guessed the right number bingo")
# a=[10,20,30,40]
# for x in a:
#     print(x)

# def raisedtopower(base,exponent):
#     original=base
    
#     if exponent==0:
#         return 1

#     for index in range(exponent-1):
#         base*=original
#     return base    
        
# print(raisedtopower(2,8))

# def changeword(a):
#     result=""
#     for x in a:
#         if x=="a" or x=="e" or x=="i" or x=="o" or x=="u":
#             result+="g"
#         else:
#             result+=x    
#     return result     

# print(changeword("giraffe"))
# employee_file=open("Python/codecamp/text.txt","r")
# print(employee_file.readable())
# # print(employee_file.readlines()[1])
# for employee in employee_file:
#     print(employee)



# employee_file.close()

# employee_file=open("Python/codecamp/text.txt","r")
# employee_file=open("Python/codecamp/text.txt","a")
# employee_file.write("\n Kelly-Bosdu")

class student:

    def __init__(self,name,id,course):
        self.name=name
        self.id=id
        self.course=course

student1=student("natiq",10,"Information technoloy")

print(student1.course)
print(student1.name)




