#include <iostream>
#include <fcntl.h>
#include<fstream>
using namespace std;
int main()
{
    CString strFileName = _T("program.txt");
    FILE *fStream;
    errno_t errCode = _tfopen_s(&fStream, strFileName, _T("r, ccs=UNICODE"));
    if (0 != errCode)
    {
        return FALSE;
    }
    CStdioFile File(fStream);
    CString strLine;
    while(File.ReadString(strLine))
    {
        //reading line-by-line
    }

}
