
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets;

/**
 * Phalcon\Assets\Asset
 *
 * Represents an asset asset
 *
 *<code>
 * $asset = new \Phalcon\Assets\Asset("js", "javascripts/jquery.js");
 *</code>
 */
class Asset implements AssetInterface
{
	/**
	 * @var array | null
	 */
	protected attributes { get };
	
	/**
	 * @var bool
	 */
	protected filter { get };

	/**
	 * @var bool
	 */
	protected local { get };
	
	/**
	 * @var string
	 */
	protected path { get };

	/**
	 * @var string
	 */
	protected sourcePath { get };

	/**
	 * @var string
	 */
	protected targetPath { get };

	/**
	 * @var string
	 */
	protected targetUri { get };
	
	/**
	 * @var string
	 */
	protected type { get };

	/**
	 * Phalcon\Assets\Asset constructor
	 */
	public function __construct(string type, string path, bool local = true, bool filter = true, array attributes = [])
	{
		let this->type = type,
			this->path = path,
			this->local = local,
			this->filter = filter,
			this->attributes = attributes;
	}

	/**
	 * Sets the asset's type
	 */
	public function setType(string type) -> <AssetInterface>
	{
		let this->type = type;
		return this;
	}

	/**
	 * Sets the asset's path
	 */
	public function setPath(string path) -> <AssetInterface>
	{
		let this->path = path;
		return this;
	}

	/**
	 * Sets if the asset is local or external
	 */
	public function setLocal(bool local) -> <AssetInterface>
	{
		let this->local = local;
		return this;
	}

	/**
	 * Sets if the asset must be filtered or not
	 */
	public function setFilter(bool filter) -> <AssetInterface>
	{
		let this->filter = filter;
		return this;
	}

	/**
	 * Sets extra HTML attributes
	 */
	public function setAttributes(array attributes) -> <AssetInterface>
	{
		let this->attributes = attributes;
		return this;
	}

	/**
	 * Sets a target uri for the generated HTML
	 */
	public function setTargetUri(string targetUri) -> <AssetInterface>
	{
		let this->targetUri = targetUri;
		return this;
	}

	/**
	 * Sets the asset's source path
	 */
	public function setSourcePath(string sourcePath) -> <AssetInterface>
	{
		let this->sourcePath = sourcePath;
		return this;
	}

	/**
	 * Sets the asset's target path
	 */
	public function setTargetPath(string targetPath) -> <AssetInterface>
	{
		let this->targetPath = targetPath;
		return this;
	}

	/**
	 * Returns the content of the asset as an string
	 * Optionally a base path where the asset is located can be set
	 */
	public function getContent(string basePath = null) -> string
	{
		var sourcePath, completePath, content;

		let sourcePath = this->sourcePath;
		if empty sourcePath {
			let sourcePath = this->path;
		}

		/**
		 * A base path for assets can be set in the assets manager
		 */
		let completePath = basePath . sourcePath;

		/**
		 * Local assets are loaded from the local disk
		 */
		if this->local {

			/**
			 * Check first if the file is readable
			 */
			if !file_exists(completePath) {
				throw new Exception("Asset's content for '" . completePath . "' cannot be read");
			}
		}

		/**
		 * Use file_get_contents to respect the openbase_dir. Access urls must be enabled
		 */
		let content = file_get_contents(completePath);
		if content === false {
			throw new Exception("Asset's content for '" . completePath . "' cannot be read");
		}

		return content;
	}

	/**
	 * Returns the real target uri for the generated HTML
	 */
	public function getRealTargetUri() -> string
	{
		var targetUri;

		let targetUri = this->targetUri;
		if empty targetUri {
			let targetUri = this->path;
		}
		return targetUri;
	}

	/**
	 * Returns the complete location where the asset is located
	 */
	public function getRealSourcePath(string basePath = null) -> string
	{
		var sourcePath;

		let sourcePath = this->sourcePath;
		if empty sourcePath {
			let sourcePath = this->path;
		}

		if this->local {
			/**
			 * Get the real template path
			 */
			return realpath(basePath . sourcePath);
		}

		return sourcePath;
	}

	/**
	 * Returns the complete location where the asset must be written
	 */
	public function getRealTargetPath(string basePath = null) -> string
	{
		var targetPath, completePath;

		let targetPath = this->targetPath;
		if empty targetPath {
			let targetPath = this->path;
		}

		if this->local {

			/**
			 * A base path for assets can be set in the assets manager
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
	 * Gets the asset's key.
	 */
	public function getAssetKey() -> string
	{
		var key;

		let key = this->getType() . ":" . this->getPath();

		return md5(key);
	}
}
