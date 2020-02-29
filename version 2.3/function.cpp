#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include <math.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include "abstractDataType.h"
#include "function.h"

using namespace std;

// check all possible error before start
// 前端开始前，第一个需要调用的函数
// 目前还没完善，暂且不调用
void check_error_before_start(){
        // check existence of database.txt for every topic...
        
        // check existence of every keyword content file and answer content file...
        
        // ...

}

// construct topic tree from topic.txt file
// if failure, return NULL
// 前端开始前，第二个需要调用，返回数据库指针
// 前端需要一个类型为 T_BST 的指针储存返回值
T_BST *cons_topic_from_file(){
        T_BST *head = NULL;
        string str = "";
        
        ifstream in("./topic/topic.txt");
        
        if (in.is_open())
        {
                while (!in.eof())
                {
                        getline(in,str);
                        // ignore empty line
                        if (str != "")
                        {
                                cons_topic_BST_no_database(&head, str);
                        }
                }
        }
        else
        {
                cout<< "Error: Topic File Not Exist"<< endl;
        }
        in.close();
        
        return head;
}

// input question, matching with database
// output corresponding answer to specifed file
// 前端匹配问题时，需要调用的函数
// 第一个参数是 问题字符串， 字符串可以包含符号和大小写，但每个字符要用空格隔开
// 第二个参数是类型为 T_BST 的指针
// 第三个参数是 要写入答案字符串的文件指针
// 该函数只负责写入字符串到文件，不负责打开和关闭文件
// 文件用 fstream 打开
void match1(string que, T_BST *head, fstream &outfile){

        // remove punctuation
        que.erase(remove_if (que.begin(), que.end(), static_cast<int(*)(int)>(&ispunct)),que.end());
        // transform to lower case
        transform(que.begin(),que.end(),que.begin(),::tolower);
        
        // split question string
        vector<string> que_arr;
        string result;
        
        stringstream input(que);
        while(input>>result){
                que_arr.push_back(result);
        }
        
        // 以下匹配部分 可以进行深度优化，提高效率，目前版本没有优化
        int index_topic = -1;
        T_BST *temp = NULL;
        Topic *current_topic = NULL;

        for(int i=0; i<que_arr.size(); i++)
        {
                temp = head;
                while(temp != NULL)
                {
                        int val = que_arr[i].compare(temp->name);
                        if(val == 0)
                        {
                                // find the topic
                                index_topic = i;
                                if(temp->topic == NULL)
                                {
                                        // set up content
                                        temp->topic = set_up_topic(temp->name);
                                        if (temp->topic == NULL)
                                        {
                                                // set-up failure
                                                cout<<"Warning: Topic: "<< temp->name;
                                                cout<<" Set-up Failure"<< endl;
                                                // release memory
                                                free_all(head);
                                                exit(3);
                                        }
                                }
                                current_topic = temp->topic;
                                break;
                        }
                        else if(val > 0)
                        {
                                temp = temp->right;
                        }
                        else
                        {
                                temp = temp->left;
                        }
                }
                if(index_topic != -1)
                {
                        break;
                }
        }
        
        // no topic matched
        if (index_topic == -1)
        {
                //没有匹配到主题词
                outfile<< "Sorry, I don't understand."<< endl;
                outfile<< "Please ask questions on C programming."<< endl;
                return;
        }
        
        int match_val = 0;
        for(int i=0; i<que_arr.size(); i++){
                if (i == index_topic)
                {
                        continue;
                }
                else
                {
                        match_val += match_keyword(que_arr[i], current_topic);
                }
        }
        
        if (match_val == 0)
        {
                // 没有匹配到关键字
                outfile<< "Sorry, I am confused"<< endl;
                outfile<< "Can you clarify your question about "<< que_arr[index_topic];
                outfile<< "?" << endl;
                return;
        }
        else
        {
                
                string answer = match_solution(match_val, current_topic);
                // write answer to targeted file...
                outfile<< answer << endl;
        }
}

