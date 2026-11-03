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
#include <Zend/zend_execute.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/debug.h"
#include "kernel/array.h"
#include "kernel/buffer.h"
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
static zval *zephir_array_write_container_ex(zval *arr, int check_reference_type)
{
	/* A reference bound to a typed property keeps that type, so null or false
	 * may become an array through it only if the type allows one. PHP checks
	 * it for every write context but the last offset of a compound
	 * assignment (`zend_fetch_dimension_address()`, ZEND_ASSIGN_DIM), and
	 * throws "Cannot auto-initialize an array inside a reference held by
	 * property ...". NULL tells the caller an error is pending.
	 * @see https://github.com/zephir-lang/zephir/issues/2747 */
	if (Z_ISREF_P(arr)) {
		zend_reference *ref = Z_REF_P(arr);

		arr = Z_REFVAL_P(arr);

		if (check_reference_type
			&& Z_TYPE_P(arr) <= IS_FALSE
			&& UNEXPECTED(ZEND_REF_HAS_TYPE_SOURCES(ref))
			&& !zend_verify_ref_array_assignable(ref)) {
			return NULL;
		}
	}

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

static zval *zephir_array_write_container(zval *arr)
{
	return zephir_array_write_container_ex(arr, 1);
}

/**
 * Creates the element a write context asked for and hands back its slot.
 *
 * A write context is a lookup-or-create: BP_VAR_W reaches `zend_hash_lookup()`
 * in `zend_fetch_dimension_address_inner()`, which inserts a null and returns
 * the new slot with no diagnostic at all. That function is not exported before
 * 8.5, so the insert is spelled out, and each one uses the same hash family as
 * the lookup it follows.
 *
 * A caller supplied string key always goes through the `zend_symtable_str_*`
 * family, never `zend_hash_str_*`. PHP folds a constant numeric string
 * subscript to an integer key while it compiles it (`zend_handle_numeric_dim()`
 * in Zend/zend_compile.c), so `$a["3"]` is `$a[3]`, and `zend_symtable_str_*`
 * is that same fold applied at runtime. Reaching for the raw hash instead is
 * what made `zephir_array_update_string()` store a string key where the array
 * literal beside it, emitted as `add_assoc_*_ex()`, stored an integer one.
 * Only an ArrayAccess container keeps the original string, which is why every
 * such branch below boxes `index` untouched rather than normalising it.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2708
 */
static zval *zephir_array_write_create_index(HashTable *ht, zend_ulong index)
{
	zval null_value;

	ZVAL_NULL(&null_value);

	return zend_hash_index_update(ht, index, &null_value);
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

/**
 * Holds a table across a diagnostic.
 *
 * An error handler runs userland code, which may drop the last reference to
 * the array being written or replace it. PHP takes a reference for the
 * duration and gives up when the table comes back changed
 * (`zend_undefined_offset_write()`, Zend/zend_execute.c); so does this.
 */
static void zephir_array_rw_hold(HashTable *ht)
{
	if (!(GC_FLAGS(ht) & IS_ARRAY_IMMUTABLE)) {
		GC_ADDREF(ht);
	}
}

static int zephir_array_rw_release(HashTable *ht)
{
	if (!(GC_FLAGS(ht) & IS_ARRAY_IMMUTABLE) && GC_DELREF(ht) != 1) {
		if (!GC_REFCOUNT(ht)) {
			zend_array_destroy(ht);
		}

		return FAILURE;
	}

	return EG(exception) ? FAILURE : SUCCESS;
}

/**
 * The same guard for a table that is only read. It is shared, so its count
 * says nothing about a change; the read gives up only when the diagnostic
 * dropped the last reference, as `slow_index_convert()` does.
 */
static int zephir_array_read_release(HashTable *ht)
{
	if (!(GC_FLAGS(ht) & IS_ARRAY_IMMUTABLE) && GC_DELREF(ht) == 0) {
		zend_array_destroy(ht);

		return FAILURE;
	}

	return EG(exception) ? FAILURE : SUCCESS;
}

/**
 * Releases what zephir_array_rw_hold() took, under the rule of the context.
 * `ZEND_UNSET_DIM` gives up only when the table was destroyed, as a read does.
 */
static int zephir_array_hold_release(HashTable *ht, int type)
{
	return type == BP_VAR_R || type == BP_VAR_IS || type == BP_VAR_UNSET
		? zephir_array_read_release(ht)
		: zephir_array_rw_release(ht);
}

/**
 * PHP 8's warnings for an element that is not there.
 */
static void zephir_array_undefined_index(zend_ulong hval)
{
	zend_error(E_WARNING, "Undefined array key " ZEND_LONG_FMT, (zend_long) hval);
}

static void zephir_array_undefined_key(const zend_string *key)
{
	zend_error(E_WARNING, "Undefined array key \"%s\"", ZSTR_VAL(key));
}

/**
 * Converts an array offset to the key PHP looks it up by.
 *
 * `slow_index_convert()` and `slow_index_convert_w()` (Zend/zend_execute.c):
 * a numeric string is an integer key, null is the empty string, a float, a
 * bool and a resource are integers. The diagnostics follow the running PHP:
 * a float with a fraction is deprecated since 8.1, null since 8.5, a resource
 * always warns, and an illegal offset throws a TypeError naming its type since
 * 8.3, worded for isset and empty() under BP_VAR_IS.
 *
 * BP_VAR_UNSET is the last offset of an unset, `ZEND_UNSET_DIM`: null is never
 * deprecated there, a resource warns only since 8.1, and before 8.3 an illegal
 * offset has its own message.
 *
 * A diagnostic runs userland code, which may destroy or replace the table, so
 * it is held across each one and the conversion gives up when it changed.
 *
 * Returns IS_LONG with `hval`, IS_STRING with `key`, or IS_UNDEF when the
 * offset cannot be used and an error is pending.
 */
static int zephir_array_offset_key(HashTable *ht, zval *dim, int type, zend_ulong *hval, zend_string **key)
{
try_again:
	switch (Z_TYPE_P(dim)) {
		case IS_LONG:
			*hval = Z_LVAL_P(dim);
			return IS_LONG;

		case IS_STRING:
			if (ZEND_HANDLE_NUMERIC_STR(Z_STRVAL_P(dim), Z_STRLEN_P(dim), *hval)) {
				return IS_LONG;
			}
			*key = Z_STR_P(dim);
			return IS_STRING;

		case IS_NULL:
#if PHP_VERSION_ID >= 80500
			if (type != BP_VAR_UNSET) {
				zephir_array_rw_hold(ht);
				zend_error(E_DEPRECATED, "Using null as an array offset is deprecated, use an empty string instead");
				if (zephir_array_hold_release(ht, type) == FAILURE) {
					return IS_UNDEF;
				}
			}
#endif
			*key = ZSTR_EMPTY_ALLOC();
			return IS_STRING;

		case IS_DOUBLE:
#if PHP_VERSION_ID >= 80100
			zephir_array_rw_hold(ht);
			*hval = zend_dval_to_lval_safe(Z_DVAL_P(dim));
			if (zephir_array_hold_release(ht, type) == FAILURE) {
				return IS_UNDEF;
			}
#else
			*hval = zend_dval_to_lval(Z_DVAL_P(dim));
#endif
			return IS_LONG;

		case IS_RESOURCE:
#if PHP_VERSION_ID < 80100
			if (type == BP_VAR_UNSET) {
				*hval = Z_RES_HANDLE_P(dim);
				return IS_LONG;
			}
#endif
			zephir_array_rw_hold(ht);
			zend_error(E_WARNING, "Resource ID#" ZEND_LONG_FMT " used as offset, casting to integer (" ZEND_LONG_FMT ")",
				(zend_long) Z_RES_HANDLE_P(dim), (zend_long) Z_RES_HANDLE_P(dim));
			if (zephir_array_hold_release(ht, type) == FAILURE) {
				return IS_UNDEF;
			}
			*hval = Z_RES_HANDLE_P(dim);
			return IS_LONG;

		case IS_FALSE:
			*hval = 0;
			return IS_LONG;

		case IS_TRUE:
			*hval = 1;
			return IS_LONG;

		case IS_REFERENCE:
			dim = Z_REFVAL_P(dim);
			goto try_again;

		default:
#if PHP_VERSION_ID >= 80300
			zend_illegal_container_offset(ZSTR_KNOWN(ZEND_STR_ARRAY), dim, type);
#else
			if (type == BP_VAR_IS) {
				zend_type_error("Illegal offset type in isset or empty");
			} else if (type == BP_VAR_UNSET) {
				zend_type_error("Illegal offset type in unset");
			} else {
				zend_type_error("Illegal offset type");
			}
#endif
			return IS_UNDEF;
	}
}

/* The write engine, defined with zephir_array_assign_op() further down. */
static int zephir_array_dim_assign(zval *container, zval *dim, zval *value, int separate);
static int zephir_array_assign_walk(zval *container, zval *value, const char *types, int types_length, va_list ap);

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

/**
 * The element `isset`, empty() and `fetch` look for, `zend_isset_dim_slow()`:
 * the offset is converted as for any read, with the same deprecations and
 * warnings, and an illegal one throws the TypeError worded for isset.
 */
static zval *zephir_array_isset_find(HashTable *ht, zval *index)
{
	zend_ulong hval;
	zend_string *key;
	zval *zv;

	switch (zephir_array_offset_key(ht, index, BP_VAR_IS, &hval, &key)) {
		case IS_LONG:
			return zend_hash_index_find(ht, hval);

		case IS_STRING:
			zv = zend_hash_find(ht, key);
			if (zv != NULL && UNEXPECTED(Z_TYPE_P(zv) == IS_INDIRECT)) {
				zv = Z_INDIRECT_P(zv);

				return Z_TYPE_P(zv) == IS_UNDEF ? NULL : zv;
			}

			return zv;

		default:
			return NULL;
	}
}

/**
 * `isset` on an object without ArrayAccess asks its own has_dimension()
 * handler, which is what answers for a SimpleXMLElement and throws "Cannot use
 * object of type %s as array" for an object with no dimensions at all. When
 * `fetched` is given, a found element is read back through read_dimension()
 * and handed over owned.
 */
static int zephir_array_isset_object(zval *fetched, const zval *arr, zval *index)
{
	zend_object *obj = Z_OBJ_P(arr);
	zval rv;
	zval *res;
	int found;

	GC_ADDREF(obj);
	found = obj->handlers->has_dimension(obj, index, 0) && !EG(exception);

	if (fetched != NULL) {
		ZVAL_NULL(fetched);

		if (found) {
			ZVAL_UNDEF(&rv);
			res = obj->handlers->read_dimension(obj, index, BP_VAR_IS, &rv);

			if (res == &rv) {
				ZVAL_COPY_VALUE(fetched, &rv);
			} else if (res != NULL && Z_TYPE_P(res) != IS_UNDEF) {
				ZVAL_COPY_DEREF(fetched, res);
			}
		}
	}

	if (UNEXPECTED(GC_DELREF(obj) == 0)) {
		zend_objects_store_del(obj);
	}

	return found && !EG(exception);
}

/**
 * The same for a literal offset.
 */
static int zephir_array_isset_object_long(zval *fetched, const zval *arr, zend_long index)
{
	zval offset;

	ZVAL_LONG(&offset, index);

	return zephir_array_isset_object(fetched, arr, &offset);
}

static int zephir_array_isset_object_string(zval *fetched, const zval *arr, const char *index, uint32_t index_length)
{
	zval offset;
	int found;

	ZVAL_STRINGL(&offset, index, index_length);
	found = zephir_array_isset_object(fetched, arr, &offset);
	zval_ptr_dtor(&offset);

	return found;
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
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT)) {
		return zephir_array_isset_object(fetched, arr, index);
	} else if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		ZVAL_NULL(fetched);

		return 0;
	}

	h      = Z_ARRVAL_P(arr);
	result = zephir_array_isset_find(h, index);

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
		if ((zv = zend_symtable_str_find(Z_ARRVAL_P(arr), index, index_length)) != NULL) {
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

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT)) {
		return zephir_array_isset_object_string(fetched, arr, index, index_length);
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

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT)) {
		return zephir_array_isset_object_long(fetched, arr, index);
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

#ifdef ZEPHIR_BUFFER_ENABLED
	if (UNEXPECTED(zephir_is_buffer(arr))) {
		return zephir_buffer_dim_isset(arr, index);
	}
#endif

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
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT)) {
		return zephir_array_isset_object(NULL, arr, index);
	} else if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		return 0;
	}

	h = Z_ARRVAL_P(arr);

	return zephir_array_isset_find(h, index) != NULL;
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
		return zend_symtable_str_exists(Z_ARRVAL_P(arr), index, index_length);
	} else if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zval offset;
		int  found;

		ZVAL_STRINGL(&offset, index, index_length);
		found = zephir_string_offset_isset_zval(arr, &offset);
		zval_ptr_dtor(&offset);

		return found;
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT)) {
		return zephir_array_isset_object_string(NULL, arr, index, index_length);
	}

	return 0;
}

