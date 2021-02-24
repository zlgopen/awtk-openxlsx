# awtk-openxlsx

基于[OpenXLSX](https://github.com/troldal/OpenXLSX)针对[AWTK](https://github.com/zlgopen/awtk)做了一些适配:

* 使用 scons 编译。

* 在不同的平台上验证。

* 可以用[AWTK引用第三方库的方式](https://github.com/zlgopen/awtk/blob/master/docs/how_to_use_3rd_libs.md)引用。

## 使用方法

 * 可以按正常使用第三方库的的方式使用。

 * 对于android/ios，可以直接拷贝到app的src目录下。


## 注意事项

需要使用cxx17编译

```
helper.use_std_cxx(17)
```
