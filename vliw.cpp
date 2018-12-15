#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;
void hex_translation(); 
void decode();
void op_decode();
void addition();
void subtraction();
void multiplication();
void division();
void nor();
void nand();
void move();
void shift_left();
void shift_right();
void xnor();
void not_gate();
void load();
void and_gate();
void or_gate();
void compare();
void read_this();
void s_decoder();
void d_decoder();
int s11;
int s12;
int s22;
int s21;
int s31;
int s32;
int d1;
int d2;
int d3;
int opn;
int register_arr[32];
char hex_val[16];
char bin_val[64];
char op1[20];
char op2[20];
char op3[20];
char rrr[4];


int main(){
int u;
hex_val[0] = 'F'; // sets the 16 hexidecimal values
hex_val[1] = 'C';
hex_val[2] = 'C';
hex_val[3] = 'B';
hex_val[4] = '1';
hex_val[5] = '9';
hex_val[6] = 'C';
hex_val[7] = '1'; 
hex_val[8] = 'D';
hex_val[9] = 'C';
hex_val[10] = '3';
hex_val[11] = '8';
hex_val[12] = '2';
hex_val[13] = '8';
hex_val[14] = '7';
hex_val[15] = '4';
register_arr[0] = 12; // Preloaded registers that can be changed
register_arr[1] = 5;
register_arr[2] = 3;
register_arr[3] = 1;
register_arr[4] = 14;
register_arr[5] = 28;
register_arr[6] = 31;
register_arr[7] = 18;
register_arr[8] = 8;
register_arr[9] = 6;
register_arr[10] = 12;
register_arr[11] = 3;
register_arr[12] = 31;
register_arr[13] = 17;
register_arr[14] = 23;
register_arr[15] = 23;
register_arr[16] = 1;
register_arr[17] = 18;
register_arr[18] = 2;
register_arr[19] = 4;
register_arr[20] = 29;
register_arr[21] = 27;
register_arr[22] = 10;
register_arr[23] = 11;
register_arr[24] = 25;
register_arr[25] = 20;
register_arr[26] = 8;
register_arr[27] = 19;
register_arr[28] = 1;
register_arr[29] = 31;
register_arr[30] = 19;
register_arr[31] = 6;
hex_translation(); // translates to binary
decode(); // separates into three operations
s_decoder(); // chooses the correct registers
d_decoder(); // stores the result into register
cout << "source address 1 op1 " << s11 << endl;
cout << "source address 2 op1 " << s21 << endl;
cout << "source address 1 op2 " << s31 << endl;
cout << "source address 2 op2 " << s12 << endl;
cout << "source address 1 op3 " << s22 << endl;
cout << "source address 2 op3 " << s32 << endl;
cout << "Result 1: " << d1 << endl;
cout << "Result 2: " << d2 << endl;
cout << "Result 3:" << d3 << endl;
cout << "Value stored in register : " << register_arr[24] << endl;
cout << "Value stored in register : " << register_arr[24] << endl;
cout << "Value stored in register: " << register_arr[3] << endl; 
return 0;
}


/***********************************************************************************************************************************************
Translates hexidecimal to binary 16 total and stores binary into new array. Translations are below:
0 = 0000
1 = 0001
2 = 0010
3 = 0011
4 = 0100
5 = 0101
6 = 0110
7 = 0111
8 = 1000
9 = 1001
A = 1010
B = 1011
C = 1100
D = 1101
E = 1110
F = 1111

***********************************************************************************************************************************************/

void hex_translation(){
	int i = 0;
	char temp_hex;
	char bin_1;
	char bin_2;
	char bin_3;
	char bin_4;
	for(i = 0; i < 16; i++){
			temp_hex = hex_val[i];
			switch(temp_hex) {
				case '0' : // translates 0 into 0000
					bin_1 = '0';
					bin_2 = '0';
					bin_3 = '0';
					bin_4 = '0';
				break;
				case '1' : // translates 1 into 0001
					bin_1 = '0';
					bin_2 = '0';
					bin_3 = '0';
					bin_4 = '1';
				break;
				case '2' : // translates 2 into 0010
					bin_1 = '0';
					bin_2 = '0';
					bin_3 = '1';
					bin_4 = '0';
				break;
				case '3' : // translates 3 into 0011
					bin_1 = '0';
					bin_2 = '0';
					bin_3 = '1';
					bin_4 = '1';
				break;
				case '4' : // translates 4
					bin_1 = '0';
					bin_2 = '1';
					bin_3 = '0';
					bin_4 = '0';
				break;
				case '5' : // translate 5
					bin_1 = '0';
					bin_2 = '1';
					bin_3 = '0';
					bin_4 = '1';
				break;
				case '6' : 
					bin_1 = '0';
					bin_2 = '1';
					bin_3 = '1';
					bin_4 = '0';
				break;
				case '7' :
					bin_1 = '0';
					bin_2 = '1';
					bin_3 = '1';
					bin_4 = '1';
				break;
				case '8' :
					bin_1 = '1';
					bin_2 = '0';
					bin_3 = '0';
					bin_4 = '0';
				break;
				case '9' :
					bin_1 = '1';
					bin_2 = '0';
					bin_3 = '0';
					bin_4 = '1';
				break;
				case 'A' :
					bin_1 = '1';
					bin_2 = '0';
					bin_3 = '1';
					bin_4 = '0';
				break;
				case 'B' :
					bin_1 = '1';
					bin_2 = '0';
					bin_3 = '1';
					bin_4 = '1';
				break;
				case 'C' :
					bin_1 = '1';
					bin_2 = '1';
					bin_3 = '0';
					bin_4 = '0';
				break;
				case 'D' :
					bin_1 = '1';
					bin_2 = '1';
					bin_3 = '0';
					bin_4 = '1';
				break;
				case 'E' :
					bin_1 = '1';
					bin_2 = '1';
					bin_3 = '1';
					bin_4 = '0';
				break;
				case 'F' :
					bin_1 = '1';
					bin_2 = '1';
					bin_3 = '1';
					bin_4 = '1';
				break;	

}
			switch(i) { // tells where to store the binary calculated from translation
				case 0 :
					bin_val[0] = bin_1;
					bin_val[1] = bin_2;
					bin_val[2] = bin_3;
					bin_val[3] = bin_4;
				break;
				case 1 :
					bin_val[4] = bin_1;
					bin_val[5] = bin_2;
					bin_val[6] = bin_3;
					bin_val[7] = bin_4;
				break;
				case 2 :
					bin_val[8] = bin_1;
					bin_val[9] = bin_2;
					bin_val[10] = bin_3;
					bin_val[11] = bin_4;
				break;
				case 3 :
					bin_val[12] = bin_1;
					bin_val[13] = bin_2;
					bin_val[14] = bin_3;
					bin_val[15] = bin_4;
				break;
				case 4 :
					bin_val[16] = bin_1;
					bin_val[17] = bin_2;
					bin_val[18] = bin_3;
					bin_val[19] = bin_4;
				break;
				case 5 :
					bin_val[20] = bin_1;
					bin_val[21] = bin_2;
					bin_val[22] = bin_3;
					bin_val[23] = bin_4;
				break;
				case 6 :
					bin_val[24] = bin_1;
					bin_val[25] = bin_2;
					bin_val[26] = bin_3;
					bin_val[27] = bin_4;
				break;
				case 7 :
					bin_val[28] = bin_1;
					bin_val[29] = bin_2;
					bin_val[30] = bin_3;
					bin_val[31] = bin_4;
				break;
				case 8 :
					bin_val[32] = bin_1;
					bin_val[33] = bin_2;
					bin_val[34] = bin_3;
					bin_val[35] = bin_4;
				break;
				case 9 :
					bin_val[36] = bin_1;
					bin_val[37] = bin_2;
					bin_val[38] = bin_3;
					bin_val[39] = bin_4;
				break;
				case 10 :
					bin_val[40] = bin_1;
					bin_val[41] = bin_2;
					bin_val[42] = bin_3;
					bin_val[43] = bin_4;
				break;
				case 11 :
					bin_val[44] = bin_1;
					bin_val[45] = bin_2;
					bin_val[46] = bin_3;
					bin_val[47] = bin_4;
				break;
				case 12 :
					bin_val[48] = bin_1;
					bin_val[49] = bin_2;
					bin_val[50] = bin_3;
					bin_val[51] = bin_4;
				break;
				case 13 :
					bin_val[52] = bin_1;
					bin_val[53] = bin_2;
					bin_val[54] = bin_3;
					bin_val[55] = bin_4;
				break;
				case 14 :
					bin_val[56] = bin_1;
					bin_val[57] = bin_2;
					bin_val[58] = bin_3;
					bin_val[59] = bin_4;
				break;
				case 15 :
					bin_val[60] = bin_1;
					bin_val[61] = bin_2;
					bin_val[62] = bin_3;
					bin_val[63] = bin_4;
				break;
			}
//cout << bin_1 << bin_2 << bin_3 << bin_4 << endl;
		}
	}
