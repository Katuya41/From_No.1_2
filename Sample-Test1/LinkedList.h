#pragma once
#include <string>
#include "test.h"
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
    bool InsertFront(const int& _score, const std::string& _name)
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
        return true;
    }

    /**
    * 受け取ったデータをリストの末尾に格納する関数です。
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    bool InsertLast(const int& _score, const std::string& _name)
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
        return  true;
    }

    /**
    * イテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    bool Insert(Iterator& _it, const int& _score, const std::string& _name)
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
            _it.Node->Prev = NewNode;
            DataNum++;
            return true;
        }
        return false;
    }

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
            _it.Node->Prev = NewNode;
            DataNum++;
            return true;
        }
        return false;
    }

    /**
    * イテレータを使用してリストの要素を削除する関数です。
    * @param _it     受け取ったイテレータ
    */
    bool Delete(Iterator& _it)
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
        it.Node = Dammy.Next;
        return it;
    }

    /*
    * 先頭コンストイテレータを取得する関数です。
    * @return 先頭コンストイテレータ
    */
    LinkedList::ConstIterator GetConstBegin()const {
        LinkedList::ConstIterator Constit;
        Constit.Node = Dammy.Next;
        return Constit;
    }

    /*
    * 末尾イテレータを取得する関数です。
    * @return 先頭イテレータ
    */
    LinkedList::Iterator GetEnd() {
        Iterator it;
        it.Node = Dammy.Prev;
        return it;
    }

    /*
     * 末尾コンストイテレータを取得する関数です。
     * @return 先頭イテレータ
     */
    LinkedList::ConstIterator GetConstEnd() const {
        LinkedList::ConstIterator Constit;
        Constit.Node = Dammy.Prev;
        return Constit;
    }

    /*
    * これはConstIteratorクラスの説明です。
    * このクラスは双方向リストで使用されます。
    *
    * @author 吉村括哉
    * @since 2024-10-02
    */

public:
    class ConstIterator
    {
    protected:
        //ノード
        NODE* Node = nullptr;

        friend class LinkedList;

    public:
        //コンストラクタ
        LinkedList::ConstIterator() {}

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

        /*
         * ダミーノードか調べます
         * @return ノードがダミーノードかどうかを返します
        */
        bool IsDammy() {
            if (Node->IsDammy)
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
            Node = Node->Next;
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            return Constit;
        }

        /*
         * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator++(int) {
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            Node = Node->Next;
            return Constit;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
         * @return 前ノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator--() {
            Node = Node->Prev;
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            return Constit;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
         * @return 前のノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator--(int) {
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            Node = Node->Prev;
            return Constit;
        }

        /*
         * イテレータのさす要素を取得するオペレータ(const)です
         * @return ノードを返します
        */
        const DATA operator*() const { return Node->Data; }

        /*
         * コピ－コンストラクタです
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}

        ////代入
        //const LinkedList::ConstIterator operator=(const ConstIterator& _it) {
        //        LinkedList::ConstIterator NewConst;
        //        NewConst = _it;
        //        return NewConst;
        //}

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
public:
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
            assert(Node != nullptr && "Iterator points to null!");
            assert(Node->IsDammy != true && "Iterator points to Dammy!");
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
            assert(Node != nullptr && "Iterator points to null!");
            assert(Node->IsDammy != true && "Iterator points to Dammy!");
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
            assert(Node != nullptr && "Iterator points to null!");
            assert(Node->IsDammy != true && "Iterator points to Dammy!");
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
            assert(Node != nullptr && "Iterator points to null!");
            assert(Node->IsDammy != true && "Iterator points to Dammy!");
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
            assert(Node != nullptr && "Iterator points to null!");
            assert(Node->IsDammy !=  true && "Iterator points to Dammy!");
            return Node->Data;
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
