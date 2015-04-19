
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
class Redis extends Adapter implements \SessionHandlerInterface
{

	protected _redis = null { get };

	protected _lifetime = 8600 { get };

	/**
	 * Re-initialize existing session, or creates a new one.
	 */
	public function open(string save_path, string session_name) -> boolean
	{
		return true;
	}

	/**
	 * Closes the current session.
	 */
	public function close() -> boolean
	{
		return true;
	}

	/**
	 * Reads the session data from the session storage, and returns the results.
	 * Note: SessionHandlerInterface::open() is called immediately before this function.
	 */
	public function read(string session_id) -> var
	{
		return this->_redis->get(session_id, this->_lifetime);
	}

	/**
	 * Writes the session data to the session storage.
	 * Note: SessionHandlerInterface::close() is called immediately after this function.
	 */
	public function write(string session_id, var session_data) -> boolean
	{
		this->_redis->save(session_id, session_data, this->_lifetime);
		return true;
	}

	/**
	 * Destroys the session data in the session storage.
	 */
	public function destroy(string session_id = null) -> boolean
	{
		return this->_redis->delete(session_id ? session_id : this->getId());
	}

	/**
	 * Cleans up expired sessions.
	 */
	public function gc(string maxlifetime) -> boolean
	{
		return true;
	}

	/**
	 * {@inheritdoc}
	 */
	public function setOptions(array! options) -> void
	{
		if isset options["lifetime"] {
			let this->_lifetime = options["lifetime"];
		}

		parent::setOptions(options);
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

		session_set_save_handler(this);
		parent::configure();
	}
}
