
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

#include "filterinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_filterinterface_ce;

static const zend_function_entry phalcon_filterinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, add, arginfo_phalcon_filterinterface_add)
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, sanitize, arginfo_phalcon_filterinterface_sanitize)
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, getFilters, NULL)
	PHP_FE_END
};

/**
 * Phalcon\FilterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_FilterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon, FilterInterface, filterinterface, phalcon_filterinterface_method_entry);

	return SUCCESS;
}

/**
 * Adds a user-defined filter
 *
 * @param string $name
 * @param callable $handler
 * @return Phalcon\FilterInterface
 */
PHALCON_DOC_METHOD(Phalcon_FilterInterface, add);

/**
 * Sanizites a value with a specified single or set of filters
 *
 * @param  mixed $value
 * @param  mixed $filters
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_FilterInterface, sanitize);

/**
 * Return the user-defined filters in the instance
 *
 * @return object[]
 */
PHALCON_DOC_METHOD(Phalcon_FilterInterface, getFilters);
