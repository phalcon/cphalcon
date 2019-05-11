
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Zephir Team (http://www.zephir-lang.com)       |
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "php_ext.h"
#include <ext/standard/php_array.h>
#include <Zend/zend_hash.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/debug.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/backtrace.h"

void ZEPHIR_FASTCALL zephir_create_array(zval *return_value, uint size, int initialize)
{
	uint i;
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

	if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		ZVAL_NULL(fetched);

		return 0;
	}

	h = Z_ARRVAL_P(arr);
	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			result = zend_hash_str_find(h, SL(""));
			break;

		case IS_DOUBLE:
			result = zend_hash_index_find(h, (ulong)Z_DVAL_P(index));
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

int zephir_array_isset_string_fetch(zval *fetched, const zval *arr, char *index, uint index_length, int readonly)
{
	zval *zv;

	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		if ((zv = zend_hash_str_find(Z_ARRVAL_P(arr), index, index_length)) != NULL) {
			zephir_ensure_array(zv);

			if (!readonly) {
				ZVAL_COPY(fetched, zv);
			} else {
				ZVAL_COPY_VALUE(fetched, zv);
			}
			return 1;
		}
	}

	ZVAL_NULL(fetched);

	return 0;
}

int zephir_array_isset_long_fetch(zval *fetched, const zval *arr, unsigned long index, int readonly)
{
	zval *zv;

	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		if ((zv = zend_hash_index_find(Z_ARRVAL_P(arr), index)) != NULL) {
			zephir_ensure_array(zv);

			if (!readonly) {
				ZVAL_COPY(fetched, zv);
			} else {
				ZVAL_COPY_VALUE(fetched, zv);
			}
			return 1;
		}
	}

	ZVAL_NULL(fetched);

	return 0;
}

int ZEPHIR_FASTCALL zephir_array_isset(const zval *arr, zval *index)
{
	HashTable *h;

	if (UNEXPECTED(!arr || Z_TYPE_P(arr) != IS_ARRAY)) {
		return 0;
	}

	h = Z_ARRVAL_P(arr);
	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			return zend_hash_str_exists(h, SL(""));

		case IS_DOUBLE:
			return zend_hash_index_exists(h, (ulong)Z_DVAL_P(index));

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

int ZEPHIR_FASTCALL zephir_array_isset_string(const zval *arr, const char *index, uint index_length)
{
	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		return zend_hash_str_exists(Z_ARRVAL_P(arr), index, index_length);
	}

	return 0;
}

int ZEPHIR_FASTCALL zephir_array_isset_long(const zval *arr, unsigned long index)
{
	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		return zend_hash_index_exists(Z_ARRVAL_P(arr), index);
	}

	return 0;
}

int ZEPHIR_FASTCALL zephir_array_unset(zval *arr, zval *index, int flags)
{
	HashTable *ht;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return FAILURE;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL_IF_NOT_REF(arr);
	}

	ht = Z_ARRVAL_P(arr);

	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			return (zend_hash_str_del(ht, "", 1) == SUCCESS);

		case IS_DOUBLE:
			return (zend_hash_index_del(ht, (ulong)Z_DVAL_P(index)) == SUCCESS);

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
			zend_error(E_WARNING, "Illegal offset type");
			return 0;
	}
}

int ZEPHIR_FASTCALL zephir_array_unset_string(zval *arr, const char *index, uint index_length, int flags)
{
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL_IF_NOT_REF(arr);
	}

	return zend_hash_str_del(Z_ARRVAL_P(arr), index, index_length);
}

int ZEPHIR_FASTCALL zephir_array_unset_long(zval *arr, unsigned long index, int flags)
{
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL_IF_NOT_REF(arr);
	}

	return zend_hash_index_del(Z_ARRVAL_P(arr), index);
}

