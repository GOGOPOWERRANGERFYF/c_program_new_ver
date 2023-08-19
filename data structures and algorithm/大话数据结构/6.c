/*
第6章 树

附加：结点和节点是有区别的，算法中的点和时间点。
    但是《数据结构与算法分析-C语言描述》里用的是节点。我擦。。。
    英文版里单词用的是node。
    结点和节点两种翻译都有。。。

6.2 树的定义
    树（tree）是n（n >= 0）个结点的有限集合。
    空树:
        n = 0 时称为空树;
    非空树:
        (1) n > 0,有且仅有一个特定的称为根（root）的结点；
        (2) n > 1,其余结点(除根结点外)可分为m（m > 0）个互不相交的有限集合，
        且每个集合本身又是一棵树，称为根的子树（SubTree）。
        附加：忘记了集合的概念，就画两个圈表示两个集合，里面有各自的元素，包含相同元素，
        则两个圈相交(部分重叠)，相交部分里面为两个集合共有的元素。
    树的定义还需要强调两点：
        (1) n > 0时，根结点是唯一的;
        (2) m > 0时，（m可理解为根结点的子树数量），子树的数量没有限制，但子树之间一定是
        互不相交的。

6.2.1 结点分类
    树的结点包含数据元素及指向其子树的分支。
    结点的子树数称为结点的度（degree）。
        (1) 结点的度为0的结点称为叶结点（leaf）或终端结点；
        (2) 结点的度不为0的结点称为分支结点或非终端结点；
            a. 除根结点外，分支结点也成为内部结点。
        树的度为树的所有结点的度中的最大值。

6.2.2 结点间关系
    结点的子树的根<结点>为该结点的子(child),相应地，该结点为子的父(parent)；
    具有相同父的结点为兄弟(sibling);
    从根结点到该结点所经过的所有<分支>结点为祖先,
    以某节点为根的子树的任一结点为该结点的子孙；

6.2.3 树的其他相关概念
    结点的层次，从根开始定义，
        第一层：根；
        第二层：根的子；
        某结点在第i层，则其子树的根在i + 1层；
        父结点在同一层互为堂兄弟；

        树的结点的最大层次为树的深度（depth）或高度。
        注意：这里说的是树的深度或高度。(本质也就是树的根结点的深度或高度)

    结点的深度和高度的定义是不一样的，对于任意结点ni:
        ni的深度(depth)为从根到ni的(唯一)路径长,根的深度为0;
        从结点ni到nk的路径(path)定义为结点ni...nk的一个序列,使得1<=i<k结点ni是ni+1的父结点，
        路径长(length)为路径上的边的条数;
        n1到nk结点,路径长为k-1,1<=i<k,结点ni是结点ni+1的父结点;
        ni到nk结点,路径长为k-i,结点ni是结点ni+1的父结点;
        ni的高度(height)为从ni到叶结点的最长路径长,因此,所有叶结点的高度都为0。
        
    森林(forest)是m（m >= 0）棵互不相交的树的集合。
    对树的每个结点而言，其子树的集合即为森林。

    无序树...

    有序树...


*/