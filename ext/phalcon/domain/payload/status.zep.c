
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 */
/**
 * Holds the status codes for the payload
 */
ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_Status) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Domain\\Payload, Status, phalcon, domain_payload_status, phalcon_domain_payload_status_method_entry, 0);

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("ACCEPTED"), "ACCEPTED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("AUTHENTICATED"), "AUTHENTICATED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("AUTHORIZED"), "AUTHORIZED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("CREATED"), "CREATED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("DELETED"), "DELETED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("ERROR"), "ERROR");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("FAILURE"), "FAILURE");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("FOUND"), "FOUND");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("NOT_ACCEPTED"), "NOT_ACCEPTED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("NOT_AUTHENTICATED"), "NOT_AUTHENTICATED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("NOT_AUTHORIZED"), "NOT_AUTHORIZED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("NOT_CREATED"), "NOT_CREATED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("NOT_DELETED"), "NOT_DELETED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("NOT_FOUND"), "NOT_FOUND");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("NOT_UPDATED"), "NOT_UPDATED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("NOT_VALID"), "NOT_VALID");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("PROCESSING"), "PROCESSING");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("SUCCESS"), "SUCCESS");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("UPDATED"), "UPDATED");

	zephir_declare_class_constant_string(phalcon_domain_payload_status_ce, SL("VALID"), "VALID");

	return SUCCESS;

}

/**
 * Instantiation not allowed.
 */
PHP_METHOD(Phalcon_Domain_Payload_Status, __construct) {

	zval *this_ptr = getThis();




}

