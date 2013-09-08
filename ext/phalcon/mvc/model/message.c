
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

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
 * Phalcon\Mvc\Model\Message
 *
 * Encapsulates validation info generated before save/delete records fails
 *
 *<code>
 *	use Phalcon\Mvc\Model\Message as Message;
 *
 *  class Robots extends Phalcon\Mvc\Model
 *  {
 *
 *    public function beforeSave()
 *    {
 *      if (this->name == 'Peter') {
 *        text = "A robot cannot be named Peter";
 *        field = "name";
 *        type = "InvalidValue";
 *        message = new Message(text, field, type);
 *        this->appendMessage(message);
 *     }
 *   }
 *
 * }
 * </code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Message) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, phalcon, Message, mvc_model_message, NULL, 0);

	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_type"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_message"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_field"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_model"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

