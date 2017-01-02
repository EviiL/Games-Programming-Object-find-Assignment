#ifndef _OBJECT_VECTOR_WRAPPER_H_
#define _OBJECT_VECTOR_WRAPPER_H_



struct ObjectVectorWrapper {
	typedef std::vector<Object> t_Object_Vector_;
	typedef t_Object_Vector_::iterator t_Object_Vector_Iterator_;
	typedef t_Object_Vector_::const_iterator t_Object_Vector_Const_Iterator_;
};

#endif