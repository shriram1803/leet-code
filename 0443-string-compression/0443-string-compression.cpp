class Solution {
public:
    int addLength(vector<char>& chars, int start, int count) {
        string temp = to_string(count);
        for(char ch : temp) {
            chars[start] = ch;
            start += 1;
        }
        return temp.size() + 1;
    }
    int compress(vector<char>& chars) {
        int cont = 1, n = chars.size(), res = 0;
        chars.emplace_back('?');
        for(int i = 1, j = 0; i <= n; ++i) {
            if(chars[i] == chars[i - 1]) {
                cont += 1;
            } else {
                if(cont == 1) {
                    chars[j] = chars[i - 1];
                    j += 1, res += 1;
                } else {
                    chars[j] = chars[i - 1];
                    int get_len = addLength(chars, j + 1, cont);
                    j += get_len, res += get_len, cont = 1;
                }
            }
        }
        return res;
    }
};