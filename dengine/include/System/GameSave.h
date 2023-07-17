#ifndef DENGINE_GAMESAVE_H
#define DENGINE_GAMESAVE_H

#include <string>
#include "GameLevel.h"

namespace dengine{
    /**
     * @brief A GameSave file
     * GameSave is an abstract class that should be overwritten by the Game code. The purpose of gamesave
     * is to provide a method of saving a game.  This used in combination with a GameLevel's Serialize
     * and Deserialize functions should allow for an easy method of saving and loading.
     * @deprecated Marking this as deprecated because as mentioned in the Serializer documentation, I wasn't able to get
     * the save/load system working quite right.  If I happen to shift my attention back here and get it working we may keep it
     * but may not.  As such, don't count on it being here in the future.
     */
    class GameSave{
    public:
        GameSave();
        ~GameSave(){
            Objects.clear();
        }
        /**
         * Write is an abstruct funtion that has to be overwritten.  This function is to write a
         * save to disk.
         * @brief Function to write the savegame to disk
         * @param filename The filename
         */
        virtual void Write(const std::string filename) = 0;

        /**
         * Read is an abstruct funtion that has to be overwritten.  This function is to read a
         * save from disk into memory.
         * @brief Function to read a savegame from disk
         * @param filename The filename
         */
        virtual void Read(const std::string filename) = 0;

        /**
         * @brief Add an object to the Objects vector to be saved
         * @param object Object to be saved
         * @see Objects
         */
        void AddObject(GameObject* object){
            Objects.push_back(object);
        }

        /**
         * @brief Returns a vector containing all currently stored objects
         * @return Vector with all stored objects
         */
        std::vector<GameObject*> GetObjects(){
            return Objects;
        }
    private:
        /**
         * @brief Objects to be saved
         */
        std::vector<GameObject*> Objects;
    };
}

#endif //DENGINE_GAMESAVE_H
