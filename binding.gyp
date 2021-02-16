{
  "targets": [
    {
      "target_name": "test",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "<!@(ls src/*.cpp)",
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "./include"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}