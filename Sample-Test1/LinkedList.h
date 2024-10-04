#pragma once
#include <string>
#include "test.h"
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
        bool IsDammy = false;  //�_�~�[��
    };

    //�_�~�[�m�[�h
    NODE Dammy;

    //�f�[�^�̐�
    int DataNum = 0;

public:
    /**
     * LinkedList�N���X�̃R���X�g���N�^�B
     * �������������s���܂��B
     */
    LinkedList() {
        Dammy.Next = Dammy.Prev = &Dammy;
        Dammy.IsDammy = true;
    }
    ~LinkedList() {}

    /**
     * �f�[�^����Ԃ��֐��ł��B
     * ���݂̃f�[�^����Ԃ��܂�
     */
    int GetDataNum() { return DataNum; }

    /**
     * �_�~�[�m�[�h���擾����֐��ł��B
     * �_�~�[�m�[�h��Ԃ��܂�
     */
    NODE* GetDammy() { return &Dammy; }

    /**
    * �󂯎�����f�[�^�����X�g�̐擪�Ɋi�[����֐��ł��B
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    bool InsertFront(const int& _score, const std::string& _name)
    {
        //�V�����m�[�h�쐬
        NODE* NewNode;
        //�f�[�^����
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
        //�m�[�h�쐬
        NewNode = new NODE();
        NewNode->Data = Data;
        NewNode->Prev = &Dammy;       //�V�����m�[�h�̑O�̓_�~�[(�擪)
        NewNode->Next = Dammy.Next;   //�V�����m�[�h�̎��̓_�~�[�̎�(�擪�������m�[�h)
        Dammy.Next->Prev = NewNode;   //�擪�������m�[�h�̑O��V�����m�[�h
        Dammy.Next = NewNode;
        DataNum++;
        return true;
    }

    /**
    * �󂯎�����f�[�^�����X�g�̖����Ɋi�[����֐��ł��B
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    bool InsertLast(const int& _score, const std::string& _name)
    {
        //�V�����m�[�h�쐬
        NODE* NewNode;
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
        //�m�[�h�쐬
        NewNode = new NODE();
        NewNode->Data = Data;
        NewNode->Prev = Dammy.Prev;   //�V�����m�[�h�̑O�̓_�~�[(�����������m�[�h)
        NewNode->Next = &Dammy;       //�V�����m�[�h�̎��̓_�~�[
        Dammy.Prev->Next = NewNode;   //�����������m�[�h�̎���V�����m�[�h
        Dammy.Prev = NewNode;
        DataNum++;
        return  true;
    }

    /**
    * �C�e���[�^���g�p���ă��X�g�Ɋi�[����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    bool Insert(Iterator& _it, const int& _score, const std::string& _name)
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
            _it.Node->Prev = NewNode;
            DataNum++;
            return true;
        }
        return false;
    }

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
            _it.Node->Prev = NewNode;
            DataNum++;
            return true;
        }
        return false;
    }

    /**
    * �C�e���[�^���g�p���ă��X�g�̗v�f���폜����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    */
    bool Delete(Iterator& _it)
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
        it.Node = Dammy.Next;
        return it;
    }

    /*
    * �擪�R���X�g�C�e���[�^���擾����֐��ł��B
    * @return �擪�R���X�g�C�e���[�^
    */
    LinkedList::ConstIterator GetConstBegin()const {
        LinkedList::ConstIterator Constit;
        Constit.Node = Dammy.Next;
        return Constit;
    }

    /*
    * �����C�e���[�^���擾����֐��ł��B
    * @return �擪�C�e���[�^
    */
    LinkedList::Iterator GetEnd() {
        Iterator it;
        it.Node = Dammy.Prev;
        return it;
    }

    /*
     * �����R���X�g�C�e���[�^���擾����֐��ł��B
     * @return �擪�C�e���[�^
     */
    LinkedList::ConstIterator GetConstEnd() const {
        LinkedList::ConstIterator Constit;
        Constit.Node = Dammy.Prev;
        return Constit;
    }

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

        friend class LinkedList;

    public:
        //�R���X�g���N�^
        LinkedList::ConstIterator() {}

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

        /*
         * �_�~�[�m�[�h�����ׂ܂�
         * @return �m�[�h���_�~�[�m�[�h���ǂ�����Ԃ��܂�
        */
        bool IsDammy() {
            if (Node->IsDammy)
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
            Node = Node->Next;
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            return Constit;
        }

        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator++(int) {
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            Node = Node->Next;
            return Constit;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator--() {
            Node = Node->Prev;
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            return Constit;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator--(int) {
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            Node = Node->Prev;
            return Constit;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����I�y���[�^(const)�ł�
         * @return �m�[�h��Ԃ��܂�
        */
        const DATA operator*() const { return Node->Data; }

        /*
         * �R�s�|�R���X�g���N�^�ł�
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}

        ////���
        //const LinkedList::ConstIterator operator=(const ConstIterator& _it) {
        //        LinkedList::ConstIterator NewConst;
        //        NewConst = _it;
        //        return NewConst;
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
            assert(Node != nullptr && "Iterator points to null!");
            assert(Node->IsDammy != true && "Iterator points to Dammy!");
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
            assert(Node != nullptr && "Iterator points to null!");
            assert(Node->IsDammy != true && "Iterator points to Dammy!");
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
            assert(Node != nullptr && "Iterator points to null!");
            assert(Node->IsDammy != true && "Iterator points to Dammy!");
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
            assert(Node != nullptr && "Iterator points to null!");
            assert(Node->IsDammy != true && "Iterator points to Dammy!");
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
            assert(Node != nullptr && "Iterator points to null!");
            assert(Node->IsDammy !=  true && "Iterator points to Dammy!");
            return Node->Data;
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
