
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
 * Phalcon\Assets\Inline
 *
 * Represents an inline asset
 *
 *<code>
 * $inline = new \Phalcon\Assets\Inline("js", "alert('hello world');");
 *</code>
 */
class $Inline implements AssetInterface
{

	/**
	 * @var string
	 */
	protected type { get };

	protected content { get };

	/**
	 * @var bool
	 */
	protected filter { get };

	/**
	 * @var array | null
	 */
	protected attributes { get };

	/**
	 * Phalcon\Assets\Inline constructor
	 */
	public function __construct(string type, string content, bool filter = true, array attributes = [])
	{
		let this->type = type,
			this->content = content,
			this->filter = filter,
			this->attributes = attributes;
	}

	/**
	 * Sets the inline's type
	 */
	public function setType(string type) -> <AssetInterface>
	{
		let this->type = type;
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
	 * Gets the asset's key.
	 */
	public function getAssetKey() -> string
	{
		var key;

		let key = this->getType() . ":" . this->getContent();

		return md5(key);
	}
}
