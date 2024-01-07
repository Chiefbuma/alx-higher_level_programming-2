#include <Python.h>

/**
 * print_python_list_info - Prints Python lists.
 * @p: A PyObject list.
 */
void print_python_list_info(PyObject *p)
{
	int siz, loc, i;
	PyObject *obj;

	siz = Py_SIZE(p);
	loc = ((PyListObject *)p)->allocated;

	printf("[*] Size of the Python List = %d\n", siz);
	printf("[*] Allocated = %d\n", loc);

	for (i = 0; i < siz; i++)
	{
		printf("Element %d: ", i);

		obj = PyList_GetItem(p, i);
		printf("%s\n", Py_TYPE(obj)->tp_name);
	}
}