/***********************************************************************************************************************************************
Takes bin_val register that stores all 64 binary bits and separates it into individual operations. Below is the arrangement of what bits belong to each operation
0 - 20 bits = operation 1
21 - 39 bits = operation 2
40 - 59 bits = operation 3
60 -63 bits = rrr

***********************************************************************************************************************************************/

void decode () {
	int y = 0;
	int p = 0;
	int l = 0;
	int q = 0;
	int pp = 0;
	int ll = 0;
	int qq = 0;

	for(y = 0; y < 20; y++){ //gives 20 binary to operation 1
		op1[y] = bin_val[y];
	}
	for( p = 0; p < 20; p++){ // gives 20 binary to operation 2
		pp = 20 + p;
		op2[p] = bin_val[pp];
	}

	for(l = 0; l < 20; l++){ // gives 29 binary to operation 3
		ll  = 40 + l;
		op3[l] = bin_val[ll];
	}

	for(q = 0; q < 5; q++){ // gives 4 binary to rrr
		qq = 60 + q;
		rrr[q] = bin_val[qq];
	}
	op_decode();


}
/***********************************************************************************************************************************************
Takes the first four bits of operation 1, 2, and 3. The fifth bit was not uilized here because specifically only 16 functions were utilized. Utilized functions are shown below and their equivalent decimal value:
0 = compare
1 = reading
2 = addition
3 = subtraction
4 = division
5 = multiplication
6 = nor gate
7 = nand gate
8 = xnor gate 
9 = move
10 = load
11 = shift left
12 = shift right
13 = or gate 
14 = and gate
15 = not gate

***********************************************************************************************************************************************/

void op_decode(){ // chooses the correct opcode
	if((op1[0] == '0')&&(op1[1] == '0')&&(op1[2] == '0')&&(op1[3] == '0')){
        opn =1;
		compare(); // two source
	}
     else if((op1[0] == '0')&&(op1[1] == '0')&&(op1[2] == '0')&&(op1[3] == '1')){
        opn =1;
		read_this(); //one source
	}
     else if((op1[0] == '0')&&(op1[1] == '0')&&(op1[2] == '1')&&(op1[3] == '0')){
        opn =1;
		addition(); // two source
	}
     else if((op1[0] == '0')&&(op1[1] == '0')&&(op1[2] == '1')&&(op1[3] == '1')){
        opn =1;
		subtraction(); // two source
	}
     else if((op1[0] == '0')&&(op1[1] == '1')&&(op1[2] == '0')&&(op1[3] == '0')){
        opn =1;
		division(); // two source
	}
     else if((op1[0] == '0')&&(op1[1] == '1')&&(op1[2] == '0')&&(op1[3] == '1')){
        opn =1;
		multiplication(); // two source
	}
     else if((op1[0] == '0')&&(op1[1] == '1')&&(op1[2] == '1')&&(op1[3] == '0')){
        opn =1;
		nor(); // two source
	}
     else if((op1[0] == '0')&&(op1[1] == '1')&&(op1[2] == '1')&&(op1[3] == '1')){
        opn =1;
		nand(); // two source
	}
     else if((op1[0] == '1')&&(op1[1] == '0')&&(op1[2] == '0')&&(op1[3] == '0')){
        opn =1;
		xnor(); // two source
	}
     else if((op1[0] == '1')&&(op1[1] == '0')&&(op1[2] == '0')&&(op1[3] == '1')){
        opn =1;
		move(); // two source
	}
     else if((op1[0] == '1')&&(op1[1] == '0')&&(op1[2] == '1')&&(op1[3] == '0')){
        opn =1;
		load(); // one source
	}
     else if((op1[0] == '1')&&(op1[1] == '0')&&(op1[2] == '1')&&(op1[3] == '1')){
        opn =1;
		shift_left(); // one source
	}
     else if((op1[0] == '1')&&(op1[1] == '1')&&(op1[2] == '0')&&(op1[3] == '0')){
        opn =1;
		shift_right(); // one source
	}
     else if((op1[0] == '1')&&(op1[1] == '1')&&(op1[2] == '0')&&(op1[3] == '1')){
        opn =1;
		or_gate(); // one source
	}
     else if((op1[0] == '1')&&(op1[1] == '1')&&(op1[2] == '1')&&(op1[3] == '0')){
        opn =1;
		and_gate();  // one source
	}
     else if((op1[0] == '1')&&(op1[1] == '1')&&(op1[2] == '1')&&(op1[3] == '1')){
        opn =1;
		not_gate(); // one source
	}


	if((op2[0] == '0')&&(op2[1] == '0')&&(op2[2] == '0')&&(op2[3] == '0')){
        opn =2;
		compare();
	}
     else if((op2[0] == '0')&&(op2[1] == '0')&&(op2[2] == '0')&&(op2[3] == '1')){
        opn =2;
		read_this();
	}
     else if((op2[0] == '0')&&(op2[1] == '0')&&(op2[2] == '1')&&(op2[3] == '0')){
        opn =2;
		addition();
	}
     else if((op2[0] == '0')&&(op2[1] == '0')&&(op2[2] == '1')&&(op2[3] == '1')){
        opn =2;
		subtraction();
	}
     else if((op2[0] == '0')&&(op2[1] == '1')&&(op2[2] == '0')&&(op2[3] == '0')){
        opn =2;
		division();
	}
     else if((op2[0] == '0')&&(op2[1] == '1')&&(op2[2] == '0')&&(op2[3] == '1')){
        opn =2;
		multiplication();
	}
     else if((op2[0] == '0')&&(op2[1] == '1')&&(op2[2] == '1')&&(op2[3] == '0')){
        opn =2;
		nor();
	}
     else if((op2[0] == '0')&&(op2[1] == '1')&&(op2[2] == '1')&&(op2[3] == '1')){
        opn =2;
		nand();
	}	
     else if((op2[0] == '1')&&(op2[1] == '0')&&(op2[2] == '0')&&(op2[3] == '0')){
        opn =2;
		xnor();
	}
     else if((op2[0] == '1')&&(op2[1] == '0')&&(op2[2] == '0')&&(op2[3] == '1')){
        opn =2;
		move();
	}
     else if((op2[0] == '1')&&(op2[1] == '0')&&(op2[2] == '1')&&(op2[3] == '0')){
        opn =2;
		load();
	}
     else if((op2[0] == '1')&&(op2[1] == '0')&&(op2[2] == '1')&&(op2[3] == '1')){
        opn =2;
		shift_left();
	}
     else if((op2[0] == '1')&&(op2[1] == '1')&&(op2[2] == '0')&&(op2[3] == '0')){
        opn =2;
		shift_right();
	}
     else if((op2[0] == '1')&&(op2[1] == '1')&&(op2[2] == '0')&&(op2[3] == '1')){
        opn =2;
		or_gate();
	}
     else if((op2[0] == '1')&&(op2[1] == '1')&&(op2[2] == '1')&&(op2[3] == '0')){
        opn =2;
		and_gate();
	}
     else if((op2[0] == '1')&&(op2[1] == '1')&&(op2[2] == '1')&&(op2[3] == '1')){
        opn =2;
		not_gate();
	}


	if((op3[0] == '0')&&(op3[1] == '0')&&(op3[2] == '0')&&(op3[3] == '0')){
        opn =3;
		compare();
	}
     else if((op3[0] == '0')&&(op3[1] == '0')&&(op3[2] == '0')&&(op3[3] == '1')){
        opn =3;
		read_this();
	}
     else if((op3[0] == '0')&&(op3[1] == '0')&&(op3[2] == '1')&&(op3[3] == '0')){
        opn =3;
		addition();
	}
     else if((op3[0] == '0')&&(op3[1] == '0')&&(op3[2] == '1')&&(op3[3] == '1')){
        opn =3;
	subtraction();
	}
     else if((op3[0] == '0')&&(op3[1] == '1')&&(op3[2] == '0')&&(op3[3] == '0')){
        opn =3;
		division();
	}
     else if((op3[0] == '0')&&(op3[1] == '1')&&(op3[2] == '0')&&(op3[3] == '1')){
        opn =3;
		multiplication();
	}
     else if((op3[0] == '0')&&(op3[1] == '1')&&(op3[2] == '1')&&(op3[3] == '0')){
        opn =3;
		nor();
	}
     else if((op3[0] == '0')&&(op3[1] == '1')&&(op3[2] == '1')&&(op3[3] == '1')){
        opn =3;
		nand();
	}
     else if((op3[0] == '1')&&(op3[1] == '0')&&(op3[2] == '0')&&(op3[3] == '0')){
        opn =3;
		xnor();
	}
     else if((op3[0] == '1')&&(op3[1] == '0')&&(op3[2] == '0')&&(op3[3] == '1')){
        opn =3;
		move();
	}
     else if((op3[0] == '1')&&(op3[1] == '0')&&(op3[2] == '1')&&(op3[3] == '0')){
        opn =3;
		load();
	}
     else if((op3[0] == '1')&&(op3[1] == '0')&&(op3[2] == '1')&&(op3[3] == '1')){
        opn =3;
		shift_left();
	}
     else if((op3[0] == '1')&&(op3[1] == '1')&&(op3[2] == '0')&&(op3[3] == '0')){
        opn =3;
		shift_right();
	}
     else if((op3[0] == '1')&&(op3[1] == '1')&&(op3[2] == '0')&&(op3[3] == '1')){
        opn =3;
		or_gate();
	}
     else if((op3[0] == '1')&&(op3[1] == '1')&&(op3[2] == '1')&&(op3[3] == '0')){
        opn =3;
		and_gate();
	}
     else if((op3[0] == '1')&&(op3[1] == '1')&&(op3[2] == '1')&&(op3[3] == '1')){
        opn =3;
		not_gate();
	}

}
/***********************************************************************************************************************************************
Takes next five bits and discovers the source address of the first register to be used, then after finding the first source address of the operations it searches for the second address of the next five bits. Variables acronyms are shown below:
s11 = operation one, address one
s12 = operation one, address two
s21 = operation two, address one
s22 = operation two, address two
s31 = operation three, address one
s32 = operation three, address two
REGISTERED ACCESS:
00000 = 0
00001 = 1
00010 = 2
00011 = 3
00100 = 4
00101 = 5
00110 = 6
00111 = 7
01000 = 8
01001 = 9
01010 = 10
01011 = 11
01100 = 12
01101 = 13
01110 = 14
01111 = 15
10000 = 16
10001 = 17
10010 = 18
10011 = 19
10100 = 20
10101 = 21
10110 = 22
10111 = 23
11000 = 24
11001 = 25
11010 = 26
11011 = 27
11100 = 28
11101 = 29
11110 = 30
11111 = 31
***********************************************************************************************************************************************/


