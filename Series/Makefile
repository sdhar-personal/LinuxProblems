TARGET=PrintSeries
OBJS=printseries_usingthreads.o

$(TARGET):$(OBJS)
	gcc -o $(TARGET) $(OBJS) -lpthread

printseries_usingthreads.o:printseries_usingthreads.c
	gcc -c printseries_usingthreads.c
