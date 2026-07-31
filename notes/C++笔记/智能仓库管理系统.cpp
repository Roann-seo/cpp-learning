//综合编程题：智能仓库管理系统
// 背景
// 设计一个泛型仓库管理系统，能够存储不同类型商品，支持入库、查询、统计分析等功能。

// 要求
// 第一题：泛型商品容器
// 用类模板设计一个 Goods<T> 类，其中 T 是商品数量类型（可以是 int 或 double）：


// // 要求类模板成员函数类外实现
// template<class T>
// class Goods {
// private:
//     string m_name;   // 商品名称
//     T m_count;        // 库存数量（泛型）
//     double m_price;   // 单价
// public:
//     Goods(string name, T count, double price);
//     string getName() const;
//     T getCount() const;
//     double getPrice() const;
//     double getTotalValue() const;  // 返回 数量 × 单价

//     // 重载 == 运算符（按名称判断是否为同一商品）
//     bool operator==(const Goods<T>& other) const;
// };
// 第二题：仓库管理类
// 设计一个 Warehouse<T> 类模板：


// template<class T>
// class Warehouse {
// private:
//     vector<Goods<T>> m_goods;  // 商品列表
// public:
//     // 1. 入库：添加商品（如果已存在则增加数量）
//     void addGoods(Goods<T> g);

//     // 2. 按名称删除商品
//     void removeGoods(string name);

//     // 3. 打印所有商品信息（用 for_each + 函数对象实现）
//     void printAll() const;

//     // 4. 按总价值降序排序（用 sort + 自定义函数对象）
//     void sortByValue();

//     // 5. 查找商品（用 find_if + 一元谓词）
//     //    返回迭代器，找不到返回 end()
//     typename vector<Goods<T>>::iterator findGoods(string name);
// };
// 提示：findGoods 中需自定义一个一元谓词（函数对象），按名称匹配。

// 第三题：统计分析
// 在 Warehouse<T> 中补充以下功能：


// // 6. 统计库存总价值（用 accumulate 算法）
// double getTotalInventoryValue() const;

// // 7. 统计单价大于指定值的商品个数（用 count_if + 一元谓词）
// int countPriceGreaterThan(double price) const;

// // 8. 将库存数量低于阈值的商品数量翻倍补货（用 replace_if 或手动 + 函数对象）
// //    需求：如果商品数量 < threshold，则 count = count * 2
// void restock(T threshold);
// 第四题：类模板与友元
// 为 Goods<T> 类添加一个全局友元函数（类外实现），用于比较两个商品的库存价值高低：


// template<class T>
// bool isMoreValuable(const Goods<T>& a, const Goods<T>& b);
// // 返回 a 的总价值 > b 的总价值
// 提示：参考你 7.类模板与友元.cpp 的写法，需要提前声明，并在类内加 friend ... <>。

// 第五题：测试用例
// 写一个 test() 函数，创建 Warehouse<int> 对象，执行以下操作：

// 添加 5 个以上商品（如："苹果" 50个 ¥3.5，"香蕉" 30个 ¥2.0，"橙子" 20个 ¥5.0，"西瓜" 5个 ¥15.0，"葡萄" 100个 ¥8.0）
// 打印所有商品
// 按总价值降序排序后再次打印
// 查找"橙子"并打印其信息
// 统计库存总价值
// 统计单价 > ¥4.0 的商品个数
// 删除"西瓜"后打印
// 对库存数量 < 30 的商品执行补货（翻倍），再次打印
// 涉及知识点对照
// 知识点	题目位置
// 类模板	第一题 Goods<T>、第二题 Warehouse<T>
// 成员函数类外实现	第一题
// 类模板与友元	第四题
// vector 存放自定义类型	第二题 m_goods
// 函数对象（一元/二元谓词）	第二题(打印、排序、查找)、第三题(count_if)
// for_each 遍历	第二题 printAll
// sort 排序	第二题 sortByValue
// find_if 条件查找	第二题 findGoods
// count_if 条件统计	第三题
// accumulate 累加	第三题
// replace_if 条件替换	第三题（可选实现）
// operator== 重载	第一题
// 💡 提示
// accumulate 的头文件是 <numeric>
// sort 的自定义比较函数对象需要 operator()(const Goods<T>& a, const Goods<T>& b) const 返回 bool
// 第四题的友元声明格式：friend bool isMoreValuable<>(const Goods<T>& a, const Goods<T>& b);（注意 <>）
// 多数题目有多种实现方法，优先用 STL 算法