#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_ask.H>

#include <cstdio>
int main(int argc, char * argv[])
{
	Fl_Window window(600, 600, "Class Information Manager");
	window.begin();


	window.end();
	window.show(argc, argv);
	return Fl::run();
}

void browser_test(Fl_Window &window)
{
	Fl_Browser *b = new Fl_Browser(10, 10, window.w() - 20, window.h() - 20);
	int widths[] = { 50, 50, 50, 70, 70, 40, 40, 70, 70, 50, 0 };               // widths for each column
	b->column_widths(widths);
	b->column_char('\t');                                                       // tabs as column delimiters
	b->type(FL_HOLD_BROWSER);
	b->add("USER\tPID\t%CPU\t%MEM\tVSZ\tRSS\tTTY\tSTAT\tSTART\tTIME\tCOMMAND"); // lines of tab delimited data
	b->add("root\t2888\t0.0\t0.0\t1352\t0\ttty3\tSW\tAug15\t0:00\t@b@f/sbin/mingetty tty3");
	b->add("erco\t2889\t0.0\t13.0\t221352\t0\ttty3\tR\tAug15\t1:34\t@b@f/usr/local/bin/render a35 0004");
	b->add("uucp\t2892\t0.0\t0.0\t1352\t0\tttyS0\tSW\tAug15\t0:00\t@b@f/sbin/agetty -h 19200 ttyS0 vt100");
	b->add("root\t13115\t0.0\t0.0\t1352\t0\ttty2\tSW\tAug30\t0:00\t@b@f/sbin/mingetty tty2");
	b->add("root\t13464\t0.0\t0.0\t1352\t0\ttty1\tSW\tAug30\t0:00\t@b@f/sbin/mingetty tty1 --noclear");
	return;
}
void box_test()
{
	Fl_Box box(20, 40, 260, 100, "Hello world!");
	box.box(FL_UP_BOX);
	box.labelsize(36);
	box.labelfont(FL_BOLD | FL_ITALIC);
	return;
}

void button_test()
{
	Fl_Button button(450, 40, 120, 30, "A push button");
	Fl_Check_Button check_button(450, 80, 120, 30, "A check button");
	button.type(FL_NORMAL_BUTTON);
	check_button.type(FL_TOGGLE_BUTTON);

	Fl_Input input(128, 40, 292, 30, "Say something...");
	Fl_Multiline_Output output(128, 80, 292, 100, "Output");
	output.value("多行文本测试\nA quick brown box jumps over the lazy dog.");

	return;
}