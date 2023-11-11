////////////////////////////////////////
//
//	File : ai.c
//	CoSpace Robot
//	Version 1.0.0
//	Jan 1 2016
//	Copyright (C) 2016 CoSpace Robot. All Rights Reserved
//
//////////////////////////////////////
//
// ONLY C Code can be compiled.
//
/////////////////////////////////////

#define CsBot_AI_H//DO NOT delete this line
#ifndef CSBOT_REAL
#include <windows.h>
#include <stdio.h>
#include <math.h>
#define DLL_EXPORT extern __declspec(dllexport)
#define false 0
#define true 1
#endif//The robot ID : It must be two char, such as '00','kl' or 'Cr'.
char AI_MyID[2] = { '0', '2' };


#define PI  3.142857142857143
#define yellow_trap  1
#define orange  2
#define black  3
#define red  4
#define green  5
#define blue_s  6
#define none  7
int mode = 52;//////////////////////////////////////////////////52
#define stop_obj  9
#define search  10
#define stop_orange  11
#define yellow  13
#define blue_trap  14
#define change_mode  15
#define change_mode_box  16
#define gray  17
#define end_get_obj  18
#define special_search 19
#define start_1  20
#define start_2  21
#define start_3  22
#define start_4  23
#define start_5  24
#define start_6  25
#define start_7  26
#define start_8  27
#define start_9  28
#define start_10  29
#define start_11  30
#define start_12  31
#define start_13  32
#define start_14  33
#define start_15  34
#define start_16  35
#define start_17  36
#define start_18  37
#define start_19  38
#define start_20  39
#define start_21  40
#define start_22  41
#define start_23  42
#define start_24  43
#define beauty_of_led_wall_mode  44
#define beauty_of_led_wall_mode_1  45
#define beauty_of_led_yellow_mode  46
#define beauty_of_led_yellow_mode_1  47
#define change_mode_led  48
#define stop_super_obj  49
#define red_robot  50
#define blue_robot  51
#define start_1_1  52
#define start  53
#define super_obj_change_mode 54
#define end_get_obj_special 55
#define stop_orange_special 56
#define stop_obj_special 57
#define start_get_super_obj 58
#define get_super_obj_1 59






/////////////////////////////////////////////////////////////ints


int Duration = 0;
int SuperDuration = 0;
int bGameEnd = false;
int CurAction = -1;
int CurGame = 0;
int SuperObj_Num = 0;
int SuperObj_X = 0;
int SuperObj_Y = 0;
int Teleport = 0;
int LoadedObjects = 0;
int US_Front = 0;
int US_Left = 0;
int US_Right = 0;
int CSLeft_R = 0;
int CSLeft_G = 0;
int CSLeft_B = 0;
int CSRight_R = 0;
int CSRight_G = 0;
int CSRight_B = 0;
int PositionX = 0;
int PositionY = 0;
int TM_State = 0;
int Compass = 0;
int Time = 0;
int WheelLeft = 0;
int WheelRight = 0;
int LED_1 = 0;
int MyState = 0;
int counter_stop = 0;
int AI_SensorNum = 13;
int counter_timer_search = 0;
int cntr = 0;
int colorL = 0;
int colorR = 0;
int objects = 0;
int purple = 0;
int black_obj = 0;
int green_obj = 0;
int red_obj = 0;
int super_obj = 0;
int counter_super_obj = 0;
int counter_wall_led = 0;
int counter_yellow_led = 0;
int flag_trap_R = 0;
int flag_trap_L = 0;
int flag_US_write = 0;
int flag_US_direction = 0;
int zone_x = 0;
int zone_y = 0;
int direction = 0;
int ark_ton_int;
double ark_ton;
double ton;
int counter_zone;
int i = 0;
int ary_x[2] = { 274, 312 };
int ary_y[2] = { 136, 249 };
int X_min[100];
int X_max[100];
int Y_max[100];
int Y_min[100];
int x_suop_max[100];
int x_suop_min[100];
int y_suop_max[100];
int y_suop_min[100];
int flag_test = 0;
int counter_goto_angle = 0;
int counter_stop_orange = 12;
int end_get_obj1 = 0;
int directoin = 0;
int counter_super_obj_s = 0;
int p = 0;
int sado_hashtad = 0;
int ark_ton_int_p = 0;
int Position_X_P = 0;
int Position_Y_P = 0;
int i_trap = 0;
int i_gray = 0;
int number_trap;
int number_gray;
int super_x;
int super_y;




