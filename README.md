# Qt 计算器

<p align="center">
  <img src="docs/images/calculator-icon.png" width="64" alt="Qt 计算器原程序图标">
</p>

<p align="center"><sub>原程序图标（从 Windows 资源文件 <code>bitbug_favicon.ico</code> 导出），不是界面预览或运行截图。仓库未提供运行界面截图；本次环境没有 Qt，未构建或运行应用。</sub></p>

> 基于 Qt Widgets 的桌面计算器，提供基础四则运算、括号和小数输入。

## 功能

- 数字输入与小数点。
- 加、减、乘、除及括号表达式。
- 清零和退格。
- 使用运算符栈将中缀表达式转换后计算，遵循括号与四则运算优先级。

## 构建与运行

### 环境要求

- Qt 5 Desktop Kit，包含 Qt Widgets。
- Qt Creator，或与所选 Qt Kit 匹配的 qmake 和 C++11 编译器（MSVC 或 MinGW）。

### 使用 Qt Creator

1. 打开仓库中的 `Calculator.pro`。
2. 选择已安装的 Qt Desktop Kit 并完成项目配置。
3. 构建项目，然后从 Qt Creator 运行。

### 使用 MinGW 命令行

在已配置 Qt/MinGW 的命令行中，从项目根目录执行：

```bat
mkdir build
cd build
qmake ..\Calculator.pro
mingw32-make
```

使用 MSVC Kit 时，在对应的 Qt/MSVC 开发者命令行中运行 qmake，并以 `nmake` 替代 `mingw32-make`。

## 使用方法

1. 点击数字和运算符按钮输入表达式；需要括号时使用 `(`、`)`。
2. 点击 `=` 计算。
3. 使用退格删除末尾字符，或点击清零重新输入。

## 实现与限制

- 项目使用 qmake，源代码位于 `main.cpp`、`mainwindow.cpp` 和 `mainwindow.ui`，语言标准为 C++11。
- 当前实现未完整校验括号配对和非法表达式，也未显式处理除以零；请只输入格式正确的表达式。
- 仓库没有自动化测试目标或预编译发布包。
