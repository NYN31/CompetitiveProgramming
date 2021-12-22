### Question 01:

Write a program which will find all such numbers which are divisible by 7 but are not a multiple of 5, between 1 and 1000 (both included).

The numbers obtained should be printed in a comma-separated sequence on a single line.

Solution:

lo = 1
hi = 1000

for x in range(lo, hi + 1) :
    if x % 7 == 0 and x % 5 != 0:
        print(x, end=',')

Solution:

lo = 1
hi = 1000

l=[]
for i in range(lo, hi + 1):
    if (i%7==0) and (i%5!=0):
        l.append(str(i))

print(','.join(l))


### Question 02:

Question: Write a program which can compute the factorial of a given numbers

Input: 5
Output: 120

Input: 10

Output: 3628800

solution:

def factorial(x):
    if x == 0:
        return 1;
    return x * factorial(x - 1)

x = int(input('Enter a number: '))
print(factorial(x))


### Question 03:

With a given integral number n, write a program to generate a dictionary that contains (key, value) = (i, i*i) such that is an integral number between 1 and n (both included) and then the program should print the dictionary.

Input: 5

Output: {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}

solution:

n = int(input())
dictonary = {}
for i in range(1, n + 1):
    dictonary[i] = i * i;
print(dictonary)


### Question 04:

Write a program which accepts a sequence of comma-separated numbers from console and generate a list and a tuple which contains every number.

Input: 1, 2, 3, 4, 5, 6

output:

{1, 2, 3, 4, 5, 6}

(1, 2, 3, 4, 5, 6)

solution:

values=input()
l=values.split(", ")
t=tuple(l)
print(l)
print(t)


### Question 05:

Write a program that calculates and prints the value according to the given formula:

E = Square root of [(2 * A * B)/C]; A = 10, C = 12. B will be console input.
You are also given a list of number which are B with comma-separated sequence.

print the answer with comma-separated sequence.

Input: 10,19,21
Output: 4,6,6

Solution:

import math

A = 10
C = 12
ans = []
B_list = list(map(int, input().split(',')))
for B in B_list:
    b = str(int(round(math.sqrt((2.0 * A * B) / C))))
    ans.append(b)
print(','.join(ans))


### Question 06:

You are given two number n and m. You have to made a 2D matrix where each index contains the multiple of i*j, where i means row number and j means column numbers. 

constraints: 0 ≤ i ≤ n, 0 ≤ j ≤ m

Solution:
n, m = map(int, input("Enter the value of n & m: ").split())
matrix = [[0 for col in range(m)] for row in range(n)]

for row in range(0, n):
    for col in range(0, m):
        matrix[row][col] = row * col

for i in range(0, n):
    for j in range(0, m):
        print(matrix[i][j], end=' ')
    print()

# Another solution:

rows, cols = map(int, input("Enter the value of n & m: ").split())
row = []

for i in range(rows):
    col = []
    for j in range(cols):
        col.append(i * j)
    row.append(col)
for i in range(rows):
    print(row[i])


### Question 07:

Write a program that accepts a comma separated sequence of words as input and prints the words in a comma-separated sequence after sorting them alphabetically.

Solution:
words = list(map(str, input("Enter words: ").split(',')))
words.sort()
print(','.join(words))


### Question 08:

Write a program that accepts sequence of lines as input and prints the lines after making all characters in the sentence capitalized.

Solution:
lines = []
while True:
    print(f"If you want to break, press only b: ", end='')
    line = input()
    if line == "b": break ;
    else: lines.append(line.upper())
for line in lines:
    print(line)
```

### Question 9:

Write a program that accepts a sequence of whitespace separated words as input and prints the words after removing all duplicate words and sort them alphanumerically.

Solution:
words = list(map(str, input().split()))
uniques = []
for word in words:
    if word not in uniques:
        uniques.append(word)
uniques.sort()
for unique_word in uniques:
    print(unique_word, end=' ')

Another way:

words = list(map(str, input("> ").split()))
print(" ".join(sorted(list(set(words))))
```

### Question 10:

