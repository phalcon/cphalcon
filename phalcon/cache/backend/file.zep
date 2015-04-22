
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

namespace Phalcon\Cache\Backend;

use Phalcon\Cache\Exception;
use Phalcon\Cache\Backend;
use Phalcon\Cache\FrontendInterface;
use Phalcon\Cache\BackendInterface;

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
class File extends Backend implements BackendInterface
{
	/**
	 * Default to false for backwards compatibility
	 *
	 * @var boolean
	 */
	private _useSafeKey = false;

	/**
	 * Phalcon\Cache\Backend\File constructor
	 *
	 * @param	Phalcon\Cache\FrontendInterface frontend
	 * @param	array options
	 */
	public function __construct(<FrontendInterface> frontend, options = null)
	{
		var prefix, safekey;

		if !isset options["cacheDir"] {
			throw new Exception("Cache directory must be specified with the option cacheDir");
		}

		if fetch safekey, options["safekey"] {
			if typeof safekey !== "boolean" {
				throw new Exception("safekey option should be a boolean.");
			}

			let this->_useSafeKey = safekey;
		}

		// added to avoid having unsafe filesystem characters in the prefix
		if fetch prefix, options["prefix"] {
			if this->_useSafeKey && preg_match("/[^a-zA-Z0-9_.-]+/", prefix) {
				throw new Exception("FileCache prefix should only use alphanumeric characters.");
			}
		}

		parent::__construct(frontend, options);
	}

