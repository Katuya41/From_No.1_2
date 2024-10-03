#pragma once
#include <string>

/**
 * �����LinkedList�N���X�̐����ł��B
 * ���̃N���X�͑o�������X�g�Ŏg�p����܂��B
 *
 * @author �g������
 * @since 2024-10-02
 */
class LinkedList
{
private:
    class Iterator;
    class ConstIterator;

    /**
     *�f�[�^������\���̂ł��B
     *
     * @param Score �X�R�A
     * @param Name  ���O
     */
    struct DATA
    {
        std::string Score;
        std::string Name;
    };

    /**
     *�m�[�h������\���̂ł��B
     *
     * @param prev  �O�̃m�[�h
     * @param next  ���̃m�[�h
     * @param Data  �f�[�^
     */
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
    /**
     * LinkedList�N���X�̃R���X�g���N�^�B
     * �������������s���܂��B
     */
    LinkedList() {}
    ~LinkedList() {}

    /**
     * �f�[�^����Ԃ��֐��ł��B
     * ���݂̃f�[�^����Ԃ��܂�
     */
    int GetDataNum() { return DataNum; }

    //�擪�ɑ}��
    void insertFront(Iterator _it) {
        //�V�����m�[�h�쐬
        NODE* NewNode;
        NewNode = new NODE;
        NewNode = (*_it);
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

    /**
    * �󂯎�����f�[�^�����X�g�̐擪�Ɋi�[����֐��ł��B
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    void InsertFront(std::string& _score, std::string& _name)
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
    void InsertLast(Iterator _it) {
        //�V�����m�[�h���쐬
        NODE* NewNode;
        NewNode = new NODE;
        NewNode = (*_it);
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

    /**
    * �󂯎�����f�[�^�����X�g�̖����Ɋi�[����֐��ł��B
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    void InsertLast(std::string& _score, std::string& _name)
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

    /**
    * �C�e���[�^���g�p���ă��X�g�Ɋi�[����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    void Insert(Iterator _it, std::string _score, std::string _name)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if ((*_it) != nullptr)
        {
            NODE* current = Head;
            NODE* NewNode = new NODE();
            if (current != nullptr)
            {
                NewNode = (*_it);
                while (current != (*_it) && (Head != nullptr && Tail != nullptr))
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
                NewNode = (*_it);
                Head = NewNode;
                Tail = NewNode;
            }
            DataNum++;
        }
    }

    /**
    * �C�e���[�^���g�p���ă��X�g�̗v�f���폜����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    */
    void Delete(Iterator _it)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if (Head != nullptr && Tail != nullptr)
        {
            NODE* current = Head;
            while (current != (*_it))
            {
                if (current == nullptr)
                    break;
                current = current->next;
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
            }

        }
    }

    /*
    * �擪�C�e���[�^���擾����֐��ł��B
    * @return �擪�C�e���[�^
    */
    LinkedList::Iterator GetBegin() {
        if (Head != NULL)
        {
            Iterator it;
            it = Head;
            return it;
        }
        else
        {
            Iterator it;
            NODE* Node;
            Node = new NODE();
            it = Node;
            Head = Node;
            Tail = Node;
            return it;
        }
    }

    /*
    * �擪�R���X�g�C�e���[�^���擾����֐��ł��B
    * @return �擪�R���X�g�C�e���[�^
    */
     LinkedList::ConstIterator GetConstBegin()const {
        if (Head != NULL)
        {
            ConstIterator it;
            it = Head;
            return it;
        }
        else
        {
            ConstIterator it;
            NODE* Node;
            Node = new NODE();
            it = Node;
            return it;
        }
    }

     /*
     * �����C�e���[�^���擾����֐��ł��B
     * @return �擪�C�e���[�^
     */
    LinkedList::Iterator GetEnd() {
        if (Tail != NULL)
        {
            Iterator it;
            it = Tail;
            return it;
        }
        else
        {
            Iterator it;
            NODE* Node;
            Node = new NODE();
            it = Node;
            Head = Node;
            Tail = Node;
            return it;
        }
    }

    /*
     * �����R���X�g�C�e���[�^���擾����֐��ł��B
     * @return �擪�C�e���[�^
     */
    LinkedList::ConstIterator GetConstEnd() const {
        if (Tail != NULL)
        {
            ConstIterator it;
            it = Tail;
            return it;
        }
        else
        {
            ConstIterator it;
            NODE* Node;
            Node = new NODE();
            it = Node;
            return it;
        }
    }

