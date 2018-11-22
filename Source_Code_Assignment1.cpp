#include <iostream>
#include <string>
#include <fstream>
#include <bitset>

using namespace std;
string G;
 ofstream out("output.txt");
string Generator()
 {
     ifstream infile; 
     infile.open("input.txt"); 
	 string m;
	 string R="";
	 infile >> m;
	 infile >> G;
	 int m_length = m.length();
	 int G_length = G.length();
	 R += m;
	 for(int j=0; j<G_length-1; j++)
		 R += '0';

	 for(int i=0; i<R.length()-(G_length-1); )
	 {
		 for(int j=0; j<G_length; j++)
			 R[i+j] = (R[i+j]==G[j])? '0':'1';
		 for( ; i<R.length() && R[i]!='1' ; i++);
	 }
	 cout << "The Original Message is " << m << endl ;
	  out << "The Original Message is " << m << endl ;
	 cout << "The Generator is " << G << endl ;
	 out <<  "The Generator is " << G << endl ;
	 return m + R.substr(R.length()-G_length+1);

 }
string Verifier(string transmitted_message , string G )
{
	string output = "Message is correct";
	for(int i=0; i<transmitted_message.length()-(G.length()-1); )
	 {
		 for(int j=0; j<G.length(); j++)
			 transmitted_message[i+j] = (transmitted_message[i+j]==G[j])? '0':'1';
		 for( ; i<transmitted_message.length() && transmitted_message[i]!='1' ; i++);
	 }
	for( char i: transmitted_message.substr(transmitted_message.length()-G.length() ))
		if(i != '0')
		{
			output = "Message is not correct";
		}
		return output;
}
void alter(string &transmitted_msg, int index)
{
	char bit = (transmitted_msg[index-1]== '0') ? '1' : '0';
	transmitted_msg.replace(index-1, 1,1, bit);
}
 void main()
 {
	 
	  string transmitted_msg = Generator();
	  cout<<"The Transmitted Message is " << transmitted_msg<<endl;
	  out <<"The Transmitted Message is " <<  transmitted_msg << endl;
	 int input;
	 cout<<"if you want to perform alter on the message enter the index of alter .. if not press 0"<<endl;
	 cin>>input;
	 if(input == 0)
	 {
		cout<<Verifier(transmitted_msg , G)<<endl;
		out << Verifier(transmitted_msg , G) << endl;
	 }
	 else
	 {

		 int index = input;
		 alter(transmitted_msg , index);
		 cout<<Verifier(transmitted_msg , G)<<endl;
		 out << Verifier(transmitted_msg , G) << endl;
	 }

 }
