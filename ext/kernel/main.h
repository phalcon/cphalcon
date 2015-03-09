
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_MAIN_H
#define ZEPHIR_KERNEL_MAIN_H

#include "Zend/zend_interfaces.h"
#include "ext/spl/spl_exceptions.h"
#include "ext/spl/spl_iterators.h"

/** Main macros */
#define PH_DEBUG 0

#define PH_NOISY 256
#define PH_SILENT 1024
#define PH_READONLY 4096

#define PH_NOISY_CC PH_NOISY TSRMLS_CC
#define PH_SILENT_CC PH_SILENT TSRMLS_CC

#define PH_SEPARATE 256
#define PH_COPY 1024
#define PH_CTOR 4096

#define SL(str) ZEND_STRL(str)
#define SS(str) ZEND_STRS(str)
#define ISL(str) (zephir_interned_##str), (sizeof(#str)-1)
#define ISS(str) (zephir_interned_##str), (sizeof(#str))

#include "Zend/zend_constants.h"
#include "kernel/exception.h"

/* Compatibility with PHP 5.3 */
#ifndef ZVAL_COPY_VALUE
 #define ZVAL_COPY_VALUE(z, v)\
  (z)->value = (v)->value;\
  Z_TYPE_P(z) = Z_TYPE_P(v);
#endif

#ifndef INIT_PZVAL_COPY
 #define INIT_PZVAL_COPY(z, v) ZVAL_COPY_VALUE(z, v);\
  Z_SET_REFCOUNT_P(z, 1);\
  Z_UNSET_ISREF_P(z);
#endif

/* Startup functions */
zend_class_entry *zephir_register_internal_interface_ex(zend_class_entry *orig_ce, zend_class_entry *parent_ce TSRMLS_DC);

/* Globals functions */
int zephir_init_global(char *global, unsigned int global_length TSRMLS_DC);
int zephir_get_global(zval **arr, const char *global, unsigned int global_length TSRMLS_DC);

int zephir_is_callable(zval *var TSRMLS_DC);
int zephir_function_exists(const zval *function_name TSRMLS_DC);
int zephir_function_exists_ex(const char *func_name, unsigned int func_len TSRMLS_DC);
int zephir_function_quick_exists_ex(const char *func_name, unsigned int func_len, unsigned long key TSRMLS_DC);
zend_class_entry* zephir_get_internal_ce(const char *class_name, unsigned int class_name_len TSRMLS_DC);

/* types */
void zephir_gettype(zval *return_value, zval *arg TSRMLS_DC);

/* Count */
void zephir_fast_count(zval *result, zval *array TSRMLS_DC);
int zephir_fast_count_ev(zval *array TSRMLS_DC);
int zephir_fast_count_int(zval *value TSRMLS_DC);

/* Utils functions */
static inline int zephir_maybe_separate_zval(zval** z)
{
	if (Z_REFCOUNT_PP(z) > 1 && !Z_ISREF_PP(z)) {
		zval *new_zv;

		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, *z);
		*z = new_zv;
		zval_copy_ctor(new_zv);

		return 1;
	}

	return 0;
}

int zephir_is_iterable_ex(zval *arr, HashTable **arr_hash, HashPosition *hash_position, int duplicate, int reverse);
void zephir_safe_zval_ptr_dtor(zval *pzval);

/* Fetch Parameters */
int zephir_fetch_parameters(int num_args TSRMLS_DC, int required_args, int optional_args, ...);

/** Symbols */
#define ZEPHIR_READ_SYMBOL(var, auxarr, name) if (EG(active_symbol_table)){ \
	if (zend_hash_find(EG(active_symbol_table), name, sizeof(name), (void **)  &auxarr) == SUCCESS) { \
			var = *auxarr; \
		} else { \
			ZVAL_NULL(var); \
		} \
	} else { \
		ZVAL_NULL(var); \
	}

#define RETURN_ON_FAILURE(what) \
	do { \
		if (what == FAILURE) { \
			return; \
		} \
	} while (0)