void s_decoder(){
	if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '0' )){
        s11 = register_arr[0];
	}
     else if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '1' )){
        s11 = register_arr[1];
	}
     else if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '0' )){
        s11 = register_arr[2];
	}
     else if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '1' )){
        s11 = register_arr[3];
	}
     else if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '0' )){
        s11 = register_arr[4];
	}
     else if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '1' )){
        s11 = register_arr[5];
	}
     else if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '0' )){
        s11 = register_arr[6];
	}
     else if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '1' )){
        s11 = register_arr[7];
	}
     else if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '0' )){
        s11 = register_arr[8];
	}
     else if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '1' )){
        s11 = register_arr[9];
	}
     else if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '0' )){
        s11 = register_arr[10];
	}
     else if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '1' )){
        s11 = register_arr[11];
	}
     else if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '0' )){
        s11 = register_arr[12];
	}
     else if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '1' )){
        s11 = register_arr[13];
	}
     else if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '0' )){
        s11 = register_arr[14];
	}
     else if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '1' )){
        s11 = register_arr[15];
	}
     else if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '0' )){
        s11 = register_arr[16];
	}
     else if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '1' )){
        s11 = register_arr[17];
	}
     else if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '0' )){
        s11 = register_arr[18];
}
     else if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '1' )){
        s11 = register_arr[19];
}
     else if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '0' )){
        s11 = register_arr[20];
}
     else if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '1' )){
        s11 = register_arr[21];
}
     else if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '0' )){
        s11 = register_arr[22];
}
     else if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '1' )){
        s11 = register_arr[23];
}
     else if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '0' )){
        s11 = register_arr[24];
}
     else if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '1' )){
        s11 = register_arr[25];
}
     else if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '0' )){
        s11 = register_arr[26];
}
     else if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '1' )){
        s11 = register_arr[27];
}
     else if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '0' )){
        s11 = register_arr[28];
}
     else if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '1' )){
        s11 = register_arr[29];
}
     else if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '0' )){
        s11 = register_arr[30];
}
     else if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '1' )){
        s11 = register_arr[31];
}

	if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '0' )){
        s21 = register_arr[0];
}
     else if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '1' )){
        s21 = register_arr[1];
}
     else if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '0' )){
        s21 = register_arr[2];
}
     else if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '1' )){
        s21 = register_arr[3];
}
     else if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '0' )){
        s21 = register_arr[4];
}
     else if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '1' )){
        s21 = register_arr[5];
}
     else if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '0' )){
        s21 = register_arr[6];
}
     else if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '1' )){
        s21 = register_arr[7];
}
     else if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '0' )){
        s21 = register_arr[8];
}
     else if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '1' )){
        s21 = register_arr[9];
}
     else if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '0' )){
        s21 = register_arr[10];
}
     else if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '1' )){
        s21 = register_arr[11];
}
     else if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '0' )){
        s21 = register_arr[12];
}
     else if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '1' )){
        s21 = register_arr[13];
}
     else if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '0' )){
        s21 = register_arr[14];
}
     else if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '1' )){
        s21 = register_arr[15];
}
     else if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '0' )){
        s21 = register_arr[16];
}
     else if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '1' )){
        s21 = register_arr[17];
}
     else if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '0' )){
        s21 = register_arr[18];
}
     else if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '1' )){
        s21 = register_arr[19];
}
     else if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '0' )){
        s21 = register_arr[20];
}
     else if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '1' )){
        s21 = register_arr[21];
}
     else if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '0' )){
        s21 = register_arr[22];
}
     else if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '1' )){
        s21 = register_arr[23];
}
     else if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '0' )){
        s21 = register_arr[24];
}
     else if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '1' )){
        s21 = register_arr[25];
}
     else if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '0' )){
        s21 = register_arr[26];
}
     else if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '1' )){
        s21 = register_arr[27];
}
     else if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '0' )){
        s21 = register_arr[28];
}
     else if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '1' )){
        s21 = register_arr[29];
}
     else if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '0' )){
        s21 = register_arr[30];
}
     else if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '1' )){
        s21 = register_arr[31];
}

if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '0' )){
        s31 = register_arr[0];
}
     else if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '1' )){
        s31 = register_arr[1];
}
     else if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '0' )){
        s31 = register_arr[2];
}
     else if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '1' )){
        s31 = register_arr[3];
}
     else if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '0' )){
        s31 = register_arr[4];
}
     else if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '1' )){
        s31 = register_arr[5];
}
     else if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '0' )){
        s31 = register_arr[6];
}
     else if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '1' )){
        s31 = register_arr[7];
}
     else if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '0' )){
        s31 = register_arr[8];
}
     else if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '1' )){
        s31 = register_arr[9];
}
     else if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '0' )){
        s31 = register_arr[10];
}
     else if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '1' )){
        s31 = register_arr[11];
}
     else if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '0' )){
        s31 = register_arr[12];
}
     else if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '1' )){
        s31 = register_arr[13];
}
     else if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '0' )){
        s31 = register_arr[14];
}
     else if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '1' )){
        s31 = register_arr[15];
}
     else if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '0' )){
        s31 = register_arr[16];
}
     else if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '1' )){
        s31 = register_arr[17];
}
     else if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '0' )){
        s31 = register_arr[18];
}
     else if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '1' )){
        s31 = register_arr[19];
}
     else if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '0' )){
        s31 = register_arr[20];
}
     else if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '1' )){
        s31 = register_arr[21];
}
     else if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '0' )){
        s31 = register_arr[22];
}
     else if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '1' )){
        s31 = register_arr[23];
}
     else if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '0' )){
        s31 = register_arr[24];
}
     else if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '1' )){
        s31 = register_arr[25];
}
     else if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '0' )){
        s31 = register_arr[26];
}
     else if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '1' )){
        s31 = register_arr[27];
}
     else if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '0' )){
        s31 = register_arr[28];
}
     else if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '1' )){
        s31 = register_arr[29];
}
     else if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '0' )){
        s31 = register_arr[30];
}
     else if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '1' )){
        s31 = register_arr[31];
}

