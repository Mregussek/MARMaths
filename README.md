
# MARMaths

<p align="center">
  <img width="425" height="133" src="img/marmaths.jpg">
</p>

<p align="center">
<a href="https://github.com/mregussek/MARMaths"><img src="https://img.shields.io/badge/version-1.0.0-red?style=flat-square"/></a>
<a href="https://github.com/mregussek/MARMaths/blob/master/LICENSE.md"><img alt="license" src="https://img.shields.io/github/license/mregussek/MARMaths?style=flat-square"/></a>
<a href="https://marmaths.readthedocs.io/"><img src="https://readthedocs.org/projects/pip/badge/?version=latest&style=flat-square"/></a>
</p>

## About MARMaths

MARMaths is a computing library written specially for MAREngine. It contains everything needed for vector and matrix calculations in order to perform correct computations.

This library will be extended as the engine will be bigger and much more advanced calculations will be in need.

## Compatibility

I believe this library should work with every game engine based on OpenGL, because everything computation is column majored. So I would like to encourage you to test it yourself and share your experiences.

## Implemented

- vec2
- vec3
- vec4
- mat4

## Usage

You need to include main file, which is *MARMaths.h*. Then you will be able to use everything.

## Examples

### Vector operations:

```c++
maths::vec2 default_values; // default values are vec2: ( 0 , 0 )
```

```c++
maths::vec3 v1 = { 1.f, 2.f, 3.f };
maths::vec3 v2 = { 2.f, 3.f, 4.f };

std::cout << v1.multiply(v2) << "\n"; // v1 = vec3: ( 2 , 6 , 12 ) // because multiply takes a reference and returns *this!
std::cout << v1 * v2 << "\n"; // vec3: ( 4 , 18 , 48 )
```

```c++
// v2 = vec3: ( 2, 3, 4 )
float value = 5.f;

std::cout << v2.subtract(value) << "\n"; // v2 = vec3: ( -3 , -2 , -1 ) // reference!
std::cout << v2 - value << "\n"; // vec3: ( -8 , -7 , -6 )
```

```c++
// v1 = vec3: ( 2 , 6 , 12 )
maths::vec4 v4{ v1, 10.f };

std::cout << v4 << "\n"; // vec4: ( 2 , 6 , 12 , 10 )
std::cout << v4 * maths::vec4{ 3.f, 3.f, 3.f, 3.f } << "\n"; // vec4: ( 6 , 18 , 36 , 30 )
```

### Matrix operations:

```c++
maths::mat4 default_mat;

std::cout << default_mat << "\n";
/*
 | 0.000000 0.000000 0.000000 0.000000 |
 | 0.000000 0.000000 0.000000 0.000000 |
 | 0.000000 0.000000 0.000000 0.000000 |
 | 0.000000 0.000000 0.000000 0.000000 |
*/
```

```c++
maths::mat4 id = maths::mat4::identity();
std::cout << id << "\n"; // just identity
```

```c++
maths::mat4 identity_2f{ 2.f };
maths::mat4 identity_3f{ 3.f };

std::cout << identity_2f * identity_3f << "\n";
/*
 | 6.000000 0.000000 0.000000 0.000000 |
 | 0.000000 6.000000 0.000000 0.000000 |
 | 0.000000 0.000000 6.000000 0.000000 |
 | 0.000000 0.000000 0.000000 6.000000 |
*/
```

```c++
float field_of_view = 55.f;
float aspectRatio = 4.f / 3.f;
float near = 0.1f;
float far = 100.f

std::cout << maths::mat4::perspective(field_of_view, aspectRatio, near, far) << "\n";
/*
 | -0.766783 0.000000 0.000000 0.000000  |
 | 0.000000 -1.022377 0.000000 0.000000  |
 | 0.000000 0.000000 -1.002002 -0.200200 |
 | 0.000000 0.000000 -1.000000 1.000000  |
*/
```

```c++
float angle_in_degrees = 45.f;
maths::vec3 rotation_axis = { 0.f, 1.f, 0.f }; // rotating around y-axis
std::cout << maths::mat4::rotation(maths::Trig::toRadians(angle_in_degrees), rotation_axis) << "\n";
/*
 | 0.707107 0.000000 0.707107 0.000000  |
 | 0.000000 1.000000 0.000000 0.000000  |
 | -0.707107 0.000000 0.707107 0.000000 |
 | 0.000000 0.000000 0.000000 1.000000  |
*/
```

```c++
maths::vec3 position{ 0.5, 0.5, 0.5 };
maths::vec3 scale{ 1.f, 1.f, 2.f }

std::cout << maths::mat4::translation(position) * maths::mat4::scale(scale) << "\n";
/*
 | 1.000000 0.000000 0.000000 0.500000 |
 | 0.000000 1.000000 0.000000 0.500000 |
 | 0.000000 0.000000 2.000000 0.500000 |
 | 0.000000 0.000000 0.000000 1.000000 |
*/
```

```c++
maths::vec3 position{ 0.5, 0.5, 0.5 };
maths::vec3 front{ 0.0f, 0.0f, -1.0f };
maths::vec3 up{ 0.0f, 1.0f, 0.0f };

std::cout << maths::mat4::lookAt(position, position + front, up) << "\n";
/*
 | 1.000000 -0.000000 0.000000 -0.500000  |
 | 0.000000 1.000000 0.000000 -0.500000   |
 | -0.000000 -0.000000 1.000000 -0.500000 |
 | 0.000000 0.000000 0.000000 1.000000   |
*/
```

### mat4 and vec4

```c++
auto vec = maths::vec4{ 3.f, 3.f, 3.f, 3.f };
auto rotate = maths::mat4::rotation(maths::Trig::toRadians(angle_in_degrees), rotation_axis);

std::cout << rotate * vec << "\n"; // vec4: ( 13.414213 , 13.000000 , 12.000000 , 13.000000 )
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Author

Copyright (C) 2020-present Mateusz Rzeczyca <info@mateuszrzeczyca.pl>

## License

See the [LICENSE.md](https://github.com/Mregussek/MARMaths/blob/master/LICENSE.md) file for details.
