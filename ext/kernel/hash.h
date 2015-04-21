
/*
 +------------------------------------------------------------------------+
 | Zephir Language                                                        |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Zephir Team  (http://www.zephir-lang.com)      |
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

#ifndef ZEPHIR_KERNEL_HASH_H
#define ZEPHIR_KERNEL_HASH_H

#include <php.h>
#include <Zend/zend.h>
#include <Zend/zend_hash.h>

#if PHP_VERSION_ID < 70000
int zephir_hash_init(HashTable *ht, uint nSize, hash_func_t pHashFunction, dtor_func_t pDestructor, zend_bool persistent);
#else
void zephir_hash_init(HashTable *ht, uint nSize, dtor_func_t pDestructor, zend_bool persistent);
#endif

int zephir_hash_exists(const HashTable *ht, const char *arKey, uint nKeyLength);
int zephir_hash_quick_exists(const HashTable *ht, const char *arKey, uint nKeyLength, ulong h);
int zephir_hash_find(const HashTable *ht, const char *arKey, uint nKeyLength, void **pData);
int zephir_hash_quick_find(const HashTable *ht, const char *arKey, uint nKeyLength, ulong h, void **pData);
void zephir_get_current_key(zval **key, const HashTable *hash_table, HashPosition *hash_position TSRMLS_DC);
zval zephir_get_current_key_w(const HashTable *hash_table, HashPosition *hash_position);
int zephir_has_numeric_keys(const zval *data);
void zephir_hash_update_or_insert(HashTable *ht, zval *offset, zval *value);
zval** zephir_hash_get(HashTable *ht, zval *key, int type);
int zephir_hash_unset(HashTable *ht, zval *offset);

#define zephir_hash_move_forward_ex(ht, pos) *pos = (*pos ? (*pos)->pListNext : NULL)

#if PHP_VERSION_ID < 70000

static zend_always_inline int zephir_hash_get_current_data_ex(HashTable *ht, void **pData, HashPosition *pos)
{
	Bucket *p;
	p = pos ? (*pos) : ht->pInternalPointer;
	if (p) {
		*pData = p->pData;
		return SUCCESS;
	} else {
		return FAILURE;
	}
}

#else

static zend_always_inline zval *zephir_hash_get_current_data_ex(HashTable *ht, HashPosition *pos)
{
	uint idx = *pos;
	Bucket *p;

	IS_CONSISTENT(ht);
	if (idx != INVALID_IDX) {
		p = ht->arData + idx;
		return &p->val;
	} else {
		return NULL;
	}
}

#endif

static zend_always_inline int zephir_hash_move_backwards_ex(HashTable *ht, HashPosition *pos)
{
#if PHP_VERSION_ID < 70000
	HashPosition *current = pos ? pos : &ht->pInternalPointer;
	if (*current) {
		*current = (*current)->pListLast;
		return SUCCESS;
	} else {
		return FAILURE;
	}
#else
	uint idx = *pos;

	IS_CONSISTENT(ht);

	if (idx != INVALID_IDX) {
		while (idx > 0) {
			idx--;
			if (Z_TYPE(ht->arData[idx].val) != IS_UNDEF) {
				*pos = idx;
				return SUCCESS;
			}
		}
		*pos = INVALID_IDX;
		return SUCCESS;
	} else {
		return FAILURE;
	}
#endif
}

#endif
