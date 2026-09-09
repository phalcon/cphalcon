/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "php_ext.h"

#include <Zend/zend_closures.h>
#include <Zend/zend_string.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"

int zephir_instance_of_ev(zval *object, const zend_class_entry *ce)
{
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;
	if (Z_TYPE_P(z) != IS_OBJECT) {
		php_error_docref(NULL, E_WARNING, "instanceof expects an object instance");
		return 0;
	}

	return instanceof_function(Z_OBJCE_P(z), ce);
}

/**
 * Check if an object is instance of a class
 */
int zephir_is_instance_of(zval *object, const char *class_name, unsigned int class_length)
{
	zend_class_entry *ce, *temp_ce;
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;

	if (Z_TYPE_P(z) == IS_OBJECT) {

		ce = Z_OBJCE_P(z);
		if (ZSTR_LEN(ce->name) == class_length) {
			if (!zend_binary_strcasecmp(ZSTR_VAL(ce->name), ZSTR_LEN(ce->name), class_name, class_length)) {
				return 1;
			}
		}

		temp_ce = zephir_fetch_class_str_ex(class_name, class_length, ZEND_FETCH_CLASS_DEFAULT);
		if (temp_ce) {
			return instanceof_function(ce, temp_ce);
		}
	}

	return 0;
}

int zephir_zval_is_traversable(zval *object)
{
	zend_class_entry *ce;
	uint32_t i;
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;

	if (Z_TYPE_P(z) == IS_OBJECT) {
		ce = Z_OBJCE_P(z);

		if (ce->get_iterator || (ce->parent && ce->parent->get_iterator)) {
			return 1;
		}

		for (i = 0; i < ce->num_interfaces; i++) {
			if (ce->interfaces[i] == zend_ce_aggregate ||
				ce->interfaces[i] == zend_ce_iterator ||
				ce->interfaces[i] == zend_ce_traversable
			) {
				return 1;
			}
		}
	}

	return 0;
}

/**
 * Returns the called in class in the current scope
 */
void zephir_get_called_class(zval *return_value)
{
	zend_class_entry *called_scope = zend_get_called_scope(EG(current_execute_data));
	if (called_scope) {
		ZVAL_STR(return_value, zend_string_dup(called_scope->name, 0));
	}

	if (!zend_get_executed_scope())  {
		php_error_docref(NULL, E_WARNING, "zephir_get_called_class() called from outside a class");
	}
}

zend_class_entry *zephir_fetch_class_str_ex(const char *class_name, size_t length, int fetch_type)
{
	zend_class_entry *retval;
	zend_string *str = zend_string_init(class_name, length, 0);
	retval = zend_fetch_class(str, fetch_type);
	zend_string_release(str);
	return retval;
}

/**
 * Fetches a zend class entry from a zval value
 */
zend_class_entry *zephir_fetch_class(zval *class_name)
{
	zval *z = Z_ISREF_P(class_name) ? Z_REFVAL_P(class_name) : class_name;
	if (Z_TYPE_P(z) == IS_STRING) {
		return zend_fetch_class(Z_STR_P(z), ZEND_FETCH_CLASS_DEFAULT);
	}

	php_error_docref(NULL, E_WARNING, "class name must be a string");
	return zend_standard_class_def;
}

/**
 * Returns a class name into a zval result
 */
void zephir_get_class(zval *result, zval *object, int lower)
{
	zend_class_entry *ce;
	zend_string *class_name;
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;

	if (Z_TYPE_P(z) == IS_OBJECT) {
		ce = Z_OBJCE_P(z);
		//zval_ptr_dtor(result);
		class_name = zend_string_init(ZSTR_VAL(ce->name), ZSTR_LEN(ce->name), 0);
		ZVAL_STR(result, class_name);

		if (lower) {
			zend_str_tolower(Z_STRVAL_P(result), Z_STRLEN_P(result));
		}

	} else {
		ZVAL_NULL(result);
		php_error_docref(NULL, E_WARNING, "zephir_get_class expects an object");
	}
}

/**
 * Returns a class name into a zval result
 */
void zephir_get_class_ns(zval *result, zval *object, int lower)
{
	int found = 0;
	unsigned int i, class_length;
	char *cursor, *class_name;
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;

	if (Z_TYPE_P(z) != IS_OBJECT) {
		if (Z_TYPE_P(z) != IS_STRING) {
			ZVAL_NULL(result);
			php_error_docref(NULL, E_WARNING, "zephir_get_class_ns expects an object");
			return;
		}

		class_name   = Z_STRVAL_P(z);
		class_length = Z_STRLEN_P(z);
	}
	else {
		zend_class_entry *ce = Z_OBJCE_P(z);
		class_name   = ZSTR_VAL(ce->name);
		class_length = ZSTR_LEN(ce->name);
	}

	if (!class_length) {
		ZVAL_NULL(result);
		return;
	}

	i = class_length;
	cursor = (char *) (class_name + class_length - 1);

	while (i > 0) {
		if ((*cursor) == '\\') {
			found = 1;
			break;
		}
		cursor--;
		i--;
	}

	if (found) {
		int cursor_length = class_length - i;
		cursor = (char *) emalloc(cursor_length + 1);
		memcpy(cursor, class_name + i, cursor_length);
		cursor[cursor_length] = 0;
		ZVAL_STRING(result, cursor);
		efree(cursor);
	} else {
		ZVAL_STRINGL(result, class_name, class_length);
	}

	if (lower) {
		zend_str_tolower(Z_STRVAL_P(result), Z_STRLEN_P(result));
	}
}

/**
 * Returns a namespace from a class name
 */
void zephir_get_ns_class(zval *result, zval *object, int lower)
{
	int found = 0;
	unsigned int i, j, class_length;
	char *cursor, *class_name;
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;

	ZVAL_NULL(result);

	if (Z_TYPE_P(z) != IS_OBJECT) {
		if (Z_TYPE_P(z) != IS_STRING) {
			php_error_docref(NULL, E_WARNING, "zephir_get_ns_class expects an object");
			return;
		}

		class_name   = Z_STRVAL_P(z);
		class_length = Z_STRLEN_P(z);
	}
	else {
		zend_class_entry *ce = Z_OBJCE_P(z);
		class_name   = ZSTR_VAL(ce->name);
		class_length = ZSTR_LEN(ce->name);
	}

	if (!class_length) {
		return;
	}

	j = 0;
	i = class_length;
	cursor = (char *) (class_name + class_length - 1);

	while (i > 0) {
		if ((*cursor) == '\\') {
			found = 1;
			break;
		}
		cursor--;
		i--;
		j++;
	}

	if (j > 0) {

		if (found) {
			int cursor_length = class_length - j - 1;
			cursor = (char *) emalloc(cursor_length + 1);
			memcpy(cursor, class_name, cursor_length);
			cursor[cursor_length] = 0;
			ZVAL_STRING(result, cursor);
			efree(cursor);
		} else {
			ZVAL_EMPTY_STRING(result);
		}

		if (lower) {
			zend_str_tolower(Z_STRVAL_P(result), Z_STRLEN_P(result));
		}
	}
}

/**
 * Checks if a class exist
 */
int zephir_class_exists(zval *class_name, int autoload)
{
	zend_class_entry *ce;
	zval *z = Z_ISREF_P(class_name) ? Z_REFVAL_P(class_name) : class_name;

	if (Z_TYPE_P(z) == IS_STRING) {
		if ((ce = zend_lookup_class_ex(Z_STR_P(z), NULL, autoload)) != NULL) {
			return (ce->ce_flags & (ZEND_ACC_INTERFACE | (ZEND_ACC_INTERFACE | ZEND_ACC_TRAIT))) == 0;
		}
		return 0;
	}

	php_error_docref(NULL, E_WARNING, "class name must be a string");
	return 0;
}

/**
 * Checks if a interface exist
 */
int zephir_interface_exists(zval *class_name, int autoload)
{
	zend_class_entry *ce;
	zval *z = Z_ISREF_P(class_name) ? Z_REFVAL_P(class_name) : class_name;

	if (Z_TYPE_P(z) == IS_STRING) {
		if ((ce = zend_lookup_class(Z_STR_P(z))) != NULL) {
			return ((ce->ce_flags & ZEND_ACC_INTERFACE) > 0);
		}
		return 0;
	}

	php_error_docref(NULL, E_WARNING, "interface name must be a string");
	return 0;
}

/**
 * Clones an object from obj to destination
 */
int zephir_clone(zval *destination, zval *obj)
{
	int status = SUCCESS;
	zend_class_entry *ce;
	zend_object_clone_obj_t clone_call;

	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL, E_ERROR, "__clone method called on non-object");
		status = FAILURE;
	} else {
		ce = Z_OBJCE_P(obj);
		clone_call =  Z_OBJ_HT_P(obj)->clone_obj;
		if (!clone_call) {
			if (ce) {
				php_error_docref(NULL, E_ERROR, "Trying to clone an uncloneable object of class %s", ZSTR_VAL(ce->name));
			} else {
				php_error_docref(NULL, E_ERROR, "Trying to clone an uncloneable object");
			}
			status = FAILURE;
		} else {
			if (!EG(exception)) {
				ZVAL_OBJ(destination, clone_call(Z_OBJ_P(obj)));
				if (EG(exception)) {
					zval_ptr_dtor(destination);
				}
			}
		}
	}

	return status;
}

