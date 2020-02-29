
/** abstractDataType.h **/
using namespace std;
struct binary_search_tree {
        binary_search_tree *left = NULL;
        binary_search_tree *right = NULL;
        int match_val;
        string keyword;
};
typedef binary_search_tree BST;

class Topic {
public:
        BST *level1_head = NULL;
        BST *level2_head = NULL;
        BST *answer_head = NULL;
        int level1_base_weight = 50;
        int level2_base_weight = 1;
};

struct topic_tree {
        string name = "";
        Topic *topic = NULL;
        topic_tree *left = NULL;
        topic_tree *right = NULL;
};
typedef topic_tree T_BST;
/** end of abstractDataType.h **/
