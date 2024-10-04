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
        bool IsDammy = false;  //ダミーか
    };

    //ダミーノード
    NODE Dammy;

    //データの数
    int DataNum = 0;

public:
    /**
     * LinkedListクラスのコンストラクタ。
     * 初期化処理を行います。
     */
    LinkedList() {
        Dammy.Next = Dammy.Prev = &Dammy;
        Dammy.IsDammy = true;
    }
    ~LinkedList() {}

    /**
     * データ数を返す関数です。
     * 現在のデータ数を返します
     */
    int GetDataNum() { return DataNum; }

    /**
     * ダミーノードを取得する関数です。
     * ダミーノードを返します
     */
    NODE* GetDammy() { return &Dammy; }

    /**
    * 受け取ったデータをリストの先頭に格納する関数です。
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    void InsertFront(const std::string& _score, const std::string& _name)
    {
        //新しいノード作成
        NODE* NewNode;
        //データ入力
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
        //ノード作成
        NewNode = new NODE();
        NewNode->Data = Data;
        NewNode->Prev = &Dammy;       //新しいノードの前はダミー(先頭)
        NewNode->Next = Dammy.Next;   //新しいノードの次はダミーの次(先頭だったノード)
        Dammy.Next->Prev = NewNode;   //先頭だったノードの前を新しいノード
        Dammy.Next = NewNode;
        DataNum++;
    }

    /**
    * 受け取ったデータをリストの末尾に格納する関数です。
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    void InsertLast(const std::string& _score, const std::string& _name)
    {
        //新しいノード作成
        NODE* NewNode;
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
        //ノード作成
        NewNode = new NODE();
        NewNode->Data = Data;
        NewNode->Prev = Dammy.Prev;   //新しいノードの前はダミー(末尾だったノード)
        NewNode->Next = &Dammy;       //新しいノードの次はダミー
        Dammy.Prev->Next = NewNode;   //末尾だったノードの次を新しいノード
        Dammy.Prev = NewNode;
        DataNum++;
    }

    /**
    * イテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    void Insert(Iterator _it, const std::string& _score, const std::string& _name)
    {
        //イテレータが空じゃないか確認
        if ((*_it) != nullptr)
        {
            //新しいノード作成
            NODE* NewNode = new NODE();
            DATA Data;
            Data.Score = _score;
            Data.Name = _name;
            NewNode->Data = Data;
            NewNode->Next = _it.GetNode();
            NewNode->Prev = _it.GetNode()->Prev;
            _it.GetNode()->Prev = NewNode;
            DataNum++;
        }
    }

    /**
    * イテレータを使用してリストの要素を削除する関数です。
    * @param _it     受け取ったイテレータ
    */
    void Delete(Iterator _it)
    {
        //イテレータが空じゃないか確認
        if (_it.GetNode() != nullptr)
        {
            _it.GetNode()->Next->Prev = _it.GetNode()->Prev;
            _it.GetNode()->Prev->Next = _it.GetNode()->Next;
            delete _it.GetNode();
            DataNum--;
        }
    }

    /*
    * 先頭イテレータを取得する関数です。
    * @return 先頭イテレータ
    */
    LinkedList::Iterator GetBegin() {
        Iterator it;
        it = Dammy.Next;
        return it;
    }

    /*
    * 先頭コンストイテレータを取得する関数です。
    * @return 先頭コンストイテレータ
    */
    LinkedList::ConstIterator GetConstBegin()const {
        LinkedList::ConstIterator it;
        it = Dammy.Next;
        return it;
    }

    /*
    * 末尾イテレータを取得する関数です。
    * @return 先頭イテレータ
    */
    LinkedList::Iterator GetEnd() {
        Iterator it;
        it = Dammy.Prev;
        return it;
    }

    /*
     * 末尾コンストイテレータを取得する関数です。
     * @return 先頭イテレータ
     */
    LinkedList::ConstIterator GetConstEnd() const {
        LinkedList::ConstIterator it;
        it = Dammy.Prev;
        return it;
    }

    

    //コンストイテレータクラス
    class ConstIterator
    {
    protected:
        //ノード
        NODE* Node = nullptr;

    public:
        LinkedList::ConstIterator(){}

        //オペレータ
        /*
         * イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator++() {
            Node = Node->Next;
            LinkedList::Iterator it;
            it.Node = Node;
            return it;
        }

        /*
         * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator++(int) {
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
            Node = Node->Prev;
            LinkedList::Iterator it;
            it.Node = Node;
            return it;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
         * @return 前のノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator--(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Prev;
            return it;
        }

        /*
         * イテレータのさす要素を取得するオペレータ(const)です
         * @return ノードを返します
        */
        const NODE* operator*() const { return Node; }
        /*
         * コピ－コンストラクタです
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}
        //代入
        const LinkedList::ConstIterator operator=(const Iterator* _it) {
            if (this != _it) {
                LinkedList::ConstIterator NewConst;
                NewConst = _it;
                return NewConst;
            }
        }
        //代入
        LinkedList::ConstIterator operator=(NODE* _node) {
                LinkedList::ConstIterator NewConstit;
                NewConstit = _node;
                return NewConstit;
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
    public:

        /**
         * 現在のイテレータの要素を返す関数です。
         * @return イテレータの中身
        */
        NODE* GetNode() { return Node; }

        /**
         * 現在のイテレータのノードのデータを返す関数です。
         * @return イテレータのノードの中身
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
                Data.Score = nullptr;
                Data.Name = nullptr;
                return Data;
            }
        }

        /**
         * イテレータの中身のノードのデータを変更する関数です。
         * @param _score   変更後のスコア
         * @param _name    変更後の名前
        */
        void ChengeData(std::string& _score, std::string& _name)
        {
            Node->Data.Score = _score;
            Node->Data.Name = _name;
        }

        /*
         * イテレータのさす要素を取得する(非const)関数です。
         * @return イテレータの要素を返します
        */
        NODE* operator*() const { return Node; }

        //オペレータ

        //代入
        LinkedList::Iterator& operator=(NODE* _node) {
            this->Node = _node;
            return *this;
        }

        //代入
        LinkedList::Iterator& operator=(NODE _node) {
            this->Node = &_node;
            return *this;
        }

    private:

    };

    private:
        Iterator It;
        ConstIterator Constit;
};
