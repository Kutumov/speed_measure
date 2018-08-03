#ifndef TEST
#define TEST

#include <chrono>
#include <string>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <boost/type_index.hpp>
#include <stdexcept>

class SpeedTest
{
public:
    SpeedTest(const std::string& name, const std::string ver): name(name), ver(ver)
    {}

    template<typename Pref, typename F, typename... Args>
    Pref
    measure(int inputWeight, F&& code, Args&&... args)
    {
        using namespace std;
        using namespace std::chrono;
        static_assert(__is_duration<Pref>::value, "Result must be duration");

        auto start = high_resolution_clock::now();
        code(args...);
        auto dur = (high_resolution_clock::now() - start);

        auto outDur = duration_cast<Pref>(dur);

        std::cout<<"Execution duration "<<outDur.count()<<std::endl;

        if(file.is_open() == false)
        {
            auto err = openFile();
            if(err.size())
                throw std::runtime_error(err);
        }

        auto  out = make_pair(inputWeight,dur.count());
        file.write((char*)&out,sizeof(out));

        return outDur;
    }
private:
    std::string openFile();

    std::fstream file;
    std::string name;
    std::string ver;

};

#endif
