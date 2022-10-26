#define _GUI_H_
#include <gtk/gtk.h>

#ifndef _DICTIONARY_H_
#include "../dictionary/dictionary.h"
#endif

typedef struct {
    int x;
    int y;
    int w;
    int h;
} gridPos;

typedef struct {
    int n;
    int e;
    int s;
    int w;
} margin;

int initApp(
    int argc, 
    char ** argv
);

GtkWidget * initWindow(
    GtkApplication * app,
    const char * title, 
    int width,
    int height
);

GtkWidget * initGrid(
    GtkWidget * window,
    int rowSpacing,
    int colSpacing,
    margin gridMargin
);

GtkWidget * initButton(
    GtkWidget * grid,
    const char * label,
    gridPos pos,
    void (*f)(GtkWidget *, gpointer),
    GtkWidget * inputWidget
);

GtkWidget * initInput(
    GtkWidget * grid,
    const char * placeHolder,
    gridPos pos
);

void activate(
    GtkApplication *    app,
    gpointer            userData
);

void addCensoredWord(
    GtkWidget * widget,
    gpointer data
);

void sendMessage(
    GtkWidget * widget,
    gpointer data
);

void setMargin(
    GtkWidget * widget, 
    margin marginValues
);
