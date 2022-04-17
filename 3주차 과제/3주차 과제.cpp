#include <bangtal.h>

// 기본적으로 장면이랑 물체 정의하기

SceneID scene1, scene2, scene3, scene4, scene5, scene6, scene7, scene8, scene9, scene10;
ObjectID rightdoor1, rightdoor2, leftdoor1, leftdoor2, Rdoor1, Rdoor2, Rdoor3, Ldoor1, Ldoor2, Ldoor3, alreadydoor1, smalldoor1;
ObjectID keypad1, keypad2, keypad3, keypad4, keypad5, keypad6;
ObjectID key1, picture1, picture2, picture3, picture4, picture5;
ObjectID flower1, flower2, flower3, flower4, flower5, flower6;


bool locked1 = true, locked2 = true, locked3 = true, locked4 = true, locked5 = true, locked6 = true;

// 사용자 지정 함수 1 (크기를 변경하지 않는 물체)

ObjectID FastCreateObject(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown) {
		showObject(object);
	}

	return object;
}

// 사용자 지정 함수 2 (방 들어갈때 메세지 보여야함)

void ENTERENTER(SceneID scene, const char* message) {
	enterScene(scene);
	showMessage(message);
}

// 사용자 지정 함수 3 (키패드 함수에서 사용)
ObjectID niceanswer(ObjectID object, const char* changeimage, const char* message) {
	setObjectImage(object, changeimage);
	showMessage(message);

	return 0;
}

// 사용자 지정 함수 4 (9번방에서 사용)

ObjectID notrightimage(ObjectID object, SceneID scene, const char* message) {
	hideObject(object);
	enterScene(scene);
	showMessage(message);

	return 0;
}

// 사용자 지정 함수 5 (크기를 줄이거나 늘리기 위해 float 사용)

ObjectID Objectsize(const char* image, SceneID scene, float size, int x, int y) {
	ObjectID object = createObject(image);
	scaleObject(object, size);
	locateObject(object, scene, x, y);
	showObject(object);

	return object;
}

void swap(bool& a) {
	a = a ? false : true;
}


// 마우스 클릭 함수

