
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use SessionHandlerInterface;
use Phalcon\Utility;

/**
 * Phalcon\Session\Adapter\Noop
 *
 * This is an "empty" or null adapter. It can be used for testing or any
 * other purpose that no session needs to be invoked
 *
 * <code>
 * <?php
 *
 * use Phalcon\Session\Manager;
 * use Phalcon\Session\Adapter\Noop;
 *
 * $session = new Manager();
 * $session->setHandler(new Noop());
 * </code>
 */
class Noop extends Utility implements SessionHandlerInterface
{
    /**
     * The connection of some adapters
     */
	protected connection;

	/**
	 * Session options
	 *
	 * @var array
	 */
	protected options = [];

	/**
	 * Session prefix
	 *
	 * @var string
	 */
	protected prefix = "";

	/**
	 * Time To Live
	 *
	 * @var int
	 */
	protected ttl = 8600;

	/**
	 * Constructor
	 */
	public function __construct(array! options = [])
	{
	    var prefix;

	    if !fetch prefix, options["prefix"] {
	        let prefix = "";
	    }

		let this->prefix  = prefix,
		    this->options = options;
	}

	/**
	 * Close
	 */
	public function close() -> bool
	{
		return true;
	}

	/**
	 * Destroy
	 */
	public function destroy(var id) -> bool
	{
		return true;
	}

	/**
	 * Garbage Collector
	 */
	public function gc(var maxlifetime) -> bool
	{
		return true;
	}

	/**
	 * Read
	 */
	public function read(var id) -> string
	{
		return "";
	}

	/**
	 * Open
	 */
	public function open(var savePath, var sessionName) -> bool
	{
		return true;
	}

	/**
	 * Write
	 */
	public function write(var id, var data) -> bool
	{
		return true;
	}

	/**
	 * Helper method to get the name prefixed
	 */
	protected function getPrefixedName(var name) -> string
	{
		let name = (string) name;

		return this->prefix . name;
	}
}
