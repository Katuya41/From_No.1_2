#pragma once
#include <string>
class LinkedList
{
private:

    class Iterator;
    class ConstIterator;

    //成績データ
    struct DATA
    {
        std::string Score;
        std::string Name;
    };

    //ノード
    struct NODE
    {
        NODE* prev = NULL;     //一個前のノード
        NODE* next = NULL;     //次のノード
        DATA Data;             //データ
    };

    NODE* Head = nullptr; //先頭のノード
    NODE* Tail = nullptr; //末尾のノード

    //データの数
    int DataNum = 0;

public:
    LinkedList() {}
    ~LinkedList() {}

    ////データを設定する
    //void SetData(std::string _score, std::string _name) {
    //    NODE
    //}

    //データ数を返す
    int GetDataNum() { return DataNum; }

    //先頭かどうか返す
    bool CheckHead(Iterator* _it) {
        if (Head == _it->Node)
            return true;
        else
            return false;
    }

    //末尾かどうか返す
    bool CheckTail(Iterator* _it) {
        if (Tail == _it->Node)
            return true;
        else
            return false;
    }

    //先頭に挿入
    void insertFront(Iterator* _it) {
        //新しいノード作成
        NODE* NewNode;
        NewNode = new NODE;
        NewNode = _it->Node;
        if (Head == NULL)
        {
            //要素がない場合
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //要素がある場合
            //リンクを繋ぎ変える
            NewNode->next = Head;
            Head->prev = NewNode;
            Head = NewNode;
        }
        DataNum++;
    }
    void InsertFront(std::string _score, std::string _name)
    {
        //新しいノード作成
        NODE* NewNode;
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
        NewNode = new NODE;
        NewNode->Data = Data;
        if (Head == NULL)
        {
            //要素がない場合
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //要素がある場合
            //リンクを繋ぎ変える
            NewNode->next = Head;
            Head->prev = NewNode;
            Head = NewNode;
        }
        DataNum++;
    }

    //末尾に挿入
    void InsertLast(Iterator* _it) {
        //新しいノードを作成
        NODE* NewNode;
        NewNode = new NODE;
        NewNode = _it->Node;
        if (Tail == NULL)
        {
            //要素がない場合
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //要素がある場合
            //リンクを繋ぎ変える
            Tail->next = NewNode;
            NewNode->prev = Tail;
            Tail = NewNode;
        }
        DataNum++;
    }
    void InsertLast(std::string _score, std::string _name)
    {
        //新しいノード作成
        NODE* NewNode;
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
        NewNode = new NODE;
        NewNode->Data = Data;
        if (Tail == NULL)
        {
            //要素がない場合
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //要素がある場合
            //リンクを繋ぎ変える
            Tail->next = NewNode;
            NewNode->prev = Tail;
            Tail = NewNode;
        }
        DataNum++;
    }

    //データの挿入(イテレータ)
    bool Insert(Iterator* _it, std::string _score, std::string _name)
    {
        //イテレータが空じゃないか確認
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
            //    //先頭と末尾に追加
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

    //データの削除(イテレータ)
    bool Delete(Iterator* _it)
    {
        //イテレータが空じゃないか確認
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
                if (current == Head)    //先頭だったら
                    Head = current->next;
                else if(current == Tail)    //末尾だったら
                    Tail = current->prev;
                else
                {
                    //ひとつ前のノードと一つ後のノードを組み合わせる
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                // メモリ解放
                delete current; 
                DataNum--;
                return true;
            }

        }
        return false;
    }

    bool Delete(const Iterator* _it)
    {
        //イテレータが空じゃないか確認
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
                if (current == Head)    //先頭だったら
                    Head = current->next;
                else if (current == Tail)    //末尾だったら
                    Tail = current->prev;
                else
                {
                    //ひとつ前のノードと一つ後のノードを組み合わせる
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                // メモリ解放
                delete current;
                DataNum--;
                return true;
            }

        }
        return false;
    }

    //先頭イテレータ取得
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

    //先頭イテレータ取得
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

    ////先頭コンストイテレータ取得
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

    //先頭コンストイテレータ取得
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

    //末尾イテレータ取得
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

    //末尾イテレータ取得
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

    //末尾コンストイテレータ取得
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

    //末尾コンストイテレータ取得
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

    //リストの内容を表示
    void display() const {
        LinkedList::Iterator* it = new LinkedList::Iterator();
        it->Node = Head;
        while (it->Node != nullptr) {
            printf("スコア: %s ,名前: %s \n", it->Node->Data.Score.c_str(), it->Node->Data.Name.c_str());
            it->AddIterator(it);
        }
    }

    //イテレータクラス
    class Iterator
    {
    public:
        //ノード
        NODE *Node = nullptr;

        //要素を返す
        NODE* GetNode() { return Node; }

        //要素を返す
        bool GetNodeBool() { 
            if (Node != nullptr)
                return true;
            else
                return false;
        }

        //値取得
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

        //ノードの中身を変更
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

        //イテレータのさす要素を取得する(非const)
        NODE* operator*() { return Node; }

        //代入する
        Iterator& operator=(const Iterator& _it) {
            if (this != &_it) {
                Node = _it.Node;
            }
            return *this;
        }

        //代入する
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

    //コンストイテレータクラス
    class ConstIterator:
        public Iterator
    {
    public:
        //オペレータ
        //先頭に向かってイテレータを進める
        Iterator* operator--(int) {
            Iterator* it = new Iterator();
            it->Node = Node->prev;
            return it;
        }
        //末尾に向かってイテレータを進める
        Iterator* operator++(int) {
            Iterator* it = new Iterator();
            it->Node = Node->next;
            return it;
        }
        //イテレータのさす要素を取得する(const)
        const NODE* operator*() const { return Node; }
        // コピーコンストラクタ
       void  CopyConst(NODE* _node) { Node = _node; }
       //代入
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