Write a program which accepts a sequence of comma separated 4 digit binary numbers as its input and then check whether the decimal of the binary numbers are divisible by 5 or not. The numbers that are divisible by 5 are to be printed in a comma separated sequence.

Solution:
answer = []
numbers_in_binary = [x for x in input().split(',')]
for number in numbers_in_binary:
    decimal_of_binary_number = int(number, 2)
    if not decimal_of_binary_number % 5:
        answer.append(number)

print(','.join(answer))
```

### Question 11:

Write a program, which will find all numbers between 100 and 300 (both included) such that each digit of the number is an even number.

The numbers obtained should be printed in a comma-separated sequence on a single line.

Solution:
even = []
lo = 100
hi = 301

for number in range(lo, hi):
    number = str(number)
    a = int(number[0]) % 2 == 0
    b = int(number[1]) % 2 == 0
    c = int(number[2]) % 2 == 0
    if a and b and c:
        even.append(number)

print(','.join(even))
```

### Question 12:

Write a program that accepts a sentence and calculate the number of letters and digits.

Solution:
sequence = input("Enter a sequence: ")
letters = 0
digits = 0

for ch in sequence:
    if ch.isalpha():
        letters += 1 ;
    elif ch.isdigit():
        digits += 1;

print(f"Letters: {letters} \nDigits: {digits}")
```

### Question 13:

Write a program that accepts a sentence and calculate the number of upper case and lower case letters.

Solution:
sequence = input("Enter a sequence: ")
upper_case = 0
lower_case = 0

for ch in sequence:
    if ch.isupper():
        upper_case += 1 ;
    elif ch.islower():
        lower_case += 1;

print(f"UpperCase: {upper_case} \nLowerCase: {lower_case}")
```

### Question 14:

Write a program that computes the value of a + aa + aaa + aaaa with a given digit as the value of a.

Solution:
a = input()
n1 = int( "%s" % a )
n2 = int( "%s%s" % (a, a) )
n3 = int( "%s%s%s" % (a, a, a) )
n4 = int( "%s%s%s%s" % (a, a, a, a) )
print(n1 + n2 + n3 + n4)
```

### Question 15:

Write a program that computes the net amount of a bank account based a transaction log from console input. The transaction log format is shown as following:

D 100

W 200

D means deposit while W means withdrawal.

Input:

D 300

D 300

W 200

D 100

Output:

Net amount: 500

Solution:
netAmount = 0

while True:
    operation = input("Enter a empty string or write quit")
    if operation.lower == 'quit' or len(operation) == 0 or not operation:
        break;
    a, b = operation.split(' ')
    b = int(b)

    if a == "D":
        netAmount += b
    elif a == "W":
        netAmount -= b
print(f"Net amound {netAmount}")
```

### Question 16:

You are required to write a program to sort the (name, age, height) tuples by ascending order where name is string, age and height are numbers. The tuples are input by console. The sort criteria is:

1: Sort based on name;

2: Then sort based on age;

3: Then sort by score.

The priority is that: name > age > score.

Input:

Tom 19 80

John 20 90

Jony 17 91

Jony 17 93

Json 21 85

Output:

[('John', '20', '90'), ('Jony', '17', '91'), ('Jony', '17', '93'), ('Json', '21', '85'), ('Tom', '19', '80')]

Solution:
from operator import itemgetter

all_tuple = []

while True:
    operation = input()
    if len(operation) == 0:
        break
    name, age, height = operation.split(',')
    age = int(age)
    height = int(height)

    all_tuple.append((name, age, height))

# print(all_tuple)
print(sorted(all_tuple, key=itemgetter(0, 1, 2)))
```

### Question 17:

Write a program to compute the frequency of the words from the console input. Then sort the key alphanumerically and print key with frequency.

Suppose the following input is supplied to the program:

New to Python or choosing between Python 2 and Python 3? Read Python 2 or Python 3.

Then, the output should be:

2: 2

3.: 1

3?: 1

New: 1

Python: 5

Read: 1

and: 1

between: 1

choosing: 1

or: 2

to: 1

Solution:
frequency = {}

line = input().split(' ')
for word in line:
    frequency[word] = frequency.get(word, 0) + 1
words = list(frequency.keys())
words.sort()

for word in words:
    print("%s: %d" % (word, frequency[word]))
```

