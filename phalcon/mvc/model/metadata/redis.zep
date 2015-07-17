
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

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Cache\Backend\Redis;
use Phalcon\Cache\Frontend\Data as FrontendData;

/**
 * Phalcon\Mvc\Model\MetaData\Redis
 *
 * Stores model meta-data in the Redis.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 *
 *<code>
 *	$metaData = new Phalcon\Mvc\Model\Metadata\Redis(array(
 *		'prefix' => 'my-app-id',
 *		'lifetime' => 86400,
 *		'host' => 'localhost',
 *		'port' => 6379,
 *  	'persistent' => false
 *	));
 *</code>
 */
class Redis extends MetaData implements MetaDataInterface
{

	protected _ttl = 172800;

	protected _redis = null;

	/**
	 * Phalcon\Mvc\Model\MetaData\Redis constructor
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		var ttl;

		if typeof options != "array" {
			let options = [];
		}

		if !isset options["host"] {
			let options["host"] = "127.0.0.1";
		}

		if !isset options["port"] {
			let options["port"] = 6379;
		}

		if !isset options["persistent"] {
			let options["persistent"] = 0;
		}

		if !isset options["statsKey"] {
			let options["statsKey"] = "_PHCM_MM";
		}

		if fetch ttl, options["lifetime"] {
			let this->_ttl = ttl;
		}

		let this->_redis = new Redis(
			new FrontendData(["lifetime": this->_ttl]),
			options
		);

		let this->_metaData = [];
	}

	/**
	 * Reads metadata from Redis
	 */
	public function read(string! key) -> array | null
	{
		var data;
		
		let data = this->_redis->get(key);
		if typeof data == "array" {
			return data;
		}
		return null;
	}

	/**
	 * Writes the metadata to Redis
	 */
	public function write(string! key, var data) -> void
	{
		this->_redis->save(key, data);
	}

	/**
	 * Flush Redis data and resets internal meta-data in order to regenerate it
	 */
	public function reset() -> void
	{
		var meta, key, realKey;

		let meta = this->_metaData;

		if typeof meta == "array" {

			for key, _ in meta {
				let realKey = "meta-" . key;
				
				this->_redis->delete(realKey);
			}
		}

		parent::reset();
	}
}