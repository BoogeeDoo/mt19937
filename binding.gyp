{
  "targets": [
    {
      "target_name": "__mt19937",
      "sources": [ "src/19937.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
