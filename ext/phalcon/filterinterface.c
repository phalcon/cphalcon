
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "kernel/main.h"


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
/**
 * Phalcon\FilterInterface
 *
 * Interface for Phalcon\Filter
 */
ZEPHIR_INIT_CLASS(Phalcon_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon, FilterInterface, phalcon, filterinterface, phalcon_filterinterface_method_entry);


	return SUCCESS;

}

/**
 * Adds a user-defined filter
 *
 * @param string name
 * @param callable handler
 * @return Phalcon\FilterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_FilterInterface, add);

/**
 * Sanizites a value with a specified single or set of filters
 *
 * @param  mixed value
 * @param  mixed filters
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_FilterInterface, sanitize);

/**
 * Return the user-defined filters in the instance
 *
 * @return object[]
 */
ZEPHIR_DOC_METHOD(Phalcon_FilterInterface, getFilters);