// input question, matching with database
// output corresponding answer to specifed file
// 前端匹配问题时，需要调用的函数
// 第一个参数是 问题字符串， 字符串可以包含符号和大小写，但每个字符要用空格隔开
// 第二个参数是类型为 T_BST 的指针
string match2(string que, T_BST *head){
        
        // remove punctuation
        que.erase(remove_if (que.begin(), que.end(), static_cast<int(*)(int)>(&ispunct)),que.end());
        // transform to lower case
        transform(que.begin(),que.end(),que.begin(),::tolower);
        
        // split question string
        vector<string> que_arr;
        string result;
        
        stringstream input(que);
        while(input>>result){
                que_arr.push_back(result);
        }
        
        // 以下匹配部分 可以进行深度优化，提高效率，目前版本没有优化
        int index_topic = -1;
        T_BST *temp = NULL;
        Topic *current_topic = NULL;
        
        for(int i=0; i<que_arr.size(); i++)
        {
                temp = head;
                while(temp != NULL)
                {
                        int val = que_arr[i].compare(temp->name);
                        if(val == 0)
                        {
                                // find the topic
                                index_topic = i;
                                if(temp->topic == NULL)
                                {
                                        // set up content
                                        temp->topic = set_up_topic(temp->name);
                                        if (temp->topic == NULL)
                                        {
                                                // set-up failure
                                                cout<<"Warning: Topic: "<< temp->name;
                                                cout<<" Set-up Failure"<< endl;
                                                // release memory
                                                free_all(head);
                                                exit(3);
                                        }
                                }
                                current_topic = temp->topic;
                                break;
                        }
                        else if(val > 0)
                        {
                                temp = temp->right;
                        }
                        else
                        {
                                temp = temp->left;
                        }
                }
                if(index_topic != -1)
                {
                        break;
                }
        }
        
        // no topic matched
        if (index_topic == -1)
        {
                //没有匹配到主题词
                return "Please ask questions on C programming.";
        }
        
        int match_val = 0;
        for(int i=0; i<que_arr.size(); i++){
                if (i == index_topic)
                {
                        continue;
                }
                else
                {
                        match_val += match_keyword(que_arr[i], current_topic);
                }
        }
        
        if (match_val == 0)
        {
                // 没有匹配到关键字
                string answer = "Can you clarify your question about " + que_arr[index_topic] + " ?";
                return answer;
        }
        else
        {
                
                string answer = match_solution(match_val, current_topic);
                if (answer == "")
                {
                        // no solution can be matched
                        answer = "Can you clarify your question about " + que_arr[index_topic] + " ?";
                }
                return answer;
        }
}

// given word and Topic object
// return match value if succeed, otherwise, return 0
int match_keyword(string word, Topic *topic){
        BST *temp1 = topic->level1_head;
        BST *temp2 = topic->level2_head;
        int match_val = 0;
        
        while (temp1 != NULL)
        {
                int val = (temp1->keyword).compare(word);
                if (val == 0)
                {
                        match_val += temp1->match_val;
                        break;
                }
                else if (val < 0)
                {
                        temp1 = temp1->right;
                }
                else
                {
                        temp1 = temp1->left;
                }
        }
        
        while (temp2 != NULL)
        {
                int val = (temp2->keyword).compare(word);
                if (val == 0)
                {
                        match_val += temp2->match_val;
                        break;
                }
                else if (val < 0)
                {
                        temp2 = temp2->right;
                }
                else
                {
                        temp2 = temp2->left;
                }
        }
        
        return match_val;
}

// given match value and Topic object
// return answer string if succeed, otherwise, return empty
string match_solution(int match_val, Topic *topic){
        BST *temp = topic->answer_head;
        string answer = "";
        
        while (temp != NULL)
        {
                if (temp->match_val == match_val)
                {
                        answer = temp->keyword;
                        break;
                }
                else if (temp->match_val > match_val)
                {
                        temp = temp->left;
                }
                else
                {
                        temp = temp->right;
                }
        }
        return answer;
}

// construct topic name binary search tree
// only has topic name, no database content
void cons_topic_BST_no_database(T_BST **head, string topic_name){
        // empty tree
        if (*head == NULL)
        {
                T_BST *t_bst = new T_BST();
                t_bst->name = topic_name;
                *head = t_bst;
        }
        // non-empty tree
        else
        {
                T_BST *temp = *head;
                do {
                        // insert to left
                        if ((temp->name).compare(topic_name) > 0)
                        {
                                if (temp->left == NULL)
                                {
                                        T_BST *t_bst = new T_BST();
                                        t_bst->name = topic_name;
                                        temp->left = t_bst;
                                        break;
                                }
                                else
                                {
                                        temp = temp->left;
                                }
                        }
                        // insert to right
                        else
                        {
                                if (temp->right == NULL)
                                {
                                        T_BST *t_bst = new T_BST();
                                        t_bst->name = topic_name;
                                        temp->right = t_bst;
                                        break;
                                }
                                else
                                {
                                        temp = temp->right;
                                }
                        }
                } while (temp != NULL);
        }
}


