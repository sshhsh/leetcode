#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    class MyNode
    {
        public:
        unordered_map<char, shared_ptr<MyNode> > m;
        int index = -1;
    };
    

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()||words[0].empty()){
            return res;
        }

        shared_ptr<MyNode> mp(new MyNode);

        for (int i = 0; i < words.size(); ++i) {
            shared_ptr<MyNode> tmp = mp;
            for (char c : words[i]) {
                if (tmp->m.count(c) == 0){
                    shared_ptr<MyNode> tmp2(new MyNode);
                    tmp->m[c] = tmp2;
                    tmp = tmp2;
                }
                else {
                    tmp = tmp->m[c];
                }
            }
            tmp->index = i;
        }

        return res;
    }
};

int main() {
    auto s = Solution();
    auto real = true;
    vector<string> input;
    input.push_back("ads");
    input.push_back("bac");
    input.push_back("ade");
    auto test = s.findSubstring("aab", input);
    // assert(real == test);
    return 0;
}