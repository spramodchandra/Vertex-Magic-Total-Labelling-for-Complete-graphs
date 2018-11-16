#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
//#include<omp.h>
#include<math.h>
#include<string.h>
//#include<GL/glut.h>
#define stack_size 1000
#define max_no_of_rows 5000
#define array_size 5000

int a[10][10], a1[10];

using namespace std;
struct state {
	int i1, i2, length1, length2;
	int **final_result, **temp_array1;
};
int top = -1;
int no_of_vertices;
struct state stack[stack_size];
void ExitAll(char *msg)
{
	cout << msg << endl;
	cin.get();
	exit(0);
}
/*void Sprint(float x, float y, int nopommy)
{
	int l, i;
	char st[] = "gh\0";
	st[0] = (nopommy / 10) + '0';
	st[1] = (nopommy % 10) + '0';
	l = strlen(st);
	glRasterPos3f(x, y, -1);
	for (i = 0; i < l; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
	}
}*/
void push(struct state *s)
{
	if (top == stack_size - 1)
	{
		printf("\nincrease the stack size\n");
		ExitAll("push");
	}
	top++;
	stack[top].i1 = s->i1;
	stack[top].i2 = s->i2;
	stack[top].length1 = s->length1;
	stack[top].length2 = s->length2;
	stack[top].final_result = s->final_result;
	stack[top].temp_array1 = s->temp_array1;
}
void pop(struct state *s)
{
	if (top == -1)
	{
		printf("\n Underflow \n");
		ExitAll("pop");
	}
	s->i1 = stack[top].i1;
	s->i2 = stack[top].i2;
	s->length1 = stack[top].length1;
	s->length2 = stack[top].length2;
	s->final_result = stack[top].final_result;
	s->temp_array1 = stack[top].temp_array1;
	top--;
}
void tobinary(int num, int n, int *result)
{
	int i = 0;
	for (i = 0; i < n; i++)
		result[i] = 0;
	i = 0;
	while (num != 0)
	{
		result[i++] = num % 2;
		num = num / 2;
	}
}
void output(int n, int kmain, int *temp_array1[])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < kmain; j++)
		{
			printf("%3d", *(*(temp_array1 + i) + j));
		}
		printf("\n");
	}
}
int subset(int check, int n, int sum, int kmain, int power, int array[], int *result, int *subset_output[], int *temp_array[])
{
	int i, j, l, row = 0, col = 0, row2 = 0, col2 = 0;
	for (i = 0; i < power; i++)
	{
		int sum2 = 0;
		tobinary(i, n, result);
		for (j = 0; j < n; j++)
		{
			sum2 = sum2 + result[j];
		}
		if (sum2 == kmain)
		{
			int sum3 = 0;

			for (l = 0; l < n; l++)
			{
				if (result[l] == 1)
				{
					sum3 += array[l];
				}

			}

			if (sum3 == sum)
			{
				for (l = 0; l < n; l++)
				{
					if (result[l] == 1)
					{
						if (check == 0)
						{
							(*(*(subset_output + row) + col)) = array[l];
							col++;
							if (col == kmain)
							{
								row++;
								col = 0;
							}

						}
						else
						{
							(*(*(temp_array + row2) + col2)) = array[l];
							printf("%3d", *(*(temp_array + row2) + col2));
							col2++;
							if (col2 == kmain)
							{
								row2++;
								col2 = 0;
							}
						}
					}
				}
				printf("\n");
			}
		}
	}
	if (check == 0)
		return row;
	else
		return row2;
}
int subset1(int check, int n, int sum, int kmain, int power, int array[], int *result, int *subset_output[], int *temp_array[])
{
	int i, j, l, row = 0, col = 0, row2 = 0, col2 = 0;

	for (i = 0; i < power; i++)
	{
		int sum2 = 0;
		tobinary(i, n, result);
		for (j = 0; j < n; j++)
		{
			sum2 = sum2 + result[j];
		}
		if (sum2 == kmain)
		{
			int sum3 = 0;

			for (l = 0; l < n; l++)
			{
				if (result[l] == 1)
				{
					sum3 += array[l];
				}

			}

			if (sum3 == sum)
			{
				for (l = 0; l < n; l++)
				{
					if (result[l] == 1)
					{
						if (check == 0)
						{
							(*(*(subset_output + row) + col)) = array[l];
							col++;
							if (col == kmain)
							{
								row++;
								col = 0;
							}

						}
						else
						{
							(*(*(temp_array + row2) + col2)) = array[l];
							printf("%3d", *(*(temp_array + row2) + col2));
							col2++;
							if (col2 == kmain)
							{
								row2++;
								col2 = 0;
							}
						}
					}
				}
				printf("\n");
			}
		}
	}
	if (check == 0)
		return row;
	else
		return row2;
}

