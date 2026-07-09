




// Butano libraries
#include "bn_core.h"
#include "bn_display.h"
#include "bn_keypad.h"
#include "bn_sprite_text_generator.h"
#include "bn_bg_palettes.h"

#include "common_info.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_regular_bg_ptr.h"

#include "bn_sprite_items_sword.h"
#include "bn_regular_bg_items_stage1.h"
#include "common_variable_8x8_sprite_font.h"
#include "bn_sprite_items_man.h"       //sprite header files






int happyman = 3; // small global variables which need initiating 
int druggedupman = 2;
int normalman = 0;
int knifeman = 1;
namespace
{ 

  
  void positioningsprite_scene(bn::sprite_text_generator& text_generator)
    {
        constexpr bn::string_view info_text_lines[] = {
        "CAVE ESCAPE : PRESS START to START GAME "
        };
        bn::vector<bn::sprite_ptr, 32> text_sprites;
        text_generator.generate(-120, -60 , info_text_lines[0], text_sprites);
        bn::bg_palettes::set_transparent_color(bn::color(16, 16, 16));
        

        bn::sprite_ptr man = bn::sprite_items::man.create_sprite(0, 0);
        man.set_tiles(bn::sprite_items::man.tiles_item().create_tiles(normalman));
        bn::optional<bn::sprite_ptr> sword = bn::sprite_items::sword.create_sprite(0, 20);
        while(! bn::keypad::start_pressed())
        {

            // this is the test stage code, whenever we must implement a new sprite or mechanic we must refer to here and test any issues 
            // within the implementation
            // ...............................................
            //  here is keypad testing
            if(bn::keypad::left_held())
            {
                man.set_x(man.x() - 1);     //move him by 1 pixel in all directions. 
            }
            else if(bn::keypad::right_held())
            {
                man.set_x(man.x() + 1);
            }   

            if(bn::keypad::up_held())
            {
                man.set_y(man.y() - 1);
            }
            else if(bn::keypad::down_held())
            {
                man.set_y(man.y() + 1);
            }

            //this here is object testing, whenever an object needs to be seen for itself we must check whether the object functions as intended
            if(sword.has_value() && ( (sword->x() - 8) < man.x() && man.x() < (sword->x() + 8)) && ( (sword->y() - 8) < man.y() && man.y() < (sword->y() + 8))){
               sword.reset();
               man.set_tiles(bn::sprite_items::man.tiles_item().create_tiles(1));
            }


            bn::core::update();

      } 
    }
    void stage1(bn::sprite_text_generator& text_generator){
        
    constexpr bn::string_view info_text_lines[] = {
        "You fell, now save yourself."
    };
      bn::sprite_ptr man = bn::sprite_items::man.create_sprite(0, 0);
      man.set_tiles(bn::sprite_items::man.tiles_item().create_tiles(normalman));
      bn::optional<bn::sprite_ptr> sword = bn::sprite_items::sword.create_sprite(0, 20);
      bn::point knife_map_position(40,40);
      bn::vector<bn::sprite_ptr, 32> text_sprites;
      text_generator.generate(-120, -60, info_text_lines[0], text_sprites);

      int text_timer_frames = 0;
      constexpr int text_display_frames = 30 * 60; //30 seconds in 60 frames


      bn::regular_bg_ptr stage1_bg = bn::regular_bg_items::stage1.create_bg(1, 120);
      bn::point man_map_position(16, 16);
     
      bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
      man.set_camera(camera);
      stage1_bg.set_camera(camera);
      

      while(true){
          

         //keypad work
          if(bn::keypad::left_held())
            {
                man.set_x(man.x() - 1);     //move him by 1 pixel in all directions, +1 is obv east and north -1 west and south
            }
            else if(bn::keypad::right_held())
            {
                man.set_x(man.x() + 1);
            }   

            if(bn::keypad::up_held())
            {
                man.set_y(man.y() - 1);
            }
            else if(bn::keypad::down_held())
            {
                man.set_y(man.y() + 1);
            }





            if(sword.has_value() && ( (sword->x() - 8) < man.x() && man.x() < (sword->x() + 8)) && ( (sword->y() - 8) < man.y() && man.y() < (sword->y() + 8))){
               sword.reset();
               man.set_tiles(bn::sprite_items::man.tiles_item().create_tiles(knifeman));
            }
            
           if(!text_sprites.empty())
            {
            text_timer_frames++;
            if(text_timer_frames >= text_display_frames)
            {
                text_sprites.clear(); // clears text
            }
           }  
           

            camera.set_position(man.x(), man.y()); // camera follows the player



            bn::core::update();

      }
    }
}



int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(16, 16, 16));

    bn::sprite_text_generator text_generator(common::variable_8x8_sprite_font);
    while(true)
    {
        positioningsprite_scene(text_generator);
        stage1(text_generator);
        bn::core::update();
    }
}
