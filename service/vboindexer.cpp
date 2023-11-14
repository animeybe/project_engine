#include <map>

#include "vboindexer.h"

//	True, если v1 примерно равен (приближен) v2
inline bool approximately_equal(float v1, float v2){
	return fabs( v1-v2 ) < 0.01f;
}

/* Выполняем поиск по всем экспортированным вершинам
 для нахождения вершин с тем же положением, UVs, нормали*/
inline bool getSimilarVertexIndex( 

	glm::vec3& in_vertex,
	glm::vec2& in_uv,
	glm::vec3& in_normal,
	std::vector<glm::vec3> & out_vertices,
	std::vector<glm::vec2> & out_uvs,
	std::vector<glm::vec3> & out_normals,

	unsigned short & result
){
	
	for ( unsigned int i=0; i<out_vertices.size(); i++ ){
		if (

			approximately_equal( in_vertex.x , out_vertices[i].x ) &&
			approximately_equal( in_vertex.y , out_vertices[i].y ) &&
			approximately_equal( in_vertex.z , out_vertices[i].z ) &&
			approximately_equal( in_uv.x     , out_uvs     [i].x ) &&
			approximately_equal( in_uv.y     , out_uvs     [i].y ) &&
			approximately_equal( in_normal.x , out_normals [i].x ) &&
			approximately_equal( in_normal.y , out_normals [i].y ) &&
			approximately_equal( in_normal.z , out_normals [i].z )

		){
			result = i;
			return true;
		}
	}
	
	return false;
}

inline void indexVBO_slow(

	std::vector<glm::vec3> & in_vertices,
	std::vector<glm::vec2> & in_uvs,
	std::vector<glm::vec3> & in_normals,

	std::vector<unsigned short> & out_indices,
	std::vector<glm::vec3> & out_vertices,
	std::vector<glm::vec2> & out_uvs,
	std::vector<glm::vec3> & out_normals

){
	// Для каждой входной вершины
	for ( unsigned int i=0; i<in_vertices.size(); i++ ){

		// Попробуйте найти похожую вершину в out_XXXX
		unsigned short index;
		bool found = getSimilarVertexIndex(in_vertices[i], in_uvs[i], in_normals[i],     out_vertices, out_uvs, out_normals, index);

		if ( found ){ // Аналогичная вершина в VBO найдена!
			out_indices.push_back( index );
		}else{ // Иначе, необходимо добавить вершину в выходные данные.
			out_vertices.push_back( in_vertices[i]);
			out_uvs     .push_back( in_uvs[i]);
			out_normals .push_back( in_normals[i]);
			out_indices .push_back( (unsigned short)out_vertices.size() - 1 );
		}
	}
}

struct PackedVertex{ // Упакованная вершина

	glm::vec3 position;
	glm::vec2 uv;
	glm::vec3 normal;

	bool operator<(const PackedVertex that) const{
		return memcmp((void*)this, (void*)&that, sizeof(PackedVertex))>0;
	};

};

//Поиск индексов аналогичных вериш (Работа с PackedVertex)
inline bool getSimilarVertexIndex_fast( 
	PackedVertex & packed, 
	std::map<PackedVertex,unsigned short> & VertexToOutIndex,
	unsigned short & result
){
	std::map<PackedVertex,unsigned short>::iterator it = VertexToOutIndex.find(packed);
	if ( it == VertexToOutIndex.end() ){
		return false;
	}else{
		result = it->second;
		return true;
	}
}

inline void indexVBO(
	std::vector<glm::vec3> & in_vertices,
	std::vector<glm::vec2> & in_uvs,
	std::vector<glm::vec3> & in_normals,

	std::vector<unsigned short> & out_indices,
	std::vector<glm::vec3> & out_vertices,
	std::vector<glm::vec2> & out_uvs,
	std::vector<glm::vec3> & out_normals
){
	std::map<PackedVertex,unsigned short> VertexToOutIndex;

	// Для каждой входной вершины
	for ( unsigned int i=0; i<in_vertices.size(); i++ ){

		PackedVertex packed = {in_vertices[i], in_uvs[i], in_normals[i]};

		// Попробуйте найти похожую вершину в out_XXXX
		unsigned short index;
		bool found = getSimilarVertexIndex_fast( packed, VertexToOutIndex, index);

		if ( found ){ // Аналогичная вершина в VBO найдена!
			out_indices.push_back( index );
		}else{ // Иначе, необходимо добавить вершину в выходные данные.
			out_vertices.push_back( in_vertices[i]);
			out_uvs     .push_back( in_uvs[i]);
			out_normals .push_back( in_normals[i]);
			unsigned short newindex = (unsigned short)out_vertices.size() - 1;
			out_indices .push_back( newindex );
			VertexToOutIndex[ packed ] = newindex;
		}
	}
}


inline void indexVBO_TBN(
	std::vector<glm::vec3> & in_vertices,
	std::vector<glm::vec2> & in_uvs,
	std::vector<glm::vec3> & in_normals,
	std::vector<glm::vec3> & in_tangents,
	std::vector<glm::vec3> & in_bitangents,

	std::vector<unsigned short> & out_indices,
	std::vector<glm::vec3> & out_vertices,
	std::vector<glm::vec2> & out_uvs,
	std::vector<glm::vec3> & out_normals,
	std::vector<glm::vec3> & out_tangents,
	std::vector<glm::vec3> & out_bitangents
){
	// Для каждой входной вершины
	for ( unsigned int i=0; i<in_vertices.size(); i++ ){

		// Попробуйте найти похожую вершину в out_XXXX
		unsigned short index;
		bool found = getSimilarVertexIndex(in_vertices[i], in_uvs[i], in_normals[i],     out_vertices, out_uvs, out_normals, index);

		if ( found ){ // Аналогичная вершина в VBO найдена!
			out_indices.push_back( index );

			// Усредните касательные и битангенсы
			out_tangents[index] += in_tangents[i];
			out_bitangents[index] += in_bitangents[i];
		}else{ // Иначе, необходимо добавить вершину в выходные данные.
			out_vertices.push_back( in_vertices[i]);
			out_uvs     .push_back( in_uvs[i]);
			out_normals .push_back( in_normals[i]);
			out_tangents .push_back( in_tangents[i]);
			out_bitangents .push_back( in_bitangents[i]);
			out_indices .push_back( (unsigned short)out_vertices.size() - 1 );
		}
	}
}
