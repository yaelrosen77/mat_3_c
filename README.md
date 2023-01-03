# mat_3_c
Our project is based on two seperate programs- isort and txtfind.

## isort
This is a program that receives a 50 positive (not necessarily different) integers from the standard input, and prints out the sorted array of these numbers.
The sorting operation is performed by the _"insertion sort"_ algorithm which has a time complexity of O(n^2).
For information about _"insertion sort"_ see [Wikipedia insertion sort](https://en.wikipedia.org/wiki/Insertion_sort). 
#### Functionality:
While receiving the 50 numbers from the standart input, each of the numbers is saved in the previously initialized array. 
After that, there is a call to the **insertion_sort** function with the given array. This function iterates each number in array from index 1 to the last one, while checking if it is bigger then the previous numbers in array. 
If not, continue. Else, checks how many previously bigger numbers from the current one exists, saving the current one at a temporary variable, and performs a "right shiftment" using the **shift_element** function to all smaller numbers. 
After that, inserting the current number in the index found to be the last bigger number. 

## txtfind
This is a program that receives a string and text from the standart input and performs one of the following options:
  a. Printing all the lines in the text in which contains the string. 
  b. Printing all the words in text which is similar to the string, up to omitting one letter. 
#### Functionality:
The text received is in the following form:

    <Required_searching_string> <user_option_char> ('a' || 'b')
    text line 1
    text line 2
    text line 3
    text line 4
    And so on.... 

The given string is saved using the **get_word** function. If the following char will be 'a', the program will call the **print_line** function.
This function first call the **getline** function to insert the first line of text to a variable. With "slicing" each word of the sentence, the **similar** function is called with our string and word as an arguments in order to check similarity between those and print the whole line to the screen if necessery.
If the char is 'b', then the **print_similar_words** function is called. By using the **get_word** function, each of the word of the text is compared with our string using the **similar** function, and with the arguments of the string, word, and 1 or 0 (both options are considered).
If the function returns true, then the similar words are being print out to the screen. 

Notice that each program "assumes" a valid input as an order from the assignment writer.


Collaborators- @noyrosenbaum
