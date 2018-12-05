
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	protected context { get };

	/**
	 * Log message
	 *
	 * @var string
	 */
	protected message { get };

	/**
	 * Log message
	 *
	 * @var string
	 */
	protected name { get };

	/**
	 * Log timestamp
	 *
	 * @var integer
	 */
	protected time { get };

	/**
	 * Log type
	 *
	 * @var integer
	 */
	protected type { get };

	/**
	 * Phalcon\Logger\Item constructor
	 *
	 * @param string message
	 * @param string name
	 * @param int    type
	 * @param int    time
	 * @param array  context
	 */
	public function __construct(string message, string name, int type, int time = 0, var context = [])
	{
		let this->message = message,
			this->name    = name,
			this->type    = type,
			this->time    = time;

		if typeof context == "array" {
			let this->context = context;
		}
	}
}
