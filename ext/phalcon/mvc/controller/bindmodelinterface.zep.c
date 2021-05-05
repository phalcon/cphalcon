
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

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
 * Phalcon\Mvc\Controller\BindModelInterface
 *
 * Interface for Phalcon\Mvc\Controller
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Controller_BindModelInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Controller, BindModelInterface, phalcon, mvc_controller_bindmodelinterface, phalcon_mvc_controller_bindmodelinterface_method_entry);

	return SUCCESS;
}

/**
 * Return the model name associated with this controller
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Controller_BindModelInterface, getModelName);
