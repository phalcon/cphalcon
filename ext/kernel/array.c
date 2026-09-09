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
#include <ext/standard/php_array.h>
#include <Zend/zend_hash.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/debug.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/backtrace.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"

/**
 * Prepares a container the write context is about to write through.
 *
 * PHP's `zend_fetch_dimension_address()` (Zend/zend_execute.c): a reference is
 * followed, an undefined, null or false container becomes an array, and the
 * table is separated *before* anything is looked up inside it, so the write
 * reaches the container however many holders it had.
 *
 * SEPARATE_ARRAY() ends in GC_TRY_DELREF(), so it may only run on a zval that
 * owns its value. That is the emitter's half of the bargain: a write context is
 * never handed a borrowed container, only a local variable or an object's
 * property slot, and separating one of those writes the new table back where
 * its owner will find it.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2691
 */
static zval *zephir_array_write_container(zval *arr)
{
	ZVAL_DEREF(arr);

	if (UNEXPECTED(Z_TYPE_P(arr) <= IS_FALSE)) {
#if PHP_VERSION_ID >= 80100
		const zend_bool was_false = Z_TYPE_P(arr) == IS_FALSE;
#endif

		array_init(arr);

#if PHP_VERSION_ID >= 80100
		/* Deprecated since 8.1, same wording through 8.5. */
		if (UNEXPECTED(was_false)) {
			zend_error(E_DEPRECATED, "Automatic conversion of false to array is deprecated");
		}
#endif

		return arr;
	}

	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		SEPARATE_ARRAY(arr);
	}

	return arr;
}

/**
 * Creates the element a write context asked for and hands back its slot.
 *
 * A write context is a lookup-or-create: BP_VAR_W reaches `zend_hash_lookup()`
 * in `zend_fetch_dimension_address_inner()`, which inserts a null and returns
 * the new slot with no diagnostic at all. That function is not exported before
 * 8.5, so the insert is spelled out, and each one uses the same hash family as
 * the lookup it follows.
 */
static zval *zephir_array_write_create_index(HashTable *ht, zend_ulong index)
{
	zval null_value;

	ZVAL_NULL(&null_value);

	return zend_hash_index_update(ht, index, &null_value);
}

static zval *zephir_array_write_create_string(HashTable *ht, const char *index, uint32_t index_length)
{
	zval null_value;

	ZVAL_NULL(&null_value);

	return zend_hash_str_update(ht, index, index_length, &null_value);
}

static zval *zephir_array_write_create_symtable(HashTable *ht, const char *index, uint32_t index_length)
{
	zval null_value;

	ZVAL_NULL(&null_value);

	return zend_symtable_str_update(ht, index, index_length, &null_value);
}

/**
 * Hands a found array element to the caller under one of three contracts.
 *
 * PH_WRITE is the write context. The element becomes a real reference, which is
 * what `ZEND_SEND_REF` (Zend/zend_vm_def.h) does to the slot `ZEND_FETCH_DIM_W`
 * produced, so the callee's write reaches the container, and a callee that
 * replaces its argument rather than mutating it replaces what the container
 * holds. Nobody else is watching that table: zephir_array_write_container()
 * separated it first.
 *
 * PH_READONLY borrows: no addref, and the caller neither observes the target
 * nor releases it, because the container owns the value.
 *
 * Otherwise the caller gets its own reference.
 *
 * Both read contracts follow a reference, as `ZEND_FETCH_DIM_R`'s
 * ZVAL_COPY_DEREF() does, so an element an earlier write context turned into
 * one still reads as its value rather than as a reference.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2682
 * @see https://github.com/zephir-lang/zephir/issues/2691
 */
static void zephir_array_fetch_found(zval *return_value, zval *zv, int flags)
{
	if ((flags & PH_WRITE) == PH_WRITE) {
		ZVAL_MAKE_REF(zv);
		ZVAL_COPY(return_value, zv);

		return;
	}

	ZVAL_DEREF(zv);

	if ((flags & PH_READONLY) == PH_READONLY) {
		ZVAL_COPY_VALUE(return_value, zv);

		return;
	}

	ZVAL_COPY(return_value, zv);
}

/**
 * PHP's warning for a write context it cannot honour.
 *
 * An ArrayAccess object builds the value inside offsetGet() and owns nothing
 * afterwards, so unless it handed back a reference, or an object whose identity
 * is the thing being modified, the caller is about to write into a temporary.
 * Same condition and same wording as `zend_fetch_dimension_address_inner()`,
 * which has not moved since 8.0.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2682
 */
static void zephir_array_fetch_overloaded_notice(const zval *arr, const zval *fetched)
{
	if (Z_ISREF_P(fetched) || Z_TYPE_P(fetched) == IS_OBJECT) {
		return;
	}

	zend_error(E_NOTICE, "Indirect modification of overloaded element of %s has no effect",
		ZSTR_VAL(Z_OBJCE_P(arr)->name));
}

void ZEPHIR_FASTCALL zephir_create_array(zval *return_value, uint32_t size, int initialize)
{
	uint32_t i;
	zval null_value;
	HashTable *hashTable;
	ZVAL_NULL(&null_value);

	array_init_size(return_value, size);
	hashTable = Z_ARRVAL_P(return_value);
	if (size > 0) {
		zend_hash_real_init(hashTable, 0);
		if (initialize) {
			for (i = 0; i < size; i++) {
				zend_hash_next_index_insert(hashTable, &null_value);
			}
		}
	}
}

/**
 * Simple convenience function which ensures that you are dealing with an array and you can
 * eliminate noise from your code.
 *
 * It's a bit strange but the refcount for an empty array is always zero somehow.
 * There is another strange phenomenon: these zvals does not have any type_flag value.
 * Thus we should recreate a new empty array so that it has correct refcount
 * value and type_flag. This magic behavior was introduced since PHP 7.3.
 *
 * Steps to reproduce:
 *
 * Userland:
 *    $object->method([10 => []]);
 *
 * Zephir:
 *    public function method(array p)
 *    {
 *        let p[10]["str"] = "foo";
 *    }
 */
