#ifndef TIME__H_
#define TIME__H_


namespace bulb
{

class Time
{
public:
   Time() = default;
   Time(const Time&) = delete;
   Time& operator=(const Time&) = delete;

   static unsigned int ComputeDeltaTime();
   static void DelayTime();

   static float deltaTime;

private:
   inline const static unsigned int FPS = 60;
   inline const static unsigned int FRAME_DELAY = 1000 / FPS;
//Maximum Delta Time
   inline const static unsigned int MAX_DT = 50; 

//Time when current frame started
   static unsigned int m_frameStart;  
//Last frame start time 
   static unsigned int m_lastFrame;   
//Time needed to run the loop 
   static unsigned int m_frameTime;    
};

}
#endif