### Question 18:

Write a method which can calculate square value of number.

Solution:
def square(num):
    return num ** 2

num = int(input("Enter a number: "))
print(square(num))
```

### Question 19:

Define a class, which have a class parameter and have a same instance parameter.

Solution:
class Person:
    # Define the class parameter "name"
    name = "Person"

    def __init__(self, name = None):
        # self.name is the instance parameter
        self.name = name

jeffrey = Person("Jeffrey")
print("%s name is %s" % (Person.name, jeffrey.name))

nico = Person()
nico.name = "Nico"
print("%s name is %s" % (Person.name, nico.name))
```

### Question 20:

Define a function that can receive two numbers in string form and compute their sum and then print it in console.

Solution:
def print_sum(num1, num2):
    print(int(num1) + int(num2))

print_sum("3","4")
```

### Question 21:

Define a function that can accept two strings as input and print the string with maximum length in console. If two strings have the same length, then the function should print both strings.

Solution:
def check_string(s1, s2):
    len1 = len(s1)
    len2 = len(s2)

    if len1 > len2:
        print(f"{s1} is greater length than {s2}")
    elif len2 > len1:
        print(f"{s2} is greater length than {s1}")
    else:
        print(f"Both {s1} and {s2} are equal length")

check_string("noyon", "sajjad")
check_string("karim", "rahim")
```

### Question 22:

Define a function that can accept an integer number as input and print "It is an even number" if the number is even, otherwise print "It is an odd number".

Solution:
def check_odd_even(num):
    if num & 1:  # can check with num % 2 == 1 also
        print(f"{num} is odd number")
    else:
        print(f"{num} is even number")

check_odd_even(5)
check_odd_even(8)

# not num & 1 => means => not odd
# num % 2 == 1 => means => odd
# num % 2 == 0 => means => even
```

### Question 23:

Define a function which can generate a dictionary where the keys are numbers between 1 and 20 (both included) and the values are square of keys. The function should print the keys and values separately.

Solution:
def square_dictionary():
    dictionary = {}
    for i in range(1, 21):
        dictionary[i] = dictionary.get(i, i**2)

    all_keys = []
    all_values = []
    for key in dictionary.keys():
        all_keys.append(key)

    for (key, value) in dictionary.items():
        all_values.append(value)

    print(f"All Keys: {all_keys}")
    print(f"All Values: {all_values}")
    #for key in all_keys:
    #    print(dictionary[key], end=' ')

square_dictionary()
```

### Question 24:

Define a function which can generate a list where the values are prime number between 1 and 50 (both included). Then the function needs to print:

1. The first 5 primes in the list.
2. The last 5 primes in the list.
3. All values except the first 5 primes in the list.

Solution:
import math

def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def list_of_prime(hi):
    prime_list = []
    for num in range(1, hi + 1):
        if is_prime(num):
            prime_list.append(num)
    return prime_list

all_primes = list_of_prime(50)
print(f"All primes are: {all_primes}")
print(f"The first 5 primes are: {all_primes[:5]}")
print(f"The last 5 primes are: {all_primes[-5:]}")
print(f"All values except the first 5 primes are: {all_primes[5:]}")
```

### Question 25:

Define a function which can generate a tuple of fibonacci number between 1 and 20 (both included). Then the function needs to print:

1. The first 5 primes in the tuple.
2. The last 5 primes in the tuple.
3. All values except the first 5 primes in the tuple.

Solution:
def tuple_of_fibonacci(hi):
    fibonacci_list = [0, 1, 1] # first three numbers of Fibonacci list
    for i in range(3, hi + 1):
        fibonacci_list.append(fibonacci_list[i - 1] + fibonacci_list[i - 2])
    return tuple(fibonacci_list)

all_fibonacci = tuple_of_fibonacci(20)
print(f"All fibonacci are: {all_fibonacci}")
print(f"The first 5 fibonacci are: {all_fibonacci[:5]}")
print(f"The last 5 fibonacci are: {all_fibonacci[-5:]}")
print(f"All values except the first 5 fibonacci are: {all_fibonacci[5:]}")
```

