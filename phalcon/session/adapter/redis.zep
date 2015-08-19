
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
use Phalcon\Cache\Backend\Redis;
use Phalcon\Cache\Frontend\Data as FrontendData;

/**
 * Phalcon\Session\Adapter\Redis
 *
 * This adapter store sessions in Redis
 *
 *<code>
 * $session = new \Phalcon\Session\Adapter\Redis(array(
 *    'uniqueId' => 'my-private-app',
 *	  'host' => 'localhost',
 *	  'port' => 6379,
 *	  'auth' => 'foobared',
 *    'persistent' => false,
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
class Redis extends Adapter implements AdapterInterface
{

	protected _redis = null { get };

	protected _lifetime = 8600 { get };

	/**
	 * Phalcon\Session\Adapter\Redis constructor
	 */
	public function __construct(array options = [])
	{
		let options = array_merge([
			"host": "127.0.0.1",
			"port": 6379,
			"persistent": false,
			"lifetime": this->_lifetime
		], options);

		let this->_lifetime = options["lifetime"];

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
		return this->_redis->get(sessionId, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 *
	 * @param string sessionId
	 * @param string data
	 */
	public function write(sessionId, data)
	{
		this->_redis->save(sessionId, data, this->_lifetime);
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
		return this->_redis->delete(sessionId);
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
		let this->_redis = new Redis(
			new FrontendData(["lifetime": this->_lifetime]),
			this->getOptions()
		);

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