#define CsBot_AI_C//DO NOT delete this line

DLL_EXPORT void SetGameID(int GameID)
{
	CurGame = GameID;
	bGameEnd = 0;
}


DLL_EXPORT int GetGameID()
{
	return CurGame;
}

//Only Used by CsBot Dance Platform

DLL_EXPORT int IsGameEnd()
{
	return bGameEnd;
}

#ifndef CSBOT_REAL

DLL_EXPORT char* GetDebugInfo()
{
	char info[1024];
	sprintf_s(info, "Duration=%d;SuperDuration=%d;bGameEnd=%d;CurAction=%d;CurGame=%d;SuperObj_Num=%d;SuperObj_X=%d;SuperObj_Y=%d;Teleport=%d;LoadedObjects=%d;US_Front=%d;US_Left=%d;US_Right=%d;CSLeft_R=%d;CSLeft_G=%d;CSLeft_B=%d;CSRight_R=%d;CSRight_G=%d;CSRight_B=%d;PositionX=%d;PositionY=%d;TM_State=%d;Compass=%d;Time=%d;WheelLeft=%d;WheelRight=%d;LED_1=%d;MyState=%d;", Duration, SuperDuration, bGameEnd, CurAction, CurGame, SuperObj_Num, SuperObj_X, SuperObj_Y, Teleport, LoadedObjects, US_Front, US_Left, US_Right, CSLeft_R, CSLeft_G, CSLeft_B, CSRight_R, CSRight_G, CSRight_B, PositionX, PositionY, TM_State, Compass, Time, WheelLeft, WheelRight, LED_1, MyState);
	return info;
}

DLL_EXPORT char* GetTeamName()
{
	return "kiarash";
}

DLL_EXPORT int GetCurAction()
{
	return CurAction;
}

//Only Used by CsBot Rescue Platform

DLL_EXPORT int GetTeleport()
{
	return Teleport;
}

//Only Used by CsBot Rescue Platform

DLL_EXPORT void SetSuperObj(int X, int Y, int num)
{
	SuperObj_X = X;
	SuperObj_Y = Y;
	SuperObj_Num = num;
}

//Only Used by CsBot Rescue Platform

DLL_EXPORT void GetSuperObj(int *X, int *Y, int *num)
{
	*X = SuperObj_X;
	*Y = SuperObj_Y;
	*num = SuperObj_Num;
}


#endif CSBOT_REAL






DLL_EXPORT void SetDataAI(volatile int* packet, volatile int *AI_IN)
{

	int sum = 0;

	US_Front = AI_IN[0]; packet[0] = US_Front; sum += US_Front;
	US_Left = AI_IN[1]; packet[1] = US_Left; sum += US_Left;
	US_Right = AI_IN[2]; packet[2] = US_Right; sum += US_Right;
	CSLeft_R = AI_IN[3]; packet[3] = CSLeft_R; sum += CSLeft_R;
	CSLeft_G = AI_IN[4]; packet[4] = CSLeft_G; sum += CSLeft_G;
	CSLeft_B = AI_IN[5]; packet[5] = CSLeft_B; sum += CSLeft_B;
	CSRight_R = AI_IN[6]; packet[6] = CSRight_R; sum += CSRight_R;
	CSRight_G = AI_IN[7]; packet[7] = CSRight_G; sum += CSRight_G;
	CSRight_B = AI_IN[8]; packet[8] = CSRight_B; sum += CSRight_B;
	PositionX = AI_IN[9]; packet[9] = PositionX; sum += PositionX;
	PositionY = AI_IN[10]; packet[10] = PositionY; sum += PositionY;
	TM_State = AI_IN[11]; packet[11] = TM_State; sum += TM_State;
	Compass = AI_IN[12]; packet[12] = Compass; sum += Compass;
	Time = AI_IN[13]; packet[13] = Time; sum += Time;
	packet[14] = sum;

}


DLL_EXPORT void GetCommand(int *AI_OUT)
{
	AI_OUT[0] = WheelLeft;
	AI_OUT[1] = WheelRight;
	AI_OUT[2] = LED_1;
	AI_OUT[3] = MyState;
}


DLL_EXPORT void positoin_lost()
{
	if (PositionX != 0)
	{
		Position_X_P = PositionX;
	}
	else if (PositionY != 0)
	{
		Position_Y_P = PositionY;
	}
}


