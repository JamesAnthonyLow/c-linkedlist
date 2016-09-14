LINKEDLIST = node.o linkedlist.o

linkedlist: $(LINKEDLIST)
	gcc $(LINKEDLIST) -o linkedlist

clean: 
	rm linkedlist *.o
