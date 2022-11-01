import string

# ---------------------------------------
# CSCI 127, Joy and Beauty of Data      |
# Program 4: Presidents                 |
# Your Name(, Your Partner's Name)      |
# Last Modified: Month __, 20__         |
# ---------------------------------------
# A brief overview of the program.
# ---------------------------------------

# Your solution goes here ...
    
# ---------------------------------------

def print_menu():
    print ("""
1. Print all presidents
2. Print president by name
3. Print president by number
4. Count presidents with occupation
5. Print average term length
6. Quit
    """)
# ---------------------------------------

def print_all_presidents(pres_listing):
    for president in pres_listing:
        print(president)

# ---------------------------------------
# Class properly initilized and with get methods for each piece of information.
class President():
    def __init__(self, first, last, number, start, term, occupations):
        self.first = first
        self.last = last
        self.number = str(number)
        self.start = str(start)
        self.term = term
        self.occupations = occupations
        self.name = first + " " + last
    def get_name(self):
        return self.name
    def get_number(self):
        return self.number
    def get_occupation(self):
        return self.occupations
    def get_time_in_office(self):
        return self.term
    def __str__(self):
        return("No. " + self.number + " (" + self.start + ") " + self.name)

# ---------------------------------------
#Prints the presidents info based on an input name, and asks for another input if the input is too short.
def print_by_name(pres_listing, name):
    count = 0
    if len(name) < 3:
        new_name = input("Please enter a string containing atleast 3 characters: ")
        print_by_name(pres_listing, new_name)
    else:
        for pres in pres_listing:
            if (name.lower()) in ((pres.get_name()).lower()):
                print(pres)
                count += 1
            else: 
                pass
        if count == 0:
            print("No president's name contains '" + name + "'")
        else:
            pass

# ---------------------------------------
# Prints the president's by their number, and asks for another input if the input is outside of the range of valid inputs.    
def print_by_number(pres_listing, number):
    count = 0
    for president in pres_listing:
        if int(president.get_number()) == number:
            print(president)
            count += 1
        else:
            continue
    if count == 0:
        print("\nPresident number must be between 1 and 46")
    else:
        pass

# ---------------------------------------
# Prints the presidents by occupation, and makes sure only to count Grover Cleavland once.
def count_by_occupation(pres_listing, occupation):
    count = {}
    for president in pres_listing:
        if str(occupation) in str(president.get_occupation()):
            if str((president.get_name())) in count:
                count[str((president.get_name()))] += 1
            else:
                count[str((president.get_name()))] = 1
    if(len(count) > 0):
        pres_list = []
        print_count = 0
        for pres in count:
            pres_list += pres
            print_count += 1
            if print_count > 1:
                pres_list += ", "
            else:
                pass
        print(str(len(count)) + " " + occupation + " presidents: " + str("".join(pres_list)))

#---------------------------------------
# Adds up all the presidents term lengths, divides by the total number of presidents, and rounds to 1 decimal place to match the transcript.
def average_term_length(pres_listing):
    total = 0
    count = 0
    for president in pres_listing:
        total += president.get_time_in_office()
        count += 1
    average = total / count
    average = round(average, 1)
    print("Average term length, about " + str(average) + "years.")

# ---------------------------------------
# Do not change anything below this line
# ---------------------------------------

def create_pres_listing(filename):
    pres_listing = []
    file = open(filename, "r")
    
    for president in file:
        presilist = president.strip().split(",")
        number = int(presilist[0])               # number
        last = presilist[1]                      # last name
        first = presilist[2]                     # first name
        start_in = int(presilist[3])             # first year in office
        term = float(presilist[4])               # years in office
        occupations = []
        for position in range(5, len(presilist)):
            occupations += [presilist[position]] # occupation
        pres_listing += [President(first, last, number, start_in, term, occupations)]

    file.close()
    return pres_listing

# ---------------------------------------

def get_choice(low, high, message):
    
    legal_choice = False
    answer = input(message)
    while answer == "":
        answer = input(message)
    for char in answer:
        if char not in string.digits:
            print('ERROR: ', answer, "is not a number")
            return 0
    answer = int(answer)
    if (low > answer) or (answer > high):
        print('ERROR: ', answer, "is not a choice")
        return 0

    return answer

# ---------------------------------------

def main():
    pres_listing = create_pres_listing("pres_listing.txt")
    choice = 0
    while choice != 6:
        print_menu()
        choice = get_choice(1, 6, "Enter a menu option: ")
        if choice == 1:    
            print_all_presidents(pres_listing)
        elif choice == 2:
            name = input("Enter a president name: ").lower()
            print_by_name(pres_listing, name)
        elif choice == 3:
            number = get_choice(1, 46, "Enter a president number: ")
            print_by_number(pres_listing, number)
        elif choice == 4:
            occupation = input("Enter a president occupation: ").lower()
            count_by_occupation(pres_listing, occupation)
        elif choice == 5:
            average_term_length(pres_listing)
        elif choice == 6:
            print("Thank you.  Goodbye!")

# ---------------------------------------

main()
