#include "Rendering\Mesh.h"

Mesh::Mesh() {

}


//Create using a factory class.
Mesh::Mesh(RawMesh rMesh) {
	//Give the Mesh class its raw data.
	rawMesh = rMesh;
	
}

