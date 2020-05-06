
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */
/**
 * Decorates an existing PDO instance with the extended methods.
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Connection_Decorated) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DataMapper\\Pdo\\Connection, Decorated, phalcon, datamapper_pdo_connection_decorated, phalcon_datamapper_pdo_connection_abstractconnection_ce, phalcon_datamapper_pdo_connection_decorated_method_entry, 0);

	return SUCCESS;

}

/**
 *
 * Constructor.
 *
 * This overrides the parent so that it can take an existing PDO instance
 * and decorate it with the extended methods.
 *
 * @param PDO                    $pdo
 * @param ProfilerInterface|null $profiler
 *
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_Decorated, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pdo, pdo_sub, *profiler = NULL, profiler_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pdo_sub);
	ZVAL_UNDEF(&profiler_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pdo, &profiler);

	if (!profiler) {
		profiler = &profiler_sub;
		ZEPHIR_CPY_WRT(profiler, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(profiler);
	}


	zephir_update_property_zval(this_ptr, SL("pdo"), pdo);
	if (Z_TYPE_P(profiler) == IS_NULL) {
		ZEPHIR_INIT_NVAR(profiler);
		object_init_ex(profiler, phalcon_datamapper_pdo_profiler_profiler_ce);
		ZEPHIR_CALL_METHOD(NULL, profiler, "__construct", NULL, 199);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprofiler", NULL, 0, profiler);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Connects to the database.
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_Decorated, connect) {

	zval *this_ptr = getThis();



}

/**
 * Disconnects from the database; disallowed with decorated PDO connections.
 *
 * @throws CannotDisconnect
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_Decorated, disconnect) {

	zval *this_ptr = getThis();


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_datamapper_pdo_exception_cannotdisconnect_ce, "Cannot disconnect a Decorated connection instance", "phalcon/DataMapper/Pdo/Connection/Decorated.zep", 66);
	return;

}

