#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    string values_line;
    getline(cin, values_line);
    
    string template_line;
    getline(cin, template_line);
    
    map<string, string> replacements;
    istringstream iss(values_line);
    string pair;
    
    while (getline(iss, pair, ',')) {
        size_t equal_pos = pair.find('=');
        if (equal_pos != string::npos) {
            string name = pair.substr(0, equal_pos);
            string value = pair.substr(equal_pos + 1);
            replacements[name] = value;
        }
    }
    
    size_t start_pos = 0;
    while (true) {
        size_t open_pos = template_line.find('[', start_pos);
        if (open_pos == string::npos) break;
        size_t close_pos = template_line.find(']', open_pos);
        if (close_pos == string::npos) break;
        
        string name = template_line.substr(open_pos + 1, close_pos - open_pos - 1);
        auto it = replacements.find(name);
        
        if (it != replacements.end()) {
            template_line.replace(open_pos, close_pos - open_pos + 1, it->second);
            start_pos = open_pos + it->second.length();
        } else {
            start_pos = close_pos + 1;
        }
    }
    
    cout << template_line << endl;
    return 0;
}