int ZEPHIR_FASTCALL zephir_array_isset_long(const zval *arr, zend_long index)
{
#ifdef ZEPHIR_BUFFER_ENABLED
	if (UNEXPECTED(zephir_is_buffer(arr))) {
		return zephir_buffer_dim_isset_long(arr, index);
	}
#endif

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

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT)) {
		return zephir_array_isset_object_long(NULL, arr, index);
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

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT)) {
		return zephir_array_isset_object(NULL, arr, index);
	}

	if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		return 0;
	}

	entry = zephir_array_isset_find(Z_ARRVAL_P(arr), index);
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

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT)) {
		return zephir_array_isset_object_string(NULL, arr, index, index_length);
	}

	if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		return 0;
	}

	entry = zend_symtable_str_find(Z_ARRVAL_P(arr), index, index_length);
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

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT)) {
		return zephir_array_isset_object_long(NULL, arr, index);
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
 * dedicated handler (`zend_isempty_dim_slow`) that reports nothing for a
 * missing key or an out-of-range string offset and answers "empty" for them,
 * while an array offset is converted as isset converts it, so an illegal one
 * throws. Reusing the isset-fetch helpers gets the same answer for arrays,
 * strings and ArrayAccess alike.
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

/**
 * Reports the container errors PHP's ZEND_UNSET_DIM reports, in its order.
 *
 * Zend/zend_vm_def.h: an object without array access and a string are errors on
 * every version, and from PHP 8.1 so is any other non-null scalar; `false` is
 * deprecated there, while null and undefined stay silent everywhere. PHP 8.0
 * has neither the scalar branch nor zend_false_to_array_deprecated(), so both
 * are gated rather than back-ported.
 *
 * The caller has already established that the container is not an array and is
 * not something it can handle itself.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2702
 */
static void zephir_unset_dim_illegal_container(zval *arr)
{
	if (Z_TYPE_P(arr) == IS_OBJECT) {
		zend_throw_error(NULL, "Cannot use object of type %s as array", ZSTR_VAL(Z_OBJCE_P(arr)->name));

		return;
	}

	if (Z_TYPE_P(arr) == IS_STRING) {
		zend_throw_error(NULL, "Cannot unset string offsets");

		return;
	}

#if PHP_VERSION_ID >= 80100
	if (Z_TYPE_P(arr) > IS_FALSE) {
		zend_throw_error(NULL, "Cannot unset offset in a non-array variable");
	} else if (Z_TYPE_P(arr) == IS_FALSE) {
		zend_false_to_array_deprecated();
	}
#endif
}

int ZEPHIR_FASTCALL zephir_array_unset(zval *arr, zval *index, int flags)
{
	HashTable *ht;
	zend_ulong hval;
	zend_string *key;

	/* PHP follows the reference before it looks at the container. */
	ZVAL_DEREF(arr);

	if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		if (Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess)) {
			zend_long ZEPHIR_LAST_CALL_STATUS;
			ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, arr, "offsetunset", NULL, 0, index);
			if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
				return 1;
			}

			return 0;
		}

		zephir_unset_dim_illegal_container(arr);

		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ARRAY(arr);
	}

	ht = Z_ARRVAL_P(arr);

	switch (zephir_array_offset_key(ht, index, BP_VAR_UNSET, &hval, &key)) {
		case IS_LONG:
			return (zend_hash_index_del(ht, hval) == SUCCESS);

		case IS_STRING:
			return (zend_hash_del(ht, key) == SUCCESS);

		default:
			return 0;
	}
}

