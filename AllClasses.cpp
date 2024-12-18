#include <iostream>
#include <string>
#include <vector>
#include<deque>
#include <set>
#include <bits/stdc++.h>
//#include <stack>
#include <ctime>
#include <utility>
#include <climits>
#include <fstream>
#include <iomanip>
#include "stack.h"
#include "queue.h"
using namespace std;

class Scholarship {
public:
    // Constructor
    Scholarship(){
        this->name = "Scholarship Not Granted Yet.";
        this->amount = 0.0;
        this->criteria = 0.0;
    }

    Scholarship(string name, double amount, float criteria) {
        this->name = name;
        this->amount = amount;
        this->criteria = criteria;
    }

    // Getters
    string getName() const { return name; }
    double getAmount() const { return amount; }
    float getCriteria() const { return criteria; }

private:
    string name;
    double amount;
    float criteria;
};

class Courses {
public:
    string CourseName;
    string CourseID;
    int Credits;
    int TotalStudents;

    Courses(string n, string id, int credit) {
        CourseName = n;
        CourseID = id;
        Credits = credit;
        TotalStudents = 0;
    }

    void setCourseName(string name) {
        CourseName = name;
    }

    string getCourseName() {
        return CourseName;
    }

    void setCourseID(int id) {
        CourseID = id;
    }

    string getCourseID() {
        return CourseID;
    }

    void setCredits(int credits) {
        Credits = credits;
    }

    int getCredits() {
        return Credits;
    }

    void setTotalStudents(int total) {
        TotalStudents = total;
    }

    int getTotalStudents() {
        return TotalStudents;
    }
};

class Students {
public:
    string Name;
    string ID;
    string Session;
    string Phone;
    string Email;
    float CGPA;
    vector<Courses> RegisteredCourses;
    Scholarship scholarshipStatus;
    map<string, string> studentGrades;

    Students(string a, string b, string c, string d, string e) {
        Name = a;
        ID = b;
        Session = c;
        Phone = d;
        Email = e;
        CGPA = 0.0;
    }

    // Setters and Getters
    void setName(string name) { Name = name; }
    string getName() { return Name; }
    void setCGPA(float cgpa) { CGPA = cgpa; }
    float getCGPA() { return CGPA; }
    void setID(string id) { ID = id; }
    string getID() { return ID; }
    void setEmail(string email) { Email = email; }
    string getSession() { return Session; }
    void setSession(string s) { Session = s; }
    string getEmail() { return Email; }
    void setPhone(string phone) { Phone = phone; }
    string getPhone() { return Phone; }
    void setCourses(vector<Courses> courses) { RegisteredCourses = courses; }
    vector<Courses> getCourses() { return RegisteredCourses; }
    void setScholarship(Scholarship ss) { scholarshipStatus = ss; }
    Scholarship getScholarshipStatus() { return scholarshipStatus; }

    void setGrades(string a, string b){
        studentGrades[a] = b;
    }

    string getGrade(string a){
        return studentGrades[a];
    }
};

class Section {
public:
    string SectionName;
    string SectionId;
    string Session;
    int TotalStudents;
    vector<Students> studentsPresent;

    // Constructors
    Section() {
        SectionName = "";
        Session = "";
        SectionId = "";
        TotalStudents = 0;
    }

    Section(string sectionName, string session, int totalStu, string sId) {
        SectionName = sectionName;
        Session = session;
        SectionId = sId;
        TotalStudents = totalStu;
    }

    // Destructor
    ~Section() {
        studentsPresent.clear();
    }

    // Setters
    void setSectionName(string sectionName) {
        SectionName = sectionName;
    }

    void setSession(string session) {
        Session = session;
    }

    void setTotalStu(int total) {
        TotalStudents = total;
    }

    void setAllStudents(vector<Students> coursesArray) {
        studentsPresent = coursesArray;
        TotalStudents = coursesArray.size();
    }

    // Getters
    string getSectionName() {
        return SectionName;
    }

    string getSession() {
        return Session;
    }

    int getTotalStudents() {
        return TotalStudents;
    }

    vector<Students>& getAllstudents() {
        return studentsPresent;
    }

    string getID(){
        return SectionId;
    }

    void Add(Students S){
        studentsPresent.push_back(S);
    }
};

class Departments {
public:
    string DepartmentName;
    string DepartmentID;
    int TotalSections;
    vector<Section> Allsections;

    Departments(string a, string b, int c) {
        DepartmentName = a;
        DepartmentID = b;
        TotalSections = c;
    }

    void setDepartmentName(string name) {
        DepartmentName = name;
    }

    string getDepartmentName() {
        return DepartmentName;
    }

    void setDepartmentID(string id) {
        DepartmentID = id;
    }

    string getDepartmentID() {
        return DepartmentID;
    }

    int getTotalSections() {
        return TotalSections;
    }

    void setSections(vector<Section> sec) {
        for (int i = 0; i < sec.size(); i++) {
            Allsections.push_back(sec[i]);
        }
    }

    vector<Section>& getSections() {
        return Allsections;
    }
};

class Graph {
private:
    vector<pair<int, int>>* graph;
    int *parent;
    int totalNodes;
    int *dist;
    bool *visited;

public:
    int gettotalNodes(){
        return totalNodes;
    }

    void Initialization(){
        graph[0].push_back({1, 10});
        graph[0].push_back({2, 15});
        graph[0].push_back({3, 20});

        graph[1].push_back({0, 10});
        graph[1].push_back({2, 5});
        graph[1].push_back({4, 25});

        graph[2].push_back({0, 15});
        graph[2].push_back({1, 5});
        graph[2].push_back({3, 10});
        graph[2].push_back({4, 30});

        graph[3].push_back({0, 20});
        graph[3].push_back({2, 10});
        graph[3].push_back({4, 35});

        graph[4].push_back({1, 25});
        graph[4].push_back({2, 30});
        graph[4].push_back({3, 35});
    } 

    Graph() {
        totalNodes = 5;
        parent = new int[totalNodes]; dist = new int[totalNodes]; visited = new bool[totalNodes];
        graph = new vector<pair<int, int>>[totalNodes];
        Initialization();
    }
    
