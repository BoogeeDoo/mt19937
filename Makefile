js: src/19937.cc
	@./scripts/emcc_check.js
	@emcc \
		-o dist/19937.js \
		src/19937.cc \
		-s EXPORTED_FUNCTIONS="[ \
			'_ReturnNumericLimits', \
			'_CreateRand', \
			'_Generate', \
			'_FreeRand' \
		]" \
		-s WASM=0 \
		-s WASM_ASYNC_COMPILATION=0 && echo 'WebAssembly done.'

test:
	@./node_modules/.bin/_mocha

.PHONY: test
