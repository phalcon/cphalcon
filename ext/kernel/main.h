/*
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifndef ZEPHIR_KERNEL_MAIN_H
#define ZEPHIR_KERNEL_MAIN_H

#include <Zend/zend_interfaces.h>
#include <ext/spl/spl_exceptions.h>
#include <ext/spl/spl_iterators.h>
#include <Zend/zend_string.h>
#include <Zend/zend.h>

extern zend_string* i_parent;
extern zend_string* i_static;
extern zend_string* i_self;

/* Main macros */
#define PH_DEBUG 0

#define PH_NOISY 256
#define PH_SILENT 1024
#define PH_READONLY 4096

#define PH_NOISY_CC PH_NOISY
#define PH_SILENT_CC PH_SILENT

#define PH_SEPARATE 256
#define PH_COPY 1024
#define PH_CTOR 4096

/* Deprecated */
#ifndef zend_uint
 #define zend_uint uint32_t
#endif

#ifndef ZEND_ACC_FINAL_CLASS
 #define ZEND_ACC_FINAL_CLASS ZEND_ACC_FINAL
#endif

#define SL(str) ZEND_STRL(str)
#define SS(str) ZEND_STRS(str)
#define ISL(str) (zephir_interned_##str), (sizeof(#str)-1)
#define ISS(str) (zephir_interned_##str), (sizeof(#str))

#include <Zend/zend_constants.h>
#include "kernel/exception.h"

