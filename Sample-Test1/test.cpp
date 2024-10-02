#include "pch.h"

// GoogleTestのヘッダ。ウィザードにて別のファイルに記述されている場合は、不要です。
#include <gtest/gtest.h>

// 例。自分のプロジェクトにあったヘッダファイルをincludeしてください。
#include "LinkedList.h"

#include "test.h"

//自動テストコード
namespace ex01_DataStructure
{
	namespace chapter2
	{

		//=================================== データ数の取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合のデータ数の取得テスト
			@details	ID:リスト-0\n
						データ数の取得機能のテストです。\n
						リストが空である場合の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {
			LinkedList list;
			EXPECT_EQ(0, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入を行った際のデータ数の取得テスト
			@details	ID:リスト-1\n
						データ数の取得機能のテストです。\n
						リスト末尾への挿入を行った際の戻り値を確認しています。\n
						データ数が1増えていれば成功です。\n
		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPush)
		{
			LinkedList list;
			list.InsertLast(1);
			EXPECT_EQ(1, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入が失敗した際のデータ数の取得テスト
			@details	ID:リスト-2\n
						データ数の取得機能のテストです。\n
						リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
						データ数が増えていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPushFailed)
		{
			// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
// 			LinkedList list;
// 			LinkedList::Iterator it = list.GetEnd();
// 			ASSERT_FALSE(list.Insert(it, 1));
// 			EXPECT_EQ(0, list.GetCount());
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った際の戻り値
			@details	ID:リスト-3\n
						データ数の取得機能のテストです。\n
						データの挿入を行った際の戻り値を確認しています。\n
						データ数が増えていれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumInsertList)
		{
			LinkedList list;
			list.InsertFront(10);
			EXPECT_EQ(1, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った際の戻り値
			@details	ID:リスト-4\n
						データ数の取得機能のテストです。\n
						データの挿入を行った際の戻り値を確認しています。\n
						データ数が増えていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumInsertListFailed)
		{
			//LinkedList list;
			//LinkedList::Iterator* Testit;
			//list.Insert(Testit);
			//EXPECT_EQ(0, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		データの削除を行った際の戻り値
			@details	ID:リスト-5\n
						データ数の取得機能のテストです。\n
						データの削除を行った際の戻り値を確認しています。\n
						データ数が減っていれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDeleteList)
		{
			LinkedList list;
			LinkedList::Iterator* Testit;
			Testit = new LinkedList::Iterator();
			list.InsertFront(1);
			Testit = list.GetBegin();
			list.Delete(Testit);
			EXPECT_EQ(0, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		データの削除を行った際の戻り値
			@details	ID:リスト-6\n
						データ数の取得機能のテストです。\n
						データの削除を行った際の戻り値を確認しています。\n
						データ数が減っていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDeleteListFailed)
		{
			//LinkedList list;
			//LinkedList::Iterator* Testit;
			//Testit = new LinkedList::Iterator();
			//list.Insert(Testit);
			//delete Testit;
			//list.Delete(Testit);
			//EXPECT_EQ(1, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		リストが空の時にデータの削除を行った際の戻り値
			@details	ID:リスト-7\n
						データ数の取得機能のテストです。\n
						データの削除を行った際の戻り値を確認しています。\n
						データ数が減っていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDeleteListWhenEmpty)
		{
			LinkedList list;
			LinkedList::Iterator* Testit;
			Testit = new LinkedList::Iterator();
			list.Delete(Testit);
			EXPECT_EQ(0, list.GetDataNum());
		}

		//=================================== データの挿入 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、データを追加した際の挙動テスト
			@details	ID:リスト-9\n
						リスト末尾のデータ追加テストです。\n
						リストが空である場合に追加した際の挙動を確認しています。\n
						要素が追加されていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToEmpty)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = list.GetBegin();
			EXPECT_EQ(true, list.Insert(it, 10));
		}

		/**********************************************************************************//**
			@brief		リストに複数挿入されている場合に、先頭にデータを追加した際の挙動テスト
			@details	ID:リスト-10\n
						データ挿入追加テストです。\n
						リストに複数挿入されている場合に先頭に追加した際の挙動を確認しています。\n
						要素が追加されていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToListFront)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			it = list.GetBegin();
			EXPECT_EQ(true,list.CheckHead(it));
		}

		/**********************************************************************************//**
			@brief		リストに複数挿入されている場合に、末尾にデータを追加した際の挙動テスト
			@details	ID:リスト-11\n
						データ挿入追加テストです。\n
						リストに複数挿入されている場合に末尾に追加した際の挙動を確認しています。\n
						要素が追加されていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToListWhenEnd)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			list.InsertLast(30);
			it = list.GetEnd();
			EXPECT_EQ(true, list.CheckTail(it));
		}

		/**********************************************************************************//**
			@brief		リストに複数挿入されている場合に、データを追加した際の挙動テスト
			@details	ID:リスト-12\n
						データ挿入追加テストです。\n
						リストに複数挿入されている場合に追加した際の挙動を確認しています。\n
						要素が追加されていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToList)
		{
			LinkedList list;
			list.InsertFront(10);
			list.InsertLast(20);
			list.InsertFront(30);
			EXPECT_EQ(3, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		constiteratorを指定して挿入した際の挙動テスト
			@details	ID:リスト-13\n
						データ挿入追加テストです。\n
						constiteratorを指定して挿入した際の挙動を確認しています。\n
						要素が追加されていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToConstIterator)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = list.GetBegin();
			EXPECT_EQ(true, list.Insert(it,10));
			it = list.GetEnd();
			EXPECT_EQ(true, list.Insert(it, 20));
			EXPECT_EQ(true, list.Insert(it, 30));
		}

		/**********************************************************************************//**
			@brief		不正なイテレータを渡して挿入した際の挙動テスト
			@details	ID:リスト-14\n
						データ挿入追加テストです。\n
						不正なイテレータを渡して挿入した際の挙動を確認しています。\n
						要素が追加されていなければ成功です。\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushTofraudIterator)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = nullptr;
			EXPECT_EQ(false, list.Insert(it, 10));
		}

		/**********************************************************************************//**
			@brief		リストが空の場合に削除した際の挙動テスト
			@details	ID:リスト-16\n
						データ削除テストです。\n
						リストが空の場合に削除した際の挙動を確認しています。\n
						何も起こらなければ成功です。\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteToEmpty)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.Delete(it);
			EXPECT_EQ(false, list.Delete(it));
			//EXPECT_EQ(false, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		リストに複数格納されている状態で先頭イテレータを渡して削除した際の挙動テスト
			@details	ID:リスト-17\n
						データ削除テストです。\n
						リストに複数格納されている状態で先頭イテレータを渡して削除した際の挙動を確認しています。\n
						削除できれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteToListWhenFront)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			it = list.GetBegin();
			EXPECT_EQ(true, list.Delete(it));
		}

		/**********************************************************************************//**
			@brief		リストに複数格納されている状態で末尾イテレータを渡して削除した際の挙動テスト
			@details	ID:リスト-18\n
						データ削除テストです。\n
						リストに複数格納されている状態で末尾イテレータを渡して削除した際の挙動を確認しています。\n
						削除できれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteToListWhenEnd)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			it = list.GetEnd();
			EXPECT_EQ(true, list.Delete(it));
		}

		/**********************************************************************************//**
			@brief		リストに複数格納されている状態で先頭末尾以外のイテレータを渡して削除した際の挙動テスト
			@details	ID:リスト-19\n
						データ削除テストです。\n
						リストに複数格納されている状態で先頭末尾以外イテレータを渡して削除した際の挙動を確認しています。\n
						削除できれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteToList)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			list.InsertFront(30);
			list.InsertLast(40);
			it = list.GetBegin();
			it->AddIterator(it);
			EXPECT_EQ(true, list.Delete(it));
		}

		/**********************************************************************************//**
			@brief		constiteratorを指定して削除した際の挙動テスト
			@details	ID:リスト-20\n
						データ削除テストです。\n
						constiteratorを指定して削除した際の挙動を確認しています。\n
						削除できれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteToConstIterator)
		{
			LinkedList list;
			list.InsertFront(10);
			list.InsertLast(20);
			const LinkedList::Iterator* constit = new LinkedList::Iterator();
			const LinkedList::ConstIterator* constit2 = new LinkedList::ConstIterator();
			constit2 = list.GetConstBegin();
			EXPECT_EQ(true, list.Delete(constit2));
		}

		/**********************************************************************************//**
			@brief		不正なイテレータを指定して削除した際の挙動テスト
			@details	ID:リスト-21\n
						データ削除テストです。\n
						不正なイテレータを指定して削除した際の挙動を確認しています。\n
						削除できれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteTofraudIterator)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			EXPECT_EQ(false, list.Delete(it));
		}

		/**********************************************************************************//**
			@brief		リストが空の場合に呼び出した際の挙動テスト
			@details	ID:リスト-23\n
						先頭イテレータテストです。\n
						リストが空の場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(FrontIteratorTest, TestIteratorCheckToEmpty)
		{
			LinkedList list;
			EXPECT_EQ(true, list.GetBeginBool());
		}

		/**********************************************************************************//**
			@brief		リストに1つ挿入されている場合に呼び出した際の挙動テスト
			@details	ID:リスト-24\n
						先頭イテレータテストです。\n
						リストに1つ挿入されている場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(FrontIteratorTest, TestIteratorCheckToListWhen1Data)
		{
			LinkedList list;
			list.InsertFront(10);
			EXPECT_EQ(true, list.GetBeginBool());
		}

		/**********************************************************************************//**
			@brief		リストに2つ挿入されている場合に呼び出した際の挙動テスト
			@details	ID:リスト-25\n
						先頭イテレータテストです。\n
						リストに2つ挿入されている場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(FrontIteratorTest, TestIteratorCheckToListWhen2Date)
		{
			LinkedList list;
			list.InsertFront(10);
			list.InsertLast(20);
			EXPECT_EQ(true, list.GetBeginBool());
		}

		/**********************************************************************************//**
			@brief		リストに挿入した後に呼び出した際の挙動テスト
			@details	ID:リスト-26\n
						先頭イテレータテストです。\n
						リストに挿入した後に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(FrontIteratorTest, TestIteratorCheckToListWhenInsertBack)
		{
			LinkedList list;
			list.InsertFront(10);
			list.InsertLast(20);
			EXPECT_EQ(true, list.GetBeginBool());
		}

		/**********************************************************************************//**
			@brief		リストを削除した後に呼び出した際の挙動テスト
			@details	ID:リスト-27\n
						先頭イテレータテストです。\n
						リストを削除した後に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(FrontIteratorTest, TestIteratorCheckToListWhenDeleteBack)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			it = list.GetBegin();
			list.Delete(it);
			EXPECT_EQ(true, list.GetBeginBool());
		}

		/**********************************************************************************//**
			@brief		リストが空の場合に呼び出した際の挙動テスト
			@details	ID:リスト-29\n
						先頭コンストイテレータテストです。\n
						リストが空の場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(FrontConstIteratorTest, TestConstIteratorCheckToEmpty)
		{
			LinkedList list;
			EXPECT_EQ(true, list.GetConstBeginBool());
		}

		/**********************************************************************************//**
			@brief		リストに1つ挿入されている場合に呼び出した際の挙動テスト
			@details	ID:リスト-30\n
						先頭コンストイテレータテストです。\n
						リストに1つ挿入されている場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(FrontConstIteratorTest, TestConstIteratorCheckToListWhen1Data)
		{
			LinkedList list;
			list.InsertFront(10);
			EXPECT_EQ(true, list.GetConstBeginBool());
		}

		/**********************************************************************************//**
			@brief		リストに2つ挿入されている場合に呼び出した際の挙動テスト
			@details	ID:リスト-31\n
						先頭コンストイテレータテストです。\n
						リストに2つ挿入されている場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(FrontConstIteratorTest, TestConstIteratorCheckToListWhen2Data)
		{
			LinkedList list;
			list.InsertFront(10);
			list.InsertLast(20);
			EXPECT_EQ(true, list.GetConstBeginBool());
		}

		/**********************************************************************************//**
			@brief		リストに挿入した後に呼び出した際の挙動テスト
			@details	ID:リスト-32\n
						先頭コンストイテレータテストです。\n
						リストに挿入した後に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(FrontConstIteratorTest, TestConstIteratorCheckToListWhenIsertBack)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			EXPECT_EQ(true, list.GetConstBeginBool());
		}

		/**********************************************************************************//**
			@brief		リストを削除した後に呼び出した際の挙動テスト
			@details	ID:リスト-33\n
						先頭コンストイテレータテストです。\n
						リストを削除した後に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(FrontConstIteratorTest, TestConstIteratorCheckToListWhenDeleteBack)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			it = list.GetBegin();
			list.Delete(it);
			EXPECT_EQ(true, list.GetConstBeginBool());
		}

		/**********************************************************************************//**
			@brief		リストが空の場合に呼び出した際の挙動テスト
			@details	ID:リスト-35\n
						末尾イテレータテストです。\n
						リストが空の場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestEndIteratorCheckToEmpty)
		{
			LinkedList list;
			EXPECT_EQ(true, list.GetEndBool());
		}

		/**********************************************************************************//**
			@brief		リストに1つ挿入されている場合に呼び出した際の挙動テスト
			@details	ID:リスト-36\n
						末尾イテレータテストです。\n
						リストに1つ挿入されている場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestEndIteratorCheckToListWhen1Data)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			EXPECT_EQ(true, list.GetEndBool());
		}

		/**********************************************************************************//**
			@brief		リストに2つ挿入されている場合に呼び出した際の挙動テスト
			@details	ID:リスト-37\n
						末尾イテレータテストです。\n
						リストに2つ挿入されている場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestEndIteratorCheckToListWhen2Data)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			EXPECT_EQ(true, list.GetEndBool());
		}

		/**********************************************************************************//**
			@brief		リストに挿入した後に呼び出した際の挙動テスト
			@details	ID:リスト-38\n
						末尾イテレータテストです。\n
						リストに挿入した後に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestEndIteratorCheckToListWhenInsertBack)
		{
			LinkedList list;
			list.InsertFront(10);
			list.InsertLast(20);
			EXPECT_EQ(true, list.GetEndBool());
		}

		/**********************************************************************************//**
			@brief		リストを削除した後に呼び出した際の挙動テスト
			@details	ID:リスト-39\n
						末尾イテレータテストです。\n
						リストを削除した後に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestEndIteratorCheckToListWhenDeleteBack)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			it = list.GetBegin();
			list.Delete(it);
			EXPECT_EQ(true, list.GetEndBool());
		}

		/**********************************************************************************//**
			@brief		リストが空の場合に呼び出した際の挙動テスト
			@details	ID:リスト-41\n
						末尾コンストイテレータテストです。\n
						リストが空の場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestEndConstIteratorCheckToEmpty)
		{
			LinkedList list;
			EXPECT_EQ(true, list.GetConstEndBool());
		}

		/**********************************************************************************//**
			@brief		リストに1つ挿入されている場合に呼び出した際の挙動テスト
			@details	ID:リスト-42\n
						末尾コンストイテレータテストです。\n
						リストに1つ挿入されている場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestEndConstIteratorCheckToListWhen1Data)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			list.InsertFront(10);
			EXPECT_EQ(true, list.GetConstEndBool());
		}

		/**********************************************************************************//**
			@brief		リストに2つ挿入されている場合に呼び出した際の挙動テスト
			@details	ID:リスト-43\n
						末尾コンストイテレータテストです。\n
						リストに2つ挿入されている場合に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestEndConstIteratorCheckToListWhen2Data)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			LinkedList::Iterator* it2 = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			EXPECT_EQ(true, list.GetConstEndBool());
		}

		/**********************************************************************************//**
			@brief		リストに挿入した後に呼び出した際の挙動テスト
			@details	ID:リスト-44\n
						末尾コンストイテレータテストです。\n
						リストに挿入した後に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestEndConstIteratorCheckToListWhenInsertBack)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			LinkedList::Iterator* it2 = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			EXPECT_EQ(true, list.GetConstEndBool());
		}

		/**********************************************************************************//**
			@brief		リストを削除した後に呼び出した際の挙動テスト
			@details	ID:リスト-45\n
						末尾コンストイテレータテストです。\n
						リストを削除した後に呼び出した際の挙動を確認しています。\n
						ダミーノードを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestEndConstIteratorCheckToListWhenDeleteBack)
		{
			LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			LinkedList::Iterator* it2 = new LinkedList::Iterator();
			list.InsertFront(10);
			list.InsertLast(20);
			it = list.GetBegin();
			list.Delete(it);
			EXPECT_EQ(true, list.GetConstEndBool());
		}

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動テスト
			@details	ID:Iterator-0\n
						イテレータのさす要素を取得するテストです。\n
						リストの参照がない状態で呼び出した際の挙動を確認しています。\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorDataTest, TestCheckIteratorDataWhenEmpty)
		{
			LinkedList::Iterator* it = new LinkedList::Iterator();
			ASSERT_TRUE(true, it->GetNodeBool());
		}

		/**********************************************************************************//**
			@brief		イテレータから取得した値を代入できるかの挙動テスト
			@details	ID:Iterator-1\n
						イテレータのさす要素を取得するテストです。\n
						イテレータから取得した値を代入できるかの挙動を確認しています。\n
						値が変更されていれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDataTest, TestCheckIteratorDataWhenDifferentData)
		{
			LinkedList List;
			List.InsertFront(1);
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = List.GetBegin();
			it->ChengeData(10);
			EXPECT_EQ(10, it->GetNodeData());
		}

		/**********************************************************************************//**
			@brief		リストが空の際の先頭イテレータを呼び出した際の挙動テスト
			@details	ID:Iterator-3\n
						イテレータのさす要素を取得するテストです。\n
						リストが空の際の先頭イテレータを呼び出した際の挙動を確認しています。\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorDataTest, TestCheckIteratorDataWhenEmptyToFrontIterator)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = List.GetBegin();
			ASSERT_TRUE(true,it->GetNode());
		}

		/**********************************************************************************//**
			@brief		末尾イテレータを呼び出した際の挙動テスト
			@details	ID:Iterator-4\n
						イテレータのさす要素を取得するテストです。\n
						リストが空の際の先頭イテレータを呼び出した際の挙動を確認しています。\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorDataTest, TestCheckIteratorDataWhenEmptyToEndIterator)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = List.GetEnd();
			ASSERT_TRUE(true, it->GetNode());
		}

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動テスト
			@details	ID:Iterator-5\n
						イテレータをリストの末尾に向かって進めるテストです。\n
						リストの参照がない状態で呼び出した際の挙動を確認しています。\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenNotList)
		{
			LinkedList::Iterator* it = new LinkedList::Iterator();
			ASSERT_TRUE(true, it->AddIterator());
		}

		/**********************************************************************************//**
			@brief		リストが空の状態で先頭イテレータに対した際の挙動テスト
			@details	ID:Iterator-6\n
						イテレータをリストの末尾に向かって進めるテストです。\n
						リストが型の状態で先頭イテレータに対した際の挙動を確認しています。\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenEmptyToFront)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = List.GetBegin();
			ASSERT_TRUE(true, it->AddIterator());
		}

		/**********************************************************************************//**
			@brief		リストが型の状態で末尾イテレータに対した際の挙動テスト
			@details	ID:Iterator-7\n
						イテレータをリストの末尾に向かって進めるテストです。\n
						リストが型の状態で末尾イテレータに対した際の挙動を確認しています。\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenEmptyToEnd)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = List.GetEnd();
			ASSERT_TRUE(true, it->AddIterator());
		}

		/**********************************************************************************//**
			@brief		リストに二つの要素がある状態で対した際の挙動テスト
			@details	ID:Iterator-8\n
						イテレータをリストの末尾に向かって進めるテストです。\n
						リストが型の状態で末尾イテレータに対した際の挙動を確認しています。\n
						指定された数字が格納されていれば\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenListTo2Data)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			List.InsertFront(10);
			List.InsertLast(20);
			it = List.GetBegin();
			it->AddIterator(it);
			EXPECT_EQ(20, it->GetNodeData());
		}

		/**********************************************************************************//**
			@brief		前置インクリメントを行った際の挙動テスト
			@details	ID:Iterator-9\n
						イテレータをリストの末尾に向かって進めるテストです。\n
						前置インクリメントを行った際の挙動を確認しています。\n
						指定された数字が格納されていれば\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenListFront)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			List.InsertFront(10);
			List.InsertLast(20);
			it = List.GetBegin();
			it->AddIterator(it);
			EXPECT_EQ(20, it->GetNodeData());
		}

		/**********************************************************************************//**
			@brief		後置インクリメントを行った際の挙動テスト
			@details	ID:Iterator-10\n
						イテレータをリストの末尾に向かって進めるテストです。\n
						後置インクリメントを行った際の挙動を確認しています。\n
						指定された数字が格納されていれば\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenListEnd)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			List.InsertFront(10);
			List.InsertLast(20);
			it = List.GetEnd();
			it->SumIterator(it);
			EXPECT_EQ(10, it->GetNodeData());
		}

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動テスト
			@details	ID:Iterator-11\n
						イテレータをリストの先頭に向かって進めるテストです。\n
						リストの参照がない状態で呼び出した際の挙動を確認しています。\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenNotList)
		{
			LinkedList::Iterator* it = new LinkedList::Iterator();
			ASSERT_TRUE(true, it->SumIterator(it));
		}

		/**********************************************************************************//**
			@brief		リストが空の状態で末尾イテレータに対した際の挙動テスト
			@details	ID:Iterator-12\n
						イテレータをリストの先頭に向かって進めるテストです。\n
						リストが型の状態で先頭イテレータに対した際の挙動を確認しています。\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenEmptyFront)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = List.GetBegin();
			ASSERT_TRUE(true, it->AddIterator(it));
		}

		/**********************************************************************************//**
			@brief		リストが空の状態で先頭イテレータに対した際の挙動テスト
			@details	ID:Iterator-13\n
						イテレータをリストの先頭に向かって進めるテストです。\n
						リストが型の状態で末尾イテレータに対した際の挙動を確認しています。\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenListToFront)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = List.GetEnd();
			ASSERT_TRUE(true, it->SumIterator(it));
		}

		/**********************************************************************************//**
			@brief		リストに二つの要素がある状態で対した際の挙動テスト
			@details	ID:Iterator-14\n
						イテレータをリストの先頭に向かって進めるテストです。\n
						リストが型の状態で末尾イテレータに対した際の挙動を確認しています。\n
						指定された数字が格納されていれば\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenListTo2Data)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			List.InsertFront(10);
			List.InsertLast(20);
			it = List.GetEnd();
			it->SumIterator(it);
			EXPECT_EQ(10, it->GetNodeData());
		}

		/**********************************************************************************//**
			@brief		前置インクリメントを行った際の挙動テスト
			@details	ID:Iterator-15\n
						イテレータをリストの先頭向かって進めるテストです。\n
						前置インクリメントを行った際の挙動を確認しています。\n
						指定された数字が格納されていれば\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenListFront)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			List.InsertFront(10);
			List.InsertLast(20);
			it = List.GetBegin();
			it->AddIterator(it);
			EXPECT_EQ(20, it->GetNodeData());
		}

		/**********************************************************************************//**
			@brief		後置インクリメントを行った際の挙動テスト
			@details	ID:Iterator-16\n
						イテレータをリストの先頭に向かって進めるテストです。\n
						後置インクリメントを行った際の挙動を確認しています。\n
						指定された数字が格納されていれば\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenListEnd)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			List.InsertFront(10);
			List.InsertLast(20);
			it = List.GetEnd();
			it->SumIterator(it);
			EXPECT_EQ(10, it->GetNodeData());
		}

		/**********************************************************************************//**
			@brief		コピーコンストラクタを行った際の挙動テスト
			@details	ID:Iterator-18\n
						イテレータのコピーを行うテストです。\n
						コピーコンストラクタを行った際の挙動を確認しています。\n
						コピー元の値と等しければ成功です。\n
		*//***********************************************************************************/
		TEST(CopyTest, TestCopy)
		{
			LinkedList List;
			List.InsertFront(10);
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = List.GetBegin();
			LinkedList::ConstIterator* constit = new LinkedList::ConstIterator();
			constit->CopyConst(it->GetNode());
			int num = constit->GetNodeData();
			EXPECT_EQ(10, num);
		}

		/**********************************************************************************//**
			@brief		代入を行った際の挙動テスト
			@details	ID:Iterator-20\n
						イテレータの代入を行うテストです。\n
						代入を行った際の挙動を確認しています。\n
						代入元の値と等しければ成功です。\n
		*//***********************************************************************************/
		TEST(AssignmentTest, TestAssignment)
		{
			LinkedList List;
			List.InsertFront(10);
			List.InsertLast(20);
			LinkedList::Iterator* it = new LinkedList::Iterator();
			LinkedList::ConstIterator* constit = new LinkedList::ConstIterator();
			it = List.GetBegin();
			constit = List.GetConstEnd();
			it = constit;
			int num = it->GetNodeData();
			EXPECT_EQ(20, num);
		}

		/**********************************************************************************//**
			@brief		リストが空の状態での末尾と先頭を比較した際の挙動テスト
			@details	ID:Iterator-21\n
						二つのイテレータが等しいかどうかを確認するテストです。\n
						リストが空の状態での末尾と先頭を比較した際の挙動を確認しています。\n
						Trueなら成功です。\n
		*//***********************************************************************************/
		TEST(CorrectTest, TestCorrectWhenEmpty)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			LinkedList::Iterator* it2 = new LinkedList::Iterator();
			it = List.GetBegin();
			it2 = List.GetEnd();
			EXPECT_EQ(true, it->TrueCheckIterator(it, it2));
		}

		/**********************************************************************************//**
			@brief		同一のイテレータを比較した際の挙動テスト
			@details	ID:Iterator-22\n
						二つのイテレータが等しいかどうかを確認するテストです。\n
						同一のイテレータを比較した際の挙動を確認しています。\n
						Trueなら成功です。\n
		*//***********************************************************************************/
		TEST(CorrectTest, TestCorrectWhenCorrectData)
		{
			LinkedList List;
			List.InsertFront(10);
			LinkedList::Iterator* it = new LinkedList::Iterator();
			LinkedList::Iterator* it2 = new LinkedList::Iterator();
			it = List.GetBegin();
			it2 = List.GetBegin();
			EXPECT_EQ(true, it->TrueCheckIterator(it, it2));
		}

		/**********************************************************************************//**
			@brief		異なるイテレータを比較した際の挙動テスト
			@details	ID:Iterator-23\n
						二つのイテレータが等しいかどうかを確認するテストです。\n
						異なるイテレータを比較した際の挙動を確認しています。\n
						Falseなら成功です。\n
		*//***********************************************************************************/
		TEST(CorrectTest, TestCorrectWhenDiffarentData)
		{
			LinkedList List;
			List.InsertFront(10);
			List.InsertLast(20);
			LinkedList::Iterator* it = new LinkedList::Iterator();
			LinkedList::Iterator* it2 = new LinkedList::Iterator();
			it = List.GetBegin();
			it2 = List.GetEnd();
			EXPECT_EQ(false, it->TrueCheckIterator(it, it2));
		}

		/**********************************************************************************//**
			@brief		リストが空の状態での末尾と先頭を比較した際の挙動テスト
			@details	ID:Iterator-24\n
						二つのイテレータが異なっているかどうかを確認するテストです。\n
						リストが空の状態での末尾と先頭を比較した際の挙動を確認しています。\n
						Falseなら成功です。\n
		*//***********************************************************************************/
		TEST(DiffarentTest, TestDiffarentWhenEmpty)
		{
			LinkedList List;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			LinkedList::Iterator* it2 = new LinkedList::Iterator();
			it = List.GetBegin();
			it2 = List.GetEnd();
			bool Res = true;
			if (it != it2)
				Res = false;
			EXPECT_EQ(false, it->FalseCheckIterator(it, it2));
		}

		/**********************************************************************************//**
			@brief		同一のイテレータを比較した際の挙動テスト
			@details	ID:Iterator-25\n
						二つのイテレータが異なっているかを確認するテストです。\n
						同一のイテレータを比較した際の挙動を確認しています。\n
						Falseなら成功です。\n
		*//***********************************************************************************/
		TEST(DiffarentTest, TestDiffarentWhenCorrectData)
		{
			LinkedList List;
			List.InsertFront(10);
			LinkedList::Iterator* it = new LinkedList::Iterator();
			LinkedList::Iterator* it2 = new LinkedList::Iterator();
			it = List.GetBegin();
			it2 = List.GetBegin();
			EXPECT_EQ(false, it->FalseCheckIterator(it, it2));
		}

		/**********************************************************************************//**
			@brief		異なるイテレータを比較した際の挙動テスト
			@details	ID:Iterator-26\n
						二つのイテレータが異なっているかを確認するテストです。\n
						異なるイテレータを比較した際の挙動を確認しています。\n
						Trueなら成功です。\n
		*//***********************************************************************************/
		TEST(DiffarentTest, TestDiffarentWhenDiffarentData)
		{
			LinkedList List;
			List.InsertFront(10);
			List.InsertLast(20);
			LinkedList::Iterator* it = new LinkedList::Iterator();
			LinkedList::Iterator* it2 = new LinkedList::Iterator();
			it = List.GetBegin();
			it2 = List.GetEnd();
			EXPECT_EQ(true, it->FalseCheckIterator(it, it2));
		}

	}

}