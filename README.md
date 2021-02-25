# awtk-openxlsx

基于 [OpenXLSX](https://github.com/troldal/OpenXLSX) 针对 [AWTK](https://github.com/zlgopen/awtk) 做了一些适配：

* 使用 scons 编译。

* 在不同的平台上验证。

* 可以通过 [AWTK 引用第三方库的方式](https://github.com/zlgopen/awtk/blob/master/docs/how_to_use_3rd_libs.md) 引用。也可以直接拷贝到自己的项目中。

## 用途

主要用途有两种：

* 导出数据。在导出数据时通常用 CSV 格式，但是 CSV 虽然简单，但是没法控制格式，XLSX 也一种选择。

* 生产报表。可以先用 excel 制作一个模版，再通过本项目提供的库去修改模版中的数据，生产最终的报表。

## 使用方法

> 这里以 awtk-hello 项目为例

### 1. 拷贝文件到自己的项目

```
cd awtk-hello
cp -rf ../awtk-openxlsx/src/* src
```

### 2. 修改 SConstruct，使用 cxx17 编译

```
helper = app.Helper(ARGUMENTS);
helper.use_std_cxx(17)
```

> 确保编译器支持 cxx17

### 3. 添加 cpp 文件到 src/SConscript

```
env.Program(os.path.join(BIN_DIR, 'demo'), Glob('*.c') + Glob('*.cpp'))
```

### 4. 对于 android/ios，修改 build.json，在 sources 中增加下列文件：

```
      "src/*.cpp",
      "src/*.hpp",
      "src/nowide/*.hpp",
```

## 注意事项

本项目是 C++开发的，如果在 C 代码中使用，需要把源文件的扩展名改为 cpp。
