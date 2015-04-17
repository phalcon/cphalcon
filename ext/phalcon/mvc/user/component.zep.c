
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


/**
 * Phalcon\Mvc\User\Component
 *
 * This class can be used to provide user components easy access to services
 * in the application
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_User_Component) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\User, Component, phalcon, mvc_user_component, phalcon_di_injectable_ce, NULL, 0);

	return SUCCESS;

}

