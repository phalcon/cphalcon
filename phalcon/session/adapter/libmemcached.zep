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
use Phalcon\Session\Exception;
use Phalcon\Cache\Backend\Libmemcached;
use Phalcon\Cache\Frontend\Data as FrontendData;

/**
 * Phalcon\Session\Adapter\Libmemcached
 *
 * This adapter store sessions in libmemcached
 *
 * <code>
 * use Phalcon\Session\Adapter\Libmemcached;
 *
 * $session = new Libmemcached(
 *     [
 *         "servers" => [
 *             [
 *                 "host"   => "localhost",
 *                 "port"   => 11211,
 *                 "weight" => 1,
 *             ],
 *         ],
 *         "client" => [
 *             \Memcached::OPT_HASH       => \Memcached::HASH_MD5,
 *             \Memcached::OPT_PREFIX_KEY => "prefix.",
 *         ],
 *         "lifetime" => 3600,
 *         "prefix"   => "my_",
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
class Libmemcached extends Adapter
{
	protected _libmemcached = null { get };

	protected _lifetime = 8600 { get };

	/**
	 * Phalcon\Session\Adapter\Libmemcached constructor
	 *
	 * @throws \Phalcon\Session\Exception
	 */
	public function __construct(array options)
	{
		var servers, client, lifetime, prefix, statsKey, persistentId;

		if !fetch servers, options["servers"] {
			throw new Exception("No servers given in options");
		}

		if !fetch client, options["client"] {
			let client = null;
		}

		if !fetch lifetime, options["lifetime"] {
			let lifetime = 8600;
		}

		// Memcached has an internal max lifetime of 30 days
		let this->_lifetime = min(lifetime, 2592000);

		if !fetch prefix, options["prefix"] {
			let prefix = null;
		}

		if !fetch statsKey, options["statsKey"] {
			let statsKey = "";
		}

		if !fetch persistentId, options["persistent_id"] {
			let persistentId = "phalcon-session";
		}

		let this->_libmemcached = new Libmemcached(
			new FrontendData(["lifetime": this->_lifetime]),
			[
				"servers":  servers,
				"client":   client,
				"prefix":   prefix,
				"statsKey": statsKey,
				"persistent_id": persistentId
			]
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

		if !empty id && this->_libmemcached->exists(id) {
			return (bool) this->_libmemcached->delete(id);
		}

		return true;
	}

	/**
	 * {@inheritdoc}
	 */
	public function gc() -> boolean
	{
		return true;
	}

	public function open() -> boolean
	{
		return true;
	}

	/**
	 * {@inheritdoc}
	 */
	public function read(string sessionId) -> string
	{
		return (string) this->_libmemcached->get(sessionId, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 */
	public function write(string sessionId, string data) -> boolean
	{
		return this->_libmemcached->save(sessionId, data, this->_lifetime);
	}
}