#define RETURN_MM_ON_FAILURE(what) \
	do { \
		if (what == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while (0)

#if PHP_VERSION_ID < 50600

/** Return zval checking if it's needed to ctor */
#define RETURN_CCTOR(var) { \
		*(return_value) = *(var); \
		if (Z_TYPE_P(var) > IS_BOOL) { \
			zephir_copy_ctor(return_value, var); \
		} \
		INIT_PZVAL(return_value) \
	} \
	ZEPHIR_MM_RESTORE(); \
	return;

/** Return zval checking if it's needed to ctor, without restoring the memory stack  */
#define RETURN_CCTORW(var) { \
		*(return_value) = *(var); \
		if (Z_TYPE_P(var) > IS_BOOL) { \
			zephir_copy_ctor(return_value, var); \
		} \
		INIT_PZVAL(return_value) \
	} \
	return;

/** Return zval with always ctor */
#define RETURN_CTOR(var) { \
		RETVAL_ZVAL(var, 1, 0); \
	} \
	ZEPHIR_MM_RESTORE(); \
	return;

/** Return zval with always ctor, without restoring the memory stack */
#define RETURN_CTORW(var) { \
		RETVAL_ZVAL(var, 1, 0); \
	} \
	return;

/** Return this pointer */
#define RETURN_THIS() { \
		RETVAL_ZVAL(this_ptr, 1, 0); \
	} \
	ZEPHIR_MM_RESTORE(); \
	return;

/** Return zval with always ctor, without restoring the memory stack */
#define RETURN_THISW() \
	RETURN_ZVAL(this_ptr, 1, 0);

#else

/** Return zval checking if it's needed to ctor */
#define RETURN_CCTOR(var) { \
		RETVAL_ZVAL_FAST(var); \
	} \
	ZEPHIR_MM_RESTORE(); \
	return;

/** Return zval checking if it's needed to ctor, without restoring the memory stack  */
#define RETURN_CCTORW(var) { \
		RETVAL_ZVAL_FAST(var); \
	} \
	return;

/** Return zval with always ctor */
#define RETURN_CTOR(var) { \
		RETVAL_ZVAL_FAST(var); \
	} \
	ZEPHIR_MM_RESTORE(); \
	return;

/** Return zval with always ctor, without restoring the memory stack */
#define RETURN_CTORW(var) { \
		RETVAL_ZVAL_FAST(var); \
	} \
	return;

/** Return this pointer */
#define RETURN_THIS() { \
		RETVAL_ZVAL_FAST(this_ptr); \
	} \
	ZEPHIR_MM_RESTORE(); \
	return;

/** Return zval with always ctor, without restoring the memory stack */
#define RETURN_THISW() \
	RETURN_ZVAL_FAST(this_ptr);

#endif

/** Returns variables without ctor */
#define RETURN_NCTOR(var) { \
		*(return_value) = *(var); \
		INIT_PZVAL(return_value) \
	} \
	ZEPHIR_MM_RESTORE(); \
	return;

/** Returns variables without ctor, without restoring the memory stack */
#define RETURN_NCTORW(var) { \
		*(return_value) = *(var); \
		INIT_PZVAL(return_value) \
	} \
	return;

/** Check for ctor on the same return_value */
#define RETURN_SCTOR() \
	if (Z_TYPE_P(return_value) > IS_BOOL) { \
		zval_copy_ctor(return_value); \
	} \
	ZEPHIR_MM_RESTORE(); \
	return;

#define RETURN_LCTOR(var) { \
	zend_uchar is_ref = Z_ISREF_P(return_value);       \
	zend_uint refcount = Z_REFCOUNT_P(return_value);   \
	(return_value)->value = var.value;                \
	Z_TYPE_P(return_value) = Z_TYPE(var);              \
	zval_copy_ctor(return_value);                      \
	Z_SET_ISREF_TO_P(return_value, is_ref);            \
	Z_SET_REFCOUNT_P(return_value, refcount);          \
	ZEPHIR_MM_RESTORE(); \
	return; \
}

#define RETURN_LCTORW(var) { \
	zend_uchar is_ref = Z_ISREF_P(return_value);       \
	zend_uint refcount = Z_REFCOUNT_P(return_value);   \
	(return_value)->value = var.value;                \
	Z_TYPE_P(return_value) = Z_TYPE(var);              \
	zval_copy_ctor(return_value);                      \
	Z_SET_ISREF_TO_P(return_value, is_ref);            \
	Z_SET_REFCOUNT_P(return_value, refcount);          \
	return; \
}

/**
 * Check for ctor on the same return_value, without restoring the memory stack
 */
