#include <iostream>
#include <windows.h>
#include<conio.h>
#include<time.h>

int Map_X_MAX = 200;
int Map_Y_MAX = 75;
int key; int gamestatus = 0; int mapdata[1500];
int beginpattern;

void SetConsole();
void gotoxy(int x, int y);
void textcolor(int color_number);
void gamestart();
void fillMap(char str[], char str_s, int max_value);
void editMap(int x, int y, char str);
void drawSprite(int x, int y, int size_x, int size_y, char spr[]);
void sans();
void type_effect(const char *str, int delay_ms);
void begin();
void pattern_begin();

int main(void) 
{	
	int x = Map_X_MAX / 2;
	int y = 50;
	SetConsole();	
	gamestart();
	
	while (gamestatus) {
        gotoxy(x, y); // 화면 초기화 지점
        system("cls");
        gotoxy(x, y);
        printf("*");
        if (GetAsyncKeyState(VK_UP) & 0x8000) 
		{
			if (y > 0)
			y--;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) 
		{
			if (y < Map_Y_MAX - 1)
		        y++;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
		{
		    if (x > 0)
				x -= 1;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
		{
			if (x < Map_X_MAX - 2)
				x += 1;
		}

        Sleep(20);
		}
	return 0;
}

void SetConsole() {
	system("under"); // 콘솔창 이름 설정
	system("mode con:cols=200 lines=75"); // 콘솔창 크기설정

	CONSOLE_CURSOR_INFO ConsoleCursor; //Windows 콘솔 응용 프로그램에서 콘솔 커서의 모양과 동작을 제어하는데 사용되는 구조이다
	ConsoleCursor.bVisible = 0;//가시성 
	ConsoleCursor.dwSize = 1;//커서 사이즈 크기 
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);//모르겠다. 
}

void textcolor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}//캐릭터 색깔 

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(consoleHandle, Cur);//좌표평면 구현 
}

void fillMap(char str[], char str_s, int max_value) {
    for (int i = 0; i < max_value; i++) {
        str[i] = str_s;
    }
}
 
void editMap(int x, int y, char str) {
    if (x > 0 && y > 0 && x - 1 < Map_X_MAX - 1 && y - 1 < Map_Y_MAX - 1)
        str = mapdata[(y - 1) * Map_X_MAX + x - 1];
}
 
void drawSprite(int x, int y, int size_x, int size_y, char spr[]) {
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x; j++) {
            editMap(x + j, y + i, spr[i * size_x + j]);
        }
    }
}

void gamestart() 
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("			  	  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("			  	  @;,   @@@     @~    :@@     *#;.        @@@;.        @;           ;=@;.           @;-          @!~   *@@@@@@;.        *@\n");
	printf("				  @-    @@@     @-    -=@     *#-         ;$#-         @;           -!@-            @-.          @-.   !@@@@@@-         *@\n");
	printf("				  @     @@@     @-    ,;@     *$           !#          @;            ;@             @            @     !@@@@@@          *@\n");
	printf("				  @     @@@     @-      @     *$   ,;      !#          @;            ;@             @            @     !@@@@@@          *@\n");
	printf("				  @     @@@     @-      @     *$   ~@@     !#     @@@@@@;            ;@             @            @     !@@@@@@     @@@@@@@\n");
	printf("				  @     @@@     @-  -   ~     *$   ~@@     !#     ~~~~*@;            ;@***!     ****@    ~;**    @     !@@@@@@     ~~~~*#@\n");
	printf("				  @     @@#     @-  !.        *$   ~@#     !#     ,,,,!@;            ;@@@@#     @@@@@    :*$$    @     !@@@@@@     ,,,,!#@\n");
	printf("				  @     @=;     @-  @.        *$   ~@;     !#     @@@@@@;            ;@@@@#     @@@@@            @     !@@@@@@     @@@@@@@\n");
	printf("				  @             @-  @@!       *$   ~@      !#          @;        ,;@@@@@@@#     @@@@@    @@#;    @          -@          *@\n");
	printf("				  @             @-  @@#$      *$    ,      !#          @;   --    .,,!@@@@#     @@@@@    @@@#    @          -@          *@\n");
	printf("				  @             @-  @@@@,     *$          ~=#          @;   :!~~     ;@@@@#     @@@@@    @@@@    @          -@          *@\n");
	printf("				  @             @-  @@@@;     *$          @@#          @;   *@@@,    ;@@@@#     @@@@@    @@@@    @          -@          *@\n");
	printf("				  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                                         	  	       		   1.시작\n\n\n");
	printf("                                                         	  	       		   2.시작(인트로 스킵)\n\n\n");
	printf("                                                         	 	       	 	   3.종료\n");
    if (getch() == '1') 
	{
		system("cls");
		beginpattern = 0;
        begin();
    }
    else if (getch() == '2') 
	{
        system("cls");
        beginpattern = 0;
        pattern_begin();
    }
    else if (getch() == '3') 
	{
        textcolor(11);
        exit(0);
    }
}
    
