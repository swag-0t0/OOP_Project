/*
                        **HOSPITAL MANAGEMENT SYSTEM**

    In this project hospital author will input data of a patient and program will find from file if there any
    doctor available or not on the required sphere.

    At first program will ask if you are a doctor or a patient
    then if you are doctor it will ask your expertise area,name.
    If it is found in the file,it will not append
    If not found then it will append in the file.
    (NOTE: You must enter the first letter as capital for Name and Expertise)

    If you are patient you have to provide your details.
    The details patient provided will be saved in a file.
    patient will be asked what kinda doctor he needed.
    THEN IT WILL SHOW DOCTORS FROM THE LIST(FILE) AVAILABLE AS REQUIRED.
*/

#include <bits/stdc++.h>
using namespace std;

class Doctor
{
private:
    string specialist;
    string name;
    string phoneNumber;

public: 
    void setSpecialist(const string &doctorSpecialist)
    {
        specialist = doctorSpecialist;
    }
    void setName(const string &doctorName)
    {
        name = doctorName;
    }
    void setPhoneNumber(const string &doctorPhoneNumber)
    {
        phoneNumber = doctorPhoneNumber;
    }
    void write_doctors()            //doctors details are written in tha file"doctor_details"
    {
        ofstream file("doctor_details.txt",ios :: app);
         if (file.is_open()) {
            
            file << specialist << endl;
            file << name << endl;
            file << phoneNumber << endl;
            file.close();
            cout << "New doctor details added to file."<<endl<<"Thank you!"<< endl;
        } 
        else {
            cout << "Unable to open the file."<< endl;
        }
    }   
};

class Patient
{
private:
    string name;
    string address;
    string phoneNumber;

public:
    void setName(const string &patientName)
    {
        name = patientName;
    }

    void setAddress(const string &patientAddress)
    {
        address = patientAddress;
    }

    void setPhoneNumber(const string &patientPhoneNumber)
    {
        phoneNumber = patientPhoneNumber;
    }

    void write_patients()                                   //patients details are written though this
    {
        ofstream file("patient_details.txt",ios :: app);
         if (file.is_open()) {
            file <<"Name: " << name << endl;
            file<< "Address: " << address << endl;
            file<<"Phone Number: " << phoneNumber << endl;
            file.close();
            cout <<"Patient details written to file."<< endl;
        } 
        else {
            cout <<"Unable to open the file."<< endl;
        }
    }   
};

void available_Doctors(const string &patientDisease)        //this will compare expertise and requirement of patient
{
    ifstream newFile("doctor_details.txt");                 //Opens file
    if (!newFile)
    {
        cout << "Unable to open the file." << endl;
        return;
        
    }
    // cout << "File operation successful.\n";
    if (newFile)
    {
        string specialist, doctorName, doctorNum;
        int count = 1;
        cout<< "Available doctors: "<<endl;
        while (!newFile.eof())                               //lopp runs till end of file;
        {

            // getline(newFile, name);
            getline(newFile, specialist);                        //expertise er line ta nibe,specialist er moddhe rakhbe
            if (patientDisease == specialist)                     //will compare
            {
                getline(newFile, doctorName);                      //will take name from file
                getline(newFile, doctorNum);                        //will take phone number form file
                cout<< count<<"."<< "\nDoctor Name: " << doctorName;       //will show name
                cout<< "\nContact No: " << doctorNum << "\n";           //will show phone number
                count++;
            }
            // getline(newFile, phoneNumber);
            //  cout << name << " " << specialist << " " << phoneNumber << "\n";
        }
        if (count == 1)                                                             //doctor as required na pele count 1 ii theke jabe
            cout << "sorry!No Doctor available at this moment.\n";
    }
    newFile.close();

    // return (patientDisease == doctor.getSpecialist());
}

bool Find_doctor(string& expertise,string & dname)      //this bool function will compare doctors name and expertise_in
{                                                       //from the file and will return value true or false
    ifstream file("doctor_details.txt");
    bool flag = false;
    if(!file)
    {
        cout<<"file does not exist or could not open. ";
        return 0;
    }
    else
    {
        string Area,name;
        while(!file.eof())
        {
            getline(file,Area);
            if( expertise==Area)                 //at first expertise area compare korci
            {                                          
                // cout << "Expertise found\n";
                getline(file,name);                 
                if (name == dname) {                                //jodi equal hoy tokhon name compare korci
                    // cout << "Name found: " << name << "\n";
                    flag = true;                                    //file er sesh porjonto dekhbe name true ase kina
                    file.close();
                    return true;
                } 
                else                                                //equal na pele theme jabe na
                    continue;                                       // porer tay search korbe
            }
        } file.close();
    }
    if (flag == false) return false;                                //Loop completely ghure na pele false dekhabe

}
int main()
{
    // Doctor d_obj;
    // d_obj.readDoctorDetails("doctor_details.txt");
    int x;
    cout << "Adding doctor or patient?" << endl
         << "1.Doctor" << endl
         << "2.Patient" << endl;
    cout<<"Input 1 or 2: ";
    cin>>x;     
    switch (x)
    {
    case 1:
    {
        Doctor d_obj;
        string expertise_area,Yourname;
        cout<<"Enter your expertise area: ";
        cin>>expertise_area;
        cout<<"Enter your name: ";
        cin>>Yourname;

        if(Find_doctor(expertise_area,Yourname))
        {
            cout<<"You are already registered as doctor.";
        }
        else
        {
            d_obj.setSpecialist(expertise_area);
            d_obj.setName(Yourname);
            string phone;
            cout<<"You are not registered!"<<endl<<"To resister Enter your phone number: ";
            cin>>phone;
            d_obj.setPhoneNumber(phone);
            d_obj.write_doctors();
        }
        break;                                                      //Important ,otherwise it will take patient details also
    }
    case 2:
    {
        Patient patient;
        string patientName, patientAddress, patientPhoneNumber;
        cout << "Enter patient's details:" << endl;
        cout << "Name: ";
        cin>>patientName;
        patient.setName(patientName);
        cout << "Address: ";
        cin>>patientAddress;
        patient.setAddress(patientAddress);
        cout << "Phone Number: ";
        cin>>patientPhoneNumber;
        patient.setPhoneNumber(patientPhoneNumber);

        string patientDisease;
        cout << "Patient's disease in: ";
        cin>>patientDisease;

        patient.write_patients();
        available_Doctors(patientDisease);
        break;
    }
    
    }
    
    return 0;
}