#include "minclude.h"

class Solution 
{
public:

    vector<int> breakInt(int number, int breaks_num)
    {
        if(breaks_num == 1 || breaks_num == 0) return {number};

        vector<int> return_value (breaks_num, 0);

        for(int i = 0 ; i < number ; i++)
        {
            return_value[i % breaks_num]++;
        }

        return return_value;
    }

    string justifyLine(vector<string>& words, int maxWidth)
    {
        int lengths_sum = 0;
        int word_count = words.size();

        for(auto& word : words)
        {       
            lengths_sum += word.length();
        }

        auto spaces_counts = breakInt(maxWidth - lengths_sum, word_count - 1);

        stringstream ss;

        if(word_count == 1)
        {
            ss << words[0];
            for(int i = 0 ; i < spaces_counts[0] ; i++)
            {
                ss << " ";
            }
        }
        else
        {
            for(int i = 0 ; i < words.size() - 1 ; i++)
            {
                ss << words[i];

                for(int j = 0 ; j < spaces_counts[i] ; j++)
                {
                    ss << " ";
                }
            }

            ss << words.back();
        }
        
        return ss.str();
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<int> words_sizes;

        vector<vector<string>> lines {{}};
        vector<int> line_lengths {0};
        int line_idx = 0;

        auto next_line = [&line_idx, &line_lengths, &lines]()
        {
            lines.push_back({});
            line_lengths.push_back(0);
            line_idx++;
        };

        for(auto& word : words)
        {
            if(line_lengths[line_idx])
            {
                line_lengths[line_idx]++;
            }

            if(line_lengths[line_idx] >= maxWidth)
            {
                next_line();
            }

            if(line_lengths[line_idx] + word.length() <= maxWidth)
            {
                line_lengths[line_idx] += word.length();
                lines[line_idx].push_back(word);
            }   
            else
            {
                next_line();
                line_lengths[line_idx] += word.length();
                lines[line_idx].push_back(word);
            }
        }
        
        vector<string> return_value;
        for(int i = 0; i < lines.size() - 1; i++)
        {
            return_value.push_back(justifyLine(lines[i], maxWidth));
        }

        //last line
        auto& last_line = lines.back();

        string ss;

        for(int i = 0 ; i < last_line.size() - 1 ; i++)
        {
            ss.append(last_line[i]);
            ss.append(" ");
        }
        ss.append(last_line.back());

        while(ss.length() != maxWidth)
        {
            ss.append(" ");
        }

        return_value.push_back(ss);

        return return_value;
    }
};

int main()
{
    vector<string> words {"What","must","be","acknowledgment","shall","be"};
    int width = 16;
    Solution s {};
    auto a = s.fullJustify(words, width);
    for(auto& l : a)
    {
        cout<<"\""<<l<<"\"\n";
    }
    return 0;
}