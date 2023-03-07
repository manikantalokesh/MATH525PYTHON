output.txt: main.exe
	./main.exe > output.txt

main.exe: main.o quad_area.o quad_perimeter.o \
	gcc quad_area.o quad_perimeter.o \
    main.o -o main.exe

	main.o: main.c
		gcc -c main.c
	quad_area.o: quad_area.c
		gcc -c quad_area.c
	quad_perimeter.o: quad_perimeter.c
		gcc -c quad_perimeter.c