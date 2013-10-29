
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * $frontCache = new Phalcon\Cache\Frontend\Base64(array(
 *		"lifetime" => 172800
 * ));
 *
 * //Create a MongoDB cache
 * $cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
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
class Mongo extends Phalcon\Cache\Backend implements Phalcon\Cache\BackendInterface
{

	protected _collection = null;


	/**
	* Phalcon\Cache\Backend\Mongo constructor
	*
	* @param Phalcon\Cache\FrontendInterface $frontend
	* @param array $options
	*/
	public function __construct(<Phalcon\Cache\FrontendInterface> frontend, options=null)
	{
		if !isset options["mongo"] {
			if !isset options["server"] {
				throw new Phalcon\Cache\Exception("The parameter 'server' is required");
			}
		}

		if !isset options["db"] {
			throw new Phalcon\Cache\Exception("The parameter 'db' is required");
		}

		if !isset options["collection"] {
			throw new Phalcon\Cache\Exception("The parameter 'collection' is required");
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
		var options, mongo, server, database, collection, mongoDatabase, mongoCollection;

		let mongoCollection = this->_collection;
		if typeof mongoCollection != "object" {
			let options = this->_options;

			/** 
            * If mongo is defined a valid Mongo object must be passed
            */
            if isset options["mongo"] {
            	let mongo = options["mongo"];
            	if typeof mongo != "object" {
            		throw new Phalcon\Cache\Exception("The 'mongo' parameter must be a valid Mongo instance");
            	}
            } else {
            	/** 
	            * Server must be defined otherwise
	            */
	            let server = options["server"];
	            if !server || typeof server != "string" {
	            	throw new Phalcon\Cache\Exception("The backend requires a valid MongoDB connection string");
	            }
	            let mongo = new Mongo();
            }

            /** 
            * Check if the database name is a string
            */
            let database = options["db"];
            if !database || typeof database != "string" {
            	throw new Phalcon\Cache\Exception("The backend requires a valid MongoDB db");
            }

            /** 
            * Retrieve the connection name
            */
            let collection = options["collection"];
            if !collection || typeof collection != "string" {
            	throw new Phalcon\Cache\Exception("The backend requires a valid MongoDB collection");
            }

            /** 
            * Make the connection and get the collection
            */
            let mongoDatabase = mongo->selectDb(database);
            mongoDatabase->selectCollection(collection);
 		} else {
 			return mongoCollection;
 		}

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
		var frontend, prefix, prefixedKey, collection, conditions, timeCondition, document,
			cachedContent;

		let conditions = [];
		let timeCondition = [];
		let frontend = this->_frontend;
		let prefix = this->_prefix;
		let prefixedKey = prefix . keyName;
		let this->_lastKey = prefixedKey;
		let collection = this->_getCollection();
		let conditions["key"] = prefixedKey;
		let timeCondition["$gt"] = time();
		let conditions["time"] = timeCondition;
		let document = collection->findOne(conditions);
		if typeof document == "array" {
			if isset document["data"] {
				let cachedContent = document["data"];
				if is_numeric(cachedContent) {
					return cachedContent;
				} else {
					return frontend->afterRetrieve(cachedContent);
				}
			} else {
				throw new Phalcon\Cache\Exception("The cache is corrupt");
			}
		} else {
			return null;
		}
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
		var lastkey, prefix, frontend, cachedContent, tmp, tt1, collection, timestamp, conditions,
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
			throw new Phalcon\Cache\Exception("The cache must be started first");
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
				let tt1 = frontend->getLifetime();
			} else {
				let tt1 = tmp;
			}
		} else {
			let tt1 = lifetime;
		}