DLL_EXPORT void move(int R, int L)
{
	WheelRight = R;
	WheelLeft = L;
}


DLL_EXPORT void find_color()
{
	if (CSLeft_R > 220 && CSLeft_G > 220 && CSLeft_B < 60)
	{
		colorL = yellow_trap;
	}
	else if (CSLeft_R > 100 && (CSLeft_G > 15 && CSLeft_G < 100) && CSLeft_B > 200)
	{
		colorL = super_obj;
	}
	else if (CSLeft_R > 200 && CSLeft_G > 200 && CSLeft_B < 80 && CSLeft_B > 30)
	{
		colorL = yellow;
	}
	else if (CSLeft_R < 90 && CSLeft_G < 135 && CSLeft_B > 200)
	{
		colorL = blue_trap;
	}
	else if (CSLeft_R > 200 && (CSLeft_G > 140 && CSLeft_G < 200) && CSLeft_B < 60)
	{
		colorL = orange;
	}

	else if (CSLeft_R > 200 && CSLeft_G < 60 && CSLeft_B < 60)
	{
		colorL = red;
	}

	else if (CSLeft_R < 60 && CSLeft_G > 200 && CSLeft_B <60)
	{
		colorL = green;

	}
	else if (CSLeft_R < 70 && CSLeft_R > 18 && CSLeft_G < 70 && CSLeft_B < 70)
	{
		colorL = black;

	}
	else if (CSLeft_R > 80 && CSLeft_R < 125 && CSLeft_G < 200 && CSLeft_G > 155 && CSLeft_B > 230)
	{
		colorL = blue_s;
	}
	else if (CSLeft_R > 200 && CSLeft_R < 225 && CSLeft_G < 110 && CSLeft_B < 190)
	{
		colorL = purple;
	}
	else
	{
		colorL = none;
	}




	if (CSRight_R > 220 && CSRight_G > 220 && CSRight_B < 60)
	{
		colorR = yellow_trap;
	}
	else if (CSRight_R > 100 && (CSRight_G > 15 && CSRight_G < 100) && CSRight_B > 200)
	{
		colorR = super_obj;
	}
	else if (CSRight_R > 200 && CSRight_G > 200 && CSRight_B < 100)
	{
		colorR = yellow;
	}
	/*else if (CSRight_R > 110 && CSRight_R < 150 && CSRight_G > 120 && CSRight_G < 160 && CSRight_B < 200 && CSRight_B > 160)
	{
	colorR = gray;
	}*/
	else if (CSRight_R < 90 && CSRight_G < 135 && CSRight_B > 200)
	{
		colorR = blue_trap;
	}
	else if (CSRight_R > 200 && (CSRight_G > 140 && CSRight_G < 200) && CSRight_B < 60)
	{
		colorR = orange;
	}

	else if (CSRight_R > 200 && CSRight_G < 60 && CSRight_B < 60)
	{
		colorR = red;
	}

	else if (CSRight_R < 50 && CSRight_G > 200 && CSRight_B < 50)
	{
		colorR = green;

	}
	else if (CSRight_R < 60 && CSRight_R < 20 && CSRight_G < 60 && CSRight_B < 60)
	{
		colorR = black;

	}
	else if (CSRight_R > 80 && CSRight_R < 125 && CSRight_G < 200 && CSRight_G > 155 && CSRight_B > 230)
	{
		colorR = blue_s;
	}
	else if (CSRight_R > 200 && CSRight_R < 225 && CSRight_G < 110 && CSRight_B < 190)
	{
		colorR = purple;
	}
	else
	{
		colorR = none;
	}
}


DLL_EXPORT void Avoid_Wall()
{
	if (flag_US_write == 1)
	{
		if (US_Left > US_Right)
		{
			flag_US_direction = 1;
		}
		else
		{
			flag_US_direction = 0;
		}
	}

	if (US_Left < 14)
	{
		LED_1 = 2;
		WheelLeft = 4;
		WheelRight = -1;

	}
	if (US_Right < 14)
	{
		LED_1 = 2;
		WheelLeft = -1;
		WheelRight = 4;

	}
	if (US_Front > 14)
	{
		flag_US_write = 0;

	}
	if (US_Front < 16)
	{
		flag_US_write = 1;
		if (flag_US_direction == 0)
		{
			LED_1 = 2;
			WheelLeft = -1;
			WheelRight = -4;
		}
		else if (flag_US_direction == 1)
		{
			LED_1 = 2;
			WheelLeft = -4;
			WheelRight = -1;
		}
	}

}


