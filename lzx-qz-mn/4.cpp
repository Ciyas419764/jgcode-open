#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

struct WordWithCount
{
    string word;
    int count;
};

int search_word(vector<WordWithCount> words_with_count, string word){
    for(int i = 0;i < words_with_count.size();i++)
        if(word == words_with_count[i].word) return i;
    return -1;
}

int main(){
    string input;
    int ch;
    for(;;){
        ch = getchar();
        input.push_back(ch);
        if(ch == EOF) break;
    }
    vector<string> words;

    int left_index = -1;
    for(int i = 0;i < input.length();i++)
        if((input[i] < 'A' || input[i] > 'z') && input[i] != '\''){
            if(left_index != i - 1) words.push_back(input.substr(left_index + 1, i -left_index -1));
            left_index = i;
        }
    
    vector<WordWithCount> words_with_count;
    for(int i = 0;i < words.size();i++){
        int tmp = search_word(words_with_count, words[i]);
        if(tmp != -1) words_with_count[tmp].count++;
        else words_with_count.push_back({words[i], 1});
    }

    for(int i = 0;i < words_with_count.size();i++){
        cout << words_with_count[i].word << ' ' << words_with_count[i].count << endl;
    }

    return 0;
}