bool closed1 = true, closed2 = true, closed3 = true, closed4 = true, closed5 = true;

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {

	// 1번방

	if (object == rightdoor1) {
		if (closed1 == true) {
			setObjectImage(rightdoor1, "rightopendoor.png");

			swap(closed1);
		//	closed1 = false;
		}

		else {
			ENTERENTER(scene2, "7989 + 5444 - 89 + 444 - 888");
		}
	}

	if (object == leftdoor1) {
		if (closed2 == true) {
			setObjectImage(leftdoor1, "leftopendoor.png");
			closed2 = false;
		}

		else {
			ENTERENTER(scene5, "한일합병이 일어난 년도는?");
		}
	}



	//Rdoor1

	if (object == Rdoor1) {
		if (locked1 == true) {
			showMessage("7989 + 5444 - 89 + 444 - 888");
		}

		else {
			ENTERENTER(scene3, "(x+1)^3 = 64일때, x의 값은?");
		}
	}

	if (object == keypad1) {
		showKeypad("14900", Rdoor1);
	}

	// Rdoor2

	if (object == Rdoor2) {
		if (locked2 == true) {
			showMessage("(x+1)^3 = 64일때, x의 값은?");
		}

		else {
			ENTERENTER(scene4, "x^2-2x=195일때, 양수 x의 값은?");
		}
	}

	if (object == keypad2) {
		showKeypad("3", Rdoor2);
	}

	// Rdoor3

	if (object == Rdoor3) {
		if (locked3 == true) {
			showMessage("x^2-2x=195일때, 양수 x의 값은?");
		}

		else {
			ENTERENTER(scene8, "진짜 열쇠를 찾아 탈출하세요!");
		}
	}

	if (object == keypad3) {
		showKeypad("15", Rdoor3);
	}

	// Ldoor1

	if (object == Ldoor1) {
		if (locked4 == true) {
			showMessage("한일합병이 일어난 년도는?");
		}

		else {
			ENTERENTER(scene6, "6.25전쟁이 종료된 년도는?");
		}
	}

	if (object == keypad4) {
		showKeypad("1910", Ldoor1);
	}

	// Ldoor2

	if (object == Ldoor2) {
		if (locked5 == true) {
			showMessage("6.25전쟁이 종료된 년도는?");
		}

		else {
			ENTERENTER(scene7, "임진왜란이 일어난 년도는?");
		}
	}

	if (object == keypad5) {
		showKeypad("1953", Ldoor2);

	}

	// Ldoor3

	if (object == Ldoor3) {
		if (locked6 == true) {
			showMessage("임진왜란이 일어난 년도는?");
		}

		else {
			ENTERENTER(scene8, "진짜 열쇠를 찾아 탈출하세요!");
		}
	}

	if (object == keypad6) {
		showKeypad("1592", Ldoor3);
	}

	// rightdoor2

	if (object == rightdoor2) {
		if (closed3 == true) {
			setObjectImage(rightdoor2, "rightopendoor.png");
			closed3 = false;
		}

		else {
			ENTERENTER(scene9, "그림 뒤에 숨어있는 열쇠를 찾으세요!");
		}
	}

	//9번방

	if (object == alreadydoor1) {
			enterScene(scene8);
	}

	if (object == picture1) {
		hideObject(picture1);
	}

	if (object == picture2) {
		notrightimage(picture2, scene8, "오답입니다. 다시 시도해 주세요");
	}

	if (object == picture3) {
		notrightimage(picture3, scene8, "오답입니다. 다시 시도해 주세요");
	}

	if (object == picture4) {
		notrightimage(picture4, scene8, "오답입니다. 다시 시도해 주세요");
	}

	if (object == picture5) {
		notrightimage(picture5, scene8, "오답입니다. 다시 시도해 주세요");
	}

	if (object == key1) {
		pickObject(key1);
	}

	//leftdoor2

	if (object == leftdoor2) {
		if (closed4 == true) {
			if (getHandObject() == key1) {
				setObjectImage(leftdoor2, "leftopendoor.png");
				closed4 = false;
			}

			else {
				showMessage("오른쪽 방에 가서 열쇠를 구하십시오");
			}
		}

		else{
			ENTERENTER(scene10, "축하합니다 당신은 탈출에 성공하셨습니다!");
			
		}
	}

	//10번방

	if (object == smalldoor1) {
		if (closed5 == true) {
			setObjectImage(smalldoor1, "leftopendoor.png");
			closed5 = false;
		}

		else {
			endGame();
		}
	}

}

//키패드함수



void objectCallback(ObjectID object, EventID event) {
	if (object == Rdoor1 && event == EventID:: EVENT_KEYPAD) {
		locked1 = false;
		niceanswer(Rdoor1, "rightopendoor.png", "정답");
		}
	if (object == Rdoor2 && event == EventID::EVENT_KEYPAD) {
		locked2 = false;
		niceanswer(Rdoor2, "leftopendoor.png", "정답");
	}
	if (object == Rdoor3 && event == EventID::EVENT_KEYPAD) {
		locked3 = false;
		niceanswer(Rdoor3, "leftopendoor.png", "정답");
	}
	if (object == Ldoor1 && event == EventID::EVENT_KEYPAD) {
		locked4 = false;
		niceanswer(Ldoor1, "leftopendoor.png", "정답");
	}
	if (object == Ldoor2 && event == EventID::EVENT_KEYPAD) {
		locked5 = false;
		niceanswer(Ldoor2, "rightopendoor.png", "정답");
	}
	if (object == Ldoor3 && event == EventID::EVENT_KEYPAD) {
		locked6 = false;
		niceanswer(Ldoor3, "rightopendoor.png", "정답");
	}

}

