#pragma once
#include <string>

/**
 * これはLinkedListクラスの説明です。
 * このクラスは双方向リストで使用されます。
 *
 * @author 吉村括哉
 * @since 2024-10-02
 */
class LinkedList
{
private:
    class Iterator;
    class ConstIterator;

    /**
     *データを入れる構造体です。
     *
     * @param Score スコア
     * @param Name  名前
     */
    struct DATA
    {
        std::string Score;
        std::string Name;
    };

    /**
     *ノードを入れる構造体です。
     *
     * @param prev  前のノード
     * @param next  次のノード
     * @param Data  データ
     */
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
    /**
     * LinkedListクラスのコンストラクタ。
     * 初期化処理を行います。
     */
    LinkedList() {}
    ~LinkedList() {}

    /**
     * データ数を返す関数です。
     * 現在のデータ数を返します
     */
    int GetDataNum() { return DataNum; }

    //先頭に挿入
    void insertFront(Iterator _it) {
        //新しいノード作成
        NODE* NewNode;
        NewNode = new NODE;
        NewNode = (*_it);
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

    /**
    * 受け取ったデータをリストの先頭に格納する関数です。
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    void InsertFront(std::string& _score, std::string& _name)
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
    void InsertLast(Iterator _it) {
        //新しいノードを作成
        NODE* NewNode;
        NewNode = new NODE;
        NewNode = (*_it);
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

    /**
    * 受け取ったデータをリストの末尾に格納する関数です。
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    void InsertLast(std::string& _score, std::string& _name)
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

    /**
    * イテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    void Insert(Iterator _it, std::string _score, std::string _name)
    {
        //イテレータが空じゃないか確認
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
    * イテレータを使用してリストの要素を削除する関数です。
    * @param _it     受け取ったイテレータ
    */
    void Delete(Iterator _it)
    {
        //イテレータが空じゃないか確認
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
            }

        }
    }

    /*
    * 先頭イテレータを取得する関数です。
    * @return 先頭イテレータ
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
    * 先頭コンストイテレータを取得する関数です。
    * @return 先頭コンストイテレータ
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
     * 末尾イテレータを取得する関数です。
     * @return 先頭イテレータ
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
     * 末尾コンストイテレータを取得する関数です。
     * @return 先頭イテレータ
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
     * リストの内容を先頭から順番に出力する関数です。
     */
    void display() const {
        LinkedList::Iterator it;
        it = Head;

        while ((*it) != nullptr) {
            printf("スコア: %s ,名前: %s \n", (*it)->Data.Score.c_str(), (*it)->Data.Name.c_str());
            it++;
            //++it;
        }
    }

#pragma warning(push)
#pragma warning(disable : 4240)

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
            Node = Node->next;
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
            Node = Node->next;
            return it;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
         * @return 前ノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator--() {
            Node = Node->prev;
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
            Node = Node->prev;
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
                Data.Score = "NULL";
                Data.Name = "NULL";
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

        /**
         * 受け取ったイテレータが同一でないかを調べる関数です。
         * @param _it1   比較するイテレータ1
         * @param _it2   比較するイテレータ2
         * @return 比較したイテレータが同一でないかを返します
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
         * 受け取ったイテレータが同一かを調べる関数です。
         * @param _it1   比較するイテレータ1
         * @param _it2   比較するイテレータ2
         * @return 比較したイテレータが同一かを返します
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

    private:

    };
#pragma warning(pop)
};
