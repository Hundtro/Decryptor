#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Decryptor
{
	public:
	
	string DecryptValue(string val){
		
		if(val == "1") return "*LMOUSE*";
		if(val == "2") return "*RMOUSE*";
		if(val == "3") return "*CENCEL*";
		if(val == "4") return "*MMOUSE*";
		if(val == "8") return "*BACKSPACE*";
		if(val == "9") return "*TAB*";
		if(val == "12") return "*CLEAR*";
		if(val == "13") return "*ENTER*";
		if(val == "16") return "*SHIFT*";
		if(val == "17") return "*CONTROL*";
		if(val == "18") return "*ALT*";
		if(val == "19") return "*PAUSE*";
		if(val == "20") return "*CAPSLOCK*";
		if(val == "27") return "*ESC*";
		if(val == "32") return "*SPACE*";
		if(val == "33") return "*PAGE_UP*";
		if(val == "34") return "*PAGE_DOWN*";
		if(val == "35") return "*END*";
		if(val == "36") return "*HOME*";
		if(val == "37") return "*LEFT_ARROW*";
		if(val == "38") return "*UP_ARROW*";
		if(val == "39") return "*RIGHT_ARROW*";
		if(val == "40") return "*DOWN_ARROW*";
		if(val == "41") return "*SELECT*";
		if(val == "43") return "*EXECUTE*";
		if(val == "44") return "*PRINT_SCREEN*";
		if(val == "45") return "*INSERT*";
		if(val == "46") return "*DELETE*";
		if(val == "47") return "*HELP*";
		
		if(val == "48") return "0";
		if(val == "49") return "1";
		if(val == "50") return "2";
		if(val == "51") return "3";
		if(val == "52") return "4";
		if(val == "53") return "5";
		if(val == "54") return "6";
		if(val == "55") return "7";
		if(val == "56") return "8";
		if(val == "57") return "9";
		
		if(val == "65") return "A";
		if(val == "66") return "B";
		if(val == "67") return "C";
		if(val == "68") return "D";
		if(val == "69") return "E";
		if(val == "70") return "F";
		if(val == "71") return "G";
		if(val == "72") return "H";
		if(val == "73") return "I";
		if(val == "74") return "J";
		if(val == "75") return "K";
		if(val == "76") return "L";
		if(val == "77") return "M";
		if(val == "78") return "N";
		if(val == "79") return "O";
		if(val == "80") return "P";
		if(val == "81") return "Q";
		if(val == "82") return "R";
		if(val == "83") return "S";
		if(val == "84") return "T";
		if(val == "85") return "U";
		if(val == "86") return "V";
		if(val == "87") return "W";
		if(val == "88") return "X";
		if(val == "89") return "Y";
		if(val == "90") return "Z";
		
		
		if(val == "144") return "*NUM_LOCK*";
		
		if(val == "160" || val == "162" || val == "164") return "*L*";
		if(val == "161" || val == "163" || val == "165") return "*R*";
		
		return "*unknow*";
	}
	
	string DecryptText(string dec_text)
	{
		string enc_text;
		unsigned int i = 0;
		string xx;
		
		while(i != dec_text.size())
		{
			if(dec_text[i] != '.')
			{
				xx.push_back(dec_text[i]);
			}
			else
			{
				enc_text += DecryptValue(xx);
				xx.clear();
			}
			
			i++;
		}
		
		return enc_text;
	}
};

int main(int argc, char **argv)
{
	string code;
	string result;
	
	ifstream fromfile;
	ofstream tofile;
	
	fromfile.open("code_log");
	
	fromfile >> code;
	
	fromfile.close();
	
	Decryptor dec;
	
	result = dec.DecryptText(code);
	
	tofile.open("encrypted");
	
	tofile << result;
	
	tofile.flush();
	
	tofile.close();
	
	return 0;
}
