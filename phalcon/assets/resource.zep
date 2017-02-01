
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

namespace Phalcon\Assets;

/**
 * Phalcon\Assets\Resource
 *
 * Represents an asset resource
 *
 *<code>
 * $resource = new \Phalcon\Assets\Resource("js", "javascripts/jquery.js");
 *</code>
 */
class $Resource implements ResourceInterface
{
	/**
	 * @var string
	 */
	protected _type { get };

	/**
	 * @var string
	 */
	protected _path { get };

	/**
	 * @var boolean
	 */
	protected _local { get };

	/**
	 * @var boolean
	 */
	protected _filter { get };

	/**
	 * @var array | null
	 */
	protected _attributes { get };

	protected _sourcePath { get };

	protected _targetPath { get };

	protected _targetUri { get };

	protected _version { set, get };

	protected _autoVersion = false { set };

	/**
	 * Phalcon\Assets\Resource constructor
	 */
	public function __construct(string type, string path, boolean local = true, boolean filter = true, attributes = null, var version = null, var autoVersion = null)
	{
		let this->_type = type,
			this->_path = path,
			this->_local = local,
			this->_filter = filter,
			this->_attributes = attributes,
			this->_version = version,
			this->_autoVersion = autoVersion;
	}

	/**
	 * Sets the resource's type
	 */
	public function setType(string type) -> <$Resource>
	{
		let this->_type = type;
		return this;
	}

	/**
	 * Sets the resource's path
	 */
	public function setPath(string path) -> <$Resource>
	{
		let this->_path = path;
		return this;
	}

	/**
	 * Sets if the resource is local or external
	 */
	public function setLocal(boolean local) -> <$Resource>
	{
		let this->_local = local;
		return this;
	}

	/**
	 * Sets if the resource must be filtered or not
	 */
	public function setFilter(boolean filter) -> <$Resource>
	{
		let this->_filter = filter;
		return this;
	}

	/**
	 * Sets extra HTML attributes
	 */
	public function setAttributes(array attributes) -> <$Resource>
	{
		let this->_attributes = attributes;
		return this;
	}

	/**
	 * Sets a target uri for the generated HTML
	 */
	public function setTargetUri(string targetUri) -> <$Resource>
	{
		let this->_targetUri = targetUri;
		return this;
	}

	/**
	 * Sets the resource's source path
	 */
	public function setSourcePath(string sourcePath) -> <$Resource>
	{
		let this->_sourcePath = sourcePath;
		return this;
	}

	/**
	 * Sets the resource's target path
	 */
	public function setTargetPath(string targetPath) -> <$Resource>
	{
		let this->_targetPath = targetPath;
		return this;
	}

	/**
	 * Returns the content of the resource as an string
	 * Optionally a base path where the resource is located can be set
	 */
	public function getContent(string basePath = null) -> string
	{
		var sourcePath, completePath, content;

		let sourcePath = this->_sourcePath;
		if empty sourcePath {
			let sourcePath = this->_path;
		}

		/**
		 * A base path for resources can be set in the assets manager
		 */
		let completePath = basePath . sourcePath;

		/**
		 * Local resources are loaded from the local disk
		 */
		if this->_local {

			/**
			 * Check first if the file is readable
			 */
			if !file_exists(completePath) {
				throw new Exception("Resource's content for '" . completePath . "' cannot be read");
			}
		}

		/**
		 * Use file_get_contents to respect the openbase_dir. Access urls must be enabled
		 */
		let content = file_get_contents(completePath);
		if content === false {
			throw new Exception("Resource's content for '" . completePath . "' cannot be read");
		}

		return content;
	}

	/**
	 * Returns the real target uri for the generated HTML
	 */
	public function getRealTargetUri() -> string
	{
		var targetUri, version, modificationTime;

		let targetUri = this->_targetUri;
		if empty targetUri {
			let targetUri = this->_path;
		}

		let version = this->_version;

		if this->_autoVersion && this->_local {
			let modificationTime = filemtime(this->getRealSourcePath());
			let version = version ? version . "." . modificationTime : modificationTime;
		}

		if version {
			let targetUri = targetUri . "?ver=" . version;
		}

		return targetUri;
	}

	/**
	 * Returns the complete location where the resource is located
	 */
	public function getRealSourcePath(string basePath = null) -> string
	{
		var sourcePath;

		let sourcePath = this->_sourcePath;
		if empty sourcePath {
			let sourcePath = this->_path;
		}

		if this->_local {
			/**
			 * Get the real template path
			 */
			return realpath(basePath . sourcePath);
		}

		return sourcePath;
	}

	/**
	 * Returns the complete location where the resource must be written
	 */
	public function getRealTargetPath(string basePath = null) -> string
	{
		var targetPath, completePath;

		let targetPath = this->_targetPath;
		if empty targetPath {
			let targetPath = this->_path;
		}

		if this->_local {

			/**
			 * A base path for resources can be set in the assets manager
			 */
			let completePath = basePath . targetPath;

			/**
			 * Get the real template path, the target path can optionally don't exist
			 */
			if file_exists(completePath) {
				return realpath(completePath);
			}

			return completePath;
		}

		return targetPath;
	}

    /**
     * Checks if resource is using auto version
     */
	public function isAutoVersion() -> boolean | null
	{
		return this->_autoVersion;
	}

	/**
	 * Gets the resource's key.
	 */
	public function getResourceKey() -> string
	{
		var key;

		let key = this->getType() . ":" . this->getPath();

		return md5(key);
	}
}
