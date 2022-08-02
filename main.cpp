//David Segura Guzman A00824276  02/05/2020

#include <iostream>
#include <cmath>
#include "NodeTree.h"

int main() 
{
  ABB Tree1;
  int iOption, iData;
  NodeTree *pP = new NodeTree;

  do
  {
    cout << "1. Agregar un valor al arbol" << endl;
    cout << "2. Buscar un valor en el arbol" << endl;
    cout << "3. Eliminar un valor en el arbol" << endl;
    cout << "4. Imprimir el arbol" << endl;
    cout << "5. Imprimir todos los ancestros de un valor en el arbol" << endl;
    cout << "6. Imprimir cuantos nodos en el arbol tienen un solo hijo" << endl;
    cout << "7. Suspender programa" << endl;
    cin >> iOption;

    switch(iOption)
    {
      case 1: 
              cout << "Ingresa el valor a agregar" << endl;
              cin >> iData;
              Tree1.InsertABB(iData);
              cout << endl << endl;
              break;             
      case 2: cout << "Ingresa el valor a buscar" << endl;
              cin >> iData;
              if (Tree1.Search(iData))
              {
                cout << "El valor " << iData << " existe dentro del arbol" << endl << endl;
              }
              else
              {
                cout << "El valor " << iData << " no existe dentro del arbol" << endl << endl;
              }
              break;                     
      case 3: cout << "Ingresa el valor a borrar" << endl;
              cin >> iData;
              Tree1.DeleteABB(iData);
              cout << endl << endl;
              break;
      case 4: cout << endl << endl;
              Tree1.Print();
              cout << endl << endl;
              break;
      case 5: cout << endl << "Ingresa el valor al cual se mostraran sus ancestros" << endl;
              cin >> iData;
              Tree1.Ancestors(iData);
              cout << endl << endl;
              break;
      case 6: cout << endl;
              cout << "La cantidad de nodos con un solo hijo son " << Tree1.SingleParents() << endl << endl;
              break;
    }
  }while (iOption != 7);

return 0;
}