#include "Evaluador.h"

string getPrimerElemento(queue<string> mi_cola);

bool estaEncendido(char byte, int pos)
{
char mascara = 1;
mascara = mascara << pos;
return byte&mascara;
}

bool compareSets(set<string>s1, set<string>s2)
{
    if(s1.size()!=s2.size())
        return false;
    set<string>::iterator j =s2.begin();
    for(set<string>::iterator i=s1.begin();i!=s1.end();i++)
    {
        if(*i!=*j)
            return false;
        j++;
    }
    return true;
}

bool compareSets(stack<char>s1, stack<char>s2)
{
    if(s1.size()!=s2.size())
        return false;
    while(!s1.empty())
    {
        if(s1.top()!=s2.top())
            return false;
        s1.pop();
        s2.pop();
    }
    return true;
}

void evaluar()
{
    int nota = 0;

    escribir("archivo_evaluador1",new Gato(5,'f',"ruru","persa"),1);
    escribir("archivo_evaluador1",new Gato(7,'m',"roro","siames"),0);
    escribir("archivo_evaluador1",new Gato(3,'f',"rara","bengala"),2);


    cout<<"Ejercicio escribir() y leer():\t\t";
    bool correcto = true;

    if(  (leer("archivo_evaluador1",0)->edad == 7
       && leer("archivo_evaluador1",1)->edad == 5
       && leer("archivo_evaluador1",2)->edad == 3
       && leer("archivo_evaluador1",0)->sexo == 'm'
       && leer("archivo_evaluador1",1)->sexo == 'f'
       && leer("archivo_evaluador1",2)->sexo == 'f'
       && leer("archivo_evaluador1",0)->nombre == "roro"
       && leer("archivo_evaluador1",1)->nombre == "ruru"
       && leer("archivo_evaluador1",2)->nombre == "rara"
       && leer("archivo_evaluador1",0)->raza == "siames"
       && leer("archivo_evaluador1",1)->raza == "persa"
       && leer("archivo_evaluador1",2)->raza == "bengala"
       )==false)
    {
        correcto=false;
    }

    escribir("archivo_evaluador2",new Gato(0,'m',"lolo","ragdoll"),0);
    escribir("archivo_evaluador2",new Gato(153,'f',"lola","sphinx"),1);

    if(  (leer("archivo_evaluador2",0)->edad == 0
       && leer("archivo_evaluador2",1)->edad == 153
       && leer("archivo_evaluador2",0)->sexo == 'm'
       && leer("archivo_evaluador2",1)->sexo == 'f'
       && leer("archivo_evaluador2",0)->nombre == "lolo"
       && leer("archivo_evaluador2",1)->nombre == "lola"
       && leer("archivo_evaluador2",0)->raza == "ragdoll"
       && leer("archivo_evaluador2",1)->raza == "sphinx"
       )==false)
    {
        correcto=false;
    }

    if(correcto)
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio getPromedioDeEdad():\t\t";
    if(getPromedioDeEdad("archivo_evaluador1")==5
       &&getPromedioDeEdad("archivo_evaluador2")==76.5
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    set<int>s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);

    set<int>s2;
    s2.insert(10);
    s2.insert(20);
    s2.insert(30);

    cout<<"Ejercicio getMayor():\t\t\t";
    if(getMayor(s1)==4
       && getMayor(s2)==30
       )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    queue<char>q1;
    q1.push('a');
    q1.push('b');
    q1.push('c');
    q1.push('d');

    queue<char>q2;
    q2.push('q');
    q2.push('w');
    q2.push('e');
    q2.push('r');
    q2.push('t');

    stack<char>sq1;
    sq1.push('a');
    sq1.push('b');
    sq1.push('c');
    sq1.push('d');

    stack<char>sq2;
    sq2.push('q');
    sq2.push('w');
    sq2.push('e');

    cout<<"Ejercicio mezclarAlphabeticamente():\t";

    set<char> rs1 = mezclarAlfabeticamente(q1,sq1);
    set<char> rs2 = mezclarAlfabeticamente(q2,sq2);
    set<char> rs3 = mezclarAlfabeticamente(q1,sq2);

    if(rs1.size()==4
       && rs2.size()==5
       && rs3.size()==7

       && rs1.find('a')!=rs1.end()
       && rs1.find('e')==rs1.end()

       && rs2.find('q')!=rs2.end()
       && rs2.find('a')==rs2.end()
       && rs2.find('w')!=rs2.end()
       && rs2.find('e')!=rs2.end()
       && rs2.find('r')!=rs2.end()
       && rs2.find('t')!=rs2.end()

       && rs3.find('a')!=rs3.end()
       && rs3.find('e')!=rs3.end()
       )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio existe():\t\t\t";

    vector<string>v1;
    v1.push_back("a");
    v1.push_back("b");
    v1.push_back("c");
    vector<string>v2;
    v2.push_back("1");
    v2.push_back("2");
    v2.push_back("3");
    v2.push_back("4");
    vector<string>v3;
    v3.push_back("q");
    v3.push_back("w");

    map<string,vector<string> >m1;
    m1["x"]=v1;
    m1["y"]=v2;

    map<string,vector<string> >m2;
    m2["A"]=v1;
    m2["B"]=v2;
    m2["C"]=v3;

    map<string,vector<string> >m3;
    m3["X"]=v3;

    if(existe(m1,"a")
       && existe(m2,"a")
       && !existe(m3,"a")
       && existe(m1,"a")

       && existe(m1,"x")
       && existe(m1,"y")
       && !existe(m1,"z")
       && existe(m1,"b")
       && existe(m1,"c")
       && !existe(m1,"d")
       && !existe(m1,"0")
       && existe(m1,"1")
       && existe(m1,"2")
       && existe(m1,"3")
       && existe(m1,"4")
       && !existe(m1,"5")
       && !existe(m1,"6")

       && existe(m2,"A")
       && existe(m2,"B")
       && existe(m2,"C")
       && !existe(m2,"D")

       && existe(m3,"X")

       && existe(m3,"q")
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    NodoTrinario* n1 = new NodoTrinario(1);
    NodoTrinario* n2 = new NodoTrinario(2);
    NodoTrinario* n3 = new NodoTrinario(3);
    NodoTrinario* n4 = new NodoTrinario(4);
    NodoTrinario* n5 = new NodoTrinario(5);
    NodoTrinario* n6 = new NodoTrinario(6);
    NodoTrinario* n7 = new NodoTrinario(7);
    NodoTrinario* n8 = new NodoTrinario(8);
    NodoTrinario* n9 = new NodoTrinario(9);
    NodoTrinario* n10 = new NodoTrinario(10);

    n1->izquierdo = n2;
    n1->medio = n3;
    n1->derecho = n4;

    n2->izquierdo = n5;
    n2->medio = n6;
    n2->derecho = n7;

    n3->izquierdo = n8;
    n3->medio = n9;
    n8->medio = n10;

    cout<<"Ejercicio getMayor():\t\t\t";
    if(getMayor(n1)==10
       && getMayor(n2)==7
       && getMayor(n3)==10
       && getMayor(n4)==4
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<"Ejercicio buscarYReemplazar():\t\t";
    buscarYReemplazar(n1,1,13);
    buscarYReemplazar(n1,8,18);
    buscarYReemplazar(n1,4,666);
    if(n1->valor == 13
        && n8->valor == 18
        && n4->valor == 666
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<"Ejercicio retener3Bits():\t\t";
    if(retener3Bits(8)==0
        && retener3Bits(3)==3
        && retener3Bits(9)==1
        && retener3Bits(147)==3
        && retener3Bits(254)==6
       )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/15"<<endl;
}
