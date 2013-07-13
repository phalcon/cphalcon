
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"

#include "kernel/memory.h"

int phalcon_hash_exists(const HashTable *ht, const char *arKey, uint nKeyLength)
{
	ulong h;
	uint nIndex;
	Bucket *p;

	h = zend_inline_hash_func(arKey, nKeyLength);
	nIndex = h & ht->nTableMask;

	p = ht->arBuckets[nIndex];
	while (p != NULL) {
		if (p->arKey == arKey || ((p->h == h) && (p->nKeyLength == nKeyLength))) {
			if (!memcmp(p->arKey, arKey, nKeyLength)) {
				return 1;
			}
		}
		p = p->pNext;
	}
	return 0;
}

int phalcon_hash_quick_exists(const HashTable *ht, const char *arKey, uint nKeyLength, ulong h)
{
	uint nIndex;
	Bucket *p;

	if (nKeyLength == 0) {
		return zend_hash_index_exists(ht, h);
	}

	nIndex = h & ht->nTableMask;

	p = ht->arBuckets[nIndex];
	while (p != NULL) {
		if (p->arKey == arKey || ((p->h == h) && (p->nKeyLength == nKeyLength))) {
			if (!memcmp(p->arKey, arKey, nKeyLength)) {
				return 1;
			}
		}
		p = p->pNext;
	}
	return 0;
}

int phalcon_hash_find(const HashTable *ht, const char *arKey, uint nKeyLength, void **pData)
{
	ulong h;
	uint nIndex;
	Bucket *p;

	h = zend_inline_hash_func(arKey, nKeyLength);
	nIndex = h & ht->nTableMask;

	p = ht->arBuckets[nIndex];
	while (p != NULL) {
		if (p->arKey == arKey || ((p->h == h) && (p->nKeyLength == nKeyLength))) {
			if (!memcmp(p->arKey, arKey, nKeyLength)) {
				*pData = p->pData;
				return SUCCESS;
			}
		}
		p = p->pNext;
	}
	return FAILURE;
}

int phalcon_hash_quick_find(const HashTable *ht, const char *arKey, uint nKeyLength, ulong h, void **pData)
{
	uint nIndex;
	Bucket *p;

	if (nKeyLength == 0) {
		return zend_hash_index_find(ht, h, pData);
	}

	nIndex = h & ht->nTableMask;

	p = ht->arBuckets[nIndex];
	while (p != NULL) {
		if (p->arKey == arKey || ((p->h == h) && (p->nKeyLength == nKeyLength))) {
			if (!memcmp(p->arKey, arKey, nKeyLength)) {
				*pData = p->pData;
				return SUCCESS;
			}
		}
		p = p->pNext;
	}
	return FAILURE;
}

/**
 * Assigns the current value in a hash traversing to a zval
 */
void phalcon_get_current_key(zval **key, const HashTable *hash_table, HashPosition *hash_position TSRMLS_DC)
{
	Bucket *p;

	PHALCON_INIT_NVAR_PNULL(*key);

	p = hash_position ? (*hash_position) : hash_table->pInternalPointer;

	if (p) {
		if (p->nKeyLength) {
			ZVAL_STRINGL(*key, (char *) p->arKey, p->nKeyLength - 1, 0);
		} else {
			ZVAL_LONG(*key, p->h);
		}
	}

}

zval phalcon_get_current_key_w(const HashTable *hash_table, HashPosition *hash_position)
{
	Bucket *p;
	zval result;

	INIT_ZVAL(result);
	p = hash_position ? (*hash_position) : hash_table->pInternalPointer;

	if (p) {
		if (p->nKeyLength) {
			ZVAL_STRINGL(&result, (char *) p->arKey, p->nKeyLength - 1, 0);
		} else {
			ZVAL_LONG(&result, p->h);
		}
	}

	return result;
}

/**
 * Traverses the hash checking if at least one of the keys is numeric
 */
int phalcon_has_numeric_keys(const zval *data)
{
	HashTable *ht;

	if (Z_TYPE_P(data) == IS_ARRAY) {

		ht = Z_ARRVAL_P(data);

		ht->pInternalPointer = ht->pListHead;
		while (ht->pInternalPointer) {
			if (!ht->pInternalPointer->nKeyLength) {
				return 1;
			}
			ht->pInternalPointer = ht->pInternalPointer->pListNext;
		}

	}

	return 0;
}