// set up all relevant keyword and answer tree for each topic
// return pointer of topic class if succeed, otherwise return NULL
Topic * set_up_topic(string topic_name){
        Topic *topic = new Topic();
        
        // specify file path
        string path = "./"+topic_name;
        string level1_filepath = path + "/first_level.txt";
        string level2_filepath = path + "/second_level.txt";
        string database_filepath = path + "/database.txt";
        
        // construct keyword and answer tree
        topic->level1_head = cons_keyword_from_file(level1_filepath, topic->level1_base_weight);
        if (topic->level1_head == NULL)
        {
                return NULL;
        }
        
        topic->level2_head = cons_keyword_from_file(level2_filepath, topic->level2_base_weight);
        if (topic->level2_head == NULL)
        {
                free_tree(topic->level1_head);
                return NULL;
        }
        
        topic->answer_head = cons_solution_from_file(database_filepath);
        if (topic->answer_head == NULL)
        {
                free_tree(topic->level1_head);
                free_tree(topic->level2_head);
                return NULL;
        }
        
        /*
        printTree(topic->level1_head);
        printTree(topic->level2_head);
        printTree(topic->answer_head);
        */
        
        return topic;
}

// NOTE: call this function every time finishing maintaining or updating ANY file content
// translate raw solution data to ready-matched database file
void trans_solution_to_file(string topic_name) {
        string filein = "./"+topic_name+"/solution.txt";
        string fileout = "./"+topic_name+"/database.txt";
        string level1_filepath = "./"+topic_name+"/first_level.txt";
        string level2_filepath = "./"+topic_name+"/second_level.txt";
        
        BST *first_level_head = cons_keyword_from_file(level1_filepath, 50);
        BST *second_level_head = cons_keyword_from_file(level2_filepath, 1);
        
        string str = "";
        string solution = "";
        
        int full_match = 0;
        int first_keyword_matched = 0;
        int first_level_val = 0;
        int second_level_val = 0;
        
        ifstream in(filein);
        ofstream out(fileout);
        
        if (!out.is_open()) {
                cout<< "Error: Cannot Create database.txt File"<< endl;
                 // release memory
                free_tree(first_level_head);
                free_tree(second_level_head);
                exit(2);
        }
        
        if (in.is_open())
        {
                while(!in.eof())
                {
                        getline(in, str);
                        // read first_level keyword for the first time
                        if (str == "#" && !first_keyword_matched)
                        {
                                first_keyword_matched = 1;
                                // obtain first_level keyword
                                getline(in, str);
                                if (str != "")
                                {
                                        if((first_level_val = get_match_val(str, first_level_head)) == -1)
                                        {
                                                cout<< "Error: Matching Failure In First_level Tree"<< endl;
                                                // release memory...
                                                free_tree(first_level_head);
                                                free_tree(second_level_head);
                                                exit(1);
                                        }
                                }
                                else
                                {
                                        first_level_val = 0;
                                }
                        }
                        // read first_level keyword for the non-first time
                        else if (str == "#" && first_keyword_matched)
                        {
                                // first_keyword_matched = 0;
                                full_match = 0;
                                // translate finished matching solution to data file
                                out<< "#"<< endl;
                                out<< first_level_val+second_level_val<< endl;
                                out<< solution<< endl;
                                solution = "";
                                // obtain first_level keyword
                                getline(in,str);
                                if (str != "")
                                {
                                        if((first_level_val = get_match_val(str, first_level_head)) == -1)
                                        {
                                                cout<< "Error: Matching Failure In First_level Tree"<< endl;
                                                // release memory...
                                                free_tree(first_level_head);
                                                free_tree(second_level_head);
                                                exit(1);
                                        }
                                }
                                else
                                {
                                        first_level_val = 0;
                                }
                        }
                        // read first second_level keyword in each first_level group
                        else if (str == "##" && !full_match)
                        {
                                full_match = 1;
                                //obtain second_level keyword
                                getline(in,str);
                                if (str != "")
                                {
                                        // get match value of second_level keyword
                                        if((second_level_val = get_match_val(str, second_level_head)) == -1)
                                        {
                                                cout<< "Error: Matching Failure In Second_level Tree"<< endl;
                                                // release memory...
                                                free_tree(first_level_head);
                                                free_tree(second_level_head);
                                                exit(1);
                                        }
                                }
                                else
                                {
                                        second_level_val = 0;
                                }
                        }
                        // read following second_level keyword in each first_level group
                        else if (str == "##" && full_match)
                        {
                                // translate finished matching solution into data file
                                out<< "#"<< endl;
                                out<< first_level_val+second_level_val<< endl;
                                out<< solution<< endl;
                                solution = "";
                                // obtain second_level keyword
                                getline(in,str);
                                if (str != "")
                                {
                                        // get match value of second_level keyword
                                        if((second_level_val = get_match_val(str, second_level_head)) == -1)
                                        {
                                                cout<< "Error: Matching Failure In Second_level Tree"<< endl;
                                                // release memory...
                                                free_tree(first_level_head);
                                                free_tree(second_level_head);
                                                exit(1);
                                                exit(1);
                                        }
                                }
                                else
                                {
                                        second_level_val = 0;
                                }
                        }
                        else
                        {
                                // read solution
                                solution += str;
                        }
                }
                // translate last matching solution into data file
                out<< "#"<< endl;
                out<< first_level_val+second_level_val<< endl;
                out<< solution<< endl;
        }
        else
        {
                cout << "Error: Cannot Open Solution.txt File" << endl;
                // release memory
                free_tree(first_level_head);
                free_tree(second_level_head);
                exit(2);
        }
        in.close();
        out.close();
        
        // release memory
        free_tree(first_level_head);
        free_tree(second_level_head);
}

