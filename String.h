#pragma once
#include <iostream>
#include <cstddef>

class String {
public:
	//Constructors
	String();
	String(const char* str);
	String(const String& other);
	String(String&& other) noexcept;

	//Destructor
	~String();

	//Member Functions
	size_t Length() const;
	char& CharacterAt(size_t index);
	const char& CharacterAt(size_t index) const;
	bool EqualTo(const String& other) const;
	String& Append(const String& str);
	String& Prepend(const String& str);
	const char* CStr() const;
	String& ToLower();
	String& ToUpper();
	size_t Find(const String& str) const;
	size_t Find(size_t startIndex, const String& str) const;
	String& Replace(const String& find, const String& replace);
	String& ReadFromConsole();
	const String& WriteToConsole() const;

	String& Wobble();

	//Overloads
	bool operator==(const String& other) const;
	bool operator!=(const String& other) const;
	bool operator<(const String& other) const;
	bool operator>(const String& other) const;
	String& operator=(const String& str);
	String& operator=(String&& other) noexcept;
	char& operator[](size_t index);
	const char& operator[](size_t index) const;
	String operator+(const String& other) const;
	String& operator+=(const String& other);
	friend std::ostream& operator<<(std::ostream& out, const String& str);
	friend std::istream& operator>>(std::istream& in, String& str);

private:
	char* _str;
	enum class AdoptPointer {};
	String(AdoptPointer, char* str);
};
