
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Logger\Item
 *
 * Represents each item in a logging transaction
 *
 */
class Item
{

	/**
	 * Log type
	 *
	 * @var integer
	 */
	protected _type { get };

	/**
	 * Log message
	 *
	 * @var string
	 */
	protected _message { get };

	/**
	 * Log timestamp
	 *
	 * @var integer
	 */
	protected _time { get };

	protected _context { get };

	/**
	 * Phalcon\Logger\Item constructor
	 *
	 * @param string $message
	 * @param integer $type
	 * @param integer $time
	 * @param array $context
	 */
	public function __construct(string message, int type, int time = 0, var context = null)
	{
		let this->_message = message,
			this->_type = type,
			this->_time = time;

		if typeof context == "array" {
			let this->_context = context;
		}
	}
}