		let collection = this->_getCollection();
		let timestamp = time() + intval(tt1);
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
	public function delete(keyName)
	{
		var prefix, prefixedKey, collection, conditions;

		let conditions = [];
		let prefix = this->_prefix;
		let prefixedKey = prefix . keyName;
		let collection = this->_getCollection();
		let conditions["key"] = prefixedKey;
		collection->remove(conditions);

		if rand() % 100 == 0 {
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
		var collection, fields, conditions, pattern, regex, timeCondition, documents,
			documentsArray, keys, index, key;

		let fields = [];
		let timeCondition = [];
		let collection = this->_getCollection();
		let fields["key"] = 1;
		let conditions = [];

		if prefix {
			let pattern = "/^". prefix ."/";
			let regex = MongoRegex(pattern);
			let conditions["key"] = regex; 
		}

		let timeCondition["$gt"] = time();
		let conditions["time"] = timeCondition;
		let documents = collection->find(conditions, fields);
		let keys = [];
		let documentsArray = iterator_to_array(documents);

		for index,key in documentsArray {
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
		var lastKey, collection, conditions, number, timeCondition;

		let conditions = [];
		let timeCondition = [];

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
		}

		if lastKey {
			let collection = this->_getCollection();
			let conditions["key"] = lastKey;
			let timeCondition["$gt"] = time();
			let conditions["time"] = timeCondition;
			let number = (int) collection->count(conditions);

			if number > 0 {
				return true;
			}
		}

		return false;
	}

	/**
	* gc
	* @return collection->remove(...)
	*/
	public function gc()
	{
		var conditions, timeCondition, collection;


		let timeCondition = ["$gt": time()];
		let conditions = ["time": timeCondition];
		let collection = this->_getCollection();
		return collection->remove(conditions);
	}

	/**
	* Increment of a given key by $value
	*
	* @param int|string $keyName
	* @param   long $value
	* @return  mixed
	*/
	public function increment(keyName, value=1)
	{
		var frontend, prefix, prefixedKey, collection, conditions, document, timestamp, lifetime, 
			tt1, modifiedTime, difference, notExpired, cachedContent, keys;

		let frontend = this->_frontend;
		let prefix = this->_prefix;
		let prefixedKey = prefix . keyName;
		
		let this->_lastKey = prefixedKey;
		
		let collection = this->_getCollection();
		let conditions = ["key": prefixedKey];
		let document = collection->findOne(conditions);
		let timestamp = time();
		let lifetime = this->_lastLifetime;
		
		if !lifetime {
			let tt1 = frontend->getLifetime();
		} else {
			let tt1 = lifetime();
		}
		
		if !isset document["time"] {
			throw new Phalcon\Cache\Exception("The cache is currupted");
		}
		
		let modifiedTime = document["time"];
		let difference = timestamp - tt1;
		let notExpired = difference < modifiedTime;

		/** 
        * The expiration is based on the column 'time'
        */
        if notExpired == true {
        	if !isset document["data"] {
        		throw new Phalcon\Cache\Exception("The cache is currupted");
        	}

        	let cachedContent = document["data"];

        	if is_numeric(cachedContent) {
        		let keys = cachedContent + value;
        		let tt1 = lifetime + timestamp;
        		this->save(prefixedKey, keys);
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
		var frontend, prefix, prefixedKey, collection, conditions, document, timestamp, lifetime, 
			tt1, modifiedTime, difference, notExpired, cachedContent, keys;

		let frontend = this->_frontend;
		let prefix = this->_prefix;
		let prefixedKey = prefix . keyName;
		
		let this->_lastKey = prefixedKey;
		
		let collection = this->_getCollection();
		let conditions = ["key": prefixedKey];
		let document = collection->findOne(conditions);
		let timestamp = time();
		let lifetime = this->_lastLifetime;
		
		if !lifetime {
			let tt1 = frontend->getLifetime();
		} else {
			let tt1 = lifetime();
		}
		
		if !isset document["time"] {
			throw new Phalcon\Cache\Exception("The cache is currupted");
		}
		
		let modifiedTime = document["time"];
		let difference = timestamp - tt1;
		let notExpired = difference < modifiedTime;

		/** 
        * The expiration is based on the column 'time'
        */
        if notExpired == true {
        	if !isset document["data"] {
        		throw new Phalcon\Cache\Exception("The cache is currupted");
        	}

        	let cachedContent = document["data"];

        	if is_numeric(cachedContent) {
        		let keys = cachedContent - value;
        		let tt1 = lifetime + timestamp;
        		this->save(prefixedKey, keys);
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
		var collection;

		let collection = this->_getCollection();
		
		collection->remove();

		if rand() % 100 == 0 {
			this->gc();
		}

		return true;
	}

}
