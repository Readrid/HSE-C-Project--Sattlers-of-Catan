#include <SDL2/SDL.h>
#include <iostream>
#include <random>
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

int main (int argc, char ** args) {

	SDL_DisplayMode displayMode;

    if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
    {
        return 1;
    }

    SDL_GetDesktopDisplayMode(0,&displayMode);

    SDL_Window *win = SDL_CreateWindow("Hello World!", 0, 0, displayMode.w, displayMode.h, SDL_WINDOW_SHOWN);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}



	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}    


	SDL_Surface *BMP_background = SDL_LoadBMP("image/back_ground.bmp");
	if (BMP_background == nullptr){
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Texture *back_ground = SDL_CreateTextureFromSurface(ren, BMP_background);
	SDL_FreeSurface(BMP_background); //Очищение памяти поверхности
	if (back_ground == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return 1;
	}/*

	SDL_Surface *BMP_player = SDL_LoadBMP("oct.bmp");
	if (BMP_player == nullptr){
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Texture *player = SDL_CreateTextureFromSurface(ren, BMP_player);
	SDL_FreeSurface(BMP_player); //Очищение памяти поверхности
	if (player == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return 1;
	}


	SDL_Surface *BMP_player1 = SDL_LoadBMP("oct1.bmp");
	if (BMP_player1 == nullptr){
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Texture *player1 = SDL_CreateTextureFromSurface(ren, BMP_player1);
	SDL_FreeSurface(BMP_player1); //Очищение памяти поверхности
	if (player1 == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return 1;
	}
*/
	SDL_Texture* arr[6];

	std::string s = "image/oct .bmp";
	for (int i = 0; i < 6; ++i) {
		s[9] = i + '0';
		SDL_Surface *BMP_player1 = SDL_LoadBMP(s.c_str());
		if (BMP_player1 == nullptr){
			std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
			return 1;
		}

		SDL_Texture *player1 = SDL_CreateTextureFromSurface(ren, BMP_player1);
		SDL_FreeSurface(BMP_player1); //Очищение памяти поверхности
		if (player1 == nullptr){
			std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			return 1;
		}
		arr[i] = player1;
	}

	SDL_Surface *BMP_road = SDL_LoadBMP("image/road.bmp");
	if (BMP_road == nullptr){
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	



	SDL_Surface *BMP_road1 = SDL_LoadBMP("image/road1.bmp");
	if (BMP_road1 == nullptr){
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Texture *road1 = SDL_CreateTextureFromSurface(ren, BMP_road1);
	SDL_FreeSurface(BMP_road1); //Очищение памяти поверхности
	if (road1 == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return 1;
	}


	SDL_Surface *BMP_road2 = SDL_LoadBMP("image/road2.bmp");
	if (BMP_road2 == nullptr){
		std::cout << "SDL_LoadBMP Error: " <<SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Texture *road2 = SDL_CreateTextureFromSurface(ren, BMP_road2);
	SDL_FreeSurface(BMP_road2); //Очищение памяти поверхности
	if (road2 == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Texture *road = SDL_CreateTextureFromSurface(ren, BMP_road);
	SDL_FreeSurface(BMP_road); //Очищение памяти поверхности
	if (road == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Surface *BMP_back = SDL_LoadBMP("image/back.bmp");
	if (BMP_back == nullptr){
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Texture *back = SDL_CreateTextureFromSurface(ren, BMP_back);
	SDL_FreeSurface(BMP_back); //Очищение памяти поверхности
	if (back == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return 1;
	}






	SDL_RenderClear(ren); //Очистка рендера
	SDL_Rect dest1;
		dest1.x = 0;
		dest1.y = 0;
		dest1.w = displayMode.w;
		dest1.h = displayMode.h;
	SDL_RenderCopy(ren,back_ground,NULL,&dest1); //Копируем в рендер фон

		dest1.x = 0;
		dest1.y = 0;
		dest1.w = displayMode.w;
		dest1.h = displayMode.h;
	SDL_RenderCopy(ren,back,NULL,&dest1); //Копируем в рендер фон

	SDL_Rect dest;
	dest.x = displayMode.w / 2 - 250*sqrt(3);
	dest.y = displayMode.h / 2 - 550;
	dest.w = 100*sqrt(3);
	dest.h = 200;
	int k = 3;
	for (int i = 0; i < 5; ++i){
		dest.y += 150;
		for (int i = 0; i < k; ++i){
			dest.x += 100*sqrt(3);
			SDL_RenderCopy(ren, arr[rand() % 6], NULL, &dest); //Копируем в рендер персонажа
		}
		dest.x-= 100*sqrt(3)*k;
		if (i < 2) {k+=1;dest.x-= 50*sqrt(3);}
		else {k-=1;dest.x+= 50*sqrt(3);}
	}


	
	
			// Структура события
	SDL_Event e;
	

	// Флаг выхода
	bool quit = false;
    // Отображение сцены
    SDL_RenderPresent(ren); //Погнали!!
	while (!quit)
	{
		// Обработка событий
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			/*if (e.type == SDL_KEYDOWN)
			{
				quit = true;
			}*/
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
                // Отображение сцены
                SDL_RenderPresent(ren); //Погнали!!
		        int x, y;
		        SDL_GetMouseState(&x, &y); // Получить координаты мыши
		        std::cout << x << ' ' << y << '\n';
		        for (int i = 0; i < 5; ++i){
		        	int a = 0;
		        	int b = 11;
		        	if (i == 0) {a = 1; b = 10;}
		        	if (i == 4) {a = 1; b = 10;}
		        	for (int j = a; j < b; ++j){
		        		if ((i+j) % 2 != 0) continue;
				        if (x > 487+ j*50*sqrt(3) && x <  515+j*50*sqrt(3) && y > 199 + 3*i*50 && y < 294 + 3*i*50) {
				        	dest.x = 460 + j*50*sqrt(3);
							dest.y = 150 + 50 + 3*i*50;
							dest.w = 80;//60
							dest.h = 100;//100
							SDL_RenderCopy(ren, road, NULL, &dest); //Копируем в рендер персонажа
							break;
						}
			        }
			    }



			    for (int i = 0; i < 6; ++i){
		        	int a = 0;
		        	int b = 10;
		        	if (i == 0) {a = 2; b = 8;}
		        	if (i == 1) {a = 1; b = 9;}
		        	if (i == 5) {a = 2; b = 8;}
		        	if (i == 4) {a = 1; b = 9;}
		        	for (int j = a; j < b; ++j){
		        		if ((i+j) % 2 == 0) {
				        if (x > 499+ j*50*sqrt(3) && x <  570+j*50*sqrt(3) && y > 160 + 3*i*50 && y < 195 + 3*i*50) {
				        	dest.x = 500 + j*50*sqrt(3);//470 + 2*100*sqrt(3);
							dest.y = 140 + 3*i*50;//150 + 50;
							dest.w = 50*sqrt(3);//60
							dest.h = 80;//100
							SDL_RenderCopy(ren, road1, NULL, &dest); //Копируем в рендер персонажа
							break;
						}}
						else {
							if (x > 499+ j*50*sqrt(3) && x <  570+j*50*sqrt(3) && y > 160 + 3*i*50 && y < 195 + 3*i*50) {
				        	dest.x = 500 + j*50*sqrt(3);//470 + 2*100*sqrt(3);
							dest.y = 140 + 3*i*50;//150 + 50;
							dest.w = 50*sqrt(3);//60
							dest.h = 80;//100
							SDL_RenderCopy(ren, road2, NULL, &dest); //Копируем в рендер персонажа
							break;
						}
						}
			        }
			    }

	     	}
		}


	}

    //SDL_Delay(2000);
	std::cout << 41.0/60.0;
    //SDL_DestroyTexture(player);
    SDL_DestroyTexture(road);
    SDL_DestroyTexture(road1);
    SDL_DestroyTexture(road2);
	SDL_DestroyTexture(back_ground);
	SDL_DestroyTexture(back);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();		
    return 0;
};
