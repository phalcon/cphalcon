
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

namespace Phalcon\Cache\Backend;

/**
 * Phalcon\Cache\Backend\Mongo
 *
 * Allows to cache output fragments, PHP data or raw data to a MongoDb backend
 *
 *<code>
 *
 * // Cache data for 2 days
 * $frontCache = new \Phalcon\Cache\Frontend\Base64(array(
 *		"lifetime" => 172800
 * ));
 *
 * //Create a MongoDB cache
 * $cache = new \Phalcon\Cache\Backend\Mongo($frontCache, array(
 *		'server' => "mongodb://localhost",
 *      'db' => 'caches',
 *		'collection' => 'images'
 * ));
 *
 * //Cache arbitrary data
 * $cache->save('my-data', file_get_contents('some-image.jpg'));
 *
 * //Get data
 * $data = $cache->get('my-data');
 *
 *</code>
 */
class Mongo extends \Phalcon\Cache\Backend implements \Phalcon\Cache\BackendInterface
{

	protected _collection = null;


	/**
	* Phalcon\Cache\Backend\Mongo constructor
	*
	* @param Phalcon\Cache\FrontendInterface $frontend
	* @param array $options
	*/
	public function __construct(<\Phalcon\Cache\FrontendInterface> frontend, options=null)
	{
		if !isset options["mongo"] {
			if !isset options["server"] {
				throw new \Phalcon\Cache\Exception("The parameter 'server' is required");
			}
		}

		if !isset options["db"] {
			throw new \Phalcon\Cache\Exception("The parameter 'db' is required");
		}

		if !isset options["collection"] {
			throw new \Phalcon\Cache\Exception("The parameter 'collection' is required");
		}

		parent::__construct(frontend, options);
	}

	/**
	* Returns a MongoDb collection based on the backend parameters
	*
	* @return MongoCollection
	*/
	public function _getCollection()
	{
		var options, mongo, server, database, collection, mongoCollection;

		let mongoCollection = this->_collection;
		if typeof mongoCollection != "object" {
			let options = this->_options;

			/**
			 * If mongo is defined a valid Mongo object must be passed
			 */
			if fetch mongo, options["mongo"] {
				if typeof mongo != "object" {
					throw new \Phalcon\Cache\Exception("The 'mongo' parameter must be a valid Mongo instance");
				}
			} else {
				/**
				 * Server must be defined otherwise
				 */
				let server = options["server"];
				if !server || typeof server != "string" {
					throw new \Phalcon\Cache\Exception("The backend requires a valid MongoDB connection string");
				}
				let mongo = new \Mongo();
			}

			/**
			 * Check if the database name is a string
			 */
			let database = options["db"];
			if !database || typeof database != "string" {
				throw new \Phalcon\Cache\Exception("The backend requires a valid MongoDB db");
			}

			/**
			* Retrieve the connection name
			*/
			let collection = options["collection"];
			if !collection || typeof collection != "string" {
				throw new \Phalcon\Cache\Exception("The backend requires a valid MongoDB collection");
			}

			/**
			* Make the connection and get the collection
			*/
			mongo->selectDb(database)->selectCollection(collection);
		}

		return mongoCollection;

	}

	/**
	 * Returns a cached content
	 *
	 * @param int|string keyName
	 * @param   long lifetime
	 * @return  mixed
	 */
	public function get(keyName, lifetime=null)
	{
		var frontend, prefixedKey, conditions,  document, cachedContent;

		let conditions = [];
		let frontend = this->_frontend;
		let prefixedKey = this->_prefix . keyName;
		let this->_lastKey = prefixedKey;

		let conditions["key"] = prefixedKey;
		let conditions["time"] = ["$gt": time()];

		let document = this->_getCollection()->findOne(conditions);
		if typeof document == "array" {
			if fetch cachedContent, document["data"] {
				if is_numeric(cachedContent) {
					return cachedContent;
				}
				return frontend->afterRetrieve(cachedContent);
			} else {
				throw new \Phalcon\Cache\Exception("The cache is corrupt");
			}
		}

		return null;
	}

	/**
	 * Stores cached content into the file backend and stops the frontend
	 *
	 * @param int|string keyName
	 * @param string content
	 * @param long lifetime
	 * @param boolean stopBuffer
	 */
	public function save(keyName=null, content=null, lifetime=null, stopBuffer=true)
	{
		var lastkey, prefix, frontend, cachedContent, tmp, ttl, collection, timestamp, conditions,
			document, preparedContent, isBuffering, data;

		let conditions = [];
		let data = [];

		if !keyName {
			let lastkey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastkey = prefix . keyName;
		}

		if !lastkey {
			throw new \Phalcon\Cache\Exception("The cache must be started first");
		}

		let frontend = this->_frontend;
		if !content {
			let cachedContent = frontend->getContent();
		} else {
			let cachedContent = content;
		}

		if !is_numeric(cachedContent) {
			let preparedContent = frontend->beforeStore(cachedContent);
		}

		if !lifetime {
			let tmp = this->_lastLifetime;
			if !tmp {
				let ttl = frontend->getLifetime();
			} else {
				let ttl = tmp;
			}
		} else {
			let ttl = lifetime;
		}

		let collection = this->_getCollection();
		let timestamp = time() + intval(ttl);
		let conditions["key"] = lastkey;
		let document = collection->findOne(conditions);

		if typeof document == "array" {
			let document["time"] = timestamp;
			if !is_numeric(cachedContent) {
				let document["data"] = preparedContent;
			} else {
				let document["data"] = cachedContent;
			}
			collection->save(document);
		} else {
			let data["key"] = lastkey;
			let data["time"] = timestamp;
			if !is_numeric(cachedContent) {
				let data["data"] = preparedContent;
			} else {
				let data["data"] = cachedContent;
			}
			collection->save(data);
		}

		let isBuffering = frontend->isBuffering();

		if stopBuffer == true {
			frontend->stop();
		}

		if isBuffering == true {
			echo cachedContent;
		}

		let this->_started = false;
	}

