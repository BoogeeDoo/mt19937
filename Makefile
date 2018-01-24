js: src/19937.cc
	@emcc --bind -o dist/19937.js src/19937.cc -s \
		EXPORTED_FUNCTIONS="[\
			'_Generate',\
			'_CreateRand',\
			'_FreeRand',\
			'_ReturnNumericLimits'\
		]" && echo 'WebAssembly done.'

test:
	@./node_modules/.bin/_mocha

.PHONY: test
