#include <tos.h>
#include <mint/dcntl.h>

int main()
{
	long retcode;
	int handle;
	char *blk;


	retcode = Fcreate("u:\\shm\\test.shm",0 );
	if	(retcode < 0L)
		return((int) retcode);
	blk = Malloc(1234L);
	if	(!blk)
		return((int) -39);
	handle = (int) retcode;

	retcode = Fcntl(handle, (long) blk, SHMSETBLK);
	if	(retcode < 0L)
		{
		return((int) retcode);
		}
	Cconin();
	Fclose(handle);
	return(0);
}