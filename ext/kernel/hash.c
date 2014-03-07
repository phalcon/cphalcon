
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/hash.h"
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

/**
 * @brief Adds or updates item @a key in the hash table @a ht
 * @param ht Hash table
 * @param[in] key Key
 * @param[in] value Value
 * @return Whether the operation succeeded
 * @retval SUCCESS
 * @retval FAILURE
 * @note @a value's reference count in not updated
 * @note If @a key is @c NULL or is @c IS_NULL, @a value is appended to @a ht
 * @throw E_WARNING if @a key type is not supported
 */
int phalcon_hash_update_or_insert(HashTable *ht, const zval *key, zval *value)
{
	if (!key || Z_TYPE_P(key) == IS_NULL) {
		return zend_hash_next_index_insert(ht, (void**)&value, sizeof(zval*), NULL);
	}

	switch (Z_TYPE_P(key)) {
		case IS_STRING:
			return zend_symtable_update(ht, Z_STRVAL_P(key), Z_STRLEN_P(key)+1, (void**)&value, sizeof(zval*), NULL);

		case IS_RESOURCE:
		case IS_DOUBLE:
		case IS_BOOL:
		case IS_LONG:
			return zend_hash_index_update(ht, ((Z_TYPE_P(key) == IS_DOUBLE) ? (ulong)Z_DVAL_P(key) : (ulong)Z_LVAL_P(key)), (void*)&value, sizeof(zval*), NULL);

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return FAILURE;
	}
}

/**
 * @brief Returns the entry @a ht identified by @a key
 * @param[in] ht Hash table
 * @param[in] key
 * @param[in] type One of @c BP_VAR_XXX values
 * @return Pointer to the stored value or a pointer to the special variable / @c NULL if @a key was not found
 * @retval <tt>&EG(error_zval_ptr)</tt> when @a key was not found and @a type is one of @c BP_VAR_W, @c BP_VAR_RW
 * @retval <tt>&EG(uninitialized_zval_ptr)</tt> when @a key was not found and @a type is one of @c BP_VAR_R, @c BP_VAR_UNSET, @c BP_VAR_IS
 * @retval @c NULL when @a key was not found and @a type is not any of the above
 * @throw @c E_WARNING when @a key is of not supported type; in this case the function never returns @c NULL
 * @throw @c E_STRICT when @a key is a resource
 * @throw @c E_NOTICE if @a key was not found and @a type is @c BP_VAR_R or @c BP_VAR_RW
 * @note Reference count of the returned item is not modified
 * @note The implementation is suitable for @c read_property, @c get_property_ptr_ptr and @c read_dimension object handlers
 * @warning If @a type is @c BP_VAR_W or @c BP_VAR_RW and @a key was not found, it is added to @a ht and its value is set to @c IS_NULL
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
						zend_hash_index_update(ht, index, (void**)&value, sizeof(void*), (void**)&ret);
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
						zend_symtable_update(ht, Z_STRVAL_P(key), Z_STRLEN_P(key)+1, (void**)&value, sizeof(void*), (void**)&ret);
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

/**
 * @brief Unset @a key from @a ht
 * @param ht
 * @param key
 * @return
 */
int phalcon_hash_unset(HashTable *ht, const zval *key)
{
	switch (Z_TYPE_P(key)) {
		case IS_LONG:
		case IS_DOUBLE:
		case IS_BOOL:
		case IS_RESOURCE:
			return (zend_hash_index_del(ht, (Z_TYPE_P(key) == IS_DOUBLE) ? ((long int)Z_DVAL_P(key)) : Z_LVAL_P(key)) == SUCCESS);

		case IS_STRING:
			return (zend_symtable_del(ht, Z_STRVAL_P(key), Z_STRLEN_P(key)+1) == SUCCESS);

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return 0;
	}
}

#if PHP_VERSION_ID >= 50400
/**
 * @brief Returns the entry @a ht identified by @a key (<tt>key->constant</tt>)
 * @param[in] ht Hash table
 * @param[in] type One of @c BP_VAR_XXX values
 * @param[in] key Zend literal key
 * @return Pointer to the stored value or a pointer to the special variable / @c NULL if the key was not found
 * @retval <tt>&EG(error_zval_ptr)</tt> when the key was not found and @a type is one of @c BP_VAR_W, @c BP_VAR_RW
 * @retval <tt>&EG(uninitialized_zval_ptr)</tt> when the key was not found and @a type is one of @c BP_VAR_R, @c BP_VAR_UNSET, @c BP_VAR_IS
 * @retval @c NULL when the key was not found and @a type is not any of the above
 * @throw @c E_WARNING when the key is of not supported type; in this case the function never returns @c NULL
 * @throw @c E_NOTICE if @a key was not found and @a type is @c BP_VAR_R or @c BP_VAR_RW
 * @note Reference count of the returned item is not modified
 * @note The implementation is suitable for @c read_property, @c get_property_ptr_ptr and @c read_dimension object handlers
 * @warning If @a type is @c BP_VAR_W or @c BP_VAR_RW and the key was not found, it is added to @a ht and its value is set to @c IS_NULL
 */
