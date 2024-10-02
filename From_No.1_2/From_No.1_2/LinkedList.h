#pragma once
#include <string>
class LinkedList
{
private:

    class Iterator;
    class ConstIterator;

    //���уf�[�^
    struct DATA
    {
        std::string Score;
        std::string Name;
    };

    //�m�[�h
    struct NODE
    {
        NODE* prev = NULL;     //��O�̃m�[�h
        NODE* next = NULL;     //���̃m�[�h
        DATA Data;             //�f�[�^
    };

    NODE* Head = nullptr; //�擪�̃m�[�h
    NODE* Tail = nullptr; //�����̃m�[�h

    //�f�[�^�̐�
    int DataNum = 0;

public:
    LinkedList() {}
    ~LinkedList() {}

    ////�f�[�^��ݒ肷��
    //void SetData(std::string _score, std::string _name) {
    //    NODE
    //}

    //�f�[�^����Ԃ�
    int GetDataNum() { return DataNum; }

    //�擪���ǂ����Ԃ�
    bool CheckHead(Iterator* _it) {
        if (Head == _it->Node)
            return true;
        else
            return false;
    }

    //�������ǂ����Ԃ�
    bool CheckTail(Iterator* _it) {
        if (Tail == _it->Node)
            return true;
        else
            return false;
    }

    //�擪�ɑ}��
    void insertFront(Iterator* _it) {
        //�V�����m�[�h�쐬
        NODE* NewNode;
        NewNode = new NODE;
        NewNode = _it->Node;
        if (Head == NULL)
        {
            //�v�f���Ȃ��ꍇ
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //�v�f������ꍇ
            //�����N���q���ς���
            NewNode->next = Head;
            Head->prev = NewNode;
            Head = NewNode;
        }
        DataNum++;
    }
    void InsertFront(std::string _score, std::string _name)
    {
        //�V�����m�[�h�쐬
        NODE* NewNode;
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
        NewNode = new NODE;
        NewNode->Data = Data;
        if (Head == NULL)
        {
            //�v�f���Ȃ��ꍇ
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //�v�f������ꍇ
            //�����N���q���ς���
            NewNode->next = Head;
            Head->prev = NewNode;
            Head = NewNode;
        }
        DataNum++;
    }

    //�����ɑ}��
    void InsertLast(Iterator* _it) {
        //�V�����m�[�h���쐬
        NODE* NewNode;
        NewNode = new NODE;
        NewNode = _it->Node;
        if (Tail == NULL)
        {
            //�v�f���Ȃ��ꍇ
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //�v�f������ꍇ
            //�����N���q���ς���
            Tail->next = NewNode;
            NewNode->prev = Tail;
            Tail = NewNode;
        }
        DataNum++;
    }
    void InsertLast(std::string _score, std::string _name)
    {
        //�V�����m�[�h�쐬
        NODE* NewNode;
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
        NewNode = new NODE;
        NewNode->Data = Data;
        if (Tail == NULL)
        {
            //�v�f���Ȃ��ꍇ
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //�v�f������ꍇ
            //�����N���q���ς���
            Tail->next = NewNode;
            NewNode->prev = Tail;
            Tail = NewNode;
        }
        DataNum++;
    }

    //�f�[�^�̑}��(�C�e���[�^)
    bool Insert(Iterator* _it, std::string _score, std::string _name)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if (_it != nullptr && _it->Node != nullptr)
        {
            NODE* current = Head;
            NODE* NewNode = new NODE();
            if (current != nullptr)
            {
                NewNode = _it->Node;
                while (current != _it->Node && (Head != nullptr && Tail != nullptr))
                {
                    current = current->next;
                }

                if (current == Head)
                {
                    NewNode->next = current;
                    current->prev = NewNode;
                    Head = NewNode;
                }
                else
                {
                    NewNode->next = current;
                    NewNode->prev = current->prev;
                    current->prev = NewNode;
                }
            }
            else
            {
                NewNode = _it->Node;
                Head = NewNode;
                Tail = NewNode;
            }


            //NODE* NewNode = new NODE();
            //NewNode = _it->Node;
            //if (Tail == nullptr && Head == nullptr)
            //{
            //    //�擪�Ɩ����ɒǉ�
            //    Tail = NewNode;
            //    Head = NewNode;
            //}
            //else
            //{
            //    NODE* current = Head;
            //    while (current != nullptr)
            //    {
            //        current = current->next;
            //    }
            //    if (NewNode == Head)
            //    {
            //        NewNode->next = Head;
            //        Head->prev = NewNode;
            //        Head = NewNode;
            //    }
            //    else if (NewNode == Tail)
            //    {
            //        NewNode->prev = Head;
            //        Head->next = NewNode;
            //        Tail = NewNode;
            //    }
            //    else
            //    {
            //        NewNode->next = current;
            //        NewNode->prev = current->prev;
            //        current->prev = NewNode;

            //        //NewNode->next = Tail;
            //        //NewNode->prev = Head;
            //        //Head->next = NewNode;
            //        //Tail->prev = NewNode;
            //    }

            //}

            DataNum++;
            return true;
        }

