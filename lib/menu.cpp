/*
因为合作伙伴不知道什么是gcc，所以这个东西是我赶出来的。
非常不优雅，见谅。
*/


const char *MENU_inputGraphFile = "请输入图文件的名称（默认为example.graph）：";

const char *MENU_cannotFindGarphFile = "没有名为*的图文件！请重新输入文件名，或Ctrl+Z以退出：\n";

const char *MENU_loadedGraphFile = "已从*中读入图。\n";

const char *MENU_mainMenu =
    "你需要做什么？\n"
    "Ctrl+Z以退出\n1、寻找最短路径\n2、输出邻接矩阵\n3、输出节点列表\n";

const char *MENU_farewell = "再见！\n";

const char *MENU_sourceForDijkstra = "请输入要寻找最短路径的节点名称：";

const char *MENU_invalidVerticle = "没有名为*的节点！\n";

const char *MENU_resultOfDijkstra = "从*到每个节点的最短路径为：\n";

const char *MENU_adjacencyMatrix = "图的邻接矩阵是：\n";

const char *MENU_verticles = "图的节点有：\n";