DLL_EXPORT void Avoid_yellow_trap()
{
	if (colorL == yellow_trap)
	{
		move(-3, -5);
		LED_1 = 2;
	}
	else if (colorR == yellow_trap)
	{

		move(-5, -3);
		LED_1 = 2;
	}
	else if (colorL == yellow_trap && colorR == yellow_trap)
	{

		move(-3, -5);
		LED_1 = 2;
	}
}


DLL_EXPORT void find_object(int next_mode)
{
	if (objects <= 7)
	{
		if (black_obj <= 3 && (colorR == black || colorL == black))
		{

			black_obj++;
			objects++;
			LED_1 = 1;
			mode = next_mode;
			flag_test = 0;
		}
		else if (green_obj <= 3 && (colorR == green || colorL == green))
		{

			green_obj++;
			objects++;
			LED_1 = 1;
			mode = next_mode;
			flag_test = 0;
		}
		else if (red_obj <= 3 && (colorR == red || colorL == red))
		{
			red_obj++;
			objects++;
			LED_1 = 1;
			mode = next_mode;
			flag_test = 0;
		}
	}
}


DLL_EXPORT void wait_super_obj(int c, int next_mode)
{
	counter_super_obj_s++;
	if (counter_super_obj_s < c)
	{
		flag_test = 1;
		LED_1 = 1;
		move(0, 0);
	}
	else if (counter_super_obj_s == c)
	{
		move(2, 2);
		mode = next_mode;
		counter_super_obj_s = 0;
	}
}


DLL_EXPORT void wait(int a, int next_mode)
{
	counter_stop++;
	if (counter_stop < a)
	{
		LED_1 = 1;
		move(0, 0);
	}
	else if (counter_stop == a)
	{
		flag_test = 1;
		move(3, 3);
		mode = next_mode;
		counter_stop = 0;
	}
}


DLL_EXPORT void wait_box(int b, int next_mode)
{
	counter_stop_orange++;
	if (counter_stop_orange < b)
	{
		LED_1 = 2;
		move(0, 0);
	}
	else if (counter_stop_orange == b)
	{
		mode = next_mode;
		objects = red_obj = black_obj = green_obj = 0;
		counter_stop_orange = 0;
	}
}


DLL_EXPORT void find_box()
{
	if (objects >= 3)
	{
		if (objects >= 3 && (colorL == orange && colorR == orange))
		{
			LED_1 = 2;
			mode = stop_orange;
		}
		else if (colorL == orange)
		{
			move(3, -1);
		}
		else if (colorR == orange)
		{
			move(-1, 3);
		}
	}
}


DLL_EXPORT void timer_search(int L, int R, int t)
{
	if (counter_timer_search < t)
	{
		move(L, R);
	}
	else if (counter_timer_search < (2 * t) - 1)
	{
		move(R, L);
	}
	else
	{
		counter_timer_search = 0;
	}
	counter_timer_search++;
}


DLL_EXPORT void back_blue_trap()
{
	if (colorR == blue_trap || colorL == blue_trap)
	{
		move(-5, -5);
		objects = black_obj = green_obj = red_obj = 0;
	}
}


DLL_EXPORT void follow_line(int color)
{
	if (colorL == color)
		move(0, 2);
	else if (colorR == color)
		move(2, 0);
	else
		move(3, 1);
}


DLL_EXPORT void follow_wall(int sensor, int fasele, int l, int r)
{
	/////////////  r  ///////
	if (sensor == 0)
	{
		if (US_Right > fasele - 1)
		{
			if (r > l)
				move(r, l);
			else
				move(l, r);
		}
		else if (US_Right < fasele - 1)
		{
			if (r < l)
				move(r, l);
			else
				move(l, r);
		}
		else
		{
			if (r > l)
				move(r, r);
			else
				move(l, l);
		}
	}
	else
	{
		if (US_Left > fasele - 1)
		{
			if (r < l)
				move(r, l);
			else
				move(l, r);
		}
		else if (US_Left < fasele - 1)
		{
			if (r > l)
				move(r, l);
			else
				move(l, r);
		}
		else
		{
			if (r > l)
				move(r, r);
			else
				move(l, l);
		}
	}
}


