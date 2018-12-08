#include "MyString.h"

MyString::MyString()
{
	str = NULL;
	str_size = 0;
	str_capacity = 15;
}
MyString::MyString(const MyString& other){
	construction(other.str);
}
MyString::MyString(const char* other){
	construction(other);
}
MyString::MyString(const MyString& other, size_t pos, size_t len){
	int n = len;
	if (pos + len > other.str_size){
		n = other.str_size - pos;
	}
	char*s = new char[n + 1];
	for (int i = 0; i < n; i++){
		s[i] = other.str[pos + i];
	}
	s[n] = '\0';
	construction(s);
	delete[]s;
}
MyString::MyString(const char* other, size_t n){
	if (n>strlen(other)){
		n = strlen(other);
	}
	char* s = new char[n + 1];
	for (int i = 0; i < n; i++){
		s[i] = other[i];
	}
	s[n] = '\0';
	construction(s);
	delete[]s;
}
MyString::MyString(size_t n, char c){
	char* s = new char[n + 1];
	for (int i = 0; i < n; i++){
		s[i] = c;
	}
	s[n] = '\0';
	construction(s);
	delete[]s;
}
void MyString::construction(const char* other){
	str_size = strlen(other);
	str_capacity = 15;
	reserve(str_size);
	str = new char[str_capacity];
	for (int i = 0; i <= str_size; i++){
		str[i] = other[i];
	}
}

MyString::~MyString()
{
	if (str != NULL){
		delete[]str;
	}
}

MyString& MyString::operator =(const MyString& str2){
	str_size = str2.str_size;
	reserve(str_size);
	realloc(str, str_capacity + 1);
	for (int i = 0; i <= str_size; i++){
		str[i] = str2.str[i];
	}
	return *this;
}
MyString& MyString::operator=(const char* str2){
	long length = 0;
	while (str2[length] != '\0'){
		length++;
	}
	str_size = length;
	reserve(str_size);
	if (str == NULL){
		str = new char[str_capacity + 1];
	}
	else{
		realloc(str, str_capacity + 1);
	}
	for (long i = 0; i <= str_size; i++){
		str[i] = str2[i];
	}
	return *this;
}
MyString& MyString::operator=(char c){
	char str[2];
	str[0] = c;
	str[1] = '\0';
	return *this = str;
}

char* MyString::begin(){
	return str;
}