### Question 26:

Write a program which can filter even and odd numbers in a list by using filter function separately.

Solution:
def fun(var):
    if var % 2 == 0:
        return True
    else:
        return False

numbers = []
for i in range(20):
    numbers.append(i)

print(numbers) # All numbers from 1 to 20 are printed
result1 = filter(lambda x: x & 1, numbers) # using lamda function filtering even number
print(list(result1))
result2 = filter(fun, numbers) # using regular function filtering odd number
print(list(result2))
```

### Question 27:

Write a program which can map() to make a list whose elements are square.

Solution:
li = list(map(int, input('Enter a list: ').split()))
squaredNumbers = map(lambda x: x**2, li)
print(f"Answer: {list(squaredNumbers)}")
```

### Question 28:

Write a program which can map() and filter() to make a list whose elements are square of even number.

Solution:
li = list(map(int, input('Enter a list: ').split()))
squaredNumbers = map(lambda x: x**2, filter(lambda x: x % 2 == 0, li))
print(list(squaredNumbers))
```

### Question 29:

Define a class which has at least two methods:

getString: to get a string from console input

printString: to print the string in upper case.

Solution:
class InputOutputString(object):
    def __init__(self):
        self.s = ""

    def getString(self):
        self.s = input()

    def printString(self):
        print(self.s.upper())

strObj = InputOutputString()
strObj.getString()
strObj.printString()
```

### Question 30

Define a class named American which has a static method called printNationality.

Solution:
class American(object):
    @staticmethod
    def printNationality():
        print("America")

american = American()
american.printNationality()
American.printNationality()
```

### Question 31

Define a class named Circle which can be constructed by a radius. The Circle class has a method which can compute the area.

Solution:
class Circle(object):
    def __init__(self, r):
        self.radius = r

    def area(self):
        return 3.14 * self.radius**2

circle = Circle(3)
print circle.area()
```

### Question 32

Define a class named Rectangle which can be constructed by a length and width. The Rectangle class has a method which can compute the area.

Solution:
class Rectangle(object):
    def __init__(self, length, width):
        self.length = length
        self.width  = width

    def area(self):
        return self.length*self.width

rectangle = Rectangle(2,10)
print(rectangle.area())
```

### Question 33

Define a class named Shape and its subclass Square. The Square class has an init function which takes a length as argument. Both classes have a area function which can print the area of the shape where Shape's area is 0 by default.

Solution:
class Shape(object):
    def __init__(self):
        pass

    def area(self):
        return 0

class Square(Shape):
    def __init__(self, l):
        Shape.__init__(self)
        self.length = l

    def area(self):
        return self.length * self.length

square= Square(3)
print(square.area())
```

### Question 34

You are given n. Write a program which compute 1/1+1/2+1/3+...+1/n, where (n > 0)

Solution:
n=int(input())
sum=0.0
for i in range(1, n+1):
    sum += float(1.0 / i)
print(sum)
```

### Question 35:

Write a program to compute:

f(n) = f(n - 1) + 100 when n>0

and f(0) = 1

Solution:
def f(n):
    if n == 0: return 0
    else: return f(n - 1) + 100

n=int(input())
print(f(n))
```

### Question 36:

The Fibonacci Sequence is computed based on the following formula:

f(n)=0 if n=0,

f(n)=1 if n=1,

and f(n)=f(n-1)+f(n-2) if n>1,

Please write a program using list comprehension to print the Fibonacci Sequence in comma separated form with a given n input by console.

Example:If the following n is given as input to the program:

7

Then, the output of the program should be:

0,1,1,2,3,5,8,13

Solution:
def f(n):
    if n == 0: return 0
    elif n == 1: return 1
    else: return f(n-1)+f(n-2)

