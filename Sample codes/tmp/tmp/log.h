#ifndef LOG_H
#define LOG_H

#include <iostream>     // used for cout
#include <fstream>      // used for write to file
#include <string>
#include <sys/timeb.h>  // used for time stamp
#include <mutex>

/* Declaration of variables */
static std::mutex mTex;

enum typelog {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    NOLOG
};

namespace LOGsettings{
    static typelog minLevel = INFO;
    static bool toCout = true;
    static std::string file = "../mylog.log";
}

class LOG{
public:
    #ifdef NOLOG
    explicit LOG(typelog type){;}
    #else
    explicit LOG(typelog type):type(type)
    {
        mTex.lock();
        if(type >= LOGsettings::minLevel)
        {
            ofs.open(LOGsettings::file,std::ofstream::app);
            addTime();
            operator << ("["+getLabel(type)+"] ");
        }
    }
    #endif

    #ifdef NOLOG
    ~LOG(){;}
    #else
    ~LOG()
    {
        if(type >= LOGsettings::minLevel)
        {
            if(opened)
            {

                if(LOGsettings::toCout)
                    std::cout << std::endl;
                ofs << std::endl;
            }
        }
        opened = false;
        ofs.close();
        mTex.unlock();
    }
    #endif
    #ifdef NOLOG
        inline LOG &operator<<(const uint8_t &msg){;}
    #else
    inline LOG &operator<<(const uint8_t &msg)
    {
        if(type >= LOGsettings::minLevel)
        {
            if(LOGsettings::toCout) std::cout << std::to_string(msg);
            ofs  << std::to_string(msg);
            opened = true;
        }
        return *this;
    }
    #endif
    #ifdef NOLOG
        template<class T>
        inline LOG &operator<<(const T &msg){;}
    #else
    template<class T>
    inline LOG &operator<<(const T &msg)
    {
        if(type >= LOGsettings::minLevel)
        {
            if(LOGsettings::toCout)
                std::cout << msg;
            ofs << msg;
            opened = true;
        }
        return *this;
    }
    #endif

private:
    bool opened = false;
    std::ofstream ofs;
    typelog type = DEBUG;
    static LOG * log;

    inline void pflush()
    {
        ofs.flush();
    }

    inline std::string getLabel(typelog type)
    {
        std::string label;
        switch(type) {
            case DEBUG: label = "DEBUG"; break;
            case INFO:  label = "INFO "; break;
            case WARN:  label = "WARN "; break;
            case ERROR: label = "ERROR"; break;
            default   : label = "DEBUG"; break;
        }
        return label;
    }

    inline void addTime(){
        timeb time;
        ftime(&time);
        int hours = ((time.time/3600)%24+2);
        if(time.dstflag) hours += 1;
        hours += (time.timezone/60);
        if(hours < 10) operator << (0);
        operator << (hours) <<":";
        int minutes = (time.time/60)%60;
        if(minutes < 10) operator << (0);
        operator << (minutes)<<":";
        int seconds = time.time%60;
        if(seconds < 10) operator << (0);
        operator << (seconds)<<".";
        int milliseconds = time.millitm;
        if(milliseconds < 100) operator << (0);
        if(milliseconds < 10) operator << (0);
        operator << (milliseconds) <<" ";
    }

};


#endif
