
public-dir:
	mkdir -p ./pub

index.html: ./src/index.html public-dir
	minhtml --minify-css --minify-js ./src/index.html -o ./pub/index.html

deploy: wrangler.toml index.html ./src/main.js
	wrangler deploy

# alias
d: deploy