
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Shared base for ACL Role and Component entities: a name and an optional
 * description.
 *
 * @todo Remove in v7. Kept only for backwards compatibility; the logic now
 *       lives in `Phalcon\Acl\Traits\ItemTrait` - compose that trait directly
 *       instead of extending this class.
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_AbstractElement)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, AbstractElement, phalcon, acl_abstractelement, phalcon_acl_abstractelement_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Role/Component description
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_acl_abstractelement_ce, SL("description"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	/**
	 * Role/Component name
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_acl_abstractelement_ce, SL("name"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

PHP_METHOD(Phalcon_Acl_AbstractElement, __toString)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

PHP_METHOD(Phalcon_Acl_AbstractElement, getDescription)
{

	RETURN_MEMBER(getThis(), "description");
}

PHP_METHOD(Phalcon_Acl_AbstractElement, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