void
ZEPHIR_FASTCALL zephir_ensure_array(zval *zv)
{
	if (
		Z_TYPE_P(zv) == IS_ARRAY &&
		zend_hash_num_elements(Z_ARRVAL_P(zv)) == 0 &&
		(!Z_REFCOUNTED_P(zv) || Z_REFCOUNT_P(zv) < 1)
	) {
		zephir_create_array(zv, 0, 0);
	}
}

int zephir_array_isset_fetch(zval *fetched, const zval *arr, zval *index, int readonly)
{
	HashTable *h;
	zval *result;

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev((zval *)arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval container, exist;
		int found = 0;

		/* offsetExists() runs userland code that can drop the last reference
		 * to the container, and zend_call_function() takes none for the call
		 * frame, so own the container across both calls. PHP's own
		 * zend_std_read_dimension() does the same. */
		ZVAL_COPY(&container, (zval *)arr);
		ZVAL_UNDEF(&exist);

		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(&exist, &container, "offsetexists", NULL, 0, index);
		if (ZEPHIR_LAST_CALL_STATUS != FAILURE && zend_is_true(&exist)) {
			/* No `readonly` here: offsetGet() owns nothing once it has
			 * returned, so its result is handed over owned. @see kernel/array.h */
			ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(fetched, &container, "offsetget", NULL, 0, index);
			found = 1;
		} else {
			ZVAL_NULL(fetched);
		}

		zval_ptr_dtor(&exist);
		zval_ptr_dtor(&container);

		return found;
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		/* A `var` holding a string: PHP's isset() on a string offset is
		 * silent for every illegal offset, so no diagnostic here. */
		if (!zephir_string_offset_isset_zval(arr, index)) {
			ZVAL_NULL(fetched);

			return 0;
		}

		zephir_string_offset_read_zval(fetched, (zval *) arr, index, 0);

		return 1;
	} else if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		ZVAL_NULL(fetched);

		return 0;
	}

	h = Z_ARRVAL_P(arr);
	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			result = zend_hash_str_find(h, SL(""));
			break;

		case IS_DOUBLE:
			result = zend_hash_index_find(h, (zend_ulong)Z_DVAL_P(index));
			break;

		case IS_LONG:
		case IS_RESOURCE:
			result = zend_hash_index_find(h, Z_LVAL_P(index));
			break;

		case IS_TRUE:
		case IS_FALSE:
			result = zend_hash_index_find(h, Z_TYPE_P(index) == IS_TRUE ? 1 : 0);
			break;

		case IS_STRING:
			result = zend_symtable_str_find(h, (Z_STRLEN_P(index) ? Z_STRVAL_P(index) : ""), Z_STRLEN_P(index));
			break;

		default:
			zend_error(E_WARNING, "Illegal offset type %d", Z_TYPE_P(index));
			return 0;
	}

	if (result != NULL) {
		/* A write context leaves the element it wrote through as a reference,
		 * exactly as PHP does, and every read of it dereferences, as
		 * `ZEND_FETCH_DIM_R`'s ZVAL_COPY_DEREF() does. Without this the caller
		 * is handed the reference and its copy is not a copy.
		 * @see https://github.com/zephir-lang/zephir/issues/2691 */
		ZVAL_DEREF(result);
		zephir_ensure_array(result);

		if (!readonly) {
			ZVAL_COPY(fetched, result);
		} else {
			ZVAL_COPY_VALUE(fetched, result);
		}

		return 1;
	}

	ZVAL_NULL(fetched);

	return 0;
}

int zephir_array_isset_string_fetch(zval *fetched, const zval *arr, char *index, uint32_t index_length, int readonly)
{
	zval *zv;
	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev((zval *)arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval container, exist, offset;
		int found = 0;

		/* offsetExists() runs userland code that can drop the last reference
		 * to the container, and zend_call_function() takes none for the call
		 * frame, so own the container across both calls. PHP's own
		 * zend_std_read_dimension() does the same. */
		ZVAL_COPY(&container, (zval *)arr);
		ZVAL_UNDEF(&exist);
		/* The offset has to outlive offsetExists() too: releasing it here left
		 * offsetGet() reading a freed zend_string, and the method-name string
		 * allocated for that very call reused the slot, so the object silently
		 * received the key "offsetget". */
		ZVAL_STRINGL(&offset, index, index_length);

		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(&exist, &container, "offsetexists", NULL, 0, &offset);
		if (ZEPHIR_LAST_CALL_STATUS != FAILURE && zend_is_true(&exist)) {
			/* No `readonly` here: offsetGet() owns nothing once it has
			 * returned, so its result is handed over owned. @see kernel/array.h */
			ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(fetched, &container, "offsetget", NULL, 0, &offset);
			found = 1;
		} else {
			ZVAL_NULL(fetched);
		}

		zval_ptr_dtor(&offset);
		zval_ptr_dtor(&exist);
		zval_ptr_dtor(&container);

		return found;
	} else if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		if ((zv = zend_hash_str_find(Z_ARRVAL_P(arr), index, index_length)) != NULL) {
			/* Dereferences for the same reason as zephir_array_isset_fetch(). */
			ZVAL_DEREF(zv);
			zephir_ensure_array(zv);

			if (!readonly) {
				ZVAL_COPY(fetched, zv);
			} else {
				ZVAL_COPY_VALUE(fetched, zv);
			}
			return 1;
		}
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zval offset;
		int  found;

		ZVAL_STRINGL(&offset, index, index_length);
		found = zephir_string_offset_isset_zval(arr, &offset);

		if (found) {
			zephir_string_offset_read_zval(fetched, (zval *) arr, &offset, 0);
		}

		zval_ptr_dtor(&offset);

		if (found) {
			return 1;
		}
	}

	ZVAL_NULL(fetched);

	return 0;
}