int ZEPHIR_FASTCALL zephir_array_unset_string(zval *arr, const char *index, uint32_t index_length, int flags)
{
	ZVAL_DEREF(arr);

	if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		if (Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess)) {
			zend_long ZEPHIR_LAST_CALL_STATUS;
			zval offset;
			ZVAL_STRINGL(&offset, index, index_length);
			ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, arr, "offsetunset", NULL, 0, &offset);
			zval_ptr_dtor(&offset);
			if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
				return 1;
			}

			return 0;
		}

		zephir_unset_dim_illegal_container(arr);

		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL(arr);
	}

	return zend_symtable_str_del(Z_ARRVAL_P(arr), index, index_length);
}

int ZEPHIR_FASTCALL zephir_array_unset_long(zval *arr, zend_long index, int flags)
{
	ZVAL_DEREF(arr);

	if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		if (Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_arrayaccess)) {
			zend_long ZEPHIR_LAST_CALL_STATUS;
			zval offset;
			ZVAL_LONG(&offset, index);
			ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, arr, "offsetunset", NULL, 0, &offset);

			if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
				return 1;
			}

			return 0;
		}

		zephir_unset_dim_illegal_container(arr);

		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ARRAY(arr);
	}

	return zend_hash_index_del(Z_ARRVAL_P(arr), (zend_ulong) index);
}

/**
 * The element an intermediate offset of an unset names, or NULL when there is
 * none. `ZEND_FETCH_DIM_UNSET` converts the offset as a write does.
 */
static zval *zephir_array_unset_find(HashTable *ht, zval *index)
{
	zend_ulong hval;
	zend_string *key;

	switch (zephir_array_offset_key(ht, index, BP_VAR_W, &hval, &key)) {
		case IS_LONG:
			return zend_hash_index_find(ht, hval);

		case IS_STRING:
			return zend_hash_find(ht, key);

		default:
			return NULL;
	}
}

/**
 * The string branch of `ZEND_FETCH_DIM_UNSET`: never a container, but the
 * offset is checked first. The error for a valid offset changed in PHP 8.2
 * (zend_wrong_string_offset_error()), the one for an invalid offset in 8.3
 * (zend_illegal_container_offset()).
 */
static void zephir_array_unset_fetch_string_error(zval *index)
{
	zend_long offset;
	bool trailing_data = false;

	ZVAL_DEREF(index);

	if (Z_TYPE_P(index) == IS_DOUBLE || Z_TYPE_P(index) <= IS_TRUE) {
		zend_error(E_WARNING, "String offset cast occurred");
	} else if (Z_TYPE_P(index) != IS_LONG
		&& (Z_TYPE_P(index) != IS_STRING
			|| IS_LONG != is_numeric_string_ex(Z_STRVAL_P(index), Z_STRLEN_P(index), &offset, NULL, true, NULL, &trailing_data))
	) {
#if PHP_VERSION_ID >= 80300
		zend_illegal_container_offset(ZSTR_KNOWN(ZEND_STR_STRING), index, BP_VAR_UNSET);
#else
		zend_type_error("Cannot access offset of type %s on string", zend_zval_type_name(index));
#endif
		return;
	}

	if (EG(exception)) {
		return;
	}

	/* 8.2 named the error after the fetch, not after the unset after it. */
#if PHP_VERSION_ID >= 80200
	zend_throw_error(NULL, "Cannot use string offset as an array");
#else
	zend_throw_error(NULL, "Cannot unset string offsets");
#endif
}

/**
 * One `ZEND_FETCH_DIM_UNSET`: the element of `container` an unset goes on
 * through, or NULL when the unset stops here. Unlike a write fetch it never
 * creates the element, and unlike a read it separates the array it passes, so
 * the final unset lands in the container rather than in a copy.
 *
 * An ArrayAccess object hands back what offsetGet() built, which `holder`
 * keeps alive until the whole unset is done.
 */
static zval *zephir_array_unset_fetch(zval *container, zval *index, zval *holder)
{
	zval rv, *retval;
	zend_object *obj;

	ZVAL_DEREF(container);

	if (EXPECTED(Z_TYPE_P(container) == IS_ARRAY)) {
		SEPARATE_ARRAY(container);

		return zephir_array_unset_find(Z_ARRVAL_P(container), index);
	}

	if (Z_TYPE_P(container) == IS_STRING) {
		zephir_array_unset_fetch_string_error(index);

		return NULL;
	}

	if (Z_TYPE_P(container) == IS_OBJECT) {
		obj = Z_OBJ_P(container);

		ZVAL_UNDEF(&rv);
		GC_ADDREF(obj);
		retval = obj->handlers->read_dimension(obj, index, BP_VAR_UNSET, &rv);

		if (UNEXPECTED(retval == &EG(uninitialized_zval))) {
			zend_error(E_NOTICE, "Indirect modification of overloaded element of %s has no effect", ZSTR_VAL(obj->ce->name));
			retval = NULL;
		} else if (EXPECTED(retval != NULL && Z_TYPE_P(retval) != IS_UNDEF)) {
			if (!Z_ISREF_P(retval) && Z_TYPE_P(retval) != IS_OBJECT) {
				zend_error(E_NOTICE, "Indirect modification of overloaded element of %s has no effect", ZSTR_VAL(obj->ce->name));
			}

			zval_ptr_dtor(holder);

			if (retval == &rv) {
				ZVAL_COPY_VALUE(holder, &rv);
			} else {
				ZVAL_COPY(holder, retval);
			}

			retval = holder;
		} else {
			retval = NULL;
		}

		if (UNEXPECTED(GC_DELREF(obj) == 0)) {
			zend_objects_store_del(obj);
		}

		return retval;
	}

	if (Z_TYPE_P(container) <= IS_FALSE) {
#if PHP_VERSION_ID >= 80100
		if (Z_TYPE_P(container) == IS_FALSE) {
			zend_false_to_array_deprecated();
		}
#endif
		return NULL;
	}

	zend_throw_error(NULL, "Cannot unset offset in a non-array variable");

	return NULL;
}

