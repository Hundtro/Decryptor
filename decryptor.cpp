#include <string>
#include <fstream>

std::string decrypt_value(std::string value);
std::string decrypt_text(std::string text);

const int keys_count = 117;
std::string keys[keys_count][2] = {
    "0", "null",
    "1", "*LMOUSE*",
    "2", "*RMOUSE*",
    "3", "*CENCEL*",
    "4", "*MMOUSE*",
    "8", "*BACKSPACE*",
    "9", "*TAB*",
    "12", "*CLEAR*",
    "13", "*ENTER*",
    "16", "*SHIFT*",
    "17", "*CONTROL*",
    "18", "*ALT*",
    "19", "*PAUSE*",
    "20", "*CAPSLOCK*",
    "27", "*ESC*",
    "32", "*SPACE*",
    "33", "*PAGE_UP*",
    "34", "*PAGE_DOWN*",
    "35", "*END*",
    "36", "*HOME*",
    "37", "*LEFT_ARROW*",
    "38", "*UP_ARROW*",
    "39", "*RIGHT_ARROW*",
    "40", "*DOWN_ARROW*",
    "41", "*SELECT*",
    "43", "*EXECUTE*",
    "44", "*PRINT_SCREEN*",
    "45", "*INSERT*",
    "46", "*DELETE*",
    "47", "*HELP*",
    "48", "0",
    "49", "1",
    "50", "2",
    "51", "3",
    "52", "4",
    "53", "5",
    "54", "6",
    "55", "7",
    "56", "8",
    "57", "9",
    "65", "A",
    "66", "B",
    "67", "C",
    "68", "D",
    "69", "E",
    "70", "F",
    "71", "G",
    "72", "H",
    "73", "I",
    "74", "J",
    "75", "K",
    "76", "L",
    "77", "M",
    "78", "N",
    "79", "O",
    "80", "P",
    "81", "Q",
    "82", "R",
    "83", "S",
    "84", "T",
    "85", "U",
    "86", "V",
    "87", "W",
    "88", "X",
    "89", "Y",
    "90", "Z",
    "91", "*LWinKey*",
    "92", "*RWinKey*",
    "93", "*AppsKey*",
    "96", "*Num0*",
    "97", "*Num1*",
    "98", "*Num2*",
    "99", "*Num3*",
    "100", "*Num4*",
    "101", "*Num5*",
    "102", "*Num6*",
    "103", "*Num7*",
    "104", "*Num8*",
    "105", "*Num9*",
    "106", "*Num**",
    "107", "*Num+*",
    "109", "*Num-*",
    "110", "*NumDel*",
    "111", "*NumSlash*",
    "112", "*F1*",
    "113", "*F2*",
    "114", "*F3*",
    "115", "*F4*",
    "116", "*F5*",
    "117", "*F6*",
    "118", "*F7*",
    "119", "*F8*",
    "120", "*F9*",
    "121", "*F10*",
    "122", "*F11*",
    "123", "*F12*",
    "124", "*F13*",
    "125", "*F14*",
    "126", "*F15*",
    "144", "*NUM_LOCK*",
    "145", "*SCROLL_LOCK*",
    "186", ",",
    "187", "=",
    "188", ",",
    "189", "-",
    "190", ".",
    "191", "/",
    "219", "[",
    "220", "\\",
    "221", "]",
    "222", "'",
    "160", "*L*",
	"162", "*L*",
	"164", "*L*",
    "161", "*R*",
    "163", "*R*",
    "165", "*R*",
};

int main()
{
    std::string encrypted_text;
    std::string decrypted_text;
    std::ifstream enc_file;
    std::ofstream dec_file;

    enc_file.open("code_log");
    enc_file >> encrypted_text;
    enc_file.close();
    decrypted_text = decrypt_text(encrypted_text);
    dec_file.open("decrypted");
    dec_file << decrypted_text;
    dec_file.flush();
    dec_file.close();

    return 0;
}

std::string decrypt_value(std::string value)
{
    std::string result = "*unknown*";
    
    for (int i = 0; i < keys_count; i++) {
        if (value == keys[i][0]) {
            result = keys[i][1];
            break;
        }
    }
    
    return result;
}

std::string decrypt_text(std::string text)
{
    std::string result = std::string();
    std::string key = std::string();

    for (int i = 0; i < text.size(); i++) {
        if (text[i] != '.') {
            key.push_back(text[i]);
        } else {
            result += decrypt_value(key);
            key.clear();
        }
    }

    return result;
}