int zephir_array_append(zval *arr, zval *value, int flags ZEPHIR_DEBUG_PARAMS)
{
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		zend_error(E_WARNING, "Cannot use a scalar value as an array in %s on line %d", file, line);
		return FAILURE;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL_IF_NOT_REF(arr);
	}

	Z_TRY_ADDREF_P(value);
	return add_next_index_zval(arr, value);
}

int zephir_array_fetch(zval *return_value, zval *arr, zval *index, int flags ZEPHIR_DEBUG_PARAMS)
{
	zval *zv;
	HashTable *ht;
	int result = SUCCESS, found = 0;
	ulong uidx = 0;
	char *sidx = NULL;

	if (Z_TYPE_P(arr) == IS_ARRAY) {
		ht = Z_ARRVAL_P(arr);
		switch (Z_TYPE_P(index)) {
			case IS_NULL:
				found = (zv = zend_hash_str_find(ht, SL(""))) != NULL;
				sidx   = "";
				break;

			case IS_DOUBLE:
				uidx   = (ulong)Z_DVAL_P(index);
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
				sidx   = Z_STRLEN_P(index) ? Z_STRVAL_P(index) : "";
				found  = (zv = zend_symtable_str_find(ht, Z_STRVAL_P(index), Z_STRLEN_P(index))) != NULL;
				break;

			default:
				if ((flags & PH_NOISY) == PH_NOISY) {
					zend_error(E_WARNING, "Illegal offset type in %s on line %d", file, line);
				}
				result = FAILURE;
				break;
		}

		if (result != FAILURE && found == 1) {
			if ((flags & PH_READONLY) == PH_READONLY) {
				ZVAL_COPY_VALUE(return_value, zv);
			} else {
				ZVAL_COPY(return_value, zv);
			}
			return SUCCESS;
		}

		if ((flags & PH_NOISY) == PH_NOISY) {
			if (sidx == NULL) {
				zend_error(E_NOTICE, "Undefined index: %ld in %s on line %d", uidx, file, line);
			} else {
				zend_error(E_NOTICE, "Undefined index: %s in %s on line %d", sidx, file, line);
			}
		}
	}

	ZVAL_NULL(return_value);
	return FAILURE;
}

