
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

namespace Phalcon\Assets;

/**
 * Phalcon\Assets\Resource
 *
 * Represents an asset resource
 *
 *<code>
 * $resource = new \Phalcon\Assets\Resource('js', 'javascripts/jquery.js');
 *</code>
 */
class $Resource
{

	protected _type { get };

	protected _path { get };

	protected _local { get };

	protected _filter { get };

	protected _attributes { get };

	protected _sourcePath { get };

	protected _targetPath { get };

	protected _targetUri { get };

	/**
	 * Phalcon\Assets\Resource constructor
	 *
	 * @param string type
	 * @param string path
	 * @param boolean local
	 * @param boolean filter
	 * @param array attributes
	 */
	public function __construct(string type, string path, boolean local = true, boolean filter = true, attributes = null)
	{
		let this->_type = type,
			this->_path = path,
			this->_local = local,
			this->_filter = filter;
		if typeof attributes == "array" {
			let this->_attributes = attributes;
		}
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
		var targetUri;

		let targetUri = this->_targetUri;
		if empty targetUri {
			let targetUri = this->_path;
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

}