/**
 * `unset container[k1][k2]...[kn]`: PHP's chain of `ZEND_FETCH_DIM_UNSET`
 * ending in `ZEND_UNSET_DIM`. `container` is the slot itself, a local or a
 * property, never a copy of it.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2705
 */
void zephir_array_unset_path(zval *container, uint32_t count, zval **keys)
{
	zval holder;
	zval *current = container;
	uint32_t i;

	/* The container's own fetch threw, and PHP does not go on past it. */
	if (UNEXPECTED(EG(exception))) {
		return;
	}

	ZVAL_UNDEF(&holder);

	for (i = 0; i + 1 < count && current != NULL; i++) {
		current = zephir_array_unset_fetch(current, keys[i], &holder);
	}

	if (current != NULL && !EG(exception)) {
		zephir_array_unset(current, keys[count - 1], PH_SEPARATE);
	}

	zval_ptr_dtor(&holder);
}

/**
 * `arr[] = value`. The value is copied in whatever the flags say.
 */
int zephir_array_append(zval *arr, zval *value, int flags ZEPHIR_DEBUG_PARAMS)
{
	return zephir_array_dim_assign(arr, NULL, value, (flags & PH_SEPARATE) == PH_SEPARATE);
}

/**
 * The engine context a fetch runs in: BP_VAR_W for a write context, BP_VAR_R
 * for a read that reports, BP_VAR_IS for one that does not.
 */
static int zephir_array_fetch_type(int flags)
{
	if ((flags & PH_WRITE) == PH_WRITE) {
		return BP_VAR_W;
	}

	return (flags & PH_NOISY) == PH_NOISY ? BP_VAR_R : BP_VAR_IS;
}

/**
 * A string key of a table that may hold IS_INDIRECT slots, the way
 * `zend_fetch_dimension_address_inner()` looks one up.
 */
static zval *zephir_array_find_key(HashTable *ht, zend_string *key)
{
	zval *zv = zend_hash_find(ht, key);

	if (zv != NULL && UNEXPECTED(Z_TYPE_P(zv) == IS_INDIRECT)) {
		zv = Z_INDIRECT_P(zv);

		return Z_TYPE_P(zv) == IS_UNDEF ? NULL : zv;
	}

	return zv;
}

/**
 * Reads an offset of anything that is neither an array, a string nor an
 * ArrayAccess object, as `zend_fetch_dimension_address_read()` does.
 *
 * An object is read through its own read_dimension() handler, which is what
 * makes a SimpleXMLElement attribute readable and an object with no dimension
 * support throw "Cannot use object of type %s as array". Whatever it returns
 * is handed over owned. A write context on it gets PHP's notice that the
 * write cannot reach the object.
 *
 * Anything else holds no offsets: a read warns and yields null, and a write
 * context throws, as `zend_fetch_dimension_address()` does for a scalar.
 */
static int zephir_array_fetch_other(zval *return_value, zval *arr, zval *dim, int flags)
{
	const int type = zephir_array_fetch_type(flags);

	if (Z_TYPE_P(arr) == IS_OBJECT) {
		zend_object *obj = Z_OBJ_P(arr);
		zval rv;
		zval *res;

		ZVAL_UNDEF(&rv);
		GC_ADDREF(obj);
		res = obj->handlers->read_dimension(obj, dim, type, &rv);

		if (res == NULL || Z_TYPE_P(res) == IS_UNDEF) {
			ZVAL_NULL(return_value);
		} else if (res == &rv) {
			ZVAL_COPY_VALUE(return_value, &rv);
		} else if (type == BP_VAR_W) {
			ZVAL_COPY(return_value, res);
		} else {
			ZVAL_COPY_DEREF(return_value, res);
		}

		if (type == BP_VAR_W && res != NULL && !EG(exception)) {
			zephir_array_fetch_overloaded_notice(arr, return_value);
		}

		if (UNEXPECTED(GC_DELREF(obj) == 0)) {
			zend_objects_store_del(obj);
		}

		return EG(exception) ? FAILURE : SUCCESS;
	}

	if (type == BP_VAR_W) {
		zend_throw_error(NULL, "Cannot use a scalar value as an array");
	} else if (type == BP_VAR_R) {
#if PHP_VERSION_ID >= 80300
		zend_error(E_WARNING, "Trying to access array offset on %s", zend_zval_value_name(arr));
#else
		zend_error(E_WARNING, "Trying to access array offset on value of type %s", zend_zval_type_name(arr));
#endif
	}

	ZVAL_NULL(return_value);

	return FAILURE;
}

/**
 * Reads `arr[index]`, PHP's `ZEND_FETCH_DIM_R`, or the write context of
 * kernel/array.h when PH_WRITE is set.
 *
 * The diagnostics are PHP 8's. A missing key is the warning
 * `Undefined array key`, a null or scalar container the warning
 * `Trying to access array offset on ...`, and the offset is converted by
 * zephir_array_offset_key() with PHP's own deprecations and TypeError. Only a
 * PH_NOISY read reports; a write context creates the element instead.
 */
int zephir_array_fetch(zval *return_value, zval *arr, zval *index, int flags ZEPHIR_DEBUG_PARAMS)
{
	zval *zv = NULL;
	HashTable *ht;
	zend_ulong hval;
	zend_string *key;

	if ((flags & PH_WRITE) == PH_WRITE) {
		arr = zephir_array_write_container(arr);
		if (UNEXPECTED(arr == NULL)) {
			ZVAL_NULL(return_value);

			return FAILURE;
		}
	} else {
		ZVAL_DEREF(arr);
	}

#ifdef ZEPHIR_BUFFER_ENABLED
	if (UNEXPECTED(zephir_is_buffer(arr)) && (flags & PH_WRITE) != PH_WRITE) {
		return zephir_buffer_dim_read(return_value, arr, index);
	}
#endif

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
	}

	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		ht = Z_ARRVAL_P(arr);

		switch (zephir_array_offset_key(ht, index, zephir_array_fetch_type(flags), &hval, &key)) {
			case IS_LONG:
				zv = zend_hash_index_find(ht, hval);
				if (zv == NULL && (flags & PH_WRITE) == PH_WRITE) {
					zv = zephir_array_write_create_index(ht, hval);
				}
				if (zv == NULL && (flags & PH_NOISY) == PH_NOISY) {
					zephir_array_undefined_index(hval);
				}
				break;

			case IS_STRING:
				zv = zephir_array_find_key(ht, key);
				if (zv == NULL && (flags & PH_WRITE) == PH_WRITE) {
					zv = zephir_array_write_create_symtable(ht, ZSTR_VAL(key), ZSTR_LEN(key));
				}
				if (zv == NULL && (flags & PH_NOISY) == PH_NOISY) {
					zephir_array_undefined_key(key);
				}
				break;
		}

		if (zv != NULL) {
			zephir_array_fetch_found(return_value, zv, flags);

			return SUCCESS;
		}

		ZVAL_NULL(return_value);

		return FAILURE;
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zephir_string_offset_read_zval(return_value, arr, index, flags);

		return EG(exception) ? FAILURE : SUCCESS;
	}

	return zephir_array_fetch_other(return_value, arr, index, flags);
}