#define RETURN_SCTORW() \
	if (Z_TYPE_P(return_value) > IS_BOOL) { \
		zval_copy_ctor(return_value); \
	} \
	return;

/**
 * Returns a zval in an object member
 */
#define RETURN_MEMBER(object, member_name) \
	zephir_return_property_quick(return_value, return_value_ptr, object, SL(member_name), zend_inline_hash_func(SS(member_name)) TSRMLS_CC); \
	return;

/**
 * Returns a zval in an object member
 */
#define RETURN_MM_MEMBER(object, member_name) \
  zephir_return_property_quick(return_value, return_value_ptr, object, SL(member_name), zend_inline_hash_func(SS(member_name)) TSRMLS_CC); \
  RETURN_MM();

/**
 * Returns a zval in an object member (quick)
 */
#define RETURN_MEMBER_QUICK(object, member_name, key) \
 	zephir_return_property_quick(return_value, NULL, object, SL(member_name), key TSRMLS_CC); \
	return;

/**
 * Returns a zval in an object member (quick)
 */
#define RETURN_MM_MEMBER_QUICK(object, member_name, key) \
  zephir_return_property_quick(return_value, NULL, object, SL(member_name), key TSRMLS_CC); \
  RETURN_MM();

/** Return without change return_value */
#define RETURN_MM()                 { ZEPHIR_MM_RESTORE(); return; }

/** Return null restoring memory frame */
#define RETURN_MM_BOOL(value)       { RETVAL_BOOL(value); ZEPHIR_MM_RESTORE(); return; }

/** Return null restoring memory frame */
#define RETURN_MM_NULL()            { RETVAL_NULL(); ZEPHIR_MM_RESTORE(); return; }

/** Return bool restoring memory frame */
#define RETURN_MM_FALSE             { RETVAL_FALSE; ZEPHIR_MM_RESTORE(); return; }
#define RETURN_MM_TRUE              { RETVAL_TRUE; ZEPHIR_MM_RESTORE(); return; }

/** Return string restoring memory frame */
#define RETURN_MM_STRING(str, copy) { RETVAL_STRING(str, copy); ZEPHIR_MM_RESTORE(); return; }
#define RETURN_MM_EMPTY_STRING()    { RETVAL_EMPTY_STRING(); ZEPHIR_MM_RESTORE(); return; }

/** Return empty array */
#define RETVAL_EMPTY_ARRAY()        { array_init(return_value); }
#define RETURN_EMPTY_ARRAY()        { RETVAL_EMPTY_ARRAY(); return; }
#define RETURN_MM_EMPTY_ARRAY()     { RETVAL_EMPTY_ARRAY(); ZEPHIR_MM_RESTORE(); return; }

/* Return long */
#define RETURN_MM_LONG(value)       { RETVAL_LONG(value); ZEPHIR_MM_RESTORE(); return; }

/* Return double */
#define RETURN_MM_DOUBLE(value)     { RETVAL_DOUBLE(value); ZEPHIR_MM_RESTORE(); return; }

/* Compat for interned strings < 5.4 */
#ifndef IS_INTERNED
#define IS_INTERNED(key) 0
#define INTERNED_HASH(key) 0
#endif

/* Compat for reallocation of interned strings < 5.4 */
#ifndef str_erealloc
#define str_erealloc(str, new_len) \
	(IS_INTERNED(str) \
	? _str_erealloc(str, new_len, INTERNED_LEN(str)) \
	: erealloc(str, new_len))

static inline char *_str_erealloc(char *str, size_t new_len, size_t old_len) {
	char *buf = (char *) emalloc(new_len);
	memcpy(buf, str, old_len);
	return buf;
}
#endif

/** Get the current hash key without copying the hash key */
#define ZEPHIR_GET_HKEY(var, hash, hash_position) \
	zephir_get_current_key(&var, hash, &hash_position TSRMLS_CC);

