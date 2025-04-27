all:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules

CFLAGS_krect.o := -DDEBUG
obj-m := krect02.o
krect02-objs := module.o krect.o

clean:
	rm -rf .*.cmd *.mod.c *.mod.o *.mod *.ko *.o Module.symvers modules.order D I 1

di:
	grep ' gcc-12 ' .*cmd | sed -e 's, -,\n-,g' | awk '{if (v[$0]) next; v[$0]=1; print}' > 1
	grep '^-D' 1 | sed -e 's/^-D/"/g' -e 's/$/",/g' > D
	grep '^-[Ii]' 1 > I