        return false;
    }

    //�f�[�^�̍폜(�C�e���[�^)
    bool Delete(Iterator* _it)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if (_it != nullptr && (Head != nullptr && Tail != nullptr))
        {
            NODE* current = Head;
            while (current != _it->Node)
            {
                if (current == nullptr)
                    break;
                current = current->next;
                //if (current->next == NULL)
                //    break;
            }

            if (current != nullptr)
            {
                if (current == Head)    //�擪��������
                    Head = current->next;
                else if(current == Tail)    //������������
                    Tail = current->prev;
                else
                {
                    //�ЂƂO�̃m�[�h�ƈ��̃m�[�h��g�ݍ��킹��
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                // ���������
                delete current; 
                DataNum--;
                return true;
            }

        }
        return false;
    }

    bool Delete(const Iterator* _it)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if (_it != nullptr && (Head != nullptr && Tail != nullptr))
        {
            NODE* current = Head;
            while (current != _it->Node)
            {
                if (current == nullptr)
                    break;
                current = current->next;
                //if (current->next == NULL)
                //    break;
            }

            if (current != nullptr)
            {
                if (current == Head)    //�擪��������
                    Head = current->next;
                else if (current == Tail)    //������������
                    Tail = current->prev;
                else
                {
                    //�ЂƂO�̃m�[�h�ƈ��̃m�[�h��g�ݍ��킹��
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                // ���������
                delete current;
                DataNum--;
                return true;
            }

        }
        return false;
    }

    //�擪�C�e���[�^�擾
    LinkedList::Iterator* GetBegin() {
        if (Head != NULL)
        {
            Iterator* it = new LinkedList::Iterator();
            it->Node = Head;
            return it;
        }
        else
        {
            Iterator* it = new LinkedList::Iterator();
            NODE* Node;
            Node = new NODE();
            it->Node = Node;
            Head = Node;
            Tail = Node;
            return it;
        }
    }

    //�擪�C�e���[�^�擾
    bool GetBeginBool() {
        if (Head != NULL)
        {
            Iterator* it = new LinkedList::Iterator();
            it->Node = Head;
            return true;
        }
        else
        {
            NODE* node;
            return true;
        }
    }

    ////�擪�R���X�g�C�e���[�^�擾
     LinkedList::ConstIterator* GetConstBegin()const {
        if (Head != NULL)
        {
            ConstIterator* it = new LinkedList::ConstIterator();
            it->Node = Head;
            return it;
        }
        else
        {
            ConstIterator* it = new LinkedList::ConstIterator();
            NODE* Node;
            Node = new NODE();
            it->Node = Node;
            return it;
        }
    }

    //�擪�R���X�g�C�e���[�^�擾
    const bool GetConstBeginBool() const {
        if (Head != NULL)
        {
            Iterator* it = new LinkedList::Iterator();
            it->Node = Head;
            return true;
        }
        else
        {
            NODE* node;
            return true;
        }
    }

    //�����C�e���[�^�擾
    LinkedList::Iterator* GetEnd() {
        if (Tail != NULL)
        {
            Iterator* it = new LinkedList::Iterator();
            it->Node = Tail;
            return it;
        }
        else
        {
            Iterator* it = new LinkedList::Iterator();
            NODE* Node;
            Node = new NODE();
            it->Node = Node;
            Head = Node;
            Tail = Node;
            return it;
        }
    }

    //�����C�e���[�^�擾
    bool GetEndBool() {
        if (Tail != NULL)
        {
            Iterator* it = new LinkedList::Iterator();
            it->Node = Tail;
            return true;
        }
        else
        {
            Iterator* it = new LinkedList::Iterator();
            NODE* Node;
            Node = new NODE();
            it->Node = Node;
            Head = Node;
            Tail = Node;
            return true;
        }
    }

    //�����R���X�g�C�e���[�^�擾
    const bool GetConstEndBool() const {
        if (Tail != NULL)
        {
            Iterator* it = new LinkedList::Iterator();
            it->Node = Tail;
            return true;
        }
        else
        {
            Iterator* it = new LinkedList::Iterator();
            NODE* Node;
            Node = new NODE();
            it->Node = Node;
            return true;
        }
    }

    //�����R���X�g�C�e���[�^�擾
    LinkedList::ConstIterator* GetConstEnd() const {
        if (Tail != NULL)
        {
            ConstIterator* it = new LinkedList::ConstIterator();
            it->Node = Tail;
            return it;
        }
        else
        {
            ConstIterator* it = new LinkedList::ConstIterator();
            NODE* Node;
            Node = new NODE();
            it->Node = Node;
            return it;
        }
    }

    //���X�g�̓��e��\��
    void display() const {
        LinkedList::Iterator* it = new LinkedList::Iterator();
        it->Node = Head;
        while (it->Node != nullptr) {
            printf("�X�R�A: %s ,���O: %s \n", it->Node->Data.Score.c_str(), it->Node->Data.Name.c_str());
            it->AddIterator(it);
        }
    }

    //�C�e���[�^�N���X
    class Iterator
    {
    public:
        //�m�[�h
        NODE *Node = nullptr;

        //�v�f��Ԃ�
        NODE* GetNode() { return Node; }

        //�v�f��Ԃ�
        bool GetNodeBool() { 
            if (Node != nullptr)
                return true;
            else
                return false;
        }

        //�l�擾
        DATA GetNodeData()
        {
            if (Node != nullptr)
            {
                DATA Data;
                Data.Score = Node->Data.Score;
                Data.Name = Node->Data.Name;
                return Data;
            }
            else
            {
                DATA Data;
                Data.Score = "NULL";
                Data.Name = "NULL";
                return Data;
            }
        }

        //�m�[�h�̒��g��ύX
        void ChengeData(std::string _score, std::string _name)
        {
            Node->Data.Score = _score;
            Node->Data.Name = _name;
        }

        bool FalseCheckIterator(Iterator* _it1, Iterator* _it2)
        {
            if (_it1->Node != _it2->Node)
            {
                return true;
            }
            else
                return false;
        }

        bool TrueCheckIterator(Iterator* _it1, Iterator* _it2)
        {
            if (_it1->Node == _it2->Node)
            {
                return true;
            }
            else
                return false;
        }

        //�C�e���[�^�̂����v�f���擾����(��const)
        NODE* operator*() { return Node; }

        //�������
        Iterator& operator=(const Iterator& _it) {
            if (this != &_it) {
                Node = _it.Node;
            }
            return *this;
        }

        //�������
        Iterator operator=(NODE* _node) {
            if (Node != _node) {
                Node = _node;
            }
            return *this;
        }

        Iterator(){}
        ~Iterator(){}

        void AddIterator(Iterator* _it)
        {
            _it->Node = _it->Node->next;
        }
        void SumIterator(Iterator* _it)
        {
            _it->Node = _it->Node->prev;
        }

    private:

    };

    //�R���X�g�C�e���[�^�N���X
    class ConstIterator:
        public Iterator
    {
    public:
        //�I�y���[�^
        //�擪�Ɍ������ăC�e���[�^��i�߂�
        Iterator* operator--(int) {
            Iterator* it = new Iterator();
            it->Node = Node->prev;
            return it;
        }
        //�����Ɍ������ăC�e���[�^��i�߂�
        Iterator* operator++(int) {
            Iterator* it = new Iterator();
            it->Node = Node->next;
            return it;
        }
        //�C�e���[�^�̂����v�f���擾����(const)
        const NODE* operator*() const { return Node; }
        // �R�s�[�R���X�g���N�^
       void  CopyConst(NODE* _node) { Node = _node; }
       //���
        const LinkedList::ConstIterator* operator =(const Iterator* _it) {
            if (this != _it) {
                LinkedList::ConstIterator* NewConst = new LinkedList::ConstIterator();
                NewConst->Node = _it->Node;
                return NewConst;
            }
        }

         LinkedList::ConstIterator* operator =(Iterator* _it) {
            if (this != _it) {
                LinkedList::ConstIterator* NewConst = new LinkedList::ConstIterator();
                NewConst->Node = _it->Node;
                return NewConst;
            }
        }

    private:

    };
};