int zephir_array_fetch_string(zval *return_value, zval *arr, const char *index, uint32_t index_length, int flags ZEPHIR_DEBUG_PARAMS)
{
	zval *zv;

	if ((flags & PH_WRITE) == PH_WRITE) {
		arr = zephir_array_write_container(arr);
		if (UNEXPECTED(arr == NULL)) {
			ZVAL_NULL(return_value);

			return FAILURE;
		}
	} else {
		ZVAL_DEREF(arr);
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
	}

	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		zend_ulong hval;

		if ((zv = zend_symtable_str_find(Z_ARRVAL_P(arr), index, index_length)) == NULL
			&& (flags & PH_WRITE) == PH_WRITE) {
			zv = zephir_array_write_create_symtable(Z_ARRVAL_P(arr), index, index_length);
		}

		if (zv != NULL) {
			zephir_array_fetch_found(return_value, zv, flags);

			return SUCCESS;
		}

		/* A numeric string is the integer key, and PHP names it as one. */
		if ((flags & PH_NOISY) == PH_NOISY) {
			if (ZEND_HANDLE_NUMERIC_STR(index, index_length, hval)) {
				zephir_array_undefined_index(hval);
			} else {
				zend_error(E_WARNING, "Undefined array key \"%.*s\"", (int) index_length, index);
			}
		}

		ZVAL_NULL(return_value);

		return FAILURE;
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		zval offset;

		ZVAL_STRINGL(&offset, index, index_length);
		zephir_string_offset_read_zval(return_value, arr, &offset, flags);
		zval_ptr_dtor(&offset);

		return EG(exception) ? FAILURE : SUCCESS;
	}

	{
		zval offset;
		int status;

		ZVAL_STRINGL(&offset, index, index_length);
		status = zephir_array_fetch_other(return_value, arr, &offset, flags);
		zval_ptr_dtor(&offset);

		return status;
	}
}

int zephir_array_fetch_long(zval *return_value, zval *arr, zend_long index, int flags ZEPHIR_DEBUG_PARAMS)
{
	zval *zv;

	if ((flags & PH_WRITE) == PH_WRITE) {
		arr = zephir_array_write_container(arr);
		if (UNEXPECTED(arr == NULL)) {
			ZVAL_NULL(return_value);

			return FAILURE;
		}
	} else {
		ZVAL_DEREF(arr);
	}

#ifdef ZEPHIR_BUFFER_ENABLED
	/* A <Ns>\Buffer element is a raw C scalar: one class-entry pointer compare
	 * and a direct load, instead of an offsetGet() call. A write-context fetch
	 * deliberately falls through to the ArrayAccess path below, so the engine
	 * still reports the element as unmodifiable. */
	if (UNEXPECTED(zephir_is_buffer(arr)) && (flags & PH_WRITE) != PH_WRITE) {
		return zephir_buffer_dim_read_long(return_value, arr, index);
	}
#endif

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
	}

	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		if ((zv = zend_hash_index_find(Z_ARRVAL_P(arr), (zend_ulong) index)) == NULL
			&& (flags & PH_WRITE) == PH_WRITE) {
			zv = zephir_array_write_create_index(Z_ARRVAL_P(arr), (zend_ulong) index);
		}

		if (zv != NULL) {
			zephir_array_fetch_found(return_value, zv, flags);

			return SUCCESS;
		}

		if ((flags & PH_NOISY) == PH_NOISY) {
			zephir_array_undefined_index((zend_ulong) index);
		}

		ZVAL_NULL(return_value);

		return FAILURE;
	}

	if (UNEXPECTED(Z_TYPE_P(arr) == IS_STRING)) {
		/* The compiler cannot prove a `var` holds a string, so the string
		 * offset is dispatched here. */
		zephir_string_offset_read(return_value, arr, index, flags);

		return SUCCESS;
	}

	{
		zval offset;

		ZVAL_LONG(&offset, index);

		return zephir_array_fetch_other(return_value, arr, &offset, flags);
	}
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

/**
 * Settles the ownership the update flags describe once the value is stored.
 *
 * The store copied the value in. PH_COPY means the caller keeps its own
 * reference; without it the caller handed one over, which is released here.
 * PH_CTOR stored a duplicate, which is released either way.
 */
static void zephir_array_update_settle(zval *value, int flags, zval *dup)
{
	if ((flags & PH_CTOR) == PH_CTOR) {
		zval_ptr_dtor(dup);
	} else if ((flags & PH_COPY) != PH_COPY) {
		zval_ptr_dtor(value);
	}
}

/**
 * The element slot of a plain array for the fast paths below, created as null
 * when missing. A symbol table hands out IS_INDIRECT slots.
 */
static zval *zephir_array_update_slot(zval *found)
{
	if (UNEXPECTED(Z_TYPE_P(found) == IS_INDIRECT)) {
		found = Z_INDIRECT_P(found);
		if (Z_TYPE_P(found) == IS_UNDEF) {
			ZVAL_NULL(found);
		}
	}

	return found;
}

/**
 * `arr[index] = value`, PHP's ZEND_ASSIGN_DIM. See zephir_array_dim_assign()
 * for every container but a <Ns>\Buffer.
 */
int zephir_array_update_zval(zval *arr, zval *index, zval *value, int flags)
{
	zval dup;
	int status;

#ifdef ZEPHIR_BUFFER_ENABLED
	if (UNEXPECTED(zephir_is_buffer(arr))) {
		return zephir_buffer_dim_write(arr, index, value);
	}
#endif

	if ((flags & PH_CTOR) == PH_CTOR) {
		ZVAL_DUP(&dup, value);
	}

	status = zephir_array_dim_assign(arr, index, (flags & PH_CTOR) == PH_CTOR ? &dup : value, (flags & PH_SEPARATE) == PH_SEPARATE);
	zephir_array_update_settle(value, flags, &dup);

	return status;
}

int zephir_array_update_string(zval *arr, const char *index, uint32_t index_length, zval *value, int flags)
{
	zval dup, offset;
	zval *stored = value, *slot;
	int status;

	if ((flags & PH_CTOR) == PH_CTOR) {
		ZVAL_DUP(&dup, value);
		stored = &dup;
	}

	/* The common case, a plain array, without building a key zval. A numeric
	 * string is the integer key, as zend_symtable_* makes it. */
	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		if ((flags & PH_SEPARATE) == PH_SEPARATE) {
			SEPARATE_ARRAY(arr);
		}

		slot = zend_symtable_str_find(Z_ARRVAL_P(arr), index, index_length);
		slot = slot != NULL
			? zephir_array_update_slot(slot)
			: zend_symtable_str_update(Z_ARRVAL_P(arr), index, index_length, &EG(uninitialized_zval));

		zephir_array_assign_value(slot, stored);
		zephir_array_update_settle(value, flags, &dup);

		return SUCCESS;
	}

	ZVAL_STRINGL(&offset, index, index_length);
	status = zephir_array_dim_assign(arr, &offset, stored, (flags & PH_SEPARATE) == PH_SEPARATE);
	zval_ptr_dtor(&offset);
	zephir_array_update_settle(value, flags, &dup);

	return status;
}

