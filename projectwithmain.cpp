#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

//helper functions

void ToLowerCase(string *value)
{
    for (long unsigned int index = 0; index < (*value).length(); index++)
    {
        (*value)[index] = tolower((*value)[index]);
    }
}
/* Depending on isCaseInsensitve flag, 
  lower text and patter
 */

void HandleTextAndPatterForCaseInSensitive(string *text, string *pattern, const bool *is_case_insensitive)
{
    if (*is_case_insensitive == true)
    {
        ToLowerCase(text);
        ToLowerCase(pattern);
    }
}
bool PatternInSubTextFound(string text, string pattern)
{
    bool pattern_found = true;
    if (text.length() < pattern.length())
        return false;
    for (long unsigned int text_index = 0; text_index < text.length(); text_index++)
    {
        int is_current_position_has_digit = isdigit((text)[text_index]); // 1 if current position of text is a number
        if ((text[text_index] == pattern[text_index] || (pattern[text_index] == '%')) || (pattern[text_index] == '#' && is_current_position_has_digit == 1))
        {
            //pattern_found = true;
        }
        else
        {
            pattern_found = false;
        }
    }
    return pattern_found;
}
/*
  find match
  find first index
  find how many matches.
  replace existing string
 */
vector<int> FindPatternInText(string text, string pattern)
{
    long unsigned int pattern_length = pattern.length();
    vector<int> pattern_indexes;
    for (long unsigned int text_index = 0; text_index < text.length(); text_index++)
    {
        string text_string_to_match = text.substr(text_index, pattern_length);
        if (PatternInSubTextFound(text_string_to_match, pattern) == true)
        {
            pattern_indexes.push_back(text_index);
        }
    }
    return pattern_indexes;
}

/*
ImprovedContains takes three arguments: a string representing the text to search, a string representing the pattern to search for, 
and a pointer to bool that represents if the search should be case insensitive. This function should return true if the pattern is 
found in the text, false otherwise.
 */

bool ImprovedContains(string text, string pattern,
                      const bool *is_case_insensitive)
{
    bool pattern_found = false;
    HandleTextAndPatterForCaseInSensitive(&text, &pattern, is_case_insensitive);
    vector<int> pattern_indexes = FindPatternInText(text, pattern);
    if (pattern_indexes.size() > 0)
    {
        pattern_found = true;
    }
    return pattern_found;
}
/*
ImprovedMatches takes three arguments: a string representing the text to search, a string representing the pattern to search for, 
and a pointer to bool that represents if the search should be case insensitive. This function should return the number of times the 
pattern is found in the text.
*/

int ImprovedMatches(string text, string pattern,
                    const bool *is_case_insensitive)
{
    int num_of_patterns = 0;
    HandleTextAndPatterForCaseInSensitive(&text, &pattern, is_case_insensitive);
    vector<int> pattern_indexes = FindPatternInText(text, pattern);
    if (pattern_indexes.size() > 0)
    {
        num_of_patterns = pattern_indexes.size();
    }
    return num_of_patterns;
}
/*
ImprovedFindFirstOf takes three arguments: a string representing the text to search, a string representing the pattern to search for, 
and a pointer to bool that represents if the search should be case insensitive. This function should return the index in the text that 
the pattern is found, return -1 if pattern is not found.
*/

int ImprovedFindFirstOf(string text, string pattern,
                        const bool *is_case_insensitive)
{
    int first_pattern_index = -1;
    HandleTextAndPatterForCaseInSensitive(&text, &pattern, is_case_insensitive);
    vector<int> pattern_indexes = FindPatternInText(text, pattern);
    if (pattern_indexes.size() > 0)
    {
        first_pattern_index = pattern_indexes.front();
    }
    return first_pattern_index;
}

/*
ImprovedReplace takes four arguments: a string representing the text to search, a string representing the pattern to search for, 
a string representing the new content to replace the pattern in the text with, and a pointer to bool that represents if the search 
should be case insensitive.
*/

void ImprovedReplace(string &text, string pattern, string new_content,
                     const bool *is_case_insensitive)
{
    string original_text = text;
    HandleTextAndPatterForCaseInSensitive(&text, &pattern, is_case_insensitive);
    vector<int> pattern_indexes = FindPatternInText(text, pattern);
    for (int index : pattern_indexes)
    {
        original_text.replace(index, pattern.length(), new_content);
        text.replace(index, pattern.length(), new_content);
        if (!ImprovedContains(text, pattern, is_case_insensitive))
        {
            break;
        }
    }
    text = original_text;
}

int FindNumberOfDifferences(string smaller_string, string bigger_string)
{
    int number_of_differences = 0;
    for (long unsigned int counter = 0; counter < smaller_string.length(); counter++)
    {
        if (smaller_string[counter] != bigger_string[counter])
        {
            number_of_differences++;
        }
    }
    return number_of_differences;
}
/*
ImprovedNumberOfDifferences takes three arguments: two strings that will be compared character by character, and a bool that represents 
if the comparison should be case insensitive. This function should return the number of characters that differ between the two strings. 
You can assume that neither string contains special characters.
*/

int ImprovedNumberOfDifferences(string str1, string str2,
                                const bool is_case_insensitive)
{
    int number_of_differences = 0;
    string smaller_string, bigger_string;
    HandleTextAndPatterForCaseInSensitive(&str1, &str2, &is_case_insensitive);
    if (str1.length() > str2.length())
    {
        smaller_string = str2;
        bigger_string = str1;
    }
    else
    {
        smaller_string = str1;
        bigger_string = str2;
    }
    number_of_differences = FindNumberOfDifferences(smaller_string, bigger_string);
    return number_of_differences;
}
///*
void ASSERT_TRUE(string test, bool result)
{
    std::cout.flush();
    if (result)
        cout << test << ": PASSED" << endl;
    else
        cout << test << " :FAILED" << endl;
}

