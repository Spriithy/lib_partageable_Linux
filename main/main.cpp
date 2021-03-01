
#include <iostream>

extern "C"
{
	void *dlopen(char *, int);
	char *dlerror(void);
	void *dlsym(void *, char *);
	int dlclose(void *);
}

void check(void *handle)
{
	if (!handle)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	void *libComposant1 = dlopen("libComposant1.so", 1);
	void *libComposant2 = dlopen("libComposant2.so", 1);

	int data1 = 3;
	int data2 = 5;

	int valeur1, valeur2;
	int (*composant1)(int, int) = (int (*)(int, int))dlsym(libComposant1, "composant1");
	check((void *)composant1);

	int (*composant2)(int, int) = (int (*)(int, int))dlsym(libComposant2, "composant2");
	check((void *)composant2);

	char *(*getComposant1Version)() = (char *(*)())dlsym(libComposant1, "getComposant1Version");
	check((void *)getComposant1Version);

	valeur1 = composant1(data1, data2);
	valeur2 = composant2(data1, data2);

	std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;

	dlclose(libComposant1);
	dlclose(libComposant2);
}
