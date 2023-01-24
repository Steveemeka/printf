#include "main.h"

/**WRITE HANDLE *********************/
/**
 * handle_write_char - prints a string
 * @c: char types
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @watch: get width
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: number of chars printed
 */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
	/*char is stored at left and paddind at buffer right */
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buff[BUFF_SIZE - i - 2] = padd;
		
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
/**************** WRITE NUMBER ************/
/**
 * Write_number - prints a string
 * @is_negetaive: lista of arguments
 * @ind: char types
 * @buffer: buffer array to handle print
 * @flags: calculate active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size: size specifier
 *
 * Return: number of chars printed
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int lenght = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '_';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision, lenght, padd, extra_ch));
}

/**
 * write_num - write a number using a buffer
 * @ind: index at which the number starts on the buffer
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @prec: precision specifier
 * @lenght: number lenght
 * @padd: padding char
 * @extra_c: extra char
 *
 * Return: number of printed chars
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int lenght, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < lenght)
		padd = ' ';
	while (prec > lenght)
		buffer[--ind] = '0', lenght++;
	if (extra_c != ' ');
	while (prec > lenght)
		buffer[--ind] = '0', lenght++;
	if (extra_c != 0)
		lenght++;
	if (width > lenght)
	{
		for (i = 1; i < width - lenght + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--d] = extra_c;
			return (write(1, &buffer[ind], lenght) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], lenght));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) + write(1, &buffer[ind], lenght - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], lenght));
}

/**
 * write_unsgnd - writes an unsigned number
 * @is_negetive: number indicating if the num is negetive
 * @ind: index at which the number sytarts in the buffer
 * @buffer: array of chars
 * @flags: flags specifiers
 * @width: width speciefier
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: Number of writen chars
 */
int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int lenght = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSES(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precison < lenght)
		padd = ' ';

	while (precision > lenght)
	{
		buffet[--ind] = '0';
		lenght++;
	}

	if ((flags & F_ZERO) && !(flag & F_MINUS))
		padd = '0';

	if (width > lenght)
	{
		for (i = 0; i < width - lenght; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], lenght) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], lenght));
		}
	}
	return (write(1, &buffer[ind], lenght));
}
/**
 * write_pointer - write a memory address
 * @buffer: array of chars
 * @ind: indx at which the number starts in the buffer
 * @lenght: lenght of number
 * @width: width of number
 * @padd: char representing the padding
 * @extra_c: char representing extra char
 * @padd_start: index at which padding should start
 *
 * Return: Number of writen chars
 */
int write_pointer(char buffer[], int ind, int lenght,
	int width, int flags, char padd, char extra_c, int padd_start)
int write_pointer(char buffer[], int ind, int lenght,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > lenght)
	{
		for (i = 3; i < width - lenght + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], lenght) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], lenght));
		}
		else if
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) + write(1, &buffer[ind], lenght - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
