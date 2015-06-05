
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
use Phalcon\Session\AdapterInterface;
use Phalcon\Cache\Backend\Memcache;
use Phalcon\Cache\Frontend\Data as FrontendData;

/**
 * Phalcon\Session\Adapter\Memcache
 *
 * This adapter store sessions in memcache
 *
 *<code>
 * $session = new \Phalcon\Session\Adapter\Memcache(array(
 *    'uniqueId' => 'my-private-app'
 *    'host' => '127.0.0.1',
 *    'port' => 11211,
 *    'persistent' => TRUE,
 *    'lifetime' => 3600,
 *    'prefix' => 'my_'
 * ));
 *
 * $session->start();
 *
 * $session->set('var', 'some-value');
 *
 * echo $session->get('var');
 *</code>
 */
class Memcache extends Adapter implements AdapterInterface
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

	public function open()
	{
		return true;
	}

	public function close()
	{
		return true;
	}

	/**
	 * {@inheritdoc}
	 *
	 * @param string sessionId
	 * @return mixed
	 */
	public function read(sessionId)
	{
		return this->_memcache->get(sessionId, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 *
	 * @param string sessionId
	 * @param string data
	 */
	public function write(sessionId, data)
	{
		this->_memcache->save(sessionId, data, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 *
	 * @param  string  sessionId
	 * @return boolean
	 */
	public function destroy(sessionId = null) -> boolean
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
}
