#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

int h;
int m;
int s;

void cl()
{
  std::string in;
  std::cin>>in;
  
  std::string cmds[6] = {"help", "exit", "about", "set", "see", "start"};
  
  if(in=="help")
  {
  std::cout<<"List of avaiable commands:"<<std::endl<<std::endl;
  std::cout<<"help - shows list of avaiable commands"<<std::endl;
  std::cout<<"exit - exits the program"<<std::endl;
  std::cout<<"about - information of software"<<std::endl;
  std::cout<<"set - begin setting timer values"<<std::endl;
  std::cout<<"see - allows to see timer values"<<std::endl;
  std::cout<<"start - start the timer"<<std::endl;
  cl();
  }
  
  if(in=="exit")
  {
    std::cout<<"The program is now exiting!"<<std::endl;
  }
  
  if(in=="about")
  {
    std::cout<<"Software name: Timer -  author: dawidg81 - last build: 2025-05-25-7:30PM - version: 0-1"<<std::endl;
    cl();
  }
  
  if(in=="set")
  {
    std::cout<<"Hours: ";
    std::cin>>h;
    std::cout<<"Minutes: ";
    std::cin>>m;
    std::cout<<"Seconds: ";
    std::cin>>s;
    cl();
  }
  
  if(in=="see")
  {
    std::cout<<"Hours: "<<h<<" Minutes: "<<m<<" Seconds: "<<s<<std::endl;
    cl();
  }
  
  if(in=="start")
  {
    while(h > 0 || m > 0 || s > 0)
    {
      std::cout
        << (h < 10 ? "0" : "") << h << ":"
        << (m < 10 ? "0" : "") << m << ":"
        << (s < 10 ? "0" : "") << s << "\r"<<std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
      
        if(s > 0)
        {
          s--;
        } else {
          if(m > 0)
          {
            m--;
            s = 59;
            } else {
              if(h > 0)
              {
                h--;
                m = 59;
                s = 59;
              }
            }
          }
        }
        std::cout << "Time's up!" << std::endl;
        cl();
      }
  bool found=false;
  
  for(const auto& cmd : cmds)
  {
    if(in==cmd)
    {
      found = true;
      break;
    }
  }
  
  if(!found)
  {
  std::cout<<in<<" is invalid or unknown. See 'help' for avaiable commands, or take a look at help.html that should come with the installation."<<std::endl;
  cl();
}
  
}

int main() {
  cl();
  return 0;
}
