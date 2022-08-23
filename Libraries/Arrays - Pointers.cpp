#include <iostream>

/*	*******************************
	МАССИВЫ И УКАЗАТЕЛИ
***********************************/

void sum(int *v1, int *v2, int * res) 
{
//	int res[3] = {0};
	for (int iter = 0; iter < 3; iter++)
		res[iter] = v1[iter] + v2[iter];
//	return &res[0];
//	return res;
}

void print(int* arr) 
{
	for (int iter = 0; iter < 3; iter++)
		std::cout << arr[iter] << "\t";
	std::cout << std::endl;
}

int main()
{
	// переменная, хранящая адрес другой переменной в памяти, называется указателем (pointer)

	int a;
	a = 321;
	double dbl = 10.005;


	// синтаксис объявления указателей
	int*ptr_int = &a; // оператор амперсенд & - оператор получения адреса
	double * ptr_dbl = &dbl;

	// все указатели всегда одной и той же разрядности (размера)
	// каким бы ни был огромным тип данных (строка, объект, массив)
	// указатель на него всегда будет занимать 4/8 байт, что и является основным
	// преимуществом указателей	std::cout << "int pointer size = " << sizeof(ptr_int) << std::endl;
	std::cout << "double pointer size = " << sizeof(ptr_dbl) << std::endl;
	std::cout << "char pointer size = " << sizeof(char*) << std::endl;
	std::cout << "long long pointer size = " << sizeof(long long *) << std::endl;
	std::cout << "bool pointer size = " << sizeof(bool *) << std::endl;

	// содержимое указателей
	std::cout << std::endl << "ptr_int = 0x" << std::hex << ptr_int << std::endl;
	// std::hex включает отображение целых чисел по 16-ричной системе
	// пока не будет включена другая система счисления подобным образом все числа
	// будут печататься в x16 системе
	std::cout << "ptr_ch = 0x" << ptr_dbl << std::endl;

	// в конечном итоге компилятор, преобразуя текст программы,
	// заменяет имена переменных на из смещения (адреса)
	// т.к. процессор обращается к данным именно по адресу

	// оператор разыменования указателей: чтобы получить значение, хранящееся по данному указателю,
	// нужно ещё раз применить оператор *
	std::cout << std::endl << "*ptr_int = " << std::dec << *ptr_int << std::endl;
	std::cout << "* ptr_dbl = " << *ptr_dbl << std::endl;

	int num = 12345;
	int * ptr_num1, *ptr_num2;
	ptr_num1 = &num;
	ptr_num2 = &num;
	std::cout << std::endl << "ptr_num1 = " << std::dec << ptr_num1 << std::endl;
	std::cout << "ptr_num2 = " << ptr_num2 << std::endl;
	std::cout << "num = " << std::dec << num << std::endl << std::endl;
	/*
	ptr_num1++;
	std::cout << std::endl << "ptr_num1 = " << std::dec << ptr_num1 << std::endl;
	std::cout << "ptr_num2 = " << ptr_num2 << std::endl;
	std::cout << "num = " << std::dec << num << std::endl << std::endl;
	std::cout << std::endl << "*ptr_num1 = " << *ptr_num1 << std::endl;
	std::cout << "*ptr_num2 = " << *ptr_num2 << std::endl;
	*/
	/*
	*ptr_num1= num+1;
	std::cout << std::endl << "ptr_num1 = " << std::hex << ptr_num1 << std::endl;
	std::cout << "ptr_num2 = " << ptr_num2 << std::endl;
	std::cout << "num = " << std::dec << num << std::endl << std::endl;
	std::cout << std::endl << "*ptr_num1 = " << *ptr_num1 << std::endl;
	std::cout << "*ptr_num2 = " << *ptr_num2 << std::endl;
	*/
	
	// массив - блок из нескольких однотипных данных
	// задавать массивом удобно:
	// 1) вектора и матрицы
	// 2) множество точек из 3D и 2D геометрии
	// 3) просто какой-либо числовой ряд, таблица и т.д.
	// 4) строка - массив символов
	// 5) видеобуфер (двумерный массив, соответствующий пикселам
	// экрана)


	//int arr[6];//  - объявление массива длины 6 (из 6 элементов)
	//int arr[5] = {0};//
	int arr[5] = { 1, 50, 11, 12, 101 }; // одномерный массив из 5 целых знаковых чисел

	// в ОП массив хранится компактно (без разрывов, элемент за элементом)
	// нумеруются массивы с 0 до (длина - 1)


	std::cout << arr[0] << '\t' <<
		arr[1] << '\t' << //в одинарных кавычках - только 1 символ (char), в двойных - любое множество
		arr[2] << '\t' << // в общем случае можно везде использовать двойные
		arr[3] << '\t' <<
		arr[4] << std::endl;

	std::cout << "arr = " << arr << std::endl;
	std::cout << "*arr = arr[0] = " << *arr << std::endl;
	std::cout << "*(arr+4) = arr[4] = " << *(arr + 4) << std::endl;
	//!!! выход за границы допустимой памяти i +- 10000
	
	for (int *i = &a - 50;
		i < &a + 50;
		i++)
	{
		std::cout <<
			"0x" << // шестнадцатиразрядные числа принято оформлять с 0x, особенно адреса ОП
			i << //печатается содержимое указателя
			'\t' << //escape-символ кодирующий табуляцию
			*i << // печатаем то, что хранится под адресом
			std::endl;
	}
	
	// получается таблица вида "адрес - значение"


	// идентификатор (имя) массива, взятое без индекса, само является указателем


	int arr2D[3][3] = { // инициализируются построчно
						{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9}
	};

	// если бы захотели занулить весь массив,написали бы int arr2D[3][3] = {0}
	// размерности массивов задаются сатически, нельзя задать размер массива с помощью переменной int arr2D[a][3]
	// для этого нужно воспользоваться динамической памятью и совсем другим синтаксисом объявления


	std::cout << std::endl;
		std::cout << arr2D[0][0] << '\t' << arr2D[0][1] << '\t' << arr2D[0][2] << '\t' << std::endl <<
			arr2D[1][0] << '\t' << arr2D[1][1] << '\t' << arr2D[1][2] << '\t' << std::endl <<
			arr2D[2][0] << '\t' << arr2D[2][1] << '\t' << arr2D[2][2] << '\t' << std::endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;
			j < 3;
			std::cout << arr2D[i][j] << '\t', j++)
			// в итераторе цикла можно записывать больше одного оператора через запятую
		{
			// std::cout << arr2D[i][j] << '\t'; - перенесено в итератор цикла, см. выше
		}

		std::cout << std::endl;
	}

	// по сути, квадратные скобки работают как разыменование и смещение
	std::cout << "*(*(arr2D+2)+2) = arr2D[2][2] = " << *(*(arr2D + 2) + 2) << std::endl;

	// arr2D тип **int (указатель на указатель на int)
	// arr2D[1] тип *int - указатель на одну строчку - одномерный массив внутри двухмерного
	// двумерный массив уложен в одномерном пространстве ОП построчно
	// arr2D[1][1] тип int - двойные скобки дважды разыменуют указатель
	// все статические массивы в памяти расположены компактно


	// если не инициализировать переменные (включая массив) - там хранится неопределённое число
	// для инициализации всего массива нулями, прописывается  = {0}
	//

//	getchar();

	int vect1[3] = { 1, 2, 3 };
	int vect2[3] = { 4, 5, 6 };
	int vect_rez[3] = { 0 };
	sum(vect1, vect2, vect_rez);
	print(vect1);
	print(vect2);
	print(vect_rez);
	/*
	динамический массив
	int n = 0;
	std::cin >> n;
	int * din_arr = new int[n];
	func(din_arr, n);
	delete [] din_arr;
	*/
	/*
	vector<char> str;//необходимо подключить vector
	str.size();
	*/
	return 0;
}

