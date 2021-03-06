#pragma once
#include <iostream>
#include <string>
using namespace std;

// Creates various data types used to Implement AVL trees for our Dataset
// Course_Data stores all the data of one Course
// Course is a node which contains data and next pointer
// AVL trees are used to store Courses
// Stack is used to balance avl trees
class Course_data
{
public:
    bool isUdemy;
    std::string name;
    std::string url;
    int Category_id;   // using h
    int difficulty_id; // Beginner, advanced etc
    int price;
    int subscribers;
    int course_id;
    int publish_year;
    float duration;
    bool isPaid;
    int counter;
    float rating;
    string difficulty;
    string tags[2];
    Course_data()
    {
        isUdemy = false;
        counter = 0;
        rating = 0;
        subscribers = 0;
        price = 0;
    }
};

class Course
{
public:
    int index;
    Course *Heap_Root;
    Course_data data;
    Course *next;
    Course *LeftChild;
    Course *RightChild;
    void PrintCourseData() //function to print the data of the course
    {
        std::cout << "Course_ID: " << data.course_id << std::endl;
        std::cout << "Course title: " << data.name << std::endl;
        std::cout << "Link: " << data.url << std::endl;
        std::cout << "Difficulty level : " << data.difficulty << std::endl;
        cout << "Rating : " << data.rating << endl;
        if (data.isUdemy)
        {
            std::cout << "Category ID: " << data.Category_id << std::endl;
            std::cout << "Category: " << data.tags[0] << std::endl;
            std::cout << "Price: " << data.price << std::endl;
            std::cout << "Number of students enrolled: " << data.subscribers << std::endl;
            std::cout << "Year published: " << data.publish_year << std::endl;
            std::cout << "Hours to complete: " << data.duration << std::endl;
        }
        else
        {
            cout << "Category: " << data.tags[0] << endl;
            cout << "Sub-category: " << data.tags[1] << endl ;
        }
        cout << endl;
    }
    void InsertUserCourseData() //function to insert the data into the course
    {
        cout << "Enter course name: " ;
        std::cin >> data.name;
        cout << "Attach course link: ";
        std::cin >> data.url;
        cout << "Give category id: ";
        std::cin >> data.Category_id;
        cout << "Give course price: ";
        std::cin >> data.price;
        cout << "Give number of subscribers: ";
        std::cin >> data.subscribers;
        cout << "Year of release = ";
        std::cin >> data.publish_year;
        cout << "Hours to complete = ";
        std::cin >> data.duration;
        if (data.price != 0)
            data.isPaid == false;

        
    }
};

class LinkedList
{
public:
    Course *first;
    Course *last;
    int length;
    Course *ploc;
    Course *loc;
    LinkedList();
    bool isEmpty();
    void printList(int, int);
    void SearchList(string); //searches through list linearly
    void insertFront();
    void insertFront(Course *);
    void insertNewNode(Course *);
    void insert(Course *);
    void deleteNode(std::string);
    void destroy(); //basic linked list functionalities
};

class stackNode // node to implement Stack datastructure
{
public:
    Course *ptr;
    stackNode *next;
    stackNode()
    {
        ptr = NULL;
        next = NULL;
    }
};

class stack
{
public:
    int len = 0;
    stackNode *start;
    stackNode *loc;
    stack()
    {
        start = NULL;
        loc = NULL;
    }

    bool isEmpty();
    Course *pop();
    void push(Course *);
};

class AVL_Tree
{
public:
    stack s; // Used to ballance AVL
    Course *root;
    Course *loc;
    Course *ploc;
    int len;
    AVL_Tree()
    {
        len = 0;
        root = NULL;
        loc = NULL;
        ploc = NULL;
    }
    ~AVL_Tree();
    bool IsEmpty();
    void search(Course *);
    void Insert(Course *);
    void PreOrder(Course *);
    void InOrder(Course *);
    void PostOrder(Course *);
    int height_of_tree(Course *);
    void destroyTree(Course *);
    void deleteNode(Course *);

    // functions to balance AVL tree

    void leftRotation(Course *);
    void rightRotation(Course *); // Rotation functions
    void leftRightRotaion(Course *);
    void rightLeftRotaion(Course *);

    int depth_of_tree(Course *); // Returns depth of a node. used for balancing an AVL tree
    void ballanceAVL(Course *, int);

    // File reading functions
    int indexSubject(string);
    int stringToint(string);
    float stringToFloat(string);
    int indexLevel(string);
    void insertUdemyDataset();
    void insertCourseraDataset();

    // Searching functions for strings
    void searchCourse(string);
};