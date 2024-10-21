#include <stdio.h>
#include <stdlib.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;


int input_date(Date *d)
{
    printf("enter year, month, day (YYYY MM DD): ");
    int n = scanf("%d %d %d", &d->year, &d->month, &d->day);
    return n == 3; 
}

void output_date(Date d)
{
    printf("%02d/%02d/%04d\n", d.day, d.month, d.year);
}

typedef struct Cell
{
    char horizontal; 
    char vertical;   
} Cell;


int can_queen_move(Cell cell1, Cell cell2)
{
    
    return (cell1.horizontal == cell2.horizontal ||    
            cell1.vertical == cell2.vertical ||         
            abs(cell1.horizontal - cell2.horizontal) == 
                abs(cell1.vertical - cell2.vertical));
}


void output_cell(Cell c)
{
    printf("cell: %c%d\n", c.horizontal, c.vertical);
}

typedef struct Vertex
{
    long double x;
    long double y;
} Vertex;


void output_vertex(Vertex v)
{
    printf("(%Lg, %Lg)", v.x, v.y);
}


Vertex input_vertex()
{
    Vertex res;
    printf("enter x and y: ");
    scanf("%Lf %Lf", &res.x, &res.y);
    return res;
}


typedef struct Rectangle
{
    Vertex v1;
    Vertex v2;
} Rectangle;


void outputRectangle(const Rectangle *r)
{
    output_vertex(r->v1);
    printf(" and ");
    output_vertex(r->v2);
    printf("\n");
}


int inputRectangle(Rectangle *r)
{
    r->v1 = input_vertex();
    r->v2 = input_vertex();
    return 0;
}


typedef struct Poly
{
    unsigned n;
    double *a; 
} Poly;


void outputPoly(Poly p)
{
    for (unsigned i = 0; i < p.n; i++)
    {
        printf("%lf*x^%u", p.a[i], i);
        if (i < p.n - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}


int inputPoly(Poly *p)
{
    printf("enter degree n: ");
    scanf("%u", &p->n);
    p->a = (double *)calloc(p->n + 1, sizeof(*p->a));
    for (unsigned i = 0; i < p->n; i++)
    {
        printf("enter coefficient a[%u]: ", i);
        scanf("%lf", &p->a[i]);
    }
    return 0;
}


void deletePoly(Poly *p)
{
    if (p->a)
    {
        free(p->a);
    }
}


typedef struct
{
    int numerator;            
    unsigned int denominator; 
} Rational;


Rational input_rational()
{
    Rational r;
    printf("enter numerator and denominator: ");
    scanf("%d %u", &r.numerator, &r.denominator);
    return r;
}


void output_rational(Rational r)
{
    printf("%d/%u\n", r.numerator, r.denominator);
}


Rational add_rational(Rational r1, Rational r2)
{
    Rational result;
    result.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;
    return result;
}


Rational subtract_rational(Rational r1, Rational r2)
{
    Rational result;
    result.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;
    return result;
}


Rational multiply_rational(Rational r1, Rational r2)
{
    Rational result;
    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    return result;
}

Rational divide_rational(Rational r1, Rational r2)
{
    Rational result;
    result.numerator = r1.numerator * r2.denominator;
    result.denominator = r1.denominator * r2.numerator;
    return result;
}

Rational simplify_rational(Rational r)
{
    int gcd = 1;
    for (int i = 1; i <= r.numerator && i <= r.denominator; i++)
    {
        if (r.numerator % i == 0 && r.denominator % i == 0)
        {
            gcd = i;
        }
    }
    r.numerator /= gcd;
    r.denominator /= gcd;
    return r;
}


int main()
{

    Date date;
    if (input_date(&date))
    {
        output_date(date);
    }

    Rectangle rect;
    inputRectangle(&rect);
    outputRectangle(&rect);

    Poly p;
    inputPoly(&p);
    outputPoly(p);
    deletePoly(&p);
    Rational r1 = input_rational();
    Rational r2 = input_rational();
    Rational sum = add_rational(r1, r2);
    Rational difference = subtract_rational(r1, r2);
    Rational product = multiply_rational(r1, r2);
    Rational quotient = divide_rational(r1, r2);

    sum = simplify_rational(sum);
    difference = simplify_rational(difference);
    product = simplify_rational(product);
    quotient = simplify_rational(quotient);
    printf("sum: ");
    output_rational(sum);
    printf("difference: ");
    output_rational(difference);
    printf("product: ");
    output_rational(product);
    printf("quotient: ");
    output_rational(quotient);
    Cell cell1, cell2;

    // Input first cell
    printf("enter first cell (e.g., a1): ");
    scanf(" %c%d", &cell1.horizontal, &cell1.vertical);

    // Input second cell
    printf("enter second cell (e.g., a1): ");
    scanf(" %c%d", &cell2.horizontal, &cell2.vertical);

    // Output the cells
    output_cell(cell1);
    output_cell(cell2);

    // Check if the queen can move
    if (can_queen_move(cell1, cell2))
    {
        printf("the queen can move from ");
        output_cell(cell1);
        printf("to ");
        output_cell(cell2);
        printf("in one move.\n");
    }
    else
    {
        printf("the queen cannot move from ");
        output_cell(cell1);
        printf("to ");
        output_cell(cell2);
        printf("in one move\n");
    }

    return 0;
}
