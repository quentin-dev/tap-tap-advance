#ifndef NOTE_H
#define NOTE_H

class Note
{
    public:

        Note(float spawn_time)
        {
            this->spawn_time = spawn_time;    
        }
        
        float spawn_time;
    
    private:
};

#endif