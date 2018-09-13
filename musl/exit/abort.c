_Noreturn void abort(void)
{
	((void (*)())1)();
	for(;;) {}
}
