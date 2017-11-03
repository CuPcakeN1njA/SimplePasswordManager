#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void retPassword(string password){
	string crypt;
	string myPassword;
	string finalPass = "";
	string line;
	string website;
	int length = password.length();
	int choice;
	int counter = 1;
	ifstream webList ("manager/weblist.txt");
	cout << "Please choose a website from the following: \n";
	while ( getline (webList,line) )
    {
      cout << counter << " => " << line << '\n';
      counter++;
    }
    cout << "Your Choice: " ;
    counter = 1;
    cin >> choice;
    webList.clear();
    webList.seekg(0, ios::beg);
    while ( getline (webList,line) )
    {
      if (counter == choice){
		  website = line;
		  }
      counter++;
    }
    cout << "You selected: " << website << "\n";
    ifstream passFile ("manager/" + website + ".txt");
    counter = 0;
    while ( getline (passFile,line) )
    {
		if (counter > length){
			counter = 0;
		}
		crypt = char(stoi(line) xor int(password[counter]));
		finalPass = finalPass + crypt;
		counter++;
		}
	cout << "Your Password is: " << finalPass;
	
	}
	
void newPassword(string password){
	string crypt;
	string website;
	string filename;
	ofstream newFile;
	ofstream webList;
	string myPassword;
	string finalPass = "";
	int length = password.length();
	int counter = 0;
	cout << "Please enter the website: ";
	cin >> website;
	webList.open("manager/weblist.txt", ios::app);
	webList << website + "\n";
	webList.close();
	filename = website + ".txt";
	cout << "Please enter the Password for this website: ";
	cin >> myPassword; 
	for(char& c : myPassword){
		if (counter > length){
			counter = 0;
			}
		crypt = std::to_string(int(c) xor int(password[counter]));
		finalPass = finalPass + crypt + "\n";
		counter++;
		}
	newFile.open("manager/" + filename);
	newFile << finalPass;
	newFile.close();
	}
	
void delPassword(){
	string website;
	string filename;
	string fileList;
	string line;
	int choice;
	int counter;
	ofstream webList;
	ifstream wList ("manager/weblist.txt");
	counter = 1;
	cout << "Please Select which website to delete: \n";
	while ( getline (wList,line) )
    {
		cout << counter << " => " << line << '\n';
		counter++;
    }
    cout << "Your Choice: " ;
    counter = 1;
    cin >> choice;
    wList.clear();
    wList.seekg(0, ios::beg);
    while ( getline (wList,line) )
    {
	if (counter == choice){
		website = line;
		}
	else{
		fileList = fileList + line + "\n";
		}
		counter++;
    }
    filename = website + ".txt";
	remove(("manager/" + filename).c_str());
	wList.close();
	webList.open("manager/weblist.txt");
	webList << fileList;
	webList.close();
	
	}
	
void showWebsites(){
	int counter = 1;
	string line;
	ifstream webList ("manager/weblist.txt");
	cout << "Site list: \n";
	 while ( getline (webList,line) )
    {
      cout << counter << " => " << line << "\n";
      counter++;
    }
}

void prog_exit(){
	exit(0);
}
	

int main(){
	int choice;
	string password;
	cout << "Please enter your Manager Password: ";
	cin >> password;
	while (true){
	const char *menu = "\nPlease select an option: \n"
	"1 = > Retrieve Password  \n"
	"2 = > Add a new Password \n"
	"3 = > Delete Password \n"
	"4 = > Show stored Website \n"
	"5 = > Exit \n"
	"Your Choice: ";
	cout << menu;
	cin >> choice;
		
	if ((choice <=0)||(choice >=6)){
		cout << "That is not an option!";
		}
	else if (choice == 1){
		retPassword(password);
		}
	else if (choice == 2){
		newPassword(password);
		}
	else if (choice == 3){
		delPassword();
		}
	else if (choice == 4){
		showWebsites();
		}	
	else if (choice == 5){
		prog_exit();
		}
	}
}