DLL_EXPORT void follow_angle(int angle)
{
	if (Compass >= angle)
	{
		if (Compass - angle <= 180)
		{
			WheelLeft = 3;
			WheelRight = 1;
		}
		if (Compass - angle > 180)
		{
			WheelLeft = 1;
			WheelRight = 3;
		}
	}
	if (Compass < angle)
	{
		if (angle - Compass <= 180)
		{
			WheelLeft = 1;
			WheelRight = 3;
		}
		if (angle - Compass > 180)
		{
			WheelLeft = 3;
			WheelRight = 1;
		}
	}
	if (Compass > angle - 5 && Compass < angle + 5)
	{
		move(3, 3);
	}
}


DLL_EXPORT void follow_angle_super_obj(int angle)
{
	if (Compass >= angle)
	{
		if (Compass - angle <= 180)
		{
			WheelLeft = 4;
			WheelRight = 2;
		}
		if (Compass - angle > 180)
		{
			WheelLeft = 2;
			WheelRight = 4;
		}
	}
	if (Compass < angle)
	{
		if (angle - Compass <= 180)
		{
			WheelLeft = 2;
			WheelRight = 4;
		}
		if (angle - Compass > 180)
		{
			WheelLeft = 4;
			WheelRight = 2;
		}
	}
	if (Compass > angle - 2 && Compass < angle + 2)
	{
		move(4, 2);
	}
}


DLL_EXPORT void goto_angle(int x, int next_mode)
{
	int ekhtelaf;
	int flag_counter;
	if (Compass > x - 10 && Compass < x + 10)
	{
		counter_goto_angle++;
	}

	if (counter_goto_angle < 10)
	{
		ekhtelaf = Compass - 180;
		ekhtelaf = ekhtelaf - (x - 180);
		if (ekhtelaf < -180) ekhtelaf += 360;
		if (ekhtelaf > 179) ekhtelaf -= 360;
		if (ekhtelaf > 3) ekhtelaf += 20;
		else if (ekhtelaf < -3) ekhtelaf -= 20;
		WheelLeft = (ekhtelaf / 20);
		WheelRight = -(ekhtelaf / 20);
	}
	else
	{
		mode = next_mode;
		counter_goto_angle = 0;
	}
}


DLL_EXPORT void out_side()
{
	if (PositionX >= 23 && PositionX <= 350 && PositionY >= 250 && PositionY <= 263)
	{
		if (Compass >= 0 && Compass <= 90)
		{
			move(3, -1);
		}
		else if (Compass >= 270)
		{
			move(-1, 3);
		}
	}
	if (PositionX >= 5 && PositionX <= 19 && PositionY >= 7 && PositionY <= 251)
	{
		if (Compass > 90 && Compass < 180)
		{
			move(3, -1);
		}
		if (Compass > 0 && Compass < 90)
		{
			move(-1, 3);
		}
	}
	else if (PositionX >= 6 && PositionX <= 350 && PositionY >= 6 && PositionY <= 7)
	{
		if (Compass > 180 && Compass < 270)
		{
			move(3, -1);
		}
		if (Compass > 90 && Compass < 180)
		{
			move(-1, 3);
		}
	}
	else if (PositionX >= 335 && PositionX <= 350 && PositionY >= 12 && PositionY <= 255)
	{
		if (Compass > 270)
		{
			move(3, -1);
		}
		else if (Compass > 180 && Compass < 270)
		{
			move(-1, 3);
		}
	}
}


DLL_EXPORT void Avoid_gray()
{
	if (colorL == gray || colorR == gray)
	{
		move(5, -5);
	}
}


DLL_EXPORT void direction_of()
{


}


DLL_EXPORT  void go_frwrd(int t, int l, int r, int next_mode)
{
	cntr++;
	if (cntr <= t)
	{
		move(l, r);
	}
	else
	{
		mode = next_mode;
		cntr = 0;
	}
}


DLL_EXPORT void follow_angle_y(int x, int y, int end_y)
{
	if (PositionX >= x && PositionY >= y)
	{
		move(4, 2);
	}
	else
	{
		move(2, 4);
	}
}