/** Get current hash key copying the hash_value if needed */
#define ZEPHIR_GET_HMKEY(var, hash, hash_pointer) \
	{\
		int hash_type; \
		char *hash_index; \
		uint hash_index_len; \
		ulong hash_num; \
		 \
		ZEPHIR_INIT_NVAR(var); \
		hash_type = zend_hash_get_current_key_ex(hash, &hash_index, &hash_index_len, &hash_num, 0, &hash_pointer); \
		if (hash_type == HASH_KEY_IS_STRING) { \
			if (IS_INTERNED(hash_index)) { \
				ZVAL_STRINGL(var, hash_index, hash_index_len - 1, 0); \
			} else { \
				ZVAL_STRINGL(var, hash_index, hash_index_len - 1, 1); \
			} \
		} else { \
			if (hash_type == HASH_KEY_IS_LONG) { \
				ZVAL_LONG(var, hash_num); \
			}\
		}\
	}

/** Get current hash key copying the iterator if needed */

#if PHP_VERSION_ID < 50500

#define ZEPHIR_GET_IMKEY(var, it) \
	{\
		int key_type, str_key_len; \
		ulong int_key; \
		char *str_key; \
		\
		ZEPHIR_INIT_NVAR(var); \
		key_type = it->funcs->get_current_key(it, &str_key, &str_key_len, &int_key TSRMLS_CC); \
		if (key_type == HASH_KEY_IS_STRING) { \
			ZVAL_STRINGL(var, str_key, str_key_len, 1); \
		} else { \
			if (key_type == HASH_KEY_IS_LONG) { \
				ZVAL_LONG(var, int_key); \
			} else { \
				ZVAL_NULL(var); \
			} \
		} \
	}

#else

#define ZEPHIR_GET_IMKEY(var, it) \
	{\
		ZEPHIR_INIT_NVAR(var); \
		it->funcs->get_current_key(it, var TSRMLS_CC); \
	}

#endif

/** Foreach */
#define ZEPHIR_GET_FOREACH_KEY(var, hash, hash_pointer) ZEPHIR_GET_HMKEY(var, hash, hash_pointer)

/** Check if an array is iterable or not */
#define zephir_is_iterable(var, array_hash, hash_pointer, duplicate, reverse, file, line) \
	if (!var || !zephir_is_iterable_ex(var, array_hash, hash_pointer, duplicate, reverse)) { \
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "The argument is not initialized or iterable()", file, line); \
		ZEPHIR_MM_RESTORE(); \
		return; \
	}

#define ZEPHIR_GET_FOREACH_VALUE(var) \
	ZEPHIR_OBS_NVAR(var); \
	var = *hd; \
	Z_ADDREF_P(var);

#define ZEPHIR_GET_HVALUE(var, hd) \
	ZEPHIR_OBS_NVAR(var); \
	var = *hd; \
	Z_ADDREF_P(var);

