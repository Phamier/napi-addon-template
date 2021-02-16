# N-API addon

This is a project template for [N-API](https://nodejs.org/api/n-api.html) addon.
To create a new project based on this template using [degit](https://github.com/Rich-Harris/degit):
```bash
npx degit Phamier/napi-addon-template your-napi-project
cd your-napi-project
```
*Note that you will need to have [Node.js](https://nodejs.org/) installed.*
## Getting started

Installing the depedencies.
```bash
npm install
```
## Building in production

`npm install` automatically builds your addon after installing dependencies. There is no need to do anything else.
## Development
### Building
If you modify `binding.gyp` or add new source files (`src/*.cpp`), you should run ...
```bash
npm run rebuild:dev
```

If you modify an existing source file, `npm run build:dev` will do the job.
```bash
npm run rebuild:dev
```
Also there is a cleaning command...
```bash
npm run clean
```
### Declaration reference and JSDoc
You can add declarations to `index.d.ts` with JSDoc documentation comments for improved Intellisence and documentaion. Example:
```js
/**
 * Hello World function
 * @returns {string} "HelloWorld"
 */
export function helloWorld(): string;
``` 
## VS Code Tips and Tricks
### Configure `includePath` for better IntelliSence results
If you are using [Microsoft C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools), you can add custom `includePath` for your project by modifying  [`c_cpp_properties.json`](https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference) :
```json
"configurations": [{
    ...
    "includePath": [
        "${workspaceFolder}/node_modules/node-addon-api/",
        "${workspaceFolder}/include/**",
        "/usr/local/include/**"    
    ],
    ...
```
### Debugging
*Note: this method was proposed by [Arul R](https://github.com/a7ul).  Basically, this template is an improved version [his](https://github.com/a7ul/basic-node-addon) and I'm using the same debugging method as he does. Check out his [blog post](https://medium.com/@a7ul/debugging-nodejs-c-addons-using-vs-code-27e9940fc3ad) on meduza.com for more information. I will only provide my `launch.json` and `tasks.json` files.*\
`launch.json`:
```json

{
    "version": "0.2.0",
    "configurations": [
        {
            "type":"lldb",
            "request": "launch",
            "name": "Debug",
            "preLaunchTask": "npm rebuild",
            "program": "npm",
            "args": "run test"
        }
    ]
}
```
`tasks.json`:
```json
{
    "version" : "2.0.0",
    "tasks": [
        {
            "type": "npm",
            "script": "rebuild:dev",
            "problemMatcher": [],
            "label": "npm rebuild",
            "detail": "node-gyp rebuild --debug"
        }
    ]
}
```
## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
