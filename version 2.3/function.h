
/**  function.h **/

BST *cons_keyword_from_file(string filename, int base_weight);
void cons_keyword_BST(string keyword, BST ** head, int match_val);
int get_match_val(string str, BST *head);
void trans_solution_to_file(string topic_name);
BST *cons_solution_from_file(string filename);
void cons_solution_BST(string solution, BST **head, int match_val);
void printTree(BST *head);
void check_error_before_start();
Topic *set_up_topic(string topic_name);
void free_tree(BST *head);
void cons_topic_BST_no_database(T_BST **head, string topic_name);
T_BST *cons_topic_from_file();
void match1(string que, T_BST *head, fstream &file);
string match2(string que, T_BST *head);
int match_keyword(string word, Topic *topic);
string match_solution(int match_val, Topic *topic);
void free_all(T_BST *head);

/** end of function.h **/