void phalcon_hash_update_or_insert(HashTable *ht, zval *key, zval *value)
{
	if (!key || Z_TYPE_P(key) == IS_NULL) {
		zend_hash_next_index_insert(ht, (void**)&value, sizeof(zval*), NULL);
		return;
	}

	switch (Z_TYPE_P(key)) {
		case IS_STRING:
			zend_symtable_update(ht, Z_STRVAL_P(key), Z_STRLEN_P(key)+1, (void**)&value, sizeof(zval*), NULL);
			return;

		case IS_RESOURCE:
		case IS_DOUBLE:
		case IS_BOOL:
		case IS_LONG:
			zend_hash_index_update(ht, ((Z_TYPE_P(key) == IS_DOUBLE) ? (ulong)Z_DVAL_P(key) : Z_LVAL_P(key)), (void*)&value, sizeof(zval*), NULL);
			return;

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return;
	}
}

/**
 * @brief Gets an entry from @a ht identified by @a key and puts it to @a *value
 * @param[in] ht Hash table
 * @param[in] offset
 * @param[out] value
 * @return
 * @retval @c SUCCESS
 * @retval @c FAILURE
 * @throw @c E_WARNING when @a key is of not supported type
 * @note @a *value is not modified on failure
 * @note Reference count of the retrieved item is not modified
 */
zval** phalcon_hash_get(HashTable *ht, const zval *key, int type)
{
	zval **ret = NULL;

	switch (Z_TYPE_P(key)) {
		case IS_RESOURCE:
			zend_error(E_STRICT, "Resource ID#%ld used as offset, casting to integer (%ld)", Z_LVAL_P(key), Z_LVAL_P(key));
			/* no break */
		case IS_LONG:
		case IS_DOUBLE:
		case IS_BOOL: {
			ulong index = (Z_TYPE_P(key) == IS_DOUBLE) ? ((long int)Z_DVAL_P(key)) : Z_LVAL_P(key);
			if (FAILURE == zend_hash_index_find(ht, index, (void**)&ret)) {
				switch (type) {
					case BP_VAR_R:
						zend_error(E_NOTICE, "Undefined offset: %ld", index);
						/* no break */
					case BP_VAR_UNSET:
					case BP_VAR_IS: {
						TSRMLS_FETCH();
						ret = &EG(uninitialized_zval_ptr);
						break;
					}

					case BP_VAR_RW:
						zend_error(E_NOTICE, "Undefined offset: %ld", index);
						/* no break */
					case BP_VAR_W: {
						zval *value;
						ALLOC_INIT_ZVAL(value);
						zend_hash_index_update(ht, index, (void**)&value, sizeof(void*), NULL);
						break;
					}
				}
			}

			return ret;
		}

		case IS_STRING:
			if (FAILURE == zend_symtable_find(ht, Z_STRVAL_P(key), Z_STRLEN_P(key)+1, (void**)&ret)) {
				switch (type) {
					case BP_VAR_R:
						zend_error(E_NOTICE, "Undefined offset: %s", Z_STRVAL_P(key));
						/* no break */
					case BP_VAR_UNSET:
					case BP_VAR_IS: {
						TSRMLS_FETCH();
						ret = &EG(uninitialized_zval_ptr);
						break;
					}

					case BP_VAR_RW:
						zend_error(E_NOTICE, "Undefined offset: %s", Z_STRVAL_P(key));
						/* no break */
					case BP_VAR_W: {
						zval *value;
						ALLOC_INIT_ZVAL(value);
						zend_symtable_update(ht, Z_STRVAL_P(key), Z_STRLEN_P(key)+1, (void**)&value, sizeof(void*), NULL);
						break;
					}
				}
			}

			return ret;

		default: {
			TSRMLS_FETCH();
			zend_error(E_WARNING, "Illegal offset type");
			return (type == BP_VAR_W || type == BP_VAR_RW) ? &EG(error_zval_ptr) : &EG(uninitialized_zval_ptr);
		}
	}
}

int phalcon_hash_unset(HashTable *ht, zval *offset)
{
	switch (Z_TYPE_P(offset)) {
		case IS_LONG:
		case IS_DOUBLE:
		case IS_BOOL:
		case IS_RESOURCE:
			return (zend_hash_index_del(ht, (Z_TYPE_P(offset) == IS_DOUBLE) ? ((long int)Z_DVAL_P(offset)) : Z_LVAL_P(offset)) == SUCCESS);

		case IS_STRING:
			return (zend_symtable_del(ht, Z_STRVAL_P(offset), Z_STRLEN_P(offset)+1) == SUCCESS);

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return 0;
	}
}
