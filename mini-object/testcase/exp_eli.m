main()
{
    int a,b,c,d,e;
    input a;
    input b;

    c = a + b;
    d = a + b;

    e = c * d;
    
    c = c;
    d = e;

    if(a > 0)
    {
        c = a + b;
        e = c + d;
    }
    else 
    {
        d = a + b;
        e = d + 1;
    }

    output c;
    output d;
    output e;
}