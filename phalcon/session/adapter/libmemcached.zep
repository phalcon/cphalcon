
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
 *<code>
 * $session = new Phalcon\Session\Adapter\Libmemcached(array(
 *     'servers' => array(
 *         array('host' => 'localhost', 'port' => 11211, 'weight' => 1),
 *     ),
 *     'client' => array(
 *         Memcached::OPT_HASH => Memcached::HASH_MD5,
 *         Memcached::OPT_PREFIX_KEY => 'prefix.',
 *     ),
 *    'lifetime' => 3600,
 *    'prefix' => 'my_',
 *
 *    'uniqueId' => 'my-private-app',
 *    'name' => 'session-name',
 *    'cookie_lifetime' => 'session-cookie-lifetime',
 *    'cookie_path' => 'session-cookie-path',
 *    'cookie_domain' => 'session-cookie-domain',
 *    'cookie_secure' => 'session-cookie-secure',
 *    'cookie_httponly' => 'session-cookie-httponly'
 * ));
 *
 * $session->start();
 *
 * $session->set('var', 'some-value');
 *
 * echo $session->get('var');
 *</code>
 */
class Libmemcached extends Adapter
{

	protected _libmemcached = null { get };

	protected _lifetime = 8600 { get };

	/**
	 * Phalcon\Session\Adapter\Libmemcached constructor
	 */
	public function __construct(array options)
	{
		if typeof options != "array" {
			throw new Exception("The options must be an array");
		}

		if !isset options["servers"] {
			throw new Exception("No servers given in options");
		}

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
	public function read(string sessionId) -> var
	{
		return this->_libmemcached->get(sessionId, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 */
	public function write(string sessionId, data) -> void
	{
		this->_libmemcached->save(sessionId, data, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 */
	public function destroy(var sessionId = null) -> boolean
	{
		if sessionId === null {
			let sessionId = this->getId();
		}
		return this->_libmemcached->delete(sessionId);
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
	protected function configure() -> void
	{
		let this->_lifetime = this->getOption("lifetime", this->getLifetime());

		let this->_libmemcached = new Libmemcached(
			new FrontendData(["lifetime": this->_lifetime]), [
				"servers": this->getOption("servers"),
				"client": this->getOption("client"),
				"prefix": this->getOption("prefix"),
				"statsKey": this->getOption("statsKey")
		]);

		session_set_save_handler(
			[this, "open"],
			[this, "close"],
			[this, "read"],
			[this, "write"],
			[this, "destroy"],
			[this, "gc"]
		);

		parent::configure();
	}
}
