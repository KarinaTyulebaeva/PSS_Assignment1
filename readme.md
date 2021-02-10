This program reads the text from the input file and uses 3 functions to 
write the correct answer to the output file.

**All functions of the program:**

_void function1(ifstream & in, vector<string> & vector, std::vector<string>  & vector2)_

This function breaks the input text into sentences. It divides words to the last point and then calls **function3**

_void function3(ifstream & in, vector<string> & words)_

This function continues the meaning of function2. After switching to a new line, divides the words and writes to the vector

_vector<string> function2(string word, vector<string> &sentences)_

This function returns all sentences that contain the word from the
input and make the word UPPERCASE in sentences.the function takes a vector of sentences and a specific word. Then it splits each sentence into words and compares each word to the specific word. If such a word was found, then makes the current word UPPERCASE and write this sentence into the answer.