    void AddOneMorePath(int source, int dest, int cost){
        if (dest < totalNodes && source < totalNodes){
            graph[source].push_back({dest, cost});
        }

        FindShortestPath(source);
    }

    void AddOnemoreDepartment(){
        setTotalNodes(totalNodes + 1);
    }

    void setTotalNodes(int val){
        totalNodes = val;

        parent = new int[val];
        dist = new int[val];
        visited = new bool[val];

        Initialization();
    }

    int MinimumElement() {
        int min = INT_MAX, min_index;

        for (int i = 0; i < totalNodes; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                min_index = i;
            }
        }

        return min_index;
    }

    void FindShortestPath(int src) {
        for (int i = 0; i < totalNodes; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
            parent[i] = -1;
        }

        dist[src] = 0;

        for (int count = 0; count < totalNodes-1; count++) {
            int u = MinimumElement();
            visited[u] = true;

            for (auto edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    void DisplayDistances(int src) {
        cout << "Shortest distances from department " << src << ":\n";
        for (int i = 0; i < totalNodes; i++) {
            cout << "Department " << i << " : " << dist[i] << "\n";
        }
    }

    void PrintPath(int dest,  vector<Departments> departs) {
        if (parent[dest] == -1) {
            cout << "You have to start from " << departs[dest].getDepartmentName() << " Department" << endl;
            return;
        }
        PrintPath(parent[dest], departs);
        cout << "Then Move To " << departs[dest].getDepartmentName() << " Departemnt" << endl;
    }

    void DisplayPath(int src, int dest, vector<Departments> departs) {
        if (dist[dest] == INT_MAX) {
            cout << "No path from department " << src << " to department " << dest << ".\n";
            return;
        }

        cout << "Shortest path from Department : " << departs[src].getDepartmentName() << " to Department : " << departs[dest].getDepartmentName() << ": " << endl;
        PrintPath(dest, departs);
        cout << " ------------------------" << endl;
        cout << "|   Total distance: " << dist[dest] << "   |" << endl;
        cout << " ------------------------" << endl;
        cout << endl;
    }
};

class UniTreeNode {
public:
    string Name;
    string Id;
    int index;
    vector<UniTreeNode*> childern;
    unordered_map<string, UniTreeNode*> mapping;
    UniTreeNode* parent;

    UniTreeNode(string a, string b, int ind) : Name(b), Id(a), index(ind) {}

    void AddChild(UniTreeNode* newNode) {
        childern.push_back(newNode);
        mapping[newNode->Name] = newNode;
        newNode->parent = this;
    }
};

class Solution {
private:
    void InsertStudents(UniTreeNode* Sec, vector<Students>& S) {
        for (int i = 0; i < S.size(); i++) {
            string Name = S[i].getName(); 
            string id = S[i].getID();
            UniTreeNode* newNode = new UniTreeNode(id, Name, i);
            Sec->AddChild(newNode);
        }
        for (int i = 0; i < S.size(); i++) {
            InsertCourses(Sec->childern[i], S[i].getCourses());
        }
    }

    void InsertCourses(UniTreeNode* Stu, vector<Courses> C) {
        for (int i = 0; i < C.size(); i++) {
            string Name = C[i].getCourseName(); 
            string id = C[i].getCourseID();
            UniTreeNode* newNode = new UniTreeNode(id, Name, i);
            Stu->AddChild(newNode);
        }
    }

    void InsertSections(UniTreeNode* Depart, vector<Section> S) {
        for (int i = 0; i < S.size(); i++) {
            string Name = S[i].getSectionName(); 
            string id = S[i].getID();
            UniTreeNode* newNode = new UniTreeNode(id, Name, i);
            Depart->AddChild(newNode);
        }

        for (int i = 0; i < S.size(); i++) {
            InsertStudents(Depart->childern[i], S[i].getAllstudents());
        }
    }

public:
    vector<Departments> departs;
    UniTreeNode* root;

    Solution(vector<Departments> d, UniTreeNode* r) : departs(d), root(r) {};
    Solution() : root(nullptr) {};

    void InsertDepartments() {
        for (int i = 0; i < departs.size(); i++) {
            string Name = departs[i].getDepartmentName(); 
            string id = departs[i].getDepartmentID();
            UniTreeNode* newNode = new UniTreeNode(id, Name, i);
            newNode->parent = root;
            root->AddChild(newNode);
        }

        for (int i = 0; i < departs.size(); i++) {
            InsertSections(root->childern[i], departs[i].getSections());
        }
    }

    void Traverse(UniTreeNode* Root){

        if (!Root){return;}

        cout << Root->Name << endl;
        for (int i=0 ; i<Root->childern.size() ; i++){
            Traverse(Root->childern[i]);
        }
    }

    bool SearchWithBFS(string key) {
        if (root == nullptr) {
            cout << "The University Tree is Empty." << endl;
            return false;
        }

        deque<UniTreeNode*> queue;
        queue.push_back(root);

        while (!queue.empty()) {
            UniTreeNode* current = queue.front();
            queue.pop_front();

            if (current->Name == key) {
                cout << "Yes, the \"" << key << "\" is found in the UniversityTree." << endl;
                return true;
            }

            for (auto child : current->childern) {
                queue.push_back(child);
            }
        }

        cout << "No, the \"" << key << "\" is not found in the UniversityTree." << endl;
        return false;
    }
    
    void StudentsInformation(UniTreeNode* Root, string Name, bool &Found){

        if (Root == nullptr){
            return;
        }

        if (Root->Name == Name && !Found){
            cout << endl;
            cout << "-------------------" << endl;
            cout << "Student's Name  : " << Name << endl;
            cout << "Student's ID    : " << Root->Id << endl;
            cout << "Course Enrolled : " << Root->childern.size() << endl;
            cout << "Department Name : " << Root->parent->parent->Name << endl;
            cout << "Section Name    : " << Root->parent->Name << endl;
            cout << "-----------------------" << endl;

            return;
        }

        for (int i=0 ; i<Root->childern.size() ; i++){
            StudentsInformation(Root->childern[i], Name, Found);
        }
    }
    
    void GetSectionsInDeparts(UniTreeNode* Root, string Name){

        if (Root == nullptr){
            return;
        }

        if (Root->Name == Name){
            for (int i=0 ; i<Root->childern.size(); i++){
                cout << "Section : " << i+1 << endl;
                cout << "Section Name      : " << root->childern[i]->Name << endl;
                cout << "Section Id        : " << root->childern[i]->Id << endl;
                cout << "StudentsEnrolled   : " << root->childern[i]->childern.size() << endl;
                cout << endl;
            }

            return;
        }

        for (int i=0 ; i<Root->childern.size() ; i++){
            GetSectionsInDeparts(Root->childern[i], Name);
        }
    }

    void GetCoursesFromStudents(UniTreeNode* Root, string Name){

        if (Root == nullptr){
            return;
        }

        if (Root->Name == Name){
            for (int i=0 ; i<Root->childern.size(); i++){
                cout << endl;
                cout << "--------------------------" << endl;
                cout << "Course No.     : " << i+1 << endl;
                cout << "Course Name    : " << Root->childern[i]->Name << endl;
                cout << "Course Id      : " << Root->childern[i]->Id << endl;
            }
            cout << endl;
            return;
        }

        for (int i=0 ; i<Root->childern.size() ; i++){
            GetCoursesFromStudents(Root->childern[i], Name);
        }
    }

    bool GetStuInSections(UniTreeNode* Root, string Name){

        if (Root == nullptr){
            return false;
        }

        if (Root->Name == Name){
            for (int i=0 ; i<Root->childern.size(); i++){
                cout << endl;
                cout << "------------------------" << endl;
                cout << "Student           : " << i+1 << endl;
                cout << "Student Name      : " << Root->childern[i]->Name << endl;
                cout << "Student Id        : " << Root->childern[i]->Id << endl;
                cout << "CoursesEnrolled   : " << Root->childern.size() << endl;
                cout << "Department        : " << Root->parent->Name << endl;
            }

            return true;
        }

        for (int i=0 ; i<Root->childern.size() ; i++){
            if (GetStuInSections(Root->childern[i], Name)){
                return true;
            }
        }

        return false;
    }
    
};

void InsertDataInToClasses(vector<Departments>& departs) {
    vector<Students> students; 
    vector<Section> sections; 
    vector<Courses> courses;
    int TotalStudents = 0;

    ifstream MyReadFile("Departments.txt");

    cout << "====================================" << endl;
    cout << "Data Insertion System Started!   " << endl;
    cout << "====================================" << endl;
    

    // Inserting Department Data
    for (int i = 0; i < 5; i++) {
        string Name = ""; 
        string Id = "", Number = "";

        getline(MyReadFile, Name);
        getline(MyReadFile, Id);
        getline(MyReadFile, Number);

        
        departs.push_back(Departments(Name, Id, stoi(Number)));
    }
    
    // Inserting Section Data
    for (int i = 0; i < departs.size(); i++) {
        for (int j = 0; j < departs[i].getTotalSections(); j++) {
            string Name = "", session = "", Id = "", Number = "";

            getline(MyReadFile, Name);
            getline(MyReadFile, Id);
            getline(MyReadFile, Number);
            getline(MyReadFile, session);
            TotalStudents += stoi(Number); 

            sections.push_back(Section(Name, session, stoi(Number), Id));
        }
    }
    
    // Inserting Student Data
    for (int i = 1; i <=TotalStudents; i++) {

        string Name="",Id="",Session="",Phone="",Email="",CGPA="",Sname="",Samount="",Scriteria="";

        getline(MyReadFile, Name);
        getline(MyReadFile, Id);
        getline(MyReadFile, Session);
        getline(MyReadFile, Phone);
        getline(MyReadFile, Email);
        getline(MyReadFile, CGPA);
        getline(MyReadFile, Sname);
        getline(MyReadFile, Samount);
        getline(MyReadFile, Scriteria);
        
        Scholarship Scholar(Sname, stod(Samount), stof(Scriteria));
        students.push_back(Students(Name, Id, Session, Phone, Email));

        students[i-1].setScholarship(Scholar);
        students[i-1].setCGPA(stof(CGPA));
    }
    
    for (int j = 0; j <TotalStudents*2 ; j++) {

        string Name; 
        string Id; 
        string Ignore; 
        string Hours;

        getline(MyReadFile, Name);
        getline(MyReadFile, Id);
        getline(MyReadFile, Ignore);
        getline(MyReadFile, Hours);        
        
        courses.push_back(Courses(Name, Id, stoi(Hours)));
    }
    
    for (int i=0 ; i<TotalStudents ; i++){
        vector<Courses> C;

        for (int j=0 ; j<2; j++){
            int Index = 2*i + j;
            C.push_back(courses[Index]);
        }

        students[i].setCourses(C);
    }
    
    for (int i=0 ; i<sections.size() ; i++){
        vector<Students> C;

        for (int j=0 ; j<sections[i].getTotalStudents(); j++){
            int index = i*sections[i].getTotalStudents()+j;

            if (index >= students.size()) {
                throw runtime_error("Index out of bounds: Invalid student index.");
            }
            C.push_back(students[index]);
        }

        sections[i].setAllStudents(C);
    }
    
    for (int i = 0; i < departs.size(); ++i) {
        vector<Section> S;
        for (int j = 0; j < 2; ++j) {
            int sectionIndex = i * 2 + j;
            S.push_back(sections[sectionIndex]); 
        }

        departs[i].setSections(S);
    }

    cout << "\n====================================" << endl;
    cout << "Data Insertion Complete!" << endl;
}

vector<Students>& GetStudents(string& D, string& S, vector<Departments>& Dept) {
    for (int i = 0; i < Dept.size(); i++) {
        if (Dept[i].getDepartmentName() == D) {
            for (int j = 0; j < Dept[i].getTotalSections(); j++) {
                if (Dept[i].getSections()[j].getSectionName() == S) {
                    return Dept[i].getSections()[j].getAllstudents();
                }
            }
        }
    }
}

void AddHistory(int choice, stack<string> &h){
    
    time_t currentTime = time(nullptr);
    string timeStr = ctime(&currentTime);
    if (!timeStr.empty() && timeStr.back() == '\n') {
        timeStr.pop_back();
    }

    string str = "";
    if (choice == 1){
        str = "You Added A Student";
    }
    else if(choice == 2){
        str = "You Removed A Student";
    }
    else if(choice == 3){
        str = "You Searched Data From Tree At " + timeStr;
    }
    else if(choice == 4){
        str = "You Searched for a Students Information At : " + timeStr;
    }
    else if(choice == 5){
        str = "You Searched For Students Present In Specific Section at : " + timeStr;
    }
    else if(choice == 6){
        str = "You Searched for a Courses Enrolled By Specific Student at : " + timeStr;
    }
    else if(choice == 7){
        str = "You Searched for a Sections Present In Specific Department at :  " + timeStr;
    }
    else if(choice == 8){
        str = "You Searched For The History Of Your Controls at : " + timeStr;
    }
    else if(choice == 9){
        str = "You Applied Grading At : " + timeStr;
    }
    else if(choice == 10){
        str = "You Assigned Ascholarships At : " + timeStr;
    }
    else if(choice == 12){
        str = "You Found Shortest Path Between Two Departments At : " + timeStr;
    }
    else if(choice == 13){
        str = "You Structured Pre Requistes At : " + timeStr;
    }
    
    if (str != ""){h.push(str);}
}

template <typename T>
void Swap(std::vector<T>& arr, int f, int s) {
    int temp1=arr[f].first;
    int temp2=arr[f].second;

    arr[f].first=arr[s].first;
    arr[f].second=arr[s].second;

    arr[s].first=temp1;
    arr[s].second=temp2;
}

template <typename T>
int Partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            Swap(arr, i, j);
        }
    }

    Swap(arr, i + 1, high);
    return (i + 1);
}