/* class/interface registering */
#define ZEPHIR_REGISTER_CLASS(ns, class_name, lower_ns, name, methods, flags)		\
	{																				\
		zend_class_entry ce;														\
		memset(&ce, 0, sizeof(zend_class_entry));									\
		INIT_NS_CLASS_ENTRY(ce, #ns, #class_name, methods);							\
		lower_ns## _ ##name## _ce = zend_register_internal_class(&ce);				\
		if (UNEXPECTED(!lower_ns## _ ##name## _ce)) {								\
			const char *_n = (#ns);													\
			const char *_c = (#class_name);											\
			zend_error(E_ERROR, "%s\\%s: class registration has failed.", _n, _c);	\
			return FAILURE;															\
		}																			\
		lower_ns## _ ##name## _ce->ce_flags |= flags;								\
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
		lower_ns## _ ##lcname## _ce = zend_register_internal_class_ex(&ce, parent_ce); \
		if (!lower_ns## _ ##lcname## _ce) { \
			fprintf(stderr, "Zephir Error: Class to extend '%s' was not found when registering class '%s'\n", (parent_ce ? ZSTR_VAL(parent_ce->name) : "(null)"), ZEND_NS_NAME(#ns, #class_name)); \
			return FAILURE; \
		} \
		lower_ns## _ ##lcname## _ce->ce_flags |= flags;  \
	}

#define ZEPHIR_REGISTER_INTERFACE(ns, classname, lower_ns, name, methods) \
	{ \
		zend_class_entry ce; \
		memset(&ce, 0, sizeof(zend_class_entry)); \
		INIT_NS_CLASS_ENTRY(ce, #ns, #classname, methods); \
		lower_ns## _ ##name## _ce = zend_register_internal_interface(&ce); \
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
		lower_ns## _ ##lcname## _ce = zend_register_internal_interface(&ce); \
		if (parent_ce) { \
			zend_do_inheritance(ce, parent_ce); \
		} \
		if (!lower_ns## _ ##lcname## _ce) { \
			fprintf(stderr, "Can't register interface %s with parent %s\n", ZEND_NS_NAME(#ns, #classname), (parent_ce ? ZSTR_VAL(parent_ce->name) : "(null)")); \
			return FAILURE; \
		} \
	}

/** Return zval with always ctor */
#define RETURN_CTOR(var)        \
	do {                        \
		RETVAL_ZVAL(var, 1, 0); \
		ZEPHIR_MM_RESTORE();    \
		return;                 \
	} while (0)

/** Return zval with always ctor, without restoring the memory stack */
#define RETURN_CTORW(var)       \
	do {                        \
		RETVAL_ZVAL(var, 1, 0); \
		return;                 \
	} while (0)

/** Return zval checking if it's needed to ctor */
#define RETURN_CCTOR(v)            \
	do {                           \
		ZVAL_DUP(return_value, v); \
		ZEPHIR_MM_RESTORE();       \
		return;                    \
	} while (0)

/** Return zval checking if it's needed to ctor, without restoring the memory stack  */
#define RETURN_CCTORW(v)           \
	do {                           \
		ZVAL_DUP(return_value, v); \
		return;                    \
	} while (0)

/** Return zval with always ctor, without restoring the memory stack */
#define RETURN_THISW() \
	RETURN_ZVAL(getThis(), 1, 0);

/** Return this pointer */
#define RETURN_THIS() { \
		RETVAL_ZVAL(getThis(), 1, 0); \
	} \
	ZEPHIR_MM_RESTORE(); \
	return;

#define RETURN_LCTORW(var) RETURN_CCTORW(var);

#define RETURN_LCTOR(var) RETURN_CCTOR(var);

/**
 * Returns a zval in an object member
 */
#define RETURN_MEMBER(object, member_name) \
	zephir_return_property(return_value, object, SL(member_name)); \
	return;

/** Return without change return_value */
#define RETURN_MM()                 { ZEPHIR_MM_RESTORE(); return; }

/** Return null restoring memory frame */
#define RETURN_MM_BOOL(value)       { RETVAL_BOOL(value); ZEPHIR_MM_RESTORE(); return; }

/** Return string restoring memory frame */
#define RETURN_MM_STRING(str)       { RETVAL_STRING(str); ZEPHIR_MM_RESTORE(); return; }
#define RETURN_MM_EMPTY_STRING()    { RETVAL_EMPTY_STRING(); ZEPHIR_MM_RESTORE(); return; }

/* Return long */
#define RETURN_MM_LONG(value)       { RETVAL_LONG(value); ZEPHIR_MM_RESTORE(); return; }

/* Return double */
#define RETURN_MM_DOUBLE(value)     { RETVAL_DOUBLE(value); ZEPHIR_MM_RESTORE(); return; }

/**
 * Returns a zval in an object member
 */
#define RETURN_MM_MEMBER(object, member_name) \
  zephir_return_property(return_value, object, SL(member_name)); \
  RETURN_MM();

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

/** Return null restoring memory frame */
#define RETURN_MM_NULL()            { RETVAL_NULL(); ZEPHIR_MM_RESTORE(); return; }

/* Globals functions */
int zephir_get_global(zval *arr, const char *global, unsigned int global_length);

/* Count */
void zephir_fast_count(zval *result, zval *array);
int zephir_fast_count_ev(zval *array);
int zephir_fast_count_int(zval *value);

int zephir_is_callable(zval *var);
int zephir_is_scalar(zval *var);

int zephir_function_exists(const zval *function_name);
int zephir_function_exists_ex(const char *func_name, unsigned int func_len);

zend_class_entry* zephir_get_internal_ce(const char *class_name, unsigned int class_name_len);

/* types */
void zephir_gettype(zval *return_value, zval *arg);

/* Utils functions */
static inline int zephir_maybe_separate_zval(zval* z)
{
	if (!Z_REFCOUNTED_P(z) || (Z_REFCOUNT_P(z) > 1 && !Z_ISREF_P(z))) {
		if (!(Z_COPYABLE_P(z) && !Z_REFCOUNTED_P(z))) {
			Z_DELREF_P(z);
		}
		zval_copy_ctor_func(z);
		return 1;
	}

	return 0;
}

#define ZEPHIR_SET_SYMBOL(symbol_table, name, value) { \
	Z_TRY_ADDREF_P(value); \
	zend_hash_str_update(symbol_table, name, sizeof(name) - 1, value); \
}

int zephir_is_iterable_ex(zval *arr, int duplicate);

/** Check if an array is iterable or not */
#define zephir_is_iterable(var, duplicate, file, line) \
	if (!zephir_is_iterable_ex(var, duplicate)) { \
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(), "The argument is not initialized or iterable()", file, line); \
		ZEPHIR_MM_RESTORE(); \
		return; \
	}

/* Fetch Parameters */
int zephir_fetch_parameters(int num_args, int required_args, int optional_args, ...);

/** Low overhead parse/fetch parameters */
#define zephir_fetch_params(memory_grow, required_params, optional_params, ...) \
	if (zephir_fetch_parameters(ZEND_NUM_ARGS(), required_params, optional_params, __VA_ARGS__) == FAILURE) { \
		if (memory_grow) { \
			RETURN_MM_NULL(); \
		} else { \
			RETURN_NULL(); \
		} \
	}

#define zephir_fetch_params_without_memory_grow(required_params, optional_params, ...) \
	if (zephir_fetch_parameters(ZEND_NUM_ARGS(), required_params, optional_params, __VA_ARGS__) == FAILURE) { \
		RETURN_NULL(); \
	}

#define ZEPHIR_CREATE_OBJECT(obj, class_type) \
	{ \
		zend_object *object = zend_objects_new(class_type); \
		ZVAL_UNDEF(obj); \
		ZVAL_OBJ(obj, object); \
		object_properties_init(object, class_type); \
	}

#define ZEPHIR_MAKE_REF(obj) ZVAL_NEW_REF(obj, obj);
#define ZEPHIR_UNREF(obj) ZVAL_UNREF(obj);

#define ZEPHIR_GET_CONSTANT(return_value, const_name) do { \
	zval *_constant_ptr = zend_get_constant_str(SL(const_name)); \
	if (_constant_ptr == NULL) { \
	    zval _null; \
		ZVAL_NULL(&_null); \
		ZVAL_COPY(return_value, &_null); \
		zephir_ptr_dtor(&_null); \
	} else { \
	    ZVAL_COPY(return_value, _constant_ptr); \
	} \
} while(0)

#define ZEPHIR_GET_IMKEY(var, it) it->funcs->get_current_key(it, &var);

/* Declare class constants */
int zephir_declare_class_constant_null(zend_class_entry *ce, const char *name, size_t name_length);
int zephir_declare_class_constant_long(zend_class_entry *ce, const char *name, size_t name_length, zend_long value);
int zephir_declare_class_constant_bool(zend_class_entry *ce, const char *name, size_t name_length, zend_bool value);
int zephir_declare_class_constant_double(zend_class_entry *ce, const char *name, size_t name_length, double value);
int zephir_declare_class_constant_stringl(zend_class_entry *ce, const char *name, size_t name_length, const char *value, size_t value_length);
int zephir_declare_class_constant_string(zend_class_entry *ce, const char *name, size_t name_length, const char *value);

int zephir_is_php_version(unsigned int id);

/** Method declaration for API generation */
#define ZEPHIR_DOC_METHOD(class_name, method)

#ifndef ZEPHIR_RELEASE
#define ZEPHIR_DEBUG_PARAMS , const char *file, int line
#define ZEPHIR_DEBUG_PARAMS_DUMMY , "", 0
#else
#define ZEPHIR_DEBUG_PARAMS , const char *file, int line
#define ZEPHIR_DEBUG_PARAMS_DUMMY , "", 0
#endif

void zephir_get_args(zval* return_value);
void zephir_get_arg(zval* return_value, zend_long idx);

void zephir_module_init();

#endif /* ZEPHIR_KERNEL_MAIN_H */