void sans_normal()
{
	printf("\n");
	printf("        			  	  			  	              ######*            \n");
    printf("        			  	  			  	          .-;;      .;:~,        \n");
    printf("        			  	  			  	         ,!,                     \n");
    printf("        			  	  			  	        ,!,              ,.      \n");
    printf("        			  	  			  	        ~,               ;~      \n");
    printf("        			  	  			  	            ...     ...  -;.     \n");
    printf("        			  	  			  	          ~!!!!;   .:.-!- *~     \n");
    printf("        			  	  			  	          =@@@@@   .-,;:;-*~     \n");
    printf("        			  	  			  	          =@@@@@   .;.,-$:*~     \n");
    printf("        			  	  			  	        :-,$@@@- * ,#==;-;:.     \n");
    printf("        			  	  			  	        .!,,,,, $@* ,,,. ..      \n");
    printf("        			  	  			  	        ;: *.   @@$   ~: :-      \n");
    printf("        			  	  			  	        !~*@,$  ..   ~@@:;~      \n");
    printf("        			  	  			  	        !~ =, @@@@@@@*:! ;~      \n");
    printf("        			  	  			  	       !@@-  $.@ #  -@!  !@@-    \n");
    printf("        			  	  			  	      :;   .  $# $  -! .;~.!#,   \n");
    printf("        			  	  			  	      :#~  !. ,,,,,,. ~$~ !:=,   \n");
    printf("        			  	  			  	    .-,,,--   *=@@@=!   .~-,,-   \n");
    printf("        			  	  			  	    -!,,,,!--~~ **!.~~, ::~-,*-  \n");
    printf("        			  	  			  	   .::,,,,,,#$@    ,@#;,,,=:,,!  \n");
    printf("        			  	  			  	   ,;,,,,,,,#!@    -@=,,,:$:,,:. \n");
    printf("        			  	  			  	  .:,,,,:~;*@!@    -@=,,:!#:,,,, \n");
    printf("        			  	  			  	  -=,,,,*$!;;!=    ,$=:=!~=:,,,,!\n");
    printf("        			  	  			  	  -$,,,;!:-,,$!    .*=~;~,~-,,,,@\n");
    printf("        			  	  			  	   -,,,*;,,,,*!    .*=-,,,,,,,,,@\n");
    printf("        			  	  			  	    -;,*;,,,,$!    .;!!,,,,,,,,$,\n");
    printf("        			  	  			  	     :!*;,,,,#!    .;~-,,,!:,,~. \n");
    printf("        			  	  			  	     :**@:,,,#@@@@@@$-,,,;#:=@,  \n");
    printf("        			  	  			  	        !@@@@@@@@@@@@@@@@@@~     \n");
    printf("        			  	  			  	        !@@@@@@@@@@@@@@@@@@~     \n");
    printf("        			  	  			  	       .!@#@@@@@@@@@@@#@@@@-     \n");
    printf("        			  	  			  	       !@@#@@@@@@#@@@@#@@@#-     \n");
    printf("        			  	  			  	       !@@#@@@@@$@@@@@#@@@#;     \n");
    printf("        			  	  			  	      ,*@@#@@@@@$@@@@@$#@@@@-    \n");
    printf("        			  	  			  	      ;#@#@@@@@@#!#@@@##@@@@-    \n");
    printf("        			  	  			  	      ;#@#@@@@@@@.#@@@@#@@@@-    \n");
    printf("        			  	  			  	      ;##$@@@@@@@.#@@@@#@@#@-    \n");
    printf("        			  	  			  	      ,~--$@@@@@~ :@@@@@@!-~.    \n");
    printf("        			  	  			  	      ~**-=@@:~~   ~~!@@@: ;*.   \n");
    printf("        			  	  			  	     ~;,-.=:-      ,!.--*; ,- -  \n");
    printf("        			  	  			  	     ..   .:;      -#;;;~.    ;  \n");
    printf("        			  	  			  	           =,$      .  ::     ~  \n");

}

