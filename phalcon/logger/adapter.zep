
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Logger;

/**
 * Phalcon\Logger\Adapter
 *
 * Base class for Phalcon\Logger adapters
 */
abstract class Phalcon_Logger_Adapter {

	/**
	 * Tells if there is an active transaction or not
	 *
	 * @var boolean
	 */
	protected _transaction = false;

	/**
	 * Array with messages queued in the transacction
	 *
	 * @var array
	 */
	protected _queue;

	/**
	 * Formatter
	 *
	 * @var object
	 */
	protected _formatter;

	/**
	 * Log level
	 *
	 * @var int
	 */
	protected _logLevel = 9;

}