int zephir_array_update_long(zval *arr, zend_long index, zval *value, int flags ZEPHIR_DEBUG_PARAMS)
{
	zval dup, offset;
	zval *stored = value, *slot;
	int status;

#ifdef ZEPHIR_BUFFER_ENABLED
	if (UNEXPECTED(zephir_is_buffer(arr))) {
		return zephir_buffer_dim_write_long(arr, index, value);
	}
#endif

	if ((flags & PH_CTOR) == PH_CTOR) {
		ZVAL_DUP(&dup, value);
		stored = &dup;
	}

	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		if ((flags & PH_SEPARATE) == PH_SEPARATE) {
			SEPARATE_ARRAY(arr);
		}

		slot = zend_hash_index_find(Z_ARRVAL_P(arr), (zend_ulong) index);
		if (slot == NULL) {
			slot = zend_hash_index_add_new(Z_ARRVAL_P(arr), (zend_ulong) index, &EG(uninitialized_zval));
		}

		zephir_array_assign_value(slot, stored);
		zephir_array_update_settle(value, flags, &dup);

		return SUCCESS;
	}

	ZVAL_LONG(&offset, index);
	status = zephir_array_dim_assign(arr, &offset, stored, (flags & PH_SEPARATE) == PH_SEPARATE);
	zephir_array_update_settle(value, flags, &dup);

	return status;
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

/**
 * array_key_exists(), `PHP_FUNCTION(array_key_exists)` (ext/standard/array.c).
 *
 * The messages are spelled out because zend_argument_type_error() would name
 * the Zephir method being executed rather than array_key_exists().
 */
int zephir_array_key_exists(zval *arr, zval *key)
{
	HashTable *ht;

	ZVAL_DEREF(arr);
	ZVAL_DEREF(key);

	if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		zend_type_error("array_key_exists(): Argument #2 ($array) must be of type array, %s given",
#if PHP_VERSION_ID >= 80300
			zend_zval_value_name(arr)
#else
			zend_zval_type_name(arr)
#endif
		);
		return 0;
	}

	ht = Z_ARRVAL_P(arr);

	switch (Z_TYPE_P(key)) {
		case IS_STRING:
			return zend_symtable_exists(ht, Z_STR_P(key));

		case IS_LONG:
			return zend_hash_index_exists(ht, Z_LVAL_P(key));

		case IS_NULL:
#if PHP_VERSION_ID >= 80500
			zend_error(E_DEPRECATED, "Using null as the key parameter for array_key_exists() is deprecated, use an empty string instead");
#endif
			return zend_hash_exists(ht, ZSTR_EMPTY_ALLOC());

		case IS_DOUBLE:
#if PHP_VERSION_ID >= 80100
			return zend_hash_index_exists(ht, zend_dval_to_lval_safe(Z_DVAL_P(key)));
#else
			return zend_hash_index_exists(ht, zend_dval_to_lval(Z_DVAL_P(key)));
#endif

		case IS_FALSE:
			return zend_hash_index_exists(ht, 0);

		case IS_TRUE:
			return zend_hash_index_exists(ht, 1);

		case IS_RESOURCE:
			zend_error(E_WARNING, "Resource ID#" ZEND_LONG_FMT " used as offset, casting to integer (" ZEND_LONG_FMT ")",
				(zend_long) Z_RES_HANDLE_P(key), (zend_long) Z_RES_HANDLE_P(key));
			return zend_hash_index_exists(ht, Z_RES_HANDLE_P(key));

		default:
			zend_type_error("array_key_exists(): Argument #1 ($key) must be a valid array offset type");
			return 0;
	}
}

/**
 * Multiple array-offset update, `a[x][y][] = value`.
 *
 * The walk is PHP's: see zephir_array_assign_walk(). It used to be a fatal
 * error for any container that was not already an array, and turned scalars
 * met on the way into arrays.
 */
void zephir_array_update_multi_ex(zval *arr, zval *value, const char *types, int types_length, int types_count, va_list ap)
{
	zephir_array_assign_walk(arr, value, types, types_length, ap);
}

int zephir_array_update_multi(zval *arr, zval *value, const char *types, int types_length, int types_count, ...)
{
	va_list ap;
	int status;

	va_start(ap, types_count);
	status = zephir_array_assign_walk(arr, value, types, types_length, ap);
	va_end(ap);

	return status;
}

/**
 * The element a read-write context reads and then writes.
 *
 * `zend_fetch_dimension_address_inner()` with BP_VAR_RW: the offset is
 * converted as for any write, and a missing element is reported as undefined
 * before it is created as null, because the operator is about to read it.
 */
static zval *zephir_array_rw_slot(HashTable *ht, zval *dim)
{
	zend_ulong hval;
	zend_string *key;
	zval *retval;

	switch (zephir_array_offset_key(ht, dim, BP_VAR_RW, &hval, &key)) {
		case IS_LONG:
			retval = zend_hash_index_find(ht, hval);
			if (EXPECTED(retval != NULL)) {
				return retval;
			}

			zephir_array_rw_hold(ht);
			zephir_array_undefined_index(hval);
			if (zephir_array_rw_release(ht) == FAILURE) {
				return NULL;
			}

			return zend_hash_index_add_new(ht, hval, &EG(uninitialized_zval));

		case IS_STRING:
			retval = zend_hash_find(ht, key);
			if (EXPECTED(retval != NULL)) {
				if (UNEXPECTED(Z_TYPE_P(retval) == IS_INDIRECT)) {
					retval = Z_INDIRECT_P(retval);
					if (UNEXPECTED(Z_TYPE_P(retval) == IS_UNDEF)) {
						zephir_array_rw_hold(ht);
						zephir_array_undefined_key(key);
						if (zephir_array_rw_release(ht) == FAILURE) {
							return NULL;
						}
						ZVAL_NULL(retval);
					}
				}

				return retval;
			}

			/* The key may be released while the warning runs userland code. */
			zend_string_addref(key);
			zephir_array_rw_hold(ht);
			zephir_array_undefined_key(key);
			if (zephir_array_rw_release(ht) == FAILURE) {
				zend_string_release(key);
				return NULL;
			}

			retval = zend_hash_add_new(ht, key, &EG(uninitialized_zval));
			zend_string_release(key);

			return retval;

		default:
			return NULL;
	}
}

/**
 * The element a plain write stores into, `zend_fetch_dimension_address_inner()`
 * with BP_VAR_W: a missing one is created as null without a word, because
 * nothing is about to read it.
 */
static zval *zephir_array_w_slot(HashTable *ht, zval *dim)
{
	zend_ulong hval;
	zend_string *key;
	zval *retval;

	switch (zephir_array_offset_key(ht, dim, BP_VAR_W, &hval, &key)) {
		case IS_LONG:
			retval = zend_hash_index_find(ht, hval);

			return retval != NULL ? retval : zend_hash_index_add_new(ht, hval, &EG(uninitialized_zval));

		case IS_STRING:
			retval = zend_hash_find(ht, key);
			if (retval == NULL) {
				return zend_hash_add_new(ht, key, &EG(uninitialized_zval));
			}

			if (UNEXPECTED(Z_TYPE_P(retval) == IS_INDIRECT)) {
				retval = Z_INDIRECT_P(retval);
				if (Z_TYPE_P(retval) == IS_UNDEF) {
					ZVAL_NULL(retval);
				}
			}

			return retval;

		default:
			return NULL;
	}
}

/**
 * The element of an array container a write context reaches, or the new one
 * `[]` (a NULL `dim`) adds. `type` is BP_VAR_W for a plain write and
 * BP_VAR_RW for a compound assignment, which reads the element first.
 */
static zval *zephir_array_element(HashTable *ht, zval *dim, int type)
{
	zval *retval;

	if (dim != NULL) {
		return type == BP_VAR_RW ? zephir_array_rw_slot(ht, dim) : zephir_array_w_slot(ht, dim);
	}

	retval = zend_hash_next_index_insert(ht, &EG(uninitialized_zval));
	if (UNEXPECTED(retval == NULL)) {
		zend_throw_error(NULL, "Cannot add element to the array as the next element is already occupied");
	}

	return retval;
}