int zephir_array_isset_long_fetch(zval *fetched, const zval *arr, zend_long index, int readonly)
{
	zval *zv;

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev((zval *)arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval container, exist, offset;
		int found = 0;

		/* offsetExists() runs userland code that can drop the last reference
		 * to the container, and zend_call_function() takes none for the call
		 * frame, so own the container across both calls. PHP's own
		 * zend_std_read_dimension() does the same. */
		ZVAL_COPY(&container, (zval *)arr);
		ZVAL_UNDEF(&exist);
		ZVAL_LONG(&offset, index);

		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(&exist, &container, "offsetexists", NULL, 0, &offset);
		if (ZEPHIR_LAST_CALL_STATUS != FAILURE && zend_is_true(&exist)) {
			/* No `readonly` here: offsetGet() owns nothing once it has
			 * returned, so its result is handed over owned. @see kernel/array.h */
			ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(fetched, &container, "offsetget", NULL, 0, &offset);
			found = 1;
		} else {
			ZVAL_NULL(fetched);
		}

		zval_ptr_dtor(&exist);
		zval_ptr_dtor(&container);

		return found;
	} else if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		if ((zv = zend_hash_index_find(Z_ARRVAL_P(arr), (zend_ulong) index)) != NULL) {
			/* Dereferences for the same reason as zephir_array_isset_fetch(). */
			ZVAL_DEREF(zv);
			zephir_ensure_array(zv);

			if (!readonly) {
				ZVAL_COPY(fetched, zv);
			} else {
				ZVAL_COPY_VALUE(fetched, zv);
			}
			return 1;
		}
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		if (zephir_string_offset_isset(arr, index)) {
			zephir_string_offset_read(fetched, (zval *) arr, index, 0);

			return 1;
		}
	}

	ZVAL_NULL(fetched);

	return 0;
}

int ZEPHIR_FASTCALL zephir_array_isset(const zval *arr, zval *index)
{
	HashTable *h;

	if (UNEXPECTED(!arr)) {
		return 0;
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev((zval *)arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval container, exist;
		int found;

		/* offsetExists() runs userland code that can drop the last reference
		 * to the container, and zend_call_function() takes none for the call
		 * frame, so own the container across both calls. PHP's own
		 * zend_std_read_dimension() does the same. */
		ZVAL_COPY(&container, (zval *)arr);
		ZVAL_UNDEF(&exist);

		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(&exist, &container, "offsetexists", NULL, 0, index);
		found = ZEPHIR_LAST_CALL_STATUS != FAILURE && zend_is_true(&exist);

		zval_ptr_dtor(&exist);
		zval_ptr_dtor(&container);

		return found;
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		return zephir_string_offset_isset_zval(arr, index);
	} else if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		return 0;
	}

	h = Z_ARRVAL_P(arr);
	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			return zend_hash_str_exists(h, SL(""));

		case IS_DOUBLE:
			return zend_hash_index_exists(h, (zend_ulong)Z_DVAL_P(index));

		case IS_TRUE:
		case IS_FALSE:
			return zend_hash_index_exists(h, Z_TYPE_P(index) == IS_TRUE ? 1 : 0);

		case IS_LONG:
		case IS_RESOURCE:
			return zend_hash_index_exists(h, Z_LVAL_P(index));

		case IS_STRING:
			return zend_symtable_str_exists(h, Z_STRVAL_P(index), Z_STRLEN_P(index));

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return 0;
	}
}

int ZEPHIR_FASTCALL zephir_array_isset_string(const zval *arr, const char *index, uint32_t index_length)
{
	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev((zval *)arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval container, exist, offset;
		int found;

		/* offsetExists() runs userland code that can drop the last reference
		 * to the container, and zend_call_function() takes none for the call
		 * frame, so own the container across both calls. PHP's own
		 * zend_std_read_dimension() does the same. */
		ZVAL_COPY(&container, (zval *)arr);
		ZVAL_UNDEF(&exist);
		ZVAL_STRINGL(&offset, index, index_length);

		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(&exist, &container, "offsetexists", NULL, 0, &offset);
		found = ZEPHIR_LAST_CALL_STATUS != FAILURE && zend_is_true(&exist);

		zval_ptr_dtor(&offset);
		zval_ptr_dtor(&exist);
		zval_ptr_dtor(&container);

		return found;
	} else if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		return zend_hash_str_exists(Z_ARRVAL_P(arr), index, index_length);
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zval offset;
		int  found;

		ZVAL_STRINGL(&offset, index, index_length);
		found = zephir_string_offset_isset_zval(arr, &offset);
		zval_ptr_dtor(&offset);

		return found;
	}

	return 0;
}

int ZEPHIR_FASTCALL zephir_array_isset_long(const zval *arr, zend_long index)
{
	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev((zval *)arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval container, exist, offset;
		int found;

		/* offsetExists() runs userland code that can drop the last reference
		 * to the container, and zend_call_function() takes none for the call
		 * frame, so own the container across both calls. PHP's own
		 * zend_std_read_dimension() does the same. */
		ZVAL_COPY(&container, (zval *)arr);
		ZVAL_UNDEF(&exist);
		ZVAL_LONG(&offset, index);

		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(&exist, &container, "offsetexists", NULL, 0, &offset);
		found = ZEPHIR_LAST_CALL_STATUS != FAILURE && zend_is_true(&exist);

		zval_ptr_dtor(&exist);
		zval_ptr_dtor(&container);

		return found;
	} else if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		return zend_hash_index_exists(Z_ARRVAL_P(arr), (zend_ulong) index);
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		return zephir_string_offset_isset(arr, index);
	}

	return 0;
}

