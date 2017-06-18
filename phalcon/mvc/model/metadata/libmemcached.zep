
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

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Mvc\Model\MetaData;
use Phalcon\Cache\Backend\Libmemcached;
use Phalcon\Cache\Frontend\Data as FrontendData;
use Phalcon\Mvc\Model\Exception;

/**
 * Phalcon\Mvc\Model\MetaData\Libmemcached
 *
 * Stores model meta-data in the Memcache.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 *<code>
 * $metaData = new Phalcon\Mvc\Model\Metadata\Libmemcached(
 *     [
 *         "servers" => [
 *             [
 *                 "host"   => "localhost",
 *                 "port"   => 11211,
 *                 "weight" => 1,
 *             ],
 *         ],
 *         "client" => [
 *             Memcached::OPT_HASH       => Memcached::HASH_MD5,
 *             Memcached::OPT_PREFIX_KEY => "prefix.",
 *         ],
 *         "lifetime" => 3600,
 *         "prefix"   => "my_",
 *     ]
 * );
 *</code>
 */
class Libmemcached extends MetaData
{

	protected _ttl = 172800;

	protected _memcache = null;

	protected _metaData = [];

	/**
	 * Phalcon\Mvc\Model\MetaData\Libmemcached constructor
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		var ttl;

		if typeof options != "array" {
			let options = [];
		}

		if !isset options["servers"] {
			throw new Exception("No servers given in options");
		}

		if fetch ttl, options["lifetime"] {
			let this->_ttl = ttl;
		}

		if !isset options["statsKey"] {
			let options["statsKey"] = "_PHCM_MM";
		}

		let this->_memcache = new Libmemcached(
			new FrontendData(["lifetime": this->_ttl]),
			options
		);
	}

	/**
	 * Reads metadata from Memcache
	 */
	public function read(string! key) -> array | null
	{
		var data;

		let data = this->_memcache->get(key);
		if typeof data == "array" {
			return data;
		}
		return null;
	}

	/**
	 * Writes the metadata to Memcache
	 */
	public function write(string! key, var data) -> void
	{
		this->_memcache->save(key, data);
	}

	/**
	 * Flush Memcache data and resets internal meta-data in order to regenerate it
	 */
	public function reset() -> void
	{
		var meta, key, realKey;

		let meta = this->_metaData;

		if typeof meta == "array" {

			for key, _ in meta {
				let realKey = "meta-" . key;

				this->_memcache->delete(realKey);
			}
		}

		parent::reset();
	}
}