// search keyword tree and return match value
int get_match_val(string str, BST *head){
        if (head == NULL)
        {
                cout <<"Error: Tree Dose Not Exist" << endl;
                return -1;
        }
        else
        {
                BST *temp = head;
                do {
                        // check left
                        if ((temp->keyword).compare(str) > 0)
                        {
                                temp = temp->left;
                        }
                        // check right
                        else if ((temp->keyword).compare(str) < 0)
                        {
                                temp = temp->right;
                        }
                        else if ((temp->keyword).compare(str) == 0){
                                return temp->match_val;
                        }
                } while (temp != NULL);
        }
        cout << "Error: No Such keyword" << endl;
        return -1;
}

// construct solution tree from data file
// NOTE: must ensure database.txt file exists, otherwise call trans_solution_to_file()
// return head pointer of solution if succeed, otherwise return NULL
BST *cons_solution_from_file(string filename){
        string solution = "";
        string str = "";
        size_t pos;
        int match_val = 0;
        BST *head = NULL;
        int start_match = 0;
        
        ifstream in(filename);
        
        if(in.is_open())
        {
                while(!in.eof())
                {
                        getline(in,str);
                        // first-time matching
                        if (str == "#" && !start_match)
                        {
                                start_match = 1;
                                getline(in, str);
                                match_val = stoi(str,&pos);
                                if(match_val <= 0)
                                {
                                        // match value is smaller than 0
                                        // database file content error
                                        cout<< "Error: Database File Content Error"<< endl;
                                        // release memory using head pointer
                                        free_tree(head);
                                        head = NULL;
                                        return head;
                                }
                        }
                        // non fisrt-time matching
                        else if (str == "#" && start_match)
                        {
                                cons_solution_BST(solution, &head, match_val);
                                
                                solution = "";
                                getline(in, str);
                                match_val = stoi(str,&pos);
                                if(match_val <= 0)
                                {
                                        // match value is smaller than 0
                                        // data file content error
                                        cout<< "Error: Data File Content Error"<< endl;
                                        // release memory using head pointer
                                        free_tree(head);
                                        head = NULL;
                                        return head;
                                }
                        }
                        else
                        {
                                // read answer
                                solution += str;
                        }
                }
                // last-time matching
                cons_solution_BST(solution, &head, match_val);
        }
        else
        {
                cout<< "Error: Database File Does Not Exist, Contact Admin To Fix"<< endl;
                return head;
        }
        return head;
}

