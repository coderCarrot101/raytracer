/*#include <SDL3/SDL.h>
#include <iostream>



int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    //string = << "P3\n" << image_width << ' ' << image_height
    //live_render(string)
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std::cout, pixel_color);
            //also write to the function
        }
    }

    std::clog << "\rDone.                 \n";
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << SDL_GetError() << "\n";
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "SDL3 Window",
        800, 600,
        SDL_WINDOW_RESIZABLE
    ); 

    SDL_Delay(2000);
    std::clog << "RAN!";

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}*/
#include <SDL3/SDL.h>
#include <iostream>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "SDL3 Test Window",
        800, 600,
        SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        SDL_Delay(16); // ~60 FPS idle
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