void setupScene1() {
}


// main 함수 

int main() {

	//콜백함수 

	setMouseCallback(mouseCallback);
	setObjectCallback(objectCallback);

	setupScene1();

	//장면 생성

	scene1 = createScene("scene1", "background-1.png");
	scene2 = createScene("scene2", "background-2.png");
	scene3 = createScene("scene3", "background-2.png");
	scene4 = createScene("scene4", "background-2.png");
	scene5 = createScene("scene5", "background-2.png");
	scene6 = createScene("scene6", "background-2.png");
	scene7 = createScene("scene7", "background-2.png");
	scene8 = createScene("scene8", "background-1.png");
	scene9 = createScene("scene9", "background-2.png");
	scene10 = createScene("scene10", "background-2.png");

	//문 생성

	rightdoor1 = FastCreateObject("rightcloseddoor.png", scene1, 800, 270, true);
	rightdoor2 = FastCreateObject("rightcloseddoor.png", scene8, 800, 270, true);
	leftdoor1 = FastCreateObject("leftcloseddoor.png", scene1, 300, 295, true);
	leftdoor2 = FastCreateObject("leftcloseddoor.png", scene8, 300, 295, true);
	Rdoor1 = FastCreateObject("rightcloseddoor.png", scene2, 800, 290, true);
	Rdoor2 = FastCreateObject("leftcloseddoor.png", scene3, 300, 265, true);
	Rdoor3 = FastCreateObject("leftcloseddoor.png", scene4, 300, 265, true);
	Ldoor1 = FastCreateObject("leftcloseddoor.png", scene5, 300, 265, true);
	Ldoor2 = FastCreateObject("rightcloseddoor.png", scene6, 800, 290, true);
	Ldoor3 = FastCreateObject("rightcloseddoor.png", scene7, 800, 290, true);
	alreadydoor1 = FastCreateObject("leftopendoor.png", scene9, 300, 265, true);
	smalldoor1 = Objectsize("leftcloseddoor.png", scene10, 0.05f, 100, 230);
	
	//키패드 생성

	keypad1 = Objectsize("keypad.png", scene2, 3, 750, 375);
	keypad2 = Objectsize("keypad.png", scene3, 3, 200, 375);
	keypad3 = Objectsize("keypad.png", scene4, 3, 200, 375);
	keypad4 = Objectsize("keypad.png", scene5, 3, 200, 375);
	keypad5 = Objectsize("keypad.png", scene6, 3, 750, 375);
	keypad6 = Objectsize("keypad.png", scene7, 3, 750, 375);

	//9번방 생성

	key1 = Objectsize("key1.png", scene9, 0.2f, 200, 500);
	picture1 = Objectsize("rain.jpg", scene9, 0.15f, 200, 500);
	picture2 = Objectsize("BOOGUM.jpg", scene9, 0.2f, 600, 500);
	picture3 = Objectsize("SHINYEAUN.jpg", scene9, 0.2f, 750, 40);
	picture4 = Objectsize("UAIN.jpg", scene9, 0.2f, 950, 400);
	picture5 = Objectsize("IU.jpg", scene9, 0.2f, 100, 10);

	//구조물 생성

	flower1 = FastCreateObject("flower.png", scene2, 900, 30, true);
	flower2 = FastCreateObject("flower.png", scene3, 700, 30, true);
	flower3 = FastCreateObject("flower.png", scene4, 900, 20, true);
	flower4 = FastCreateObject("flower.png", scene5, 900, 30, true);
	flower5 = FastCreateObject("flower.png", scene6, 700, 30, true);
	flower6 = FastCreateObject("flower.png", scene7, 900, 20, true);

	//시작 

	showMessage("오른쪽 문은 수학, 왼쪽 문은 역사 퀴즈입니다");
	startGame(scene1);


}