// construct binary search tree for solution
// according to match value
void cons_solution_BST(string solution, BST **head, int match_val) {
        // empty tree
        if (*head == NULL)
        {
                BST *bst = new BST();
                bst->keyword = solution;
                bst->match_val = match_val;
                *head = bst;
        }
        // non-empty tree
        else
        {
                BST * temp = *head;
                do
                {
                        // insert element to left side
                        if (temp->match_val > match_val)
                        {
                                // left node not exists
                                if (temp->left == NULL)
                                {
                                        BST *bst = new BST();
                                        bst->keyword = solution;
                                        bst->match_val = match_val;
                                        temp->left = bst;
                                        break;
                                }
                                // left node exists
                                else
                                {
                                        temp = temp->left;
                                }
                                
                        }
                        // insert element to right side
                        else
                        {
                                // right node not exists
                                if (temp->right == NULL)
                                {
                                        BST *bst = new BST();
                                        bst->keyword = solution;
                                        bst->match_val = match_val;
                                        temp->right = bst;
                                        break;
                                }
                                // right node exists
                                else
                                {
                                        temp = temp->right;
                                }
                        }
                } while (temp != NULL);
        }
}


// construct keyword tree
// first level base_weight = 50
// second level base_weight = 1
BST* cons_keyword_from_file(string filename, int base_weight){
        
        string keyword_str ="";
        BST *head = NULL;
        int num_keyword = 0;
        
        ifstream in(filename);
        
        // open info file...
        if (in.is_open())
        {
                while (!in.eof())
                {
                        num_keyword++;
                        // read keyword line from file
                        getline(in,keyword_str);
                        
                        // split synonym keyword string
                        vector<string> res;
                        string result;
                        stringstream input(keyword_str);
                        // remove space and split
                        while(input>>result)
                        {
                                res.push_back(result);
                        }
                        // construct tree using each keyword
                        for(int i=0;i<res.size();i++)
                        {
                                // synonym has same match value
                                cons_keyword_BST(res[i].c_str(), &head, num_keyword*base_weight);
                        }
                }
        }
        else
        {
                cout<<"Error: cannot open " << filename <<endl;
        }
        in.close();
        return head;
}

// construct binary search tree for keywords according to alphabet
void cons_keyword_BST(string keyword, BST ** head, int match_val) {
        
        if (*head == NULL)
        {
                BST *bst = new BST();
                bst->keyword = keyword;
                bst->match_val = match_val;
                bst->left = NULL;
                bst->right = NULL;
                *head = bst;
        }
        else
        {
                BST *temp = *head;
                do {
                        // check left
                        if ((temp->keyword).compare(keyword) > 0)
                        {
                                if (temp->left == NULL){
                                        BST *bst = new BST();
                                        bst->keyword = keyword;
                                        bst->match_val = match_val;
                                        bst->left = NULL;
                                        bst->right = NULL;
                                        temp->left = bst;
                                        break;
                                }
                                else
                                {
                                        temp = temp->left;
                                }
                        }
                        // check right
                        else
                        {
                                if (temp->right == NULL){
                                        BST *bst = new BST();
                                        bst->keyword = keyword;
                                        bst->match_val = match_val;
                                        bst->left = NULL;
                                        bst->right = NULL;
                                        temp->right = bst;
                                        break;
                                }
                                else
                                {
                                        temp = temp->right;
                                }
                        }
                } while (temp != NULL);
        }
}

// print out content of element
// including match value and string
void printTree(BST *head) {
        BST *temp = head;
        if (temp == NULL)
        {
                return;
        }
        else
        {
                cout << temp->keyword;
                cout << " " << temp->match_val << endl;
                printTree(temp->left);
                printTree(temp->right);
        }
}

// release memory for tree
// based on the idea of recursion
void free_tree(BST *head)
{
        if (head == NULL)
        {
                return;
        }
        else
        {
                free_tree(head->left);
                free_tree(head->right);
                delete head;
        }
}

// 程序关闭前，前端需要调用的函数来释放内存
// release memory for all data
void free_all(T_BST *head){
        if (head == NULL)
        {
                return;
        }
        else
        {
                free_all(head->left);
                free_all(head->right);
                if (head->topic == NULL)
                {
                        // not set up content
                        delete head;
                }
                else
                {
                        // set up content
                        free_tree(head->topic->level1_head);
                        free_tree(head->topic->level2_head);
                        free_tree(head->topic->answer_head);
                        delete head;
                }
        }
}
                        

