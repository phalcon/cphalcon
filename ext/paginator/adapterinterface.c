
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Paginator\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Paginator_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Paginator, AdapterInterface, paginator_adapterinterface, phalcon_paginator_adapterinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Paginator\AdapterInterface constructor
 *
 * @param array $config
 */
PHALCON_DOC_METHOD(Phalcon_Paginator_AdapterInterface, __construct);

/**
 * Set the current page number
 *
 * @param int $page
 */
PHALCON_DOC_METHOD(Phalcon_Paginator_AdapterInterface, setCurrentPage);

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHALCON_DOC_METHOD(Phalcon_Paginator_AdapterInterface, getPaginate);