/*
 * PHP isset() semantics for array offsets: key exists AND value is not IS_NULL.
 * See https://github.com/zephir-lang/zephir/issues/2385.
 *
 * For ArrayAccess objects we keep the existing offsetExists() truthy check —
 * the object's offsetGet() may have side-effects, so we don't read the value.
 * Native arrays look up the entry and additionally check the stored zval's
 * type. References are followed (matching the engine's own isset path).
 */
int ZEPHIR_FASTCALL zephir_array_isset_value(const zval *arr, zval *index)
{
	zval *entry;

	if (UNEXPECTED(!arr)) {
		return 0;
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev((zval *)arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		return zephir_array_isset(arr, index);
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		/* A byte is never null, so isset() is the whole answer. */
		return zephir_array_isset(arr, index);
	}

	if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		return 0;
	}

	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			entry = zend_hash_str_find(Z_ARRVAL_P(arr), "", 0);
			break;
		case IS_DOUBLE:
			entry = zend_hash_index_find(Z_ARRVAL_P(arr), (zend_ulong)Z_DVAL_P(index));
			break;
		case IS_TRUE:
			entry = zend_hash_index_find(Z_ARRVAL_P(arr), 1);
			break;
		case IS_FALSE:
			entry = zend_hash_index_find(Z_ARRVAL_P(arr), 0);
			break;
		case IS_LONG:
		case IS_RESOURCE:
			entry = zend_hash_index_find(Z_ARRVAL_P(arr), Z_LVAL_P(index));
			break;
		case IS_STRING:
			entry = zend_symtable_str_find(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index));
			break;
		default:
			zend_error(E_WARNING, "Illegal offset type");
			return 0;
	}

	if (entry == NULL) {
		return 0;
	}

	ZVAL_DEREF(entry);
	return Z_TYPE_P(entry) != IS_NULL;
}

int ZEPHIR_FASTCALL zephir_array_isset_value_string(const zval *arr, const char *index, uint32_t index_length)
{
	zval *entry;

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev((zval *)arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		return zephir_array_isset_string(arr, index, index_length);
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		/* A byte is never null, so isset() is the whole answer. */
		return zephir_array_isset_string(arr, index, index_length);
	}

	if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		return 0;
	}

	entry = zend_hash_str_find(Z_ARRVAL_P(arr), index, index_length);
	if (entry == NULL) {
		return 0;
	}

	ZVAL_DEREF(entry);
	return Z_TYPE_P(entry) != IS_NULL;
}

int ZEPHIR_FASTCALL zephir_array_isset_value_long(const zval *arr, zend_long index)
{
	zval *entry;

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev((zval *)arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		return zephir_array_isset_long(arr, index);
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		/* A byte is never null, so isset() is the whole answer. */
		return zephir_array_isset_long(arr, index);
	}

	if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		return 0;
	}

	entry = zend_hash_index_find(Z_ARRVAL_P(arr), (zend_ulong) index);
	if (entry == NULL) {
		return 0;
	}

	ZVAL_DEREF(entry);
	return Z_TYPE_P(entry) != IS_NULL;
}

/**
 * `empty($container[$offset])`.
 *
 * PHP does not compose this out of a read plus a truthiness test: it has a
 * dedicated silent handler (`zend_isempty_dim_slow`) that reports nothing for
 * a missing key, an out-of-range string offset or an illegal offset type, and
 * answers "empty" for all of them. Reusing the isset-fetch helpers gets the
 * same answer for arrays, strings and ArrayAccess alike.
 */
static int zephir_isempty_dim_fetched(int found, zval *fetched)
{
	int result;

	if (!found) {
		return 1;
	}

	result = !zend_is_true(fetched);
	zval_ptr_dtor(fetched);

	return result;
}

int zephir_isempty_dim(zval *container, zval *offset)
{
	zval fetched;

	ZVAL_UNDEF(&fetched);

	return zephir_isempty_dim_fetched(zephir_array_isset_fetch(&fetched, container, offset, 0), &fetched);
}

int zephir_isempty_dim_long(zval *container, zend_long offset)
{
	zval fetched;

	ZVAL_UNDEF(&fetched);

	return zephir_isempty_dim_fetched(zephir_array_isset_long_fetch(&fetched, container, offset, 0), &fetched);
}

int zephir_isempty_dim_string(zval *container, char *offset, uint32_t offset_length)
{
	zval fetched;

	ZVAL_UNDEF(&fetched);

	return zephir_isempty_dim_fetched(
		zephir_array_isset_string_fetch(&fetched, container, offset, offset_length, 0),
		&fetched
	);
}

int ZEPHIR_FASTCALL zephir_array_unset(zval *arr, zval *index, int flags)
{
	HashTable *ht;

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, arr, "offsetunset", NULL, 0, index);
		if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
			return 1;
		}

		return 0;
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zend_throw_error(NULL, "Cannot unset string offsets");

		return 0;
	} else if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ARRAY(arr);
	}

	ht = Z_ARRVAL_P(arr);

	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			return (zend_hash_str_del(ht, "", 1) == SUCCESS);

		case IS_DOUBLE:
			return (zend_hash_index_del(ht, (zend_ulong)Z_DVAL_P(index)) == SUCCESS);

		case IS_TRUE:
			return (zend_hash_index_del(ht, 1) == SUCCESS);

		case IS_FALSE:
			return (zend_hash_index_del(ht, 0) == SUCCESS);

		case IS_LONG:
		case IS_RESOURCE:
			return (zend_hash_index_del(ht, Z_LVAL_P(index)) == SUCCESS);

		case IS_STRING:
			return (zend_symtable_del(ht, Z_STR_P(index)) == SUCCESS);

		default:
			zend_error(E_WARNING, "Passed index has illegal offset type (check zephir_array_unset())");
			return 0;
	}
}

