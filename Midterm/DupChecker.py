# Taking input from user. It is stored as a string in userInput var
userInput = input()
# removing the fullstop at the end because, is a duplicate is present at the end, then the full stop along with it will be difficult for comparison
userInput = userInput.strip(".")
# split the words seperated by space and store then in a list called words
words = userInput.split(" ")
#only allow maximum of 64 characters
if len(words) > 64:
    # reduce the size of the words list upto the first 64 words
    words = words[:64]
#use dictionary to store and count duplicated words
count = {}
# use flag var to keep track of duplicated words
#if flag is 0 then simply means no duplcates
flag = 0
# sotre the duplicated words in a list for output 
dupes = []
# taking x as key and assigning value 0 to every element of count from words
for x in words:
    count[x] = 0
# traversing the list of words
for x in words:
    # increment count in dictionary for each word
    #so if a word is duplicated, that word will have more than 1 count in the dictionary
    count[x] += 1
# traversing the dictionary to check the values of each key 
for x in count:
    # if count is more than 1, it means that it is a duplicate
    if count[x] > 1:
    # append it to the list of dupes
        dupes.append(x)
# set flag to 1
        flag = 1
# if flag is 0, then it means that there are no duplicates
if flag == 0:
    print("No Duplicates")
else:
    # sort the duplicates in ascending order
    dupes.sort()
# traversing and printing the duplicates ine by line
    for x in dupes:
        #print out the dop word and its count value
        print("{} {}".format(x, count[x]))