if((op1[9] == '0')&&(op1[10] == '0')&&(op1[11] == '0')&&(op1[12] == '0') && (op1[13] == '0' )){
        s12 = register_arr[0];
}
     else if((op1[9] == '0')&&(op1[10] == '0')&&(op1[11] == '0')&&(op1[12] == '0') && (op1[13] == '1' )){
        s12 = register_arr[1];
}
     else if((op1[9] == '0')&&(op1[10] == '0')&&(op1[11] == '0')&&(op1[12] == '1') && (op1[13] == '0' )){
        s12 = register_arr[2];
}
     else if((op1[9] == '0')&&(op1[10] == '0')&&(op1[11] == '0')&&(op1[12] == '1') && (op1[13] == '1' )){
        s12 = register_arr[3];
}
     else if((op1[9] == '0')&&(op1[10] == '0')&&(op1[11] == '1')&&(op1[12] == '0') && (op1[13] == '0' )){
        s12 = register_arr[4];
}
     else if((op1[9] == '0')&&(op1[10] == '0')&&(op1[11] == '1')&&(op1[12] == '0') && (op1[13] == '1' )){
        s12 = register_arr[5];
}
     else if((op1[9] == '0')&&(op1[10] == '0')&&(op1[11] == '1')&&(op1[12] == '1') && (op1[13] == '0' )){
        s12 = register_arr[6];
}
     else if((op1[9] == '0')&&(op1[10] == '0')&&(op1[11] == '1')&&(op1[12] == '1') && (op1[13] == '1' )){
        s12 = register_arr[7];
}
     else if((op1[9] == '0')&&(op1[10] == '1')&&(op1[11] == '0')&&(op1[12] == '0') && (op1[13] == '0' )){
        s12 = register_arr[8];
}
     else if((op1[9] == '0')&&(op1[10] == '1')&&(op1[11] == '0')&&(op1[12] == '0') && (op1[13] == '1' )){
        s12 = register_arr[9];
}
     else if((op1[9] == '0')&&(op1[10] == '1')&&(op1[11] == '0')&&(op1[12] == '1') && (op1[13] == '0' )){
        s12 = register_arr[10];
}
     else if((op1[9] == '0')&&(op1[10] == '1')&&(op1[11] == '0')&&(op1[12] == '1') && (op1[13] == '1' )){
        s12 = register_arr[11];
}
     else if((op1[9] == '0')&&(op1[10] == '1')&&(op1[11] == '1')&&(op1[12] == '0') && (op1[13] == '0' )){
        s12 = register_arr[12];
}
     else if((op1[9] == '0')&&(op1[10] == '1')&&(op1[11] == '1')&&(op1[12] == '0') && (op1[13] == '1' )){
        s12 = register_arr[13];
}
     else if((op1[9] == '0')&&(op1[10] == '1')&&(op1[11] == '1')&&(op1[12] == '1') && (op1[13] == '0' )){
        s12 = register_arr[14];
}
     else if((op1[9] == '0')&&(op1[10] == '1')&&(op1[11] == '1')&&(op1[12] == '1') && (op1[13] == '1' )){
        s12 = register_arr[15];
}
     else if((op1[9] == '1')&&(op1[10] == '0')&&(op1[11] == '0')&&(op1[12] == '0') && (op1[13] == '0' )){
        s12 = register_arr[16];
}
     else if((op1[9] == '1')&&(op1[10] == '0')&&(op1[11] == '0')&&(op1[12] == '0') && (op1[13] == '1' )){
        s12 = register_arr[17];
}
     else if((op1[9] == '1')&&(op1[10] == '0')&&(op1[11] == '0')&&(op1[12] == '1') && (op1[13] == '0' )){
        s12 = register_arr[18];
}
     else if((op1[9] == '1')&&(op1[10] == '0')&&(op1[11] == '0')&&(op1[12] == '1') && (op1[13] == '1' )){
        s12 = register_arr[19];
}
     else if((op1[9] == '1')&&(op1[10] == '0')&&(op1[11] == '1')&&(op1[12] == '0') && (op1[13] == '0' )){
        s12 = register_arr[20];
}
     else if((op1[9] == '1')&&(op1[10] == '0')&&(op1[11] == '1')&&(op1[12] == '0') && (op1[13] == '1' )){
        s12 = register_arr[21];
}
     else if((op1[9] == '1')&&(op1[10] == '0')&&(op1[11] == '1')&&(op1[12] == '1') && (op1[13] == '0' )){
        s12 = register_arr[22];
}
     else if((op1[9] == '1')&&(op1[10] == '0')&&(op1[11] == '1')&&(op1[12] == '1') && (op1[13] == '1' )){
        s12 = register_arr[23];
}
     else if((op1[9] == '1')&&(op1[10] == '1')&&(op1[11] == '0')&&(op1[12] == '0') && (op1[13] == '0' )){
        s12 = register_arr[24];
}
     else if((op1[9] == '1')&&(op1[10] == '1')&&(op1[11] == '0')&&(op1[12] == '0') && (op1[13] == '1' )){
        s12 = register_arr[25];
}
     else if((op1[9] == '1')&&(op1[10] == '1')&&(op1[11] == '0')&&(op1[12] == '1') && (op1[13] == '0' )){
        s12 = register_arr[26];
}
     else if((op1[9] == '1')&&(op1[10] == '1')&&(op1[11] == '0')&&(op1[12] == '1') && (op1[13] == '1' )){
        s12 = register_arr[27];
}
     else if((op1[9] == '1')&&(op1[10] == '1')&&(op1[11] == '1')&&(op1[12] == '0') && (op1[13] == '0' )){
        s12 = register_arr[28];
}
     else if((op1[9] == '1')&&(op1[10] == '1')&&(op1[11] == '1')&&(op1[12] == '0') && (op1[13] == '1' )){
        s12 = register_arr[29];
}
     else if((op1[9] == '1')&&(op1[10] == '1')&&(op1[11] == '1')&&(op1[12] == '1') && (op1[13] == '0' )){
        s12 = register_arr[30];
}
     else if((op1[9] == '1')&&(op1[10] == '1')&&(op1[11] == '1')&&(op1[12] == '1') && (op1[13] == '1' )){
        s12 = register_arr[31];
}

if((op2[9] == '0')&&(op2[10] == '0')&&(op2[11] == '0')&&(op2[12] == '0') && (op2[13] == '0' )){
        s22 = register_arr[0];
}
     else if((op2[9] == '0')&&(op2[10] == '0')&&(op2[11] == '0')&&(op2[12] == '0') && (op2[13] == '1' )){
        s22 = register_arr[1];
}
     else if((op2[9] == '0')&&(op2[10] == '0')&&(op2[11] == '0')&&(op2[12] == '1') && (op2[13] == '0' )){
        s22 = register_arr[2];
}
     else if((op2[9] == '0')&&(op2[10] == '0')&&(op2[11] == '0')&&(op2[12] == '1') && (op2[13] == '1' )){
        s22 = register_arr[3];
}
     else if((op2[9] == '0')&&(op2[10] == '0')&&(op2[11] == '1')&&(op2[12] == '0') && (op2[13] == '0' )){
        s22 = register_arr[4];
}
     else if((op2[9] == '0')&&(op2[10] == '0')&&(op2[11] == '1')&&(op2[12] == '0') && (op2[13] == '1' )){
        s22 = register_arr[5];
}
     else if((op2[9] == '0')&&(op2[10] == '0')&&(op2[11] == '1')&&(op2[12] == '1') && (op2[13] == '0' )){
        s22 = register_arr[6];
}
     else if((op2[9] == '0')&&(op2[10] == '0')&&(op2[11] == '1')&&(op2[12] == '1') && (op2[13] == '1' )){
        s22 = register_arr[7];
}
     else if((op2[9] == '0')&&(op2[10] == '1')&&(op2[11] == '0')&&(op2[12] == '0') && (op2[13] == '0' )){
        s22 = register_arr[8];
}
     else if((op2[9] == '0')&&(op2[10] == '1')&&(op2[11] == '0')&&(op2[12] == '0') && (op2[13] == '1' )){
        s22 = register_arr[9];
}
     else if((op2[9] == '0')&&(op2[10] == '1')&&(op2[11] == '0')&&(op2[12] == '1') && (op2[13] == '0' )){
        s22 = register_arr[10];
}
     else if((op2[9] == '0')&&(op2[10] == '1')&&(op2[11] == '0')&&(op2[12] == '1') && (op2[13] == '1' )){
        s22 = register_arr[11];
}
     else if((op2[9] == '0')&&(op2[10] == '1')&&(op2[11] == '1')&&(op2[12] == '0') && (op2[13] == '0' )){
        s22 = register_arr[12];
}
     else if((op2[9] == '0')&&(op2[10] == '1')&&(op2[11] == '1')&&(op2[12] == '0') && (op2[13] == '1' )){
        s22 = register_arr[13];
}
     else if((op2[9] == '0')&&(op2[10] == '1')&&(op2[11] == '1')&&(op2[12] == '1') && (op2[13] == '0' )){
        s22 = register_arr[14];
}
     else if((op2[9] == '0')&&(op2[10] == '1')&&(op2[11] == '1')&&(op2[12] == '1') && (op2[13] == '1' )){
        s22 = register_arr[15];
}
     else if((op2[9] == '1')&&(op2[10] == '0')&&(op2[11] == '0')&&(op2[12] == '0') && (op2[13] == '0' )){
        s22 = register_arr[16];
}
     else if((op2[9] == '1')&&(op2[10] == '0')&&(op2[11] == '0')&&(op2[12] == '0') && (op2[13] == '1' )){
        s22 = register_arr[17];
}
     else if((op2[9] == '1')&&(op2[10] == '0')&&(op2[11] == '0')&&(op2[12] == '1') && (op2[13] == '0' )){
        s22 = register_arr[18];
}
     else if((op2[9] == '1')&&(op2[10] == '0')&&(op2[11] == '0')&&(op2[12] == '1') && (op2[13] == '1' )){
        s22 = register_arr[19];
}
     else if((op2[9] == '1')&&(op2[10] == '0')&&(op2[11] == '1')&&(op2[12] == '0') && (op2[13] == '0' )){
        s22 = register_arr[20];
}
     else if((op2[9] == '1')&&(op2[10] == '0')&&(op2[11] == '1')&&(op2[12] == '0') && (op2[13] == '1' )){
        s22 = register_arr[21];
}
     else if((op2[9] == '1')&&(op2[10] == '0')&&(op2[11] == '1')&&(op2[12] == '1') && (op2[13] == '0' )){
        s22 = register_arr[22];
}
     else if((op2[9] == '1')&&(op2[10] == '0')&&(op2[11] == '1')&&(op2[12] == '1') && (op2[13] == '1' )){
        s22 = register_arr[23];
}
     else if((op2[9] == '1')&&(op2[10] == '1')&&(op2[11] == '0')&&(op2[12] == '0') && (op2[13] == '0' )){
        s22 = register_arr[24];
}
     else if((op2[9] == '1')&&(op2[10] == '1')&&(op2[11] == '0')&&(op2[12] == '0') && (op2[13] == '1' )){
        s22 = register_arr[25];
}
     else if((op2[9] == '1')&&(op2[10] == '1')&&(op2[11] == '0')&&(op2[12] == '1') && (op2[13] == '0' )){
        s22 = register_arr[26];
}
     else if((op2[9] == '1')&&(op2[10] == '1')&&(op2[11] == '0')&&(op2[12] == '1') && (op2[13] == '1' )){
        s22 = register_arr[27];
}
     else if((op2[9] == '1')&&(op2[10] == '1')&&(op2[11] == '1')&&(op2[12] == '0') && (op2[13] == '0' )){
        s22 = register_arr[28];
}
     else if((op2[9] == '1')&&(op2[10] == '1')&&(op2[11] == '1')&&(op2[12] == '0') && (op2[13] == '1' )){
        s22 = register_arr[29];
}
     else if((op2[9] == '1')&&(op2[10] == '1')&&(op2[11] == '1')&&(op2[12] == '1') && (op2[13] == '0' )){
        s22 = register_arr[30];
}
     else if((op2[9] == '1')&&(op2[10] == '1')&&(op2[11] == '1')&&(op2[12] == '1') && (op2[13] == '1' )){
        s22 = register_arr[31];
}

