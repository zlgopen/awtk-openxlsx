# awtk-openxlsx

基于[OpenXLSX](https://github.com/troldal/OpenXLSX)针对[AWTK](https://github.com/zlgopen/awtk)做了一些适配:

* 使用 scons 编译。

* 在不同的平台上验证。

* 可以用[AWTK引用第三方库的方式](https://github.com/zlgopen/awtk/blob/master/docs/how_to_use_3rd_libs.md)引用。

## 使用方法

> 这里以awtk-hello项目为例

### 1.拷贝文件到自己的项目

```
cd awtk-hello
cp -rf ../awtk-openxlsx/src/* src
```

### 2.修改SConstruct，使用cxx17编译

```
helper = app.Helper(ARGUMENTS);
helper.use_std_cxx(17)
```

> 确保编译器支持cxx17

### 3.添加cpp文件到src/SConscript

```
env.Program(os.path.join(BIN_DIR, 'demo'), Glob('*.c') + Glob('*.cpp'))
```

### 4.对于android/ios，修改build.json，在sources中增加下列文件:

```
      "src/*.cpp",
      "src/*.hpp",
      "src/nowide/*.hpp",
```

