
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Session\Adapter;
use Phalcon\Cache\Backend\Memcache;
use Phalcon\Cache\Frontend\Data as FrontendData;

/**
 * Phalcon\Session\Adapter\Memcache
 *
 * This adapter store sessions in memcache
 *
 * <code>
 * use Phalcon\Session\Adapter\Memcache;
 *
 * $session = new Memcache(
 *     [
 *         "uniqueId"   => "my-private-app",
 *         "host"       => "127.0.0.1",
 *         "port"       => 11211,
 *         "persistent" => true,
 *         "lifetime"   => 3600,
 *         "prefix"     => "my_",
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
class Memcache extends Adapter
{
	protected _memcache = null { get };

	protected _lifetime = 8600 { get };

	/**
	 * Phalcon\Session\Adapter\Memcache constructor
	 */
	public function __construct(array options = [])
	{
		var lifetime;

		if !isset options["host"] {
			let options["host"] = "127.0.0.1";
		}

		if !isset options["port"] {
			let options["port"] = 11211;
		}

		if !isset options["persistent"] {
			let options["persistent"] = 0;
		}

		if fetch lifetime, options["lifetime"] {
			let this->_lifetime = lifetime;
		}

		let this->_memcache = new Memcache(
			new FrontendData(["lifetime": this->_lifetime]),
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

	public function open() -> boolean
	{
		return true;
	}

	public function close() -> boolean
	{
		return true;
	}

	/**
	 * {@inheritdoc}
	 */
	public function read(string sessionId) -> string
	{
		return (string) this->_memcache->get(sessionId, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 */
	public function write(string sessionId, string data) -> boolean
	{
		return this->_memcache->save(sessionId, data, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 */
	public function destroy(var sessionId = null) -> boolean
	{
		var id;

		if sessionId === null {
			let id = this->getId();
		} else {
			let id = sessionId;
		}

		this->removeSessionData();

		if !empty id && this->_memcache->exists(id) {
			return (bool) this->_memcache->delete(id);
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
}
