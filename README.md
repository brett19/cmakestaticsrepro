# CMake.js statics initialization error repro

## Failing Case:
```
npm run build
npm run test
```

## Working Case:
```
npm run build-debug
npm run test
```

## Notes

- You may need to delete you 'build' folder between Release/Debug build tests,
  since the bindings library uses a particular search order.