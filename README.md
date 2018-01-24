# @crand/mt19937

C++ [mt19937 random generator](http://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine) wrapper for Node.js.

## Installation

```console
$ npm install --save @crand/mt19937
```

## Usage

First you should create an mt19937 Object:

```javascript
const Mt19937 = require('@crand/mt19937');
const rand = new Mt19937(seed);
```

Then you can generate random numbers via `.next()`:

```javascript
for(let i = 0; i < 100; i++) {
    console.log(rand.next());
}
```

## API

### `Mt19937::Constructor([seed, ] [a, ] [b])`

Constructor of `Mt19937` class.

#### Parameters

+ `seed`: the random seed (optional);
+ `a`: the minimum bound of the random number (default to 0);
+ `b`: the maximum bound of the random number (default to `std::numeric_limits<int>::max()`).

### `Mt19937.prototype.next()`

Generate next random number.

#### Parameters

None.

#### Return

The random number.

### `Mt19937.prototype.destroy()`

Destroy the generator.

#### Parameters

None.

#### Return

None.

## Contribution

You're welcome to make Pull Requests.
