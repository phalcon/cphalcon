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
 * Returns an iterator from the object.
 *
 * `iterator()` requires an object implementing Iterator or IteratorAggregate
 * (== Z_OBJCE_P(obj) has a non-NULL get_iterator handler). Passing anything
 * else — scalar, array, stdClass — used to return NULL silently and the
 * caller would NULL-deref on `it->funcs->rewind`, segfaulting the process.
 * Now we throw a TypeError matching PHP's own foreach diagnostic so user
 * code can catch and recover. See
 * https://github.com/zephir-lang/zephir/issues/820.
 */
zend_object_iterator *zephir_get_iterator(zval *iterator)
{
	zend_class_entry *ce;
	zend_object_iterator *it;

	if (UNEXPECTED(Z_TYPE_P(iterator) != IS_OBJECT)) {
		zend_type_error(
			"iterator() argument must be of type Traversable, %s given",
			zend_zval_type_name(iterator)
		);
		return NULL;
	}

	ce = Z_OBJCE_P(iterator);
	if (UNEXPECTED(ce->get_iterator == NULL)) {
		zend_type_error(
			"iterator() argument must be of type Traversable, %s given",
			ZSTR_VAL(ce->name)
		);
		return NULL;
	}

	it = ce->get_iterator(ce, iterator, 0);
	if (UNEXPECTED(!it || EG(exception))) {
		return NULL;
	}

	if (UNEXPECTED(it->funcs->get_current_key == NULL)) {
		zend_iterator_dtor(it);
		return NULL;
	}

	if (UNEXPECTED(it->funcs->rewind == NULL)) {
		zend_iterator_dtor(it);
		return NULL;
	}

	return it;
}