/**
 * An intermediate offset of a write, `ZEND_FETCH_DIM_W`, or of a compound
 * assignment, `ZEND_FETCH_DIM_RW`, as `type` says.
 *
 * Hands back the container the next offset is applied to, or NULL once an
 * error is pending. An ArrayAccess object builds that container in offsetGet()
 * and owns nothing afterwards, so unless it returned a reference or an object
 * the result goes into `holder` and PHP's notice says the write is lost. Same
 * branches as the object case of `zend_fetch_dimension_address()`.
 */
static zval *zephir_array_fetch_dim_w(zval *container, zval *dim, zval *holder, int type)
{
	zend_object *pending = EG(exception);
	zval *retval;

	container = zephir_array_write_container(container);
	if (UNEXPECTED(container == NULL)) {
		return NULL;
	}

	if (EXPECTED(Z_TYPE_P(container) == IS_ARRAY)) {
		/* Turning false into an array is deprecated, and a handler may throw. */
		if (UNEXPECTED(EG(exception) != pending)) {
			return NULL;
		}

		return zephir_array_element(Z_ARRVAL_P(container), dim, type);
	}

	if (Z_TYPE_P(container) == IS_OBJECT) {
		zend_object *obj = Z_OBJ_P(container);

		GC_ADDREF(obj);
		retval = obj->handlers->read_dimension(obj, dim, type, holder);

		if (UNEXPECTED(retval == &EG(uninitialized_zval))) {
			ZVAL_NULL(holder);
			retval = holder;
			zend_error(E_NOTICE, "Indirect modification of overloaded element of %s has no effect", ZSTR_VAL(obj->ce->name));
		} else if (EXPECTED(retval != NULL && Z_TYPE_P(retval) != IS_UNDEF)) {
			if (!Z_ISREF_P(retval)) {
				if (retval != holder) {
					ZVAL_COPY(holder, retval);
					retval = holder;
				}

				if (Z_TYPE_P(retval) != IS_OBJECT) {
					zend_error(E_NOTICE, "Indirect modification of overloaded element of %s has no effect", ZSTR_VAL(obj->ce->name));
				}
			}
		} else {
			retval = NULL;
		}

		if (UNEXPECTED(GC_DELREF(obj) == 0)) {
			zend_objects_store_del(obj);
		}

		return EG(exception) != pending ? NULL : retval;
	}

	if (Z_TYPE_P(container) == IS_STRING) {
		if (dim == NULL) {
			zend_throw_error(NULL, "[] operator not supported for strings");
		} else {
			zephir_string_offset_check(container, dim);
			if (EG(exception) == pending) {
				zend_throw_error(NULL, "Cannot use string offset as an array");
			}
		}

		return NULL;
	}

	zend_throw_error(NULL, "Cannot use a scalar value as an array");

	return NULL;
}

/**
 * Applies the operator to an element in place.
 *
 * An element that is a reference to a typed property keeps that type, so the
 * result is computed aside and checked before it replaces the value, as in
 * `zend_binary_assign_op_typed_ref()`. Zephir code is never `strict_types`.
 */
void zephir_array_apply_op(zval *var_ptr, zval *value, binary_op_type op)
{
	if (UNEXPECTED(Z_ISREF_P(var_ptr))) {
		zend_reference *ref = Z_REF_P(var_ptr);

		var_ptr = Z_REFVAL_P(var_ptr);

		if (UNEXPECTED(ZEND_REF_HAS_TYPE_SOURCES(ref))) {
			zval result;

			if (op(&result, var_ptr, value) == SUCCESS
				&& zend_verify_ref_assignable_zval(ref, &result, 0)) {
				zval_ptr_dtor(var_ptr);
				ZVAL_COPY_VALUE(var_ptr, &result);
			} else {
				zval_ptr_dtor(&result);
			}

			return;
		}
	}

	op(var_ptr, var_ptr, value);
}

/**
 * The last offset of a compound assignment, `ZEND_ASSIGN_DIM_OP` itself.
 *
 * An object is read through read_dimension() and written back through
 * write_dimension(), the two calls `zend_binary_assign_op_obj_dim()` makes.
 */
static void zephir_array_dim_op(zval *container, zval *dim, zval *value, binary_op_type op)
{
	zend_object *pending = EG(exception);
	zval *var_ptr;

	/* ZEND_ASSIGN_DIM_OP alone does not check a typed reference. */
	container = zephir_array_write_container_ex(container, 0);

	if (EXPECTED(Z_TYPE_P(container) == IS_ARRAY)) {
		if (UNEXPECTED(EG(exception) != pending)) {
			return;
		}

		var_ptr = zephir_array_element(Z_ARRVAL_P(container), dim, BP_VAR_RW);
		if (EXPECTED(var_ptr != NULL)) {
			zephir_array_apply_op(var_ptr, value, op);
		}

		return;
	}

	if (Z_TYPE_P(container) == IS_OBJECT) {
		zend_object *obj = Z_OBJ_P(container);
		zval rv, result;
		zval *z;

		GC_ADDREF(obj);
		ZVAL_UNDEF(&rv);

		z = obj->handlers->read_dimension(obj, dim, BP_VAR_R, &rv);
		if (z != NULL) {
			if (op(&result, z, value) == SUCCESS) {
				obj->handlers->write_dimension(obj, dim, &result);
			}
			if (z == &rv) {
				zval_ptr_dtor(&rv);
			}
			zval_ptr_dtor(&result);
		} else {
#if PHP_VERSION_ID >= 80200
			zend_throw_error(NULL, "Cannot use object of type %s as array", ZSTR_VAL(obj->ce->name));
#else
			zend_throw_error(NULL, "Cannot use object as array");
#endif
		}

		if (UNEXPECTED(GC_DELREF(obj) == 0)) {
			zend_objects_store_del(obj);
		}

		return;
	}

	if (Z_TYPE_P(container) == IS_STRING) {
		if (dim == NULL) {
			zend_throw_error(NULL, "[] operator not supported for strings");
		} else {
			zephir_string_offset_check(container, dim);
			if (EG(exception) == pending) {
				zend_throw_error(NULL, "Cannot use assign-op operators with string offsets");
			}
		}

		return;
	}

	zend_throw_error(NULL, "Cannot use a scalar value as an array");
}

/**
 * `container[o1]...[oN] OP= value`, PHP's ZEND_ASSIGN_DIM_OP.
 *
 * Reading the element, applying the operator and writing the result back is
 * one operation, never a plain update with the right-hand side: every offset
 * but the last is fetched read-write, so a missing one warns before it reads
 * as null, and null or false containers become arrays on the way. `op` is the
 * engine's own operator function, so its result, its TypeError and its
 * DivisionByZeroError are PHP's.
 *
 * `value` is held for the duration: the compiler may hand over a borrowed read
 * of the very element being modified, which an in-place `.=` would otherwise
 * free under itself.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2747
 */