/**
 * Checks if property exists on object
 */
int zephir_isset_property(zval *object, const char *property_name, unsigned int property_length)
{
	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (EXPECTED(zend_hash_str_exists(&Z_OBJCE_P(object)->properties_info, property_name, property_length))) {
			return 1;
		}

		return zend_hash_str_exists(
			Z_OBJ_HT_P(object)->get_properties(Z_OBJ_P(object)),
			property_name,
			property_length
		);
	}

	return 0;
}

/**
 * Checks if string property exists on object
 */
int zephir_isset_property_zval(zval *object, const zval *property)
{
	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (Z_TYPE_P(property) == IS_STRING) {
			if (EXPECTED(zend_hash_str_exists(&Z_OBJCE_P(object)->properties_info, Z_STRVAL_P(property), Z_STRLEN_P(property)))) {
				return 1;
			} else {
				return zend_hash_str_exists(
					Z_OBJ_HT_P(object)->get_properties(Z_OBJ_P(object)),
					Z_STRVAL_P(property),
					Z_STRLEN_P(property)
				);
			}
		}
	}

	return 0;
}

/*
 * PHP isset() semantics for object properties: the property exists AND its
 * value is not IS_NULL. Delegates to the object's has_property handler with
 * ZEND_PROPERTY_ISSET (mode 0), which is the same path the engine takes for
 * the ZEND_ISSET_ISEMPTY_PROP_OBJ opcode — this gives correct behaviour for
 * std objects, __isset magic, typed-uninitialized properties, etc.
 * See https://github.com/zephir-lang/zephir/issues/2385.
 */
int zephir_isset_property_value(zval *object, const char *property_name, unsigned int property_length)
{
	zend_string *member;
	int result;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return 0;
	}

	if (!Z_OBJ_HT_P(object)->has_property) {
		return 0;
	}

	member = zend_string_init(property_name, property_length, 0);
	result = Z_OBJ_HT_P(object)->has_property(Z_OBJ_P(object), member, 0, NULL);
	zend_string_release(member);

	return result;
}

int zephir_isset_property_value_zval(zval *object, const zval *property)
{
	if (Z_TYPE_P(object) != IS_OBJECT || Z_TYPE_P(property) != IS_STRING) {
		return 0;
	}

	if (!Z_OBJ_HT_P(object)->has_property) {
		return 0;
	}

	return Z_OBJ_HT_P(object)->has_property(Z_OBJ_P(object), Z_STR_P(property), 0, NULL);
}

int zephir_isset_property_value_fast(zval *object, zend_string *property_name)
{
	if (Z_TYPE_P(object) != IS_OBJECT) {
		return 0;
	}

	if (!Z_OBJ_HT_P(object)->has_property) {
		return 0;
	}

	return Z_OBJ_HT_P(object)->has_property(Z_OBJ_P(object), property_name, 0, NULL);
}

/**
 * Lookup for the real owner of the property
 */
static inline zend_class_entry *zephir_lookup_class_ce(
	zend_class_entry *ce,
	const char *property_name,
	unsigned int property_length
) {
	zend_class_entry *original_ce = ce;
	zend_property_info *info;
	const zend_class_entry *scope;
	zval member;

	ZVAL_STRINGL(&member, property_name, property_length);

	/* Backup current scope */
	scope = zephir_get_scope(0);

	while (ce) {
		/* Use the scope of the current object */
		zephir_set_scope(ce);

		info = zend_get_property_info(ce, Z_STR(member), 1);
		if (info && info != ZEND_WRONG_PROPERTY_INFO) {
			zval_ptr_dtor(&member);
			/* Restore original scope */
			zephir_set_scope(scope);

			return ce;
		}

		ce = ce->parent;
	}

	zval_ptr_dtor(&member);

	/* Restore original scope */
	zephir_set_scope(scope);

	return original_ce;
}

/**
 * Checks whether obj is an object and reads a property from this object.
 *
 * This function is intended to use in initializer.  Do not use it for a
 * regular property updating.
 */
int zephir_read_property_ex(
	zval *result,
	zval *object,
	const char *property_name,
	uint32_t property_length, int flags
) {
	const zend_class_entry *scope;
	int retval;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		zend_class_entry *ce;

		/* Backup current scope */
		scope = zephir_get_scope(0);
		ce = Z_OBJCE_P(object);

		/* Lookup for the real owner of the property */
		if (ce->parent) {
			ce = zephir_lookup_class_ce(ce, property_name, property_length);
		}

		/* Use the scope of the found object */
		zephir_set_scope(ce);
	}
	/* Read the property */
	retval = zephir_read_property(result, object, property_name, property_length, flags);

	if (Z_TYPE_P(object) == IS_OBJECT) {
		/* Restore original scope */
		zephir_set_scope(scope);
	}

	return retval;
}

/**
 * Checks whether obj is an object and reads a property from this object
 */
int zephir_read_property(
	zval *result,
	zval *object,
	const char *property_name,
	uint32_t property_length,
	int flags
) {
	zval property, tmp;
	zval *res;

	ZVAL_UNDEF(&tmp);

	if (Z_TYPE_P(object) != IS_OBJECT) {
		if ((flags & PH_NOISY) == PH_NOISY) {
			php_error_docref(NULL, E_NOTICE, "Trying to get property '%s' of non-object", property_name);
		}

		ZVAL_NULL(result);
		return FAILURE;
	}

	if (!Z_OBJ_HT_P(object)->read_property) {
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be read", property_name, ZSTR_VAL(Z_OBJCE_P(object)->name));
	}

	ZVAL_STRINGL(&property, property_name, property_length);
	res = Z_OBJ_HT_P(object)->read_property(Z_OBJ_P(object), Z_STR(property),
											flags ? BP_VAR_IS : BP_VAR_R,
											NULL, &tmp);

	if ((flags & PH_READONLY) == PH_READONLY) {
		ZVAL_COPY_VALUE(result, res);
	} else {
		ZVAL_COPY(result, res);
	}

	zval_ptr_dtor(&property);

	return SUCCESS;
}

/**
 * Fast object-property read for compile-time-known names.
 *
 * Identical semantics to zephir_read_property(), but the name is a
 * pre-interned zend_string (the codegen emits a method-static slot,
 * skipping the per-call zend_string_init/dtor) and an optional inline
 * cache slot index may be supplied. cache_slot == 0 means "uncached"
 * (a NULL cache_slot is handed to the engine, i.e. today's behavior).
 * See https://github.com/zephir-lang/zephir/issues/1884 (property access).
 */
int zephir_read_property_cached(
	zval *result,
	zval *object,
	zend_string *name,
	zend_ulong cache_slot,
	int flags
) {
	zval tmp;
	zval *res;
	void **slot = NULL;

	/*
	 * Resolve the per-site inline cache slot from the per-request-zeroed
	 * module globals. Index 0 = uncached -> NULL (engine re-resolves every
	 * time, as before). A zeroed slot is a safe miss: the engine's
	 * `ce == slot[0]` check fails against NULL and it fills the slot.
	 */
	if (cache_slot) {
		zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;
		slot = &zephir_globals_ptr->pcache[cache_slot * ZEPHIR_PROPERTY_CACHE_SLOT_SIZE];
	}

	ZVAL_UNDEF(&tmp);

	if (Z_TYPE_P(object) != IS_OBJECT) {
		if ((flags & PH_NOISY) == PH_NOISY) {
			php_error_docref(NULL, E_NOTICE, "Trying to get property '%s' of non-object", ZSTR_VAL(name));
		}

		ZVAL_NULL(result);
		return FAILURE;
	}

	if (!Z_OBJ_HT_P(object)->read_property) {
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be read", ZSTR_VAL(name), ZSTR_VAL(Z_OBJCE_P(object)->name));
	}

	res = Z_OBJ_HT_P(object)->read_property(Z_OBJ_P(object), name,
											flags ? BP_VAR_IS : BP_VAR_R,
											slot, &tmp);

	if ((flags & PH_READONLY) == PH_READONLY) {
		ZVAL_COPY_VALUE(result, res);
	} else {
		ZVAL_COPY(result, res);
	}

	return SUCCESS;
}

/**
 * The property slot a write context writes through.
 *
 * PHP's `ZEND_FETCH_OBJ_W` hands the VM an IS_INDIRECT to the property itself
 * (`zend_fetch_property_address()`, Zend/zend_execute.c). That is what lets a
 * by-reference argument separate a shared array in place, create a missing
 * element, and be replaced outright by a callee that assigns rather than
 * mutates. A borrowed copy of the property loses all three, and the last one
 * frees the array the property is still pointing at.
 *
 * `get_property_ptr_ptr` answers NULL when there is no slot to hand out: a
 * magic __get, a readonly or asymmetrically visible property, or an object
 * whose handlers do not offer one. PHP falls back to read_property() in write
 * mode, and that is what raises "Indirect modification of overloaded property
 * %s::$%s has no effect" (Zend/zend_object_handlers.c), so this does the same
 * and lets the engine speak. The value goes into `fallback`, owned, which the
 * caller has registered with the memory frame, and the write reaches no
 * further than it.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2691
 */
