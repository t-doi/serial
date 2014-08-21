//091127　シリアル通信テスト doi
//Visual Studioでコンパイルするときは，プロジェクト→プロパティ→全般→文字セット
//の項目を，「マルチバイト文字セットを使用する」
//と設定する．

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include "serial.h"


int main(void)
{
	serial s1;//シリアル通信クラス
	char s_buf[32];//送信バッファ
	char r_buf[32];//受信バッファ

	printf("Serial Commnucation Test for Win32\n");

	//初期化----------------------------------------
	bool res=s1.init("COM1",9600);//初期化
	if(res!=true)
	  {
	    printf("Port Open Error\n");
	    return 1;
	  }

	//送信処理----------------------------------------
	printf("送信テスト\n");
	sprintf(s_buf, "This is test.\n");//送信バッファにデータセット
	s1.send(s_buf,32);//送信

	//受信処理----------------------------------------
	printf("受信テスト\n");
	s1.receive(r_buf,32);//32バイト受信
	printf("[%s]",r_buf);//受信結果表示

	//終了処理----------------------------------------
	printf("終了処理\n");
	s1.close();//ポートクローズ
	
	getchar();//キー入力待ち





	return 0;
}

