#pragma once
#include <iostream>
#include "datatype.hpp"
#include <fstream>
#include <sstream>

LinkedList::LinkedList()
{
    first = NULL;
    last = NULL;
    loc = NULL;
    ploc = NULL;
    length = 0;
}
bool LinkedList::isEmpty()
{
    return first == NULL;
}
void LinkedList::printList()
{
    int x = 0;
    Course *temp = first;
    if (!isEmpty())
    {
        while (temp->next != NULL)
        {
            temp->PrintCourseData();
            temp = temp->next;
        }
    }
}
void LinkedList::SearchList(std::string value)
{
    loc = first;
    ploc = NULL;
    while (loc != NULL && loc->data.name > value)
    {
        ploc = loc;
        loc = loc->next;
    }
    if (loc != NULL && loc->data.name != value)
    {
        loc = NULL;
    }
}
void LinkedList::insertFront()
{
    Course *newCourse = new Course;
    newCourse->InsertUserCourseData();
    if (isEmpty())
    {
        first = newCourse;
        last = newCourse;
        newCourse->next = NULL;
    }
    else
    {
        newCourse->next = first;
        first = newCourse;
    }
    length++;
}

void LinkedList::insert(Course *obj)
{
    obj->data.course_id = ++obj->data.courseCount; 
    if (isEmpty())
    {
        first = obj;
        last = obj;
    }
    else
    {
        last->next = obj;
        last = obj;
    }
    length++;
}

void LinkedList::insertNewNode(std::string value)
{
    Course *newCourse = new Course;
    newCourse->InsertUserCourseData();
    SearchList(value);
    if (loc == NULL)
    {
        if (ploc == NULL)
            insertFront();
        else
        {
            newCourse->next = ploc->next;
            ploc->next = newCourse;
            if (ploc == last)
            {
                last = newCourse;
            }
        }
        length++;
    }
    else
    {
        std::cout << "Duplication of courses is not allowed" << std::endl;
    }
}
void LinkedList::insertFile(std::string s)
{
    std::ifstream myFile;
    myFile.open(s);
    int len = 10;
    int count = 0;
    std::string str = "";
    std::string line, str1, str2;
    while (myFile.good())
    {
        Course *newNode = new Course();
        getline(myFile, line, ',');
        newNode->data.name = line;

        getline(myFile, line, ',');
        newNode->data.url = line;

        getline(myFile, line, ',');
        if (line.compare("TRUE"))
            newNode->data.isPaid = true;
        else
            newNode->data.isPaid = false;

        getline(myFile, line, ',');
        newNode->data.price = stringToint(line);

        getline(myFile, line, ',');
        newNode->data.subscribers = stringToint(line);

        getline(myFile, line, ',');
        newNode->data.difficulty_id = indexLevel(line);

        getline(myFile, line, ',');
        newNode->data.duration = stringToint(line);

        getline(myFile, line, ',');
        str1 = line.substr(0, 4);
        newNode->data.publish_year = stringToint(str1);

        getline(myFile, line, '\n');
        newNode->data.Category_id = indexSubject(line);
        this->insert(newNode);
    }
}
void LinkedList::deleteNode(std::string value)
{
    if (!isEmpty())
    {
        SearchList(value);
        if (loc != NULL)
        {
            if (first == last)
            {
                first = NULL;
                last = NULL;
            }
            else if (ploc == NULL)
            {
                first = first->next;
                delete loc;
                loc = first;
            }
            else if (loc->next)
            {
                delete last;
                last = ploc;
                last->next = NULL;
            }
            else
            {
                ploc->next = loc->next;
                delete loc;
            }
            length--;
        }
        else
        {
            std::cout << "Value Not Found" << std::endl;
        }
    }
    else
        std::cout << "No courses are in the structure" << std::endl;
}
void LinkedList::destroy()
{
    Course *temp;
    while (first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    last = NULL;
}

int LinkedList::indexSubject(std::string str)
{
    if (str.compare("Business Finance"))
        return 1;
    else if (str.compare("Graphic Design"))
        return 2;
    else if (str.compare("Musical Instruments"))
        return 3;
    else if (str.compare("Web Development"))
        return 4;
    else
        return 5;
}

int LinkedList::stringToint(std::string str)
{
    int x;
    std::stringstream val(str);
    val >> x;
    return x;
}

int LinkedList::indexLevel(std::string str)
{
    if (str.compare("Beginner Level"))
        return 1;
    else if (str.compare("Intermediate Level"))
        return 2;
    else if (str.compare("Expert Level"))
        return 3;
    else
        return 4;
}
