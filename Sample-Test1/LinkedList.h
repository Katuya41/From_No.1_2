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
public:
    class Iterator;
    class ConstIterator;

private:

    /**
     *�f�[�^������\���̂ł��B
     *
     * @param Score ����
     * @param Name  ���O
     */
    struct DATA
    {
        int Score = NULL;
        std::string Name;
    };

    /**
     *�m�[�h������\���̂ł��B
     *
     * @param Prev  �O�̃m�[�h
     * @param Next  ���̃m�[�h
     * @param Data  �f�[�^
     */
    struct NODE
    {
        NODE* Prev = NULL;     //��O�̃m�[�h
        NODE* Next = NULL;     //���̃m�[�h
        DATA Data = {};          //�f�[�^
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

     /**
      * �f�[�^����Ԃ��֐��ł��B
      * ���݂̃f�[�^����Ԃ��܂�
      */
    int GetDataNum() { return DataNum; }

    //�擪���ǂ����Ԃ�
    bool CheckHead(Iterator _it) {
        if (Head == (*_it))
            return true;
        else
            return false;
    }

    //�������ǂ����Ԃ�
    bool CheckTail(Iterator _it) {
        if (Tail == (*_it))
            return true;
        else
            return false;
    }

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
            NewNode->Next = Head;
            Head->Prev = NewNode;
            Head = NewNode;
        }
        DataNum++;
    }

    /**
    * �󂯎�����f�[�^�����X�g�̐擪�Ɋi�[����֐��ł��B
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    void InsertFront(int _score,std::string _name)
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
            NewNode->Next = Head;
            Head->Prev = NewNode;
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
            Tail->Next = NewNode;
            NewNode->Prev = Tail;
            Tail = NewNode;
        }
        DataNum++;
    }

    /**
    * �󂯎�����f�[�^�����X�g�̖����Ɋi�[����֐��ł��B
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    void InsertLast(int _score,std::string _name)
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
            Tail->Next = NewNode;
            NewNode->Prev = Tail;
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
    void Insert(Iterator _it, int _score,std::string _name)
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
                    current = current->Next;
                }

                if (current == Head)
                {
                    NewNode->Next = current;
                    current->Prev = NewNode;
                    Head = NewNode;
                }
                else
                {
                    NewNode->Next = current;
                    NewNode->Prev = current->Prev;
                    current->Prev = NewNode;
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

    bool InsertBool(Iterator _it, int _Score,std::string _name)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if ((*_it) != nullptr)
        {
            return true;
        }
        return false;
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
                current = current->Next;
            }

            if (current != nullptr)
            {
                if (current == Head)    //�擪��������
                    Head = current->Next;
                else if (current == Tail)    //������������
                    Tail = current->Prev;
                else
                {
                    //�ЂƂO�̃m�[�h�ƈ��̃m�[�h��g�ݍ��킹��
                    current->Prev->Next = current->Next;
                    current->Next->Prev = current->Prev;
                }
            }
            // ���������
            delete current;
            DataNum--;
        }
    }
    bool DeleteBool(Iterator _it)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if (Head != nullptr && Tail != nullptr)
        {
            return true;
        }
        return false;
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
            NODE* Node = nullptr;
            Node = new NODE();
            it = Node;
            Head = Node;
            Tail = Node;
            return it;
        }
    }

    //�擪�C�e���[�^�擾
    bool GetBeginBool() {
        if (Head != NULL)
        {
            return true;
        }
        else
        {
            Iterator it;
            NODE* Node;
            Node = new NODE();
            it = Node;
            Head = Node;
            Tail = Node;
            return true;
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
            (it) = Head;
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

    //�擪�R���X�g�C�e���[�^�擾
    const bool GetConstBeginBool() const {
        if (Head != NULL)
        {
            return true;
        }
        else
        {
            ConstIterator it;
            NODE* Node;
            Node = new NODE();
            it = Node;
            return true;
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

    //�����C�e���[�^�擾
    bool GetEndBool() {
        if (Tail != NULL)
        {
            return true;
        }
        else
        {
            Iterator it;
            NODE* Node;
            Node = new NODE();
            it = Node;
            Head = Node;
            Tail = Node;
            return true;
        }

    }

    //�����R���X�g�C�e���[�^�擾
    const bool GetConstEndBool() const {
        if (Tail != NULL)
        {
            return true;
        }
        else
        {
            Iterator it;
            NODE* Node;
            Node = new NODE();
            it = Node;
            return true;
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

    ///*
    // * ���X�g�̓��e��擪���珇�Ԃɏo�͂���֐��ł��B
    // */
    //void display() const {
    //    LinkedList::Iterator it;
    //    it = Head;
    //    while ((*it) != nullptr) {
    //        printf("�X�R�A: %s ,���O: %s \n", (*it)->Data.Score.c_str(), (*it)->Data.Name.c_str());
    //        it++;
    //        //++it;
    //    }
    //}

    /*
    * �����ConstIterator�N���X�̐����ł��B
    * ���̃N���X�͑o�������X�g�Ŏg�p����܂��B
    *
    * @author �g������
    * @since 2024-10-02
    */

public:
    class ConstIterator
    {
    protected:
        //�m�[�h
        NODE* Node = nullptr;

    public:
        LinkedList::ConstIterator() { Node = nullptr; }

        //�I�y���[�^
        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator++() {
            Node = Node->Next;
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
            Node = Node->Next;
            return it;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator--() {
            Node = Node->Prev;
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
            Node = Node->Prev;
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
            this->Node = _node;
            return *this;
        }

        ////���
        //LinkedList::ConstIterator operator=(LinkedList::ConstIterator _node) {
        //    LinkedList::ConstIterator NewConstit;
        //    NewConstit = _node;
        //    return NewConstit;
        //}

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
public:
    class Iterator :
        public ConstIterator
    {
    public:
        LinkedList::Iterator() { Node = nullptr; }

        /**
         * ���݂̃C�e���[�^�̗v�f��Ԃ��֐��ł��B
         * @return �C�e���[�^�̒��g
        */
        NODE* GetNode() {
            return Node;
        }

        /**
         * ���݂̃C�e���[�^�̃m�[�h�̃f�[�^��Ԃ��֐��ł��B
         * @return �C�e���[�^�̃m�[�h�̒��g
        */
        DATA GetNodeData()
        {
            return Node->Data;
        }

        bool GetNodeDataBool()
        {
            if (Node != nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        /**
         * �C�e���[�^�̒��g�̃m�[�h�̃f�[�^��ύX����֐��ł��B
         * @param _score   �ύX��̃X�R�A
         * @param _name    �ύX��̖��O
        */
        void ChengeData(int _score,std::string _name)
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
        bool FalseCheckIterator(Iterator& _it1, Iterator& _it2)
        {
            if (_it1.Node != _it2.Node)
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
        bool TrueCheckIterator(Iterator _it1, Iterator _it2)
        {
            if (_it1.Node == _it2.Node)
            {
                return true;
            }
            else
                return false;
        }

        bool AddIterator()
        {
            if (Node != nullptr)
            {
                if (Node->Next == nullptr)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }

        bool SumIterator()
        {
            if (Node != nullptr)
            {
                if (Node->Prev == nullptr)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����(��const)�֐��ł��B
         * @return �C�e���[�^�̗v�f��Ԃ��܂�
        */
        NODE* operator*() {
            return Node;
        }

        //�I�y���[�^

        //���
        LinkedList::Iterator& operator=(NODE* _node) {
            this->Node = _node;
            return *this;
        }
    };
};