int ZEPHIR_FASTCALL zephir_array_unset_string(zval *arr, const char *index, uint32_t index_length, int flags)
{
	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval offset;
		ZVAL_STRINGL(&offset, index, index_length);
		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, arr, "offsetunset", NULL, 0, &offset);
		zval_ptr_dtor(&offset);
		if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
			return 1;
		}

		return 0;
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zend_throw_error(NULL, "Cannot unset string offsets");

		return 0;
	} else if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL(arr);
	}

	return zend_hash_str_del(Z_ARRVAL_P(arr), index, index_length);
}

int ZEPHIR_FASTCALL zephir_array_unset_long(zval *arr, zend_long index, int flags)
{
	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval offset;
		ZVAL_LONG(&offset, index);
		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, arr, "offsetunset", NULL, 0, &offset);

		if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
			return 1;
		}

		return 0;
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zend_throw_error(NULL, "Cannot unset string offsets");

		return 0;
	} else if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ARRAY(arr);
	}

	return zend_hash_index_del(Z_ARRVAL_P(arr), (zend_ulong) index);
}

int zephir_array_append(zval *arr, zval *value, int flags ZEPHIR_DEBUG_PARAMS)
{
	if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zend_throw_error(NULL, "[] operator not supported for strings");

		return FAILURE;
	}

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		zend_error(E_WARNING, "Cannot use a scalar value as an array in %s on line %d", file, line);
		return FAILURE;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ARRAY(arr);
	}

	Z_TRY_ADDREF_P(value);
	return add_next_index_zval(arr, value);
}

int zephir_array_fetch(zval *return_value, zval *arr, zval *index, int flags ZEPHIR_DEBUG_PARAMS)
{
	zval *zv;
	HashTable *ht;
	int result = SUCCESS, found = 0;
	zend_ulong uidx = 0;
	char *sidx = NULL;
	uint32_t sidx_length = 0;

	if ((flags & PH_WRITE) == PH_WRITE) {
		arr = zephir_array_write_container(arr);
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(return_value, arr, "offsetget", NULL, 0, index);
		if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
			/* No PH_READONLY here: offsetGet() owns nothing once it has
			 * returned, so its result is handed over owned. @see kernel/array.h */
			if ((flags & PH_WRITE) == PH_WRITE) {
				zephir_array_fetch_overloaded_notice(arr, return_value);
			}

			return SUCCESS;
		}

		return FAILURE;
	} else if (Z_TYPE_P(arr) == IS_ARRAY) {
		ht = Z_ARRVAL_P(arr);
		switch (Z_TYPE_P(index)) {
			case IS_NULL:
				found = (zv = zend_hash_str_find(ht, SL(""))) != NULL;
				sidx   = "";
				break;

			case IS_DOUBLE:
				uidx   = (zend_ulong)Z_DVAL_P(index);
				found  = (zv = zend_hash_index_find(ht, uidx)) != NULL;
				break;

			case IS_LONG:
			case IS_RESOURCE:
				uidx   = Z_LVAL_P(index);
				found  = (zv = zend_hash_index_find(ht, uidx)) != NULL;
				break;

			case IS_FALSE:
				uidx = 0;
				found  = (zv = zend_hash_index_find(ht, uidx)) != NULL;
				break;

			case IS_TRUE:
				uidx = 1;
				found  = (zv = zend_hash_index_find(ht, uidx)) != NULL;
				break;

			case IS_STRING:
				sidx        = Z_STRLEN_P(index) ? Z_STRVAL_P(index) : "";
				sidx_length = Z_STRLEN_P(index);
				found       = (zv = zend_symtable_str_find(ht, Z_STRVAL_P(index), Z_STRLEN_P(index))) != NULL;
				break;

			default:
				if ((flags & PH_NOISY) == PH_NOISY) {
					zend_error(E_WARNING, "Illegal offset type in %s on line %d", file, line);
				}
				result = FAILURE;
				break;
		}

		if (result != FAILURE && found == 0 && (flags & PH_WRITE) == PH_WRITE) {
			zv    = (sidx != NULL)
				? zephir_array_write_create_symtable(ht, sidx, sidx_length)
				: zephir_array_write_create_index(ht, uidx);
			found = zv != NULL;
		}

		if (result != FAILURE && found == 1) {
			zephir_array_fetch_found(return_value, zv, flags);

			return SUCCESS;
		}

		if ((flags & PH_NOISY) == PH_NOISY) {
			if (sidx == NULL) {
				zend_error(E_NOTICE, "Undefined index: " ZEND_LONG_FMT " in %s on line %d", (zend_long) uidx, file, line);
			} else {
				zend_error(E_NOTICE, "Undefined index: %s in %s on line %d", sidx, file, line);
			}
		}
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zephir_string_offset_read_zval(return_value, arr, index, flags);

		return EG(exception) ? FAILURE : SUCCESS;
	}

	ZVAL_NULL(return_value);
	return FAILURE;
}