void type_effect(const char *str, int delay_ms) {
	printf("			  	  "); 
    while (*str) {
        putchar(*str);
        fflush(stdout);
        Sleep(delay_ms);   // 밀리초 단위 지연
        str++;
    }
}
    
void begin()
{
	Sleep(1000);
	printf("    			  	                                 ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#;\n");
	printf("    			  	                                 .@*@@@@@@@@@@@@@@@@@@@@@@@@@#;\n");
	printf("    			  	                                 .@=@@@@@@@@@@@@@@@@@@@@@@@@@#;.\n");
	printf("    			  	                                 .@=@@@@@@@@@@@@@@@@@@@@@@@@@#;.\n");
	printf("    			  	                                 .@@@@@@@@@@@@@@@@@@@@@@@@@@@#;.\n");
	printf("    			  	                                 .@@@@@@@@@@@@@@@@@@@@@@@@@@@#;.\n");
	printf("    			  	                                 .@#@@@@@@@@@@@@@@@@@@@@@@@@@#!.\n");
	printf("    			  	  *******************************~@*@@@@@@@@@@@@@@@@@@@@@@@@@#!***************************************\n");
	printf("    			  	                                 ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#!,,,,,.\n");
	printf("    			  	  !!;;;;;;!;;;;;!!!!!!!;;;;;;;;;;~@~$@@@@@@@@@@@@@@@@@@@@@@@@@!;;;!!!;;;;;;;;;;;;;;;;;;;;;;!;;;;;;;;;;\n");
	printf("    			  	                                 ,@~$@@@@@@@@@@@@@@@@@@@@@@@@@!\n");     
	printf("    			  	                                 ,@~$@@@@@@@@@@@@@@@@@@@@@@@@@;.\n");  
	printf("    			  	                                 ,@:$@@@@@@@@@@@@@@@@@@@@@@@@@;~-\n");
	printf("    			  	                                 .@*@@@@@@@@@@@@@@@@@@@@@@@@@#; ;\n");
	printf("    			  	                                 ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#; .-\n");
	printf("    			  	                                 ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#; .- \n");
	printf("    			  	                                 ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#;  ::\n");
	printf("    			  	                                 ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#;   !\n");
	printf("    			  	                ....             ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#; ..,$.                ....\n");
	printf("    			  	               #@@@@@=           ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#!.    ;              #@@@@@@:\n");
	printf("    			  	              @@@@@@@@$          ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#!$####;             ;@@@@@@@@ \n");
	printf("    			  	             !@@@@@@@@$          ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                   @@@@@@@@@!\n");
	printf("    			  	             $@@@@@@@@-          ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                   @@@@@@@@@!\n");
	printf("    			  	             $@@@@@@@@-          ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                   *@@@@@@@@  \n");
	printf("    			  	             $@@@@@@@@$          ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                   @@@@@@@@# \n");
	printf("    			  	             .@@@@@@@@$          ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                   !@@@@@@@:   \n");
	printf("    			  	               ;;@@@@$           .@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                   ;@@@@@@@@;\n");
	printf("    			  	                 *@!             .@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                    $@@@@@@@. \n");
	printf("    			  	                !@@@~            .@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                    #@@@@@@@~ \n");
	printf("    			  	                $@@@$            ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                    #@@@@@@@!  \n");
	printf("    			  	                $@@@@.           ,@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                    =@@@@@@$ \n");
	printf("    			  	                $@@@@            .@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                    ~@@@@@@~ \n");
	printf("     			  	                $@@@@            .@*@@@@@@@@@@@@@@@@@@@@@@@@@#;                    ~@@@@@@~\n");
	printf("       			  	                ~@@@,            .@:#@@@@@@@@@@@@@@@@@@@@@@@;#;                     =@@@@~ \n");          
	printf("        			  	         =@*             ,@~$@@@@@@@@@@@@@@@@@@@@@@@-#;....                ,#@@@;\n");
	printf("        			  	         -:~             .@~$@@@@@@@@@@@@@@@@@@@@@@@-#!....                .$@@:-\n");
	printf("        			  	                         .@~$@@@@@@@@@@@@@@@@@@@@@@@-#!....\n");
	printf("       			  	                                 .@~$@@@@@@@@@@@@@@@@@@@@@@@-#;....\n");
	printf("       			  	                                 .@~$@@@@@@@@@@@@@@@@@@@@@@@-#;....\n");
	printf("       			  	                                 .@~$@@@@@@@@@@@@@@@@@@@@@@@-#;....\n");      
	printf("       			  	                                 .@~$@@@@@@@@@@@@@@@@@@@@@@@-#;....\n");
	printf("       			  	                                 ,$;#@@@@@@@@@@@@@@@@@@@@@@@-#~.... \n");
	printf("       			  	                                 ,*!@@@@@@@@@@@@@@@@@@@@@@@@-$-....\n");
	printf("       			  	                                 ,--$@@@@@@@@@@@@@@@@@@@@@@*--- \n");
	printf("      			  	                                  ,--:@@@@@@@@@@@@@@@@@@@@$=----.\n");                                                                                                                                                                                                                                                                          
    Sleep(2000);    
	//                           
	printf("\n\n\n\n");
	type_effect("안녕.\n", 250);
	type_effect("꽤 바빴었지, 응?\n", 120);
	type_effect("...\n", 500); 
	type_effect("그래, 물어볼 게 하나 있어.\n", 120);
	type_effect("가장 나쁜 사람이라 할지라도 바뀔 수 있을까...?\n", 120);
	type_effect("노력만 한다면, 모두가 착한 사람이 될 수 있을까?\n", 120);
	type_effect("헤 헤 헤 헤...\n", 200);
	type_effect("좋아.\n", 300);
	type_effect("그럼, 여기 더 괜찮은 질문이 있어.\n\n", 120);
	type_effect("끔 찍 한 시 간 을 보 내 고 싶 어 ?\n\n", 140);
	type_effect("네가 한발짝이라도 더 다가온다면...\n", 120);
	type_effect("그 뒤에 벌어질 일이 정말 달갑지 않을걸.\n", 120);
	type_effect("음...\n", 500);
	type_effect("죄송해요, 아주머니.\n", 120);
	type_effect("이게 바로 제가 약속을 안 하는 이유에요.\n", 120);
	//
	pattern_begin();
}

void pattern_begin()
{
	system("cls");
	Sleep(2000);
	sans_normal();
	if(beginpattern == 0)
	{
		printf("\n\n\n");
		type_effect("정말 아름다운 날이야.\n", 120);
		type_effect("새들은 지저귀고, 꽃들은 피어나고...\n", 120);
		type_effect("이런 날엔, 너 같은 꼬마들은...\n", 120);
		type_effect("지옥에서 불타 버려야 해.", 250);
		gamestatus = 1;
	}
	else if(beginpattern == 1)
	{
		printf("\n\n\n");
		type_effect("정말 아름다운 날이야.\n", 120);
		type_effect("새들은 지저귀고,\n", 120);
		gamestatus = 1;
	}
	else
	{
		printf("\n\n\n");
		type_effect("준비됐어?\n", 120);
		gamestatus = 1;
	}
}
