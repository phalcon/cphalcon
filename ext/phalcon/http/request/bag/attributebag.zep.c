
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Holds the request attributes: arbitrary, application-defined values
 * attached to the request during its lifecycle (router, dispatcher,
 * security components etc.). Unlike the other request bags, it is not
 * hydrated from a superglobal - it always starts empty.
 *
 * The base class supplies the entire surface; this class exists as a
 * distinct type so DI typing and IDE autocomplete stay precise.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request_Bag_AttributeBag)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http\\Request\\Bag, AttributeBag, phalcon, http_request_bag_attributebag, phalcon_http_request_bag_abstractbag_ce, NULL, 0);

	return SUCCESS;
}