DLL_EXPORT void follow_angle_x(int x, int y, int end_x, int next_mode)
{
	if ((PositionX >= x || PositionX >= x - 1 || PositionX >= x - 2 || PositionX >= x + 1 || PositionX >= x + 2) && PositionY >= y)
	{
		move(1, 3);
	}
	else
	{
		move(3, 1);
	}
	if (PositionX <= end_x || PositionX <= end_x - 1 || PositionX <= end_x - 2 || PositionX <= end_x - 3 || PositionX <= end_x - 4 || PositionX <= end_x - 5 || PositionX <= end_x || PositionX <= end_x + 1 || PositionX <= end_x + 2 || PositionX <= end_x + 3 || PositionX <= end_x + 4 || PositionX <= end_x + 5)
	{
		mode = next_mode;
	}
}


DLL_EXPORT void follow_angle_xy(int x, int y, int end_x, int end_y, int next_mode)
{
	if (PositionX <= x && PositionY <= y)
	{
		move(3, 1);
	}
	else
	{
		move(1, 3);
	}
	if (x == end_x)
	{
		if (PositionY >= end_y || (PositionY >= end_y - 5 && PositionY >= end_y + 5))
		{
			mode = next_mode;
		}
	}
	if (y == end_y)
	{
		if (PositionX <= end_x || (PositionX >= end_x - 5 && PositionX <= end_x + 5))
		{
			mode = next_mode;
		}
	}
}


DLL_EXPORT void zone(int x, int y, int next_mode)
{
	if ((x - PositionX) == 0)
	{
		if ((y - PositionY) > 0)
			p = 180;
		if ((y - PositionY) < 0)
			p = 0;
	}
	else
	{
		ton = (y - PositionY) / (x - PositionX);
		ark_ton = atan(ton);
		ark_ton_int_p = (ark_ton * 180) / PI;
		if ((x - PositionX)> 0)
			p = 270 + ark_ton_int_p;
		else if ((x - PositionX)< 0)
			p = 90 + ark_ton_int_p;
	}
	if (((PositionX <= (x + 3) && PositionX >= x - 3)) && (PositionY <= (y + 3) && PositionY >= (y - 3)))
	{
		mode = next_mode;
	}
}


DLL_EXPORT void get_super_obj()
{

	zone(super_x, super_y, stop_super_obj);
	follow_angle_super_obj(p);
}


DLL_EXPORT void find_super()
{
	if (colorL == super_obj || colorR == super_obj)
	{
		LED_1 = 1;
		mode = stop_super_obj;
	}
}


DLL_EXPORT void zone_ary(int x, int y)
{
	zone_ary(x, y);
	if (((PositionX <= (x + 5) && PositionX >= x - 5)) && (PositionY <= (y + 5) && PositionY >= (y - 5)))
	{
		i++;
	}
}


DLL_EXPORT void find_direction()
{
	if (Compass<315 && Compass>225)
	{
		direction = 1;
	}
	else if (Compass<225 && Compass>135)
	{
		direction = 2;
	}
	else if (Compass<135 && Compass>45)
	{
		direction = 3;
	}
	else
	{
		direction = 4;
	}
}


DLL_EXPORT void Traps_1()
{
	number_trap = 2;
	i_trap = 0;
	X_max[0] = 130;
	Y_max[0] = 76;
	X_min[0] = 85;
	Y_min[0] = 96;
	//////////////////////////////////////1
	X_max[1] = 127;
	Y_max[1] = 163;
	X_min[1] = 83;
	Y_min[1] = 133;
	//////////////////////////////////////2
	X_max[2] = 352;
	Y_max[2] = 142;
	X_min[2] = 325;
	Y_min[2] = 176;
	while (i_trap <= number_trap)
	{
		if ((PositionX <= X_max[i_trap] && PositionX >= X_min[i_trap]) && (PositionY <= (Y_max[i_trap] + 14) && PositionY >= Y_max[i_trap]))
		{

			if (Compass >= 90 && Compass <= 180)
			{
				move(2, 5);
			}
			else if (Compass >= 180 && Compass <= 270)
			{
				move(5, 2);
			}
		}
		else if ((PositionX <= (X_max[i_trap] + 14) && PositionX >= X_max[i_trap]) && (PositionY <= Y_max[i_trap] && PositionY >= Y_min[i_trap]))
		{

			if (Compass >= 0 && Compass <= 90)
			{
				move(2, 5);
			}
			else if (Compass >= 90 && Compass <= 180)
			{
				move(5, 2);
			}
		}
		else if ((PositionX < X_max[i_trap] && PositionX > X_min[i_trap]) && (PositionY > (Y_min[i_trap] - 14) && PositionY <= Y_min[i_trap]))
		{

			if (Compass >= 270)
			{
				move(2, 5);
			}
			else if (Compass <= 90)
			{
				move(5, 2);
			}
		}
		else if ((PositionX >= (X_min[i_trap] - 14) && PositionX <= X_min[i_trap]) && (PositionY > Y_min[i_trap] && PositionY < Y_max[i_trap]))
		{

			if (Compass >= 270)
			{
				move(5, 2);
			}
			else if (Compass >= 180 && Compass <= 270)
			{
				move(2, 5);
			}
		}
		i_trap++;
	}
}


