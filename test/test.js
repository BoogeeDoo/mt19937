"use strict";

const assert = require("assert");

const Mt19937 = require("../");

describe("generate random", function() {
    it("should generate via 2333", function() {
        const mt = new Mt19937(2333);

        const ret = [
            127893920,
            1923203196,
            1694310899,
            1863585917,
            1040834671,
            1820367189,
            1833782135,
            888917466,
            824035782,
            534795149
        ];

        for(let i = 0; i < 10; i++) {
            assert.strictEqual(ret[i], mt.next());
        }
    });
});
