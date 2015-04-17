
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "session/adapter/files.h"
#include "session/adapter.h"
#include "session/adapterinterface.h"
#include "kernel/main.h"

/**
 * Phalcon\Session\Adapter\Files
 *
 * This adapter store sessions in plain files
 *
 *<code>
 * $session = new Phalcon\Session\Adapter\Files(array(
 *    'uniqueId' => 'my-private-app'
 * ));
 *
 * $session->start();
 *
 * $session->set('var', 'some-value');
 *
 * echo $session->get('var');
 *</code>
 */
zend_class_entry *phalcon_session_adapter_files_ce;

/**
 * Phalcon\Session\Adapter\Files initializer
 */
PHALCON_INIT_CLASS(Phalcon_Session_Adapter_Files){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Files, session_adapter_files, phalcon_session_adapter_ce, NULL, 0);

	zend_class_implements(phalcon_session_adapter_files_ce TSRMLS_CC, 1, phalcon_session_adapterinterface_ce);

	return SUCCESS;
}
