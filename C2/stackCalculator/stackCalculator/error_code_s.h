#pragma once
class error_code_s
{
public:
	void show();
	void write(int error_code);
	error_code_s();
	~error_code_s();

private:
	int error;
};

void error_code_s::write(int error_code)
{
	error_code_s::error = error_code;
}

void error_code_s::show()
{
	cout << error_code_s::error;
	return;
}

error_code_s::error_code_s()
{
}

error_code_s::~error_code_s()
{
}