zval *zephir_fetch_property_write(zval *object, zend_string *name, zval *fallback)
{
	zval tmp;
	zval *res;

	ZVAL_NULL(fallback);

	if (UNEXPECTED(Z_TYPE_P(object) != IS_OBJECT)) {
		php_error_docref(NULL, E_NOTICE, "Trying to get property '%s' of non-object", ZSTR_VAL(name));

		return fallback;
	}

	if (EXPECTED(Z_OBJ_HT_P(object)->get_property_ptr_ptr != NULL)) {
		res = Z_OBJ_HT_P(object)->get_property_ptr_ptr(Z_OBJ_P(object), name, BP_VAR_W, NULL);

		if (EXPECTED(res != NULL && res != &EG(error_zval))) {
			return res;
		}
	}

	if (UNEXPECTED(!Z_OBJ_HT_P(object)->read_property)) {
		return fallback;
	}

	ZVAL_UNDEF(&tmp);
	res = Z_OBJ_HT_P(object)->read_property(Z_OBJ_P(object), name, BP_VAR_W, NULL, &tmp);

	/* A getter builds its result in `tmp` and hands over what it owns, while a
	 * real slot stays the object's and has to be addref'd. */
	if (res == &tmp) {
		ZVAL_COPY_VALUE(fallback, res);
	} else {
		ZVAL_COPY(fallback, res);
	}

	return fallback;
}

/**
 * The same for a property named at runtime, `this->{name}`.
 *
 * PHP's `ZEND_FETCH_OBJ_W` takes the same path whether the name came from a
 * literal or from a variable, so this one only has to turn the name into a
 * zend_string and hand over.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2691
 */
zval *zephir_fetch_property_write_zval(zval *object, zval *property, zval *fallback)
{
	if (UNEXPECTED(Z_TYPE_P(property) != IS_STRING)) {
		php_error_docref(NULL, E_NOTICE, "Cannot access empty property %d", Z_TYPE_P(property));

		ZVAL_NULL(fallback);

		return fallback;
	}

	return zephir_fetch_property_write(object, Z_STR_P(property), fallback);
}

/**
 * The same for a static property, `ZEND_FETCH_STATIC_PROP_W`.
 *
 * zend_std_get_static_property() is the slot getter here, and it throws for a
 * property that does not exist rather than answering NULL, so the fallback is
 * only reached when an error is already pending.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2691
 */
zval *zephir_fetch_static_property_write_ce(zend_class_entry *ce, const char *property, uint32_t property_length, zval *fallback)
{
	zend_string *name;
	zval *res;

	ZVAL_NULL(fallback);

	name = zend_string_init(property, property_length, 0);
	res  = zend_std_get_static_property(ce, name, BP_VAR_W);
	zend_string_release(name);

	if (EXPECTED(res != NULL && res != &EG(error_zval))) {
		return res;
	}

	return fallback;
}

/**
 * Fetches a property using a const char
 */
int zephir_fetch_property(zval *result, zval *object, const char *property_name, uint32_t property_length, int silent)
{
	if (zephir_isset_property(object, property_name, property_length)) {
		zephir_read_property(result, object, property_name, property_length, 0);
		return 1;
	}

	ZVAL_NULL(result);
	return 0;
}

/**
 * Fetches a property using a zval property
 */
int zephir_fetch_property_zval(zval *result, zval *object, zval *property, int silent)
{
	if (UNEXPECTED(Z_TYPE_P(property) != IS_STRING)) {
		ZVAL_NULL(result);
		return 0;
	}

	if (zephir_isset_property(object, Z_STRVAL_P(property), Z_STRLEN_P(property))) {
		zephir_read_property(result, object, Z_STRVAL_P(property), Z_STRLEN_P(property), 0);
		return 1;
	}

	ZVAL_NULL(result);
	return 0;
}

int zephir_return_property(zval *return_value, zval *object, char *property_name, unsigned int property_length)
{
	ZVAL_NULL(return_value);
	return zephir_read_property(return_value, object, property_name, property_length, 0);
}

/**
 * Reads a property from an object
 */
int zephir_read_property_zval(zval *result, zval *object, zval *property, int flags)
{
	if (UNEXPECTED(Z_TYPE_P(property) != IS_STRING)) {
		if ((flags & PH_NOISY) == PH_NOISY) {
			php_error_docref(NULL, E_NOTICE, "Cannot access empty property %d", Z_TYPE_P(property));
		}

		ZVAL_NULL(result);
		return FAILURE;
	}

	return zephir_read_property(result, object, Z_STRVAL_P(property), Z_STRLEN_P(property), flags);
}

/**
 * Checks whether obj is an object and updates property with another zval.
 *
 * This function is intended to use in initializer.  Do not use it for a
 * regular property updating.
 */
int zephir_update_property_zval_ex(
	zval *object,
	const char *property_name,
	unsigned int property_length,
	zval *value
) {
	const zend_class_entry *scope;
	int retval;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		zend_class_entry *ce;

		/* Backup current scope */
		scope = zephir_get_scope(0);
		ce = Z_OBJCE_P(object);

		/* Lookup for the real owner of the property */
		if (ce->parent) {
			ce = zephir_lookup_class_ce(ce, property_name, property_length);
		}

		/* Use the scope of the found object */
		zephir_set_scope(ce);
	}
	/* Update the property */
	retval = zephir_update_property_zval(object, property_name, property_length, value);

	if (Z_TYPE_P(object) == IS_OBJECT) {
		/* Restore original scope */
		zephir_set_scope(scope);
	}

	return retval;
}

/**
 * Checks whether obj is an object and updates property with another zval
 */
int zephir_update_property_zval(
	zval *object,
	const char *property_name,
	unsigned int property_length,
	zval *value
) {
	zval property, sep_value;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL, E_WARNING, "Attempt to assign property '%s' of non-object", property_name);
		return FAILURE;
	}

	if (!Z_OBJ_HT_P(object)->write_property) {
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be updated", property_name, ZSTR_VAL(Z_OBJCE_P(object)->name));
	}

	ZVAL_STRINGL(&property, property_name, property_length);
	ZVAL_COPY_VALUE(&sep_value, value);
	if (Z_TYPE(sep_value) == IS_ARRAY) {
		ZVAL_ARR(&sep_value, zend_array_dup(Z_ARR(sep_value)));
		if (EXPECTED(!(GC_FLAGS(Z_ARRVAL(sep_value)) & IS_ARRAY_IMMUTABLE))) {
			if (UNEXPECTED(GC_REFCOUNT(Z_ARR(sep_value)) > 0)) {
				GC_DELREF(Z_ARR(sep_value));
			}
		}
	}

	/* write_property will add 1 to refcount,
	   so no Z_TRY_ADDREF_P(value) is necessary */
	Z_OBJ_HT_P(object)->write_property(Z_OBJ_P(object), Z_STR(property), &sep_value, 0);

	zval_ptr_dtor(&property);

	if (UNEXPECTED(EG(exception))) {
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Fast object-property write for compile-time-known names.
 *
 * Identical semantics to zephir_update_property_zval(), but the name is a
 * pre-interned zend_string and an optional inline cache slot index may be
 * supplied. cache_slot == 0 means "uncached" (NULL cache_slot to the engine).
 * See https://github.com/zephir-lang/zephir/issues/1884 (property access).
 */
int zephir_update_property_zval_cached(
	zval *object,
	zend_string *name,
	zend_ulong cache_slot,
	zval *value
) {
	zval sep_value;
	void **slot = NULL;

	/* See zephir_read_property_cached: resolve the per-request cache slot. */
	if (cache_slot) {
		zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;
		slot = &zephir_globals_ptr->pcache[cache_slot * ZEPHIR_PROPERTY_CACHE_SLOT_SIZE];
	}

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL, E_WARNING, "Attempt to assign property '%s' of non-object", ZSTR_VAL(name));
		return FAILURE;
	}

	if (!Z_OBJ_HT_P(object)->write_property) {
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be updated", ZSTR_VAL(name), ZSTR_VAL(Z_OBJCE_P(object)->name));
	}

	ZVAL_COPY_VALUE(&sep_value, value);
	if (Z_TYPE(sep_value) == IS_ARRAY) {
		ZVAL_ARR(&sep_value, zend_array_dup(Z_ARR(sep_value)));
		if (EXPECTED(!(GC_FLAGS(Z_ARRVAL(sep_value)) & IS_ARRAY_IMMUTABLE))) {
			if (UNEXPECTED(GC_REFCOUNT(Z_ARR(sep_value)) > 0)) {
				GC_DELREF(Z_ARR(sep_value));
			}
		}
	}

	/* write_property will add 1 to refcount,
	   so no Z_TRY_ADDREF_P(value) is necessary */
	Z_OBJ_HT_P(object)->write_property(Z_OBJ_P(object), name, &sep_value, slot);

	if (UNEXPECTED(EG(exception))) {
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Checks whether obj is an object and updates zval property with another zval
 */
int zephir_update_property_zval_zval(zval *object, zval *property, zval *value)
{
	if (Z_TYPE_P(property) != IS_STRING) {
		php_error_docref(NULL, E_WARNING, "Property should be string");
		return FAILURE;
	}

	return zephir_update_property_zval(object, Z_STRVAL_P(property), Z_STRLEN_P(property), value);
}

/**
 * Updates an array property
 */
int zephir_update_property_array(zval *object, const char *property, uint32_t property_length, const zval *index, zval *value)
{
	zval tmp, sep_value;
	int separated = 0;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return SUCCESS;
	}

	zephir_read_property(&tmp, object, property, property_length, PH_NOISY | PH_READONLY);

	/**
	 * If the property holds an object implementing ArrayAccess, delegate the
	 * offset assignment to its offsetSet() method instead of converting the
	 * object into a plain array. See #2465.
	 */
	if (UNEXPECTED(Z_TYPE(tmp) == IS_OBJECT && zephir_instance_of_ev(&tmp, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, &tmp, "offsetset", NULL, 0, (zval *)index, value);
		return ZEPHIR_LAST_CALL_STATUS != FAILURE ? SUCCESS : FAILURE;
	}

	/** Separation only when refcount > 1 */
	if (Z_REFCOUNTED(tmp)) {
		if (Z_REFCOUNT(tmp) > 1) {
			if (!Z_ISREF(tmp)) {
				zval new_zv;
				ZVAL_DUP(&new_zv, &tmp);
				ZVAL_COPY_VALUE(&tmp, &new_zv);
				Z_TRY_DELREF(new_zv);
				Z_ADDREF(tmp);
				separated = 1;
			}
		}
	} else {
		zval new_zv;
		ZVAL_DUP(&new_zv, &tmp);
		ZVAL_COPY_VALUE(&tmp, &new_zv);
		Z_TRY_DELREF(new_zv);
		separated = 1;
	}

	/** Convert the value to array if not is an array */
	if (Z_TYPE(tmp) != IS_ARRAY) {
		if (separated) {
			convert_to_array(&tmp);
		} else {
			array_init(&tmp);
			separated = 1;
		}

		if (Z_REFCOUNTED(tmp)) {
			if (Z_REFCOUNT(tmp) > 1) {
				if (!Z_ISREF(tmp)) {
					Z_DELREF(tmp);
				}
			}
		}
	}

	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZVAL_ARR(&sep_value, zend_array_dup(Z_ARR_P(value)));
	} else {
		ZVAL_COPY(&sep_value, value);
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		zend_symtable_str_update(Z_ARRVAL(tmp), Z_STRVAL_P(index), Z_STRLEN_P(index), &sep_value);
	} else if (Z_TYPE_P(index) == IS_LONG) {
		zend_hash_index_update(Z_ARRVAL(tmp), Z_LVAL_P(index), &sep_value);
	} else if (Z_TYPE_P(index) == IS_NULL) {
		zend_hash_next_index_insert(Z_ARRVAL(tmp), &sep_value);
	}

	if (separated) {
		zephir_update_property_zval(object, property, property_length, &tmp);
		zval_ptr_dtor(&tmp);
	}

	return SUCCESS;
}