int zephir_array_fetch_string(zval *return_value, zval *arr, const char *index, uint32_t index_length, int flags ZEPHIR_DEBUG_PARAMS)
{
	zval *zv;

	if ((flags & PH_WRITE) == PH_WRITE) {
		arr = zephir_array_write_container(arr);
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval offset;
		ZVAL_STRINGL(&offset, index, index_length);
		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(return_value, arr, "offsetget", NULL, 0, &offset);
		zval_ptr_dtor(&offset);
		if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
			/* No PH_READONLY here: offsetGet() owns nothing once it has
			 * returned, so its result is handed over owned. @see kernel/array.h */
			if ((flags & PH_WRITE) == PH_WRITE) {
				zephir_array_fetch_overloaded_notice(arr, return_value);
			}

			return SUCCESS;
		}

		return FAILURE;
	} else if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		if ((zv = zend_hash_str_find(Z_ARRVAL_P(arr), index, index_length)) == NULL
			&& (flags & PH_WRITE) == PH_WRITE) {
			zv = zephir_array_write_create_string(Z_ARRVAL_P(arr), index, index_length);
		}

		if (zv != NULL) {
			zephir_array_fetch_found(return_value, zv, flags);

			return SUCCESS;
		}
		if ((flags & PH_NOISY) == PH_NOISY) {
			zend_error(E_NOTICE, "Undefined index: %s", index);
		}
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zval offset;

		ZVAL_STRINGL(&offset, index, index_length);
		zephir_string_offset_read_zval(return_value, arr, &offset, flags);
		zval_ptr_dtor(&offset);

		return EG(exception) ? FAILURE : SUCCESS;
	} else {
		if ((flags & PH_NOISY) == PH_NOISY) {
			zend_error(E_NOTICE, "Cannot use a scalar value as an array in %s on line %d", file, line);
		}
	}

	if (return_value == NULL) {
		zend_error(E_ERROR, "No return value passed to zephir_array_fetch_string");
		return FAILURE;
	}

	ZVAL_NULL(return_value);
	return FAILURE;
}

int zephir_array_fetch_long(zval *return_value, zval *arr, zend_long index, int flags ZEPHIR_DEBUG_PARAMS)
{
	zval *zv;

	if ((flags & PH_WRITE) == PH_WRITE) {
		arr = zephir_array_write_container(arr);
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval offset;
		ZVAL_LONG(&offset, index);
		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(return_value, arr, "offsetget", NULL, 0, &offset);
		if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
			/* No PH_READONLY here: offsetGet() owns nothing once it has
			 * returned, so its result is handed over owned. @see kernel/array.h */
			if ((flags & PH_WRITE) == PH_WRITE) {
				zephir_array_fetch_overloaded_notice(arr, return_value);
			}

			return SUCCESS;
		}

		return FAILURE;
	} else if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		if ((zv = zend_hash_index_find(Z_ARRVAL_P(arr), (zend_ulong) index)) == NULL
			&& (flags & PH_WRITE) == PH_WRITE) {
			zv = zephir_array_write_create_index(Z_ARRVAL_P(arr), (zend_ulong) index);
		}

		if (zv != NULL) {
			zephir_array_fetch_found(return_value, zv, flags);

			return SUCCESS;
		}
		if ((flags & PH_NOISY) == PH_NOISY) {
			zend_error(E_NOTICE, "Undefined index: " ZEND_LONG_FMT, index);
		}
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		/* The compiler cannot prove a `var` holds a string, so the string
		 * offset is dispatched here. */
		zephir_string_offset_read(return_value, arr, index, flags);

		return SUCCESS;
	} else {
		if ((flags & PH_NOISY) == PH_NOISY) {
			zend_error(E_NOTICE, "Cannot use a scalar value as an array in %s on line %d", file, line);
		}
	}

	if (return_value == NULL) {
		zend_error(E_ERROR, "No return value passed to zephir_array_fetch_string");
		return FAILURE;
	}

	ZVAL_NULL(return_value);
	return FAILURE;
}

/**
 * Appends every element of an array at the end of the left array
 */
void zephir_merge_append(zval *left, zval *values)
{
	if (Z_TYPE_P(left) != IS_ARRAY) {
		zend_error(E_NOTICE, "First parameter of zephir_merge_append must be an array");
		return;
	}

	if (Z_TYPE_P(values) == IS_ARRAY) {
		zval *tmp;

		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(values), tmp) {

			Z_TRY_ADDREF_P(tmp);
			add_next_index_zval(left, tmp);

		} ZEND_HASH_FOREACH_END();

	} else {
		Z_TRY_ADDREF_P(values);
		add_next_index_zval(left, values);
	}
}

int zephir_array_update_zval(zval *arr, zval *index, zval *value, int flags)
{
	HashTable *ht;
	zval *ret = NULL;

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, arr, "offsetset", NULL, 0, index, value);
		if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
			return SUCCESS;
		}

		return FAILURE;
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zephir_string_offset_write_zval(arr, index, value);

		return EG(exception) ? FAILURE : SUCCESS;
	} else if (Z_TYPE_P(arr) != IS_ARRAY) {
		zend_error(E_WARNING, "Cannot use a scalar value as an array (2)");
		return FAILURE;
	}

	if ((flags & PH_CTOR) == PH_CTOR) {
		zval new_zv;
		ZVAL_DUP(&new_zv, value);
		value = &new_zv;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ARRAY(arr);
	}

	if ((flags & PH_COPY) == PH_COPY) {
		Z_TRY_ADDREF_P(value);
	}

	ht = Z_ARRVAL_P(arr);

	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			ret = zend_symtable_str_update(ht, "", 1, value);
			break;

		case IS_DOUBLE:
			ret = zend_hash_index_update(ht, (zend_ulong)Z_DVAL_P(index), value);
			break;

		case IS_LONG:
		case IS_RESOURCE:
			ret = zend_hash_index_update(ht, Z_LVAL_P(index), value);
			break;

		case IS_TRUE:
		case IS_FALSE:
			ret = zend_hash_index_update(ht, Z_TYPE_P(index) == IS_TRUE ? 1 : 0, value);
			break;

		case IS_STRING:
			ret = zend_symtable_str_update(ht, Z_STRVAL_P(index), Z_STRLEN_P(index), value);
			break;

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return FAILURE;
	}

	return ret != NULL ? FAILURE : SUCCESS;
}