	/**
	 * Returns a cached content
	 *
	 * @param int|string keyName
	 * @param   int lifetime
	 * @return  mixed
	 */
	public function get(var keyName, lifetime = null)
	{
		var prefixedKey, cacheDir, cacheFile, frontend, lastLifetime, ttl, cachedContent, ret;
		int modifiedTime;

		let prefixedKey =  this->_prefix . this->getKey(keyName);
		let this->_lastKey = prefixedKey;

		if !fetch cacheDir, this->_options["cacheDir"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		let cacheFile = cacheDir . prefixedKey;

		if file_exists(cacheFile) == true {

			let frontend = this->_frontend;

			/**
			 * Take the lifetime from the frontend or read it from the set in start()
			 */
			if !lifetime {
				let lastLifetime = this->_lastLifetime;
				if !lastLifetime {
					let ttl = (int) frontend->getLifeTime();
				} else {
					let ttl = (int) lastLifetime;
				}
			} else {
				let ttl = (int) lifetime;
			}

			let modifiedTime = (int) filemtime(cacheFile);

			/**
			 * Check if the file has expired
			 * The content is only retrieved if the content has not expired
			 */
			if !(time() - ttl > modifiedTime) {

				/**
				 * Use file-get-contents to control that the openbase_dir can't be skipped
				 */
				let cachedContent = file_get_contents(cacheFile);
				if cachedContent === false {
					throw new Exception("Cache file ". cacheFile. " could not be opened");
				}

				if is_numeric(cachedContent) {
					return cachedContent;
				} else {
					/**
					 * Use the frontend to process the content of the cache
					 */
					let ret = frontend->afterRetrieve(cachedContent);
					return ret;
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
	public function save(var keyName = null, var content = null, lifetime = null, boolean stopBuffer = true) -> void
	{
		var lastKey, frontend, cacheDir, isBuffering, cacheFile, cachedContent, preparedContent, status;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . this->getKey(keyName);
		}

		if !lastKey {
			throw new Exception("Cache must be started first");
		}

		let frontend = this->_frontend;

		if !fetch cacheDir, this->_options["cacheDir"] {
			throw new Exception("Unexpected inconsistency in options");
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

		if status === false {
			throw new Exception("Cache file ". cacheFile . " could not be written");
		}

		let isBuffering = frontend->isBuffering();

		if stopBuffer === true {
			frontend->stop();
		}

		if isBuffering === true {
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
	public function delete(var keyName) -> boolean
	{
		var cacheFile, cacheDir;

		if !fetch cacheDir, this->_options["cacheDir"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		let cacheFile = cacheDir . this->_prefix . this->getKey(keyName);
		if file_exists(cacheFile) {
			return unlink(cacheFile);
		}

		return false;
	}

	/**
	 * Query the existing cached keys
	 *
	 * @param string|int prefix
	 * @return array
	 */
	public function queryKeys(var prefix = null) -> array
	{
		var item, key, cacheDir;
		array keys = [];

		if !fetch cacheDir, this->_options["cacheDir"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		/**
		 * We use a directory iterator to traverse the cache dir directory
		 */
		for item in iterator(new \DirectoryIterator(cacheDir)) {

			if likely item->isDir() === false {
				let key = item->getFileName();
				if prefix !== null {
					if starts_with(key, prefix) {
						let keys[] = key;
					}
				} else {
					let keys[] = key;
				}
			}
		}

		return keys;
	}

	/**
	 * Checks if cache exists and it isn't expired
	 *
	 * @param string|int keyName
	 * @param   int lifetime
	 * @return boolean
	 */
	public function exists(var keyName = null, int lifetime = null) -> boolean
	{
		var lastKey, prefix, cacheFile;
		int ttl;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastKey = prefix . this->getKey(keyName);
		}

		if lastKey {

			let cacheFile = this->_options["cacheDir"] . lastKey;

			if file_exists(cacheFile) {

				/**
				 * Check if the file has expired
				 */
				if !lifetime {
					let ttl = (int) this->_frontend->getLifeTime();
				} else {
					let ttl = (int) lifetime;
				}

				if filemtime(cacheFile) + ttl > time() {
					return true;
				}
			}
		}

		return false;
	}

	/**
	 * Increment of a given key, by number $value
	 *
	 * @param  string|int keyName
	 * @param  int value
	 * @return mixed
	 */
	public function increment(var keyName = null, int value = 1)
	{
		var prefixedKey, cacheFile, frontend, timestamp, lifetime, ttl,
			cachedContent, result;

		let prefixedKey = this->_prefix . this->getKey(keyName),
			this->_lastKey = prefixedKey,
			cacheFile = this->_options["cacheDir"] . prefixedKey;

		if file_exists(cacheFile) {

			let frontend = this->_frontend;

			/**
			 * Check if the file has expired
			 */
			let timestamp = time();

			/**
			 * Take the lifetime from the frontend or read it from the set in start()
			 */
			let lifetime = this->_lastLifetime;
			if !lifetime {
				let ttl = frontend->getLifeTime();
			} else {
				let ttl = lifetime;
			}

			/**
			 * The content is only retrieved if the content has not expired
			 */
			if (timestamp - ttl) < filemtime(cacheFile) {

				/**
				 * Use file-get-contents to control that the openbase_dir can't be skipped
				 */
				let cachedContent = file_get_contents(cacheFile);

				if cachedContent === false {
					throw new Exception("Cache file " . cacheFile . " could not be opened");
				}

				if is_numeric(cachedContent) {

					let result = cachedContent + value;
					if file_put_contents(cacheFile, result) === false {
						throw new Exception("Cache directory could not be written");
					}

					return result;
				}
			}
		}
	}

	/**
	 * Decrement of a given key, by number $value
	 *
	 * @param  string|int keyName
	 * @param  int value
	 * @return mixed
	 */
	public function decrement(var keyName = null, int value = 1)
	{
		var prefixedKey, cacheFile, timestamp, lifetime, ttl, cachedContent, result;

		let prefixedKey = this->_prefix . this->getKey(keyName),
			this->_lastKey = prefixedKey,
			cacheFile = this->_options["cacheDir"] . prefixedKey;

		if file_exists(cacheFile) {

			/**
			 * Check if the file has expired
			 */
			let timestamp = time();

			/**
			 * Take the lifetime from the frontend or read it from the set in start()
			 */
			let lifetime = this->_lastLifetime;
			if !lifetime {
				let ttl = this->_frontend->getLifeTime();
			} else {
				let ttl = lifetime;
			}

			/**
			 * The content is only retrieved if the content has not expired
			 */
			if (timestamp - ttl) < filemtime(cacheFile) {

				/**
				 * Use file-get-contents to control that the openbase_dir can't be skipped
				 */
				let cachedContent = file_get_contents(cacheFile);

				if cachedContent === false {
					throw new Exception("Cache file " . cacheFile . " could not be opened");
				}

				if is_numeric(cachedContent) {

					let result = cachedContent - value;
					if file_put_contents(cacheFile, result) === false {
						throw new Exception("Cache directory can't be written");
					}

					return result;
				}
			}
		}
	}

	/**
	 * Immediately invalidates all existing items.
	 */
	public function flush() -> boolean
	{
		var prefix, cacheDir, item, key, cacheFile;

		let prefix = this->_prefix;

		if !fetch cacheDir, this->_options["cacheDir"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		for item in iterator(new \DirectoryIterator(cacheDir)) {

			if likely item->isFile() == true {
				let key = item->getFileName(),
					cacheFile = item->getPathName();

				if empty prefix || starts_with(key, prefix) {
					if  !unlink(cacheFile) {
						return false;
					}
				}
			}
		}

		return true;
	}

	/**
	 * Return a file-system safe identifier for a given key
	 */
	public function getKey(key) -> string
	{
		if this->_useSafeKey === true {
			return md5(key);
		}

		return key;
	}

	/**
	 * Set whether to use the safekey or not
	 *
	 * @return this
	 */
	public function useSafeKey(bool useSafeKey)
	{
		let this->_useSafeKey = useSafeKey;

		return this;
	}
}
