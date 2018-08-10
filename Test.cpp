
#include "./include/Test.h"

using namespace std;
using namespace chrono;

string SpeedTest::openFile()
{
    auto res = mkdir(name.c_str(),-1);
    if(res && errno != EEXIST)
        return ("cant open directory" + name);

    string path=name+"/"+realization;
    res = mkdir(path.c_str(),-1);
        if(res && errno != EEXIST)
            return ("cant open directory" + name);

    path =  path+"/"+ver+".tm";
    file.open(path, ios_base::app);

    if(file.is_open() == false)
        return ("cant open or create file " + path);

    return "";

}
