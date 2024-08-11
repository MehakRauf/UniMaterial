# You have collected information about cities in your province. You decide to store each city’s
# name, population, and mayor in a file. Write a python program to accept the data for a number
# of cities from the keyboard and store the data in a file in the order in which they’re entered.

def store_data():
    n=int(input("Enter the number of cities: "))
    for i in range(n):
        f= open("city_data.txt","a")
        name = input("Enter city name: ")
        population = input("Enter city population: ")
        mayor = input("Enter mayor's name: ")

        f.write(f"{name},{population},{mayor}\n")
        f.close()
    print("City data has been stored in city_data.txt")

def read_data():
        f=open("city_data.txt","r")
        for line in f:
            city_info =line.strip().split(',')
            name = city_info[0]
            population = city_info[1]
            mayor = city_info[2]
            print(f"{name},{population},{mayor}")
        f.close()   
       
store_data()

read_data()
             