
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
 * Phalcon\Cache\Backend\File
 *
 * Allows to cache output fragments using a file backend
 *
 *<code>
 *	//Cache the file for 2 days
 *	$frontendOptions = array(
 *		'lifetime' => 172800
 *	);
 *
 *  //Create a output cache
 *  $frontCache = \Phalcon\Cache\Frontend\Output($frontOptions);
 *
 *	//Set the cache directory
 *	$backendOptions = array(
 *		'cacheDir' => '../app/cache/'
 *	);
 *
 *  //Create the File backend
 *  $cache = new \Phalcon\Cache\Backend\File($frontCache, $backendOptions);
 *
 *	$content = $cache->start('my-cache');
 *	if ($content === null) {
 *  	echo '<h1>', time(), '</h1>';
 *  	$cache->save();
 *	} else {
 *		echo $content;
 *	}
 *</code>
 */
class File extends Phalcon\Cache\Backend implements Phalcon\Cache\BackendInterface
{

	/**
	 * Phalcon\Cache\Backend\File constructor
	 *
	 * @param	Phalcon\Cache\FrontendInterface frontend
	 * @param	array options
	 */
	public function __construct(<Phalcon\Cache\FrontendInterface> frontend, options=null)
	{
		if !options || isset options["cacheDir"] {
			throw new Phalcon\Cache\Exception("Cache directory must be specified with the option cacheDir");
		}

		this->__construct(frontend, options);
	}

	/**
	 * Returns a cached content
	 *
	 * @param int|string keyName
	 * @param   int lifetime
	 * @return  mixed
	 */
	public function get(keyName, lifetime=null)
	{
		var options, prefix, prefixedKey, cacheDir, cacheFile, frontend, now, lastLifetime, tmp, 
			ttl, diff, cachedContent;
		int modifiedTime;

		let options = this->_options;
		let prefix  = this->_prefix;

		let prefixedKey = prefix . keyName;
		let this->_lastKey = prefixedKey;

		if unlikely fetch cacheDir, options["cacheDir"] {
			throw new Phalcon\Cache\Exception("Unexpected inconsistency in options");
		}

		let cacheFile = cacheDir . prefixedKey;

		if file_exists(cacheFile) == true {
			let frontend = this->_frontend;

			/** 
			* Check if the file has expired
			*/
			let now = time();

			/** 
			* Take the lifetime from the frontend or read it from the set in start()
			*/
			if !lifetime {
				let lastLifetime = this->_lastLifetime;

				if !lastLifetime {
					let tmp = frontend->getLifeTime();
					let ttl = (int) tmp;
				} else {
					let ttl = (int) lastLifetime;
				}
			} else {
				let ttl = (int) lifetime;
			}

			let modifiedTime = (int) filemtime(cacheFile);

			let diff = now - ttl;
			
			/** 
			* The content is only retrieved if the content has not expired
			*/
			if !diff > modifiedTime {
				/** 
				* Use file-get-contents to control that the openbase_dir can't be skipped
				*/
				let cachedContent = get_file_contents(cacheFile);
				if !cachedContent {
					throw new Phalcon\Cache\Exception("Cache file ". cacheFile. " could not be opened");
				}

				if is_numeric(cachedContent) {
					return cachedContent;
				} else {
					/** 
					* Use the frontend to process the content of the cache
					*/
					return frontend->afterRetrieve(cachedContent);
				}
			}
		}
	}

	/**
	 * Stores cached content into the file backend and stops the frontend
	 *
	 * @param int|string keyName
	 * @param string content
	 * @param int lifetime
	 * @param boolean stopBuffer
	 */
	public function save(keyName=null, content=null, lifetime=null, stopBuffer=true) -> void
	{
		var lastKey, prefix, lastPrefix, frontend, options, cacheDir, isBuffering;

		if !keyName {
				let lastKey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastPrefix = prefix . keyName;
		}

		if !lastKey {
			throw new Phalcon\Cache\Exception("The cache must be started first");
		}

		let frontend = this->_frontend;
		let options = this->_options;

		if unlikely isset options["cacheDir"] {
			throw new Phalcon\Cache\Exception("Unexpected inconsistency in options");
		}

		let cacheFile = cacheDir . lastKey;

		if !content {
			let cachedContent = frontend->getContent();
		} else {
			let cachedContent = content;
		}

		let preparedContent = frontend->beforeStore(cachedContent);

		/** 
		* We use file_put_contents to respect open-base-dir directive
		*/
		if !is_numeric(cachedContent) {
			let status = file_put_contents(cacheFile, preparedContent);
		} else {
			let status = file_put_contents(cacheFile, cachedContent);
		}

		if !status {
			throw new Phalcon\Cache\Exception("Cache directory is not writable");
		}

		let isBuffering = frontend->isBuffering();
		
		if !stopBuffer {
			frontend->stop();
		}

		if isBuffering {
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
		var options, prefix, prefixedKey, cacheFile;

		let prefix = this->_prefix;
		let options = this->_options;
		let prefixedKey = prefix . keyName;

		if unlikely isset options["cacheDir"] {
			throw new Phalcon\Cache\Exception("Unexpected inconsistency in options");
		}

		let cacheFile = cacheDir . prefixedKey;
		if file_exists(cacheFile) {
			return unlink(cacheFile);
		}
		return false;
	}

	/**
	 * Query the existing cached keys
	 *
	 * @param string prefix
	 * @return array
	 */
	public function queryKeys(string prefix=null)
	{
		var options, item, isDirectory, key, ret;
		
		let ret = [];
		let options = this->_options;
		
		if unlikely isset options["cacheDir"] {
			throw new Phalcon\Cache\Exception("Unexpected inconsistency in options");
		}

		/** 
		* We use a directory iterator to traverse the cache dir directory
		*/
		for item in iterator(new DirectoryIterator(cacheDir)) {
			let isDirectory = item->isDir();

			if isDirectory===false {
				let key = item->getFileName();

				if start_with(key, prefix) {
					let ret[] = key;
				}
			}
		}

		return ret;
	}

	/**
	 * Checks if cache exists and it isn't expired
	 *
	 * @param string keyName
	 * @param   int lifetime
	 * @return boolean
	 */
	public function exists(string keyName=null, int lifetime=null) -> boolean
	{
		var lastKey, prefix, options, cacheDir, cacheFile, frontend;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastKey = prefix . keyName;
		}

		if lastKey {
			let options = this->_options;
			let cacheDir = options["cacheDir"];
			let cacheFile = cacheDir . lastKey;

			if file_exists(cacheFile) {
				let frontend = this->_frontend;

				/** 
				* Check if the file has expired
				*/
				if !lifetime {
					let tmp = frontend->getLifeTime();
					let ttl = (int) tmp;
				} else {
					let ttl = (int) lifetime;
				}

				let modifiedTime = filemtime(cacheFile);

				if modifiedTime+ ttl > time() {
					return true;
				}
			}
		}

		return false;
	}

