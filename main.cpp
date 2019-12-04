#include <iostream>
#include <string>
#include <map>
#include <windows.h>
#include <thread>
#include <chrono>

void textToMorse(const std::string &text);

std::string codeToMorse(char character);

char decodeMorse(std::string morse);

std::string getText(const std::string &msg);

void morseToText(const std::string &morse);

void sing_a_song(std::string &morse);

int main() {
    textToMorse(getText("Enter text to convert to Morse"));
    morseToText(getText("Enter morse to convert to text"));

    std::cout << "Press any key to continue...";
    getchar();
    return 0;
}

void textToMorse(const std::string &text) {
    for (char i : text) {
        if (i == ' ')
            std::cout << "  ";
        else if (isalpha(i))
            std::cout << codeToMorse(tolower(i)) << ' ';
        else
            std::cout << codeToMorse(i) << ' ';
    }
    std::cout << std::endl;
}

std::string getText(const std::string &msg) {
    std::cout << msg << "\n";
    std::string text;
    getline(std::cin, text);
    return text;
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

char decodeMorse(std::string morse) {
    std::map<std::string, char> mapForTranslatingFromMorse = {
            {".-",     'a'},
            {"-...",   'b'},
            {"-.-.",   'c'},
            {"-..",    'd'},
            {".",      'e'},
            {"..-.",   'f'},
            {"--.",    'g'},
            {"....",   'h'},
            {"..",     'i'},
            {".---",   'j'},
            {"-.-",    'k'},
            {".-..",   'l'},
            {"--",     'm'},
            {"-.",     'n'},
            {"---",    'o'},
            {".--.",   'p'},
            {"--.-",   'q'},
            {".-.",    'r'},
            {"...",    's'},
            {"-",      't'},
            {"..-",    'u'},
            {"...-",   'v'},
            {".--",    'w'},
            {"-..-",   'x'},
            {"-.--",   'y'},
            {"--..",   'z'},
            {"-----",  '0'},
            {".----",  '1'},
            {"..---",  '2'},
            {"...--",  '3'},
            {"....-",  '4'},
            {".....",  '5'},
            {"-....",  '6'},
            {"--...",  '7'},
            {"---..",  '8'},
            {"----.",  '9'},
            {".-.-.-", '.'},
            {"--..--", ','},
            {"..--..", '?'},
            {"---...", ':'},
            {".----.", '\''},
            {"-....-", '-'},
            {"-..-.",  '/'},
            {"-.--.-", '('},
            {"-.--.-", ')'},
            {".-..-.", '\"'}
    };

    return mapForTranslatingFromMorse.find(morse)->second;
}

void morseToText(const std::string& morse) {
	int morseSize = morse.size();
	std::string tempMorse;
	std::string fullMorse = morse;

	for (int i = 0; i < morseSize; i++) {
		if (morse[i] == ' ' && morse[i + 1] != ' ' && i < morseSize - 1) {
			std::cout << decodeMorse(tempMorse);
			
			tempMorse.clear();
		}
		else if (morse[i] == ' ' && morse[i + 2] == ' ' && i < morseSize - 2) {
			std::cout << decodeMorse(tempMorse) << " ";
			i += 2;
			tempMorse.clear();
		}
		else
			tempMorse += morse[i];
		if (i == morseSize - 1) {
			std::cout << decodeMorse(tempMorse);
		}

	}
	putchar('\n');
	sing_a_song(fullMorse);
}

void sing_a_song(std::string& morse) {
	int beat = 100;
	int frequency = 1000;
	for (int i = 0; i < morse.size(); i++) {
		if (morse[i] == '.' && morse[i + 1] != ' ' && i + 1 <= morse.size()) {
			Beep(frequency, beat);
			std::this_thread::sleep_for(std::chrono::milliseconds(beat));
		}
		else if (morse[i] == '-' && morse[i + 1] != ' ' && i + 1 <= morse.size()) {
			Beep(frequency, beat * 3);
			std::this_thread::sleep_for(std::chrono::milliseconds(beat));
		}
		else if (morse[i] == '.' && morse[i + 1] == ' ' && morse[i + 2] != ' ' && i + 2 <= morse.size()) {
			Beep(frequency, beat);
			std::this_thread::sleep_for(std::chrono::milliseconds(beat*3));
		}
		else if (morse[i] == '-' && morse[i + 1] == ' ' && morse[i + 2] != ' ' && i + 2 <= morse.size()) {
			Beep(frequency, beat * 3);
			std::this_thread::sleep_for(std::chrono::milliseconds(beat * 3));
		}
		else if (morse[i] == '.' && morse[i + 3] == ' ' && i + 3 < morse.size()) {
			Beep(frequency, beat);
			std::this_thread::sleep_for(std::chrono::milliseconds(beat * 7));
		}
		else if (morse[i] == '-' && morse[i + 3] == ' ' && i + 3 < morse.size()) {
			Beep(frequency, beat * 3);
			std::this_thread::sleep_for(std::chrono::milliseconds(beat * 7));
		}
	}
}

