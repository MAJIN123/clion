#include <iostream>
//二叉搜索数转换成排序好的双向链表
struct BSTNode{
    int m_nValue;
    BSTNode* m_pLeft;
    BSTNode* m_pRight;
    BSTNode(int value=0,BSTNode* L=NULL,BSTNode* R=NULL):
            m_nValue(value),m_pLeft(L),m_pRight(R){}
};
void ConvertNode(BSTNode* root,BSTNode** LastNode){
    if(root==NULL)
        return;
    BSTNode* p=root;
    if(p->m_pLeft)
        ConvertNode(p->m_pLeft,LastNode);
    p->m_pLeft=*LastNode;
    if(*LastNode)
        (*LastNode)->m_pRight=p;
    *LastNode=p;
    if(p->m_pRight)
        ConvertNode(p->m_pRight,LastNode);
}
BSTNode* Convert(BSTNode* root){
    BSTNode* p=NULL;
    ConvertNode(root,&p);
    //p指向尾部节点
    BSTNode* Head=p;
    while(Head->m_pLeft!=NULL&&Head!=NULL){
        Head=Head->m_pLeft;
    }
    return Head;
}
int main() {
    BSTNode* m1=new BSTNode(2);
    BSTNode* m2=new BSTNode(1);
    BSTNode* m3=new BSTNode(3);
    m1->m_pLeft=m2;
    m1->m_pRight=m3;
    BSTNode* Head=Convert(m1);
    std::cout<<Head->m_pRight->m_nValue<<std::endl;//2
    return 0;
}