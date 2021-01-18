#include <iostream>

#include <fstream>

#include <conio.h>

#include <windows.h>

#include <mmsystem.h>

#include <string>

#include <vector>

#include<iterator>

#include <string>

#include <cstring>

using namespace std;

void avatar_1() {
    cout << endl << "        _, _,        ";
    cout << endl << "      .' .' |         ";
    cout << endl << "     /  /   /         ";
    cout << endl << "    _A_/__.'          ";
    cout << endl << "   .'   `A            ";
    cout << endl << "  ( ^     A          ";
    cout << endl << "   '.__    A          ";
    cout << endl << "      _)    '.        ";
    cout << endl << "  _.-'/       '.      ";
    cout << endl << " (__.'          A     ";
    cout << endl << "  .' .-.         ;    ";
    cout << endl << " (_.'   A        |`A  ";
    cout << endl << "      .--A      /   | ";
    cout << endl << "     (__.-'    /'--'  ";
    cout << endl << "       (______(	   ";
    cout << endl;
}
void avatar_2() {
    cout << endl << " A_____A ";
    cout << endl << "| . V . |";
    cout << endl << "| )   ( |";
    cout << endl << "|       |";
    cout << endl << "|       |";
    cout << endl << "|       |";
    cout << endl << "|       |";
    cout << endl << "| _____ |";
    cout << endl << " U     U ";
    cout << endl;
}

int choose_avatar() {
    int achoice;
    cout << "Avatar 1:" << endl;
    avatar_1();
    cout << "Avatar 2:" << endl;
    avatar_2();
    cout << "Chose an Avatar" << endl;
    cin >> achoice;
    return achoice;
}
void print_ava(int n) {
    if (n == 1) {
        avatar_1();
    } else {
        avatar_2();
    }

}
void credits() {
    cout << "Credits: CARSON RODRIGUES, REEV D'SOUZA, RITIKA GHANTI" << endl;
    cout << "Project Name: Playlist Management System" << endl;
    cout << "Special Thanks To Teacher Amrita Naik For Guiding Us To Make This Project Succesful" << endl;
}
vector < string > get_all_files_names_within_folder(string folder) {
    vector < string > names;
    string search_path = folder + "/*.*";
    WIN32_FIND_DATA fd;
    HANDLE hFind = ::FindFirstFile(search_path.c_str(), & fd);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                names.push_back(fd.cFileName);
            }
        } while (::FindNextFile(hFind, & fd));::FindClose(hFind);
    }
    return names;
}

class user {
    public:
        char name[100], password[100];
    int user_id, avatar_no;

    void add_user() {
        cin.ignore(256, '\n');
        cout << "Enter the Details" << endl << endl;

        cout << "Enter Name:" << endl;
        gets_s(name);

        cout << "Enter the password:" << endl;
        gets_s(password);
        cout << "Enter user id:" << endl;
        cin >> user_id;
        system("CLS");
        avatar_no = choose_avatar();
        system("CLS");
    }
    void check_login() {
        cout << "Enter Username:" << endl;
        gets_s(name);
        cout << "Enter password:" << endl;
        gets_s(password);
    }
    void print() {

        cout << "Name:" << name << endl;
        cout << "password:" << password << endl;
        cout << "userid:" << user_id << endl;
        cout << "avatar:" << avatar_no << endl;
        print_ava(avatar_no);
    }
    void change() {
        cin.ignore(256, '\n');
        cout << endl << "Enter new password:" << endl;
        gets_s(password);
    }
    int userid_return() {
        return user_id;
    }
    int avatar_num() {
        return avatar_no;
    }

    char * username_return() {
        return name;
    }
    char * userpassword_return() {
        return password;
    }

};

class playlist: public user {
    public: char pname[100];
    int plaid;
    int playlistid;
    int songno[100];
    vector < string > songname;
    int ns;

	playlist(int n){
        playlistid = 0;
		user_id=n;
	}

