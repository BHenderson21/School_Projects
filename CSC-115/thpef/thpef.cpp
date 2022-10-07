/** **************************************************************************************
* @file
*****************************************************************************************/
#include "thpef.h"

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Returns a string containing the current date in the format dd mon, yyyy
 *
 *  @param[in] N/A
 *
 *  @returns N/A
 *
 *  @par Example
 *  @verbatim
    
    string date = getDate(); // date would equal "25 Dec, 2021"
    
 *  @endverbatim
************************************************************************/

string getDate()
{
    time_t myTimeT = time(nullptr);
    string currentTime = ctime(&myTimeT);
    string day = currentTime.substr(8, 2);
    string month = currentTime.substr(4, 3);
    string year = currentTime.substr(20, 4);
    string formattedDate = day + " " + month + ", " + year;
    return formattedDate;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  given an if stream and a member structure, fills in the structure with data from the ifstream
 *
 *  @param[in] An ifstream containing data to put into the structure
 *             A member structure
 *
 *  @returns True if data is inserted propperly, and false if it isn't
 *
 *  @par Example
 *  @verbatim
    
    ifstream fin;
    member currentMember;
 
    getClient(fin, currentMember); \\ Would fill currentMember with the data from fin.
    
 *  @endverbatim
************************************************************************/

bool getClient(ifstream& fin, client& currentMember)
{
    string temp = "";
    if(getline(fin, temp, ','))
    {
        currentMember.first = temp;
    }
    else
    {
        return false;
    }
    if(getline(fin, temp, ','))
    {
        currentMember.last = temp;
    }
    else
    {
        return false;
    }
    if(getline(fin, temp, ','))
    {
        currentMember.address = temp;
    }
    else
    {
        return false;
    }
    if(getline(fin, temp, ','))
    {
        currentMember.city = temp;
    }
    else
    {
        return false;
    }
    if(getline(fin, temp, ','))
    {
        currentMember.state = temp;
    }
    else
    {
        return false;
    }
    if(getline(fin, temp, ','))
    {
        currentMember.zip = temp;
    }
    else
    {
        return false;
    }
    if(getline(fin, temp, ','))
    {
        ostringstream tempStream;
        tempStream << fixed;
        tempStream << setprecision(2);
        tempStream << temp;
        temp = tempStream.str();
        tempStream.str("");
        currentMember.transactionAmount = stod(temp);
    }
    else
    {
        return false;
    }
    if(getline(fin, temp))
    {
        ostringstream tempStream;
        tempStream.precision(2);
        tempStream << fixed << showpoint << setprecision(2); 
        tempStream << temp;
        temp = tempStream.str();
        tempStream.str("");
        currentMember.currBal = stod(temp);
    }
    else
    {
        return false;
    }
    return true;    
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a member structure, a templateFile name and the current date,
 *  fills in the template with the propper information from the member
 *
 *  @param[in] member structure filled in with data
 *             string template file name
 *             string containing the date
 *
 *  @returns N/A
 *
 *  @par Example
 *  @verbatim
    
    writeLetter(currentMember, templateFile, date); // Fills in the template file with info from the member, and writes to an output file.
    
 *  @endverbatim
************************************************************************/

void writeLetter(client& currentMember, string templateFile, string date)
{
    string outputFile = currentMember.first + "." + currentMember.last + ".txt";
    ofstream fout;
    ifstream fin;
    string tempLine;
    string temp;
    if(!openInput(fin, templateFile))
    {
        cout << "Unable to open the template file: " + templateFile << endl;
        return;
    }
    if(!openOutput(fout, outputFile))
    {
        cout << "Unable to open the output file: " + outputFile << endl;
        return;
    }
    
    while(getline(fin, tempLine))
    {
        
        if(tempLine.find("#TRANSACTION") != string::npos)
        {
            ostringstream tempStream;
            tempStream.precision(2);
            tempStream << fixed << showpoint << setprecision(2); 
            tempStream << fabs(currentMember.transactionAmount);
            temp = tempStream.str();
            tempStream.str("");
            tempLine.replace(tempLine.find("#TRANSACTION"), 12, temp);
        }
        if(tempLine.find("#FULLNAME") != string::npos)
        {
            tempLine.replace(tempLine.find("#FULLNAME"), 9, (currentMember.first + " " + currentMember.last));
        }
        if(tempLine.find("#ADDRESS") != string::npos)
        {
            tempLine.replace(tempLine.find("#ADDRESS"), 8, currentMember.address);
        }
        if(tempLine.find("#CITY") != string::npos)
        {
            tempLine.replace(tempLine.find("#CITY"), 5, currentMember.city);
        }
        if(tempLine.find("#STATE") != string::npos)
        {
            tempLine.replace(tempLine.find("#STATE"), 6, currentMember.state);
        }
        if(tempLine.find("#ZIP") != string::npos)
        {
            tempLine.replace(tempLine.find("#ZIP"), 4, currentMember.zip);
        }
        if(tempLine.find("#FIRST") != string::npos)
        {
            tempLine.replace(tempLine.find("#FIRST"), 6, currentMember.first);
        }
        if(tempLine.find("#LAST") != string::npos)
        {
            tempLine.replace(tempLine.find("#LAST"), 5, currentMember.last);
        }
        if(tempLine.find("#DATE") != string::npos)
        {
            tempLine.replace(tempLine.find("#DATE"), 5, date);
        }
        if(tempLine.find("#BALANCE") != string::npos)
        {
            ostringstream tempStream;
            tempStream.precision(2);
            tempStream << fixed << showpoint << setprecision(2); 
            tempStream << (currentMember.currBal + currentMember.transactionAmount);
            temp = tempStream.str();
            tempStream.str("");
            tempLine.replace(tempLine.find("#BALANCE"), 8, temp);
        }
        fout << tempLine << endl;
    }
    
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an file stream and a file name, opens the file to the stream
 *
 *  @param[in] fin An input stream
 *             fileName A file name
 *
 *  @returns A bool, indicating if the file was successfully opened
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    ifsteam fin;
    name = "test.txt";
    name2 = "test";
    
    result = openInput(fin, name); // result would be true
    
    result = openInput(fin, name2); // result would be false. 
    
    
 *  @endverbatim
************************************************************************/

bool openInput(ifstream& fin, string fileName)
{
    fin.open(fileName);
    if(!fin.is_open())
    {
        return false;
    }
    return true;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an file stream and a file name, opens the file to the stream
 *
 *  @param[in] fout An output stream
 *             fileName A file name
 *
 *  @returns A bool, indicating if the file was successfully opened
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    ofsteam fout;
    name = "test.txt";
    name2 = "test";
    
    result = openOutput(fin, name); // result would be true
    
    result = openOutput(fin, name2); // result would be false. 
    
    
 *  @endverbatim
************************************************************************/

bool openOutput(ofstream& fout, string fileName)
{
    fout.open(fileName);
    if(!fout.is_open())
    {
        return false;
    }
    return true;
}