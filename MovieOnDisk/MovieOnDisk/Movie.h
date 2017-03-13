#include <vector>
#include <string>

class MovieList {
public:
   MovieList();
   ~MovieList();
   std::vector<std::string> search_file_on_disk(std::string path, std::vector<std::string> list);
   void create_file_movie(std::string path, std::vector<std::string> list);
   void read_config();
   std::string get_path_hard_disk();
   std::string get_path_to_onedrive();
private:
   std::vector<std::string> list;
   std::string path_to_onedrive;
   std::string path_hard_disk;
};