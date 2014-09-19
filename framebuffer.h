#ifndef FRAMEBUFFER_API_H_
#define FRAMEBUFFER_API_H_

#include <hardware/hardware.h>

struct private_handle_t;


typedef struct framebuffer_info_t{
    //set by device.
    int   displayType;
    int   fbIdx;

    //information get from osd
    struct fb_var_screeninfo info;//need to fbpost
    struct fb_fix_screeninfo finfo;

    int   fd;//for fbpost use
    int   fbSize;
    
    float xdpi;
    float ydpi;
    float fps;
    int   flipFlags;
    
    buffer_handle_t currentBuffer;
}framebuffer_info_t;


// Initialize the framebuffer (must keep module lock before calling
extern int init_frame_buffer_locked(struct framebuffer_info_t* info);
extern int fb_post_locked(struct framebuffer_info_t* fbinfo,buffer_handle_t buffer);
extern int fb_post_with_fence_locked(struct framebuffer_info_t* fbinfo,buffer_handle_t hnd,int in_fence);
extern int getOsdIdx(int display_type);
extern int bits_per_pixel();

//for egl to get framebuffer count
extern unsigned int get_num_fb_buffers();


#endif
