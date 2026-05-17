---
name: environment-patterns
description: >
  编程教学环境配置模式：如何根据编程语言/框架配置教学环境，
  如何处理无环境情况，以及在线替代方案指南。
version: 1.0.0
---

# 编程教学环境配置模式

## 一、环境配置优先级

```
1. 用户已有本地环境 → 直接使用
2. 用户没有但可以快速安装 → 引导安装（给出精确命令）
3. 用户无法安装但有网络 → 推荐在线 playground
4. 用户无法安装且无网络 → 使用"现象描述+推理"模式
```

---

## 二、各语言/框架环境配置模板

### 2.1 Python

**环境检查**：
```bash
python3 --version  # 或 python --version
```

**最小安装**：
```bash
# macOS
brew install python3

# Ubuntu/Debian
sudo apt install python3

# Windows
# 从 python.org 下载安装包，勾选"Add Python to PATH"
```

**在线替代**：
- Python.org 自带的 interactive shell
- Google Colab
- Replit (Python)

### 2.2 JavaScript/Node.js

**环境检查**：
```bash
node --version
npm --version
```

**最小安装**：
```bash
# 推荐 nvm (Node Version Manager)
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.0/install.sh | bash
nvm install --lts
```

**在线替代**：
- 浏览器 DevTools Console（F12 → Console）
- CodeSandbox
- StackBlitz
- JSFiddle

### 2.3 Rust

**环境检查**：
```bash
rustc --version
cargo --version
```

**最小安装**：
```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

**在线替代**：
- Rust Playground (play.rust-lang.org)

### 2.4 前端（React/Vue 等）

**环境检查**：
```bash
node --version  # 需要 >= 16
npm --version
```

**在线替代**：
- CodeSandbox (支持 React/Vue/Angular 模板)
- StackBlitz

---

## 三、教材中的环境标注规范

在生成的编程教材中，每个需要运行代码的地方必须标注：

### 标注模板

```markdown
> **运行环境**：[语言/工具] [版本要求]
> **运行方式**：[具体的命令]
> **预期输出**：[输出内容]
```

### 示例

```markdown
> **运行环境**：Python 3.8+
> **运行方式**：将代码保存为 `example.py`，运行 `python example.py`
> **预期输出**：
> ```
> Hello, World!
> 42
> ```

或者（终端命令）：

```markdown
> **运行环境**：任意终端（bash/zsh/PowerShell）
> **运行方式**：直接在终端输入以下命令
> **预期输出**：
> ```
> total 0
> -rw-r--r-- 1 user staff 0 May 17 10:00 hello.txt
> ```
```

---

## 四、无环境时的教学模式

当用户完全无法运行代码时（如移动端或受限环境），切换为"现象描述+推理"模式：

### 模式切换话术
> "看起来你现在不方便运行代码。没关系——我会把每段代码的预期输出都详细描述出来。你重点关注：输入是什么、输出是什么、从输入到输出发生了什么变化。"
> "等你有环境之后，建议把教材中的代码都实际跑一遍——看到实际现象和预期一致，三层才算打通。"

### 教材调整
- 代码块后必须附带详细的"预期现象描述"（不仅是输出，还包括中间状态）
- 增加"心智追踪"练习：用纸笔模拟代码执行过程
- 标注"有环境后优先运行"的代码块

---

## 五、环境感知教学流程

### 会话开始时
```
1. 检测用户是否提到已有的编程环境
2. 如果没有，在学情诊断阶段询问：
   "你电脑上有 [所需语言/工具] 吗？可以运行代码吗？"
3. 根据回答选择教学模式
```

### 生成模式中的环境文件
每本生成的教材都包含 `_环境配置指南.md`，内容：
1. 所需工具清单（版本要求）
2. 各操作系统安装命令
3. 验证安装成功的命令
4. 在线替代方案列表
5. 第一个"Hello World"程序（验证环境可用）
