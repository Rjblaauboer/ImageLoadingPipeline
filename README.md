<h3 align="center">Image Loading Pipeline Exercise</h3>

<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About the Project</a>
    </li>
    <li>
        <a href="#prerequisites">Prerequisites</a>
    </li>
    <li>
      <a href="#running-the-example">Running the example</a>
    </li>
    <li><a href="#useful-links">Useful Links</a></li>
  </ol>
</details>

## About the Project

The ImageLoadingPipeline is a small library to load images in various formats from various locations and convert them to pixel data.

Supported formats:
* JPEG
* TIFF


### Prerequisites

* C++17
* CMake 3.17

### Running the example

1. Clone the repo and `cd` into it

2. Build the example
    ```c++
   mkdir cmake-build && cd cmake-build
   cmake ../ && make
   ```   
3. Run the example
   ```c++
   ./example
   ```
## Useful Links

* [Crafting Interpreters - Visitor Pattern](https://craftinginterpreters.com/representing-code.html#the-expression-problem) - Some ideas on how to deal with various operations on various formats
* [Understanding and writing a JPEG decoder](https://yasoob.me/posts/understanding-and-writing-jpeg-decoder-in-python/) - Great deconstruction of how JPEGs work