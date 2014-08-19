""" 
    
    Problem: You are given two files, one contains a list of 
    names (names.txt) and the other a list of phone numbers (numbers.txt). 
    Your boss needs a single CSV file that can be loaded into excel.

    Your task is to combine both txt files into one CSV file. 

    The first and last names need to be in separate columns
    and the phone number must be in the format (555)555-5555

    One row in the csv file might look like this:

    Smith,John,(555)555-5555

"""
""" 
Assumption: Names file and numbers file have the same number of entries and a line 
from a given file corresponds to the same line in the other file for each entry. 
"""


names = [] # a blank list to hold list of names
numbers = [] # blank list to hold list of numbers

# Open names.txt as "Readable"
with open('names.txt', 'r') as namesfile:
    for line in namesfile: # iterate through each line in names file
        names.append(line.rstrip().split()) # append line to names list

with open('numbers.txt', 'r') as numbersfile:
    for line in numbersfile: # iterate through each line in numbers file
        numbers.append(line.rstrip().split(".")) # append line to numbers list


# Creates a new file "output.csv" that you can write
with open('output.csv', 'w') as csvfile:
    for i in range(len(names)):
        line = '{},{},({}){}-{}\n'.format(names[i][1], names[i][0], numbers[i][0], numbers[i][1], numbers[i][2])
        csvfile.write(line)