	/**
	 * Deletes a value from the cache by its key
	 *
	 * @param int|string keyName
	 * @return boolean
	 */
	public function delete(keyName) -> boolean
	{

		this->_getCollection()->remove(["key": this->_prefix . keyName]);
		if ((int) rand()) % 100 == 0 {
			this->gc();
		}

		return true;
	}

	/**
	 * Query the existing cached keys
	 *
	 * @param string prefix
	 * @return array
	 */
	public function queryKeys(prefix=null)
	{
		var fields, conditions, keys, index, key;

		let fields = ["key": 1];
		let conditions = [];

		if prefix {
			let conditions["key"] = new \MongoRegex("/^" . prefix . "/");
		}

		let conditions["time"] = ["$gt": time()];

		let keys = [];
		for index, key in iterator_to_array(this->_getCollection()->find(conditions, fields)) {
			if index == "key" {
				let keys[] = key;
			}
		}

		return keys;
	}

	/**
	 * Checks if cache exists and it isn't expired
	 *
	 * @param string keyName
	 * @param   long lifetime
	 * @return boolean
	 */
	public function exists(keyName=null, lifetime=null)
	{
		var lastKey;

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
		}

		if lastKey {
			return this->_getCollection()->count(["key": lastKey, "time": ["$gt": time()]]) > 0;
		}

		return false;
	}

	/**
	 * gc
	 * @return collection->remove(...)
	 */
	public function gc()
	{
		return this->_getCollection()->remove(["time": ["$gt": time()]]);
	}

	/**
	 * Increment of a given key by $value
	 *
	 * @param int|string keyName
	 * @param   long value
	 * @return  mixed
	 */
	public function increment(keyName, value=1)
	{
		var frontend,  prefixedKey, document, timestamp, lifetime,
			ttl, modifiedTime,  cachedContent;

		let frontend = this->_frontend;

		let prefixedKey = this->_prefix . keyName;
		let this->_lastKey = prefixedKey;

		let document = this->_getCollection()->findOne(["key": prefixedKey]);
		let timestamp = time();
		let lifetime = this->_lastLifetime;

		if !lifetime {
			let ttl = frontend->getLifetime();
		} else {
			let ttl = lifetime;
		}

		if !fetch modifiedTime, document["time"] {
			throw new \Phalcon\Cache\Exception("The cache is currupted");
		}

		/**
		* The expiration is based on the column 'time'
		*/
		if (timestamp - ttl) < modifiedTime {

			if !fetch cachedContent, document["data"] {
				throw new \Phalcon\Cache\Exception("The cache is currupted");
			}

			if is_numeric(cachedContent) {
				this->save(prefixedKey, cachedContent + value, lifetime + timestamp);
			}
		}
		return null;
	}

	/**
	* Decrement of a given key by $value
	*
	* @param int|string $keyName
	* @param   long $value
	* @return  mixed
	*/
	public function decrement(keyName, value=1)
	{
		var prefixedKey, document, timestamp, lifetime, ttl, modifiedTime, cachedContent;

		let prefixedKey = this->_prefix . keyName;

		let this->_lastKey = prefixedKey;

		let document = this->_getCollection()->findOne(["key": prefixedKey]);
		let timestamp = time();
		let lifetime = this->_lastLifetime;

		if !lifetime {
			let ttl = this->_frontend->getLifetime();
		} else {
			let ttl = lifetime;
		}

		if !fetch modifiedTime, document["time"] {
			throw new \Phalcon\Cache\Exception("The cache is currupted");
		}

		/**
		* The expiration is based on the column 'time'
		*/
		if (timestamp - ttl) < modifiedTime == true {

			if !fetch cachedContent, document["data"] {
				throw new \Phalcon\Cache\Exception("The cache is currupted");
			}

			if is_numeric(cachedContent) {
				this->save(prefixedKey, cachedContent - value, lifetime + timestamp);
			}
		}
		return null;
	}

	/**
	* Immediately invalidates all existing items.
	*
	* @return bool
	*/
	public function flush()
	{

		this->_getCollection()->remove();

		if (int) rand() % 100 == 0 {
			this->gc();
		}

		return true;
	}

}
