
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

namespace Phalcon\Assets;

/**
 * Phalcon\Assets\Resource
 *
 * Represents an asset resource
 *
 *<code>
 * $resource = new Phalcon\Assets\Resource('js', 'javascripts/jquery.js');
 *</code>
 */
 class Resource
{

	protected _type;

	protected _path;

	protected _local;

	protected _filter;

	protected _attributes;

	protected _sourcePath;

	protected _targetPath;

	protected _targetUri;

	/**
	 * Phalcon\Assets\Resource constructor
	 *
	 * @param string type
	 * @param string path
	 * @param boolean local
	 * @param boolean filter
	 * @param array attributes
	 */
	public function __construct(string type, string path, boolean local=true, boolean filter=true, attributes=null)
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
	 *
	 * @param string type
	 * @return Phalcon\Assets\Resource
	 */
	public function setType(string type) -> <Phalcon\Assets\Resource>
	{
		let this->_type = type;
		return this;
	}

	/**
	 * Returns the type of resource
	 *
	 * @return string
	 */
	public function getType() -> string
	{
		return this->_type;
	}

	/**
	 * Sets the resource's path
	 *
	 * @param string path
	 * @return Phalcon\Assets\Resource
	 */
	public function setPath(string path) -> <Phalcon\Assets\Resource>
	{
		let this->_path = path;
		return this;
	}

	/**
	 * Returns the URI/URL path to the resource
	 *
	 * @return string
	 */
	public function getPath() -> string
	{
		return this->_path;
	}

	/**
	 * Sets if the resource is local or external
	 *
	 * @param boolean local
	 * @return Phalcon\Assets\Resource
	 */
	public function setLocal(boolean local) -> <Phalcon\Assets\Resource>
	{
		let this->_local = local;
		return this;
	}

	/**
	 * Returns whether the resource is local or external
	 *
	 * @return boolean
	 */
	public function getLocal() -> boolean
	{
		return this->_local;
	}

	/**
	 * Sets if the resource must be filtered or not
	 *
	 * @param boolean filter
	 * @return Phalcon\Assets\Resource
	 */
	public function setFilter(boolean filter) -> <Phalcon\Assets\Resource>
	{
		let this->_filter = filter;
		return this;
	}

	/**
	 * Returns whether the resource must be filtered or not
	 *
	 * @return boolean
	 */
	public function getFilter() -> boolean
	{
		return this->_filter;
	}

	/**
	 * Sets extra HTML attributes
	 *
	 * @param array attributes
	 * @return Phalcon\Assets\Resource
	 */
	public function setAttributes(attributes)
	{
		let this->_attributes = attributes;
		return this;
	}

	/**
	 * Returns extra HTML attributes set in the resource
	 *
	 * @return array
	 */
	public function getAttributes()
	{
		return this->_attributes;
	}

	/**
     * Sets a target uri for the generated HTML
     *
     * @param string targetUri
     * @return Phalcon\Assets\Resource
     */
    public function setTargetUri(string targetUri) -> <Phalcon\Assets\Resource>
    {
        let this->_targetUri = targetUri;
        return this;
    }

    /**
     * Returns the target uri for the generated HTML
     *
     * @return string
     */
    public function getTargetUri() -> string
    {
        return this->_targetUri;
    }

	/**
	 * Sets the resource's source path
	 *
	 * @param string sourcePath
	 * @return Phalcon\Assets\Resource
	 */
	public function setSourcePath(string sourcePath) -> <Phalcon\Assets\Resource>
	{
		let this->_sourcePath = sourcePath;
		return this;
	}

	/**
	 * Returns the resource's target path
	 *
	 * @return string
	 */
	public function getSourcePath() -> string
	{
		return this->_targetPath;
	}

	/**
	 * Sets the resource's target path
	 *
	 * @param string targetPath
	 * @return Phalcon\Assets\Resource
	 */
	public function setTargetPath(string targetPath) -> <Phalcon\Assets\Resource>
	{
		let this->_targetPath = targetPath;
		return this;
	}

	/**
	 * Returns the resource's target path
	 *
	 * @return string
	 */
	public function getTargetPath() -> string
	{
		return this->_sourcePath;
	}

	/**
	 * Returns the content of the resource as an string
	 * Optionally a base path where the resource is located can be set
	 *
	 * @param string basePath
	 * @return string
	 */
	public function getContent(string basePath=null) -> string
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
				throw new Phalcon\Assets\Exception("Resource's content for '" . completePath . "' cannot be read");
			}

		}

		/**
		 * Use file_get_contents to respect the openbase_dir. Access urls must be enabled
		 */
		let content = file_get_contents(completePath);
		if content === false {
			throw new Phalcon\Assets\Exception("Resource's content for '" . completePath . "' cannot be read");
		}

		return content;
	}

	/**
	 * Returns the real target uri for the generated HTML
	 *
	 * @return string
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
	 *
	 * @param string basePath
	 * @return string
	 */
	public function getRealSourcePath(string basePath=null) -> string
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
	 *
	 * @param string basePath
	 * @return string
	 */
	public function getRealTargetPath(stirng basePath=null) -> string
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
