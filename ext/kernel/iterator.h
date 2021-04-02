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

#ifndef ZEPHIR_KERNEL_ITERATOR_H
#define ZEPHIR_KERNEL_ITERATOR_H

#include <php.h>
#include <Zend/zend.h>

zend_object_iterator *zephir_get_iterator(zval *iterator);

#define ZEPHIR_ITERATOR_COPY(var, it) \
	{ \
		zval *ZEPHIR_TMP_ITERATOR_PTR; \
		ZEPHIR_TMP_ITERATOR_PTR = it->funcs->get_current_data(it); \
		if (UNEXPECTED(EG(exception) != NULL)) { \
			return; \
		} \
		ZEPHIR_INIT_NVAR(var); \
		if (Z_ISREF_P(var)) { \
			ZVAL_DUP(var, Z_REFVAL_P(var)); \
		} else { \
			ZVAL_COPY(var, ZEPHIR_TMP_ITERATOR_PTR); \
		} \
	}

#endif