DLL_EXPORT void back_gray()
{
	number_gray = 1;
	i_gray = 0;

	x_suop_max[0] = 99;
	y_suop_max[0] = 210;
	x_suop_min[0] = 60;
	y_suop_min[0] = 188;

	//////////////////////////////////////////1

	x_suop_max[1] = 322;
	y_suop_max[1] = 87;
	x_suop_min[1] = 172;
	y_suop_min[1] = 7;

	while (i_gray <= number_gray)
	{
		if ((PositionX <= x_suop_max[i_gray] && PositionX >= x_suop_min[i_gray]) && (PositionY <= (y_suop_max[i_gray] + 20) && PositionY >= y_suop_max[i_gray]))
		{

			if (Compass >= 90 && Compass <= 180)
			{
				move(1, 5);
			}
			else if (Compass >= 180 && Compass <= 270)
			{
				move(5, 1);
			}
		}
		else if ((PositionX <= (x_suop_max[i_gray] + 20) && PositionX >= x_suop_max[i_gray]) && (PositionY <= y_suop_max[i_gray] && PositionY >= y_suop_min[i_gray]))
		{

			if (Compass >= 0 && Compass <= 90)
			{
				move(1, 5);
			}
			else if (Compass >= 90 && Compass <= 180)
			{
				move(5, 1);
			}
		}
		else if ((PositionX < x_suop_max[i_gray] && PositionX > x_suop_min[i_gray]) && (PositionY > (y_suop_min[i_gray] - 20) && PositionY <= y_suop_min[i_gray]))
		{

			if (Compass >= 270)
			{
				move(1, 5);
			}
			else if (Compass <= 90)
			{
				move(5, 1);
			}
		}
		else if ((PositionX >= (x_suop_min[i_gray] - 20) && PositionX <= x_suop_min[i_gray]) && (PositionY > y_suop_min[i_gray] && PositionY < y_suop_max[i_gray]))
		{

			if (Compass >= 270)
			{
				move(5, 1);
			}
			else if (Compass >= 180 && Compass <= 270)
			{
				move(1, 5);
			}
		}
		i_gray++;
	}
}


DLL_EXPORT void avoid_purple()
{
	if (colorR == purple && colorL == purple)
	{
		move(-5, -3);
	}

	else if (colorL == purple)
	{
		move(-1, -3);
	}
	if (colorR == purple && colorL == purple)
	{
		move(-5, -3);
	}
	else if (colorR == purple)
	{
		move(-3, 1);
	}
	if (colorR == purple && colorL == purple)
	{
		move(-5, -3);
	}

}