int zephir_array_update_string(zval *arr, const char *index, uint32_t index_length, zval *value, int flags)
{
	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval offset;
		ZVAL_STRINGL(&offset, index, index_length);
		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, arr, "offsetset", NULL, 0, &offset, value);
		zval_ptr_dtor(&offset);
		if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
			return SUCCESS;
		}

		return FAILURE;
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zval offset;

		ZVAL_STRINGL(&offset, index, index_length);
		zephir_string_offset_write_zval(arr, &offset, value);
		zval_ptr_dtor(&offset);

		return EG(exception) ? FAILURE : SUCCESS;
	} else if (Z_TYPE_P(arr) != IS_ARRAY) {
		zend_error(E_WARNING, "Cannot use a scalar value as an array (3)");
		return FAILURE;
	}

	if ((flags & PH_CTOR) == PH_CTOR) {
		zval new_value;

		ZVAL_DUP(&new_value, value);
		value = &new_value;
	} else if ((flags & PH_COPY) == PH_COPY) {
		Z_TRY_ADDREF_P(value);
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ARRAY(arr);
	}

	return zend_hash_str_update(Z_ARRVAL_P(arr), index, index_length, value) ? SUCCESS : FAILURE;
}

int zephir_array_update_long(zval *arr, zend_long index, zval *value, int flags ZEPHIR_DEBUG_PARAMS)
{
	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess))) {
		zend_long ZEPHIR_LAST_CALL_STATUS;
		zval offset;
		ZVAL_LONG(&offset, index);
		ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, arr, "offsetset", NULL, 0, &offset, value);
		if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
			return SUCCESS;
		}

		return FAILURE;
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zephir_string_offset_write(arr, index, value);

		return EG(exception) ? FAILURE : SUCCESS;
	} else if (Z_TYPE_P(arr) != IS_ARRAY) {
		zend_error(E_WARNING, "Cannot use a scalar value as an array in %s on line %d", file, line);
		return FAILURE;
	}

	if ((flags & PH_CTOR) == PH_CTOR) {
		zval new_value;

		ZVAL_DUP(&new_value, value);
		value = &new_value;
	} else if ((flags & PH_COPY) == PH_COPY) {
		Z_TRY_ADDREF_P(value);
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ARRAY(arr);
	}

	return zend_hash_index_update(Z_ARRVAL_P(arr), (zend_ulong) index, value) ? SUCCESS : FAILURE;
}

void zephir_array_keys(zval *return_value, zval *input)
{
	zval *entry, new_val;
	zend_ulong num_idx;
	zend_string *str_idx;

	if (EXPECTED(Z_TYPE_P(input) == IS_ARRAY)) {
		array_init_size(return_value, zend_hash_num_elements(Z_ARRVAL_P(input)));
		zend_hash_real_init(Z_ARRVAL_P(return_value), 1);
		ZEND_HASH_FILL_PACKED(Z_ARRVAL_P(return_value)) {
			/* Go through input array and add keys to the return array */
			ZEND_HASH_FOREACH_KEY_VAL_IND(Z_ARRVAL_P(input), num_idx, str_idx, entry) {
				if (str_idx) {
					ZVAL_STR_COPY(&new_val, str_idx);
				} else {
					ZVAL_LONG(&new_val, num_idx);
				}
				ZEND_HASH_FILL_ADD(&new_val);
			} ZEND_HASH_FOREACH_END();
		} ZEND_HASH_FILL_END();
	}

	entry = NULL;
	str_idx = NULL;
	num_idx = 0;
	ZVAL_UNDEF(&new_val);
}

int zephir_array_key_exists(zval *arr, zval *key)
{
	HashTable *h;

	/* Reachable with any dynamically typed container, and reading Z_ARRVAL of
	 * a string would reinterpret the zend_string as a HashTable. Every other
	 * helper here answers 0 for a non-array, so this one does too. */
	if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		return 0;
	}

	h = Z_ARRVAL_P(arr);
	if (h) {
		switch (Z_TYPE_P(key)) {
			case IS_STRING:
				return zend_symtable_exists(h, Z_STR_P(key));

			case IS_LONG:
				return zend_hash_index_exists(h, Z_LVAL_P(key));

			case IS_NULL:
				return zend_hash_str_exists(h, "", 1);

			default:
				zend_error(E_WARNING, "The key should be either a string or an integer");
				return 0;
		}
	}

	return 0;
}

/**
 * Implementation of Multiple array-offset update
 */
