#include "Movie.h"
#include <Windows.h>
#include <fstream>
#include <iostream>

MovieList::MovieList() 
{
   list.clear();
}

MovieList::~MovieList()
{

}

std::vector<std::string> MovieList::search_file_on_disk(std::string path_hard_disk, std::vector<std::string> list)
{
   list.clear();
   static const std::string file_mask("/*.*");
   std::string _path = path_hard_disk + file_mask;
   WIN32_FIND_DATAA FindFileData;
   HANDLE hFind;
   hFind = FindFirstFileA(_path.c_str(), &FindFileData);
   if (hFind != INVALID_HANDLE_VALUE)
   {
      do
      {
         if ((FILE_ATTRIBUTE_DIRECTORY) != (FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY))
         {
            if (("." == FindFileData.cFileName) || (".." == FindFileData.cFileName))
            {
               continue;
            }
            list.push_back(FindFileData.cFileName);
         }
      } while (FindNextFileA(hFind, &FindFileData));
      FindClose(hFind);
   }
   return list;
}

void MovieList::create_file_movie(std::string path_to_onedrive, std::vector<std::string> list)
{
   std::ofstream fout(path_to_onedrive);
   std::cout << "Адрес создания файла с фильмами: " << path_to_onedrive << std::endl;
   if (!fout.is_open()) {
      std::cout << "Файл на запись не может быть открыт!\n";
   }
   else {
      fout.clear();
      for (int i = 0, q = list.size(); i < q; i++) {
         fout << i + 1 << ". " << list[i] << "\n";
      }
      std::cout << "Файл создан! по адресу: "  << path_to_onedrive << std::endl;
   }
   fout.close();
}

void MovieList::read_config()
{  
   setlocale(LC_ALL, "rus");
   std::vector<std::string> config;
   char buff[100];
   config.push_back("");
   config.push_back("");
   std::ifstream fin("config_movie.txt");
   if (!fin.is_open()) // если файл не открыт
      std::cout << "Файл config не может быть открыт!\n"; // сообщить об этом
   else
   {
      for (int i = 0, q = config.size(); i < q; i++) {
         fin.getline(buff, 100);
         std::cout << buff << std::endl;
         config[i] = buff;
      }
   }
   fin.close();
   path_hard_disk = config[0];
   path_to_onedrive = config[1];
}

std::string MovieList::get_path_hard_disk() 
{
   return path_hard_disk;
}

std::string MovieList::get_path_to_onedrive() 
{
   return path_to_onedrive;
}