
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

void phalcon_hash_update_or_insert(HashTable *ht, zval *offset, zval *value)
{
	if (!offset || Z_TYPE_P(offset) == IS_NULL) {
		zend_hash_next_index_insert(ht, value, sizeof(zval*), NULL);
	}
	else {
		if (Z_TYPE_P(offset) == IS_LONG || Z_TYPE_P(offset) == IS_DOUBLE || Z_TYPE_P(offset) == IS_BOOL) {
			zend_hash_index_update(ht, phalcon_get_intval(offset), value, sizeof(zval*), NULL);
		}
		else {
			zval copy;
			int use_copy = 0;

			if (Z_TYPE_P(offset) != IS_STRING) {
				zend_make_printable_zval(offset, &copy, &use_copy);
				if (use_copy) {
					offset = &copy;
				}
			}

			zend_hash_update(ht, Z_STRVAL_P(offset), Z_STRLEN_P(offset)+1, &value, sizeof(zval*), NULL);
			if (use_copy) {
				zval_dtor(&copy);
			}
		}
	}
}

int phalcon_hash_get(HashTable *ht, zval *offset, zval **value)
{
	switch (Z_TYPE_P(offset)) {
		case IS_LONG:
		case IS_DOUBLE:
		case IS_BOOL:
		case IS_RESOURCE:
			return (zend_hash_index_find(ht, (Z_TYPE_P(offset) == IS_DOUBLE) ? ((long int)Z_DVAL_P(offset)) : Z_LVAL_P(offset), (void**)value) == SUCCESS);

		case IS_STRING:
			return (zend_symtable_find(ht, Z_STRVAL_P(offset), Z_STRLEN_P(offset)+1, (void**)value) == SUCCESS);

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return 0;
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
