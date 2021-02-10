#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;



void function3(ifstream & in, vector<string> & words);

// function1-t breaks the input text into sentences
void function1(ifstream & in, vector<string> & vector, std::vector<string>  & vector2){
 char ch;
 string s;
  while(in){
      in.get(ch);
      if(ch!='.' && ch!='\n') s+=ch;
      else{
          if(ch=='.'){
              s+=ch;
          }
          if(s.empty()) {
              function3(in, vector2);  // if we go to a new line we call function3 which continue dividing file into words
              break;
          }
          else{
              vector.push_back(s);
              s.clear();
          }
      }
  }
}
//function2-returns all sentences that contain the word from the
//input and make the word UPPERCASE in sentences
vector<string> function2(string word, vector<string> &sentences){

    string upper;  //uppercase word for current word
    int ix=0;
    char character;
    while (word[ix])
    {
        character = word[ix];
        upper+=(char)toupper(character);
        ix++;
    }

    vector<string> answer;
    string current_sentence;
    string sentence_for_answer;
    string current_word;
    for(int i=0; i<sentences.size(); i++){
        current_sentence=sentences[i];
        for(int j=0; j<current_sentence.length(); j++){
            if(current_sentence[j]!=' ' && current_sentence[j]!='.') current_word+=current_sentence[j];
            else{
                    if(current_word==word) {
                        sentence_for_answer=current_sentence;
                        sentence_for_answer.replace(j-upper.length(), upper.length(), upper);
                        sentence_for_answer+='\n';
                        answer.push_back(sentence_for_answer);

                    }

                current_word.clear();
            }
        }
    }

    return answer;
}

//function3-divide file into words after sentences
void function3(ifstream & in, vector<string> & words){
    char ch;
    string s;
    while(in){
        in.get(ch);
        if(ch!='\n') s+=ch;
        else{
            words.push_back(s);
            s.clear();
        }
    }
    words.push_back(s.substr(0,s.length()-1));
}


int main(){
    setlocale(LC_ALL, "rus");
    ifstream filein;
    filein.open("in.txt");
    ofstream fileout;
    fileout.open("out.txt");
    vector<string> sentences; //vector of strings with each sentence,
    vector<string> words;     //vector of strings where the first element is number of words, and every next contain the word

    function1(filein, sentences, words);

    int counter;
    for(int i=1; i<words.size(); i++){
        counter=function2(words[i],sentences).size();
        fileout<<counter<<endl;
        for(int k=0; k<counter; k++) {
            fileout << function2(words[i], sentences)[k];
        }
    }

    filein.close();
    fileout.close();
    return 0;
}
