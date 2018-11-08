#include <stdio.h>
#include <conio.h>
#include <windows.h>
void ppak();
void print(char);
void fun();
void result();
void gamecomp();
void gameover();

COORD coord;
int coin = 30, cnt = 0, cost = 0,miss = 0;
int rt[3] = { 0 };

void Coord(int x, int y)
{
	coord.X = x;coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(void)
{
	int i = 0;


	while ((coin >= 3) && (coin < 15000)) {
		coin -= 3;	cost += 3;
		Coord(0, 2);
		Coord(0, 0);printf("coin : %06d   JackPot : %06d   miss : %02d", coin,cost+10000,miss);
		fun();
		result();
	}

	if (coin > 100)gamecomp();
//	ppak();
	gameover();
	ppak();
}
void gameover()
{
	int i = 0, k;Sleep(1000);

	char end[13][60] = {
		"◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆",
		"◆◇◇◇◇◇◇◆◇◆◆◆◆◆◆◆◇◆◇◇◇◇◆◆◆",
		"◆◇◆◆◆◆◆◆◇◇◆◆◆◆◆◆◇◆◇◆◆◆◇◆◆",
		"◆◇◆◆◆◆◆◆◇◆◇◆◆◆◆◆◇◆◇◆◆◆◆◇◆",
		"◆◇◆◆◆◆◆◆◇◆◆◇◆◆◆◆◇◆◇◆◆◆◆◇◆",
		"◆◇◇◇◇◇◆◆◇◆◆◆◇◆◆◆◇◆◇◆◆◆◆◇◆",
		"◆◇◆◆◆◆◆◆◇◆◆◆◆◇◆◆◇◆◇◆◆◆◆◇◆",
		"◆◇◆◆◆◆◆◆◇◆◆◆◆◆◇◆◇◆◇◆◆◆◆◇◆",
		"◆◇◆◆◆◆◆◆◇◆◆◆◆◆◆◇◇◆◇◆◆◆◇◆◆",
		"◆◇◇◇◇◇◇◆◇◆◆◆◆◆◆◆◇◆◇◇◇◇◆◆◆",
		"◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆"
	};

	Coord(0,0);

	for (i = 0;i < 13;i++)
	{
		for (k = 0;k < 77;k++)putchar(32);
	}

	Coord(11, 1);

	for (i = 0;i < sizeof(end) / sizeof(end[0]); i++)	printf("%s\n           ", end[i]);

	Coord(0,0);

}

void gamecomp()
{
	int i = 0, j = 0, k;Sleep(1000);
/*		char end[8][50] = {
		"          ∧＿∧                                \n",
		"　／＼（　・∀・）／ヽ       　   ∧＿∧        \n",
		"（ ●　と　　　つ　● ）　／＼（　・∀・）／ヽ  \n",
		"　＼/⊂、　 　ノ　＼ノ  （ ●　と　　　つ　● ）\n",
		"　　　　　し’          　＼/⊂、　 　ノ　＼ノ  \n",
		"                        　　　　　し’          "
	};
*/

	char end[6][100] = {
		"          ∧＿∧                                          ∧＿∧        ",
		"　／＼（　・∀・）／ヽ       　   ∧＿∧        　／＼（　・∀・）／ヽ  ",
		"（ ●　と　　　つ　● ）　／＼（　・∀・）／ヽ  （ ●　と　　　つ　● ）",
		"　＼/⊂、　 　ノ　＼ノ  （ ●　と　　　つ　● ）　＼/⊂、　 　ノ　＼ノ  ",
		"　　　　　し’          　＼/⊂、　 　ノ　＼ノ  　　　　　し’          ",
		"                        　　　　　し’                                  "
	};

	for (i = 0;i < 20;i++)
	{
		Coord(0, i);for (k = 0;k < 77;k++)putchar(32);
	}

	for (i = 0;i <  sizeof(end) / sizeof(end[0]);i++)
	{
		Coord(5, i+13);			printf("%s\n", end[i]);
	}
	
	Sleep(1000);


/*
	for (i = 0;i < 20;i++)
	{
		Coord(0, i + 5);for (k = 0;k < 77;k++)putchar(32);
	}

	for (i = 0;i<6;i++) {
		Coord(i, 7);	printf("%s\n", end[i]);
	}
*/	
	putchar("\n");
	Sleep(1000);
}

void result() {


	int win[5] = { 5,15,25,15,25 };

	Coord(0, 20);

	miss++;

	//チェリー
	if (rt[0] == -1) {
		coin += 1;
		if (rt[1] == -1) {
			coin += 2;
			if (rt[2] == -1) {
				coin += 12; 	printf("小当たり：チェリー     ");miss=0;
				}
		}
	}

	//その他 全部同じ もしくは １０回以上外れかつ左２つ同じ 

	else if	(((rt[0] == rt[1]) && ((rt[0] == rt[2])||(miss > 10)))||(miss > 30)) { 
		if (rt[0] > 5) { coin += 10000 + cost;cost = 0; printf("!!JACK POT!!"); miss =0;}
		else 
		{
			coin += win[rt[0]]; 
			switch (rt[0])
			{
				case 0:printf("中当たり：Bar      ");miss = 0; break;
				case 1:printf("中当たり：BarBar   ");miss = 0; break;
				case 2:printf("中当たり：BarBarBar"); miss = 0;break;
				case 3:printf("中当たり：ベル       ");miss = 0;break;
				case 4:printf("中当たり：スイカ        ");miss = 0; break;
			}
		}
	}



}

void fun(void)
{

	/*初期化*/
//	char list[15][5]={0};
	char  i, j;
	unsigned char k = 1;
	cnt = 0;
/*
	for(i = 0;i < 26 && k < 128;i++){
		for(j = 0;j < 5 ;j++){list[j][i] = k;k+=2;}
	}	
	k = 0;
*/
	/*初期化確認*/
/*	for(i = 0;i < 5;i++){
	for(j = 0;j < 15;j++){
	if(k % 2 == 0) printf("cherry ");
	else print(j);k++;
	if(k == 127){printf("JP");goto end;}
	else{
	if(k % 2 == 0) printf("cherry ");
	else print(j);k++;
	}putchar('\n');
	}putchar('\n');
	}
*/

start:

	/*目押し*/
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};

	while (_kbhit() == 0) {
		k++;

		Coord(cnt * 26, 2);
	/*2つは例外*/
	
	 if (k == 0) {	
	printf("777^^^^^^^^^^^^^^^77\n");Coord(cnt * 26, 3);
	printf("77^^^^^^^^^^^^^^^777\n");Coord(cnt * 26, 4);
	printf("7777777777^^^^^^7777\n");Coord(cnt * 26, 5);
	printf("7777777^^^^^^7777777\n");Coord(cnt * 26, 6);
	printf("777^^^^^^77777777777\n");Coord(cnt * 26, 7);
	printf("7^^^^^^^777777777777\n");Coord(cnt * 26, 8); 			
		rt[cnt] = 10;//goto end; 
	}
/*	else if (k < 0) {
	printf("　　　　　　　　　　\n");Coord(cnt * 26, 3);
	printf("  　　　／＼　　　　\n");Coord(cnt * 26, 4);
	printf(" 　 　／　　＼  　　\n");Coord(cnt * 26, 5);
	printf("  　／　　　　＼　　\n");Coord(cnt * 26, 6);
	printf("  ／　  　　  　＼　\n");Coord(cnt * 26, 7);
	printf(" ●　 　   　　　● \n");Coord(cnt * 26, 8);
		rt[cnt] = -1;//goto end; 
	}
*/
	/*判定*/
	else  print( k % 5);/*goto end;*/ 		

	}

end:
	if (cnt == 2) ppak();
		else {
			cnt++; Sleep(miss); goto start;
		}
}
void ppak()
{
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};



	while (1) {
		if (_kbhit()) { _getch(); break; }
	};
}
void print(char i)
{
	//中でやる
	//	if(j % 2 == 0)printf("cherry"); 
	rt[cnt] = i;


	if (i == 0)	{	
	printf(" _________________  \n");Coord(cnt * 26, 3);
	printf(" |■■■■■■■■| \n");Coord(cnt * 26, 4);
	printf(" |■■■■■■■■| \n");Coord(cnt * 26, 5);
	printf(" |■B■■A ■■R■| \n");Coord(cnt * 26, 6);
	printf(" |■■■■■■■■| \n");Coord(cnt * 26, 7);
	printf("￣￣￣￣￣￣￣￣￣￣\n");Coord(cnt * 26, 8); 
	}

	else if (i == 1){
	printf("    ____________    \n");Coord(cnt * 26, 3);
	printf("  _|■■■■■■|_  \n");Coord(cnt * 26, 4);
	printf(" |■■■■■■■■| \n");Coord(cnt * 26, 5);
	printf(" |■B■■A ■■R■| \n");Coord(cnt * 26, 6);
	printf(" |■■■■■■■■| \n");Coord(cnt * 26, 7);
	printf("￣￣￣￣￣￣￣￣￣￣\n");Coord(cnt * 26, 8); 		
	}

	else if (i == 2){
	printf("       _____        \n");Coord(cnt * 26, 3);
	printf("     __|■■|_      \n");Coord(cnt * 26, 4);
	printf(" ____|■■■■|___  \n");Coord(cnt * 26, 5);
	printf(" |■■■■■■■■| \n");Coord(cnt * 26, 6);
	printf(" |■B■■A ■■R■| \n");Coord(cnt * 26, 7);
	printf("￣￣￣￣￣￣￣￣￣￣\n");Coord(cnt * 26, 8); 	
	}
		
	else if (i == 3){
	printf("         ◎         \n");Coord(cnt * 26, 3);
	printf("        ◎◎        \n");Coord(cnt * 26, 4);
	printf("      ◎◎◎◎      \n");Coord(cnt * 26, 5);
	printf("  ◎B◎E◎◎L◎L◎  \n");Coord(cnt * 26, 6);
	printf("   ◎◎◎◎◎◎◎   \n");Coord(cnt * 26, 7);
	printf("         ◎         \n");Coord(cnt * 26, 8); 	
	}
		
	else if (i == 4){
	printf("▲△△△△△△△△▲\n");Coord(cnt * 26, 3);
	printf("▲▲△●△△●△▲▲\n");Coord(cnt * 26, 4);
	printf("▲▲△△西瓜△△▲▲\n");Coord(cnt * 26, 5);
	printf(" ▲▲△●△●△▲▲ \n");Coord(cnt * 26, 6);
	printf("　 ▲▲▲▲▲▲▲   \n");Coord(cnt * 26, 7);
	printf("　　  ▲▲▲▲　    \n");Coord(cnt * 26, 8); 	
	}
		
	else printf("error2 ");
}

/*現在の状況及びこれからの予定

//終了済み
00:初期化完了
01:初期化完了確認
02:kを目押し
03:目押しで判定と出力
04:コインの作成と消費
05:コイン獲得
06:終了処理
07:画面処理(AA)
08:天井を作る
10:目押しに対応

//予定
09:確率変動
11:チェリーを偶数に

*/

/* 	愚痴

なんだよ・・・。リストとか要らなかったじゃねぇか・・・！！！
アスキーアートが・・・！でかくなってしまった!!
*/
