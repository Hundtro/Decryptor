#include <iostream>
#include <string>
#include <list>

using namespace std;

class Decryptor
{
	string code;
	list<string> codes;
	
	public:
	
	void GetText(string text)
	{
		code = text;
	}
	
	string DecryptText()
	{
		return "";
	}
	
	private:
	string DecryptValue(string val){
		
		if(val == "1") return "*LM*";
		if(val == "2") return "*RM*";
		if(val == "16") return "*SHIFT_";
		if(val == "32") return "*SPACE*";
		
		if(val == "160" || val == "162" || val == "164") return "L*";
		if(val == "161" || val == "163" || val == "165") return "R*";
		
		return "*unknow*";
	}
};

int main(int argc, char **argv)
{
	Decryptor dec;
	
	return 0;
}