void zephir_array_update_multi_ex(zval *arr, zval *value, const char *types, int types_length, int types_count, va_list ap)
{
	char *s;
	zval *item;
	zval pzv;
	zend_array *p;
	int i, re_update, must_continue, wrap_tmp;
	zend_long ll;
	/* SL() yields sizeof(...) - 1, a size_t, so that is what the variadic
	 * slot holds. Reading it back as `int` was reading half of it. */
	size_t l;

	ZVAL_UNDEF(&pzv);

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		zend_error(E_ERROR, "Cannot use a scalar value as an array (multi)");
		return;
	}
	p = Z_ARRVAL_P(arr);

	for (i = 0; i < types_length; ++i) {
		zval tmp;
		zval fetched;
		ZVAL_UNDEF(&fetched);

		re_update = 0;
		must_continue = 0;
		wrap_tmp = 0;

		ZVAL_ARR(&pzv, p);
		switch (types[i]) {

			case 's':
				s = va_arg(ap, char*);
				l = va_arg(ap, size_t);

				/*
				 * Issue #1884: the final offset overwrites its slot regardless of
				 * the value already there, so skip the redundant isset-fetch and
				 * store directly. PH_SEPARATE only when the level is actually
				 * shared (re_update); otherwise SEPARATE_ARRAY would be a no-op.
				 */
				if (i == (types_length - 1)) {
					ZVAL_ARR(&pzv, p);
					re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
					zephir_array_update_string(&pzv, s, l, value, PH_COPY | (re_update ? PH_SEPARATE : 0));
					p = Z_ARRVAL(pzv);
					break;
				}

				if (zephir_array_isset_string_fetch(&fetched, &pzv, s, l, 1)) {
					if (Z_TYPE(fetched) == IS_ARRAY) {
						re_update = !Z_REFCOUNTED(fetched) || (Z_REFCOUNT(fetched) > 1 && !Z_ISREF(fetched));
						if (re_update) {
							ZVAL_DUP(&tmp, &fetched);
							zephir_array_update_string(&pzv, s, l, &tmp, 0);
							p = Z_ARRVAL(tmp);
						} else {
							p = Z_ARRVAL(fetched);
						}
						must_continue = 1;
					}
				}

				if (!must_continue) {
					ZVAL_ARR(&pzv, p);
					re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
					array_init(&tmp);
					zephir_array_update_string(&pzv, s, l, &tmp, PH_SEPARATE);
					p = Z_ARRVAL(pzv);
					if (re_update) {
						wrap_tmp = 1;
					} else {
						p = Z_ARRVAL(tmp);
					}
				}
				break;

			case 'l':
				ll = va_arg(ap, zend_long);

				/* Issue #1884: final offset always overwrites -> store directly. */
				if (i == (types_length - 1)) {
					ZVAL_ARR(&pzv, p);
					re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
					zephir_array_update_long(&pzv, ll, value, PH_COPY | (re_update ? PH_SEPARATE : 0) ZEPHIR_DEBUG_PARAMS_DUMMY);
					p = Z_ARRVAL(pzv);
					break;
				}

				if (zephir_array_isset_long_fetch(&fetched, &pzv, ll, 1)) {
					if (Z_TYPE(fetched) == IS_ARRAY) {
						re_update = !Z_REFCOUNTED(fetched) || (Z_REFCOUNT(fetched) > 1 && !Z_ISREF(fetched));
						if (re_update) {
							ZVAL_DUP(&tmp, &fetched);
							zephir_array_update_long(&pzv, ll, &tmp, 0 ZEPHIR_DEBUG_PARAMS_DUMMY);
							p = Z_ARRVAL(tmp);
						} else {
							p = Z_ARRVAL(fetched);
						}
						must_continue = 1;
					}
				}

				if (!must_continue) {
					ZVAL_ARR(&pzv, p);
					re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
					array_init(&tmp);
					zephir_array_update_long(&pzv, ll, &tmp, PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					p = Z_ARRVAL(pzv);
					if (re_update) {
						wrap_tmp = 1;
					} else {
						p = Z_ARRVAL(tmp);
					}
				}
				break;

			case 'z':
				item = va_arg(ap, zval*);

				/* Issue #1884: final offset always overwrites -> store directly. */
				if (i == (types_length - 1)) {
					ZVAL_ARR(&pzv, p);
					re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
					zephir_array_update_zval(&pzv, item, value, PH_COPY | (re_update ? PH_SEPARATE : 0));
					p = Z_ARRVAL(pzv);
					break;
				}

				if (zephir_array_isset_fetch(&fetched, &pzv, item, 1)) {
					if (Z_TYPE(fetched) == IS_ARRAY) {
						re_update = !Z_REFCOUNTED(fetched) || (Z_REFCOUNT(fetched) > 1 && !Z_ISREF(fetched));
						if (re_update) {
							ZVAL_DUP(&tmp, &fetched);
							zephir_array_update_zval(&pzv, item, &tmp, 0);
							p = Z_ARRVAL(tmp);
						} else {
							p = Z_ARRVAL(fetched);
						}
						must_continue = 1;
					}
				}

				if (!must_continue) {
					ZVAL_ARR(&pzv, p);
					re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
					array_init(&tmp);
					zephir_array_update_zval(&pzv, item, &tmp, PH_SEPARATE);
					p = Z_ARRVAL(pzv);
					if (re_update) {
						wrap_tmp = 1;
					} else {
						p = Z_ARRVAL(tmp);
					}
				}
				break;

			case 'a':
				re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
				if (re_update) {
					zephir_array_append(&pzv, value, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				} else {
					zephir_array_append(&pzv, value, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
				}

				p = Z_ARRVAL(pzv);
				break;
		}
	}
}

int zephir_array_update_multi(zval *arr, zval *value, const char *types, int types_length, int types_count, ...)
{
	va_list ap;
	va_start(ap, types_count);
	SEPARATE_ZVAL(arr);

	zephir_array_update_multi_ex(arr, value, types, types_length, types_count, ap);
	va_end(ap);

	return 0;
}

/**
 * Fast in_array function
 */
int zephir_fast_in_array(zval *value, zval *haystack)
{
	zval *entry;

	if (Z_TYPE_P(haystack) != IS_ARRAY) {
		return 0;
	}

	if (Z_TYPE_P(value) == IS_STRING) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(haystack), entry) {
			if (fast_equal_check_string(value, entry)) {
				return 1;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(haystack), entry) {
			if (fast_equal_check_function(value, entry)) {
				return 1;
			}
		} ZEND_HASH_FOREACH_END();
	}

	return 0;
}

/**
 * Fast array merge
 */
void zephir_fast_array_merge(zval *return_value, zval *array1, zval *array2)
{
	int init_size, num;

	if (Z_TYPE_P(array1) != IS_ARRAY) {
		zend_error(E_WARNING, "First argument is not an array");
		RETURN_NULL();
	}

	if (Z_TYPE_P(array2) != IS_ARRAY) {
		zend_error(E_WARNING, "Second argument is not an array");
		RETURN_NULL();
	}

	init_size = zend_hash_num_elements(Z_ARRVAL_P(array1));
	num = zend_hash_num_elements(Z_ARRVAL_P(array2));
	if (num > init_size) {
		init_size = num;
	}

	array_init_size(return_value, init_size);
	php_array_merge(Z_ARRVAL_P(return_value), Z_ARRVAL_P(array1));
	php_array_merge(Z_ARRVAL_P(return_value), Z_ARRVAL_P(array2));
}
