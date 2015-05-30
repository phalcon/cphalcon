
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
use Phalcon\Session\AdapterInterface;
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
class Libmemcached extends Adapter implements AdapterInterface
{

	protected _libmemcached = NULL { get };

	protected _lifetime = 8600 { get };

	/**
	 * Phalcon\Session\Adapter\Libmemcached constructor
	 */
	public function __construct(array options)
	{
		var servers, client, lifetime, prefix, statsKey;

		if !fetch servers, options["servers"] {
			throw new Exception("No servers given in options");
		}

		if !fetch client, options["client"] {
			let client = null;
		}

		if !fetch lifetime, options["lifetime"] {
			let lifetime = 8600;
		}

		let this->_lifetime = lifetime;

		if !fetch prefix, options["prefix"] {
			let prefix = null;
		}

		if !fetch statsKey, options["statsKey"] {
			let statsKey = null;
		}

		let this->_libmemcached = new Libmemcached(
			new FrontendData(["lifetime": this->_lifetime]),
			[
				"servers":  servers,
				"client":   client,
				"prefix":   prefix,
				"statsKey": statsKey
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
	 *
	 * @param string sessionId
	 * @return mixed
	 */
	public function read(sessionId)
	{
		return this->_libmemcached->get(sessionId, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 *
	 * @param string sessionId
	 * @param string data
	 */
	public function write(sessionId, data)
	{
		this->_libmemcached->save(sessionId, data, this->_lifetime);
	}

	/**
	 * {@inheritdoc}
	 *
	 * @param  string  sessionId
	 * @return boolean
	 */
	public function destroy(sessionId = null)
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
}