	/**
	* Increment of a given key, by number $value
	* 
	* @param  string $keyName
	* @param  int $value
	* @return mixed
	*/
	public function increment(string keyName=null, int value=null)
	{
		var options, prefix, prefixedKey, cacheDir, cacheFile, frontend, timestamp, lifetime, ttl, 
			modifiedTime, difference, notExpired, cachedContent, status, result;

		let options = this->_options;
		let prefix = this->_prefix;
		let prefixedKey = prefix . keyName;
		let this->_lastKey = prefixedKey;
		let cacheDir = options["cacheDir"];
		let cacheFile = cacheDir . prefixedKey;
	
		if file_exists(cacheFile) {
			let frontend = this->_frontend;
			
			/** 
			* Check if the file has expired
			*/
			let timestamp = time();

			/** 
			* Take the lifetime from the frontend or read it from the set in start()
			*/
			if !lifetime {
				let lifetime = this->_lastLifetime;
				if !lifetime {
					let ttl = frontend->getLifeTime();
				} else {
					let ttl = lifetime;
				}
			} else {
				let ttl = lifetime;
			}

			let modifiedTime = filemtime(cacheFile);
			let difference = timestamp - ttl;
			let notExpired = difference < modifiedTime;

			/** 
			* The content is only retrieved if the content has not expired
			*/
			if notExpired {
				/** 
				* Use file-get-contents to control that the openbase_dir can't be skipped
				*/
				let cachedContent = file_get_contents(cacheFile);

				if !cachedContent {
					throw new Phalcon\Cache\Exception("Cache file ". cacheFile. " could not be opened");
				}

				if is_numeric(cachedContent) {
					let result = value + cachedContent;
					let status = file_put_contents(cacheFile, result);

					if !status {
						throw new Phalcon\Cache\Exception("Cache directory can't be written");
					}

					return result;
				}
			}
		}
	}

	/**
	* Decrement of a given key, by number $value
	* 
	* @param  string $keyName
	* @param  int $value
	* @return mixed
	*/
	public function decrement(string keyName=null, int value=null)
	{
		var options, prefix, prefixedKey, cacheDir, cacheFile, frontend, timestamp, lifetime, ttl, 
			modifiedTime, difference, notExpired, cachedContent, status, result;

		let options = this->_options;
		let prefix = this->_prefix;
		let prefixedKey = prefix . keyName;
		let this->_lastKey = prefixedKey;
		let cacheDir = options["cacheDir"];
		let cacheFile = cacheDir . prefixedKey;
	
		if file_exists(cacheFile) {
			let frontend = this->_frontend;
			
			/** 
			* Check if the file has expired
			*/
			let timestamp = time();

			/** 
			* Take the lifetime from the frontend or read it from the set in start()
			*/
			if !lifetime {
				let lifetime = this->_lastLifetime;
				if !lifetime {
					let ttl = frontend->getLifeTime();
				} else {
					let ttl = lifetime;
				}
			} else {
				let ttl = lifetime;
			}

			let modifiedTime = filemtime(cacheFile);
			let difference = timestamp - ttl;
			let notExpired = difference < modifiedTime;

			/** 
			* The content is only retrieved if the content has not expired
			*/
			if notExpired {
				/** 
				* Use file-get-contents to control that the openbase_dir can't be skipped
				*/
				let cachedContent = file_get_contents(cacheFile);

				if !cachedContent {
					throw new Phalcon\Cache\Exception("Cache file ". cacheFile. " could not be opened");
				}

				if is_numeric(cachedContent) {
					let result = value - cachedContent;
					let status = file_put_contents(cacheFile, result);

					if !status {
						throw new Phalcon\Cache\Exception("Cache directory can't be written");
					}

					return result;
				}
			}
		}
	}
}