/**
 * Appends a zval value to an array property
 */
int zephir_update_property_array_append(zval *object, char *property, unsigned int property_length, zval *value)
{
	zval tmp, sep_value;
	int separated = 0;

	ZVAL_UNDEF(&tmp);

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return SUCCESS;
	}

	zephir_read_property(&tmp, object, property, property_length, PH_NOISY | PH_READONLY);

	/** Separation only when refcount > 1 */
	if (Z_REFCOUNTED(tmp)) {
		if (Z_REFCOUNT(tmp) > 1) {
			if (!Z_ISREF(tmp)) {
				zval new_zv;
				ZVAL_DUP(&new_zv, &tmp);
				ZVAL_COPY_VALUE(&tmp, &new_zv);
				if (Z_REFCOUNT(tmp) > 1) {
				    Z_TRY_DELREF(new_zv);
				}
				separated = 1;
			}
		}
	} else {
		zval new_zv;
		ZVAL_DUP(&new_zv, &tmp);
		ZVAL_COPY_VALUE(&tmp, &new_zv);
		Z_TRY_DELREF(new_zv);
		separated = 1;

		/**
		 * class A {
		 *     protected foo;
		 *
		 *     public function test() {
		 *         let this->foo[] = 42;
		 *     }
		 * }
		 *
		 * In this case: Z_REFCOUNT(tmp) == 0
		 */
		if (Z_REFCOUNTED(tmp)) {
			if (EXPECTED(Z_REFCOUNT(tmp) == 0)) {
				Z_ADDREF(tmp);
			}
		}
	}

	/** Convert the value to array if not is an array */
	if (Z_TYPE(tmp) != IS_ARRAY) {
		if (separated) {
			convert_to_array(&tmp);
		} else {
			array_init(&tmp);
			separated = 1;
		}

		if (Z_REFCOUNTED(tmp)) {
			if (Z_REFCOUNT(tmp) > 1) {
				if (!Z_ISREF(tmp)) {
					Z_DELREF(tmp);
				}
			}
		}
	}

	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZVAL_ARR(&sep_value, zend_array_dup(Z_ARR_P(value)));
	} else {
		ZVAL_COPY(&sep_value, value);
	}

	add_next_index_zval(&tmp, &sep_value);

	if (separated) {
		zephir_update_property_zval(object, property, property_length, &tmp);
		zval_ptr_dtor(&tmp);
	}

	return SUCCESS;
}

/**
 * Multiple array-offset update
 */
int zephir_update_property_array_multi(zval *object, const char *property, uint32_t property_length, zval *value, const char *types, int types_length, int types_count, ...)
{
	va_list ap;
	zval tmp_arr;
	int separated = 0;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		zephir_read_property(&tmp_arr, object, property, property_length, PH_NOISY | PH_READONLY);

		/**
		 * If the property holds an object implementing ArrayAccess, a chained
		 * write (this->prop[a][b] = value) cannot persist. This mirrors native
		 * PHP exactly: the first offset is fetched once via offsetGet(), the
		 * indirect modification of the returned by-value element has no effect,
		 * and an "Indirect modification of overloaded element" notice is raised.
		 * The object is left intact rather than converted into an array. #2465
		 */
		if (UNEXPECTED(Z_TYPE(tmp_arr) == IS_OBJECT && zephir_instance_of_ev(&tmp_arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
			zend_long ZEPHIR_LAST_CALL_STATUS;
			zval offset, fetched;
			/* Class entries are persistent, so this stays valid even if the
			 * offsetGet() call below were to drop the last instance reference. */
			zend_class_entry *ce = Z_OBJCE(tmp_arr);
			ZVAL_UNDEF(&fetched);
			ZVAL_UNDEF(&offset);

			va_start(ap, types_count);
			switch (types[0]) {
				case 's': {
					char *str  = va_arg(ap, char*);
					/* SL() pushes a size_t; see kernel/array.c. */
					size_t len = va_arg(ap, size_t);
					ZVAL_STRINGL(&offset, str, len);
					break;
				}
				case 'l':
					ZVAL_LONG(&offset, va_arg(ap, zend_long));
					break;
				case 'z':
					ZVAL_COPY(&offset, va_arg(ap, zval*));
					break;
				default: /* 'a' (append): the fetched offset is null */
					ZVAL_NULL(&offset);
					break;
			}
			va_end(ap);

			ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(&fetched, &tmp_arr, "offsetget", NULL, 0, &offset);
			zval_ptr_dtor(&fetched);
			zval_ptr_dtor(&offset);

			zend_error(E_NOTICE, "Indirect modification of overloaded element of %s has no effect", ZSTR_VAL(ce->name));

			return SUCCESS;
		}

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNTED(tmp_arr)) {
			if (Z_REFCOUNT(tmp_arr) > 1) {
				if (!Z_ISREF(tmp_arr)) {
					zval new_zv;
					ZVAL_DUP(&new_zv, &tmp_arr);
					ZVAL_COPY_VALUE(&tmp_arr, &new_zv);
					Z_TRY_DELREF(new_zv);
					Z_ADDREF(tmp_arr);
					separated = 1;
				}
			}
		} else {
			zval new_zv;
			ZVAL_DUP(&new_zv, &tmp_arr);
			ZVAL_COPY_VALUE(&tmp_arr, &new_zv);
			Z_TRY_DELREF(new_zv);
			separated = 1;
		}

		/** Convert the value to array if not is an array */
		if (Z_TYPE(tmp_arr) != IS_ARRAY) {
			if (separated) {
				convert_to_array(&tmp_arr);
			} else {
				array_init(&tmp_arr);
				separated = 1;
			}

			if (Z_REFCOUNTED(tmp_arr)) {
				if (Z_REFCOUNT(tmp_arr) > 1) {
					if (!Z_ISREF(tmp_arr)) {
						Z_DELREF(tmp_arr);
					}
				}
			}
		}

		va_start(ap, types_count);
		zephir_array_update_multi_ex(&tmp_arr, value, types, types_length, types_count, ap);
		va_end(ap);

		if (separated) {
			zephir_update_property_zval(object, property, property_length, &tmp_arr);
			zval_ptr_dtor(&tmp_arr);
		}
	}

	return SUCCESS;
}

