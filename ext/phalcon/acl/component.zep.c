
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This class defines component entity and its description
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Component) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, Component, phalcon, acl_component, phalcon_acl_component_method_entry, 0);

	/**
	 * Component description
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_component_ce, SL("description"), ZEND_ACC_PRIVATE);

	/**
	 * Component name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_component_ce, SL("name"), ZEND_ACC_PRIVATE);

	zend_class_implements(phalcon_acl_component_ce, 1, phalcon_acl_componentinterface_ce);
	return SUCCESS;

}

/**
 * Component description
 */
PHP_METHOD(Phalcon_Acl_Component, getDescription) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "description");

}

/**
 * Component name
 */
PHP_METHOD(Phalcon_Acl_Component, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * Component name
 */
PHP_METHOD(Phalcon_Acl_Component, __toString) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * Phalcon\Acl\Component constructor
 */
PHP_METHOD(Phalcon_Acl_Component, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *description_param = NULL;
	zval name, description;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&description);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &description_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!description_param) {
		ZEPHIR_INIT_VAR(&description);
		ZVAL_STRING(&description, "");
	} else {
		zephir_get_strval(&description, description_param);
	}


	if (UNEXPECTED(ZEPHIR_IS_STRING(&name, "*"))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Component name cannot be '*'", "phalcon/Acl/Component.zep", 38);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("name"), &name);
	zephir_update_property_zval(this_ptr, SL("description"), &description);
	ZEPHIR_MM_RESTORE();

}

