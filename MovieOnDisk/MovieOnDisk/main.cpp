#include <iostream>
#include "Movie.h"

void main() {
   MovieList list;
   std::vector<std::string> list_movie;
   list.read_config();
   list_movie = list.search_file_on_disk(list.get_path_hard_disk(), list_movie);
   list.create_file_movie(list.get_path_to_onedrive(), list_movie);
   system("pause");
   exit(1);
}