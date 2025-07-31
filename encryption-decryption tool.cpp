#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void welcome()
{
	cout<<"====Welcome to File Encryption-Decryption Tool====(^-^)\n"<<endl;
}
// Ftn for file encryption.....
void encryptfile(string &encryptedfile,int &shift)
{
	string filename;
	char ch;
	cout<<"Enter file name you want to encrypt (with .txt):"<<endl;
	getline(cin,filename);
	cout<<"Enter file name to save encryption (with .txt):"<<endl;
	getline(cin,encryptedfile);
	while(true)
	{
		cout<<"Enter shift value betwen 1 and 25:"<<endl;
		cin>>shift;
		if(shift>=1 && shift<=25)
		{
			break;
		}
		else
		{
			cout<<"Invalid shift value :( Try between 1 & 25...."<<endl;
		}
	}
	ifstream input(filename);
	ofstream output(encryptedfile);
	if(!input || !output)
	{
		cout<<"Error in opening file!"<<endl;
		return;
	}
	while(input.get(ch))
	{
		ch=ch+shift;
		output<<ch;
	}
	input.close();
	output.close();
	cout<<"Encryption completed successfully(*-*)...Encrypted data stored in "<<encryptedfile<<endl;	
}
// Ftn for file decryption...
void decryptfile(string encryptedfile,int shift)
{
	string outputfile;
	char ch;
	cout<<"Enter output file name to save decryption (with .txt):"<<endl;
	getline(cin,outputfile);
	ifstream input(encryptedfile);
	ofstream output(outputfile);
	if(!input || !output)
	{
		cout<<"Error in opening file!"<<endl;
		return;
	}
	while(input.get(ch))
	{
		ch=ch-shift;
		output<<ch;
	}
	input.close();
	output.close();
	cout<<"Decryption completed successfully (*-*)...Decrypted data stored in "<<outputfile<<endl;	
}
void goodbye()
{
	cout<<"\n====Thankyou for using this tool====(^-^)"<<endl;
}
int main()
{
welcome();
string encryptedfile;
int shift;
char choice;
encryptfile(encryptedfile,shift);//ftn call for encryption
cout<<"Do you want to decrypt the file now? (y/n)"<<endl;
cin>>choice;
cin.ignore();
if(choice == 'Y'||choice == 'y')
{
	decryptfile(encryptedfile,shift);
}
else
{
	cout<<"Program finished without decryption:( "<<endl;
}
goodbye();
return 0;
}