int search1(int element, int kmain, int counterIndex, int *subset_output[])
{
	int l;
	for (l = 0; l < kmain; l++)
	{
		if (element == *(*(subset_output + counterIndex) + l))
		{
			return 0;
		}
	}
	return 1;
}
int compare(int kmain, int *a1, int *a2)
{
	int index, count = 0, i1, i2;
	for (i1 = 0; i1 < kmain; i1++)
	{
		for (i2 = 0; i2 < kmain; i2++)
		{
			if (a1[i1] == a2[i2])
			{
				count++;
				index = i2;
			}
		}
	}
	if (count == 0)
		return -1;
	else if (count == 1)
		return index;
	else
		return (-count);
}
int intersection(int i, long j, int k, int *final_result[])
{
	int iter1, iter2, element;
	int *array1 = new int[k - 1];
	for (iter1 = 0; iter1 < k - 1; iter1++)
		array1[iter1] = final_result[i][iter1];
	int *array2 = new int[k - 1];
	for (iter1 = 0; iter1 < k - 1; iter1++)
		array2[iter1] = final_result[j][iter1];
	for (iter1 = 0; iter1 < k - 1; iter1++)
	{
		for (iter2 = 0; iter2 < k - 1; iter2++)
		{
			if (array1[iter1] == array2[iter2])
			{
				element = array1[iter1];
				return element;
			}
		}
	}
	return 0;
}
void check(int j, int k, int magic)
{
	if (j == k)
	{
		printf("%3d", magic);
	}
}
/*void draw_circle(float x, float y, float r) {
	float theta;
	glColor3f(0, 1, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2d(x, y);
	for (theta = 0.0; theta <= 2 * 3.6; theta += 0.2)
		glVertex2d(x + r*cos(theta), y + r*sin(theta));
	glEnd();
	glFlush();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	float p[10][2];
	int n = no_of_vertices;
	float theta1 = 0.0, dtheta = 2 * 3.14 / n;
	for (int i = 0; i < n; i++){
		draw_circle(250 * cos(theta1), 250 * sin(theta1), 20);
		p[i][0] = 250 * cos(theta1);
		p[i][1] = 250 * sin(theta1);
		//cout << 250 * cos(theta1) << " " << 250 * sin(theta1) << endl;
		theta1 += dtheta;
	}
	glLineWidth(2.0);
	glColor3f(0, 0, 0);
	for (int i = 0; i < n; i++){
		Sprint(p[i][0], p[i][1], a1[i]);
		for (int j = 0; j < n; j++){
			if (i != j && a[i][j] != 0)
				Sprint((p[i][0] + p[j][0]) / 2-20, (p[i][1] + p[j][1]) / 2-20, a[i][j]);
			glBegin(GL_LINES);
			glVertex2fv(p[i]);
			glVertex2fv(p[j]);
			glEnd();
		}
	}

	glFlush();
}

void myinit(){
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-299, 300, -299, 300);
	glMatrixMode(GL_MODELVIEW);
}*/
int main(int argc, char **argv)
{
	int array[array_size], i, j, l = 0, sum, counterIndex, magic;
	double tpommy;
	long long int power;
	struct state current_state;
	printf("\nEnter the no.of vertices greater than 2\n");
	cin >> no_of_vertices;
	int no_of_edges = (no_of_vertices*(no_of_vertices - 1)) / 2;
	printf("\n No of edges:%d\n", no_of_edges);
	for (i = 1; i <= no_of_vertices + no_of_edges; i++)
	{
		array[i - 1] = i;
	}
	int min_magic_constant = (int)ceil(((double)no_of_vertices*((double)no_of_vertices*(double)no_of_vertices + 3)) / 4);
	int max_magic_constant = (int)floor(((double)no_of_vertices*((double)no_of_vertices + 1)*((double)no_of_vertices + 1)) / 4);
	l = max_magic_constant - min_magic_constant;

	printf("\n Enter the magic constant between %d & %d\n", min_magic_constant, max_magic_constant);
	cin >> magic;
	tpommy = omp_get_wtime();
	if ((magic<min_magic_constant) || (magic>max_magic_constant))
	{
		printf("\n Magic constant should be in the rang from %d to %d", min_magic_constant, max_magic_constant);
		ExitAll("\nExiting\n");
	}
	for (i = 0; i <= l; i++)
	{
		if ((min_magic_constant + i) == magic)
		{
			sum = ((no_of_vertices*no_of_edges) + (no_of_vertices*(no_of_vertices + 1)) / 2) - no_of_vertices*i;
			break;
		}
	}
	if ((no_of_vertices % 4) == 2)
	{
		sum = sum - (no_of_vertices) / 2;
	}
	printf("\nSum:%d\n", sum);
	int n = no_of_vertices + no_of_edges;
	int k = no_of_vertices;
	power = 1 << n;
	printf("\nPower:%ld\n", power);
	int *result = new int[n];
	for (i = 0; i < n; i++)
		result[i] = 0;
	int **subset_output = new int *[1000000];
	for (i = 0; i < 100000; i++)
		subset_output[i] = new int[n];
	for (i = 0; i < 100000; i++)
		for (j = 0; j < n; j++)
			subset_output[i][j] = 0;
	int **temp_array = new int *[max_no_of_rows];
	for (j = 0; j < max_no_of_rows; j++)
		temp_array[j] = new int[k];
	int counter = subset(0, n, sum, k, power, array, result, subset_output, temp_array);
	delete[] result;
	delete[] temp_array;
	int **final_result;
	for (counterIndex = 0; counterIndex < counter; counterIndex++)
	{
	START_LOOP:
		if (counterIndex >= counter)break;
		top = -1;
		printf("\nFirst set of values being taken");
		for (i = 0; i < k; i++)
		{
			printf("%3d", *(*(subset_output + counterIndex) + i));
		}
		int *mag = new int[k];
		for (i = 0; i < k; i++)
		{
			mag[i] = magic - *(*(subset_output + counterIndex) + i);
		}
		int *remaining_set = new int[n - k];
		i = 0;
		for (j = 0; j < n; j++)
		{
			int ret_val = search1(array[j], k, counterIndex, subset_output);
			if (ret_val == 1)
				remaining_set[i++] = array[j];
		}
		printf("\nRemaining Set:");
		for (i = 0; i < n - k; i++)
		{
			printf("%3d", remaining_set[i]);
		}
		int *result1 = new int[n - k];
		for (i = 0; i < n - k; i++)
			result1[i] = 0;
		power = 1 << (n - k);
		printf("\n");
		final_result = new int*[k];
		for (j = 0; j < k; j++)
			final_result[j] = new int[k - 1];
		for (i = 0; i < k; i++)
		{
			for (j = 0; j < k - 1; j++)
				final_result[i][j] = 0;
		}
		for (i = 0; i < k; i++)
		{
			int** temp_array1 = new int *[max_no_of_rows];
			for (j = 0; j < max_no_of_rows; j++)
				temp_array1[j] = new int[k - 1];
			for (int iter = 0; iter < max_no_of_rows; iter++)
			{
				for (j = 0; j < k - 1; j++)
				{
					temp_array1[iter][j] = 0;
				}
			}
			printf("\nFor magic constant %d:\n", mag[i]);
			int length2 = subset1(1, n - k, mag[i], k - 1, power, remaining_set, result1, subset_output, temp_array1);
			printf("\n");

			{
				int length1 = i;
				int index, i1, i2, l, ii, kmain = k - 1;
				i2 = 0;
			label1:
				for (; i2 < length2; i2++)
				{
					int *flag = new int[kmain];
					for (ii = 0; ii < kmain; ii++)
					{
						flag[ii] = 0;
					}
					for (i1 = 0; i1 < length1; i1++)
					{
						index = compare(kmain, &final_result[i1][0], &temp_array1[i2][0]);
						if (index<0)
							break;
						else
						{
							if (flag[index] == 1)
								break;
							flag[index] = 1;

						}
					}
					if (i1 == length1)
					{
						for (l = 0; l<kmain; l++)
						{
							final_result[length1][l] = temp_array1[i2][l];
						}
						length1++;
						break;
					}
					delete[] flag;
				}
				if (i2<length2)
				{
					current_state.i1 = i1;
					current_state.i2 = i2;
					current_state.length1 = length1;
					current_state.length2 = length2;
					current_state.final_result = final_result;
					current_state.temp_array1 = temp_array1;
					push(&current_state);
				}
				else
				{
					int hello = 0;
					hello++;
					if (top == -1)
					{
						counterIndex++;
						goto START_LOOP;
					}
					pop(&current_state);
					i1 = current_state.i1;
					i2 = current_state.i2;
					length1 = current_state.length1;
					length2 = current_state.length2;
					final_result = current_state.final_result;
					temp_array1 = current_state.temp_array1;
					i2++;
					length1--;
					i--;
					goto label1;
				}
			}
			printf("\n");
		}
		tpommy = omp_get_wtime() - tpommy;
		for (i = 0; i<k; i++)
		{
			for (j = 0; j<k - 1; j++);
			{
				printf("%3d ", final_result[i][j]);
			}
			printf("\n");
		}
		if (final_result[k - 1][k - 2] != 0)
		{
			printf("%d ", counterIndex);
			break;
		}

		delete[] result1;
		delete[] remaining_set;
		delete[] mag;
	}
	printf("\n Final Table:\n");
	for (i = 0; i<k + 1; i++)
	{
		for (j = 0; j<k + 1; j++)
		{
			if (i == 0)
			{
				if (j == 0)
					printf("  -");
				else{
					printf("%3d", *(*(subset_output + counterIndex) + (j - 1)));
					a1[j-1] = *(*(subset_output + counterIndex) + (j - 1));
				}
			}
			else
			{
				if (j == 0)
				{
					printf("%3d", *(*(subset_output + counterIndex) + (i - 1)));
					check(j, k, magic);
				}
				else
				{
					if (i == j)
					{
						printf("  -");
						check(j, k, magic);
					}
					else
					{
						int element = intersection(i - 1, j - 1, k, final_result);
						printf("%3d", element);
						a[i-1][j-1] = element;
						check(j, k, magic);
					}
				}
			}
		}
		printf("\n");
	}
	printf("\n   ");
	for (i = 0; i<k; i++)
	{
		printf("%3d", magic);
	}
	cout << endl << endl << "Total Time taken = " << tpommy << endl;
	/*glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(700, 100);
	glutCreateWindow("All Vertex Magic Labelling");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();*/
	return 0;
}