int zephir_unset_property(zval* object, const char* name)
{
	if (Z_TYPE_P(object) != IS_OBJECT) {
		return FAILURE;
	}

	zval member;
	const zend_class_entry *scope;

	ZVAL_STRING(&member, name);

	/* Backup current scope */
	scope = zephir_get_scope(0);

	/* Use caller's scope */
	zephir_set_scope(Z_OBJCE_P(object));
	Z_OBJ_HT_P(object)->unset_property(Z_OBJ_P(object), Z_STR(member), 0);
	/* Restore original scope */
	zephir_set_scope(scope);

	zval_ptr_dtor(&member);

	return SUCCESS;
}

/**
 * Unsets an object property whose name is given as a zval string.
 * Mirrors zephir_unset_property() but accepts a dynamic zval name,
 * enabling unset(obj->{variable}) compiled via zephir_unset_property_zval().
 */
int zephir_unset_property_zval(zval *object, const zval *name)
{
	const zend_class_entry *scope;

	if (Z_TYPE_P(object) != IS_OBJECT || Z_TYPE_P(name) != IS_STRING) {
		return FAILURE;
	}

	scope = zephir_get_scope(0);
	zephir_set_scope(Z_OBJCE_P(object));
	Z_OBJ_HT_P(object)->unset_property(Z_OBJ_P(object), Z_STR_P(name), 0);
	zephir_set_scope(scope);

	return SUCCESS;
}

/**
 * Unsets an index in an array property
 *
 * TODO: This only works with zephir_read_property() + zephir_array_unset_string(), which might be incorrect
 */
int zephir_unset_property_array(zval *object, char *property, unsigned int property_length, zval *index)
{
	zval tmp;
	int separated = 0;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		zephir_read_property(&tmp, object, property, property_length, PH_NOISY_CC);
		Z_TRY_DELREF(tmp);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNTED(tmp)) {
			if (Z_REFCOUNT(tmp) > 1) {
				if (!Z_ISREF(tmp)) {
					zval new_zv;
					ZVAL_DUP(&new_zv, &tmp);
					ZVAL_COPY_VALUE(&tmp, &new_zv);
					Z_TRY_DELREF(new_zv);
					separated = 1;
				}
			}
		} else {
			zval new_zv;
			ZVAL_DUP(&new_zv, &tmp);
			ZVAL_COPY_VALUE(&tmp, &new_zv);
			Z_TRY_DELREF(new_zv);
			separated = 1;
		}

		zephir_array_unset(&tmp, index, PH_SEPARATE);

		if (separated) {
			zephir_update_property_zval(object, property, property_length, &tmp);
		}
	}

	return SUCCESS;
}

int zephir_method_exists_ex(zval *object, const char *method_name, unsigned int method_len)
{
	zend_class_entry *ce;
	union _zend_function *func = NULL;
	zend_string *method;

	if (EXPECTED(Z_TYPE_P(object) == IS_OBJECT)) {
		ce = Z_OBJCE_P(object);
	} else if (Z_TYPE_P(object) == IS_STRING) {
		ce = zend_fetch_class(Z_STR_P(object), ZEND_FETCH_CLASS_DEFAULT);
	} else {
		return FAILURE;
	}

	if (zend_hash_str_exists(&ce->function_table, method_name, method_len)) {
		return SUCCESS;
	}

	method = zend_string_init(method_name, method_len, 0);
	if (
		   Z_TYPE_P(object) == IS_OBJECT
		&& Z_OBJ_HT_P(object)->get_method
		&& (func = Z_OBJ_HT_P(object)->get_method(&Z_OBJ_P(object), method, NULL))
	) {
		if (func->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE) {
			int status = (func->common.scope == zend_ce_closure && zend_string_equals_literal(method, ZEND_INVOKE_FUNC_NAME));

			zend_string_release(method);
			zend_string_release(func->common.function_name);
			zend_free_trampoline(func);
			return status ? SUCCESS : FAILURE;
		}

		zend_string_release(method);
		return SUCCESS;
	}

	zend_string_release(method);
	return FAILURE;
}

int zephir_method_exists(zval *object, const zval *method_name)
{
	if (Z_TYPE_P(method_name) != IS_STRING) {
		zend_error(E_WARNING, "method_exists expected a string");
		return 0;
	}

	char *lcname = zend_str_tolower_dup(Z_STRVAL_P(method_name), Z_STRLEN_P(method_name));
	int res = zephir_method_exists_ex(object, lcname, Z_STRLEN_P(method_name));
	efree(lcname);

	return res;
}

int zephir_read_static_property_ce(zval *result, zend_class_entry *ce, const char *property, int len, int flags)
{
	zval *tmp = zend_read_static_property(ce, property, len, (zend_bool) ZEND_FETCH_CLASS_SILENT);

	ZVAL_NULL(result);
	if (tmp) {
		if ((flags & PH_READONLY) == PH_READONLY) {
			ZVAL_COPY_VALUE(result, tmp);
		} else {
			ZVAL_COPY(result, tmp);
		}

		return SUCCESS;
	}

	return FAILURE;
}

/**
 * TODO: Use directly zend_update_static_property()
 */
int zephir_update_static_property_ce(zend_class_entry *ce, const char *property_name, uint32_t property_length, zval *value)
{
	return zend_update_static_property(ce, property_name, property_length, value);
}

int zephir_add_static_property_ce(zend_class_entry *ce, const char *property_name, uint32_t property_length, zval *value)
{
	zval tmp_value, new_value;
	zephir_read_static_property_ce(&tmp_value, ce, property_name, property_length, PH_NOISY | PH_READONLY);
	zephir_add_function(&new_value, &tmp_value, value);
	return zend_update_static_property(ce, property_name, property_length, &new_value);
}

int zephir_sub_static_property_ce(zend_class_entry *ce, const char *property_name, uint32_t property_length, zval *value)
{
	zval tmp_value, new_value;
	zephir_read_static_property_ce(&tmp_value, ce, property_name, property_length, PH_NOISY | PH_READONLY);
	zephir_sub_function(&new_value, &tmp_value, value);
	return zend_update_static_property(ce, property_name, property_length, &new_value);
}

/*
 * Multiple array-offset update
 */
int zephir_update_static_property_array_multi_ce(
	zend_class_entry *ce,
	const char *property,
	uint32_t property_length,
	zval *value,
	const char *types,
	int types_length,
	int types_count,
	...
) {
	va_list ap;
	zval tmp_arr;
	int separated = 0;

	ZVAL_UNDEF(&tmp_arr);

	zephir_read_static_property_ce(&tmp_arr, ce, property, property_length, PH_NOISY | PH_READONLY);

	/** Separation only when refcount > 1 */
	if (Z_REFCOUNTED(tmp_arr)) {
		if (Z_REFCOUNT(tmp_arr) > 1) {
			if (!Z_ISREF(tmp_arr)) {
				zval new_zv;
				ZVAL_DUP(&new_zv, &tmp_arr);
				ZVAL_COPY_VALUE(&tmp_arr, &new_zv);
				Z_TRY_DELREF(new_zv);
				Z_ADDREF(tmp_arr);
				separated = 1;
			}
		}
	} else {
		zval new_zv;
		ZVAL_DUP(&new_zv, &tmp_arr);
		ZVAL_COPY_VALUE(&tmp_arr, &new_zv);
		Z_TRY_DELREF(new_zv);
		separated = 1;
	}

	/** Convert the value to array if not is an array */
	if (Z_TYPE(tmp_arr) != IS_ARRAY) {
		if (separated) {
			convert_to_array(&tmp_arr);
		} else {
			array_init(&tmp_arr);
			separated = 1;
		}

		if (Z_REFCOUNTED(tmp_arr)) {
			if (Z_REFCOUNT(tmp_arr) > 1) {
				if (!Z_ISREF(tmp_arr)) {
					Z_DELREF(tmp_arr);
				}
			}
		}
	}

	va_start(ap, types_count);
	SEPARATE_ZVAL_NOREF(&tmp_arr);
	zephir_array_update_multi_ex(&tmp_arr, value, types, types_length, types_count, ap);
	va_end(ap);

	if (separated) {
		zend_update_static_property(ce, property, property_length, &tmp_arr);
	}

	if (Z_REFCOUNTED(tmp_arr)) {
		if (Z_REFCOUNT(tmp_arr) > 1) {
			if (!Z_ISREF(tmp_arr)) {
				Z_DELREF(tmp_arr);
			}
		}
	}

	return SUCCESS;
}

/**
 * Increments an object property
 */
