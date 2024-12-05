#include "Trie.cpp"
#include <fstream>
#include <iostream>
#include <conio.h> 
#include <Windows.h>

using namespace std;

void print_result(vector<string>& vec)
{
    for(auto& word : vec)
    {
        cout<<word<<" ";
    }
    cout<<"\n";
}

int main()
{

    Trie trie {};

    ifstream file("words_alpha.txt");
    string line;

    if (file.is_open()) 
    {
        while (getline(file, line)) 
        {
            trie.insert(line);
        }
        file.close();
    }

    string current = "";
    system("CLS");
    while(true)
    {
        if (_kbhit()) 
        {
            int key = _getch(); 

            if (key == ' ') 
            {
                current = "";
                system("CLS");
                std::cout<<"Word: "<<current<<"\n";
            } 
            else if (key >= 32 && key <= 126) 
            { 
                system("CLS");
                current += static_cast<char>(key);
                std::cout<<"Word: "<<current<<"\n";
                auto result = trie.getPrefixes(current);
                std::cout<<"Found "<<result.size()<<" words with prefix "<<current<<":\n";
                print_result(result);
            }
            else if (key == 8)
            {
                system("CLS");
                current = current.substr(0, current.size() - 1);
                std::cout<<"Word: "<<current<<"\n";
                auto result = trie.getPrefixes(current);
                std::cout<<"Found "<<result.size()<<" words with prefix "<<current<<":\n";
                print_result(result);
            }
        }
        
    }
}