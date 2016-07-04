#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "material.hpp"
#include "scene.hpp"


Scene loadFromFile(std::string const& filename);

int main(int argc, char* argv[])
{
	std::string filePath = "../../../Scenes/scene1.txt";

	Scene scene1 = loadFromFile(filePath);
	
	std::cout << "\nMaterials inside container:\n" << std::endl;
	for (auto i : scene1.materials) { std::cout << "Key: " << i.first << "\n" << i.second << std::endl; }
}


// SceneLoader

int getNext(int curPos, std::string const& txt)
{
	return txt.find_first_of(" ", curPos);
}

Scene loadFromFile(std::string const& filename)
{
	Scene scene{};
	std::map<std::string,Material> materials;

	std::ifstream file(filename);
	std::string line;

	while(std::getline(file, line))
	{
		// suche bis text begint
		auto begin = line.find_first_not_of(" ");
		line = line.substr(begin);

		std::vector<std::string> input;

		while(line.length() > 0)
		{
			int end = getNext(0, line);
			std::string cmd = line.substr(0, end);

			input.push_back(cmd);

			if (line.length() > 1 && end <= line.length()) { line = line.substr(end+1); }
			else { break; }
		}

		// input ausgabe
		//for (auto i : input) { std::cout << i << std::endl; }

		// define material
		if (input.size() > 1)
		{
			if (input[0] == "define" && input[1] == "material")
			{
				std::string name = input[2];
				std::cout << "\nCreating material " << name << "...";

				Color ka = input.size() > 5 ? Color{std::stof(input[3]),std::stof(input[4]),std::stof(input[5])} : Color{0.0f,0.0f,0.0f};
				std::cout << "\nka: " << ka.r << "," << ka.g << "," << ka.b;

				Color kd = input.size() > 8 ? Color{std::stof(input[6]),std::stof(input[7]),std::stof(input[8])} : Color{0.0f,0.0f,0.0f};
				std::cout << "\nkd: " << kd.r << "," << kd.g << "," << kd.b;

				Color ks = input.size() > 11 ? Color{std::stof(input[9]),std::stof(input[10]),std::stof(input[11])} : Color{0.0f,0.0f,0.0f};
				std::cout << "\nks: " << ks.r << "," << ks.g << "," << ks.b;

				float exp = input.size() > 12 ? std::stof(input[12]) : 1.0f;
				std::cout << "\nm: " << exp;

				/*
				Color ka = Color{0,0,0};
				Color kd = Color{0,0,0};
				Color ks = Color{0,0,0};
				float exp = 1.0f;
				*/

				Material m{name,ka,kd,ks,exp}; //create new material
				materials[name] = m; // save material to the map

				std::cout << "\n...finished!" << std::endl;
			}
			// else if ... more definitions...
		}
	}

	// add materials to scene
	scene.materials = materials;

	return scene;
}