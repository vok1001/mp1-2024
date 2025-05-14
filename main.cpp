
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>



using namespace std;


struct Song_info {
    string title;
    string artist;
    int year;

    friend ostream& operator<<(ostream& os, const Song_info& song) {
        os << "\"" << song.title << "\" | " << song.artist << " | " << song.year;
        return os;
    }
};


class SongLibrary {
private:
    vector<Song_info> songs;

public:

    void addSong(const Song_info& song) {
        songs.push_back(song);
    }

    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "Не удалось открыть файл: " << filename << endl;
            return;
        }

        string line;
        while (getline(fin, line)) {
            if (line.empty()) continue;

            Song_info song;
            istringstream iss(line);
            string token;
            vector<string> tokens;

            while (iss >> token) {
                tokens.push_back(token);
            }

            parseTokens(tokens, song);
            songs.push_back(song);
        }

        cout << "Загружено " << songs.size() << " записей из файла." << endl;
        fin.close();
    }

    void saveToFile(const string& filename) {
        ofstream fout(filename);
        if (!fout) {
            cout << "Не удалось открыть файл для записи." << endl;
            return;
        }

        for (const auto& song : songs) {
            fout << "\"" << song.title << "\" " << song.artist << " " << song.year << "\n";
        }

        cout << "Данные сохранены в файл: " << filename << endl;
        fout.close();
    }

    void displayAll() const {
        if (songs.empty()) {
            cout << "Библиотека пуста." << endl;
            return;
        }

        for (size_t i = 0; i < songs.size(); ++i) {
            cout << i + 1 << ". " << songs[i] << endl;
        }
    }

    void addFromConsole() {
        cout << "Введите данные о песне (название в кавычках, артист, год, можно в любом порядке): ";
        string line;
        cin.ignore();
        getline(cin, line);

        istringstream iss(line);
        string token;
        vector<string> tokens;

        while (iss >> token) {
            tokens.push_back(token);
        }

        Song_info song;
        if (parseTokens(tokens, song)) {
            songs.push_back(song);
            cout << "Песня добавлена: " << song << endl;
        }
        else {
            cout << "Ошибка при обработке ввода." << endl;
        }
    }

    void editSong(int index) {
        if (index < 0 || index >= static_cast<int>(songs.size())) {
            cout << "Неверный номер песни." << endl;
            return;
        }

        Song_info& song = songs[index];
        cout << "Текущие данные:\n" << song << endl;

        string line;
        cout << "Введите новые данные (в любом порядке): ";
        cin.ignore();
        getline(cin, line);

        istringstream iss(line);
        string token;
        vector<string> tokens;

        while (iss >> token) {
            tokens.push_back(token);
        }

        Song_info newSong;
        if (parseTokens(tokens, newSong)) {
            song = newSong;
            cout << "Песня обновлена: " << song << endl;
        }
        else {
            cout << "Ошибка при обработке ввода." << endl;
        }
    }

    void findSong(const string& title, const string& artist) {
        bool found = false;
        for (size_t i = 0; i < songs.size(); ++i) {
            if (songs[i].title == title && songs[i].artist == artist) {
                cout << "Найдена песня под номером " << i + 1 << ": " << songs[i] << endl;
                found = true;
            }
        }
        if (!found)
            cout << "Песня не найдена." << endl;
    }

    void songsByArtist(const string& artist) {
        bool found = false;
        for (size_t i = 0; i < songs.size(); ++i) {
            if (songs[i].artist == artist) {
                cout << i + 1 << ". " << songs[i] << endl;
                found = true;
            }
        }
        if (!found)
            cout << "Песни этого исполнителя не найдены." << endl;
    }

    int getCount() const {
        return songs.size();
    }

    void removeSong(int index) {
        if (index < 0 || index >= static_cast<int>(songs.size())) {
            cout << "Неверный номер песни." << endl;
            return;
        }

        cout << "Удалена песня: " << songs[index] << endl;
        songs.erase(songs.begin() + index);
    }

private:
    bool parseTokens(const vector<string>& tokens, Song_info& song) {
        bool hasTitle = false, hasArtist = false, hasYear = false;

        for (const auto& token : tokens) {
            
            if (token.size() >= 2 && token.front() == '"' && token.back() == '"') {
                song.title = token.substr(1, token.size() - 2);
                hasTitle = true;
            }
           
            else if (all_of(token.begin(), token.end(), ::isdigit)) {
                song.year = stoi(token);
                hasYear = true;
            }
           
            else {
                song.artist = token;
                hasArtist = true;
            }
        }

        return hasTitle && hasArtist && hasYear;
    }
};

int getChoiceFromUser() {
    int choice;
    while (true) {
        if (cin >> choice) {
            return choice;
        }
        else {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Ошибка ввода. Введите число от 1 до 10: ";
        }
    }
}


void showMenu() {
    cout << "\n===== Меню =====\n";
    cout << "1. Загрузить данные из файла\n";
    cout << "2. Добавить песню вручную\n";
    cout << "3. Показать все песни\n";
    cout << "4. Сохранить в файл\n";
    cout << "5. Редактировать песню\n";
    cout << "6. Найти песню по названию и исполнителю\n";
    cout << "7. Показать песни исполнителя\n";
    cout << "8. Узнать количество песен\n";
    cout << "9. Удалить песню\n";
    cout << "10. Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "ru");
    

    SongLibrary library;
    int choice;

    do {
        showMenu();
        choice = getChoiceFromUser();

        switch (choice) {
        case 1: {
            string filename;
            cout << "Введите имя файла для загрузки: ";
            cin >> filename;
            library.loadFromFile(filename);
            break;
        }
        case 2:
            library.addFromConsole();
            break;
        case 3:
            library.displayAll();
            break;
        case 4: {
            string filename;
            cout << "Введите имя файла для сохранения: ";
            cin >> filename;
            library.saveToFile(filename);
            break;
        }
        case 5: {
            int index;
            cout << "Введите номер песни для редактирования: ";
            cin >> index;
            library.editSong(index - 1);
            break;
        }
        case 6: {
            string title, artist;
            cout << "Введите название песни: ";
            cin >> ws;
            getline(cin, title);
            cout << "Введите имя исполнителя: ";
            getline(cin, artist);
            library.findSong(title, artist);
            break;
        }
        case 7: {
            string artist;
            cout << "Введите имя исполнителя: ";
            cin >> ws;
            getline(cin, artist);
            library.songsByArtist(artist);
            break;
        }
        case 8:
            cout << "Количество песен: " << library.getCount() << endl;
            break;
        case 9: {
            int index;
            cout << "Введите номер песни для удаления: ";
            cin >> index;
            library.removeSong(index - 1);
            break;
        }
        case 10:
            cout << "Выход..." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 10);

    return 0;
}