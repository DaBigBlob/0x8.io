
com-dir:
	mkdir -p ./com

esr.exe: ./esr/esr.c com-dir
	cc ./esr/esr.c -o ./com/esr.exe

index.html: ./src/index.html com-dir
	minhtml --minify-css --minify-js ./src/index.html -o ./com/index.html

main.js: ./src/main.js com-dir esr.exe index.html
	./com/esr.exe "$$(cat ./src/main.js)" "__HTML__" "\`$$(cat ./com/index.html)\`" > ./com/main.js

deploy: wrangler.toml main.js
	wrangler deploy

clean: com-dir
	rm -rf ./com

# alias
d: deploy
c: clean