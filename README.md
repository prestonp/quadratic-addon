Quadratic Addon
-------------

A simple c++ addon for solving the quadratic formula.

**Install**

npm quadratic-addon

**Usage**

```javascript
var quadratic = require('quadratic-addon');
quadratic.solve(6, 11, -35); // [-3.5, 1.6666667]
```

**Building manually**

Building the addon requires node-gyp

```
npm install -g node-gyp
```

Configure and build for your machine

```javascript
node-gyp configure
node-gyp build
```

Node binding will be located in `build/Release/addon.node`

**License**

MIT

