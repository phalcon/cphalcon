all: scanner.c parser.c ../../../../lemon/lemon

../../../../lemon/lemon: ../../../../lemon/lemon.c
	$(CC) -O2 "$<" -o "$@"

scanner.c: scanner.re Makefile
	re2c -b -o "$@" "$<"
	sed -i 's!^#line.*$$!/* & */!g' "$@"

parser.c: parser.y base.c Makefile ../../../../lemon/lemon
	../../../../lemon/lemon -s -q "$<"
	cat base.c >> "$@"
	sed -i 's!^#line.*$$!/* & */!g' "$@"

clean:
	-rm -f *.o *.lo

.PHONY: clean
