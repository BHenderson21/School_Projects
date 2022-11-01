# --------------------------------------
# CSCI 127, Program 3                  |
# Month 10, 2021                       |
# Brandon Henderson                    |
# --------------------------------------

# Average infection rate function. I have a little trick in the beginning to skip over the header line. There might be a method for this
# or somethint, but I remember using a trick like this in a class I took in high school so I applied it here (The if statement and 
# firstline bool). Then I split the line, using ," instead of just , in order to avoid the one comma in the middle of some of the countrys.
# I just noticed that every other comma was followed by a quote. Cleans up the lines removing the new line breaks and the quotes, adds
# the infection rate, keeps track of how many rates its added, then uses those two to calculate and return the average.
def ave_infection_rate(file):
    data = open(file, 'r')
    total = 0
    lines = 0
    firstline = True
    for line in data:
        if firstline == True:
            firstline = False
            continue
        else:
            line = line.split(',"')
            line[9] = line[9].replace("\n", "")
            line[9] = line[9].replace('"', "")
            total += float(line[9])
            lines += 1
    return(float(total/lines))

# Countries in study file save function. Skip the first line the same way as the last one. Clean up line indexes 3 and 7.
# Make a dictionary of each country (once) and their populations.
def countries_in_study(file, save):
    data = open(file, 'r')
    countries = {}
    firstline = True
    for line in data:
        if firstline == True:
            firstline = False
        else:
                line = line.split(',"')
                line[3] = line[3].replace('"', "")
                line[7] = line[7].replace('"', "")
                if (str(line[5]) in countries):
                    continue
                else:
                    countries[str(line[5])] = int(line[7])
# For this line, I wanted to take my newly created countries dictionary and sort it by values.
# I tried every way I knew on my own, but kept getting a list of only the values. I did some digging in the doccumentation, here:
# https://docs.python.org/3/howto/sorting.html and found the sorted function, and the "key" and "reverse" arguments it takes,
# and saw that it did what I needed. If this is considered cheating, this was not my intention. I just remember we talked about
# using documentation in class so I figured it was something I could do here. I'm explaining this here to say that if any of my
# practices in doing this were wrong I am 100% open to and would like to learn how to better go about this.
    countriesSorted = sorted(countries.items(), key=lambda x:x[1], reverse=1)
    saved = open(save, 'w')
    rank = 0
    # Exclude negatives, print each line with a incrimenting rank, country name, and population, all justified correctly.
    # *I had a weird bug here where the countrys with 4 letter names had their populations moved over 1 space that I could not
    # figure out.
    for country in countriesSorted:
        if "-" in str(country[1]):
            continue
        else:
            rank += 1
            saved.write(str(rank).ljust(5) + (str(country[0]).replace('"', "")).replace("_", " ").ljust(5) + str(country[1]).rjust((50-len(country[0]))) +  "\n")
# Deaths in country function. Works the same way as the average infection rate function, but just returns the total and doesn't average.
def deaths_in_country(file, country):
    data = open(file, 'r')
    deaths = 0
    for line in data:
        line = line.split(',"')
        line[4] = line[4].replace('"', "")
        line[5] = line[5].replace('"', "")
        if str(line[5]).lower() == country.lower():
            deaths += int(line[4])
    return deaths
# --------------------------------------

def main(file_name):

    print("Global data collected between Jan 1 - Nov 5, 2020".center(50))
    infections = ave_infection_rate(file_name)
    print('*' * 50)
    print("Fortnightly cases reported per 100,000 people,\n(global average): ", end="")
    print(ave_infection_rate(file_name))

    print('*' * 50)
    user_input = input("Save list countries? ('y' for yes) : ")
    if user_input.lower() == 'y':
        save_as = input("Save File As: ")
        save_as += ".txt"
        countries_in_study(file_name, save_as)
        print("File saved as", save_as)

    print('*' * 50)
    country = input("Enter a country in the dataset: ")
    num = deaths_in_country(file_name, country)
    print("The data reports {:d} covid deaths in {}.".format(num, country))

# --------------------------------------

main("covid.csv")
