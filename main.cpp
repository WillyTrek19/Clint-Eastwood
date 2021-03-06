#include "Game.h"

int main(int argc, char* argv[]) {
	Game game;						//Inicializa la class Game
	if (!game.Init()) return -1;	//Ejecuta game.Init(que es un bool)
									//Si hay alguna parte que no funciona, devuelve false y crashea

	bool quit = false;
	if (game.introScreen()) {		//La intro es una funci�n bool. Si devuelve true, significa que la intro se ha cargado correctamente y empieza el loop.
									//Sino cierra el juego entero
		while (!quit)
		{

			quit = game.Update();		//Hace los inputs del juego
			if (!game.intro) { 
				game.Logic();			//Hace la l�gica del juego
				game.Scoreboard();      //Hace la scoreboard
				game.Render(); }		//Hace el render
			if (game.win)
			{
				quit = true;
			}
			SDL_Delay(10);
			
		}
	}
	game.CleanUp();						//Cierra todo
	return 0;
}