    void display_songs(int user_id) {

        if (plaid == user_id) {

            vector < string > files1 = get_all_files_names_within_folder("./songs");
            int kil = 1;

            cout << "	Playlist Number:" << playlistid << " | Playlist Name:" << pname << endl;

            for (vector < string > ::iterator i = files1.begin(); i != files1.end(); ++i) {

                for (int j = 1; j <= ns; j++) {

                    if (kil == songno[j]) {

                        cout << j << ") " << * i << endl;
                    }

                }
                kil++;
            }

            cout << endl;

        }

        int stop = 1;
        int oc = 0;
        int playstop = 0;
        int splay;
        cout << "Enter Song No. To Play" << endl;
        cin >> splay;
		system("CLS");

		if((splay>=1&&splay<=ns)){
			
		vector < string > files1 = get_all_files_names_within_folder("./songs");

		int kil=1;
		for (vector < string > ::iterator i = files1.begin(); i != files1.end(); ++i) {
        for (int j = 1; j <= ns; j++) {

            if (songno[j] == splay&&kil==songno[j]) {		
                    string ad = "songs/" + * i;
                    char * pa = & (ad[0]);
                    PlaySound(TEXT(pa), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                    cout << "Press 0 to stop playing song" << endl;
                    cin >> stop;
                    if (stop == 0) {
                        PlaySound(NULL, 0, 0);
                        playstop = 1;
                        system("CLS");
                        break;
                    }

				
                }
                if (playstop == 1) {
                    break;
                }


            }
		kil++;
		      if (playstop == 1) {
                break;
			}
        }
    
		}else{
		cout<<"Enter Correct Song No. To Play:"<<endl;
		}
		}
    int return_playlistid() {
        return playlistid;
    }

    void play_song() {

        vector < string > files2 = get_all_files_names_within_folder("./songs");
        int kit = 0;
        for (vector < string > ::const_iterator i = files2.begin(); i != files2.end(); ++i) {
            kit++;
            cout << kit << ") " << * i << endl;
        }
        int playstop = 0;
        int ch;
        cout << "Choose a Song To Play" << endl;
        cin >> ch;
        system("CLS");
        int stop = 1;
        vector < string > files5 = get_all_files_names_within_folder("./songs");
        int oc = 0;

        for (vector < string > ::const_iterator i = files5.begin(); i != files5.end(); ++i) {
            oc++;
            if (ch == oc) {
                string ad = "songs/" + * i;
                char * pa = & (ad[0]);
                PlaySound(TEXT(pa), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                cout << "Press 0 to stop playing song" << endl;
                cin >> stop;
                if (stop == 0) {
                    PlaySound(NULL, 0, 0);
                    playstop = 1;
                    system("CLS");
                    break;
                }
            } else if (ch > kit) {
                cout << "Press Correct Choice" << endl;
                system("pause");
                system("CLS");
                play_song();
            }
            if (playstop == 1) {
                break;
            }

        }
    }
    void create_playlist(int user_id) {

        cin.ignore(256, '\n');
        cout << "Enter the Details" << endl << endl;
        cout << "Enter Name of playlist " << ++playlistid << ": ";
        gets_s(pname);
		
        plaid = user_id;
        cout << "Choose A Song From Below:" << endl;

        vector < string > files = get_all_files_names_within_folder("./songs");
        int kep = 1;
        for (vector < string > ::const_iterator i = files.begin(); i != files.end(); ++i) {
            cout << kep << ") " << * i << ' ' << endl;
            kep++;
        }

        cout << "How many songs do you want to select:" << endl;
        cin >> ns;
        cout << "Enter The Song Numbers:" << endl;
        for (int i = 1; i <= ns; i++) {
            cin >> songno[i];
        }
        system("CLS");
    }

    void print_playlist(int user_id) {
		
        if (plaid == user_id) {

            vector < string > files1 = get_all_files_names_within_folder("./songs");
            int kil = 1;
            string song;
            cout << "Playlist is:" << playlistid << " | Playlist Name:" << pname << endl;
            for (vector < string > ::iterator i = files1.begin(); i != files1.end(); ++i) {

                for (int j = 1; j <= ns; j++) {

                    if (kil == songno[j]) {
                        //song=*i;
                        cout << * i << endl;
                    }

                }
                kil++;
            }

            cout << endl;

        }

    }
    char * username_return() {
        return pname;
    }

    void deleteit(int n) {

        int pos, flag = 0;

        ifstream ifs;
        ifs.open("playlist.txt", ios:: in | ios::binary);

        ofstream ofs;
        ofs.open("temp.txt", ios::out | ios::binary);

        while (!ifs.eof()) {

            ifs.read((char * ) this, sizeof(playlist));

            if (ifs) {               
                if (n == playlistid) {
                    flag = 1;
                } else { 
                    ofs.write((char * ) this, sizeof(playlist));
                }
            }
        }

        ofs.close();
        ifs.close();

        remove("playlist.txt");

        rename("temp.txt", "playlist.txt");

        if (flag == 1)
            cout << "\nPlaylist successfully deleted \n";
        else
            cout << "\nPlaylist not found \n";
    }

};

int main() {

    user emp;

    fstream f;
    fstream fp;
    int i = 1, id, c;
    while (i == 1) {
        cout << endl << "1. Sign Up\n2. Login\n3. Change password\n4. Credits \nChoose an option" << endl;
        cin >> c;
        system("CLS");
        switch (c) {
        case 1: {
            f.open("user.txt", ios:: in | ios::out | ios::app);
            cout << "Welcome to spotify" << endl;
            emp.add_user();
            f.write((char * ) & emp, sizeof(emp));
            cout << "User Added" << endl;
            f.close();
        }
        break;
        case 2: {
            int pos, flag = 0;
            char tname[100], tpassword[100];
            cin.ignore(256, '\n');
            cout << "Enter Username:" << endl;
            gets_s(tname);
            cout << "Enter password:" << endl;
            gets_s(tpassword);
            system("CLS");
            f.open("user.txt", ios:: in | ios::out| ios::app);

            while (!f.eof()) {
                pos = f.tellg();
                f.read((char * ) & emp, sizeof(emp));
                if (f) {

                    if (!strcmp(emp.username_return(), tname)) {

                        if (!strcmp(emp.userpassword_return(), tpassword)) {

                            flag = 1;
                            break;
                        } else {
                            flag = 2;
                            break;
                        }

                    }

                }
            }

            f.close();

            if (flag == 1) {
				playlist pla(emp.userid_return());
				
                cout << endl << "Login Succesful" << endl;
                cout << "\t Welcome " << emp.username_return() << " to spotify" << endl;
                print_ava(emp.avatar_num());
                int jpp = 1, id, pc;
                while (jpp == 1) {
                    cout << endl << "1. Create New Playlist\n2. Delete Playlist\n3. Show Playlist\n4. Show All Song\n5. Logout" << endl;
                    cin >> pc;
                    system("CLS");
                    switch (pc) {
                    case 1: {
                        fp.open("playlist.txt", ios:: in | ios::out | ios::app);

                        pla.create_playlist(emp.userid_return());

                        fp.write((char * ) & pla, sizeof(pla));

                        cout << "Playlist Added" << endl;

                        fp.close();
                    }
                    break;
                    case 2: {
                        int n;

                        fp.open("playlist.txt", ios:: in | ios::out);
                        cout << "Your playlists are:" << endl << endl;
                        while (fp.read((char * ) & pla, sizeof(pla))) {
                            pla.print_playlist(emp.userid_return());
                        }
                        fp.close();

                        cout << "Enter the playlist number you want to delete" << endl;
                        cin >> n;

                        pla.deleteit(n);
                    		system("CLS");
					}

                    break;
                    case 3: {
                        fp.open("playlist.txt", ios:: in | ios::out);
                        cout << "Your playlists are:" << endl << endl;
                        while (fp.read((char * ) & pla, sizeof(pla))) {

                            pla.print_playlist(emp.userid_return());

                        }
                        fp.close();
                        int pl;
                        cout << "Enter 0 To Exit or Enter A Playlist Number:" << endl;
                        cin >> pl;
						system("CLS");
                        fp.open("playlist.txt", ios:: in | ios::out);

                        while (fp.read((char * ) & pla, sizeof(pla))) {

                            if (pl == pla.return_playlistid()) {
								cout<<pla.playlistid;
                                pla.display_songs(emp.userid_return());
                            }

                        }

                        fp.close();
                    }
                    break;
                    case 4: {

                        pla.play_song();

                    }
                    break;
                    case 5:
                        jpp = 0;
                        break;
                    default:
                        cout << endl << "Please enter the correct option:" << endl;
                        break;
                    }
                }

            } else if (flag == 2) {
                cout << "Passowrd is wrong. Please try again." << endl;
            } else {
                cout << endl << "User Doesn't Exist! Sign Up User To Login." << endl;
            }
        }
        break;
        case 3: {
            int pos, flag = 0;
            cout << "Enter the user Id:" << endl;
            cin >> id;
            f.open("user.txt", ios:: in | ios::out);

            while (!f.eof()) {
                pos = f.tellg();
                f.read((char * ) & emp, sizeof(emp));
                if (f) {
                    if (emp.userid_return() == id) {
                        flag = 1;
                        emp.change();
                        f.seekp(pos);
                        f.write((char * ) & emp, sizeof(emp));
                        break;
                    }
                }
            }

            f.close();
            if (flag == 1){
				system("CLS");
                cout << endl << "Password Changed" << endl;
			}
            else{
                cout << endl << "User not found" << endl;
			}
        }
        break;
        case 4: {
            credits();
            break;
        }
        break;
        default:
            cout << endl << "Please enter the correct option:" << endl;
            break;
        }
    }

    return 0;
}