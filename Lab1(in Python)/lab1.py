#CIS 22C Lab1 - Iteration vs Recursion
#Ali Halmamat
#The purpose of this assignment is to show the difference between iterative approach and recursive apprach to a problem 

# function ro check for the prime number Iterative version
#this Iteration functions takes in 2 parameters, the array list, and the length of that array list
#then it loops thru each element in the array 
# and it uses the helper function to check if each element in the array is a prime number
#Note, the nested loop is inside the helper function
#if it is then we increase the count of prime number by 1
#if the count of prime number is equal to the length of array,
#then that means all numbers inside that array list is a prime number, so the entire list is prime 
#otherwise, it means one or more nums in the list is not prime, therefore the list is not prime
#return boolean in those conditions
def IsArrayPrimeIter(arr, le):
    #print out the function name after calling the function
    print("Entering IsArrayPrimeIter")
    count = 0
    for i in arr:
        if(isPrime(i)):
            count = count+1
    if(count == le):
        #print leaving statement in both conditions, print it before return out of the function
        print("Leaving IsArrayPrimeIter")
        return True
    else:
        #print leaving statement in both conditions, print it before return out of the function
        print("Leaving IsArrayPrimeIter")
        return False
# Helper function for iterative approach
#this helper function uses conditioning and math logic to determine if the inputs that's passed in is prime or not
def isPrime(n):
    if n <= 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

# function ro check for the prime number Recursive version
#this function has no for loop involved
#this function will recursively call itself and uses the helped function to determine if the input is prime
#this function will -1 from the lenth (le) everytime it finds the element to be prime
#if the length (le) equals to 0 that means all integer elements inside the array was prime
#otherwise it will return false
def IsArrayPrimeRecur(arr, le):
    #print out the function name after calling the function
    print("Entering IsArrayPrimeRecur")
    if(le == 0):
        print("Leaving IsArrayPrimeRecur")
        return True
    if(IsPrimeRecur(arr[le - 1])):
        return IsArrayPrimeRecur(arr, le - 1)
    print("Leaving IsArrayPrimeRecur")
    return False

#Helper funtion for the recursive function
#this helper function uses conditioning and math logic to determine if the inputs that's passed in is prime or not
def IsPrimeRecur(n, i=2):
    if (n <= 2):
        return True if(n == 2) else False
    if (n % i == 0):
        return False
    if (i * i > n):
        return True
    return IsPrimeRecur(n, i + 1)


# List to store values
list = []
i = 1

# input taking
n = int(input("Enter size of an Array"))
print("Please enter your input data on one line only.")
#this while loop will take input depends on the size of the array
while(i <= n):
    input_value = int(input("Enter number"))
    #I set the max value to be 9999 
    if(input_value >= 1 and input_value <= 9999):
        #add integers to the array list with append method
        list.append(input_value)
    else:
        print("please enter valid input between 1 and 9999")
        i = i-1
    #increment this i counter before exiting the while loop
    i = i+1
# Final list after validation
print("Array List", list)

if IsArrayPrimeIter(list, len(list)):
    print("Array was found to be prime using iteration")
else:
    print("Not a Prime Array using iteration")

if IsArrayPrimeRecur(list, len(list)):
    print("Array was found to be prime using recursion")
else:
    print("Not a Prime Array using recursion")
