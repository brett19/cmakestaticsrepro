"use strict";

const addon = require('bindings')('staticsrepro');
let assert = require("assert");

const result = addon.hello();
assert.notEqual(result, 0);
