
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

#ifndef PHALCON_KERNEL_HASH_H
#define PHALCON_KERNEL_HASH_H

#include <Zend/zend.h>

int phalcon_hash_exists(const HashTable *ht, const char *arKey, uint nKeyLength);
int phalcon_hash_quick_exists(const HashTable *ht, const char *arKey, uint nKeyLength, ulong h);
int phalcon_hash_find(const HashTable *ht, const char *arKey, uint nKeyLength, void **pData);
int phalcon_hash_quick_find(const HashTable *ht, const char *arKey, uint nKeyLength, ulong h, void **pData);
void phalcon_get_current_key(zval **key, const HashTable *hash_table, HashPosition *hash_position TSRMLS_DC);
zval phalcon_get_current_key_w(const HashTable *hash_table, HashPosition *hash_position);
int phalcon_has_numeric_keys(const zval *data);
void phalcon_hash_update_or_insert(HashTable *ht, zval *offset, zval *value);
zval** phalcon_hash_get(HashTable *ht, zval *key, int type);
int phalcon_hash_unset(HashTable *ht, zval *offset);

#endif /* PHALCON_KERNEL_HASH_H */