if((op3[9] == '0')&&(op3[10] == '0')&&(op3[11] == '0')&&(op3[12] == '0') && (op3[13] == '0' )){
        s32 = register_arr[0];
}
     else if((op3[9] == '0')&&(op3[10] == '0')&&(op3[11] == '0')&&(op3[12] == '0') && (op3[13] == '1' )){
        s32 = register_arr[1];
}
     else if((op3[9] == '0')&&(op3[10] == '0')&&(op3[11] == '0')&&(op3[12] == '1') && (op3[13] == '0' )){
        s32 = register_arr[2];
}
     else if((op3[9] == '0')&&(op3[10] == '0')&&(op3[11] == '0')&&(op3[12] == '1') && (op3[13] == '1' )){
        s32 = register_arr[3];
}
     else if((op3[9] == '0')&&(op3[10] == '0')&&(op3[11] == '1')&&(op3[12] == '0') && (op3[13] == '0' )){
        s32 = register_arr[4];
}
     else if((op3[9] == '0')&&(op3[10] == '0')&&(op3[11] == '1')&&(op3[12] == '0') && (op3[13] == '1' )){
        s32 = register_arr[5];
}
     else if((op3[9] == '0')&&(op3[10] == '0')&&(op3[11] == '1')&&(op3[12] == '1') && (op3[13] == '0' )){
        s32 = register_arr[6];
}
     else if((op3[9] == '0')&&(op3[10] == '0')&&(op3[11] == '1')&&(op3[12] == '1') && (op3[13] == '1' )){
        s32 = register_arr[7];
}
     else if((op3[9] == '0')&&(op3[10] == '1')&&(op3[11] == '0')&&(op3[12] == '0') && (op3[13] == '0' )){
        s32 = register_arr[8];
}
     else if((op3[9] == '0')&&(op3[10] == '1')&&(op3[11] == '0')&&(op3[12] == '0') && (op3[13] == '1' )){
        s32 = register_arr[9];
}
     else if((op3[9] == '0')&&(op3[10] == '1')&&(op3[11] == '0')&&(op3[12] == '1') && (op3[13] == '0' )){
        s32 = register_arr[10];
}
     else if((op3[9] == '0')&&(op3[10] == '1')&&(op3[11] == '0')&&(op3[12] == '1') && (op3[13] == '1' )){
        s32 = register_arr[11];
}
     else if((op3[9] == '0')&&(op3[10] == '1')&&(op3[11] == '1')&&(op3[12] == '0') && (op3[13] == '0' )){
        s32 = register_arr[12];
}
     else if((op3[9] == '0')&&(op3[10] == '1')&&(op3[11] == '1')&&(op3[12] == '0') && (op3[13] == '1' )){
        s32 = register_arr[13];
}
     else if((op3[9] == '0')&&(op3[10] == '1')&&(op3[11] == '1')&&(op3[12] == '1') && (op3[13] == '0' )){
        s32 = register_arr[14];
}
     else if((op3[9] == '0')&&(op3[10] == '1')&&(op3[11] == '1')&&(op3[12] == '1') && (op3[13] == '1' )){
        s32 = register_arr[15];
}
     else if((op3[9] == '1')&&(op3[10] == '0')&&(op3[11] == '0')&&(op3[12] == '0') && (op3[13] == '0' )){
        s32 = register_arr[16];
}
     else if((op3[9] == '1')&&(op3[10] == '0')&&(op3[11] == '0')&&(op3[12] == '0') && (op3[13] == '1' )){
        s32 = register_arr[17];
}
     else if((op3[9] == '1')&&(op3[10] == '0')&&(op3[11] == '0')&&(op3[12] == '1') && (op3[13] == '0' )){
        s32 = register_arr[18];
}
     else if((op3[9] == '1')&&(op3[10] == '0')&&(op3[11] == '0')&&(op3[12] == '1') && (op3[13] == '1' )){
        s32 = register_arr[19];
}
     else if((op3[9] == '1')&&(op3[10] == '0')&&(op3[11] == '1')&&(op3[12] == '0') && (op3[13] == '0' )){
        s32 = register_arr[20];
}
     else if((op3[9] == '1')&&(op3[10] == '0')&&(op3[11] == '1')&&(op3[12] == '0') && (op3[13] == '1' )){
        s32 = register_arr[21];
}
     else if((op3[9] == '1')&&(op3[10] == '0')&&(op3[11] == '1')&&(op3[12] == '1') && (op3[13] == '0' )){
        s32 = register_arr[22];
}
     else if((op3[9] == '1')&&(op3[10] == '0')&&(op3[11] == '1')&&(op3[12] == '1') && (op3[13] == '1' )){
        s32 = register_arr[23];
}
     else if((op3[9] == '1')&&(op3[10] == '1')&&(op3[11] == '0')&&(op3[12] == '0') && (op3[13] == '0' )){
        s32 = register_arr[24];
}
     else if((op3[9] == '1')&&(op3[10] == '1')&&(op3[11] == '0')&&(op3[12] == '0') && (op3[13] == '1' )){
        s32 = register_arr[25];
}
     else if((op3[9] == '1')&&(op3[10] == '1')&&(op3[11] == '0')&&(op3[12] == '1') && (op3[13] == '0' )){
        s32 = register_arr[26];
}
     else if((op3[9] == '1')&&(op3[10] == '1')&&(op3[11] == '0')&&(op3[12] == '1') && (op3[13] == '1' )){
        s32 = register_arr[27];
}
     else if((op3[9] == '1')&&(op3[10] == '1')&&(op3[11] == '1')&&(op3[12] == '0') && (op3[13] == '0' )){
        s32 = register_arr[28];
}
     else if((op3[9] == '1')&&(op3[10] == '1')&&(op3[11] == '1')&&(op3[12] == '0') && (op3[13] == '1' )){
        s32 = register_arr[29];
}
     else if((op3[9] == '1')&&(op3[10] == '1')&&(op3[11] == '1')&&(op3[12] == '1') && (op3[13] == '0' )){
        s32 = register_arr[30];
}
     else if((op3[9] == '1')&&(op3[10] == '1')&&(op3[11] == '1')&&(op3[12] == '1') && (op3[13] == '1' )){
        s32 = register_arr[31];
}
}
/************************************************************************************************************************************************
Decodes the destination address from the last five bits and determines which register to store the results from the mathematical functions
These values are the same as the source decoder and the binary can be found in that comment section, but the destination variables are recorded below:
d1 = destination address for operation 1
d2 = destination address for operation 2
d3 = destination address for operation 3

************************************************************************************************************************************************/

