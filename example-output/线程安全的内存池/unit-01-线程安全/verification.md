# Unit 1 验证题

> 以下验证题全部是你在知识点的示例代码中**未见过**的新场景。
> 先自己判断，再看答案。

---

## 基础验证：概念判别

### 题 1

以下代码在多个线程同时调用 `record_hit()` 时，是否线程安全？说清依据。

```cpp
class HitCounter {
    std::mutex mtx;
    std::map<std::string, int> counts;
public:
    void record_hit() {
        std::string name = get_thread_name();
        std::lock_guard<std::mutex> lock(mtx);
        counts[name]++;
    }
    int get_hits() {
        std::lock_guard<std::mutex> lock(mtx);
        int total = 0;
        for (auto& [name, count] : counts) total += count;
        return total;
    }
};
```

<details>
<summary>点击查看答案</summary>

**安全。** 两个方法都使用了 `std::lock_guard` 保护对 `counts` 的访问。`get_thread_name()` 返回的是线程私有的字符串，不涉及共享数据。关键判据：
- `counts` 是共享可变数据 ✅ 有 mutex 保护
- `name` 是线程局部数据 ✅ 无需保护

</details>

---

### 题 2

判断以下代码是否线程安全：

```cpp
class Logger {
    std::ofstream file;
public:
    Logger(const std::string& path) : file(path) {}
    void log(const std::string& msg) {
        file << msg << std::endl;  // 多线程同时调用
    }
};
```

<details>
<summary>点击查看答案</summary>

**不安全。** `file << msg << std::endl` 不是原子操作，且 `std::ofstream` 本身不是线程安全的。多个线程同时写同一个文件流会导致输出交错甚至崩溃。需要加 `std::mutex` 保护写操作。

</details>

---

### 题 3

判断：多个线程同时调用 `std::cout << "hello"` 是线程安全的吗？

<details>
<summary>点击查看答案</summary>

**部分安全，但输出会交错。** C++11 起，`std::cout` 的每个 `operator<<` 调用是线程安全的（不会崩溃），但多个 `<<` 组成的表达式不是原子的。例如 `std::cout << "hello " << "world"` 两个 `<<` 之间可能被其他线程插入，导致输出 `"hello hello world world"` 之类的交错。如需完整输出不被中断，需自行加锁。

</details>

---

## 进阶验证：写同步代码

### 题 4

下面的类维护一个"最高温度记录"，多线程调用 `update()` 更新温度。补全代码使其线程安全。

```cpp
class TemperatureTracker {
    double highest_temp = -100.0;  // 初始不可能的低值
    // TODO: 添加需要的成员

public:
    void update(double new_temp) {
        // TODO: 使以下操作线程安全
        if (new_temp > highest_temp) {
            highest_temp = new_temp;
        }
    }

    double get_highest() const {
        // TODO: 使以下操作线程安全
        return highest_temp;
    }
};
```

<details>
<summary>点击查看答案</summary>

```cpp
class TemperatureTracker {
    double highest_temp = -100.0;
    mutable std::mutex mtx;  // mutable 允许在 const 方法中上锁

public:
    void update(double new_temp) {
        std::lock_guard<std::mutex> lock(mtx);
        if (new_temp > highest_temp) {
            highest_temp = new_temp;
        }
    }

    double get_highest() const {
        std::lock_guard<std::mutex> lock(mtx);
        return highest_temp;
    }
};
```

关键点：`get_highest()` 是 const 方法，但需要锁 `mtx`，所以 `mtx` 必须声明为 `mutable`。

</details>