int zephir_property_incr_decr(zval *object, char *property_name, unsigned int property_length, unsigned int increment)
{
	zval tmp;
	zend_class_entry *ce;
	int separated = 0;

	ZVAL_UNDEF(&tmp);

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = zephir_lookup_class_ce(ce, property_name, property_length);
	}

	zephir_read_property(&tmp, object, property_name, property_length, 0);
	if (Z_TYPE(tmp) > IS_UNDEF) {
		Z_TRY_DELREF(tmp);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNTED(tmp)) {
			if (Z_REFCOUNT(tmp) > 1) {
				if (!Z_ISREF(tmp)) {
					zval new_zv;
					ZVAL_DUP(&new_zv, &tmp);
					ZVAL_COPY_VALUE(&tmp, &new_zv);
					Z_TRY_DELREF(new_zv);
					separated = 1;
				}
			}
		} else {
			zval new_zv;
			ZVAL_DUP(&new_zv, &tmp);
			ZVAL_COPY_VALUE(&tmp, &new_zv);
			Z_TRY_DELREF(new_zv);
			separated = 1;
		}

		if (increment) {
			zephir_increment(&tmp);
		} else {
			zephir_decrement(&tmp);
		}

		if (separated) {
			zephir_update_property_zval(object, property_name, property_length, &tmp);
		}
	}

	return SUCCESS;
}

/**
 * Writes a PHP reference into a declared property without dereferencing it.
 *
 * write_property() assigns *through* a reference, which is the opposite of
 * what a by-reference closure capture needs: the carrier has to hold the
 * reference itself, so that the closure and the enclosing scope keep sharing
 * one storage slot.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2652
 */
int zephir_update_property_reference(zval *object, const char *property_name, uint32_t property_length, zval *value)
{
	zend_string *property;
	zval *slot;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL, E_WARNING, "Attempt to assign property '%s' of non-object", property_name);
		return FAILURE;
	}

	property = zend_string_init(property_name, property_length, 0);
	slot     = zend_std_get_property_ptr_ptr(Z_OBJ_P(object), property, BP_VAR_W, NULL);
	zend_string_release(property);

	if (slot == NULL) {
		return FAILURE;
	}

	zval_ptr_dtor(slot);
	ZVAL_COPY(slot, value);

	return SUCCESS;
}

/**
 * Turns a local into a PHP reference holding NULL.
 *
 * NULL rather than UNDEF on purpose: ZEPHIR_CPY_WRT() observes its
 * destination when it is UNDEF, which would register the reference's inner
 * slot with the memory frame and free it twice.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2652
 */
void zephir_make_local_reference(zval *var)
{
	zval value;

	ZVAL_NULL(&value);
	ZVAL_NEW_REF(var, &value);
}

/**
 * -------------------------------------------------------------------------
 * Rebinding a closure that owns a capture carrier
 * -------------------------------------------------------------------------
 *
 * The engine gives an internal-function closure exactly one owned per-instance
 * slot, its bound `$this`, and a capturing closure spends it on the capture
 * carrier. `bindTo()`, `Closure::bind()` and `Closure::call()` each rebuild the
 * closure around a different `$this`, which drops the carrier: the captures
 * read back as NULL and the generated prologue then reads a property off a
 * NULL `this_ptr`.
 *
 * There is no second slot to move the captures into, so the three rebinding
 * entry points are wrapped instead. Each one delegates to the engine's own
 * handler, so scope resolution, validation and the version-specific
 * diagnostics stay PHP's, and then re-points the closure the engine produced
 * at a copy of the carrier.
 *
 * Zephir closures are tagged by giving them a private copy of Closure's object
 * handler table; pointer identity of that table is the marker. A closure that
 * is not ours reaches the saved original handler untouched.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2667
 */
#if PHP_VERSION_ID < 80600

/** Carries the enclosing `$this` on a carrier whose body reads it. */
#define ZEPHIR_CLOSURE_BOUND_THIS "__$zephir_this"

/** Tag for closures that own a capture carrier; rebinding one copies it. */
static zend_object_handlers zephir_closure_carrier_handlers;
/** Tag for closures without captures, so var_dump() has somewhere to land. */
static zend_object_handlers zephir_closure_plain_handlers;
static int zephir_closure_handlers_ready = 0;

static zend_object *(*zephir_closure_std_clone)(zend_object *object) = NULL;

static zend_function *zephir_closure_bind_to_fn = NULL;

static zif_handler zephir_closure_std_bind_to = NULL;
static zif_handler zephir_closure_std_bind    = NULL;
static zif_handler zephir_closure_std_call    = NULL;

static int zephir_closure_is_ours(zval *closure)
{
	return closure != NULL
		&& Z_TYPE_P(closure) == IS_OBJECT
		&& (Z_OBJ_HT_P(closure) == &zephir_closure_carrier_handlers
			|| Z_OBJ_HT_P(closure) == &zephir_closure_plain_handlers);
}

static int zephir_closure_has_carrier(zval *closure)
{
	return closure != NULL
		&& Z_TYPE_P(closure) == IS_OBJECT
		&& Z_OBJ_HT_P(closure) == &zephir_closure_carrier_handlers;
}

/**
 * Rebinding a closure without captures needs no carrier, but the closure the
 * engine returns is a fresh object carrying the engine's own handlers, so it
 * has to be re-tagged or var_dump() of it would crash again.
 */
static void zephir_closure_delegate_plain(zval *rebound)
{
	if (!EG(exception) && Z_TYPE_P(rebound) == IS_OBJECT) {
		Z_OBJ_P(rebound)->handlers = &zephir_closure_plain_handlers;
	}
}

/**
 * A clone keeps whichever tag its source carried, so `clone $closure` followed
 * by a rebind still finds the carrier.
 */
static zend_object *zephir_closure_clone_obj(zend_object *object)
{
	const zend_object_handlers *handlers = object->handlers;
	zend_object *clone = zephir_closure_std_clone(object);

	if (clone != NULL) {
		clone->handlers = handlers;
	}

	return clone;
}

/**
 * zend_closure_get_debug_info() reads func.op_array.filename with no
 * ZEND_USER_FUNCTION guard, and that field lies past the end of a
 * zend_internal_function, so var_dump() of any closure compiled by Zephir used
 * to hand zend_string_addref() a NULL pointer. Report the shape an internal
 * closure actually has: its name, its captures, and the object its body sees
 * as `$this` rather than the carrier holding it.
 */
static HashTable *zephir_closure_get_debug_info(zend_object *object, int *is_temp)
{
	const zend_function *func;
	zend_object *carrier = NULL;
	zend_string *name;
	zend_property_info *info;
	zval closure_zv, captures, value;
	zval *bound;
	HashTable *debug_info;

	*is_temp   = 1;
	debug_info = zend_new_array(4);
	func       = zend_get_closure_method_def(object);

	ZVAL_STR_COPY(&value, func->common.function_name);
	zend_hash_str_update(debug_info, ZEND_STRL("name"), &value);

	ZVAL_OBJ(&closure_zv, object);
	bound = zend_get_closure_this_ptr(&closure_zv);

	if (bound != NULL && Z_TYPE_P(bound) == IS_OBJECT) {
		if (object->handlers == &zephir_closure_carrier_handlers) {
			carrier = Z_OBJ_P(bound);
		} else {
			ZVAL_COPY(&value, bound);
			zend_hash_str_update(debug_info, ZEND_STRL("this"), &value);
		}
	}

	if (carrier == NULL) {
		return debug_info;
	}

	array_init(&captures);

	ZEND_HASH_FOREACH_STR_KEY_PTR(&carrier->ce->properties_info, name, info) {
		zval *slot = OBJ_PROP(carrier, info->offset);

		if (name == NULL || Z_TYPE_P(slot) == IS_UNDEF) {
			continue;
		}

		if (zend_string_equals_literal(name, ZEPHIR_CLOSURE_BOUND_THIS)) {
			if (Z_TYPE_P(slot) == IS_OBJECT) {
				ZVAL_COPY(&value, slot);
				zend_hash_str_update(debug_info, ZEND_STRL("this"), &value);
			}

			continue;
		}

		ZVAL_COPY(&value, Z_ISREF_P(slot) ? Z_REFVAL_P(slot) : slot);
		zend_hash_update(Z_ARRVAL(captures), name, &value);
	} ZEND_HASH_FOREACH_END();

	if (zend_hash_num_elements(Z_ARRVAL(captures)) > 0) {
		zend_hash_str_update(debug_info, ZEND_STRL("static"), &captures);
	} else {
		zval_ptr_dtor(&captures);
	}

	return debug_info;
}

/**
 * Copies a capture carrier for a closure that is about to be rebound, and
 * points the copy's enclosing `$this` at the new object.
 */
