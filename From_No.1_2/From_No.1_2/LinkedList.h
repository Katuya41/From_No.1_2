#pragma once
#include <string>
#include "main.h"


/**
 * これはLinkedListクラスの説明です。
 * このクラスは双方向リストで使用されます。
 *
 * @author 吉村括哉
 * @since 2024-10-02
 */
class LinkedList
{
public:
    class Iterator;
    class ConstIterator;

private:
    /**
     *ノードを入れる構造体です。
     *
     * @param prev  前のノード
     * @param next  次のノード
     * @param Data  データ
     */
    struct NODE
    {
        NODE* Prev = nullptr;     //一個前のノード
        NODE* Next = nullptr;     //次のノード
        DATA Data;             //データ
    };

    //ダミーノード
    NODE* Dummy;

    //データの数
    int DataNum = 0;

    /**
     * ダミーノードを取得する関数です。
     * ダミーノードを返します
     */
    NODE* GetDummy() { return Dummy; }

    /*
        * ダミーノードか調べます
         * @return ノードがダミーノードかどうかを返します
    */
    bool IsDummy(NODE* _node) {
        if (Dummy == _node)
            return true;
        else
            return false;
    }

public:
    /**
     * LinkedListクラスのコンストラクタ。
     * 初期化処理を行います。
     */
    LinkedList() {
        Dummy = new NODE();
        Dummy->Next = Dummy->Prev = Dummy;
    }
    ~LinkedList() {}

    /**
     * データ数を返す関数です。
     * 現在のデータ数を返します
     */
    int GetDataNum() const { return DataNum; }

    /**
    * コンストイテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    bool Insert(ConstIterator& _it, const int& _score, const std::string& _name)
    {
        //イテレータが空じゃないか確認
        if (!_it.IsEmpty())
        {
            //新しいノード作成
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
    * コンストイテレータを使用してリストの要素を削除する関数です。
    * @param _it     受け取ったイテレータ
    */
    bool Delete(ConstIterator& _it)
    {
        //イテレータが空じゃないか確認
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
    * 先頭イテレータを取得する関数です。
    * @return 先頭イテレータ
    */
    LinkedList::Iterator GetBegin() {
        Iterator it;
        it.Node = Dummy->Next;
        return it;
    }

    /*
    * 先頭コンストイテレータを取得する関数です。
    * @return 先頭コンストイテレータ
    */
    LinkedList::ConstIterator GetConstBegin()const {
        LinkedList::ConstIterator Constit;
        Constit.Node = Dummy->Next;
        return Constit;
    }

    /*
    * 末尾イテレータを取得する関数です。
    * @return 末尾イテレータ
    */
    LinkedList::Iterator GetEnd() {
        Iterator it;
        it.Node = Dummy;
        return it;
    }

    /*
     * 末尾コンストイテレータを取得する関数です。
     * @return 先頭イテレータ
     */
    LinkedList::ConstIterator GetConstEnd() const {
        LinkedList::ConstIterator Constit;
        Constit.Node = Dummy;
        return Constit;
    }   

    //コンストイテレータクラス
    class ConstIterator
    {
    private:
        friend class LinkedList;

    protected:
        //ノード
        NODE* Node = nullptr;

    public:
        LinkedList::ConstIterator(){}

        /*
         * ノードが空か調べます
         * @return ノードが空かどうかを返します
        */
        bool IsEmpty() {
            if (Node == nullptr)
                return true;
            else
                return false;
        }

        //オペレータ
        /*
         * イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator++() {
            this->Node = Node->Next;
            return *this;
        }

        /*
         * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator++(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Next;
            return it;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
         * @return 前ノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator--() {
            this->Node = Node->Prev;
            return *this;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
         * @return 前のノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator--(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Prev;
            return it;
        }

        /*
         * イテレータのさす要素を取得するオペレータ(const)です
         * @return ノードを返します
        */
        const DATA operator*() const { return this->Node->Data; }
        /*
         * コピ－コンストラクタです
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}
        //代入
        LinkedList::ConstIterator operator=(const Iterator* _it) {
            if (this != _it) {
                LinkedList::ConstIterator NewConst;
                NewConst = _it;
                return NewConst;
            }
            return *this;
        }

        /*
         * 比較するオペレータです
         * @return 同一かを返します
        */
        bool operator==(const LinkedList::ConstIterator& _constit) const {
            return Node == _constit.Node;
        }

        /*
         * 比較するオペレータです
         * @return 異なるかを返します
        */
        bool operator!=(const LinkedList::ConstIterator& _constit) const {
            return Node != _constit.Node;
        }

    };

    /**
    * これはIteratorクラスの説明です。
    * このクラスは双方向リストで使用されます。
    *
    * @author 吉村括哉
    * @since 2024-10-02
    */
    class Iterator :
        public ConstIterator
    {
    private:
        friend class LinkedList;

    public:
        //コンストラクタ
        LinkedList::Iterator() {}

        //オペレータ
        /*
         * イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator++() {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            this->Node = Node->Next;
            return *this;
        }

        /*
         * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
         * @return 次のノードを取得したイテレータを返します
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
         * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
         * @return 前ノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator--() {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            this->Node = Node->Prev;
            return *this;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
         * @return 前のノードを取得したイテレータを返します
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
         * イテレータのさす要素を取得する(非const)関数です。
         * @return イテレータの要素を返します
        */
        DATA operator*() {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            return this->Node->Data;
        }

        /*
         * 比較するオペレータです
         * @return 同一かを返します
        */
        bool operator==(const LinkedList::Iterator& _it) const {
            return Node == _it.Node;
        }

        /*
         * 比較するオペレータです
         * @return 異なるかを返します
        */
        bool operator!=(const LinkedList::Iterator& _it) const {
            return Node != _it.Node;
        }
    };
};
