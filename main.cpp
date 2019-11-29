#include <iostream>
#include <string>
#include <map>

void textToMorse(const std::string &text);

std::string codeToMorse(char character);

std::string encodeMorse(std::string morse);

std::string getText();

void morseToText(const std::string &morse);

int main() {
    std::cout << "Enter text to convert to Morse\n";
    std::string text;
    getline(std::cin, text);
    textToMorse(text);
    std::cout << "Enter Morse code to convert to text\n";
    getline(std::cin, text);
    morseToText(text);

    std::cout << "Press any key to continue...";
    getchar();
    return 0;
}

void textToMorse(const std::string &text) {
    for (char i : text) {
        if (i == ' ')
            std::cout << "   ";
        else
            std::cout << codeToMorse(i) << ' ';
    }
    std::cout << std::endl;
}

std::string getText() {

}

std::string codeToMorse(char character) {
    std::map<char, std::string> mapForTranslateToMorse = {
            {'a',  ".-"},
            {'b',  "-..."},
            {'c',  "-.-."},
            {'d',  "-.."},
            {'e',  "."},
            {'f',  "..-."},
            {'g',  "--."},
            {'h',  "...."},
            {'i',  ".."},
            {'j',  ".---"},
            {'k',  "-.-"},
            {'l',  ".-.."},
            {'m',  "--"},
            {'n',  "-."},
            {'o',  "---"},
            {'p',  ".--."},
            {'q',  "--.-"},
            {'r',  ".-."},
            {'s',  "..."},
            {'t',  "-"},
            {'u',  "..-"},
            {'v',  "...-"},
            {'w',  ".--"},
            {'x',  "-..-"},
            {'y',  "-.--"},
            {'z',  "--.."},
            {'0',  "-----"},
            {'1',  ".----"},
            {'2',  "..---"},
            {'3',  "...--"},
            {'4',  "....-"},
            {'5',  "....."},
            {'6',  "-...."},
            {'7',  "--..."},
            {'8',  "---.."},
            {'9',  "----."},
            {'.',  ".-.-.-"},
            {',',  "--..--"},
            {'?',  "..--.."},
            {':',  "---..."},
            {'\'', ".----."},
            {'-',  "-....-"},
            {'/',  "-..-."},
            {'(',  "-.--.-"},
            {')',  "-.--.-"},
            {'\"', ".-..-."}
    };

    return mapForTranslateToMorse.find(character)->second;
}

std::string encodeMorse(std::string morse) {
    std::map<std::string, std::string> mapForTranslatingFromMorse = {
            {".-",     "a"},
            {"-...",   "b"},
            {"-.-.",   "c"},
            {"-..",    "d"},
            {".",      "e"},
            {"..-.",   "f"},
            {"--.",    "g"},
            {"....",   "h"},
            {"..",     "i"},
            {".---",   "j"},
            {"-.-",    "k"},
            {".-..",   "l"},
            {"--",     "m"},
            {"-.",     "n"},
            {"---",    "o"},
            {".--.",   "p"},
            {"--.-",   "q"},
            {".-.",    "r"},
            {"...",    "s"},
            {"-",      "t"},
            {"..-",    "u"},
            {"...-",   "v"},
            {".--",    "w"},
            {"-..-",   "x"},
            {"-.--",   "y"},
            {"--..",   "z"},
            {"-----",  "0"},
            {".----",  "1"},
            {"..---",  "2"},
            {"...--",  "3"},
            {"....-",  "4"},
            {".....",  "5"},
            {"-....",  "6"},
            {"--...",  "7"},
            {"---..",  "8"},
            {"----.",  "9"},
            {".-.-.-", "."},
            {"--..--", ","},
            {"..--..", "?"},
            {"---...", ":"},
            {".----.", "\'"},
            {"-....-", "-"},
            {"-..-.",  "/"},
            {"-.--.-", "("},
            {"-.--.-", ")"},
            {".-..-.", "\""}
    };

    return mapForTranslatingFromMorse.find(morse)->second;
}

void morseToText(const std::string &morse) {
    int morseSize = morse.size();
    std::string tempMorse;
    for (int i = 0; i < morseSize; i++) {
        if (morse[i] == ' ')
            std::cout << encodeMorse(tempMorse);
        else if (morse[i] == ' ' && morse[i + 2] == ' ' && i < morseSize - 2)
            std::cout << encodeMorse(tempMorse) << " ";
        else
            tempMorse += morse[i];
    }
}

