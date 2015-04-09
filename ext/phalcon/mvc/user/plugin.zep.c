
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
 * Phalcon\Mvc\User\Plugin
 *
 * This class can be used to provide user plugins an easy access to services
 * in the application
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_User_Plugin) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\User, Plugin, phalcon, mvc_user_plugin, phalcon_di_injectable_ce, NULL, 0);

	return SUCCESS;

}

