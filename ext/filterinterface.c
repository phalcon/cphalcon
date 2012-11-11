
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

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
