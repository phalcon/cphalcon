
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Cli\TaskInterface
 *
 * Interface for task handlers
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_TaskInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cli, TaskInterface, phalcon, cli_taskinterface, NULL);

	return SUCCESS;

}

