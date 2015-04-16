
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\ControllerInterface
 *
 * Interface for controller handlers
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_ControllerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, ControllerInterface, phalcon, mvc_controllerinterface, NULL);

	return SUCCESS;

}