char* MyString::end(){
	return &str[str_size];
}
char* MyString::rbegin(){
	return &str[str_size - 1];
}
char* MyString::rend(){
	return str-1;
}
const char* MyString::cbegin()const {
	return str;
}
const char* MyString::cend()const{
	return &str[str_size];
}
const char* MyString::crbegin()const{
	return &str[str_size - 1];
}
const char* MyString::crend()const{
	return str - 1;
}
size_t MyString::size(){
	return str_size;
}
size_t MyString::length(){
	return str_size;
}
size_t MyString::max_size()const{
	return LONG_MAX*2-1;
}
void MyString::resize(size_t n){
	reserve(n);
	realloc(str, str_capacity+1);
	if (n < str_size){
		for (int i = n; i <= str_size; i++){
			str[i] = '\0';
		}
		str_size = n;
	}
	else if (n>str_size){
		for (int i = str_size; i <= n; i++){
			str[i] = '\0';
		}
		str[n] = '\0';
		str_size = n;
	}
}
void MyString::resize(size_t n, char c){
	reserve(n);
	realloc(str, str_capacity+1);
	if (n < str_size){
		resize(n);
	}
	else{
		for (int i = str_size; i <= n; i++){
			str[i] = c;
		}
		str_size = n;
	}
}
size_t MyString::capacity()const{
	return str_capacity;
}
void MyString::reserve(size_t n){
	while (n > str_capacity){
		str_capacity = (str_capacity + 1) * 2 - 1;
	}
}
void MyString::clear(){
	delete[]str;
	str_size = 0;
	str_capacity = 15;
}
bool MyString::empty()const{
	return str_size == 0;
}
void MyString::shrink_to_fit(){
	while (str_size < (str_capacity + 1) / 2 - 1){
		str_capacity = (str_capacity + 1) / 2 - 1;
	}
}
char& MyString::operator[](size_t pos){
	return str[pos];
}
char& MyString::at(size_t pos){
	return str[pos];
}
char& MyString::back(){
	return str[str_size - 1];
}
char& MyString::front(){
	return str[0];
}
MyString MyString::operator+(const MyString& rhs){
	return *this + rhs.str;
}
MyString MyString::operator+(const char* rhs){
	size_t len1 = str_size;
	size_t len2 = strlen(rhs);
	size_t len = len1 + len2 + 1;
	MyString newstr;
	newstr.reserve(len);
	newstr.str = new char[newstr.str_capacity];
	newstr.str_size = len-1;
	for (int i = 0; i < len1; i++){
		newstr.str[i] = str[i];
	}
	for (int i = 0; i <= len2; i++){
		newstr.str[i + len1] = rhs[i];
	}
	return newstr;
}
MyString MyString::operator+(char c){
	char str[2];
	str[0] = c;
	str[1] = '\0';
	return *this + str;
}
MyString operator+ (const MyString& lhs, const MyString& rhs){
	MyString str(lhs);
	return str + rhs;
}
MyString operator+ (const MyString& lhs, const char* rhs){
	return lhs + rhs;
}
MyString operator+ (const char* lhs, const MyString& rhs){
	MyString str(lhs);
	return lhs + rhs;
}
MyString operator+ (char c, const MyString& rhs){
	char str[2];
	str[0] = c;
	str[1] = '\0';
	return str + rhs;
}
MyString operator+ (const MyString& lhs,char c){
	char str[2];
	str[0] = c;
	str[1] = '\0';
	return lhs + str;
}
MyString& MyString::operator+=(const char* rhs){
	reserve(str_size+strlen(rhs));
	if (str != NULL){
		realloc(str, str_capacity);
	}
	else{
		str = new char[str_capacity];
	}
	for (int i = 0; i <= strlen(rhs); i++){
		str[i + str_size] = rhs[i];
	}
	str_size += strlen(rhs);
	return *this;
}
MyString& MyString::operator+=(const MyString& rhs){
	return *this += rhs.str;
}
MyString& MyString::operator+=(char c){
	char str[2];
	str[0] = c;
	str[1] = '\0';
	return *this += str;
}
MyString& MyString::append(const MyString& str){
	return append(str.str);
}
MyString& MyString::append(const MyString& str,size_t subpos,size_t sublen){
	char*substr;
	substr = new char[sublen + 1];
	for (int i = 0; i < sublen; i++){
		substr[i] = str.str[i + subpos];
	}
	substr[sublen] = '\0';
	append(substr);
	delete[]substr;
	return *this;
}
MyString& MyString::append(const char* str){
	return *this += str;
}
MyString& MyString::append(const char* str,size_t n){
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = str[i];
	}
	substr[n] = '\0';
	append(substr);
	delete[]substr;
	return *this;
}
MyString& MyString::append(size_t n, char c){
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = c;
	}
	substr[n] = '\0';
	append(substr);
	delete[]substr;
	return *this;
}
MyString& MyString::push_back(char c){
	char*str = new char[2];
	str[0] = c;
	str[1] = '\0';
	*this += str;
	delete[]str;
	return *this;
}
MyString& MyString::assign(const MyString& str){
	return *this = str;
}
MyString& MyString::assign(const MyString& str, size_t subpos, size_t sublen){
	char*substr;
	substr = new char[sublen + 1];
	for (int i = 0; i < sublen; i++){
		substr[i] = str.str[i + subpos];
	}
	substr[sublen] = '\0';
	*this = substr;
	delete[]substr;
	return *this;
}
MyString& MyString::assign(const char* str){
	return *this = str;
}
MyString& MyString::assign(const char* str, size_t n){
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = str[i];
	}
	substr[n] = '\0';
	*this = substr;
	delete[]substr;
	return*this;
}
MyString& MyString::assign(size_t n,char c){
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = c;
	}
	substr[n] = '\0';
	*this = substr;
	delete[]substr;
	return *this;
}
MyString& MyString::insert(size_t pos, const MyString& str){
	return insert(pos, str.str);
}
MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen){
	char*substr;
	substr = new char[sublen + 1];
	for (int i = 0; i < sublen; i++){
		substr[i] = str.str[i + subpos];
	}
	substr[sublen] = '\0';
	insert(pos,substr);
	delete[]substr;
	return *this;
}
MyString& MyString::insert(size_t pos, const char* src){
	str_size = str_size + strlen(src);
	reserve(str_size);
	realloc(str, str_capacity + 1);
	char* substr = new char[str_size - pos + 1];
	for (int i = pos; i <= str_size; i++){
		substr[i - pos] = str[i];
	}
	for (int i = 0; i <= strlen(str); i++){
		str[i + pos] = src[i];
	}
	*this += substr;
	delete[]substr;
	return*this;
}
MyString& MyString::insert(size_t pos, const char* src, size_t n){
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = str[i];
	}
	substr[n] = '\0';
	insert(pos, substr);
	delete[]substr;
	return*this;
}
MyString& MyString::insert(size_t pos,size_t n,char c){
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = c;
	}
	substr[n] = '\0';
	insert(pos, substr);
	delete[]substr;
	return *this;
}
MyString& MyString::erase(size_t pos, size_t len){
	long n = pos + len;
	if (n>str_size){
		str[pos] = '\0';
		str_size = 0;
	}
	else{
		for (int i = 0; i <= len; i++){
			str[pos + i] = str[n + i];
		}
		str_size -= len;
	}
	return *this;
}
MyString& MyString::erase(char* p){
	if (str <= p&&str + str_size > p){
		size_t pos = p - str;
		return erase(pos, 1U);
	}
}
MyString& MyString::erase(char* first, char* last){
	if (str <= first && str + str_size > first){
		size_t pos = first - str;
		size_t len = last - first;
		return erase(pos, len);
	}
}
MyString& MyString::replace(size_t pos, size_t len, const MyString& str){
	return replace(pos, len, str.str);
}
MyString& MyString::replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen){
	char*substr = new char[sublen + 1];
	for (int i = 0; i < sublen; i++){
		substr[i] = str.str[i + subpos];
	}
	substr[sublen] = '\0';
	replace(pos, len, substr);
	delete[]substr;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const char* str){
	erase(pos, len);
	insert(pos, str);
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const char* str, size_t n){
	char*substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = str[i];
	}
	substr[n] = '\0';
	replace(pos, len, substr);
	delete[]substr;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, size_t n, char c){
	char*substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = c;
	}
	substr[n] = '\0';
	replace(pos, len, substr);
	delete[]substr;
	return *this;
}
MyString& MyString::replace(char* i1, char* i2, const MyString& s){
	if (i1 >= str&&i1 < str + str_size){
		size_t pos = i1 - str;
		size_t len = i2 - i1;
		return replace(pos, len, s);
	}
}
MyString& MyString::replace(char* i1, char* i2, const char* s){
	if (i1 >= str&&i1 < str + str_size){
		size_t pos = i1 - str;
		size_t len = i2 - i1;
		return replace(pos, len, s);
	}
}
MyString& MyString::replace(char* i1, char* i2, const char* s, size_t n){
	if (i1 >= str&&i1 < str + str_size){
		size_t pos = i1 - str;
		size_t len = i2 - i1;
		return replace(pos, len, s, n);
	}
}
MyString& MyString::replace(char* i1, char* i2, size_t n, char c){
	if (i1 >= str&&i1 < str + str_size){
		size_t pos = i1 - str;
		size_t len = i2 - i1;
		return replace(pos, len, n, c);
	}
}
void swap(MyString& x,MyString& y){
	MyString sub = x;
	x = y;
	y = sub;
}
void MyString::popback(){
	str_size--;
	str[str_size] = '\0';
}
const char* MyString::c_str()const{
	return str;
}
const char* MyString::data()const{
	return str;
}
size_t MyString::copy(char* s, size_t len, size_t pos) const{
	int n = len;
	if (pos + len < str_size){
		n = str_size - pos;
	}
	for (int i = 0; i < n; i++){
		s[i] = str[pos + i];
	}
	s[n] = '\0';
	return n;
}
size_t MyString::find(const MyString& scr, size_t pos) const{
	return find(scr.str, pos);
}
size_t MyString::find(const char* s, size_t pos) const{
	for (int i = 0; i < str_size; i++){
		if (str[i] == s[0]){
			int k = 1;
			for (int j = 0; j < strlen(s); j++){
				if (str[pos + i + j] != s[j]){
					k = 0;
					break;
				}
			}
			if (k){
				return pos+i;
			}
		}
	}
	return npos;
}
size_t MyString::find(const char* s, size_t pos, size_t n) const{
	if (n > strlen(s)){
		n = strlen(s);
	}
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = s[i];
	}
	substr[n] = '\0';
	int k = find(substr,pos);
	delete[]substr;
	return k;
}
size_t MyString::find(char c, size_t pos) const{
	for (int i = pos; i < str_size; i++){
		if (str[i] == c){
			return pos + i;
		}
	}
	return npos;
}
size_t MyString::rfind(const MyString& scr, size_t pos) const{
	return rfind(scr.str,pos);
}
size_t MyString::rfind(const char* s, size_t pos) const{
	if (pos == npos){
		pos = str_size;
	}
	for (int i = 0; i < pos; i++){
		if (str[pos - i] == s[strlen(s) - 1]){
			int k = 1;
			for (int j = 0; j <strlen(s); j++){
				if (str[pos - i - j] != s[strlen(s) - j - 1]){
					k = 0;
					break;
				}
			}
			if (k){
				return pos-i;
			}
		}
	}
	return npos;
}
size_t MyString::rfind(const char* s, size_t pos, size_t n) const{
	if (n > strlen(s)){
		n = strlen(s);
	}
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = s[i];
	}
	substr[n] = '\0';
	int k = rfind(substr,pos);
	delete[]substr;
	return k;
}
size_t MyString::rfind(char c, size_t pos) const{
	for (int i = pos; i >= 0; i--){
		if (str[i] == c){
			return i;
		}
	}
	return npos;
}
size_t MyString::find_first_of(const MyString& str, size_t pos) const{
	return find_first_of(str.str, pos);
}
size_t MyString::find_first_of(const char* s, size_t pos) const{
	return find(s,pos);
}
size_t MyString::find_first_of(const char* s, size_t pos, size_t n) const{
	if (n > strlen(s)){
		n = strlen(s);
	}
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = s[i];
	}
	substr[n] = '\0';
	int k = find_first_of(substr, pos);
	delete[]substr;
	return k;
}
size_t MyString::find_first_of(char c, size_t pos) const{
	return find(c,pos);
}
size_t MyString::find_last_of(const MyString& str, size_t pos) const{
	return find_last_of(str.str, pos);
}
size_t MyString::find_last_of(const char* s, size_t pos) const{
	return rfind(s, pos);
}
size_t MyString::find_last_of(const char* s, size_t pos, size_t n) const{
	if (n > strlen(s)){
		n = strlen(s);
	}
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = s[i];
	}
	substr[n] = '\0';
	int k = find_last_of(substr, pos);
	delete[]substr;
	return k;
}
size_t MyString::find_last_of(char c, size_t pos) const{
	return rfind(c, pos);
}
size_t MyString::find_first_not_of(const MyString& str, size_t pos) const{
	return find_first_not_of(str.str, pos);
}
size_t MyString::find_first_not_of(const char* s, size_t pos) const{
	for (int i = 0; i < str_size; i++){
		if (str[i] != s[0]){
			int k = 1;
			for (int j = 0; j < strlen(s); j++){
				if (str[pos + i + j] == s[j]){
					k = 0;
					break;
				}
			}
			if (k){
				return pos + i;
			}
		}
	}
	return npos;
}
size_t MyString::find_first_not_of(const char* s, size_t pos, size_t n) const{
	if (n > strlen(s)){
		n = strlen(s);
	}
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = s[i];
	}
	substr[n] = '\0';
	int k = find_first_not_of(substr, pos);
	delete[]substr;
	return k;
}
size_t MyString::find_first_not_of(char c, size_t pos) const{
	for (int i = pos; i < str_size; i++){
		if (str[i] != c){
			return pos + i;
		}
	}
	return npos;
}
size_t MyString::find_last_not_of(const MyString& str, size_t pos) const{
	return find_last_not_of(str.str, pos);
}
size_t MyString::find_last_not_of(const char* s, size_t pos) const{
	for (int i = 0; i < pos; i++){
		if (str[pos - i] != s[strlen(s) - 1]){
			int k = 1;
			for (int j = 0; j <strlen(s); j++){
				if (str[pos - i - j] == s[strlen(s) - j - 1]){
					k = 0;
					break;
				}
			}
			if (k){
				return pos + i;
			}
		}
	}
	return npos;
}
size_t MyString::find_last_not_of(const char* s, size_t pos, size_t n) const{
	if (n > strlen(s)){
		n = strlen(s);
	}
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = s[i];
	}
	substr[n] = '\0';
	int k = find_last_not_of(substr, pos);
	delete[]substr;
	return k;
}
size_t MyString::find_last_not_of(char c, size_t pos) const{
	for (int i = pos; i >= 0; i--){
		if (str[i] != c){
			return i;
		}
	}
	return npos;
}
MyString MyString::substr(size_t pos, size_t len) const{
	MyString s(*this, pos, len);
	return s;
}
int MyString::compare(const MyString& str) const{
	return compare(0,str.str_size,str.str);
}
int MyString::compare(size_t pos, size_t len, const MyString& str) const{
	return compare(pos, len, str.str);
}
int MyString::compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen) const{
	if (subpos + sublen>str.str_size){
		sublen = str.str_size - subpos;
	}
	char* s = new char[sublen];
	for (int i = 0; i < sublen; i++){
		s[i] = str.str[subpos + i];
	}
	int t = compare(pos, len, s);
	delete[]s;
	return t;
}
int MyString::compare(const char* s) const{
	return compare(0, strlen(s), s);
}
int MyString::compare(size_t pos, size_t len, const char* s) const{
	if (pos + len > str_size){
		len = str_size - pos;
	}
	char* substr = new char[len+1];
	for (int i = 0; i<len; i++){
		substr[i] = str[i];
	}
	substr[len] = '\0';
	int k = strcmp(substr, s);
	delete[]substr;
	return k;
}
int MyString::compare(size_t pos, size_t len, const char* s, size_t n) const{
	if (n > strlen(s)){
		n = strlen(s);
	}
	char* substr = new char[n + 1];
	for (int i = 0; i < n; i++){
		substr[i] = s[i];
	}
	substr[n] = '\0';
	int k = compare(pos, len, substr);
	delete[]substr;
	return k;
}
bool MyString::operator== (const MyString& rhs){
	return *this == rhs.str;
}
bool MyString::operator== (const char* rhs){
	if (str == NULL || !rhs){
		return false;
	}
	return strcmp(str, rhs) == 0;
}
bool MyString::operator!= (const MyString& rhs){
	return *this != rhs.str;
}
bool MyString::operator!= (const char* rhs){
	if (str == NULL||!rhs){
		return true;
	}
	return strcmp(str, rhs) != 0;
}
bool MyString::operator< (const MyString& rhs){
	return *this < rhs.str;
}
bool MyString::operator< (const char* rhs){
	return strcmp(str, rhs) < 0;
}
bool MyString::operator<= (const MyString& rhs){
	return *this <= rhs.str;
}
bool MyString::operator<= (const char* rhs){
	return strcmp(str, rhs) <= 0;
}
bool MyString::operator> (const MyString& rhs){
	return *this > rhs.str;
}
bool MyString::operator> (const char* rhs){
	return strcmp(str, rhs) > 0;
}
bool MyString::operator>= (const MyString& rhs){
	return *this >= rhs.str;
}
bool MyString::operator>= (const char* rhs){
	return strcmp(str, rhs) >= 0;
}
bool operator== (const MyString& lhs, const MyString& rhs){
	return lhs == rhs;
}
bool operator== (const char*   lhs, const MyString& rhs){
	MyString s(lhs);
	return lhs == rhs;
}
bool operator== (const MyString& lhs, const char*   rhs){
	return lhs == rhs;
}
bool operator!= (const MyString& lhs, const MyString& rhs){
	return lhs != rhs;
}
bool operator!= (const char*   lhs, const MyString& rhs){
	MyString s(lhs);
	return lhs != rhs;
}
bool operator!= (const MyString& lhs, const char*   rhs){
	return lhs != rhs;
}
bool operator<  (const MyString& lhs, const MyString& rhs){
	return lhs < rhs;
}
bool operator<  (const char*   lhs, const MyString& rhs){
	MyString s(lhs);
	return lhs < rhs;
}
bool operator<  (const MyString& lhs, const char*   rhs){
	return lhs < rhs;
}
bool operator<= (const MyString& lhs, const MyString& rhs){
	return lhs <= rhs;
}
bool operator<= (const char*   lhs, const MyString& rhs){
	MyString s(lhs);
	return lhs <= rhs;
}
bool operator<= (const MyString& lhs, const char*   rhs){
	return lhs <= rhs;
}
bool operator>  (const MyString& lhs, const MyString& rhs){
	return lhs > rhs;
}
bool operator>  (const char*   lhs, const MyString& rhs){
	MyString s(lhs);
	return lhs > rhs;
}
bool operator>  (const MyString& lhs, const char*   rhs){
	return lhs > rhs;
}
bool operator>= (const MyString& lhs, const MyString& rhs){
	return lhs >= rhs;
}
bool operator>= (const char*   lhs, const MyString& rhs){
	MyString s(lhs);
	return lhs >= rhs;
}
bool operator>= (const MyString& lhs, const char*   rhs){
	return lhs >= rhs;
}
istream& operator>> (istream& in, MyString& str){
	char ch = in.peek();
	while (!in.eof() && (ch == ' ' || ch == '\n')){
		in.get();
		ch = in.peek();
	}
	if (str.str != NULL){
		delete[]str.str;
		str.str = NULL;
	}
	char readStr[127];
	size_t count = 0;
	while (!in.eof() && (ch != ' ' && ch != '\n') && count < 126){
		in.get();
		readStr[count++] = ch;
		ch = in.peek();
	}
	str = new char[count + 1];
	memcpy(str.str, readStr, sizeof(char)*count);
	str[count] = '\0';
	str.str_size = count;
	return in;
}
ostream& operator<< (ostream& out, const MyString& str){
	for (int i = 0; i <= str.str_size; i++){
		out << str.str[i];
	}
	cout.flush();
	return out;
}
istream& getline(istream& in, MyString& str, char delim){
	char ch = in.peek();
	while (!in.eof() && (ch == ' ' || ch == '\n')){
		in.get();
		ch = in.peek();
	}
	if (str.str != NULL){
		delete[]str.str;
		str.str = NULL;
	}
	char readStr[127];
	size_t count = 0;
	while (!in.eof() && (ch != delim ) && count < 126){
		in.get();
		readStr[count++] = ch;
		ch = in.peek();
	}
	str = new char[count + 1];
	memcpy(str.str, readStr, sizeof(char)*count);
	str[count] = '\0';
	str.str_size = count;
	return in;
}
istream& getline(istream& in, MyString& str){
	return getline(in, str, '\n');
}
