#pragma once
#include <string>
#include "main.h"


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
     *�m�[�h������\���̂ł��B
     *
     * @param prev  �O�̃m�[�h
     * @param next  ���̃m�[�h
     * @param Data  �f�[�^
     */
    struct NODE
    {
        NODE* Prev = nullptr;     //��O�̃m�[�h
        NODE* Next = nullptr;     //���̃m�[�h
        DATA Data;             //�f�[�^
    };

    //�_�~�[�m�[�h
    NODE* Dummy;

    //�f�[�^�̐�
    int DataNum = 0;

    /**
     * �_�~�[�m�[�h���擾����֐��ł��B
     * �_�~�[�m�[�h��Ԃ��܂�
     */
    NODE* GetDummy() { return Dummy; }

    /*
        * �_�~�[�m�[�h�����ׂ܂�
         * @return �m�[�h���_�~�[�m�[�h���ǂ�����Ԃ��܂�
    */
    bool IsDummy(NODE* _node) {
        if (Dummy == _node)
            return true;
        else
            return false;
    }

public:
    /**
     * LinkedList�N���X�̃R���X�g���N�^�B
     * �������������s���܂��B
     */
    LinkedList() {
        Dummy = new NODE();
        Dummy->Next = Dummy->Prev = Dummy;
    }
    ~LinkedList() {}

    /**
     * �f�[�^����Ԃ��֐��ł��B
     * ���݂̃f�[�^����Ԃ��܂�
     */
    int GetDataNum() const { return DataNum; }

    /**
    * �R���X�g�C�e���[�^���g�p���ă��X�g�Ɋi�[����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    bool Insert(ConstIterator& _it, const int& _score, const std::string& _name)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if (!_it.IsEmpty())
        {
            //�V�����m�[�h�쐬
            NODE* NewNode = new NODE();
            DATA Data;
            Data.Score = _score;
            Data.Name = _name;
            NewNode->Data = Data;
            NewNode->Next = _it.Node;
            NewNode->Prev = _it.Node->Prev;
            _it.Node->Prev->Next = NewNode;
            _it.Node->Prev = NewNode;
            DataNum++;
            return true;
        }
        return false;
    }

    /**
    * �R���X�g�C�e���[�^���g�p���ă��X�g�̗v�f���폜����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    */
    bool Delete(ConstIterator& _it)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if (!_it.IsEmpty())
        {
            _it.Node->Next->Prev = _it.Node->Prev;
            _it.Node->Prev->Next = _it.Node->Next;
            delete _it.Node;
            DataNum--;
            return true;
        }
        return false;
    }

    /*
    * �擪�C�e���[�^���擾����֐��ł��B
    * @return �擪�C�e���[�^
    */
    LinkedList::Iterator GetBegin() {
        Iterator it;
        it.Node = Dummy->Next;
        return it;
    }

    /*
    * �擪�R���X�g�C�e���[�^���擾����֐��ł��B
    * @return �擪�R���X�g�C�e���[�^
    */
    LinkedList::ConstIterator GetConstBegin()const {
        LinkedList::ConstIterator Constit;
        Constit.Node = Dummy->Next;
        return Constit;
    }

    /*
    * �����C�e���[�^���擾����֐��ł��B
    * @return �����C�e���[�^
    */
    LinkedList::Iterator GetEnd() {
        Iterator it;
        it.Node = Dummy;
        return it;
    }

    /*
     * �����R���X�g�C�e���[�^���擾����֐��ł��B
     * @return �擪�C�e���[�^
     */
    LinkedList::ConstIterator GetConstEnd() const {
        LinkedList::ConstIterator Constit;
        Constit.Node = Dummy;
        return Constit;
    }   

    //�R���X�g�C�e���[�^�N���X
    class ConstIterator
    {
    private:
        friend class LinkedList;

    protected:
        //�m�[�h
        NODE* Node = nullptr;

    public:
        LinkedList::ConstIterator(){}

        /*
         * �m�[�h���󂩒��ׂ܂�
         * @return �m�[�h���󂩂ǂ�����Ԃ��܂�
        */
        bool IsEmpty() {
            if (Node == nullptr)
                return true;
            else
                return false;
        }

        //�I�y���[�^
        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator++() {
            this->Node = Node->Next;
            return *this;
        }

        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator++(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Next;
            return it;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator--() {
            this->Node = Node->Prev;
            return *this;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator--(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Prev;
            return it;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����I�y���[�^(const)�ł�
         * @return �m�[�h��Ԃ��܂�
        */
        const DATA operator*() const { return this->Node->Data; }
        /*
         * �R�s�|�R���X�g���N�^�ł�
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}
        //���
        LinkedList::ConstIterator operator=(const Iterator* _it) {
            if (this != _it) {
                LinkedList::ConstIterator NewConst;
                NewConst = _it;
                return NewConst;
            }
            return *this;
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
    private:
        friend class LinkedList;

    public:
        //�R���X�g���N�^
        LinkedList::Iterator() {}

        //�I�y���[�^
        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator++() {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            this->Node = Node->Next;
            return *this;
        }

        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator++(int) {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
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
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            this->Node = Node->Prev;
            return *this;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator--(int) {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Prev;
            return it;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����(��const)�֐��ł��B
         * @return �C�e���[�^�̗v�f��Ԃ��܂�
        */
        DATA operator*() {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            return this->Node->Data;
        }

        /*
         * ��r����I�y���[�^�ł�
         * @return ���ꂩ��Ԃ��܂�
        */
        bool operator==(const LinkedList::Iterator& _it) const {
            return Node == _it.Node;
        }

        /*
         * ��r����I�y���[�^�ł�
         * @return �قȂ邩��Ԃ��܂�
        */
        bool operator!=(const LinkedList::Iterator& _it) const {
            return Node != _it.Node;
        }
    };
};
