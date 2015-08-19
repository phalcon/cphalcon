
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
use Phalcon\Cache\Backend\Memcache;
use Phalcon\Cache\Frontend\Data as FrontendData;

/**
 * Phalcon\Session\Adapter\Memcache
 *
 * This adapter store sessions in memcache
 *
 *<code>
 * $session = new \Phalcon\Session\Adapter\Memcache(array(
 *    'uniqueId' => 'my-private-app',
 *    'host' => '127.0.0.1',
 *    'port' => 11211,
 *    'persistent' => true,
 *    'lifetime' => 3600,
 *    'prefix' => 'my_',
 *
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
class Memcache extends Adapter
{

	protected _memcache = null { get };

	protected _lifetime = 8600 { get };

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
	public function read(string sessionId)
	{
		return this->_memcache->get(sessionId, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 */
	public function write(string sessionId, var data)
	{
		this->_memcache->save(sessionId, data, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 */
	public function destroy(var sessionId = null) -> boolean
	{
		if sessionId === null {
			let sessionId = this->getId();
		}
		return this->_memcache->delete(sessionId);
	}

	/**
	 * {@inheritdoc}
	 */
	public function gc()
	{
		return true;
	}

	/**
	 * {@inheritdoc}
	 */
	protected function configure() -> void
	{
		let this->_lifetime = this->getOption("lifetime", this->getLifetime());
		let this->_memcache = new Memcache(new FrontendData(["lifetime": this->_lifetime]), this->getOptions());

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
