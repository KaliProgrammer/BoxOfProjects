// UsefullFileManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <direct.h>
#include <io.h>
#include <string>
#include<string.h>


class item
{
private:

    int id;
    char name[_MAX_PATH]{};
    int qty;
public:
    item() : id(0), qty(0) {}
    void get_item();
    void put_item();
    int get_id()
    {
        return id;
    }
    void update_qty(int num)
    {
        qty = qty - num;
    }

};

void item::get_item()
{
    std::cout << "Enter Item ID: "; std::cin >> id;
    fflush(stdin);
    std::cout << "Enter Item Name: "; std::cin >> name;
    std::cout << "Enter Qty: "; std::cin >> qty;
}
void item::put_item()
{
    std::cout << std::setw(6) << id
        << std::setw(15) << name
        << std::setw(15) << qty << std::endl;
}

void add_record(item myItem);
void show_record(item myItem);
void show_all(item myItem);
void delete_record(item myItem);
void modify_record(item myItem);
void get_file_size(item myItem);

void create_directory(const char*);
void rename_directory();
void copy_directory(const char*, const char*);
void remove_directory();
void show_directory(std::string = "");


std::fstream file;

int main()
{
    item myItem;
    char name[_MAX_PATH];
    char source[_MAX_PATH];
    char destination[_MAX_PATH];
    int option = 0;
    while (true)
    {
        system("cls");
        std::cout << R"(
		---------------------------------------
		---------------------------------------
				MENU
		---------------------------------------
		---------------------------------------
)";
        std::cout << "\t\tX[1] - Add New Record\n";
        std::cout << "\t\tX[2] - Display All Records\n";
        std::cout << "\t\tX[3] - Display Particular Record\n";
        std::cout << "\t\tX[4] - Delete Record\n";
        std::cout << "\t\tX[5] - Update / Modify Record\n";
        std::cout << "\t\tX[6] - Get File Size\n";
        std::cout << "\t\tX[7] - Create Directory\n";
        std::cout << "\t\tX[8] - Rename Directory\n";
        std::cout << "\t\tX[9] - Copy Directory\n";
        std::cout << "\t\tX[10] - Remove Directory\n";
        std::cout << "\t\tX[11] - Show Directory\n";
        std::cout << "\t\tX[12] - Exit\n";
        std::cout << "\t\tEnter option: "; std::cin >> option;
        switch (option)
        {
        case 1:
            std::cin.ignore();
            add_record(myItem);
            std::cout << "Press any key for Main Menu...";
            system("pause");
            break;

        case 2:
            std::cin.ignore();
            std::cout << "---------------------------------------\n";
            std::cout << std::setw(6) << "ID" << std::setw(15) << "Name" << std::setw(15) << "Qty" << std::endl;
            std::cout << "---------------------------------------\n";
            show_all(myItem);
            std::cout << "---------------------------------------\n";
            std::cout << "Press any key for Main Menu...";
            system("pause");
            break;

        case 3:
            std::cin.ignore();
            show_record(myItem);
            std::cout << "Press any key for Main Menu...";
            system("pause");
            break;

        case 4:
            delete_record(myItem);
            std::cout << "Press any key for Main Menu...";
            system("pause");
            break;

        case 5:
            modify_record(myItem);
            std::cout << "Press any key for Main Menu...";
            system("pause");
            break;

        case 6:
            get_file_size(myItem);
            std::cout << "Press any key for Main Menu...";
            system("pause");
            break;

        case 7:
            std::cin.ignore();
            std::cout << "Enter the name and the path of directory: ";
            gets_s(name);
            create_directory(name);
            std::cout << "Press any key for Main Menu...";
            system("pause");
            break;
        case 8:
            std::cin.ignore();
            rename_directory();
            std::cout << "Press any key for Main Menu...";
            system("pause");
            break;
        case 9:
            std::cin.ignore();
            copy_directory(source, destination);
            std::cout << "Press any key for Main Menu...";
            system("pause");
            break;
        case 10:
            std::cin.ignore();
            remove_directory();
            std::cout << "Press any key for Main Menu...";
            system("pause");
            break;
        case 11:
            std::cin.ignore();
            show_directory();
            std::cout << "Press any key for Main Menu...";
            system("pause");
            break;
        case 12:
            exit(0);
        default:
            std::cout << "Incorrect Option, Press any key for Main Menu...";
            system("pause");
            break;
        }
    }
    return 0;
}

