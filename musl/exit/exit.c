_Noreturn void exit(int code)
{
	((void (*)())1)();
	for(;;) {}
}