void d_decoder(){
if((op1[15] == '0')&&(op1[16] == '0')&&(op1[17] == '0')&&(op1[18] == '0') && (op1[19] == '0' )){
		register_arr[0] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '0')&&(op1[17] == '0')&&(op1[18] == '0') && (op1[19] == '1' )){
		register_arr[1] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '0')&&(op1[17] == '0')&&(op1[18] == '1') && (op1[19] == '0' )){
		register_arr[2] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '0')&&(op1[17] == '0')&&(op1[18] == '1') && (op1[19] == '1' )){
		register_arr[3] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '0')&&(op1[17] == '1')&&(op1[18] == '0') && (op1[19] == '0' )){
		register_arr[4] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '0')&&(op1[17] == '1')&&(op1[18] == '0') && (op1[19] == '1' )){
		register_arr[5] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '0')&&(op1[17] == '1')&&(op1[18] == '1') && (op1[19] == '0' )){
		register_arr[6] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '0')&&(op1[17] == '1')&&(op1[18] == '1') && (op1[19] == '1' )){
		register_arr[7] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '1')&&(op1[17] == '0')&&(op1[18] == '0') && (op1[19] == '0' )){
		register_arr[8] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '1')&&(op1[17] == '0')&&(op1[18] == '0') && (op1[19] == '1' )){
		register_arr[9] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '1')&&(op1[17] == '0')&&(op1[18] == '1') && (op1[19] == '0' )){
		register_arr[10] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '1')&&(op1[17] == '0')&&(op1[18] == '1') && (op1[19] == '1' )){
		register_arr[11] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '1')&&(op1[17] == '1')&&(op1[18] == '0') && (op1[19] == '0' )){
		register_arr[12] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '1')&&(op1[17] == '1')&&(op1[18] == '0') && (op1[19] == '1' )){
		register_arr[13] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '1')&&(op1[17] == '1')&&(op1[18] == '1') && (op1[19] == '0' )){
		register_arr[14] = d1;
}
     else if((op1[15] == '0')&&(op1[16] == '1')&&(op1[17] == '1')&&(op1[18] == '1') && (op1[19] == '1' )){
		register_arr[15] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '0')&&(op1[17] == '0')&&(op1[18] == '0') && (op1[19] == '0' )){
		register_arr[16] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '0')&&(op1[17] == '0')&&(op1[18] == '0') && (op1[19] == '1' )){
		register_arr[17] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '0')&&(op1[17] == '0')&&(op1[18] == '1') && (op1[19] == '0' )){
		register_arr[18] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '0')&&(op1[17] == '0')&&(op1[18] == '1') && (op1[19] == '1' )){
		register_arr[19] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '0')&&(op1[17] == '1')&&(op1[18] == '0') && (op1[19] == '0' )){
		register_arr[20] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '0')&&(op1[17] == '1')&&(op1[18] == '0') && (op1[19] == '1' )){
		register_arr[21] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '0')&&(op1[17] == '1')&&(op1[18] == '1') && (op1[19] == '0' )){
		register_arr[22] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '0')&&(op1[17] == '1')&&(op1[18] == '1') && (op1[19] == '1' )){
		register_arr[23] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '1')&&(op1[17] == '0')&&(op1[18] == '0') && (op1[19] == '0' )){
		register_arr[24] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '1')&&(op1[17] == '0')&&(op1[18] == '0') && (op1[19] == '1' )){
		register_arr[25] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '1')&&(op1[17] == '0')&&(op1[18] == '1') && (op1[19] == '0' )){
		register_arr[26] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '1')&&(op1[17] == '0')&&(op1[18] == '1') && (op1[19] == '1' )){
		register_arr[27] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '1')&&(op1[17] == '1')&&(op1[18] == '0') && (op1[19] == '0' )){
		register_arr[28] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '1')&&(op1[17] == '1')&&(op1[18] == '0') && (op1[19] == '1' )){
		register_arr[29] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '1')&&(op1[17] == '1')&&(op1[18] == '1') && (op1[19] == '0' )){
		register_arr[30] = d1;
}
     else if((op1[15] == '1')&&(op1[16] == '1')&&(op1[17] == '1')&&(op1[18] == '1') && (op1[19] == '1' )){
		register_arr[31] = d1;
}

if((op2[15] == '0')&&(op2[16] == '0')&&(op2[17] == '0')&&(op2[18] == '0') && (op2[19] == '0' )){
		register_arr[0] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '0')&&(op2[17] == '0')&&(op2[18] == '0') && (op2[19] == '1' )){
		register_arr[1] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '0')&&(op2[17] == '0')&&(op2[18] == '1') && (op2[19] == '0' )){
		register_arr[2] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '0')&&(op2[17] == '0')&&(op2[18] == '1') && (op2[19] == '1' )){
		register_arr[3] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '0')&&(op2[17] == '1')&&(op2[18] == '0') && (op2[19] == '0' )){
		register_arr[4] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '0')&&(op2[17] == '1')&&(op2[18] == '0') && (op2[19] == '1' )){
		register_arr[5] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '0')&&(op2[17] == '1')&&(op2[18] == '1') && (op2[19] == '0' )){
		register_arr[6] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '0')&&(op2[17] == '1')&&(op2[18] == '1') && (op2[19] == '1' )){
		register_arr[7] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '1')&&(op2[17] == '0')&&(op2[18] == '0') && (op2[19] == '0' )){
		register_arr[8] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '1')&&(op2[17] == '0')&&(op2[18] == '0') && (op2[19] == '1' )){
		register_arr[9] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '1')&&(op2[17] == '0')&&(op2[18] == '1') && (op2[19] == '0' )){
		register_arr[10] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '1')&&(op2[17] == '0')&&(op2[18] == '1') && (op2[19] == '1' )){
		register_arr[11] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '1')&&(op2[17] == '1')&&(op2[18] == '0') && (op2[19] == '0' )){
		register_arr[12] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '1')&&(op2[17] == '1')&&(op2[18] == '0') && (op2[19] == '1' )){
		register_arr[13] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '1')&&(op2[17] == '1')&&(op2[18] == '1') && (op2[19] == '0' )){
		register_arr[14] = d2;
}
     else if((op2[15] == '0')&&(op2[16] == '1')&&(op2[17] == '1')&&(op2[18] == '1') && (op2[19] == '1' )){
		register_arr[15] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '0')&&(op2[17] == '0')&&(op2[18] == '0') && (op2[19] == '0' )){
		register_arr[16] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '0')&&(op2[17] == '0')&&(op2[18] == '0') && (op2[19] == '1' )){
		register_arr[17] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '0')&&(op2[17] == '0')&&(op2[18] == '1') && (op2[19] == '0' )){
		register_arr[18] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '0')&&(op2[17] == '0')&&(op2[18] == '1') && (op2[19] == '1' )){
		register_arr[19] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '0')&&(op2[17] == '1')&&(op2[18] == '0') && (op2[19] == '0' )){
		register_arr[20] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '0')&&(op2[17] == '1')&&(op2[18] == '0') && (op2[19] == '1' )){
		register_arr[21] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '0')&&(op2[17] == '1')&&(op2[18] == '1') && (op2[19] == '0' )){
		register_arr[22] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '0')&&(op2[17] == '1')&&(op2[18] == '1') && (op2[19] == '1' )){
		register_arr[23] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '1')&&(op2[17] == '0')&&(op2[18] == '0') && (op2[19] == '0' )){
		register_arr[24] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '1')&&(op2[17] == '0')&&(op2[18] == '0') && (op2[19] == '1' )){
		register_arr[25] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '1')&&(op2[17] == '0')&&(op2[18] == '1') && (op2[19] == '0' )){
		register_arr[26] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '1')&&(op2[17] == '0')&&(op2[18] == '1') && (op2[19] == '1' )){
		register_arr[27] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '1')&&(op2[17] == '1')&&(op2[18] == '0') && (op2[19] == '0' )){
		register_arr[28] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '1')&&(op2[17] == '1')&&(op2[18] == '0') && (op2[19] == '1' )){
		register_arr[29] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '1')&&(op2[17] == '1')&&(op2[18] == '1') && (op2[19] == '0' )){
		register_arr[30] = d2;
}
     else if((op2[15] == '1')&&(op2[16] == '1')&&(op2[17] == '1')&&(op2[18] == '1') && (op2[19] == '1' )){
		register_arr[31] = d2;
}