int zephir_array_fetch_string(zval *return_value, zval *arr, const char *index, uint index_length, int flags ZEPHIR_DEBUG_PARAMS)
{
	zval *zv;

	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		if ((zv = zend_hash_str_find(Z_ARRVAL_P(arr), index, index_length)) != NULL) {

			if ((flags & PH_READONLY) == PH_READONLY) {
				ZVAL_COPY_VALUE(return_value, zv);
			} else {
				ZVAL_COPY(return_value, zv);
			}
			return SUCCESS;
		}
		if ((flags & PH_NOISY) == PH_NOISY) {
			zend_error(E_NOTICE, "Undefined index: %s", index);
		}
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

int zephir_array_fetch_long(zval *return_value, zval *arr, unsigned long index, int flags ZEPHIR_DEBUG_PARAMS)
{
	zval *zv;

	if (EXPECTED(Z_TYPE_P(arr) == IS_ARRAY)) {
		if ((zv = zend_hash_index_find(Z_ARRVAL_P(arr), index)) != NULL) {

			if ((flags & PH_READONLY) == PH_READONLY) {
				ZVAL_COPY_VALUE(return_value, zv);
			} else {
				ZVAL_COPY(return_value, zv);
			}
			return SUCCESS;
		}
		if ((flags & PH_NOISY) == PH_NOISY) {
			zend_error(E_NOTICE, "Undefined index: %lu", index);
		}
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
	zval *tmp;

	if (Z_TYPE_P(left) != IS_ARRAY) {
		zend_error(E_NOTICE, "First parameter of zephir_merge_append must be an array");
		return;
	}

	if (Z_TYPE_P(values) == IS_ARRAY) {

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

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		zend_error(E_WARNING, "Cannot use a scalar value as an array (2)");
		return FAILURE;
	}

	if ((flags & PH_CTOR) == PH_CTOR) {
		zval new_zv;
		//Z_TRY_DELREF_P(value); //?
		ZVAL_DUP(&new_zv, value);
		value = &new_zv;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL_IF_NOT_REF(arr);
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
			ret = zend_hash_index_update(ht, (ulong)Z_DVAL_P(index), value);
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

int zephir_array_update_string(zval *arr, const char *index, uint index_length, zval *value, int flags)
{

	if (Z_TYPE_P(arr) != IS_ARRAY) {
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
		SEPARATE_ZVAL_IF_NOT_REF(arr);
	}

	return zend_hash_str_update(Z_ARRVAL_P(arr), index, index_length, value) ? SUCCESS : FAILURE;
}

int zephir_array_update_long(zval *arr, unsigned long index, zval *value, int flags ZEPHIR_DEBUG_PARAMS)
{
	if (Z_TYPE_P(arr) != IS_ARRAY) {
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
		SEPARATE_ZVAL_IF_NOT_REF(arr);
	}

	return zend_hash_index_update(Z_ARRVAL_P(arr), index, value) ? SUCCESS : FAILURE;
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
	HashTable *h = Z_ARRVAL_P(arr);
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
	long old_l[ZEPHIR_MAX_ARRAY_LEVELS], old_ll[ZEPHIR_MAX_ARRAY_LEVELS];
	char *s, *old_s[ZEPHIR_MAX_ARRAY_LEVELS], old_type[ZEPHIR_MAX_ARRAY_LEVELS];
	zval *item, *old_item[ZEPHIR_MAX_ARRAY_LEVELS];
	zval pzv;
	zend_array *p, *old_p[ZEPHIR_MAX_ARRAY_LEVELS];
	zval tmp;
	int i, j, l, ll, re_update, must_continue, wrap_tmp;

	assert(types_length < ZEPHIR_MAX_ARRAY_LEVELS);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&pzv);

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		zend_error(E_ERROR, "Cannot use a scalar value as an array (multi)");
		return;
	}
	p = Z_ARRVAL_P(arr);

	for (i = 0; i < types_length; ++i) {
		zval fetched;
		ZVAL_UNDEF(&fetched);

		re_update = 0;
		must_continue = 0;
		wrap_tmp = 0;

		old_p[i] = p;
		ZVAL_ARR(&pzv, p);
		switch (types[i]) {

			case 's':
				s = va_arg(ap, char*);
				l = va_arg(ap, int);
				old_s[i] = s;
				old_l[i] = l;
				if (zephir_array_isset_string_fetch(&fetched, &pzv, s, l, 1)) {
					if (Z_TYPE(fetched) == IS_ARRAY) {
						if (i == (types_length - 1)) {
							re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
							zephir_array_update_string(&pzv, s, l, value, PH_COPY | PH_SEPARATE);
							p = Z_ARRVAL(pzv);
						} else {
							p = Z_ARRVAL(fetched);
							Z_TRY_ADDREF(fetched);
						}
						must_continue = 1;
					}
				}

				if (!must_continue) {
					ZVAL_ARR(&pzv, p);
					re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
					if (i == (types_length - 1)) {
						zephir_array_update_string(&pzv, s, l, value, PH_COPY | PH_SEPARATE);
						p = Z_ARRVAL(pzv);
					} else {
						array_init(&tmp);
						zephir_array_update_string(&pzv, s, l, &tmp, PH_SEPARATE);
						p = Z_ARRVAL(pzv);
						if (re_update) {
							wrap_tmp = 1;
						} else {
							p = Z_ARRVAL(tmp);
						}
					}
				}
				break;

			case 'l':
				ll = va_arg(ap, long);
				old_ll[i] = ll;
				if (zephir_array_isset_long_fetch(&fetched, &pzv, ll, 1)) {
					if (Z_TYPE(fetched) == IS_ARRAY) {
						if (i == (types_length - 1)) {
							re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
							zephir_array_update_long(&pzv, ll, value, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
							p = Z_ARRVAL(pzv);
						} else {
							p = Z_ARRVAL(fetched);
							Z_TRY_ADDREF(fetched);
						}
						must_continue = 1;
					}
				}

				if (!must_continue) {
					ZVAL_ARR(&pzv, p);
					re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
					if (i == (types_length - 1)) {
						zephir_array_update_long(&pzv, ll, value, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
						p = Z_ARRVAL(pzv);
					} else {
						array_init(&tmp);
						zephir_array_update_long(&pzv, ll, &tmp, PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
						p = Z_ARRVAL(pzv);
						if (re_update) {
							wrap_tmp = 1;
						} else {
							p = Z_ARRVAL(tmp);
						}
					}
				}
				break;

			case 'z':
				item = va_arg(ap, zval*);
				old_item[i] = item;
				if (zephir_array_isset_fetch(&fetched, &pzv, item, 1)) {
					if (Z_TYPE(fetched) == IS_ARRAY) {
						if (i == (types_length - 1)) {
							re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
							zephir_array_update_zval(&pzv, item, value, PH_COPY | PH_SEPARATE);
							p = Z_ARRVAL(pzv);
						} else {
							p = Z_ARRVAL(fetched);
							Z_TRY_ADDREF(fetched);
						}
						must_continue = 1;
					}
				}

				if (!must_continue) {
					ZVAL_ARR(&pzv, p);
					re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
					if (i == (types_length - 1)) {
						zephir_array_update_zval(&pzv, item, value, PH_COPY | PH_SEPARATE);
						p = Z_ARRVAL(pzv);
					} else {
						array_init(&tmp);
						zephir_array_update_zval(&pzv, item, &tmp, PH_SEPARATE);
						p = Z_ARRVAL(pzv);
						if (re_update) {
							wrap_tmp = 1;
						} else {
							p = Z_ARRVAL(tmp);
						}
					}
				}
				break;

			case 'a':
				re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));
				zephir_array_append(&pzv, value, PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				p = Z_ARRVAL(pzv);
				break;
		}

		if (re_update) {
			for (j = i - 1; j >= 0; j--) {
				zval old_pzv;

				if (!re_update) {
					break;
				}

				ZVAL_ARR(&pzv, old_p[j]);
				re_update = !Z_REFCOUNTED(pzv) || (Z_REFCOUNT(pzv) > 1 && !Z_ISREF(pzv));

				if (j == i - 1) {
					ZVAL_ARR(&old_pzv, p);
				} else {
					ZVAL_ARR(&old_pzv, old_p[j + 1]);
				}

				switch (old_type[j])
				{
					case 's':
						zephir_array_update_string(&pzv, old_s[j], old_l[j], &old_pzv, PH_SEPARATE);
						break;
					case 'l':
						zephir_array_update_long(&pzv, old_ll[j], &old_pzv, PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
						break;
					case 'z':
						zephir_array_update_zval(&pzv, old_item[j], &old_pzv, PH_SEPARATE);
						break;
				}
				old_p[j] = Z_ARRVAL(pzv);
				if (wrap_tmp) {
					p = Z_ARRVAL(tmp);
					wrap_tmp = 0;
				}
			}
		}

		if (i != (types_length - 1)) {
			old_type[i] = types[i];
		}
	}
}

int zephir_array_update_multi(zval *arr, zval *value, const char *types, int types_length, int types_count, ...)
{
	va_list ap;
	va_start(ap, types_count);
	SEPARATE_ZVAL_IF_NOT_REF(arr);

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
	zend_ulong num_idx;
	zend_string *str_idx;

	if (Z_TYPE_P(haystack) != IS_ARRAY) {
		return 0;
	}

	if (Z_TYPE_P(value) == IS_STRING) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(haystack), num_idx, str_idx, entry) {
			if (fast_equal_check_string(value, entry)) {
				return 1;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(haystack), num_idx, str_idx, entry) {
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
