
# include "iostream"
int main(void)
{
std::string var = "DAMIANO";

std::string *ptr = &var; 

std::string &ref = var; 
std::cout << "POINTERS OF " << std::endl;
std::cout << "\tPOINTER " << &ptr << "\n\tREFERENCE " << &ref << "\n\tVAR " <<&var << std::endl;

std::cout << "VALUES OF " << std::endl;
std::cout << "\tPOINTER " << ptr << "\n\tREFERENCE " << ref << "\n\tVAR " << var << std::endl;



return 0;	
}