static zend_object *zephir_closure_copy_carrier(zend_object *carrier, zval *new_this)
{
	zval carrier_zv, bound;
	zend_object *copy;
	uint32_t i;

	object_init_ex(&carrier_zv, carrier->ce);
	copy = Z_OBJ(carrier_zv);

	for (i = 0; i < (uint32_t) carrier->ce->default_properties_count; i++) {
		zval *source = &carrier->properties_table[i];
		zval *target = &copy->properties_table[i];

		if (Z_TYPE_P(source) == IS_UNDEF) {
			continue;
		}

		zval_ptr_dtor(target);

		/**
		 * The rule zend_array_dup_value() applies to a user closure's
		 * `use (...)` slots on a rebind: a reference nobody else holds is
		 * split off into a private copy, one that is still shared stays
		 * shared. Matching it is what makes `use (&x)` behave the same in a
		 * rebound Zephir closure as in a rebound PHP one.
		 *
		 * PHP dereferences the slot outright, which cannot be done here: the
		 * generated body reads a by-reference capture through Z_REFVAL_P()
		 * unconditionally, so the copy has to stay a reference. A brand new
		 * one nobody else holds is indistinguishable from a plain value.
		 */
		if (Z_ISREF_P(source) && Z_REFCOUNT_P(source) == 1) {
			zval inner;

			ZVAL_COPY(&inner, Z_REFVAL_P(source));
			ZVAL_NEW_REF(target, &inner);
		} else {
			ZVAL_COPY(target, source);
		}
	}

	if (zend_hash_str_exists(&carrier->ce->properties_info, ZEND_STRL(ZEPHIR_CLOSURE_BOUND_THIS))) {
		if (new_this != NULL && Z_TYPE_P(new_this) == IS_OBJECT) {
			ZVAL_COPY_VALUE(&bound, new_this);
		} else {
			ZVAL_NULL(&bound);
		}

		zephir_update_property_zval(&carrier_zv, ZEND_STRL(ZEPHIR_CLOSURE_BOUND_THIS), &bound);
	}

	return copy;
}

/**
 * Re-points a closure the engine has just built at a copy of `source`'s
 * carrier, so it keeps the captures the rebind would otherwise have dropped.
 */
static void zephir_closure_adopt_carrier(zval *rebound, zval *source, zval *new_this)
{
	zval *bound = zend_get_closure_this_ptr(source);
	zval *slot;

	if (bound == NULL || Z_TYPE_P(bound) != IS_OBJECT) {
		return;
	}

	slot = zend_get_closure_this_ptr(rebound);

	if (slot == NULL) {
		return;
	}

	/* Releases the `$this` the engine bound; safe on the IS_UNDEF an unbind leaves. */
	zval_ptr_dtor(slot);
	ZVAL_OBJ(slot, zephir_closure_copy_carrier(Z_OBJ_P(bound), new_this));

	Z_OBJ_P(rebound)->handlers = &zephir_closure_carrier_handlers;
}

/**
 * PHP refuses to unbind `$this` from a closure whose body reads it, but it
 * gates that on ZEND_ACC_USES_THIS, a flag its compiler only ever sets on a
 * user function. An internal-function closure can never carry it, so the check
 * has to be made here. The carrier declaring ZEPHIR_CLOSURE_BOUND_THIS is
 * exactly the compiler's record that the body reads `this`.
 */
static int zephir_closure_refuse_unbind(zval *closure, zval *new_this)
{
	zval *bound;

	if (new_this != NULL && Z_TYPE_P(new_this) == IS_OBJECT) {
		return 0;
	}

	bound = zend_get_closure_this_ptr(closure);

	if (bound == NULL
		|| Z_TYPE_P(bound) != IS_OBJECT
		|| !zend_hash_str_exists(&Z_OBJCE_P(bound)->properties_info, ZEND_STRL(ZEPHIR_CLOSURE_BOUND_THIS))) {
		return 0;
	}

#if PHP_VERSION_ID >= 80500
	zend_error(E_WARNING, "Cannot unbind $this of closure using $this, this will be an error in PHP 9");
#else
	zend_error(E_WARNING, "Cannot unbind $this of closure using $this");
#endif

	return 1;
}

static ZEND_NAMED_FUNCTION(zephir_closure_bind_to)
{
	zval *closure  = getThis();
	zval *new_this = NULL;

	if (!zephir_closure_has_carrier(closure)) {
		zephir_closure_std_bind_to(INTERNAL_FUNCTION_PARAM_PASSTHRU);

		if (zephir_closure_is_ours(closure)) {
			zephir_closure_delegate_plain(return_value);
		}

		return;
	}

	/**
	 * Read the argument off the frame rather than parsing it: the delegated
	 * handler parses the same frame, and parsing here as well would report a
	 * bad argument twice.
	 */
	if (ZEND_NUM_ARGS() >= 1) {
		new_this = ZEND_CALL_ARG(execute_data, 1);

		if (zephir_closure_refuse_unbind(closure, new_this)) {
			RETURN_NULL();
		}
	}

	zephir_closure_std_bind_to(INTERNAL_FUNCTION_PARAM_PASSTHRU);

	if (EG(exception) || Z_TYPE_P(return_value) != IS_OBJECT) {
		return;
	}

	zephir_closure_adopt_carrier(return_value, closure, new_this);
}

static ZEND_NAMED_FUNCTION(zephir_closure_bind)
{
	zval *closure  = ZEND_NUM_ARGS() >= 1 ? ZEND_CALL_ARG(execute_data, 1) : NULL;
	zval *new_this = NULL;

	if (!zephir_closure_has_carrier(closure)) {
		zephir_closure_std_bind(INTERNAL_FUNCTION_PARAM_PASSTHRU);

		if (zephir_closure_is_ours(closure)) {
			zephir_closure_delegate_plain(return_value);
		}

		return;
	}

	if (ZEND_NUM_ARGS() >= 2) {
		new_this = ZEND_CALL_ARG(execute_data, 2);

		if (zephir_closure_refuse_unbind(closure, new_this)) {
			RETURN_NULL();
		}
	}

	zephir_closure_std_bind(INTERNAL_FUNCTION_PARAM_PASSTHRU);

	if (EG(exception) || Z_TYPE_P(return_value) != IS_OBJECT) {
		return;
	}

	zephir_closure_adopt_carrier(return_value, closure, new_this);
}

static ZEND_NAMED_FUNCTION(zephir_closure_call)
{
	zval *closure  = getThis();
	zval *new_this;
	zval rebound, retval;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	char *error = NULL;

	if (!zephir_closure_has_carrier(closure)
		|| zephir_closure_bind_to_fn == NULL
		|| ZEND_NUM_ARGS() < 1
		|| Z_TYPE_P(ZEND_CALL_ARG(execute_data, 1)) != IS_OBJECT) {
		zephir_closure_std_call(INTERNAL_FUNCTION_PARAM_PASSTHRU);
		return;
	}

	new_this = ZEND_CALL_ARG(execute_data, 1);

	/**
	 * Closure::call() builds no lasting closure of its own: it copies the
	 * function onto the stack, delivers `$this` out of band and restores the
	 * unwrapped internal handler, so there is nothing to re-point afterwards.
	 * It binds the new object as both `$this` and the scope, which is what
	 * bindTo($object, $object) does, so route it through there to get the
	 * identical validation and diagnostics and then invoke the result.
	 */
	ZVAL_UNDEF(&rebound);
	zend_call_known_instance_method_with_2_params(
		zephir_closure_bind_to_fn,
		Z_OBJ_P(closure),
		&rebound,
		new_this,
		new_this
	);

	if (EG(exception) || Z_TYPE(rebound) != IS_OBJECT) {
		zval_ptr_dtor(&rebound);
		RETURN_NULL();
	}

	ZVAL_UNDEF(&retval);

	if (zend_fcall_info_init(&rebound, 0, &fci, &fci_cache, NULL, &error) == SUCCESS) {
		fci.retval       = &retval;
		fci.param_count  = ZEND_NUM_ARGS() - 1;
		fci.params       = fci.param_count > 0 ? ZEND_CALL_ARG(execute_data, 2) : NULL;
		fci.named_params = (ZEND_CALL_INFO(execute_data) & ZEND_CALL_HAS_EXTRA_NAMED_PARAMS)
			? EX(extra_named_params)
			: NULL;

		zend_call_function(&fci, &fci_cache);
	}

	if (error != NULL) {
		efree(error);
	}

	zval_ptr_dtor(&rebound);

	if (Z_TYPE(retval) != IS_UNDEF) {
		if (Z_ISREF(retval)) {
			zend_unwrap_reference(&retval);
		}

		ZVAL_COPY_VALUE(return_value, &retval);
	}
}

static zif_handler zephir_closure_install(const char *name, size_t name_length, zif_handler handler, zend_function **function)
{
	zend_function *entry = zend_hash_str_find_ptr(&zend_ce_closure->function_table, name, name_length);
	zif_handler previous;

	if (entry == NULL || entry->type != ZEND_INTERNAL_FUNCTION) {
		return NULL;
	}

	previous = entry->internal_function.handler;
	entry->internal_function.handler = handler;

	if (function != NULL) {
		*function = entry;
	}

	return previous;
}

static void zephir_closure_restore(const char *name, size_t name_length, zif_handler ours, zif_handler previous)
{
	zend_function *entry;

	if (previous == NULL) {
		return;
	}

	entry = zend_hash_str_find_ptr(&zend_ce_closure->function_table, name, name_length);

	/* Only when nobody wrapped us in turn, so two Zephir extensions unload safely. */
	if (entry != NULL && entry->type == ZEND_INTERNAL_FUNCTION && entry->internal_function.handler == ours) {
		entry->internal_function.handler = previous;
	}
}