void get_file_size(item myItem)
{
    std::streampos begin, end;
    std::ifstream file("stock.txt", std::ios::binary);
    begin = file.tellg();
    file.seekg(0, std::ios::end);
    end = file.tellg();
    file.close();
    std::cout << "The File Size Is: " << (end - begin) << " Bytes\n";
    system("pause");
}
void add_record(item myItem)
{
    char ch = 'y';
    file.open("stock.txt", std::ios::app | std::ios::binary);
    while (ch == 'y' || ch == 'Y')
    {
        myItem.get_item();
        file.write((char*)&myItem, sizeof(myItem));
        std::cout << "Add More Records...(y/n)?";
        std::cin >> ch;
    }
    file.close();
}


void show_all(item myItem)
{

    file.open("stock.txt", std::ios::in | std::ios::binary);
    if (!file)
    {
        std::cout << "File not found!";
        exit(0);
    }
    else
    {
        file.read((char*)&myItem, sizeof(myItem));
        while (!file.eof())
        {
            myItem.put_item();
            file.read((char*)&myItem, sizeof(myItem));
        }
    }
    file.close();
}


void show_record(item myItem)
{
    int num;
    bool flag = false;
    file.open("stock.txt", std::ios::in | std::ios::binary);
    if (!file)
    {
        std::cout << "File Not Found!";
        exit(0);
    }
    else
    {
        std::cout << "Enter Item Code To Search: ";
        std::cin >> num;
        file.read((char*)&myItem, sizeof(myItem));
        while (!file.eof())
        {
            if (num == myItem.get_id())
            {
                flag = true;
                std::cout << "---------------------------------------\n";
                std::cout << std::setw(6) << "ID" << std::setw(15) << "Name" << std::setw(15) << "Qty" << std::endl;
                std::cout << "---------------------------------------\n";
                myItem.put_item();
                std::cout << "---------------------------------------\n";
                break;
            }
            file.read((char*)&myItem, sizeof(myItem));
        }
        if (flag == false)
        {
            std::cout << "Item Not Found...\n";
        }
    }
    file.close();
}
void delete_record(item myItem)
{
    int num;
    std::cout << "Enter Item ID To Delete: "; std::cin >> num;
    std::ofstream file2;
    file2.open("new.txt", std::ios::out | std::ios::binary);
    file.open("stock.txt", std::ios::in | std::ios::binary);
    if (!file)
    {
        std::cout << "File Not Found!";
        exit(0);
    }
    else
    {
        file.read((char*)&myItem, sizeof(myItem));
        while (!file.eof())
        {
            if (num != myItem.get_id())
            {
                file2.write((char*)&myItem, sizeof(myItem));
            }
            file.read((char*)&myItem, sizeof(myItem));
        }

    }
    file2.close();
    file.close();
    remove("stock.txt");
    if (rename("new.txt", "stock.txt") != 0)
    {
        std::cout << "Error Deleting File!\n";
    }
    else
    {
        std::cout << "File Deleted Successfully!\n";
    }
}

void modify_record(item myItem)
{
    int no, num;
    std::cout << "Enter Item Code To Modify: "; std::cin >> no;
    std::cout << "Enter Number Of Items Issued: "; std::cin >> num;
    file.open("stock.txt", std::ios::in | std::ios::out | std::ios::binary);
    if (!file)
    {
        std::cout << "File Not Found...";
        exit(0);
    }
    while (file.read((char*)&myItem, sizeof(myItem)))
    {
        if (myItem.get_id() == no)
        {
            myItem.update_qty(num);
            int pos = sizeof(myItem);
            file.seekp(-pos, std::ios::cur);
            file.write((char*)&myItem, sizeof(myItem));
        }
    }
    file.close();
}

