#pragma once

class TimeStamp {
    int time;
public:
    TimeStamp(int time) : time(time) {}
    int getTime(){
        return time;
    }
};