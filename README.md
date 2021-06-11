# improvedStringFunction
My project at MSU to find a pattern in string.

In a file named "project.cpp", you will need to write the a number of functions described below. You should include all the described functions in your solution, but you should also be writing additional "helper" functions to aid the functions that the test cases will be exercising. Remember to keep your functions as short and legible as possible, as you will lose points for excessively complicated or unreadable code.
You will be writing many functions that involve searching for a string for a certain pattern. The simplest case is looking for an exact match. For instance, the pattern string "Mal" can be found in the text "My dog's name is Mal.". All of the functions can be switched to a case insensitive version with an argument. With a case insensitive function, the pattern "MAL", "mal", and "Mal" will all find a match, but "cat" will still fail on the previous text example.
Additionally the pattern string can contain special characters that match a set of possible text characters:
The '%' character can match any other single character.
The '#' character can match any single digit character.
The text is guaranteed not contain either of these special characters.

ImprovedContains takes three arguments: a string representing the text to search, a string representing the pattern to search for, and a pointer to bool that represents if the search should be case insensitive. This function should return true if the pattern is found in the text, false otherwise.
ImprovedMatches takes three arguments: a string representing the text to search, a string representing the pattern to search for, and a pointer to bool that represents if the search should be case insensitive. This function should return the number of times the pattern is found in the text.
ImprovedFindFirstOf takes three arguments: a string representing the text to search, a string representing the pattern to search for, and a pointer to bool that represents if the search should be case insensitive. This function should return the index in the text that the pattern is found, return -1 if pattern is not found.
ImprovedReplace takes four arguments: a string representing the text to search, a string representing the pattern to search for, a string representing the new content to replace the pattern in the text with, and a pointer to bool that represents if the search should be case insensitive.
ImprovedNumberOfDifferences takes three arguments: two strings that will be compared character by character, and a bool that represents if the comparison should be case insensitive. This function should return the number of characters that differ between the two strings. You can assume that neither string contains special characters.