void create_directory(const char* Name)
{
    if (_mkdir(Name) == -1)
    {
        std::cout << "Directory creating error! Check the name and path!" << std::endl;
        return;
    }
    else std::cout << "Directory successfully created!" << std::endl;
}

void rename_directory()
{
    char old_name[_MAX_PATH];
    char new_name[_MAX_PATH];
    std::cout << "Please enter the old name of directory with the path: \n";
    gets_s(old_name);
    std::cout << "Please enter the new name of directory with the path: \n";
    gets_s(new_name);
    if (rename(old_name, new_name))
    {
        std::cout << "Directory rename error! Check old and new path and directory name!" << std::endl;
        return;
    }
    else std::cout << "Directory successfully renamed!" << std::endl;
}

void copy_directory(const char* source, const char* destination)
{
    static int count_dir = 0;
    static int count_files = 0;
    char Path[15]{};
    strcpy_s(Path, source);
    strcat_s(Path, "\\*.*");
    _finddata_t Find;
    long Done = _findfirst(Path, &Find);
    int MayWeWork = Done;
    if (MayWeWork == -1)
    {
        std::cout << "Directory does not exist!" << std::endl;
        return;
    }
    create_directory(destination);
    while (MayWeWork != -1)
    {
        if (strcmp(Find.name, ".") && strcmp(Find.name, ".."))
        {
            if (Find.attrib & _A_SUBDIR)
            {

                char SubDirSrc[_MAX_PATH]{};
                strcpy_s(SubDirSrc, source);
                strcat_s(SubDirSrc, "\\");
                strcat_s(SubDirSrc, Find.name);
                char SubDirDest[_MAX_PATH]{};
                strcpy_s(SubDirDest, destination);
                strcat_s(SubDirDest, "\\");
                strcat_s(SubDirDest, Find.name);
                count_dir++;
                copy_directory(SubDirSrc, SubDirDest);
            }
            else
            {

                char FileSrc[_MAX_PATH]{};
                strcpy_s(FileSrc, source);
                strcat_s(FileSrc, "\\");
                strcat_s(FileSrc, Find.name);
                char FileDest[_MAX_PATH]{};
                strcpy_s(FileDest, destination);
                strcat_s(FileDest, "\\");
                strcat_s(FileDest, Find.name);
                count_files++;
                // Copy_File(FileSrc, FileDest);
            }
        }
        MayWeWork = _findnext(Done, &Find);
    }
    _findclose(Done);
    std::cout << "Copied: " << count_dir << " directories and " << count_files << " files!" << std::endl;


}
void remove_directory()
{
    char name[_MAX_PATH];
    std::cout << "Enter the name of directory with the path: ";
    gets_s(name);
    if (_rmdir(name) == -1)
    {
        std::cout << "Directory delete error! Check the name and is the directory empty!" << std::endl;
        return;
    }
    else std::cout << "Directory successfully deleted!" << std::endl;
}

void show_directory(std::string Name)
{
    if (Name == "")
    {
        std::cout << "Enter the path to directory: ";
        getline(std::cin, Name);
    }

    std::string Path = Name;
    Path += "\\*.*";
    system("cls");
    _finddata_t Find;
    int Done = _findfirst(Path.c_str(), &Find);
    int MayWeWork = Done;
    if (MayWeWork == -1)
    {
        std::cout << "Directory does not exist!" << std::endl;
        return;
    }
    std::cout << "Directory contents: " << Name << std::endl;
    int CountDir = 0, CountFile = 0;
    while (MayWeWork != -1)
    {
        if (strcmp(Find.name, ".") && strcmp(Find.name, ".."))
        {
            if (Find.attrib & _A_SUBDIR)
            {
                std::cout << "Directory: \t|\t";
                CountDir++;
            }
            else
            {
                std::cout << "File: \t\t|" << Find.size << "\t";
                CountFile++;
            }
            if (Find.size <= 999999)std::cout << "\t";
            std::cout << "|" << Find.name << std::endl;
        }
        MayWeWork = _findnext(Done, &Find);
    }
    std::cout << "The numbers of files: " << CountFile << " The numbers of directories: " << CountDir << std::endl;
    _findclose(Done);
}