template <typename T>
void QuickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void AssignGradesToStudents(vector<Departments>& departments, Solution &solution){
    string Cou = "", Dept="", Sec="";int id=0;
    bool Found = false;

    do{
        cout << "Enter Department : "; cin >> Dept;
    }while(!solution.SearchWithBFS(Dept));
    
    do{
        cout << "Enter Section : "; cin >> Sec;
    }while(!solution.SearchWithBFS(Sec));
    
    vector<Students> empty;
    vector<Students>& stu = empty;

    for (int i=0 ; i< departments.size() ; i++){
        if (departments[i].getDepartmentName() == Dept){
            for (int j=0 ; j<departments[i].getTotalSections() ; j++){
                if (departments[i].getSections()[j].getSectionName() == Sec){
                    stu = departments[i].getSections()[j].getAllstudents();
                }
            }
        }
    }

    vector<Courses> C = stu[0].getCourses();

    do{
      cout << "Enter Subject Name : ";cin>>Cou;
      
      for (int i=0 ; i<C.size() ; i++){
        if (Cou == C[i].getCourseName()){
            Found = true;
        }
      }
    }while(!Found);
    
    vector<pair<int, int>> marks;
    
    for (int i=0 ; i<stu.size() ; i++){
        int mark = 0; float CGPA = 0.0; 
        cout << "Enter the marks for " << stu[i].getName() << " : "; cin >> mark;
        cout << "Enter CGPA : "; cin >> CGPA;
        stu[i].setCGPA(CGPA);

        marks.push_back({mark, i});
    }
    
    QuickSort(marks, 0, stu.size()-1);
    
    stack<int> TopStudents;
    
    for (int i=0 ; i<stu.size() ; i++){
        TopStudents.push(marks[i].second);
    }
    
    string grades[] = {"A+", "A", "A-", "B+", "B-", "C+", "C-", "D", "E", "F"};

    cout << "\n+======================================+" << endl;
    cout << "|         Students Annual Grading        |" << endl;
    cout << "+======================================+" << endl;
    
    for (int i=0 ; i<stu.size() ; i++){
        int index = TopStudents.top();
        TopStudents.pop();

        stu[index].setGrades(Cou, grades[i]);
        cout << endl;
        cout << "Name      : " << stu[index].getName() << endl;
        cout << "ID        : " << stu[index].getID() << endl;
        cout << "CGPA      : " << stu[index].getCGPA() << endl;
        cout << "Subject   : " << Cou << endl;
        cout << "Graded As : " << stu[index].getGrade(Cou) << endl;
        cout << "======================================" << endl;
    }

    for (int i=0 ; i< departments.size() ; i++){
        if (departments[i].getDepartmentName() == Dept){
            for (int j=0 ; j<departments[i].getTotalSections() ; j++){
                if (departments[i].getSections()[j].getSectionName() == Sec){
                    departments[i].getSections()[j].setAllStudents(stu);
                }
            }
        }
    }
}

