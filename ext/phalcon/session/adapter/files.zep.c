
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
 * Phalcon\Session\Adapter\Files
 *
 * This adapter store sessions in plain files
 *
 * <code>
 * use Phalcon\Session\Adapter\Files;
 *
 * $session = new Files(
 *     [
 *         "uniqueId" => "my-private-app",
 *     ]
 * );
 *
 * $session->start();
 *
 * $session->set("var", "some-value");
 *
 * echo $session->get("var");
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Files) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Files, phalcon, session_adapter_files, phalcon_session_adapter_ce, NULL, 0);

	return SUCCESS;

}

