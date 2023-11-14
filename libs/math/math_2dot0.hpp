#include <cassert>
#include <cmath>

//Векторы
template <class T>
class vec2 {
public:
	T x, y;

	vec2() :x(0), y(0) {}
	vec2(T x) : x(x), y(0) {}
	vec2(T x, T y) : x(x), y(y) {}
	vec2(const vec2<double>& v) : x(v.x), y(v.y) {}

	vec2& operator=(const vec2& v) {
		x = v.x;
		y = v.y;
		return *this;
	}

	vec2 operator+(vec2& v) {
		return vec2(x + v.x, y + v.y);
	}
	vec2 operator-(vec2& v) {
		return vec2(x - v.x, y - v.y);
	}

	vec2& operator+=(vec2& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	vec2& operator-=(vec2& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	vec2 operator+(double s) {
		return vec2(x + s, y + s);
	}
	vec2 operator-(double s) {
		return vec2(x - s, y - s);
	}
	vec2 operator*(double s) {
		return vec2(x * s, y * s);
	}
	vec2 operator/(double s) {
		return vec2(x / s, y / s);
	}


	vec2& operator+=(double s) {
		x += s;
		y += s;
		return *this;
	}
	vec2& operator-=(double s) {
		x -= s;
		y -= s;
		return *this;
	}
	vec2& operator*=(double s) {
		x *= s;
		y *= s;
		return *this;
	}
	vec2& operator/=(double s) {
		x /= s;
		y /= s;
		return *this;
	}

	bool operator==(vec2& v) {
		return (x == v.x && y == v.y);
	}

	bool operator!=(vec2& v) {
		return (x != v.x || y != v.y);
	}

	void set(T x, T y) {
		this->x = x;
		this->y = y;
	}

	vec2& normalize() {
		if (length() == 0) return *this;
		*this *= (1.0 / length());
		return *this;
	}

	float length() const {
		return std::sqrt(x * x + y * y);
	}

	static double dot(vec2 v1, vec2 v2) {
		return (v1.x * v2.x) + (v1.y * v2.y);
	}

};

template <class T>
class vec3 {
public:
	T x, y, z;

	vec3() :x(0), y(0), z(0) {}
	vec3(T x) : x(x), y(0), z(0) {}
	vec3(T x, T y) : x(x), y(y), z(0) {}
	vec3(T x, T y, T z) : x(x), y(y), z(z) {}
	vec3(const vec3<double>& v) : x(v.x), y(v.y), z(v.z) {}

	vec3& operator=( vec3& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	vec3 operator+(vec3& v) const {
		return vec3(x + v.x, y + v.y, z + v.z);
	}
	vec3 operator-(vec3& v) const {
		return vec3(x - v.x, y - v.y, z - v.z);
	}

	vec3& operator+=(vec3& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	vec3& operator-=(vec3& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	vec3 operator+(double s) const {
		return vec3(x + s, y + s, z + s);
	}
	vec3 operator-(double s) const {
		return vec3(x - s, y - s, z - s);
	}
	vec3 operator*(double s) const {
		return vec3(x * s, y * s, z * s);
	}
	vec3 operator/(double s) const {
		return vec3(x / s, y / s, z / s);
	}

	vec3& operator+=(double s) {
		x += s;
		y += s;
		z += s;
		return *this;
	}
	vec3& operator-=(double s) {
		x -= s;
		y -= s;
		z -= s;
		return *this;
	}
	vec3& operator*=(double s) {
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	vec3& operator/=(double s) {
		x /= s;
		y /= s;
		z /= s;
		return *this;
	}

	bool operator==(vec3& v) {
		return (x == v.x && y == v.y && z == v.z);
	}

	bool operator!=(vec3& v) {
		return (x != v.x || y != v.y || z != v.z);
	}

	void set(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& normalize() {
		if (length() == 0) return *this;
		*this *= (1.0 / length());
		return *this;
	}

	double length() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	double dot(vec3 v1) {
		return (v1.x * x) + (v1.y * y) + (v1.z * z);
	}
	vec3 cross(vec3 v1) {
		return vec3((v1.y * z) - (v1.z * y), (v1.z * x) - (v1.x * z), (v1.x * y) - (v1.y * x));
	}

};

template <class T>
class vec4 {
public:
	T x, y, z, w;

	vec4() :x(0), y(0), z(0), w(0) {}
	vec4(T x) : x(x), y(0), z(0), w(0) {}
	vec4(T x, T y) : x(x), y(y), z(0), w(0) {}
	vec4(T x, T y, T z) : x(x), y(y), z(z), w(0) {}
	vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
	vec4(const vec4<double>& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

	vec4& operator=(const vec4& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
		return *this;
	}

	vec4 operator+(const vec4& v) const {
		return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
	}
	vec4 operator-(vec4& v) const {
		return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
	}

	vec4& operator+=(vec4& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	vec4& operator-=(vec4& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	vec4 operator+(double s) const {
		return vec4(x + s, y + s, z + s, w + s);
	}
	vec4 operator-(double s) const {
		return vec4(x - s, y - s, z - s, w - s);
	}
	vec4 operator*(double s) const {
		return vec4(x * s, y * s, z * s, w * s);
	}
	vec4 operator/(double s) const {
		return vec4(x / s, y / s, z / s, w / s);
	}


	vec4& operator+=(double s) {
		x += s;
		y += s;
		z += s;
		return *this;
	}
	vec4& operator-=(double s) {
		x -= s;
		y -= s;
		z -= s;
		return *this;
	}
	vec4& operator*=(double s) {
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	vec4& operator/=(double s) {
		x /= s;
		y /= s;
		z /= s;
		return *this;
	}

	bool operator==(vec4& v) const {
		return (x == v.x && y == v.y && z == v.z && w == v.w);
	}

	bool operator!=(vec4& v) const {
		return (x != v.x || y != v.y || z != v.z || w != v.w);
	}

	void set(T x, T y, T z, T w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4& normalize() {
		if (length() == 0) return *this;
		*this *= (1.0 / length());
		return *this;
	}
	double length() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	double& operator[](int i) {
		assert(i >= 0 && i <= 3);
		return (i == 0) ? x : ((i == 1) ? y : ((i == 2) ? z : w));
	};
	double const& operator[](int i) const {
		assert(i >= 0 && i <= 3);
		return (i == 0) ? x : ((i == 1) ? y : ((i == 2) ? z : w));
	};

	static double dot(vec4 v1, vec4 v2) {
		return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	}
	static double cross(vec4 v1, vec4 v2) {
		return vec4((v1.y * v2.z) - (v1.z * v2.y), (v1.z * v2.x) - (v1.x * v2.z), (v1.x * v2.y) - (v1.y * v2.x));
	}

};


//Матрицы
class mat2 {
private:
	double* data;
public:
	//База
	mat2() {
		data = (double*)calloc(4, sizeof(double));
	};
	~mat2() {
		free(data);
	};
	mat2(mat2&& m) {
		data = (double*)calloc(4, sizeof(double));
		data = m.data;
		m.data = nullptr;
	};
	mat2& operator=(mat2&& m) {
		data = m.data;
		m.data = nullptr;
		return *this;
	};
	template <typename T,
		typename = std::enable_if_t<std::is_arithmetic<T>::value>>
		mat2(const T other) {
		data = (double*)calloc(4, sizeof(double));
		data[0] = static_cast<double>(other);
		data[3] = data[0];
	}
	template<typename... Args>
	mat2(Args&&... args) {
		data = (double*)calloc(4, sizeof(double));
		int i = 0;
		for (auto j : { args... })
			data[i++] = static_cast<double>(j);
	}
	mat2(const mat2& m) {
		data = (double*)calloc(4, sizeof(double));
		std::memcpy(data, m.data, sizeof(double) * 4);
	};

	//Операторы сравнения
	bool operator==(const mat2& m) const {
		return (!memcmp(data, m.data, sizeof(double) * 4));
	}
	bool operator!=(const mat2& m) const {
		return !(*this == m);
	};

	//Операторы +, -, *, /
	mat2 operator+(const mat2& m) {
		mat2 matrix;
		for (int i = 0; i < 4; ++i)
			matrix.data[i] = data[i] + m.data[i];
		return matrix;
	};
	mat2 operator+(const double m) const {
		mat2 matrix;
		for (int i = 0; i < 4; ++i)
			matrix.data[i] = data[i] + m;
		return matrix;
	};
	mat2& operator+=(const mat2& m) {
		for (int i = 0; i < 4; ++i)
			data[i] += m.data[i];
		return *this;
	};
	mat2& operator+=(const double m) {
		for (int i = 0; i < 4; ++i)
			data[i] += m;
		return *this;
	};
	mat2 operator-(const mat2& m) {
		mat2 matrix;
		for (int i = 0; i < 4; ++i)
			matrix.data[i] = data[i] - m.data[i];
		return m;
	};
	mat2 operator-(const double m) const {
		mat2 matrix;
		for (int i = 0; i < 4; ++i)
			matrix.data[i] = data[i] - m;
		return matrix;
	};
	mat2& operator-=(const mat2& m) {
		for (int i = 0; i < 4; ++i)
			data[i] -= m.data[i];
		return *this;
	};
	mat2& operator-=(const double m) {
		for (int i = 0; i < 4; ++i)
			data[i] -= m;
		return *this;
	};
	mat2 operator*(const mat2& m) const {
		mat2 matrix;
		matrix.data[0] = (data[0] * m.data[0]) + (data[1] * m.data[2]);
		matrix.data[1] = (data[0] * m.data[1]) + (data[1] * m.data[3]);
		matrix.data[2] = (data[2] * m.data[0]) + (data[3] * m.data[2]);
		matrix.data[3] = (data[2] * m.data[1]) + (data[3] * m.data[3]);
		return matrix;
	};
	mat2 operator*(const double m) const {
		mat2 matrix;
		for (int i = 0; i < 4; ++i)
			matrix.data[i] = data[i] * m;
		return matrix;
	};
	vec2<double> operator*(const vec2<double>& v) const {
		vec2<double> vec;
		vec.x = data[0] * v.x + data[1] * v.y;
		vec.y = data[2] * v.x + data[3] * v.y;
		return vec;
	};
	mat2& operator*=(const mat2& m) {
		mat2 matrix;
		matrix.data[0] = (data[0] * m.data[0]) + (data[1] * m.data[2]);
		matrix.data[1] = (data[0] * m.data[1]) + (data[1] * m.data[3]);
		matrix.data[2] = (data[2] * m.data[0]) + (data[3] * m.data[2]);
		matrix.data[3] = (data[2] * m.data[1]) + (data[3] * m.data[3]);
		*this = std::move(matrix);
		return *this;
	};
	mat2& operator*=(const double m) {
		for (int i = 0; i < 4; ++i)
			data[i] *= m;
		return *this;
	};
	mat2 operator/(const double m) const {
		mat2 matrix;
		for (int i = 0; i < 4; ++i)
			matrix.data[i] = data[i] / m;
		return matrix;
	};
	mat2& operator/=(const double m) {
		for (int i = 0; i < 4; ++i)
			data[i] /= m;
		return *this;
	};

	//Оператор индекса
	double& operator[](int i) {
		assert(i >= 0 && i <= 3);
		return data[i];
	};
	double const& operator[](int i) const {
		assert(i >= 0 && i <= 3);
		return data[i];
	};

	//Функции
	double det() const { //Определитель
		return (data[0] * data[3]) - (data[1] * data[2]);
	};
	mat2 inverse() const { //Поиск обратной матрицы
		mat2 inv(*this);
		assert(this->det() != 0);
		std::swap(inv.data[0], inv.data[3]);
		inv.data[1] *= -1;
		inv.data[2] *= -1;
		for (size_t i = 0; i < 4; ++i)
			inv.data[i] /= this->det();
		return inv;
	};
	mat2 trans() const { //Транспанированная матрица
		mat2 t(*this);
		std::swap(t.data[1], t.data[2]);
		return t;
	};

	//Вычленение строк и столбцов
	vec2<double> row(int i) {
		assert(i >= 0 && i <= 1);
		return vec2<double>(data[i * 2], data[i * 2 + 1]);
	};
	vec2<double> row(int i) const {
		assert(i >= 0 && i <= 1);
		return vec2<double>(data[i * 2], data[i * 2 + 1]);
	};
	vec2<double> column(int i) {
		assert(i >= 0 && i <= 1);
		return vec2<double>(data[i], data[i + 2]);
	};
	vec2<double> column(int i) const {
		assert(i >= 0 && i <= 1);
		return vec2<double>(data[i], data[i + 2]);
	};

};

class mat3 {
private:
	double* data;
public:
	//База
	mat3() {
		data = (double*)calloc(9, sizeof(double));
	};
	~mat3() {
		free(data);
	};
	mat3(mat3&& m) {
		data = (double*)calloc(9, sizeof(double));
		data = m.data;
		m.data = nullptr;
	};
	mat3& operator=(mat3&& m) {
		data = m.data;
		m.data = nullptr;
		return *this;
	};
	template<typename T>
	mat3(T v) {
		data = (double*)calloc(9, sizeof(double));
		data[0] = static_cast<double>(v);
		data[4] = data[0];
		data[8] = data[0];
	}
	template<typename... Args>
	mat3(Args... args) {
		data = (double*)calloc(9, sizeof(double));
		int i = 0;
		for (auto j : { args... })
			data[i++] = static_cast<double>(j);
	}
	mat3(const mat3& m) {
		data = (double*)calloc(9, sizeof(double));
		std::memcpy(data, m.data, sizeof(double) * 9);
	};

	//Операторы сравнения
	bool operator==(const mat3& m) const {
		return (!memcmp(data, m.data, sizeof(double) * 9));
	}
	bool operator!=(const mat3& m) const {
		return !(*this == m);
	};

	//Операторы +, -, *, /
	mat3 operator+(const mat3& m) {
		mat3 matrix;
		for (int i = 0; i < 9; ++i)
			matrix.data[i] = data[i] + m.data[i];
		return matrix;
	};
	mat3 operator+(const double m) const {
		mat3 matrix;
		for (int i = 0; i < 9; ++i)
			matrix.data[i] = data[i] + m;
		return matrix;
	}
	mat3& operator+=(const mat3& m) {
		for (int i = 0; i < 9; ++i)
			data[i] += m.data[i];
		return *this;
	};
	mat3& operator+=(const double m) {
		for (int i = 0; i < 9; ++i)
			data[i] += m;
		return *this;
	}
	mat3 operator-(const mat3& m) {
		mat3 matrix;
		for (int i = 0; i < 9; ++i)
			matrix.data[i] = data[i] - m.data[i];
		return m;
	};
	mat3 operator-(const double m) const {
		mat3 matrix;
		for (int i = 0; i < 9; ++i)
			matrix.data[i] = data[i] - m;
		return matrix;
	}
	mat3& operator-=(const mat3& m) {
		for (int i = 0; i < 9; ++i)
			data[i] -= m.data[i];
		return *this;
	};
	mat3& operator-=(const double m) {
		for (int i = 0; i < 9; ++i)
			data[i] -= m;
		return *this;
	}
	mat3 operator*(const mat3& m) const {
		mat3 matrix;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j) {
				matrix[i * 3 + j] = 0;
				for (int k = 0; k < 3; ++k)
					matrix[i * 3 + j] += m[i * 3 + k] * data[k * 3 + j];
			}
		return matrix;
	}
	mat3 operator*(const double m) const {
		mat3 matrix;
		for (int i = 0; i < 9; ++i)
			matrix.data[i] = data[i] * m;
		return matrix;
	}
	vec3<double> operator*(const vec3<double>& v) const {
		vec3<double> vec;
		vec.x = data[0] * v.x + data[1] * v.y + data[2] * v.z;
		vec.y = data[3] * v.x + data[4] * v.y + data[5] * v.z;
		vec.z = data[6] * v.x + data[7] * v.y + data[8] * v.z;
		return vec;
	}
	mat3& operator*=(const mat3& m) {
		mat3 matrix;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j) {
				matrix[i * 3 + j] = 0;
				for (int k = 0; k < 3; ++k)
					matrix[i * 3 + j] += m[i * 3 + k] * data[k * 3 + j];
			}
		*this = std::move(matrix);
		return *this;
	}
	mat3& operator*=(const double m) {
		for (int i = 0; i < 9; ++i)
			data[i] *= m;
		return *this;
	}
	mat3 operator/(const double m) const {
		mat3 matrix;
		for (size_t i = 0; i < 9; ++i)
			matrix.data[i] = data[i] / m;
		return matrix;
	}
	mat3& operator/=(const double m) {
		for (size_t i = 0; i < 9; ++i)
			data[i] /= m;
		return *this;
	}

	//Операторы индекса
	double& operator[](int i) {
		assert(i >= 0 && i <= 8);
		return data[i];
	};
	double const& operator[](int i) const {
		assert(i >= 0 && i <= 8);
		return data[i];
	};

	//Функции
	double det() const { //Определитель
		return 
			data[0] * ((data[4] * data[8]) - (data[5] * data[7])) -
			data[1] * ((data[3] * data[8]) - (data[5] * data[6])) +
			data[2] * ((data[3] * data[7]) - (data[4] * data[6]));
	}
	mat3 inverse() const { //Поиск обратной матрицы
		assert(this->det() != 0);
		mat3 inverse(
			(data[4] * data[8] - data[5] * data[7]) / this->det(),
			-(data[1] * data[8] - data[2] * data[7]) / this->det(),
			(data[1] * data[5] - data[2] * data[4]) / this->det(),
			-(data[3] * data[8] - data[5] * data[6]) / this->det(),
			(data[0] * data[8] - data[2] * data[6]) / this->det(),
			-(data[0] * data[5] - data[2] * data[3]) / this->det(),
			(data[3] * data[7] - data[4] * data[6]) / this->det(),
			-(data[0] * data[7] - data[1] * data[6]) / this->det(),
			(data[0] * data[4] - data[1] * data[3]) / this->det()
		);
		return inverse;
	}
	mat3 trans() const { //Транспонированная матрица
		mat3 t(*this);
		std::swap(t.data[1], t.data[3]);
		std::swap(t.data[2], t.data[6]);
		std::swap(t.data[5], t.data[7]);
		return t;
	}

	//Вычленение строк и столбцов
	vec3<double> row(int i) {
		assert(i >= 0 && i <= 2);
		return vec3<double>(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
	};
	vec3<double> row(int i) const {
		assert(i >= 0 && i <= 2);
		return vec3<double>(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
	};
	vec3<double> column(int i) {
		assert(i >= 0 && i <= 2);
		return vec3<double>(data[i], data[i + 3], data[i + 6]);
	};
	vec3<double> column(int i) const {
		assert(i >= 0 && i <= 2);
		return vec3<double>(data[i], data[i + 3], data[i + 6]);
	};

};

class mat4 {
private:
	double* data;
public:
	//База
	mat4() {
		data = (double*)calloc(16, sizeof(double));
	};
	~mat4() {
		free(data);
	};
	mat4(mat4&& m) {
		data = (double*)calloc(16, sizeof(double));
		data = m.data;
		m.data = nullptr;
	};
	mat4& operator=(mat4&& m) {
		data = m.data;
		m.data = nullptr;
		return *this;
	};
	mat4(const mat4& m) {
		data = (double*)calloc(16, sizeof(double));
		std::memcpy(data, m.data, sizeof(double) * 16);
	}
	template<typename T>
	mat4(const T& v) {
		data = (double*)calloc(16, sizeof(double));
		data[0] = static_cast<double>(v);
		data[5] = data[0];
		data[10] = data[0];
		data[15] = data[0];
	}
	template<typename... Args>
	mat4( Args... args) {
		data = (double*)calloc(16, sizeof(double));
		int i = 0;
		for (auto j : { args... })
			data[i++] = static_cast<double>(j);
	}
	
	mat4(const vec4<double>& v1, const vec4<double>& v2, const vec4<double>& v3, const vec4<double>& v4) {
		data = (double*)calloc(16, sizeof(double));
		data[0] = v1.x, data[1] = v1.y, data[2] = v1.z, data[3] = v1.w;
		data[4] = v2.x, data[5] = v2.y, data[6] = v2.z, data[7] = v2.w;
		data[8] = v3.x, data[9] = v3.y, data[10] = v3.z, data[11] = v3.w;
		data[12] = v4.x, data[13] = v4.y, data[14] = v4.z, data[15] = v4.w;
	}

	//Операторы сравнения
	bool operator==(const mat4& m) const {
		return (!memcmp(data, m.data, sizeof(double) * 16));
	}
	bool operator!=(const mat4& m) const {
		return !(*this == m);
	};

	//Операторы +, -, *, /
	mat4 operator+(const mat4& m) {
		mat4 matrix;
		for (int i = 0; i < 16; ++i)
			matrix.data[i] = data[i] + m.data[i];
		return matrix;
	};
	mat4 operator+(const double m) const {
		mat4 matrix;
		for (int i = 0; i < 16; ++i)
			matrix.data[i] = data[i] + m;
		return matrix;
	}
	mat4& operator+=(const mat4& m) {
		for (int i = 0; i < 16; ++i)
			data[i] += m.data[i];
		return *this;
	};
	mat4& operator+=(const double m) {
		for (int i = 0; i < 16; ++i)
			data[i] += m;
		return *this;
	}
	mat4 operator-(const mat4& m) {
		mat4 matrix;
		for (int i = 0; i < 16; ++i)
			matrix.data[i] = data[i] - m.data[i];
		return m;
	};
	mat4 operator-(const double m) const {
		mat4 matrix;
		for (int i = 0; i < 16; ++i)
			matrix.data[i] = data[i] - m;
		return matrix;
	}
	mat4& operator-=(const mat4& m) {
		for (int i = 0; i < 16; ++i)
			data[i] -= m.data[i];
		return *this;
	};
	mat4& operator-=(const double m) {
		for (int i = 0; i < 16; ++i)
			data[i] -= m;
		return *this;
	}
	mat4 operator*(const mat4& m) const {
		mat4 matrix;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrix[i * 4 + j] = 0;
				for (int k = 0; k < 4; k++)
					matrix[i * 4 + j] += m[i * 4 + k] * data[k * 4 + j];
			}
		}
		return matrix;
	}
	mat4 operator*(const double m) const {
		mat4 matrix;
		for (int i = 0; i < 16; ++i)
			matrix.data[i] = data[i] * m;
		return matrix;
	}
	vec4<double> operator*(const vec4<double>& v) const {
		vec4<double> vec;
		vec.x = data[0] * v.x + data[1] * v.y + data[2] * v.z + data[3] * v.w;
		vec.y = data[4] * v.x + data[5] * v.y + data[6] * v.z + data[7] * v.w;
		vec.z = data[8] * v.x + data[9] * v.y + data[10] * v.z + data[11] * v.w;
		vec.w = data[12] * v.x + data[13] * v.y + data[14] * v.z + data[15] * v.w;
		return vec;
	}
	mat4& operator*=(const mat4& m) {
		mat4 matrix;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrix[i * 4 + j] = 0;
				for (int k = 0; k < 4; k++)
					matrix[i * 4 + j] += m[i * 4 + k] * data[k * 4 + j];
			}
		}
		*this = std::move(matrix);
		return *this;
	}
	mat4& operator*=(const double m) {
		for (int i = 0; i < 16; ++i)
			data[i] *= m;
		return *this;
	}
	mat4 operator/(const double m) const {
		mat4 matrix;
		for (int i = 0; i < 9; ++i)
			matrix.data[i] = data[i] / m;
		return matrix;
	}
	mat4& operator/=(const double m) {
		for (int i = 0; i < 9; ++i)
			data[i] /= m;
		return *this;
	}

	//Операторы индекса
	double& operator[](int i) {
		assert(i >= 0 && i <= 15);
		return data[i];
	};
	double const& operator[](int i) const {
		assert(i >= 0 && i <= 15);
		return data[i];
	};
	//Функции
	double det() const { //Определитель
		return data[0] * (data[5] * data[10] * data[15] -
				data[5] * data[11] * data[14] -
				 data[9] * data[6] * data[15] +
				 data[9] * data[7] * data[14] +
				 data[13] * data[6] * data[11] -
				 data[13] * data[7] * data[10])
			+ data[1] * (-data[4] * data[10] * data[15] +
				data[4] * data[11] * data[14] +
				data[8] * data[6] * data[15] -
				data[8] * data[7] * data[14] -
				data[12] * data[6] * data[11] +
				data[12] * data[7] * data[10])
			+ data[2] * (data[4] * data[9] * data[15] -
				data[4] * data[11] * data[13] -
				data[8] * data[5] * data[15] +
				data[8] * data[7] * data[13] +
				data[12] * data[5] * data[11] -
				data[12] * data[7] * data[9])
			+ data[3] * (-data[4] * data[9] * data[14] +
				data[4] * data[10] * data[13] +
				data[8] * data[5] * data[14] -
				data[8] * data[6] * data[13] -
				data[12] * data[5] * data[10] +
				data[12] * data[6] * data[9]);

	}
	mat4 inverse() const { //Поиск обратной матрицы
		double det = this->det();
		assert(det != 0);
		mat4 inverse(
			(data[5] * data[10] * data[15] -
				data[5] * data[11] * data[14] -
				data[9] * data[6] * data[15] +
				data[9] * data[7] * data[14] +
				data[13] * data[6] * data[11] -
				data[13] * data[7] * data[10]) / det,
			(-data[1] * data[10] * data[15] +
				data[1] * data[11] * data[14] +
				data[9] * data[2] * data[15] -
				data[9] * data[3] * data[14] -
				data[13] * data[2] * data[11] +
				data[13] * data[3] * data[10]) / det,
			(data[1] * data[6] * data[15] -
				data[1] * data[7] * data[14] -
				data[5] * data[2] * data[15] +
				data[5] * data[3] * data[14] +
				data[13] * data[2] * data[7] -
				data[13] * data[3] * data[6]) / det,
			(-data[1] * data[6] * data[11] +
				data[1] * data[7] * data[10] +
				data[5] * data[2] * data[11] -
				data[5] * data[3] * data[10] -
				data[9] * data[2] * data[7] +
				data[9] * data[3] * data[6]) / det,
			(-data[4] * data[10] * data[15] +
				data[4] * data[11] * data[14] +
				data[8] * data[6] * data[15] -
				data[8] * data[7] * data[14] -
				data[12] * data[6] * data[11] +
				data[12] * data[7] * data[10]) / det,
			(data[0] * data[10] * data[15] -
				data[0] * data[11] * data[14] -
				data[8] * data[2] * data[15] +
				data[8] * data[3] * data[14] +
				data[12] * data[2] * data[11] -
				data[12] * data[3] * data[10]) / det,
			(-data[0] * data[6] * data[15] +
				data[0] * data[7] * data[14] +
				data[4] * data[2] * data[15] -
				data[4] * data[3] * data[14] -
				data[12] * data[2] * data[7] +
				data[12] * data[3] * data[6]) / det,
			(data[0] * data[6] * data[11] -
				data[0] * data[7] * data[10] -
				data[4] * data[2] * data[11] +
				data[4] * data[3] * data[10] +
				data[8] * data[2] * data[7] -
				data[8] * data[3] * data[6]) / det,
			(data[4] * data[9] * data[15] -
				data[4] * data[11] * data[13] -
				data[8] * data[5] * data[15] +
				data[8] * data[7] * data[13] +
				data[12] * data[5] * data[11] -
				data[12] * data[7] * data[9]) / det,
			(-data[0] * data[9] * data[15] +
				data[0] * data[11] * data[13] +
				data[8] * data[1] * data[15] -
				data[8] * data[3] * data[13] -
				data[12] * data[1] * data[11] +
				data[12] * data[3] * data[9]) / det,
			(data[0] * data[5] * data[15] -
				data[0] * data[7] * data[13] -
				data[4] * data[1] * data[15] +
				data[4] * data[3] * data[13] +
				data[12] * data[1] * data[7] -
				data[12] * data[3] * data[5]) / det,
			(-data[0] * data[5] * data[11] +
				data[0] * data[7] * data[9] +
				data[4] * data[1] * data[11] -
				data[4] * data[3] * data[9] -
				data[8] * data[1] * data[7] +
				data[8] * data[3] * data[5]) / det,
			(-data[4] * data[9] * data[14] +
				data[4] * data[10] * data[13] +
				data[8] * data[5] * data[14] -
				data[8] * data[6] * data[13] -
				data[12] * data[5] * data[10] +
				data[12] * data[6] * data[9]) / det,
			(data[0] * data[9] * data[14] -
				data[0] * data[10] * data[13] -
				data[8] * data[1] * data[14] +
				data[8] * data[2] * data[13] +
				data[12] * data[1] * data[10] -
				data[12] * data[2] * data[9]) / det,
			(-data[0] * data[5] * data[14] +
				data[0] * data[6] * data[13] +
				data[4] * data[1] * data[14] -
				data[4] * data[2] * data[13] -
				data[12] * data[1] * data[6] +
				data[12] * data[2] * data[5]) / det,
			(data[0] * data[5] * data[10] -
				data[0] * data[6] * data[9] -
				data[4] * data[1] * data[10] +
				data[4] * data[2] * data[9] +
				data[8] * data[1] * data[6] -
				data[8] * data[2] * data[5]) / det
		);

		return inverse;
	}
	mat4 trans() const { //Транспонированная матрица
		mat4 t(*this);
		for (int i = 0; i < 4; ++i)
			for (int j = i + 1; j < 4; ++j)
				std::swap(t.data[i * 4 + j], t.data[j * 4 + i]);
		return t;
	}
	//Вычленение строк и столбцов
	vec4<double> row(int i) {
		assert(i >= 0 && i <= 3);
		return vec4<double>(data[i * 4], data[i * 4 + 1], data[i * 4 + 2], data[i * 4 + 3]);
	};
	vec4<double> row(int i) const {
		assert(i >= 0 && i <= 3);
		return vec4<double>(data[i * 4], data[i * 4 + 1], data[i * 4 + 2], data[i * 4 + 3]);
	};
	vec4<double> column(int i) {
		assert(i >= 0 && i <= 2);
		return vec4<double>(data[i], data[i + 4], data[i + 8], data[i + 12]);
	};
	vec4<double> column(int i) const {
		assert(i >= 0 && i <= 2);
		return vec4<double>(data[i], data[i + 4], data[i + 8], data[i + 12]);
	};

	mat4 translate(const vec3<double>& vec) {
		mat4 matrix(*this);
		matrix[3] = vec.x;
		matrix[7] = vec.y;
		matrix[11] = vec.z;
		return matrix;
	}

	mat4 scale(const vec3<double>& vec) {
		mat4 matrix(*this);
		matrix[0] = vec.x;
		matrix[5] = vec.y;
		matrix[10] = vec.z;
		return matrix;
	}

	mat4 rotate(vec3<double>& vec, double angle) {
		double const cosa = cos(angle);
		double const sina = sin(angle);

		vec3<double> axis = vec.normalize();
		vec3<double> temp(axis * (1.f - cosa));
		
		mat4 rotate;
		rotate[0] = cosa + temp.x * axis.x;
		rotate[1] = temp.x * axis.y + sina * axis.z;
		rotate[2] = temp.x * axis.z - sina * axis.y;

		rotate[4] = temp.y * axis.x - sina * axis.z;
		rotate[5] = cosa + temp.y * axis.y;
		rotate[6] = temp.y * axis.z + sina * axis.x;

		rotate[8] = temp.z * axis.x + sina * axis.y;
		rotate[9] = temp.z * axis.y - sina * axis.x;
		rotate[10] = cosa + temp.z * axis.z;

		vec4<double> temp1 = (row(0) * rotate[0]) + (row(1) * rotate[1]) + (row(2) * rotate[2]);
		vec4<double> temp2 = (row(0) * rotate[4]) + (row(1) * rotate[5]) + (row(2) * rotate[6]);
		vec4<double> temp3 = (row(0) * rotate[8]) + (row(1) * rotate[9]) + (row(2) * rotate[10]);
		return mat4(temp1, temp2, temp3, row(3));
	}

	mat4 ortho(double left, double right, double bottom, double top, double near, double far) {
		mat4 matrix(1.f);
		matrix[0] = 2 / (right - left);
		matrix[5] = 2 / (top - bottom);
		matrix[10] = -2 / (far - near);
		matrix[12] = -(right + left) / (right - left);
		matrix[13] = -(top + bottom) / (top - bottom);
		matrix[14] = -(far + near) / (far - near);
		return matrix;
	}


	mat4 lookAt(vec3<double>& cameraPos, vec3<double>& cameraTarget, vec3<double>& upVector) {
		vec3<double> f = cameraTarget - cameraPos;
		f.normalize();
		vec3<double> s = f.cross(upVector).normalize();
		vec3<double> u = s.cross(f);

		mat4 matrix(1.f);
		matrix[0] = s.x;
		matrix[4] = s.y;
		matrix[8] = s.z;
		matrix[1] = u.x;
		matrix[5] = u.y;
		matrix[9] = u.z;
		matrix[2] = -f.x;
		matrix[6] = -f.y;
		matrix[10] = -f.z;
		matrix[12] = -1 * (s.dot(cameraPos));
		matrix[13] = -1 * (u.dot(cameraPos));
		matrix[14] = (f.dot(cameraPos));
		return matrix;
	}

	mat4 perspective(double fov, double ratio, double near, double far) {
		mat4 matrix;
		double tg = tan(fov / 2);
		matrix = 1.f / (ratio * tg);
		matrix[5] = 1.f / tg;
		matrix[10] = far / (near - far);
		matrix[14] = (2.f * far * near) / (near - far);
		matrix[11] = -1;
		return matrix;
	}
};