#include <tesselator.h>

class Tesselator {
   TESStesselator* tess;
public:
   operator bool() {
      return tess;
   }
   Tesselator( TESSalloc* alloc ) : tess( tessNewTess(alloc) ) {
   }
   ~Tesselator() {
      if (tess)
         tessDeleteTess( tess );
   }
   void addContour(int size, const void* pointer, int stride, int count, int offset ) {
      tessAddContour( tess, size, pointer, stride, count, offset );
   }
   void setOption(int option, int value ) {
      tessSetOption( tess, option, value );
   }
   int tesselate( int windingRule, int elementType, int polySize, int vertexSize, const TESSreal* normal ) {
      return tessTesselate(tess, windingRule, elementType, polySize, vertexSize, normal );
   }
   int getVertexCount() {
      return tessGetVertexCount(tess);
   }
   const TESSreal* getVertices() {
      return tessGetVertices(tess);
   }
   const TESSindex* getVertexIndices() {
      return tessGetVertexIndices(tess);
   }
   int getElementCount() {
      return tessGetElementCount(tess);
   }
   const TESSindex* getElements() {
      return tessGetElements( tess );
   }
};