n=int(input())
values = [str(f(x)) for x in range(0, n+1)]
print(",".join(values))
```

### Question 37

Please write assert statements to verify that every number in the list [2,4,6,8] is even.

Solution:
li = [2,4,6,8]
for i in li:
    assert i%2==0
```

### Question 38:

Please write a program which accepts basic mathematic expression from console and print the evaluation result.

Input: 2 + (7 - 1) * 5 - 4

Output: 28

Solution:
expression = input()
print(eval(expression))
```

### Question 39:

Please write a binary search function which searches an item in a sorted list. The function should return the index of element to be searched in the list.

Solution:
import math

def binary_search(_arr, element):
    lo = 0
    hi = len(_arr) - 1
    index = -1

    while lo <= hi:
        mid = lo + int(math.floor((hi - lo) / 2.0))
        if _arr[mid] == element:
            index = mid
            break
        elif _arr[mid] > element:
            hi = mid - 1
        else:
            lo = mid + 1

    return index

arr = list(map(int, input('Enter a list of numbers: ').split()))
print(binary_search(arr, 11))
print(binary_search(arr, 20))
```

### Question 40:

Please write a program to output a random even number between 0 and 10 inclusive using random module and list comprehension.

Solution:
import random
print(random.choice([i for i in range(11) if i % 2 == 0]))
```

### Question 41:

Please write a program to output a random number, which is divisible by 5 and 7, between 0 and 100 inclusive using random module and list comprehension.

Solution:
import random
print(random.choice([i for i in range(101) if i % 5 == 0 and i % 7 == 0]))
```

### Question 42:

Please write a program to generate a list with 5 even random numbers between 100 and 200 inclusive.

Solution:
import random
print(random.sample([i for i in range(100, 200) if i % 2 == 0], 5))
```

### Question 43:

Please write a program to randomly print a integer number between 7 and 15 inclusive.

Solution:
import random
print(random.randrange(1, 100))
```

### Question 44:

With a given list [12,24,35,24,88,120,155,88,120,155], write a program to print this list after removing all duplicate values with original order reserved.

Solution:
def removeDuplicate(li):
    newli = []
    seen = set()
    for item in li:
        if item not in seen:
            seen.add( item )
            newli.append(item)

    return newli[::-1]

li=[12,24,35,24,88,120,155,88,120,155]
print(removeDuplicate(li))
```


### Question 45:

By using list comprehension, please write a program generate a (2 * 4 * 3) 3D array whose each element is 0.

Solution:
array = [[ [0 for col in range(2)] for col in range(4)] for row in range(3)]
print(array)
```

### Question 46:

You are given a list of tuples and tuples contains two information which are movie name and year of release. You have to find out which movie were release before 2001 year with release year.

Solution:
movies = [('A', 2000), ('B', 2001), ('C', 1997), ('D', 1987), ('E', 1985), ('F', 2005),
          ('G', 2004), ('H', 2011), ('I', 1999), ('J', 1991)]

required_movies = [(title, year) for (title, year) in movies if year <= 2000]
print(required_movies)
```

### Question 47:

You are given two lists each of them contain distinct integer. One list contain just even numbers and another contain odd numbers. You have to find out all possible pair from this two lists such that no pair contains both elements from same list.

Solution:
A = [1, 3, 5, 7]
B = [2, 4, 6, 8]

all_pairs = [(a, b) for a in A for b in B]
print(all_pairs)
```

### Question 48:

Find n'th Fibonacci number using recursion.

Solution:
def fib(n):
    if n <= 1: return 0
    elif n == 2: return 1
    return fib(n - 1) + fib(n - 2)

t = int(input('Enter test case: '))
while t > 0:
    n = int(input('Enter a number: '))
    if n == 0:
        print('Enter the value of n greater than 0.')
        continue
    print(f"{n}'th Fibonacci number is {fib(n)}")
    t -= 1
```

### Question 49:

Find n'th factorial number using recursion.

Solution:
def fact(n):
    if n == 0: return 1
    return n * fact(n - 1)

t = int(input('Enter test case: '))
while t > 0:
    n = int(input('Enter a number: '))
    print(f"{n}'th factorial number is: {fact(n)}")
    t -= 1
```