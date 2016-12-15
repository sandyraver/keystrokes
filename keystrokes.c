#include <iostream>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv)
{
	int fd;	
	if (argc < 2)
	{
		printf("usage: %s <device>\n", argv[0]);
		return 1;
	}
	fd = open(argv[1], O_RDONLY);
	struct input_event ev;
	bool cntrl = false;
	while(1)
	{

		read(fd, &ev, sizeof(struct input_event));
		if(ev.type == 1)
		{
			if(ev.code == 29 && ev.value > 0)
			{
				cntrl = true;
			}
			if(cntrl)
			{
				if ( ev.code == 36 && ev.value > 0)
				{
					cout << "fuck yeah " << endl;
				}
			}
			cout << "Key "<< ev.code << " state "<< ev.value << endl;
			//printf("key %i state %i\n",ev.code, ev.value);
		}
	}
	return 0;
}