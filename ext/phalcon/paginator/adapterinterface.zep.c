
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Paginator\AdapterInterface
 *
 * Interface for Phalcon\Paginator adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Paginator, AdapterInterface, phalcon, paginator_adapterinterface, phalcon_paginator_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Paginator\AdapterInterface constructor
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, __construct);

/**
 * Set the current page number
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, setCurrentPage);

/**
 * Returns a slice of the resultset to show in the pagination
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, getPaginate);

/**
 * Set current rows limit
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, setLimit);

/**
 * Get current rows limit
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, getLimit);

