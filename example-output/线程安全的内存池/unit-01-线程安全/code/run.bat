@echo off
REM run.bat — 编译并运行 Unit 1 所有代码示例（Windows）
REM 用法: run.bat

echo ========== 1/5 竞态条件（线程不安全） ==========
g++ -std=c++11 -pthread race_condition.cpp -o race_condition.exe
race_condition.exe
echo.

echo ========== 2/5 加锁保护（线程安全） ==========
g++ -std=c++11 -pthread mutex_safe.cpp -o mutex_safe.exe
mutex_safe.exe
echo.

echo ========== 3/5 局部变量（天然安全） ==========
g++ -std=c++11 -pthread local_variable.cpp -o local_variable.exe
local_variable.exe
echo.

echo ========== 4/5 不安全 vector（可能崩溃） ==========
g++ -std=c++11 -pthread unsafe_vector.cpp -o unsafe_vector.exe
echo 警告：以下运行可能崩溃或产生异常结果——这是教学的预期现象
unsafe_vector.exe || echo 如预期那样崩溃或异常了
echo.

echo ========== 5/5 只读共享（安全） ==========
g++ -std=c++11 -pthread readonly_shared.cpp -o readonly_shared.exe
readonly_shared.exe

echo.
echo ========== 全部运行完毕 ==========
del *.exe