/**
 * Tags a freshly created closure, snapshotting Closure's handler table the
 * first time round.
 *
 * The snapshot cannot be taken at MINIT: the table is file-static in the
 * engine, ce->default_object_handlers only exists from PHP 8.3, and a closure
 * cannot be built before init_executor() has set up the object store. Threads
 * racing here write identical bytes.
 */
static void zephir_closure_tag(zval *closure, int has_carrier)
{
	zend_object *object = Z_OBJ_P(closure);

	if (!zephir_closure_handlers_ready) {
		memcpy(&zephir_closure_carrier_handlers, object->handlers, sizeof(zend_object_handlers));

		zephir_closure_std_clone = zephir_closure_carrier_handlers.clone_obj;

		zephir_closure_carrier_handlers.clone_obj      = zephir_closure_clone_obj;
		zephir_closure_carrier_handlers.get_debug_info = zephir_closure_get_debug_info;

		memcpy(&zephir_closure_plain_handlers, &zephir_closure_carrier_handlers, sizeof(zend_object_handlers));

		zephir_closure_handlers_ready = 1;
	}

	object->handlers = has_carrier
		? &zephir_closure_carrier_handlers
		: &zephir_closure_plain_handlers;
}

void zephir_closure_module_init(void)
{
	zephir_closure_std_bind_to = zephir_closure_install(ZEND_STRL("bindto"), zephir_closure_bind_to, &zephir_closure_bind_to_fn);
	zephir_closure_std_bind    = zephir_closure_install(ZEND_STRL("bind"), zephir_closure_bind, NULL);
	zephir_closure_std_call    = zephir_closure_install(ZEND_STRL("call"), zephir_closure_call, NULL);
}

void zephir_closure_module_shutdown(void)
{
	zephir_closure_restore(ZEND_STRL("bindto"), zephir_closure_bind_to, zephir_closure_std_bind_to);
	zephir_closure_restore(ZEND_STRL("bind"), zephir_closure_bind, zephir_closure_std_bind);
	zephir_closure_restore(ZEND_STRL("call"), zephir_closure_call, zephir_closure_std_call);

	zephir_closure_std_bind_to = NULL;
	zephir_closure_std_bind    = NULL;
	zephir_closure_std_call    = NULL;
	zephir_closure_bind_to_fn  = NULL;
}

#else

void zephir_closure_module_init(void) {}
void zephir_closure_module_shutdown(void) {}

#endif /* PHP_VERSION_ID < 80600 */

/**
 * Creates a closure bound to `bound_this`, scoped by `scope_this`.
 *
 * A closure with `use (...)` captures binds a per-creation capture carrier as
 * its `$this`, because that is the only per-instance slot the engine gives an
 * internal-function closure. The scope has to keep coming from the enclosing
 * object, or the body would lose access to its protected/private members.
 * The two are the same object for every other closure.
 *
 * `has_carrier` says which of the two it is. It is passed explicitly rather
 * than inferred from the two arguments being different, because rebinding
 * depends on it: only a carrier has to be copied across to the new closure.
 */
static int zephir_create_closure_impl(zval *return_value, zval *bound_this, zval *scope_this, zend_class_entry *ce, const char *method_name, uint32_t method_length, int has_carrier)
{
	zend_function *function_ptr;
	zend_class_entry *scope_ce;

	if ((function_ptr = zend_hash_str_find_ptr(&ce->function_table, method_name, method_length)) == NULL) {
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	/**
	 * When an enclosing object is provided, use its class as the scope so the
	 * closure can access protected/private members of that object.
	 */
	scope_ce = (scope_this && Z_TYPE_P(scope_this) == IS_OBJECT) ? Z_OBJCE_P(scope_this) : ce;

	/**
	 * The engine wraps an internal function's handler with
	 * zend_closure_internal_handler(), whose only job is to release the
	 * reference every call path takes on the closure object
	 * (zend_call_function() does it unconditionally for ZEND_ACC_CLOSURE, and
	 * the internal-call teardown releases nothing else). Restoring
	 * orig_internal_handler here used to bypass that release, so each
	 * invocation leaked one reference and the closure - with everything it
	 * held - was never freed.
	 */
	zend_create_closure(return_value, function_ptr, scope_ce, scope_ce, bound_this);

#if PHP_VERSION_ID < 80600
	/* Marks the closure as ours, so a rebind can find its carrier. */
	zephir_closure_tag(return_value, has_carrier);
#endif

	return SUCCESS;
}

/**
 * Creates a closure bound to a per-creation capture carrier.
 */
int zephir_create_closure_bound(zval *return_value, zval *bound_this, zval *scope_this, zend_class_entry *ce, const char *method_name, uint32_t method_length)
{
	return zephir_create_closure_impl(return_value, bound_this, scope_this, ce, method_name, method_length, 1);
}

/**
 * Creates a closure whose bound object doubles as its scope.
 */
int zephir_create_closure_ex(zval *return_value, zval *this_ptr, zend_class_entry *ce, const char *method_name, uint32_t method_length)
{
	return zephir_create_closure_impl(return_value, this_ptr, this_ptr, ce, method_name, method_length, 0);
}

/**
 * Copied from php-src source tree for PHP 8.4
 */
#if PHP_VERSION_ID < 80400
static zend_result object_init_with_constructor(zval *arg, zend_class_entry *class_type, uint32_t param_count, zval *params, HashTable *named_params)
{
	zend_result status = object_and_properties_init(arg, class_type, NULL);
	if (UNEXPECTED(status == FAILURE)) {
		ZVAL_UNDEF(arg);
		return FAILURE;
	}
	zend_object *obj = Z_OBJ_P(arg);
	zend_function *constructor = obj->handlers->get_constructor(obj);
	if (constructor == NULL) {
		/* The constructor can be NULL for 2 different reasons:
		 * - It is not defined
		 * - We are not allowed to call the constructor (e.g. private, or internal opaque class)
		 *   and an exception has been thrown
		 * in the former case, we are (mostly) done and the object is initialized,
		 * in the latter we need to destroy the object as initialization failed
		 */
		if (UNEXPECTED(EG(exception))) {
			zval_ptr_dtor(arg);
			ZVAL_UNDEF(arg);
			return FAILURE;
		}

		/* Surprisingly, this is the only case where internal classes will allow to pass extra arguments
		 * However, if there are named arguments (and it is not empty),
		 * an Error must be thrown to be consistent with new ClassName() */
		if (UNEXPECTED(named_params != NULL && zend_hash_num_elements(named_params) != 0)) {
			/* Throw standard Error */
			zend_string *arg_name = NULL;
			zend_hash_get_current_key(named_params, &arg_name, /* num_index */ NULL);
			ZEND_ASSERT(arg_name != NULL);
			zend_throw_error(NULL, "Unknown named parameter $%s", ZSTR_VAL(arg_name));
			/* Do not call destructor, free object, and set arg to IS_UNDEF */
			zend_object_store_ctor_failed(obj);
			zval_ptr_dtor(arg);
			ZVAL_UNDEF(arg);
			return FAILURE;
		} else {
			return SUCCESS;
		}
	}
	/* A constructor should not return a value, however if an exception is thrown
	 * zend_call_known_function() will set the retval to IS_UNDEF */
	zval retval;
	zend_call_known_function(
		constructor,
		obj,
		class_type,
		&retval,
		param_count,
		params,
		named_params
	);
	if (Z_TYPE(retval) == IS_UNDEF) {
		/* Do not call destructor, free object, and set arg to IS_UNDEF */
		zend_object_store_ctor_failed(obj);
		zval_ptr_dtor(arg);
		ZVAL_UNDEF(arg);
		return FAILURE;
	} else {
		/* Unlikely, but user constructors may return any value they want */
		zval_ptr_dtor(&retval);
		return SUCCESS;
	}
}
#endif

/**
 * Creates a new instance dynamically. Call constructor without parameters
 */
int zephir_create_instance(zval *return_value, const zval *class_name)
{
	zend_class_entry *ce;

	if (Z_TYPE_P(class_name) != IS_STRING) {
		zephir_throw_exception_string(spl_ce_RuntimeException, SL("Invalid class name"));
		return FAILURE;
	}

	ce = zend_fetch_class(Z_STR_P(class_name), ZEND_FETCH_CLASS_DEFAULT);
	if (!ce) {
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	return object_init_with_constructor(return_value, ce, 0, NULL, NULL);
}

/**
 * Creates a new instance dynamically calling constructor with parameters
 */
int zephir_create_instance_params(zval *return_value, const zval *class_name, zval *params)
{
	zend_class_entry *ce;

	if (Z_TYPE_P(class_name) != IS_STRING) {
		zephir_throw_exception_string(spl_ce_RuntimeException, SL("Invalid class name"));
		return FAILURE;
	}

	if (Z_TYPE_P(params) != IS_ARRAY) {
		zephir_throw_exception_string(spl_ce_RuntimeException, SL("Instantiation parameters must be an array"));
		return FAILURE;
	}

	ce = zend_fetch_class(Z_STR_P(class_name), ZEND_FETCH_CLASS_AUTO);
	if (!ce) {
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	return object_init_with_constructor(return_value, ce, 0, NULL, Z_ARRVAL_P(params));
}