if((op3[15] == '0')&&(op3[16] == '0')&&(op3[17] == '0')&&(op3[18] == '0') && (op3[19] == '0' )){
		register_arr[0] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '0')&&(op3[17] == '0')&&(op3[18] == '0') && (op3[19] == '1' )){
		register_arr[1] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '0')&&(op3[17] == '0')&&(op3[18] == '1') && (op3[19] == '0' )){
		register_arr[2] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '0')&&(op3[17] == '0')&&(op3[18] == '1') && (op3[19] == '1' )){
		register_arr[3] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '0')&&(op3[17] == '1')&&(op3[18] == '0') && (op3[19] == '0' )){
		register_arr[4] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '0')&&(op3[17] == '1')&&(op3[18] == '0') && (op3[19] == '1' )){
		register_arr[5] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '0')&&(op3[17] == '1')&&(op3[18] == '1') && (op3[19] == '0' )){
		register_arr[6] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '0')&&(op3[17] == '1')&&(op3[18] == '1') && (op3[19] == '1' )){
		register_arr[7] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '1')&&(op3[17] == '0')&&(op3[18] == '0') && (op3[19] == '0' )){
		register_arr[8] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '1')&&(op3[17] == '0')&&(op3[18] == '0') && (op3[19] == '1' )){
		register_arr[9] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '1')&&(op3[17] == '0')&&(op3[18] == '1') && (op3[19] == '0' )){
		register_arr[10] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '1')&&(op3[17] == '0')&&(op3[18] == '1') && (op3[19] == '1' )){
		register_arr[11] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '1')&&(op3[17] == '1')&&(op3[18] == '0') && (op3[19] == '0' )){
		register_arr[12] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '1')&&(op3[17] == '1')&&(op3[18] == '0') && (op3[19] == '1' )){
		register_arr[13] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '1')&&(op3[17] == '1')&&(op3[18] == '1') && (op3[19] == '0' )){
		register_arr[14] = d3;
}
     else if((op3[15] == '0')&&(op3[16] == '1')&&(op3[17] == '1')&&(op3[18] == '1') && (op3[19] == '1' )){
		register_arr[15] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '0')&&(op3[17] == '0')&&(op3[18] == '0') && (op3[19] == '0' )){
		register_arr[16] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '0')&&(op3[17] == '0')&&(op3[18] == '0') && (op3[19] == '1' )){
		register_arr[17] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '0')&&(op3[17] == '0')&&(op3[18] == '1') && (op3[19] == '0' )){
		register_arr[18] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '0')&&(op3[17] == '0')&&(op3[18] == '1') && (op3[19] == '1' )){
		register_arr[19] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '0')&&(op3[17] == '1')&&(op3[18] == '0') && (op3[19] == '0' )){
		register_arr[20] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '0')&&(op3[17] == '1')&&(op3[18] == '0') && (op3[19] == '1' )){
		register_arr[21] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '0')&&(op3[17] == '1')&&(op3[18] == '1') && (op3[19] == '0' )){
		register_arr[22] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '0')&&(op3[17] == '1')&&(op3[18] == '1') && (op3[19] == '1' )){
		register_arr[23] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '1')&&(op3[17] == '0')&&(op3[18] == '0') && (op3[19] == '0' )){
		register_arr[24] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '1')&&(op3[17] == '0')&&(op3[18] == '0') && (op3[19] == '1' )){
		register_arr[25] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '1')&&(op3[17] == '0')&&(op3[18] == '1') && (op3[19] == '0' )){
		register_arr[26] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '1')&&(op3[17] == '0')&&(op3[18] == '1') && (op3[19] == '1' )){
		register_arr[27] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '1')&&(op3[17] == '1')&&(op3[18] == '0') && (op3[19] == '0' )){
		register_arr[28] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '1')&&(op3[17] == '1')&&(op3[18] == '0') && (op3[19] == '1' )){
		register_arr[29] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '1')&&(op3[17] == '1')&&(op3[18] == '1') && (op3[19] == '0' )){
		register_arr[30] = d3;
}
     else if((op3[15] == '1')&&(op3[16] == '1')&&(op3[17] == '1')&&(op3[18] == '1') && (op3[19] == '1' )){
		register_arr[31] = d3;
}

}
/************************************************************************************************************************************************
Preforms addition opn represents the sub stage of the execution stage. Variable stages are shown:
opn 1 = stage execution stage for operation 1
opn 2 = stage execution stage for operation 2
opn 3 = stage execution stage for operation 3
Math proof: 
Destination = source 1 + source 2
************************************************************************************************************************************************/
void addition(){ // addition two source
	if (opn == 1){
		d1 = s11 + s12;
	}
     else if (opn == 2){
		d2 = s21 + s22;
	}
     else if (opn == 3){
		d3 = s31 + s32;
	}
}
/************************************************************************************************************************************************
Math proof:
destination = source 1 - source 2
************************************************************************************************************************************************/
void subtraction(){ // sub two source
	if (opn == 1){
		d1 = s11 - s12;
	}
     else if (opn == 2){
		d2 = s21 - s22;
	}
     else if (opn == 3){
		d3 = s31 - s32;
	}
}
/************************************************************************************************************************************************
Math proof:
destination = source 1 x source 2
************************************************************************************************************************************************/
void multiplication(){ // multiplication two source
	if (opn == 1){
		d1 = s11 * s12;
	}
     else if (opn == 2){
		d2 = s21 * s22;
	}
     else if (opn == 3){
		d3 = s31 * s32;
	}
}
/************************************************************************************************************************************************
Math proof:
destination = source 1 / source 2
************************************************************************************************************************************************/
void division(){ // division two source
	if (opn == 1){
		d1 = s11 / s12;
	}
     else if (opn == 2){
		d2 = s21 / s22;
	}
     else if (opn == 3){
		d3 = s31 / s32;
	}
}
/************************************************************************************************************************************************
Math proof:
destination = NOT source 1
* The second source is ignored
************************************************************************************************************************************************/
void not_gate(){ // needs choice
	if (opn == 1){
		d1 = ~s11;
	}
     else if (opn == 2){
		d2 = ~s21;
	}
     else if (opn == 3){
		d3 = ~s31;
	}
}
/************************************************************************************************************************************************
Math proof:
destination = source 1 NOR source 2

************************************************************************************************************************************************/
void nor(){ // nor two source
	if (opn == 1){
		d1 = ~(s11 | s12);
	}
     else if (opn == 2){
		d2 = ~(s21 | s22);
	}
     else if (opn == 3){
		d3 = ~(s31 | s32);
	}
}
/************************************************************************************************************************************************
Math proof:
destination = source 1 XNOR source 2

************************************************************************************************************************************************/
void xnor(){ //xnor two source 
	if (opn == 1){
		d1 = ((s11 & s12) | (( ~ s11) & (~s12))); 
	}
     else if (opn == 2){
		d2 = ((s21 & s22) | (( ~ s21) & (~ s22))); 
	}
     else if (opn == 3){
		d3 = ((s31 & s32) | (( ~ s31) & (~ s32))); 
	}
}
/************************************************************************************************************************************************
Math proof:
destination = source 1 NAND source 2

************************************************************************************************************************************************/

void nand(){ // nand two source
	if (opn == 1){
		d1 = ~(s11 & s12); 
	}
     else if (opn == 2){
		d2 = ~(s21 & s22); 
	}
     else if (opn == 3){
		d3 = ~(s31 & s32); 
	}
}
/************************************************************************************************************************************************
Math proof:
destination = source 1
* Source two is ignored and sources one value is moved to destination
************************************************************************************************************************************************/

void move(){ // choice 
	if (opn == 1){
		d1 = s11;
	}
     else if (opn == 2){
		d2 = s21;
	}
     else if (opn == 3){ 
		d3 = s31;
	}
}

/************************************************************************************************************************************************
Math proof:
If the values of source 1 is equal to source 2 then the destination address stores 1
if the values of source 1 is not equal to source 2 then the destination address stores 0

************************************************************************************************************************************************/

