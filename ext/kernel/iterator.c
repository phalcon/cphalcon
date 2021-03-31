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
