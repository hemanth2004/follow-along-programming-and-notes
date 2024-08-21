#include <iostream>

using namespace std;

class ContactDetail
{
    private:
    string mobileNumber;
    string alternateMobileNumber;
    string email;
    public:
    ContactDetail(string _mb, string _amb, string _email)
    {
        mobileNumber = _mb;
        alternateMobileNumber = _amb;
        email = _email;
    }
    void Display()
    {
        cout << "Contact Details\n";
        cout << "Mobile Number: " << mobileNumber;
        cout << "Alternate Mobile Number: " << alternateMobileNumber;
        cout << "E-Mail ID: " << mobileNumber;
    }

    friend class ContactDetailBO;
};

class DuplicateMobileNumberException : public exception 
{
    public:

    string what()
    {
        return "DuplicateMobileNumberException";
    }
};

class ContactDetailBO
{
    public:
    bool Validate(ContactDetail cd)
    {
        if(cd.mobileNumber == cd.alternateMobileNumber)
        {
            DuplicateMobileNumberException _exception;
            throw _exception;
        }
        return true;
    }
};

int main()
{
    ContactDetail cd("987654321", "987654321", "cd@nitk.in");
    ContactDetailBO cd_bo;

    try
    {
        cd_bo.Validate(cd);
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    return 0;
}