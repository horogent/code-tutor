# code-tutor — 编程特化版渐构导师

基于「渐构学习理论」的编程教学 Claude Code Skill。

## 核心理念

学编程 ≠ 记语法。真正的编程能力来自建构能应对「未见代码/未见需求」的通用思维模型。

## 三重映射（编程版三重世界）

```
现象层（代码运行结果/终端输出）→ 语义层（代码含义/术语定义）→ 概念层（判别模型/抽象模式）
```

## 三种模式

| 模式 | 用途 | 示例 |
|------|------|------|
| 微观模式 | 交互式教单个编程概念/命题 | "教我什么是闭包" |
| 宏观模式 | 交互式系统教一门语言/框架 | "系统学Rust" |
| 生成模式 | 生成结构化文件夹+md教材 | "生成Python入门的编程教材" |

## 核心特色

- **现象先行**：永远先展示运行结果，再解释为什么，最后归纳是什么
- **三层递进**：未知语义自动拆解为 语义学习→概念构建→知识构建
- **判联双修**：判别模型（识别问题类型）+ 联结模型（推导代码实现）
- **教学必落盘**：所有材料模块化写入磁盘，可随时回顾、修改、实验

## 安装

```bash
# 克隆仓库
git clone <repo-url> code-tutor

# 安装到 Claude Code
mkdir -p .claude/skills/
cp -r code-tutor/SKILL.md code-tutor/references/ .claude/skills/code-tutor/
```

或者通过 Claude Code 的 Skill 管理直接导入。

## 目录结构

```
code-tutor/
├── SKILL.md                        # Skill 主指令文件
├── references/                     # 参考资源（渐进式披露）
│   ├── programming-methodology.md  # 编程渐构方法论
│   ├── programming-three-worlds.md # 编程三重映射
│   ├── code-teaching-methodology.md# 三层递进教学法
│   ├── environment-patterns.md     # 环境配置模式
│   ├── verification-design-code.md # 验证方案设计
│   ├── common-traps-code.md        # 编程学习陷阱库
│   ├── context-management.md       # 上下文管理策略
│   └── templates/                  # 教材生成模板
│       ├── knowledge-point-code.md
│       ├── module-summary-code.md
│       ├── knowledge-map-code.md
│       ├── learning-path-code.md
│       └── environment-setup.md
└── example-output/                 # 示例学习材料输出
    └── 线程安全的内存池/
```

## 方法论基础

- 渐构学习理论（YJango，knowledge_base/ 53课完整课程）
- 三重世界映射（现实→认知→符号）
- 判联模型体系（判别模型 + 联结模型）
- 信息推测框架（经验推测 vs 模型推测）

## License

MIT
