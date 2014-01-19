all: scanner.c parser.c ../../../../../lemon/lemon

../../../../../lemon/lemon: ../../../../../lemon/lemon.c
	$(CC) -O2 "$<" -o "$@"

scanner.c: scanner.re Makefile
	re2c -b -o "$@" "$<"
	sed -i 's!^#line.*$$!/* & */!g' "$@"
	sed -i 's/YY/KK/g; s/yy/kk/g' "$@"

parser.c: parser.y base.c Makefile ../../../../../lemon/lemon
	../../../../../lemon/lemon -m -s -q "$<"
	cat base.c >> "$@"
	sed -i 's!^#line.*$$!/* & */!g' "$@"
	sed -i 's/YY/KK/g; s/yy/kk/g; s/TOKEN/KTOKEN/g' "$@"

clean:
	-rm -f *.o *.lo

.PHONY: clean
