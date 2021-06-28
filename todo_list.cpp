#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>
#include <typeinfo>

std::string username;
std::string filename;

std::string mainMenu(){
    //system("clear");
    std::cout << "Want do you want to do?" << std::endl;
    std::cout << "Press 1 to add a new item" << std::endl;
    std::cout << "Press 2 to watch your current items" << std::endl;
    std::cout << "Press 3 to remove an item" << std::endl;
    std::cout << "Write 'EXIT' if you are done" << std::endl;
    std::string choice;
    std::cin >> choice;
    return choice;
}




void navigate(){
   
}

std::vector<std::string> writetodovec;
void renderAddItem(){
    // (1) receive the item from the user
    // (2) check if a file exists
    // (3a) if file exists, write it to the file
    // (3b) if file dosen't exists, create file and write to the new file
    // DONE

    // Read from user
    //system("clear");
    std::cout << "Add items to your list, when done write DONE" << std::endl;
    std::string to_add;
    while(to_add != "DONE"){
        std::cout << "Add to your list, when you're done write 'DONE': ";
        std::cin >> to_add; 
        if(to_add == "DONE"){
            std::cout << "Writing your todo's to your file" << std::endl;
        }
        else {
            std::cout << to_add << ", was added to your list" << std::endl;
            writetodovec.push_back(to_add);
        }          
    }
    // Write "todos to the file"
    std::ofstream TodoFile(filename);
    for(int i = 0; i < writetodovec.size(); i++){
        std::cout << writetodovec[i] << std::endl;
        TodoFile << writetodovec[i] << "\n";
    }
    TodoFile.close();
    

}

std::vector<std::string> readtodovec;
void renderViewItems(){
    // (1) Check if file exists
    // (2a) If it dosen't, inform user
    // (2b) If it does, read "todo's" form file and display to user
    // DONE
    //system("clear"); 
    std::ifstream TodoFile(filename);
    std::string read_todo;
    std::cout << "Here are your current 'todos': " << std::endl;
    int count = 1;
    while(getline (TodoFile, read_todo)){
        std::cout << "\t" << "\t" << "\t" << "\t" << count << ". " <<  read_todo << std::endl;
        count += 1;
    }
    TodoFile.close();

}
std::vector<std::string> remove_todo_vec;
void removeTodo(){
    // first read the currently available Todo's
    std::ifstream TodoFile(filename);
    std::string read_todo;
    while(getline (TodoFile, read_todo)){
        remove_todo_vec.push_back(read_todo);
    }
    std::string response_from_user;
    while(response_from_user != "DONE"){
        std::cout << "Write the number of the todo you want to delete, for example 1" << std::endl;
        std::cout << "Write DONE to go back to main menu" << std::endl;
        for(int i = 0; i < remove_todo_vec.size(); i++){
            std::cout << (i+1)  << remove_todo_vec[i] << std::endl;
        }
        std::cin >> response_from_user;
        if(response_from_user != "DONE"){
            remove_todo_vec.erase(remove_todo_vec.begin()+stoi(response_from_user)-1);
        }
    }

    TodoFile.close();
}

class TimeEntry {
    private:
        auto create_time(){
            auto time = std::chrono::system_clock::now();
            std::time_t current_time = std::chrono::system_clock::to_time_t(time);
            return std::ctime(&current_time);
        }

        std::string created_at;
        std::string todo_text;

    public:
    // Default constructor (Might be removed later)
        TimeEntry(){
            created_at = create_time();
            todo_text = "";
        }
        TimeEntry(std::string text_from_user){
             created_at = create_time();
             todo_text = text_from_user; 
        }

        auto get_time(){
             return created_at;
        }

        std::string get_todo(){
            return todo_text;
        }
};


int main(){
    std::cout << "Start" << std::endl;
    TimeEntry myobj("Example text");
    std::cout << myobj.get_todo() << std::endl;
    std::cout << myobj.get_time() << std::endl;
    /*
    bool exit = false;
    std::cout << "Please enter your username" << std::endl;
    std::cin >> username;
    filename = username + ".txt";
    std::cout << filename << std::endl;
    while(!exit){
        std::string choice;
        choice = mainMenu();
        std::cout << "Choice was: " << choice << std::endl;
        std::cout << (choice == "2") << std::endl;
        if(choice == "1"){
            renderAddItem();
        }
        else if(choice == "2"){
            renderViewItems();
        }
        else if(choice == "3"){
            removeTodo();
        }
        else if(choice == "EXIT"){
            exit = true;
        }
    }
    */
    return 0;
}