void compare(){
if(opn == 1){
	if(s11  == s12){
		d1 = 1;
		}
	     else {
		d1 = 0;
		}

}
     else if(opn == 2){
	if(s21  == s22){
		d2 = 1;
		}
	     else {
		d2 = 0;
		}
}
     else if(opn == 3){
	if(s31  == s32){
		d3 = 1;
		}
	     else {
		d3 = 0;
		}
}
}
/************************************************************************************************************************************************
Reads the first source and ignores the second
************************************************************************************************************************************************/
void read_this(){ // choice 
	if(opn == 1){
			cout << "I read: " << s11 << endl;
		}
	     else if (opn == 2){
			cout << "I read: " << s21 << endl; 
		}
	     else if(opn == 3){
			cout << "I read: " << s31 << endl;
		}
}
/************************************************************************************************************************************************
Math proof
destination address is equal to source one x (2 ^ source address two)
source address represents the number of shifts the user likes to preform
ex:
00010 = 2  then shift twice
2 * 2 * 2 = 8
01000 = 8

************************************************************************************************************************************************/

void shift_left(){
	if(opn == 1){
			d1 = s11 * pow(2,s12);
		}
	     else if(opn == 2){
			d2 = s21 * pow(2,s22);
		}
	     else if(opn == 3){
			d3 = s31 * pow(2,s32);
		}
}
/************************************************************************************************************************************************
Math proof:
source 1 times negative one to create a negative exponent
source address 2 represents the number of shift left
ex:
1000 = 8
shift twice
8 * .5 * .5 = 2
0010 = 2
************************************************************************************************************************************************/

void shift_right(){
	int s1t;
	int s2t;
	int s3t;
	s1t = s12 * (-1);
	s2t = s22 * (-1);
	s3t = s32 * (-1);
	if(opn == 1){
		d1 = s11 * pow(2,s12);
		}
	     else if(opn == 2){
		d2 = s21 * pow(2,s22);
		}
	     else if(opn == 3){
		d3 = s31 * pow(2,s32);	
		}
}
/************************************************************************************************************************************************
Math proof:
Destination address = source 1 address OR source 2 address

************************************************************************************************************************************************/
void or_gate(){
	if(opn == 1){
		d1 = s11 | s12;
		}
	     else if(opn == 2){
		d2 = s21 | s22;
		}
	     else if(opn == 3){
		d3 = s31 | s32;	
		}
}
/************************************************************************************************************************************************
Math proof:
Destination address = source AND source 2 address

************************************************************************************************************************************************/
void and_gate(){
	if(opn == 1){
		d1 = s11 & s12;
		}
	     else if(opn == 2){
			d2 = s21 & s22;
		}
	     else if(opn == 3){
			d3 = s31 & s32;	
		}
}
/************************************************************************************************************************************************
instead of pulling from the sources this takes the first five binary utilized to calculate the registry and insteads utilizes it to store
the value for the destination
Math proof; 
00000 = 0 = destination
00001 = 1 = "...."
00010 = 2 = "...."
00011 = 3= "...."
00100 = 4= "...."
00101 = 5= "...."
00110 = 6= "...."
00111 = 7= "...."
01000 = 8= "...."
01001 = 9= "...."
01010 = 10= "...."
01011 = 11= "...."
01100 = 12= "...."
01101 = 13= "...."
01110 = 14= "...."
01111 = 15= "...."
10000 = 16= "...."
10001 = 17= "...."
10010 = 18= "...."
10011 = 19= "...."
10100 = 20= "...."
10101 = 21= "...."
10110 = 22= "...."
10111 = 23= "...."
11000 = 24= "...."
11001 = 25= "...."
11010 = 26= "...."
11011 = 27= "...."
11100 = 28= "...."
11101 = 29= "...."
11110 = 30= "...."
11111 = 31= "...."
************************************************************************************************************************************************/
void load(){ 
if (opn == 1){
if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '0' )){
d1 = 0;
}
if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '1' )){
d1 = 1;
}
if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '0' )){
d1 = 2;
}
if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '1' )){
d1 = 3;
}
if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '0' )){
d1 = 4;
}
if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '1' )){
d1 = 5;
}
if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '0' )){
d1 = 6;
}
if((op1[4] == '0')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '1' )){
d1 = 7;
}
if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '0' )){
d1 = 8;
}
if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '1' )){
d1 = 9;
}
if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '0' )){
d1 = 10;
}
if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '1' )){
d1 = 11;
}
if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '0' )){
d1 = 12;
}
if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '1' )){
d1 = 13;
}
if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '0' )){
d1 = 14;
}
if((op1[4] == '0')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '1' )){
d1 = 15;
}
if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '0' )){
d1 = 16;
}
if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '1' )){
d1 = 17;
}
if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '0' )){
d1 = 18;
}
if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '1' )){
d1 = 19;
}
if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '0' )){
d1 = 20;
}
if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '1' )){
d1 = 21;
}
if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '0' )){
d1 = 22;
}
if((op1[4] == '1')&&(op1[5] == '0')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '1' )){
d1 = 23;
}
if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '0' )){
d1 = 24;
}
if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '0') && (op1[8] == '1' )){
d1 = 25;
}
if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '0' )){
d1 = 26;
}
if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '0')&&(op1[7] == '1') && (op1[8] == '1' )){
d1 = 27;
}
if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '0' )){
d1 = 28;
}
if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '0') && (op1[8] == '1' )){
d1 = 29;
}
if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '0' )){
d1 = 30;
}
if((op1[4] == '1')&&(op1[5] == '1')&&(op1[6] == '1')&&(op1[7] == '1') && (op1[8] == '1' )){
d1 = 31;
}
}
     else if (opn == 2){
if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '0' )){
d2 = 0;
}
if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '1' )){
d2 = 1;
}
if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '0' )){
d2 = 2;
}
if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '1' )){
d2 = 3;
}
if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '0' )){
d2 = 4;
}
if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '1' )){
d2 = 5;
}
if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '0' )){
d2 = 6;
}
if((op2[4] == '0')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '1' )){
d2 = 7;
}
if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '0' )){
d2 = 8;
}
if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '1' )){
d2 = 9;
}
if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '0' )){
d2 = 10;
}
if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '1' )){
d2 = 11;
}
if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '0' )){
d2 = 12;
}
if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '1' )){
d2 = 13;
}
if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '0' )){
d2 = 14;
}
if((op2[4] == '0')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '1' )){
d2 = 15;
}
if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '0' )){
d2 = 16;
}
if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '1' )){
d2 = 17;
}
if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '0' )){
d2 = 18;
}
if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '1' )){
d2 = 19;
}
if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '0' )){
d2 = 20;
}
if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '1' )){
d2 = 21;
}
if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '0' )){
d2 = 22;
}
if((op2[4] == '1')&&(op2[5] == '0')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '1' )){
d2 = 23;
}
if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '0' )){
d2 = 24;
}
if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '0') && (op2[8] == '1' )){
d2 = 25;
}
if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '0' )){
d2 = 26;
}
if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '0')&&(op2[7] == '1') && (op2[8] == '1' )){
d2 = 27;
}
if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '0' )){
d2 = 28;
}
if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '0') && (op2[8] == '1' )){
d2 = 29;
}
if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '0' )){
d2 = 30;
}
if((op2[4] == '1')&&(op2[5] == '1')&&(op2[6] == '1')&&(op2[7] == '1') && (op2[8] == '1' )){
d2 = 31;
}

}
     else if (opn == 3){
if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '0' )){
d3 = 0;
}
if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '1' )){
d3 = 1;
}
if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '0' )){
d3 = 2;
}
if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '1' )){
d3 = 3;
}
if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '0' )){
d3 = 4;
}
if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '1' )){
d3 = 5;
}
if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '0' )){
d3 = 6;
}
if((op3[4] == '0')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '1' )){
d3 = 7;
}
if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '0' )){
d3 = 8;
}
if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '1' )){
d3 = 9;
}
if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '0' )){
d3 = 10;
}
if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '1' )){
d3 = 11;
}
if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '0' )){
d3 = 12;
}
if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '1' )){
d3 = 13;
}
if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '0' )){
d3 = 14;
}
if((op3[4] == '0')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '1' )){
d3 = 15;
}
if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '0' )){
d3 = 16;
}
if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '1' )){
d3 = 17;
}
if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '0' )){
d3 = 18;
}
if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '1' )){
d3 = 19;
}
if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '0' )){
d3 = 20;
}
if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '1' )){
d3 = 21;
}
if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '0' )){
d3 = 22;
}
if((op3[4] == '1')&&(op3[5] == '0')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '1' )){
d3 = 23;
}
if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '0' )){
d3 = 24;
}
if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '0') && (op3[8] == '1' )){
d3 = 25;
}
if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '0' )){
d3 = 26;
}
if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '0')&&(op3[7] == '1') && (op3[8] == '1' )){
d3 = 27;
}
if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '0' )){
d3 = 28;
}
if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '0') && (op3[8] == '1' )){
d3 = 29;
}
if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '0' )){
d3 = 30;
}
if((op3[4] == '1')&&(op3[5] == '1')&&(op3[6] == '1')&&(op3[7] == '1') && (op3[8] == '1' )){
d3 = 31;
} 
}
}