void Game0()
{


	find_color();
	back_blue_trap();

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////My Code
	if (mode == start)
	{
		mode = search;
	}
	else if (mode == search)
	{
		LED_1 = 0;
		move(4, 4);
		Avoid_Wall();
		Avoid_yellow_trap();
		find_object(stop_obj);
		if (objects == 6 && flag_test == 1)
		{
			mode = end_get_obj;
		}
	}
	else if (mode == special_search)
	{
		LED_1 = 0;
		move(4, 4);
		if (colorL == none)
		{
			move(-4, -1);
		}
		else if (colorR == none)
		{
			move(-1, -4);
		}
		Avoid_Wall();
		Avoid_yellow_trap();
		find_object(stop_obj_special);
		if (objects == 6 && flag_test == 1)
		{
			mode = end_get_obj_special;
		}
	}
	else if (mode == stop_obj_special)
	{
		wait(50, special_search);
	}
	else if (mode == end_get_obj_special)
	{

		follow_angle(45);
		Avoid_Wall();
		Avoid_yellow_trap();
		if (colorL == orange && colorR == orange)
		{
			mode = stop_orange_special;
		}
		else if (colorL == orange)
		{
			move(4, 1);
		}
		else if (colorR == orange)
		{
			move(1, 4);
		}

	}
	else if (mode == stop_orange_special)
	{
		wait_box(60, special_search);
	}
	else if (mode == end_get_obj)
	{
		follow_angle(45);
		Avoid_Wall();
		Avoid_yellow_trap();
		if (colorL == orange && colorR == orange)
		{
			mode = stop_orange;
		}
		else if (colorL == orange)
		{
			move(4, 1);
		}
		else if (colorR == orange)
		{
			move(1, 4);
		}
	}


	else if (mode == stop_obj)
	{
		wait(50, change_mode);////////////////////////////////////for object
	}
	else if (mode == stop_orange)
	{
		wait_box(67, change_mode_box);///////////////////////////////for box
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////next modes


	if (mode == change_mode)////////////////////////////////////for object
	{
		mode = search;
	}
	else if (mode == change_mode_box)//////////////////////////for box
	{
		objects = black_obj = red_obj = green_obj = 0;
		mode = search;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////// teleport


	if ((Time >= 190 && objects <= 2 && (colorL != orange && colorR != orange)))
	{
		objects = LED_1 = red_obj = black_obj = green_obj = 0;
		mode = start_1_1;
		Teleport = 1;
	}
}


void Game1()
{
	find_color();
	out_side();
	if (SuperObj_X != 0 && SuperObj_Y != 0)
	{
		super_x = SuperObj_X;
		super_y = SuperObj_Y;
		mode = start_get_super_obj;
	}
	//////////////////////////////////////////////////////////////My Code


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////my code
	if (mode == start_1_1)
	{
		mode = search;
	}
	else if (mode == search)
	{
		LED_1 = 0;
		move(3, 3);
		Avoid_Wall();
		Avoid_yellow_trap();
		out_side();
		find_object(stop_obj);
		find_box();
		if (objects == 6 && flag_test == 1)
		{
			mode = end_get_obj;
		}
	}
	else if (mode == special_search)
	{
		LED_1 = 0;
		move(4, 4);
		if (colorL == none)
		{
			move(-4, -1);
		}
		else if (colorR == none)
		{
			move(-1, -4);
		}
		Avoid_Wall();
		Avoid_yellow_trap();
		find_object(stop_obj_special);
		if (objects == 6 && flag_test == 1)
		{
			mode = end_get_obj_special;
		}
	}
	else if (mode == stop_obj_special)
	{
		wait(50, special_search);
	}
	else if (mode == end_get_obj_special)
	{

		follow_angle(45);
		Avoid_Wall();
		Avoid_yellow_trap();
		if (colorL == orange && colorR == orange)
		{
			mode = stop_orange_special;
		}
		else if (colorL == orange)
		{
			move(4, 1);
		}
		else if (colorR == orange)
		{
			move(1, 4);
		}

	}
	else if (mode == stop_orange_special)
	{
		wait_box(60, special_search);
	}
	else if (mode == start_get_super_obj)
	{
		zone(super_x, super_y, get_super_obj_1);
		follow_angle(p);
		Avoid_Wall();
		Avoid_yellow_trap();
		out_side();
	}
	else if (mode == get_super_obj_1)
	{
		LED_1 = 1;
		wait_super_obj(50, super_obj_change_mode);
	}
	else if (mode == end_get_obj)
	{
		LED_1 = 2;
		zone(314, 186, stop_orange);
		follow_angle(p);
		out_side();
		Avoid_Wall();
		Avoid_yellow_trap();
		if (colorL == orange && colorR == orange)
		{
			mode = stop_orange;
		}
		if (colorL == orange)
		{
			move(4, 1);
		}
		else if (colorR == orange)
		{
			move(1, 4);
		}
	}
	else if (mode == stop_obj)
	{
		wait(50, change_mode);
	}
	else if (mode == stop_orange)
	{
		wait_box(65, change_mode_box);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////next modes
	if (mode == change_mode)
	{
		mode = start_1_1;
	}
	else if (mode == change_mode_box)
	{
		mode = start_1_1;
	}
	else if (mode == super_obj_change_mode)
	{
		mode = end_get_obj;
	}
}


DLL_EXPORT void OnTimer()
{
	switch (CurGame)
	{
	case 9:
		break;
	case 10:
		WheelLeft = 0;
		WheelRight = 0;
		LED_1 = 0;
		MyState = 0;
		break;
	case 0:
		Game0();
		break;
	case 1:
		Game1();
		break;
	default:
		break;
	}
}