void zephir_array_assign_op(zval *container, zval *value, binary_op_type op, const char *types, int types_length, int types_count, ...)
{
	va_list ap;
	zval operand, offset;
	zval *holders = NULL, *dim;
	int i;

	if (UNEXPECTED(EG(exception))) {
		return;
	}

	if (types_length > 1) {
		holders = safe_emalloc(types_length - 1, sizeof(zval), 0);
		for (i = 0; i < types_length - 1; ++i) {
			ZVAL_UNDEF(&holders[i]);
		}
	}

	ZVAL_COPY(&operand, value);
	va_start(ap, types_count);

	for (i = 0; i < types_length && container != NULL; ++i) {
		ZVAL_UNDEF(&offset);

		switch (types[i]) {
			case 's': {
				const char *s = va_arg(ap, const char *);
				size_t l      = va_arg(ap, size_t);

				ZVAL_STRINGL(&offset, s, l);
				dim = &offset;
				break;
			}

			case 'l':
				ZVAL_LONG(&offset, va_arg(ap, zend_long));
				dim = &offset;
				break;

			case 'z':
				dim = va_arg(ap, zval *);
				break;

			default:
				dim = NULL;
				break;
		}

		if (i == types_length - 1) {
			zephir_array_dim_op(container, dim, &operand, op);
		} else {
			container = zephir_array_fetch_dim_w(container, dim, &holders[i], BP_VAR_RW);
		}

		zval_ptr_dtor(&offset);
	}

	va_end(ap);
	zval_ptr_dtor(&operand);

	if (holders != NULL) {
		for (i = 0; i < types_length - 1; ++i) {
			zval_ptr_dtor(&holders[i]);
		}
		efree(holders);
	}
}

/**
 * Stores `value` in an element slot, as `zend_assign_to_variable()` does.
 *
 * An element that is a reference is written through, so the variable it is
 * bound to sees the new value, and one bound to a typed property is checked
 * against that type first. The old value is released only once the slot
 * holds the new one, because its destructor may run userland code.
 */
void zephir_array_assign_value(zval *slot, zval *value)
{
	zval garbage;

	if (UNEXPECTED(Z_ISREF_P(slot))) {
		zend_reference *ref = Z_REF_P(slot);

		if (UNEXPECTED(ZEND_REF_HAS_TYPE_SOURCES(ref))) {
			zval copy;

			/* zend_try_assign_typed_ref() consumes the copy either way. */
			ZVAL_COPY_DEREF(&copy, value);
			zend_try_assign_typed_ref(ref, &copy);

			return;
		}

		slot = Z_REFVAL_P(slot);
	}

	ZVAL_COPY_VALUE(&garbage, slot);
	ZVAL_COPY_DEREF(slot, value);
	zval_ptr_dtor(&garbage);
}

/**
 * The last offset of a plain write, `ZEND_ASSIGN_DIM`: `container[dim] = value`,
 * or `container[] = value` for a NULL `dim`.
 *
 * Null and false become arrays (false deprecated since 8.1), an object is
 * written through its own write_dimension() handler, which is offsetSet() for
 * ArrayAccess and "Cannot use object of type %s as array" for anything else,
 * and a string takes a byte. Any other value throws, as PHP does. The value is
 * copied in; the caller keeps its own reference.
 *
 * `separate` is false only for a container the caller just created, which
 * nobody else can be holding.
 */
static int zephir_array_dim_assign(zval *container, zval *dim, zval *value, int separate)
{
	zend_object *pending = EG(exception);
	zval *slot;

	if (separate || Z_TYPE_P(Z_ISREF_P(container) ? Z_REFVAL_P(container) : container) <= IS_FALSE) {
		container = zephir_array_write_container(container);
		if (UNEXPECTED(container == NULL)) {
			return FAILURE;
		}
	} else {
		ZVAL_DEREF(container);
	}

	if (EXPECTED(Z_TYPE_P(container) == IS_ARRAY)) {
		/* Turning false into an array is deprecated, and a handler may throw. */
		if (UNEXPECTED(EG(exception) != pending)) {
			return FAILURE;
		}

		slot = zephir_array_element(Z_ARRVAL_P(container), dim, BP_VAR_W);
		if (UNEXPECTED(slot == NULL)) {
			return FAILURE;
		}

		zephir_array_assign_value(slot, value);

		return SUCCESS;
	}

	if (Z_TYPE_P(container) == IS_OBJECT) {
		zend_object *obj = Z_OBJ_P(container);

		GC_ADDREF(obj);
		obj->handlers->write_dimension(obj, dim, value);
		if (UNEXPECTED(GC_DELREF(obj) == 0)) {
			zend_objects_store_del(obj);
		}

		return EG(exception) != pending ? FAILURE : SUCCESS;
	}

	if (Z_TYPE_P(container) == IS_STRING) {
		if (dim == NULL) {
			zend_throw_error(NULL, "[] operator not supported for strings");

			return FAILURE;
		}

		zephir_string_offset_write_zval(container, dim, value);

		return EG(exception) != pending ? FAILURE : SUCCESS;
	}

	zend_throw_error(NULL, "Cannot use a scalar value as an array");

	return FAILURE;
}

/**
 * `container[o1]...[oN] = value`: every offset but the last is fetched for
 * writing, `ZEND_FETCH_DIM_W`, which creates a missing element silently, and
 * the last one is assigned. `types` uses the zephir_array_update_multi()
 * encoding, a trailing 'a' being `[]`.
 */
static int zephir_array_assign_walk(zval *container, zval *value, const char *types, int types_length, va_list ap)
{
	zval offset;
	zval *holders = NULL, *dim;
	int i, status = FAILURE;

	if (types_length > 1) {
		holders = safe_emalloc(types_length - 1, sizeof(zval), 0);
		for (i = 0; i < types_length - 1; ++i) {
			ZVAL_UNDEF(&holders[i]);
		}
	}

	for (i = 0; i < types_length && container != NULL; ++i) {
		ZVAL_UNDEF(&offset);

		switch (types[i]) {
			case 's': {
				const char *s = va_arg(ap, const char *);
				size_t l      = va_arg(ap, size_t);

				ZVAL_STRINGL(&offset, s, l);
				dim = &offset;
				break;
			}

			case 'l':
				ZVAL_LONG(&offset, va_arg(ap, zend_long));
				dim = &offset;
				break;

			case 'z':
				dim = va_arg(ap, zval *);
				break;

			default:
				dim = NULL;
				break;
		}

		if (i == types_length - 1) {
			status = zephir_array_dim_assign(container, dim, value, 1);
		} else {
			container = zephir_array_fetch_dim_w(container, dim, &holders[i], BP_VAR_W);
		}

		zval_ptr_dtor(&offset);
	}

	if (holders != NULL) {
		for (i = 0; i < types_length - 1; ++i) {
			zval_ptr_dtor(&holders[i]);
		}
		efree(holders);
	}

	return status;
}

/**
 * `container[dim] = value` for a container slot the caller resolved, such as
 * a property's (see zephir_update_property_array()).
 *
 * @see https://github.com/zephir-lang/zephir/issues/2747
 */
int zephir_array_assign_dim(zval *container, zval *dim, zval *value)
{
	return zephir_array_dim_assign(container, dim, value, 1);
}

/**
 * Fast in_array function
 */
/**
 * in_array() without `strict`, `php_search_array()` (ext/standard/array.c).
 */
int zephir_fast_in_array(zval *value, zval *haystack)
{
	zval *entry;

	ZVAL_DEREF(value);
	ZVAL_DEREF(haystack);

	if (UNEXPECTED(Z_TYPE_P(haystack) != IS_ARRAY)) {
		zend_type_error("in_array(): Argument #2 ($haystack) must be of type array, %s given",
#if PHP_VERSION_ID >= 80300
			zend_zval_value_name(haystack)
#else
			zend_zval_type_name(haystack)
#endif
		);
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
