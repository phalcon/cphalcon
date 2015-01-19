
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		var servers, client, lifetime, prefix, statsKey;

		if typeof options != "array" {
			throw new Exception("The options must be an array");
		}

		if !isset options["servers"] {
			throw new Exception("No servers given in options");
		}

		let servers = options["servers"];

		if !isset options["client"] {
			let client = NULL;
		} else {
			let client = options["client"];
		}

		if fetch lifetime, options["lifetime"] {
			let this->_lifetime = lifetime;
		} else {
			let this->_lifetime = 8600;
		}

		if !fetch prefix, options["prefix"] {
			let prefix = NULL;
		} else {
			let prefix = options["prefix"];
		}

		if !fetch statsKey, options["statsKey"] {
			let statsKey = NULL;
		} else {
			let statsKey = options["statsKey"];
		}

		let this->_libmemcached = new Libmemcached(
			new FrontendData(["lifetime": this->_lifetime]),
			["servers": servers, "client": client, "prefix": prefix, "statsKey": statsKey]
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
    public function destroy(session_id = null)
    {
        if session_id === null {
            let session_id = this->getId();
        }
        return this->_libmemcached->delete(session_id);
    }

    /**
     * {@inheritdoc}
     */
    public function gc() -> boolean
    {
		return true;
	}

}