void ScholarshipGranting(Scholarship scholarship, vector<Departments> departs){
    
    //Initializing Variables For Data Storage
    string Dept="", Sec="";int id=0;
    
    //Getting Data From Admin About For scholarship Marking
    cout << "Enter Department : "; cin >> Dept;
    cout << "Enter Section : ";cin >> Sec;

    float Criteria = scholarship.getCriteria();
    
    //Getting Students of that course
    vector<Students> stu = GetStudents(Dept, Sec, departs);

    //Creating Paired vector for storage of marks alongwith index
    vector<pair<float, int>> marks;
    
    //Now, getting marks and pushing into paired vectors alongwith indexes
    for (int i=0 ; i<stu.size() ; i++){
        marks.push_back({stu[i].getCGPA(), i});
    }
    
    //Sorting Paired vector on the bases of marks
    QuickSort(marks, 0, stu.size()-1);
    
    //Creating a stack for storage of indexes of students from top
    stack<int> TopStudents;
    
    //Pushing indexes into stack
    for (int i=0 ; i<stu.size() ; i++){
        TopStudents.push(marks[i].second);
    }
    
    //Granting Schoilarships
    cout << "\n+====================================+" << endl;
    cout << "|         Scholarships Granting       |" << endl;
    cout << "+====================================+" << endl;

    int i=-1;bool Found = true;

    cout << TopStudents.size() << endl;

    while (Found){
        i++;
        int PoppedIndex = TopStudents.top();
        TopStudents.pop();

        if (stu[PoppedIndex].getCGPA() >= Criteria){
            stu[PoppedIndex].setScholarship(scholarship);
            cout << i+1 << ". Student " << stu[PoppedIndex].getName() << " got Scholarship Beacuse CGPA : "<< stu[PoppedIndex].getCGPA() <<" is greater/Equal to Scholarship's Criteria : " << scholarship.getCriteria() << endl;
        }
        else{
            Found=false;
        }
    }

    cout << "Scholarships has been granted to our most brilliant students!!!" << endl;
}

