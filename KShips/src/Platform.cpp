#include "Platform.h"

Platform* Platform::ptr;

Platform::Platform()
{

}

Platform* Platform::GetPtr()
{
	if (ptr == nullptr)
	{
		ptr = new Platform();
	}
	return ptr;
}

bool Platform::Init(int width, int heigth)
{
	//Initialization flag
	bool success = true;
	this->width = width;
	this->heigth = heigth;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, heigth, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0x64, 0x6F, 0xCE, 0xFF);
			}
		}
	}
	return success;
}

void Platform::Close()
{
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	SDL_Quit();
}

void Platform::RenderClear()
{
	SDL_SetRenderDrawColor(gRenderer, 0x64, 0x6F, 0xCE, 0xFF);
	SDL_RenderClear(gRenderer);
}

void Platform::RenderPresent()
{
	SDL_RenderPresent(gRenderer);
}

void Platform::Input(GameState* obj, bool (GameState::* f)(int))
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{
			(obj->*f)(e.key.keysym.sym); // https://www.geeksforgeeks.org/callbacks-in-c/
		}
	}
}

SDL_Renderer* Platform::GetRenderer()
{
	return gRenderer;
}

void Platform::RenderTexture(Image* tex, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(tex->GetTexture(), NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(gRenderer, tex->GetTexture(), NULL, &dst);
}

/*
C++ Lenguaje orientado a Objetos
C++ es compatible con C
Bjarne Stroustrup c++, creador
Compilado(Rapido) depende de la plataforma en la cual fue compilado

3.1. CLASES
class Player
{
	public:
		
	private:

	protected;
};
Conjunto de atributos y metodos, que pueden ser publicos, privados, protejidos 
public : se pueden invocar desde cual parte del programa
private : solo se pueden invocar dentro la clase
protected : se heredan como metodos o atributos privados, se pueden invocar solamente dentro la clase.


CLASES ABSTRACTAS

class Player
{
	public:
		void Draw() = 0;
};



3.3. ATRIBUTOS
Es similar a variable, que puede publica, privada o protegida. Almacena una caractetistica.
3.4. MÉTODOS
Es similiar a una funcion, que puede publica, privada o protegida. Ejecuta una Accion.
3.6. ENCAPSULACIÓN
Es importante mantener los atributos como privados para que la clase administre y valide, cada uno de
sus atributos, permitiendo un mejor control de los atributos tanto en lectura como escritura.

tipo NameClass::GetAtributo()
{
	return atributo;
}

void NameClass::SetAtributo(tipo v)
{
	atributo = v;
}
3.7. HERENCIA
Una clase base es aquella clase que es basica o elemental que describe objetos muy generales
estas clases usualmente aportar caracteristicas y acciones a clases mas especificas, permitiendo 
REUTILIZAR estas caracteristicas de las clases base.

class Player : public GameObject
{


};

Solo se heredan los atributos y metodos, publicos y protected.
C++ permite herencia multiple, NO LO HAGAN!!!!!


3.8. POLIMORFISMO

Una varibale puede comportarse como su clase base, permitiendo usar una clase como dos distintas clases.


class Player : public GameObject
{


};

Dos Ejercicio de programa

*/