zval** phalcon_hash_fast_get(HashTable *ht, int type, const zend_literal* key)
{
	zval **ret = NULL;

	switch (Z_TYPE(key->constant)) {
		case IS_RESOURCE:
			zend_error(E_STRICT, "Resource ID#%ld used as offset, casting to integer (%ld)", Z_LVAL(key->constant), Z_LVAL(key->constant));
			/* no break */
		case IS_LONG:
		case IS_DOUBLE:
		case IS_BOOL: {
			ulong index = (Z_TYPE(key->constant) == IS_DOUBLE) ? ((long int)Z_DVAL(key->constant)) : Z_LVAL(key->constant);
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
						zend_hash_index_update(ht, index, (void**)&value, sizeof(void*), (void**)&ret);
						break;
					}
				}
			}

			return ret;
		}

		case IS_STRING:
			if (*(Z_STRVAL(key->constant)) >= '0' && *(Z_STRVAL(key->constant)) <= '9') {
				return phalcon_hash_get(ht, &key->constant, type);
			}

			if (FAILURE == zend_hash_quick_find(ht, Z_STRVAL(key->constant), Z_STRLEN(key->constant)+1, key->hash_value, (void**)&ret)) {
				switch (type) {
					case BP_VAR_R:
						zend_error(E_NOTICE, "Undefined offset: %s", Z_STRVAL(key->constant));
						/* no break */
					case BP_VAR_UNSET:
					case BP_VAR_IS: {
						TSRMLS_FETCH();
						ret = &EG(uninitialized_zval_ptr);
						break;
					}

					case BP_VAR_RW:
						zend_error(E_NOTICE, "Undefined offset: %s", Z_STRVAL(key->constant));
						/* no break */
					case BP_VAR_W: {
						zval *value;
						ALLOC_INIT_ZVAL(value);
						zend_hash_quick_update(ht, Z_STRVAL(key->constant), Z_STRLEN(key->constant)+1, key->hash_value, (void**)&value, sizeof(void*), (void**)&ret);
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

/**
 * @brief Adds or updates item @a key in the hash table @a ht
 * @param ht Hash table
 * @param[in] key Literal key
 * @param[in] value Value
 * @return Whether the operation succeeded
 * @retval SUCCESS
 * @retval FAILURE
 * @note @a value's reference count in not updated
 * @note If <tt>key->constant</tt> is @c IS_NULL, @a value is appended to @a ht
 * @throw E_WARNING if @a key type is not supported
 */
int phalcon_hash_quick_update_or_insert(HashTable *ht, zval *value, const zend_literal *key)
{
	if (Z_TYPE(key->constant) == IS_NULL) {
		return zend_hash_next_index_insert(ht, (void**)&value, sizeof(zval*), NULL);
	}

	switch (Z_TYPE(key->constant)) {
		case IS_STRING:
			if (*(Z_STRVAL(key->constant)) >= '0' && *(Z_STRVAL(key->constant)) <= '9') {
				return zend_symtable_update(ht, Z_STRVAL(key->constant), Z_STRLEN(key->constant)+1, (void**)&value, sizeof(zval*), NULL);
			}

			return zend_hash_quick_update(ht, Z_STRVAL(key->constant), Z_STRLEN(key->constant)+1, key->hash_value, (void**)&value, sizeof(zval*), NULL);

		case IS_RESOURCE:
		case IS_DOUBLE:
		case IS_BOOL:
		case IS_LONG:
			return zend_hash_index_update(ht, ((Z_TYPE(key->constant) == IS_DOUBLE) ? (ulong)Z_DVAL(key->constant) : (ulong)Z_LVAL(key->constant)), (void*)&value, sizeof(zval*), NULL);

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return FAILURE;
	}
}

/**
 * @brief Unset key identified by @a key from @a ht
 * @param ht
 * @param key
 * @return
 */
int phalcon_hash_fast_unset(HashTable *ht, const zend_literal *key)
{
	switch (Z_TYPE(key->constant)) {
		case IS_LONG:
		case IS_DOUBLE:
		case IS_BOOL:
		case IS_RESOURCE:
			return (zend_hash_index_del(ht, (Z_TYPE(key->constant) == IS_DOUBLE) ? ((ulong)Z_DVAL(key->constant)) : (ulong)Z_LVAL(key->constant)) == SUCCESS);

		case IS_STRING:
			if (*(Z_STRVAL(key->constant)) >= '0' && *(Z_STRVAL(key->constant)) <= '9') {
				return (zend_symtable_del(ht, Z_STRVAL(key->constant), Z_STRLEN(key->constant)+1) == SUCCESS);
			}

			return (zend_hash_quick_del(ht, Z_STRVAL(key->constant), Z_STRLEN(key->constant)+1, key->hash_value) == SUCCESS);

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return 0;
	}
}

#endif