/** class/interface registering */
#define ZEPHIR_REGISTER_CLASS(ns, class_name, lower_ns, name, methods, flags) \
	{ \
		zend_class_entry ce; \
		memset(&ce, 0, sizeof(zend_class_entry)); \
		INIT_NS_CLASS_ENTRY(ce, #ns, #class_name, methods); \
		lower_ns## _ ##name## _ce = zend_register_internal_class(&ce TSRMLS_CC); \
		lower_ns## _ ##name## _ce->ce_flags |= flags;  \
	}

#define ZEPHIR_REGISTER_CLASS_EX(ns, class_name, lower_ns, lcname, parent_ce, methods, flags) \
	{ \
		zend_class_entry ce; \
		if (!parent_ce) { \
			fprintf(stderr, "Can't register class %s::%s with null parent\n", #ns, #class_name); \
			return FAILURE; \
		} \
		memset(&ce, 0, sizeof(zend_class_entry)); \
		INIT_NS_CLASS_ENTRY(ce, #ns, #class_name, methods); \
		lower_ns## _ ##lcname## _ce = zend_register_internal_class_ex(&ce, parent_ce, NULL TSRMLS_CC); \
		if (!lower_ns## _ ##lcname## _ce) { \
			fprintf(stderr, "Phalcon Error: Class to extend '%s' was not found when registering class '%s'\n", (parent_ce ? parent_ce->name : "(null)"), ZEND_NS_NAME(#ns, #class_name)); \
			return FAILURE; \
		} \
		lower_ns## _ ##lcname## _ce->ce_flags |= flags;  \
	}

#define ZEPHIR_REGISTER_INTERFACE(ns, classname, lower_ns, name, methods) \
	{ \
		zend_class_entry ce; \
		memset(&ce, 0, sizeof(zend_class_entry)); \
		INIT_NS_CLASS_ENTRY(ce, #ns, #classname, methods); \
		lower_ns## _ ##name## _ce = zend_register_internal_interface(&ce TSRMLS_CC); \
	}

#define ZEPHIR_REGISTER_INTERFACE_EX(ns, classname, lower_ns, lcname, parent_ce, methods) \
	{ \
		zend_class_entry ce; \
		if (!parent_ce) { \
			fprintf(stderr, "Can't register interface %s with null parent\n", ZEND_NS_NAME(#ns, #classname)); \
			return FAILURE; \
		} \
		memset(&ce, 0, sizeof(zend_class_entry)); \
		INIT_NS_CLASS_ENTRY(ce, #ns, #classname, methods); \
		lower_ns## _ ##lcname## _ce = zephir_register_internal_interface_ex(&ce, parent_ce TSRMLS_CC); \
		if (!lower_ns## _ ##lcname## _ce) { \
			fprintf(stderr, "Can't register interface %s with parent %s\n", ZEND_NS_NAME(#ns, #classname), (parent_ce ? parent_ce->name : "(null)")); \
			return FAILURE; \
		} \
	}

/** Method declaration for API generation */
#define ZEPHIR_DOC_METHOD(class_name, method)

/** Low overhead parse/fetch parameters */
#define zephir_fetch_params(memory_grow, required_params, optional_params, ...) \
	if (zephir_fetch_parameters(ZEND_NUM_ARGS() TSRMLS_CC, required_params, optional_params, __VA_ARGS__) == FAILURE) { \
		if (memory_grow) { \
			RETURN_MM_NULL(); \
		} else { \
			RETURN_NULL(); \
		} \
	}

#define ZEPHIR_VERIFY_INTERFACE(instance, interface_ce) \
	do { \
		if (Z_TYPE_P(instance) != IS_OBJECT || !instanceof_function_ex(Z_OBJCE_P(instance), interface_ce, 1 TSRMLS_CC)) { \
			char *buf; \
			if (Z_TYPE_P(instance) != IS_OBJECT) { \
				spprintf(&buf, 0, "Unexpected value type: expected object implementing %s, %s given", interface_ce->name, zend_zval_type_name(instance)); \
			} \
			else { \
				spprintf(&buf, 0, "Unexpected value type: expected object implementing %s, object of type %s given", interface_ce->name, Z_OBJCE_P(instance)->name); \
			} \
			ZEPHIR_THROW_EXCEPTION_STR(spl_ce_LogicException, buf); \
			efree(buf); \
			return; \
		} \
	} while (0)


#define ZEPHIR_VERIFY_CLASS(instance, class_ce) \
	do { \
		if (Z_TYPE_P(instance) != IS_OBJECT || !instanceof_function_ex(Z_OBJCE_P(instance), class_ce, 0 TSRMLS_CC)) { \
			char *buf; \
			if (Z_TYPE_P(instance) != IS_OBJECT) { \
				spprintf(&buf, 0, "Unexpected value type: expected object of type %s, %s given", class_ce->name, zend_zval_type_name(instance)); \
			} \
			else { \
				spprintf(&buf, 0, "Unexpected value type: expected object of type %s, object of type %s given", class_ce->name, Z_OBJCE_P(instance)->name); \
			} \
			ZEPHIR_THROW_EXCEPTION_STR(spl_ce_LogicException, buf); \
			efree(buf); \
			return; \
		} \
	} while (0)

#define ZEPHIR_GET_CONSTANT(return_value, const_name) \
	RETURN_MM_ON_FAILURE(zend_get_constant(SL(const_name), return_value TSRMLS_CC));

#ifndef ZEPHIR_RELEASE
#define ZEPHIR_DEBUG_PARAMS , const char *file, int line
#define ZEPHIR_DEBUG_PARAMS_DUMMY , "", 0
#else
#define ZEPHIR_DEBUG_PARAMS , const char *file, int line
#define ZEPHIR_DEBUG_PARAMS_DUMMY , "", 0
#endif

#define ZEPHIR_CHECK_POINTER(v) if (!v) fprintf(stderr, "%s:%d\n", __PRETTY_FUNCTION__, __LINE__);

#define zephir_is_php_version(id) ((PHP_VERSION_ID >= id && PHP_VERSION_ID <= (id + 10000)) ?  1 : 0)

#endif /* ZEPHIR_KERNEL_MAIN_H */
