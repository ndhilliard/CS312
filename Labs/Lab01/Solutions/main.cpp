#include <iostream>
#include <string>

bool ppe(std::string str) 
{
	int c = 0;
	
	for(auto i : str) 
	{
		if(i == '(' || i == ')') 
		{
			c += (i == '(')?(1):(-1);
		}
		
		if(c < 0) {return false;}
	}
	return (c == 0);
}

int main()
{
	std::string str;

	std::cout << "Enter a string: ";
	std::cin >> str;

	std::cout << std::boolalpha;
	std::cout << ("ppe(\"" + str + "\") = ") << ppe(str) << "\n";
	return 0;
}
