
#include <stdio.h>
#include "AdptArray.h"


typedef struct AdptArray_* PAdptArray;
typedef enum  {FAIL = 0, SUCCESS=1} Result;
typedef void* PElement;

typedef void(*DEL_FUNC)(PElement);
typedef PElement(*COPY_FUNC)(PElement);
typedef void(*PRINT_FUNC)(PElement);


typedef stuct AdptArray_ {
	int ArrSize;
	PElement *pElement;
	DEL_FUNC delFunc;
	COPY_FUNC copyFunc;
	PRINT_FUNC printFunc;
} AdptArray, *PAdptArray

PAdptArray CreateAdptArray(COPY_FUNC copyF, DEL_FUNC delF,PRINT_FUNC printF){
    PAdptArray pArr = (PAdptArray)malloc(sizeof(AdptArray));
	if (!pArr){
        return NULL;
    }
	pArr ->ArrSize = 0;
	pArr ->pElement = NULL;
	pArr ->delFunc = delF;
	pArr ->copyFunc = copyF;
	pArr ->printFunc = printF;
	return pArr;
}

void DeleteAdptArray(PAdptArray pArr){
	if (!pArr){
        return;
    }
	for(int i = 0; i < pArr->ArrSize; i++){
		pArr->delFunc((pArr->pElement)[i]);
	}
	free(pArr->pElement);
	free(pArr);

}

Result SetAdptArrayAt(PAdptArray pArr, int index, PElement pElem){
	if (!pArr){
		return FAIL;
	}

	PElement *elementCopy;
	// if the given index if larger than the array's size we'll have to extend it (possible as dynamic)
	if (index >= pArr -> ArrSize){
		//Note that we're using calloc so values are not initialized to random values as malloc would do.
		elementCopy = (PElement*)calloc((index+1),sizeof(Element));
		if (!elementCopy){
			return FAIL;
		}
		//Copies the element and saves it so it can be added back later
		memcpy(elementCopy, pArr -> pElement , (pArr -> ArrSize) * sizeof(PElement));
		//frees the old element
		free (pArr ->pElement);
		pArr -> pElement = elementCopy;
	}

	pArr-> delFunc((pArr -> pElement)[index]);
	(pArr -> pElement)[index] = pArr -> copyFunc(elementCopy);

	//Update the size of the final array if needed
	if (pArr -> ArrSize <= index){
		pArr -> ArrSize = index+1;
	}
	return SUCCESS;
}

PElement GetAdptArrayAt(PAdptArray, int){
	
}

int GetAdptArraySize(PAdptArray pArr){
    if (!pArr) return -1;
    return pArr -> ArrSize;
}

//prints the array by going over the array and if there's a value in the cell (not NULL) print that value using the print function
void PrintDB(PAdptArray pArr){
    if (!pArr){
		return;
	}
	for (int i = 0 ; i < pArr-> ArrSize ; i++){
		if (pArr -> pElement[i] != NULL){
			pArr -> printFunc(pArr ->pElement[i]);
		}
	}
}
