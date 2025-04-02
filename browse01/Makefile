all:
	make -C /usr/src/linux-headers-6.8.0-52-generic M=$(PWD) modules

obj-m := browse01.o

clean:
	rm -rf .*.cmd *.mod.c *.mod.o *.mod *.ko *.o Module.symvers modules.order D I 1

di:
	grep ' gcc ' .*cmd | sed -e 's, -,\n-,g' | awk '{if (v[$0]) next; v[$0]=1; print}' > 1
	grep '^-D' 1 | sed -e 's/^-D/"/g' -e 's/$/",/g' > D
	grep '^-[Ii]' 1 > I
