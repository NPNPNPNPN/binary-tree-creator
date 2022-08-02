#include <cmath>
#include <iostream>

using namespace std;

class NodeTree
{
public:
  int iData;
  NodeTree *Left, *Right;
  NodeTree() { Left = Right = NULL; }
  NodeTree(int iValue) { iData = iValue; Left = Right = NULL;}
};

class ABB
{
private:
  NodeTree *root;
public:
  //Constructor
  ABB() { root = NULL; }
  //Destructor
  ~ABB() { };
  //miscellaneous

  bool Search ( int iValue )
  {
    NodeTree *pP = root;
    while ( pP != NULL )
    {
      if (pP -> iData == iValue )
        return true;
      else
        pP = ( pP -> iData > iValue? pP -> Left: pP -> Right );
    }
    return false;
  }

  NodeTree* FindFather ( int iValue )
  {
    NodeTree *pFather, *pSon;
    pSon = root;
    pFather = NULL;
    while ( pSon != NULL and pSon -> iData != iValue )
    {
      pFather = pSon;
      pSon = ( pSon -> iData > iValue? pSon -> Left: pSon -> Right );
    }
    return pFather;
  }

  void InsertABB ( int iValue )
  {
    NodeTree *pFather = FindFather ( iValue );
    NodeTree *pNew = new NodeTree ( iValue );
    if ( pFather == NULL )
      root = pNew;
    else
      {
        if ( pFather -> iData > iValue )
          pFather -> Left = pNew;
        else
          pFather -> Right = pNew;
      }
  }

  NodeTree* Predecesor ( NodeTree *pActual )
  {
    NodeTree *pP = pActual -> Left;
    while ( pP -> Right != NULL )
      pP = pP -> Left;
    return pP;
  }

  NodeTree* Sucesor ( NodeTree *pActual )
  {
    NodeTree *pP = pActual -> Right;
    while ( pP -> Left != NULL )
      pP = pP -> Left;
    return pP;
  }

  void DeleteABB ( int iValue )
  {
    NodeTree *pFather = FindFather ( iValue );
    NodeTree *pDN;
    if ( pFather == NULL )
      pDN = root;
    else
      pDN = ( pFather -> iData > iValue? pFather -> Left : pFather -> Right );

    if ( pDN -> Left != NULL and pDN -> Right != NULL )
    {
      NodeTree *pS = Predecesor ( pDN );
      int iNewValue = pS -> iData;
      DeleteABB ( pS -> iData );
      pDN -> iData = iNewValue;
    }
    else if ( pFather == NULL )
    {
      if ( pDN -> Right == NULL )
        root = pDN -> Left;
      else
        root = pDN -> Right;
    }
    else if ( pFather -> iData > iValue )
    {
      if ( pDN -> Left == NULL )
        pFather -> Left = pDN -> Right;
      else
        pFather -> Left = pDN -> Left;
    }
    else if ( pDN -> Right == NULL )
      pFather -> Right = pDN -> Left;
    else
      pFather -> Right = pDN -> Right;

    delete pDN;
  }

  void P_Print (NodeTree *pP, int iS)
  {
    if (pP != NULL)
    {
      iS += 8;
      P_Print (pP -> Right, iS);
      cout << endl;
      for (int iC = 10; iC < iS; iC++)
        cout << " ";
      cout << pP -> iData << endl;
      P_Print (pP -> Left, iS);
    }
    else
      return;
  }

  void Print()
  {
    NodeTree *pP = root;
    P_Print (pP, 0);
  }

  void Ancestors (int iValue)
  {
    NodeTree *pActual;
    NodeTree *pFather;
    if ( Search(iValue) )
      pFather = FindFather (iValue);
    else
      return;
    
    while (pFather != NULL)
    {
      pActual = pFather;
      cout << pFather -> iData << " ";
      pFather = FindFather(pFather -> iData);
    }
  }

  int P_SingleParents (NodeTree *pP, int &iCount)
  {
    if (pP == NULL)
      return 0;

    P_SingleParents (pP -> Right, iCount);
    P_SingleParents (pP -> Left, iCount);

    if ( (pP -> Right == NULL and pP -> Left != NULL) or (pP -> Right != NULL and pP -> Left == NULL) )
      iCount++;
  
    return iCount;
  }

  int SingleParents ()
  {
    int iCount = 0;
    NodeTree *pP = root;
    return P_SingleParents (pP, iCount);  
  }


};