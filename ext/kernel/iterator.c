
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "kernel/main.h"
#include "kernel/memory.h"

/**
 * Returns an iterator from the object
 */
zend_object_iterator *phalcon_get_iterator(zval *iterator TSRMLS_DC) {

	zend_class_entry *ce;
	zend_object_iterator *it;

	if (Z_TYPE_P(iterator) != IS_OBJECT) {
		return NULL;
	}

	ce = Z_OBJCE_P(iterator);
	it = ce->get_iterator(ce, iterator, 0 TSRMLS_CC);
	if (!it || EG(exception)) {
		return NULL;
	}

	if (it->funcs->get_current_key == NULL) {
		return NULL;
	}

	if (it->funcs->rewind == NULL) {
		return NULL;
	}

	return it;
}