void ASSERT_EQ(string test, int result, int value)
{
    if (result == value)
    {
        cout << test << ": PASSED" << endl;
    }
    else
    {
        cout << test << ": FAILED" << endl;
    }
}

void ASSERT_EQ(string result, string value)
{

    if (result == value)
    {
        cout << result << ": PASSED" << endl;
    }
    else
    {
        cout << result << ": FAILED" << endl;
    }
}

int main()
{
    //ImprovedNumberOfDifferences

    int result0 = ImprovedNumberOfDifferences("", "", false);
    ASSERT_EQ("ImprovedNumberOfDifferences", result0, 0);

    result0 = ImprovedNumberOfDifferences("abc", "def", false);
    ASSERT_EQ("ImprovedNumberOfDifferences", result0, 3);

    result0 = ImprovedNumberOfDifferences("abc 123", "Abc 124", false);
    ASSERT_EQ("ImprovedNumberOfDifferences", result0, 2);

    result0 = ImprovedNumberOfDifferences("abc 123", "Abc 124", true);
    ASSERT_EQ("ImprovedNumberOfDifferences", result0, 1);

    //  ImproveContains

    const std::string text{"My dog is named Mal."};
    bool is_case_insensitive = false;
    bool result;

    std::string pattern{"Mal"};
    result = ImprovedContains(text, pattern, &is_case_insensitive);
    ASSERT_TRUE(text, result);

    pattern = "mal";
    result = ImprovedContains(text, pattern, &is_case_insensitive);
    ASSERT_TRUE(text, result);

    is_case_insensitive = true;

    result = ImprovedContains(text, pattern, &is_case_insensitive);
    ASSERT_TRUE(text, result);

    pattern = "mAL";
    result = ImprovedContains(text, pattern, &is_case_insensitive);
    ASSERT_TRUE(text, result);

    pattern = "crashdown";
    result = ImprovedContains(text, pattern, &is_case_insensitive);
    ASSERT_TRUE(text, result);

    pattern = "my dog is NAMED Mal.";
    result = ImprovedContains(text, pattern, &is_case_insensitive);
    ASSERT_TRUE(text, result);

    //ImprovedMatches
    const std::string text1{"Was 2020 < 2021 do you think? Perhaps NOT?"};
    is_case_insensitive = false;
    int result1;
    result1 = ImprovedMatches(text1, "do ", &is_case_insensitive);
    ASSERT_EQ(text1, result1, 1);

    result1 = ImprovedMatches(text1, "2022", &is_case_insensitive);
    ASSERT_EQ(text1, result1, 0);

    result1 = ImprovedMatches(text1, "####", &is_case_insensitive);
    ASSERT_EQ(text1, result1, 2);

    result1 = ImprovedMatches(text1, "o", &is_case_insensitive);
    ASSERT_EQ(text1, result1, 2);

    //FAILED//
    result1 = ImprovedMatches(text1, "% ", &is_case_insensitive);
    ASSERT_EQ(text1, result1, 8);

    result1 = ImprovedMatches(text1, "##", &is_case_insensitive);
    ASSERT_EQ(text1, result1, 6);

    result = ImprovedMatches(text1, "W", &is_case_insensitive);
    ASSERT_EQ(text1, result, 1);

    result1 = ImprovedMatches(text1, "?", &is_case_insensitive);
    ASSERT_EQ(text1, result1, 2);

    is_case_insensitive = true;

    result1 = ImprovedMatches(text1, "o", &is_case_insensitive);
    ASSERT_EQ(text1, result1, 3);

    //ImprovedReplace

    std::string text2{"first 2021 middle 2020 last"};
    is_case_insensitive = false;

    //FAILED
    ImprovedReplace(text2, "first", "FIRST", &is_case_insensitive);
    ASSERT_EQ(text2, "FIRST 2021 middle 2020 last");

    ImprovedReplace(text2, "last", " end", &is_case_insensitive);
    ASSERT_EQ(text2, "FIRST 2021 middle 2020  end");

    ImprovedReplace(text2, "don't", "can't", &is_case_insensitive);
    ASSERT_EQ(text2, "FIRST 2021 middle 2020  end");

    ImprovedReplace(text2, "E", "Y", &is_case_insensitive);
    ASSERT_EQ(text2, "FIRST 2021 middle 2020  end");

    ImprovedReplace(text2, "##21", "34", &is_case_insensitive);
    ASSERT_EQ(text2, "FIRST 34 middle 2020  end");

    ImprovedReplace(text2, " %i", " MeE", &is_case_insensitive);
    ASSERT_EQ(text2, "FIRST 34 MeEddle 2020  end");

    is_case_insensitive = true;
    //cout<<"Initian Text: " << text2<<endl;
    ImprovedReplace(text2, "###", "ab", &is_case_insensitive);
    ASSERT_EQ(text2, "FIRST 34 MeEddle ab0  end");
    //cout<<"Initian Text: " << text2<<endl;
    ImprovedReplace(text2, "Ee", "eE", &is_case_insensitive);
    ASSERT_EQ(text2, "FIRST 34 MeEddle ab0  end");
    //cout<<"Initian Text: " << text2<<endl;
    ImprovedReplace(text2, "mee", "X", &is_case_insensitive);
    ASSERT_EQ(text2, "FIRST 34 Xddle ab0  end");
}
//*/
/*
int main(){

}
*/
