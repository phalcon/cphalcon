
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Acl_Component)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, Component, phalcon, acl_component, phalcon_acl_component_method_entry, 0);

	/**
	 * Component description
	 *
	 * @var string | null
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
 * Phalcon\Acl\Component constructor
 */
PHP_METHOD(Phalcon_Acl_Component, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, description_zv;
	zend_string *name = NULL, *description = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&description_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(description)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!description) {
		ZEPHIR_INIT_VAR(&description_zv);
	} else {
		zephir_memory_observe(&description_zv);
	ZVAL_STR_COPY(&description_zv, description);
	}
	if (UNEXPECTED(ZEPHIR_IS_STRING_IDENTICAL(&name_zv, "*"))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_forbiddenwildcard_ce, "component", "phalcon/Acl/Component.zep", 40);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("description"), &description_zv);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Acl_Component, __toString)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

PHP_METHOD(Phalcon_Acl_Component, getDescription)
{

	RETURN_MEMBER(getThis(), "description");
}

PHP_METHOD(Phalcon_Acl_Component, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

