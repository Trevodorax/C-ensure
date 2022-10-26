#ifndef _GUI_H_
#include "./GUI.h"
#endif

int initApp(
    int argc, 
    char ** argv
)
{
    GtkApplication * app;
    int status;

    app = gtk_application_new("com.gaudeaux.paul", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

void activate(
    GtkApplication *    app,
    gpointer            userData
) 
{
    GtkWidget * window;
    GtkWidget * grid;

    GtkWidget * messageButton;
    GtkWidget * messageInput;

    GtkWidget * addWordButton;
    GtkWidget * addWordInput;

    // ----- APP FRAME START
    window = initWindow(app, "C-ensure", 500, 500);
    grid = initGrid(window, 20, 20, (margin){20, 20, 20, 20});
    // ----- APP FRAME END


    // ----- WRITE MESSAGE SECTION START
    messageInput = initInput(grid, "Enter message", (gridPos){0, 1, 2, 1});
    messageButton = initButton(grid, "Send", (gridPos){0, 0, 2, 1}, sendMessage, messageInput);
    // ----- WRITE MESSAGE SECTION END


    // ----- ADD CENSORED WORD SECTION START
    addWordInput = initInput(grid, "Enter word", (gridPos){2, 1, 1, 1});
    addWordButton = initButton(grid, "Add word", (gridPos){2, 0, 1, 1}, addCensoredWord, addWordInput);
    // ----- ADD CENSORED WORD SECTION END

    gtk_window_present(GTK_WINDOW(window));
}

GtkWidget * initWindow(
    GtkApplication * app,
    const char * title, 
    int width,
    int height
)
{
    GtkWidget * newWindow;
    newWindow = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (newWindow), title);
    gtk_window_set_default_size (GTK_WINDOW (newWindow), width, height);

    return newWindow;
}

GtkWidget * initGrid(
    GtkWidget * window,
    int rowSpacing,
    int colSpacing,
    margin gridMargin
)
{
    GtkWidget * newGrid;

    newGrid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID (newGrid), rowSpacing);
    gtk_grid_set_column_spacing(GTK_GRID (newGrid), colSpacing);
    gtk_grid_set_column_homogeneous(GTK_GRID (newGrid), TRUE);
    gtk_window_set_child (GTK_WINDOW (window), newGrid);

    setMargin(newGrid, gridMargin);

    return newGrid;
}

GtkWidget * initButton(
    GtkWidget * grid,
    const char * label,
    gridPos pos,
    void (*f)(GtkWidget *, gpointer),
    GtkWidget * inputWidget
)
{
    GtkWidget * button;

    button = gtk_button_new_with_label(label);
    g_signal_connect(button, "clicked", G_CALLBACK (*f), inputWidget);
    gtk_grid_attach(GTK_GRID (grid), button, pos.x, pos.y, pos.w, pos.h);
}

GtkWidget * initInput(
    GtkWidget * grid,
    const char * placeHolder,
    gridPos pos
)
{
    GtkWidget * newInput;

    newInput = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(newInput), placeHolder);
    gtk_grid_attach(GTK_GRID (grid), newInput, pos.x, pos.y, pos.w, pos.h);

    return newInput;
}

void sendMessage(
    GtkWidget * widget,
    gpointer data
)
{
    GtkWidget * inputWidget = data;
    g_print("\nSending message : %s", gtk_editable_get_text(GTK_EDITABLE (inputWidget)));
}

void addCensoredWord(
    GtkWidget * widget,
    gpointer data
)
{
    GtkWidget * inputWidget = data;
    g_print("\nAdding censored word : %s", gtk_editable_get_text(GTK_EDITABLE (inputWidget)));
}

void setMargin(
    GtkWidget * widget, 
    margin marginValues
)
{
    gtk_widget_set_margin_top(widget, marginValues.n);
    gtk_widget_set_margin_end(widget, marginValues.e);
    gtk_widget_set_margin_bottom(widget, marginValues.s);
    gtk_widget_set_margin_start(widget, marginValues.w);
}