    /*
     * ���X�g�̓��e��擪���珇�Ԃɏo�͂���֐��ł��B
     */
    void display() const {
        LinkedList::Iterator it;
        it = Head;

        while ((*it) != nullptr) {
            printf("�X�R�A: %s ,���O: %s \n", (*it)->Data.Score.c_str(), (*it)->Data.Name.c_str());
            it++;
            //++it;
        }
    }

#pragma warning(push)
#pragma warning(disable : 4240)

    //�R���X�g�C�e���[�^�N���X
    class ConstIterator
    {
    protected:
        //�m�[�h
        NODE* Node = nullptr;

    public:
        LinkedList::ConstIterator(){}

        //�I�y���[�^
        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator++() {
            Node = Node->next;
            LinkedList::Iterator it;
            it.Node = Node;
            return it;
        }

        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator++(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->next;
            return it;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator--() {
            Node = Node->prev;
            LinkedList::Iterator it;
            it.Node = Node;
            return it;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator--(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->prev;
            return it;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����I�y���[�^(const)�ł�
         * @return �m�[�h��Ԃ��܂�
        */
        const NODE* operator*() const { return Node; }
        /*
         * �R�s�|�R���X�g���N�^�ł�
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}
        //���
        const LinkedList::ConstIterator operator=(const Iterator* _it) {
            if (this != _it) {
                LinkedList::ConstIterator NewConst;
                NewConst = _it;
                return NewConst;
            }
        }
        //���
        LinkedList::ConstIterator operator=(NODE* _node) {
                LinkedList::ConstIterator NewConstit;
                NewConstit = _node;
                return NewConstit;
        }

        /*
         * ��r����I�y���[�^�ł�
         * @return ���ꂩ��Ԃ��܂�
        */
        bool operator==(const LinkedList::ConstIterator& _constit) const {
            return Node == _constit.Node;
        }

        /*
         * ��r����I�y���[�^�ł�
         * @return �قȂ邩��Ԃ��܂�
        */
        bool operator!=(const LinkedList::ConstIterator& _constit) const {
            return Node != _constit.Node;
        }

    };

    /**
    * �����Iterator�N���X�̐����ł��B
    * ���̃N���X�͑o�������X�g�Ŏg�p����܂��B
    *
    * @author �g������
    * @since 2024-10-02
    */
    class Iterator :
        public ConstIterator
    {
    public:

        /**
         * ���݂̃C�e���[�^�̗v�f��Ԃ��֐��ł��B
         * @return �C�e���[�^�̒��g
        */
        NODE* GetNode() { return Node; }

        /**
         * ���݂̃C�e���[�^�̃m�[�h�̃f�[�^��Ԃ��֐��ł��B
         * @return �C�e���[�^�̃m�[�h�̒��g
        */
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

        /**
         * �C�e���[�^�̒��g�̃m�[�h�̃f�[�^��ύX����֐��ł��B
         * @param _score   �ύX��̃X�R�A
         * @param _name    �ύX��̖��O
        */
        void ChengeData(std::string& _score, std::string& _name)
        {
            Node->Data.Score = _score;
            Node->Data.Name = _name;
        }

        /**
         * �󂯎�����C�e���[�^������łȂ����𒲂ׂ�֐��ł��B
         * @param _it1   ��r����C�e���[�^1
         * @param _it2   ��r����C�e���[�^2
         * @return ��r�����C�e���[�^������łȂ�����Ԃ��܂�
        */
        bool FalseCheckIterator(Iterator*& _it1, Iterator*& _it2)
        {
            if (_it1->Node != _it2->Node)
            {
                return true;
            }
            else
                return false;
        }

        /**
         * �󂯎�����C�e���[�^�����ꂩ�𒲂ׂ�֐��ł��B
         * @param _it1   ��r����C�e���[�^1
         * @param _it2   ��r����C�e���[�^2
         * @return ��r�����C�e���[�^�����ꂩ��Ԃ��܂�
        */
        bool TrueCheckIterator(Iterator* _it1, Iterator* _it2)
        {
            if (_it1->Node == _it2->Node)
            {
                return true;
            }
            else
                return false;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����(��const)�֐��ł��B
         * @return �C�e���[�^�̗v�f��Ԃ��܂�
        */
        NODE* operator*() const { return Node; }

        //�I�y���[�^

        //���
        LinkedList::Iterator& operator=(NODE* _node) {
            this->Node = _node;
            return *this;
        }

    private:

    };
#pragma warning(pop)
};