vector<string> findCourseOrder(vector<string>& courses, vector<pair<string, string>>& prerequisites) {
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> inDegree;

    for (const string& course : courses) {
        inDegree[course] = 0;
    }

    for (auto& prereq : prerequisites) {
        string course = prereq.first;
        string prereqCourse = prereq.second;
        graph[prereqCourse].push_back(course);
        inDegree[course]++;
    }

    queue<string> q;
    for (const auto& entry : inDegree) {
        if (entry.second == 0) {
            q.push(entry.first);
        }
    }

    vector<string> courseOrder;
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        courseOrder.push_back(current);

        for (const string& neighbor : graph[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (courseOrder.size() != courses.size()) {
        return {}; // Cycle detected
    }

    return courseOrder;
}

void DisplayBanner() {
    cout << "\n";
    cout << "============================================\n";
    cout << "         UNIVERSITY MANAGEMENT SYSTEM        \n";
    cout << "============================================\n";
    cout << "Welcome! Manage your university data efficiently.\n";
    cout << "\n";
}

void DisplayMenu() {
    cout << "\n================= MENU =================\n";
    cout << left << setw(3) << "" << "1. Add Students" << endl;
    cout << left << setw(3) << "" << "2. Remove Students" << endl;
    cout << left << setw(3) << "" << "3. Search Data from Tree" << endl;
    cout << left << setw(3) << "" << "4. Find Students' Information" << endl;
    cout << left << setw(3) << "" << "5. Find Students Present in Section" << endl;
    cout << left << setw(3) << "" << "6. Find Courses Enrolled by Students" << endl;
    cout << left << setw(3) << "" << "7. Find Sections in Specific Department" << endl;
    cout << left << setw(3) << "" << "8. View Your History Log" << endl;
    cout << left << setw(3) << "" << "9. Apply Grading to Student Marks" << endl;
    cout << left << setw(3) << "" << "10. Automate Scholarship Granting" << endl;
    cout << left << setw(3) << "" << "11. Undo (CTRL + Z)" << endl;
    cout << left << setw(3) << "" << "12. Shortest Path Between Two Departments" << endl;
    cout << left << setw(3) << "" << "13. List Pre-Requisites Pattern" << endl;
    cout << left << setw(3) << "" << "14. Quit" << endl;
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

tuple<int, int> GraphInputs(vector<Departments>& departments){
    int source, destination;
    int limit = departments.size()-1;

    //Showing User The Number Of Depatrments
    cout << "\n+======================================+" << endl;
    cout << "|         Showing All Departments       |" << endl;
    cout << "+======================================+" << endl;
    for (int i=0 ; i<departments.size() ; i++){
        cout << i << ".  " << departments[i].getDepartmentName() << " With Id : " << departments[i].getDepartmentID() << endl;
    }

    cout << endl;
    cout << "-----------------------------" << endl;
    
    do{
        cout << "Enter Source Department (0-" << departments.size()-1 << "): ";
        cin >> source;
    }while(source < 0 || source > limit);

    do{
        cout << "Enter the destination department (0-" << departments.size()-1 << "): ";
        cin >> destination;
    }while(destination < 0 || destination > limit);
    
    cout << "-----------------------------" << endl;

    return make_tuple(source, destination);
}

void EnteringDataToFiles(vector<Departments>& departs){

    ofstream outFile("Departments.txt");
    
    //Adding Departments Information
    for (int i=0 ; i<departs.size() ; i++){
        outFile << departs[i].getDepartmentName() << endl;
        outFile << departs[i].getDepartmentID() << endl;
        outFile << departs[i].getTotalSections() << endl;
    }
    
    //Adding Sections Information
    vector<Section> SEC;
    for (int i=0 ; i<departs.size() ; i++){
        for (int j=0 ; j<departs[i].getSections().size() ; j++){
            outFile << departs[i].getSections()[j].getSectionName() << endl;
            outFile << departs[i].getSections()[j].getID() << endl;
            outFile << departs[i].getSections()[j].getTotalStudents() << endl;
            outFile << departs[i].getSections()[j].getSession() << endl;

            SEC.push_back(departs[i].getSections()[j]);
        }
    }
    
    //Adding Students Information
    vector<Students> STU;
    for (int i=0 ; i<SEC.size() ; i++){
        for (int j=0 ; j<SEC[i].getTotalStudents() ; j++){
            outFile << SEC[i].getAllstudents()[j].getName() << endl;
            outFile << SEC[i].getAllstudents()[j].getID() << endl;
            outFile << SEC[i].getAllstudents()[j].getSession() << endl;
            outFile << SEC[i].getAllstudents()[j].getPhone() << endl;
            outFile << SEC[i].getAllstudents()[j].getEmail() << endl;
            outFile << SEC[i].getAllstudents()[j].getCGPA() << endl;
            outFile << SEC[i].getAllstudents()[j].getScholarshipStatus().getName() << endl;
            outFile << SEC[i].getAllstudents()[j].getScholarshipStatus().getAmount() << endl;
            outFile << SEC[i].getAllstudents()[j].getScholarshipStatus().getCriteria() << endl;

            STU.push_back(SEC[i].getAllstudents()[j]);
        }
    }
    
    //Adding Coursse Information
    for (int i=0 ; i<STU.size() ; i++){
        for (int j=0 ; j<STU[i].getCourses().size() ; j++){
            outFile << STU[i].getCourses()[j].getCourseName() << endl;
            outFile << STU[i].getCourses()[j].getCourseID() << endl;
            outFile << STU[i].getCourses()[j].getTotalStudents() << endl;
            outFile << STU[i].getCourses()[j].getCredits() << endl;
        }
    }

    outFile.close();

}

int main() {

    //Initially Designed Demo Scholarship Instance
    Scholarship scholarship("FACS", 50000, 3.70); Graph g;

    //Initializations of arrays to store our data from .txt file.
    vector<Departments> departments;
    stack<string> history;
    InsertDataInToClasses(departments);
    stack<tuple<Students, int, int>> RemovedStudents;
    stack<pair<int, int>> NewAddedStudents;
    
    //Creating Root With University Name
    UniTreeNode* root = new UniTreeNode("UET-02", "KSK New Campus", 0);
    Solution solution(departments, root);
    solution.InsertDepartments();

    cout << "Student Name : " << solution.root->mapping["SoftwareEngineering"]->mapping["Section1"]->mapping["John-Smith"]->Name << endl;

    DisplayBanner();

    int choice = 0;
    while (choice != 14) {
        DisplayMenu();
        cin >> choice;
        
        AddHistory(choice, history);
        
        if (choice == 1){
            string S="", D=""; string state ="Enter Student ID: ";
            string A, B, C, E, F;bool Found = false;
            
            cout << endl;
            cout << "================================" << endl;
            do{cout << "Enter Department : "; cin>>D; }while(!solution.SearchWithBFS(D));
            do{cout << "Enter Section : "; cin>>S; }while(!solution.SearchWithBFS(S));            
            vector<Students>& St = GetStudents(D, S, departments);
            cout << "================================" << endl;
            cout << endl;

            cout << "-------------------------" << endl;
            cout << "Enter Name   : ";cin>>A;
            do{
                cout << state;cin>>B;

                for (int i=0 ; i<St.size() ; i++){
                    if (St[i].getID() == B){
                        Found = true;
                        state="ID Must Be Valid : ";
                    }
                }
            }while(Found);

            cout << "Enter Session : ";cin>>C;
            cout << "Enter Phone   : ";cin>>E;
            cout << "Enter Email   : ";cin>>F;
            cout << endl;

            St.push_back(Students(A, B, C, E, F));
            St[St.size()-1].setCourses(St[0].getCourses());


            cout << "SuccessFully Added Student In " << S << " of " << " Department : " << D << endl;
            cout << "-------------------------" << endl;
            cout << endl;


            int DIndex=0;
            for (int i=0 ; i<departments.size() ; i++){
                if (departments[i].getDepartmentName() == D){
                    DIndex = i;
                }
            }

            int SIndex=0;
            for (int i=0 ; i<departments[DIndex].getTotalSections() ; i++){
                if (departments[DIndex].getSections()[i].getSectionName() == S){
                    SIndex = i;
                }
            }
            
            UniTreeNode *N = new UniTreeNode(B, A, St.size());
            N->parent = solution.root->childern[DIndex]->childern[SIndex];
            solution.root->childern[DIndex]->childern[SIndex]->AddChild(N);

            //Now, adding Student's Courses In Tree
            vector<Courses> COU = St[0].getCourses();
            cout << "Size : " << COU.size() << endl;

            for (int i=0 ; i<COU.size() ; i++){
                UniTreeNode *NW = new UniTreeNode(COU[i].getCourseName(),COU[i].getCourseID(),i);
                solution.root->childern[DIndex]->childern[SIndex]->childern[St.size()-1]->AddChild(N);
            }

            NewAddedStudents.push({DIndex, SIndex});
        }
        else if(choice == 2){

            //Collecting Information For Getting Students
            string S="", D="";
            cout << endl;
            cout << "================================" << endl;
            do{cout << "Enter Department : "; cin>>D; }while(!solution.SearchWithBFS(D));
            do{cout << "Enter Section : "; cin>>S; }while(!solution.SearchWithBFS(S));
            vector<Students>& St = GetStudents(D, S, departments);
            cout << "================================" << endl;
            cout << endl;
            
            //Getting Index Of Department
            int DIndex=0;
            for (int i=0 ; i<departments.size() ; i++){
                if (departments[0].getDepartmentName() == D){
                    DIndex = i;
                }
            }
            
            //Getting Index Of Section
            int SIndex=0;
            for (int i=0 ; i<departments[DIndex].getTotalSections() ; i++){
                if (departments[DIndex].getSections()[i].getSectionName() == S){
                    SIndex = i;
                }
            }
            
            //Collecting Students Of That Department's Section
            string A; int stIndex=0; bool Found = false;
            
            do{
                cout << "Enter Student's ID : ";cin>>A;

                for (int i=0 ; i<St.size() ; i++){
                    if (St[i].getID() == A){
                        Found = true;
                        RemovedStudents.push(make_tuple(St[i], DIndex, SIndex));
                        St.erase(St.begin()+i);
                        stIndex = i;
                    }
                }

            }while(!Found);

            cout << "SuccessFully Removed Student From " << D << " at "<< S << endl;
            auto& AllStudents = solution.root->childern[DIndex]->childern[SIndex]->childern;
            AllStudents.erase(AllStudents.begin() + stIndex);
        }
        else if(choice == 3){
            string data;
            cout << "Enter Data To Search : "; cin>>data;

            solution.SearchWithBFS(data);
        }
        else if(choice == 4){
            string Name = "";bool Found = false;
            cout << "Enter Student's Name : "; cin >> Name;

            if (solution.SearchWithBFS(Name)){
                solution.StudentsInformation(root, Name, Found);
            }
        }
        else if(choice == 5){
            string Name = "";bool Found = false;
            cout << "Enter Section Name : "; cin >> Name;

            if (solution.SearchWithBFS(Name)){
                solution.GetStuInSections(root, Name);
            }
        }
        else if(choice == 6){
            string Name = "";bool Found = false;
            cout << "Enter Student Name : "; cin >> Name;

            if (solution.SearchWithBFS(Name)){
                solution.GetCoursesFromStudents(root, Name);
            }
        }
        else if(choice == 7){
            string Name = "";bool Found = false;
            cout << "Enter Departments's Name : "; cin >> Name;

            if (solution.SearchWithBFS(Name)){
                solution.GetSectionsInDeparts(root, Name);
            }
        }
        else if(choice == 8){
            if (history.empty()) {
                cout << "\n+======================================+" << endl;
                cout << "|         No History Available        |" << endl;
                cout << "+======================================+" << endl;
            }
            else{
                cout << "\n+======================================+" << endl;
                cout << "|            History Log               |" << endl;
                cout << "+--------------------------------------+" << endl;

                vector<string> val;
                int j = 0;
                while (!history.empty()){
                    val.push_back(history.top());
                    history.pop();

                    cout << "| " << setw(2) << j+1 << ". " 
                        << setfill(' ') << setw(35) << left << val[j] 
                        << " |" << endl;
                    j += 1;
                }
                
                cout << "+======================================+" << endl;
                
                // Restore history
                for (int i = val.size() - 1; i >= 0; i--) {
                    history.push(val[i]);
                }
            }
        }
        else if(choice == 9){
            AssignGradesToStudents(departments, solution);
        }
        else if(choice == 10){
            ScholarshipGranting(scholarship, departments);
        }
        else if(choice == 11){

            string a = history.top(); history.pop();

            if (a == "You Added A Student") {
                auto studentData = NewAddedStudents.top();
                auto& allStudents = departments[get<0>(studentData)].getSections()[get<1>(studentData)].getAllstudents();
                
                if (!allStudents.empty()) {
                    allStudents.erase(allStudents.begin() + allStudents.size() - 1);
                }
                NewAddedStudents.pop();

                auto& allCHilds = root->childern[get<0>(studentData)]->childern[get<1>(studentData)]->childern;
                allCHilds.erase(allCHilds.begin() + allCHilds.size() - 1);

                cout << "===================================================" << endl;
                cout << "|              ACTION: REMOVE STUDENT             |" << endl;
                cout << "===================================================" << endl;
                cout << "| STATUS: The last added student has been removed.|" << endl;
                cout << "| FROM DEPARTMENT: " << departments[get<0>(studentData)].getDepartmentName() << endl;
                cout << "| SECTION: " << departments[get<0>(studentData)].getSections()[get<1>(studentData)].getSectionName() << endl;
                cout << "===================================================" << endl;
                cout << endl;
            }
            else if (a == "You Removed A Student") {
                auto studentData = RemovedStudents.top();
                departments[get<1>(studentData)].getSections()[get<2>(studentData)].Add(get<0>(studentData));
                RemovedStudents.pop();

                UniTreeNode* NewStudent = new UniTreeNode(get<0>(studentData).getName(), get<0>(studentData).getID(), 0);
                root->childern[get<1>(studentData)]->childern[get<2>(studentData)]->AddChild(NewStudent);

                cout << "***************************************************" << endl;
                cout << "*              ACTION: ADD BACK STUDENT           *" << endl;
                cout << "***************************************************" << endl;
                cout << "* STATUS: A student was re-added to the section.  *" << endl;
                cout << "* STUDENT NAME: " << get<0>(studentData).getName() << endl;
                cout << "* STUDENT ID: " << get<0>(studentData).getID() << endl;
                cout << "* DEPARTMENT: " << get<1>(studentData) << endl;
                cout << "* SECTION: " << get<2>(studentData) << endl;
                cout << "***************************************************" << endl;
                cout << endl;
            }
        }
        else if(choice == 12){
            
            int choose = 0;

            do{
                cout << "1. Add New Path Between Departments." << endl;
                cout << "2. Add New Building" << endl;
                cout << "3. Find Shortest Path Between Departments." << endl;
                cout << "4. Find Least Distances Of One Departments With Others." << endl;
                cin >> choose;
            }while(choose<0 || choose>4);

            
            if (choose == 1){
                int S=0, D=0, W=0;
                do{cout << "Enter Source : "; cin>>S;}while(S<0 || S>g.gettotalNodes()-1);
                do{cout << "Enter Destination : "; cin>>D;}while(D<0 ||D>g.gettotalNodes()-1);
                cout << "Enter Cost : "; cin>>W;
                g.AddOneMorePath(S, D, W);
            }
            else if(choice == 2){
                g.AddOnemoreDepartment();
            }
            else if(choose == 4){
                auto getData = GraphInputs(departments);
                int source = get<0>(getData);int destination = get<1>(getData);

                g.FindShortestPath(source);
                cout << "\n+======================================+" << endl;
                cout << "|       Shortest Distances From " << source << "   |" << endl;
                cout << "+======================================+" << endl;
                g.DisplayDistances(source);
            }
            else if(choose == 3){
                auto getData = GraphInputs(departments);
                int source = get<0>(getData);int destination = get<1>(getData);

                g.FindShortestPath(source);
                cout << "\n+======================================+" << endl;
                cout << "|       Shortest Path Found As         |" << endl;
                cout << "+======================================+" << endl;
                g.DisplayPath(source, destination, departments);
            }
            else if(choice == 4){

            }
        }
        else if(choice == 13){
            vector<string> Ccourses = {"Object-Oriented-Programming", "Programming-Fundamentals", "Data-Structures-and-Algorithms", "Database-Systems", "Artificial-Intelligence", "Linear-Algebra", "Machine-Learning", ""};
            vector<pair<string, string>> Computer = {
            {"Object-Oriented-Programming", "Programming-Fundamentals"},
            {"Data-Structures-and-Algorithms", "Object-Oriented-Programming"},
            {"Database-Systems", "Data-Structures-and-Algorithms"},
            {"Artificial-Intelligence", "Linear-Algebra"},
            {"Machine-Learning", "Linear-Algebra"}};
            
            vector<string> Ecourses = {"Digital-Systems-Design", "Circuit-Analysis", "Control-Systems-Engineering", "Electromagnetic-Fields", "Signal-Processing", "Linear-Algebra", "Power-Systems-Analysis"};
            vector<pair<string, string>> Electrical = {
            {"Digital-Systems-Design", "Circuit-Analysis"},
            {"Control-Systems-Engineering", "Electromagnetic-Fields"},
            {"Signal-Processing", "Linear-Algebra"},
            {"Power-Systems-Analysis", "Digital-Systems-Design"}};
            
            vector<string> Mcourses = {
                "Mechanics-of-Materials", 
                "Machine-Design", 
                "Heat-Transfer", 
                "Fluid-Mechanics", 
                "Dynamics"
            };

            vector<pair<string, string>> Mechanical = {
                {"Mechanics-of-Materials", "Engineering-Mechanics"},
                {"Machine-Design", "Mechanics-of-Materials"},
                {"Heat-Transfer", "Thermodynamics"},
                {"Fluid-Mechanics", "Thermodynamics"},
                {"Dynamics", "Mechanics-of-Materials"}
            };

            vector<string> CHcourses = {
                "Chemical-Reaction-Engineering",
                "Mass-Transfer-Operations",
                "Process-Control"
            };

            vector<pair<string, string>> Chemical = {
                {"Chemical-Reaction-Engineering", "Thermodynamics"},
                {"Mass-Transfer-Operations", "Fluid-Mechanics"},
                {"Process-Control", "Heat-Transfer"}
            };

            vector<string> Bcourses = {
                "Biomechanics",
                "Cellular-Tissue-Engineering",
                "Bioinstrumentation",
                "Medical-Imaging",
                "Biosignal-Processing"
            };

            vector<pair<string, string>> BioMedical = {
                {"Biomechanics", "Biology-for-Engineers"},
                {"Cellular-Tissue-Engineering", "Biomechanics"},
                {"Bioinstrumentation", "Signal-Processing"},
                {"Medical-Imaging", "Bioinstrumentation"},
                {"Biosignal-Processing", "Medical-Imaging"}
            };
            int choice1 = 0, choice = 0;
            
            do{
                cout << "1. Add New Course : PreRequistes" << endl;
                cout << "2. Find Courses Pattern" << endl;
                cin>>choice1;
            }while(choice1<0 || choice1>2);

            if (choice1 == 1){
               
                int choice2 = 0; string C="", P="";
                cout << "1. Add New Pattern For Computer" << endl;
                cout << "2. Add New Pattern For Electrical" << endl;
                cout << "3. Add New Pattern For Chemical" << endl;
                cout << "4. Add New Pattern For Mechanical" << endl;
                cout << "5. Add New Pattern For Bio-Medical" << endl;

                do{
                    cout << "Enter Choice : "; cin>>choice2;
                }while(choice2<0 || choice2>5);
                
                cout << "Enter Course  : "; cin>>C;
                cout << "Enter Pre-Requistes : "; cin>>P;
         
                if(choice2 == 1){
                    auto it = find(Ccourses.begin(), Ccourses.end(), C);
                    auto it2 = find(Ccourses.begin(), Ccourses.end(), P);

                    if (it != Ccourses.end() && it2 != Ccourses.end()){Computer.push_back({C, P});}
                }
                else if(choice == 2){
                    auto it = find(Ecourses.begin(), Ecourses.end(), C);
                    auto it2 = find(Ecourses.begin(), Ecourses.end(), P);

                    if (it != Ecourses.end() && it2 != Ecourses.end()){Electrical.push_back({C, P});}
                }
                else if(choice == 3){
                    auto it = find(CHcourses.begin(), CHcourses.end(), C);
                    auto it2 = find(CHcourses.begin(), CHcourses.end(), P);

                    if (it != CHcourses.end() && it2 != CHcourses.end()){Chemical.push_back({C, P});}
                }
                else if(choice == 4){
                    auto it = find(Mcourses.begin(), Mcourses.end(), C);
                    auto it2 = find(Mcourses.begin(), Mcourses.end(), P);

                    if (it != Mcourses.end() && it2 != Mcourses.end()){Mechanical.push_back({C, P});}
                }
                else if(choice == 5){
                    auto it = find(Bcourses.begin(), Bcourses.end(), C);
                    auto it2 = find(Bcourses.begin(), Bcourses.end(), P);

                    if (it != Bcourses.end() && it2 != Bcourses.end()){BioMedical.push_back({C, P});}
                }
            }

            if (choice1 == 2){
                cout << "\n+======================================+" << endl;
                cout << "|         Enter PreRequistes For?        |" << endl;
                cout << "+======================================+" << endl;
                cout << "1. Pre-requistes of ComputerScience" << endl;
                cout << "2. Pre-requistes of ElectricalEngineering" << endl;
                cout << "3. Pre-requistes of ChemicalEngineering" << endl;
                cout << "4. Pre-requistes of MechanicalEngineering" << endl;
                cout << "5. Pre-requistes of Bio-Medical" << endl;
                cout << endl;

                do
                {
                cout << "Enter Your Choice : "; cin>>choice;
                }while(choice<0 || choice>5);
                
                cout << endl;
                cout << "\n+======================================+" << endl;
                cout << "|         Pre-Requistes Sequence Is      |" << endl;
                cout << "+======================================+" << endl;
                if (choice == 1){
                    vector<string> C = findCourseOrder(Ccourses, Computer);

                    for (int i=0 ; i<C.size() ; i++){
                        cout << C[i] << endl;
                    }
                }
                else if(choice == 2){
                    vector<string> C = findCourseOrder(Ecourses, Electrical);
                    
                    for (int i=1 ; i<C.size() ; i++){
                        cout << i << ". " << C[i] << endl;
                    }
                }
                else if(choice == 3){
                    vector<string> C = findCourseOrder(CHcourses, Chemical);
                    for (int i=1 ; i<C.size() ; i++){
                        cout << i << ". " << C[i] << endl;
                    }
                }
                else if(choice == 4){
                    vector<string> C = findCourseOrder(Mcourses, Mechanical);
                    for (int i=1 ; i<C.size() ; i++){
                        cout << i << ". " << C[i] << endl;
                    }
                }
                else if(choice == 5){
                    vector<string> C = findCourseOrder(Bcourses, BioMedical);
                    for (int i=1 ; i<C.size() ; i++){
                        cout << i << ". " << C[i] << endl;
                    }
                }
            }

            cout << "-----------------------------" << endl;
            cout << endl;
        }
    }

    EnteringDataToFiles(departments);

    return 0;
}