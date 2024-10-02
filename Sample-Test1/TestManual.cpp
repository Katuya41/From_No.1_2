#include "pch.h"

//--------------------------------------------------------------------------------
// ファイル依存関係
//--------------------------------------------------------------------------------
// GoogleTestのヘッダ。ウィザードにて別のファイルに記述されている場合は、不要です。
#include <gtest/gtest.h>

// 例。自分のプロジェクトにあったヘッダファイルをincludeしてください。
#include "LinkedList.h"

#include "TestManual.h"

namespace ex01_DataStructure
{
	namespace chapter2
	{
		//--------------------------------------------------------------------------------
		// コンパイル関連手動テスト
		//--------------------------------------------------------------------------------
		/**********************************************************************************//**
			@brief		データ数の取得機能について、constのメソッドであるかのテスト
			@details	ID:リスト-8(手動)\n
						データ数の取得機能のテストです。\n
						constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通れば成功です。\n
						TT_TEST_GET_DATA_NUM_IS_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenConst)
		{
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
			const LinkedList list;
			EXPECT_EQ(0, list.GetDataNum());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		データ数の取得機能について、constのメソッドであるかのテスト
			@details	ID:リスト-34(手動)\n
						データ数の取得機能のテストです。\n
						constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通れば成功です。\n
						TT_TEST_GET_DATA_NUM_IS_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetFrontConstIterateWhenConst)
		{
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
			const LinkedList list;
			EXPECT_EQ(true, list.GetConstBeginBool());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
			SUCCEED();
		}



		/**********************************************************************************//**
			@brief		リスト先頭データ追加について、非constが保障されているかのテスト
			@details	ID:リスト-15(手動)\n
						リスト先頭データ追加テストです。\n
						非constが保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestInsertWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const LinkedList list;
			LinkedList::ConstIterator* it = new LinkedList::ConstIterator();
			it = list.GetConstBegin();
			list.Insert(it, 1);//ここでエラー
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		リスト先頭のデータ削除について、非constが保障されているかのテスト
			@details	ID:リスト-22(手動)\n
						リスト先頭データ追加テストです。\n
						非constが保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestDeleteWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const LinkedList list;
			LinkedList::ConstIterator* it = new LinkedList::ConstIterator();
			it = list.GetConstBegin();
			list.Delete(it);//ここでエラー
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		constのリストから、ConstIteratorでないIteratorの取得が行えないかのテスト
			@details	ID:リスト-40(手動)\n
						リスト先頭データ追加テストです。\n
						非constが保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestGetWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = list.GetBegin();//エラー
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		ConstIteratorから、Iteratorのコピーが作成されないかのテスト
			@details	ID:Iterator-17(手動)\n
						ConstIteratorから、Iteratorのコピーが作成されないかのテストです。\n
						非constが保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestCopyWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const LinkedList list;
			LinkedList::ConstIterator* Constit = new LinkedList::ConstIterator();
			LinkedList::Iterator* it = new LinkedList::Iterator();
			Constit->CopyConst(it);	//エラー
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		IteratorにConstIteratorを代入できないかのテスト
			@details	ID:Iterator-19(手動)\n
						IteratorにConstIteratorを代入できないかのテストです。\n
						非constが保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestSetWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const LinkedList list;
			const LinkedList::ConstIterator* Constit = new LinkedList::ConstIterator();
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = Constit;	//エラー
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}


	}	// chapter2
}	//	ex01_DataStructure
