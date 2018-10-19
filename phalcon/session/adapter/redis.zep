/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Session\Adapter;
use Phalcon\Cache\Backend\Redis;
use Phalcon\Cache\Frontend\None as FrontendNone;

/**
 * Phalcon\Session\Adapter\Redis
 *
 * This adapter store sessions in Redis
 *
 * <code>
 * use Phalcon\Session\Adapter\Redis;
 *
 * $session = new Redis(
 *     [
 *         "uniqueId"   => "my-private-app",
 *         "host"       => "localhost",
 *         "port"       => 6379,
 *         "auth"       => "foobared",
 *         "persistent" => false,
 *         "lifetime"   => 3600,
 *         "prefix"     => "my",
 *         "index"      => 1,
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
class Redis extends Adapter
{
	protected _lifetime = 8600 { get };

	protected _redis = null { get };

	/**
	 * Phalcon\Session\Adapter\Redis constructor
	 */
	public function __construct(array options = [])
	{
		var lifetime;

		if !isset options["host"] {
			let options["host"] = "127.0.0.1";
		}

		if !isset options["port"] {
			let options["port"] = 6379;
		}

		if !isset options["persistent"] {
			let options["persistent"] = false;
		}

		if fetch lifetime, options["lifetime"] {
			let this->_lifetime = lifetime;
		}

		let this->_redis = new Redis(
			new FrontendNone(["lifetime": this->_lifetime]),
			options
		);

		session_set_save_handler(
			[this, "open"],
			[this, "close"],
			[this, "read"],
			[this, "write"],
			[this, "destroy"],
			[this, "gc"]
		);

		parent::__construct(options);
	}

	/**
	 * {@inheritdoc}
	 */
	public function close() -> boolean
	{
		return true;
	}

	/**
	 * {@inheritdoc}
	 */
	public function destroy(string sessionId = null) -> boolean
	{
		var id;

		if sessionId === null {
			let id = this->getId();
		} else {
			let id = sessionId;
		}

		this->removeSessionData();

		return this->_redis->exists(id) ? this->_redis->delete(id) : true;
	}

	/**
	 * {@inheritdoc}
	 */
	public function gc() -> boolean
	{
		return true;
	}

	/**
	 * {@inheritdoc}
	 */
	public function open() -> boolean
	{
		return true;
	}

	/**
	 * {@inheritdoc}
	 */
	public function read(sessionId) -> string
	{
		return (string) this->_redis->get(sessionId, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 */
	public function write(string sessionId, string data) -> boolean
	{
		return this->_redis->save(sessionId, data, this->_lifetime);
	}
}
