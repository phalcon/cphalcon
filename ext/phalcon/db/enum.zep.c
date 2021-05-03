
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Constants for Phalcon\Db
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Enum)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Enum, phalcon, db_enum, NULL, 0);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_ASSOC"), 2);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_BOTH"), 4);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_BOUND"), 6);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_CLASS"), 8);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_CLASSTYPE"), 262144);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_COLUMN"), 7);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_FUNC"), 10);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_GROUP"), 65536);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_INTO"), 9);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_KEY_PAIR"), 12);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_LAZY"), 1);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_NAMED"), 11);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_NUM"), 3);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_OBJ"), 5);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_PROPS_LATE"), 1048576);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_SERIALIZE"), 524288);

	zephir_declare_class_constant_long(phalcon_db_enum_ce, SL("FETCH_UNIQUE"), 196608);

	return SUCCESS;
}

