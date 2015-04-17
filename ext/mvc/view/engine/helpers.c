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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include "mvc/view/engine/helpers.h"
#include <Zend/zend_globals.h>

zend_bool phalcon_mvc_view_engine_php_symtable_merger(HashTable *ht, void *pData, zend_hash_key *hash_key, void *pParam)
{
#ifdef ZTS
	TSRMLS_FETCH_FROM_CTX(pParam);
#endif

	return hash_key->arKey && hash_key->nKeyLength && !zend_hash_quick_exists(CG(auto_globals), hash_key->arKey, hash_key->nKeyLength, hash_key->h);
}
