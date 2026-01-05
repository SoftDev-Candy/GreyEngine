//
// Created by Candy on 1/4/2026.
//

#include "ObjLoader.hpp"
#include<fstream>
#include<iostream>
#include <sstream>
#include<string>
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

ObjMeshData LoadOBJ(const std::string &path)
{
ObjMeshData Data;
std::ifstream objFile(path);
    if(!objFile.is_open())
{
    std::cerr<<"[OBJLoader] Failed to open OBJ"<<std::endl;
    return Data;

}
    int vCount = 0;
    int vnCount = 0;
    int vtCount = 0;
    int fCount = 0;

    //To store vectors and UV's
    std::vector<glm::vec3>positions;
    std::vector<glm::vec2>uvs;

    std::string line;
    // Absolutely no clue what I did here ......and i forgot to doc it!
    //I mean I do know what I did its just reading a file a and finding
    //the right count for the vertices or faces etc and adding their values still not very clear
    while(std::getline(objFile , line))
      {
        if (line.empty())
        {
            continue;
        }
        if(line.find("v " , 0) == 0)
        {
            vCount++;

        }
        else if(line.find("vt " , 0) == 0){vtCount++;}
        else if(line.find("vn " , 0) == 0){vnCount++;}
        else if(line.find("f " , 0) == 0){fCount++;}

          std::stringstream iss(line);

      }


//TODO -- Remember to delete this please here to just test this HO~ //
    std::cout << "[ObjLoader] " << path
          << " | v=" << vCount
          << " vt=" << vtCount
          << " vn=" << vnCount
          << " f=" << fCount
          << "\n";


    return Data;

}
