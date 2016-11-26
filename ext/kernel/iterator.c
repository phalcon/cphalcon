
/*
	+------------------------------------------------------------------------+
	| Zephir Language                                                        |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2016 Zephir Team  (http://www.zephir-lang.com)      |
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

#include "php.h"
#include "php_ext.h"

#include "kernel/main.h"
#include "kernel/memory.h"

/**
 * Returns an iterator from the object
 */
zend_object_iterator *zephir_get_iterator(zval *iterator)
{
	zend_class_entry *ce;
	zend_object_iterator *it;

	if (UNEXPECTED(Z_TYPE_P(iterator) != IS_OBJECT)) {
		return NULL;
	}

	ce = Z_OBJCE_P(iterator);
	it = ce->get_iterator(ce, iterator, 0);
	if (UNEXPECTED(!it || EG(exception))) {
		return NULL;
	}

	if (UNEXPECTED(it->funcs->get_current_key == NULL)) {
		return NULL;
	}

	if (UNEXPECTED(it->funcs->rewind == NULL)) {
		return NULL;
	}

	return it;
}
