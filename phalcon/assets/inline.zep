
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
 * Phalcon\Assets\Inline
 *
 * Represents an inline asset
 *
 *<code>
 * $inline = new \Phalcon\Assets\Inline("js", "alert('hello world');");
 *</code>
 */
class $Inline implements ResourceInterface
{

	/**
	 * @var string
	 */
	protected _type { get };

	protected _content { get };

	/**
	 * @var bool
	 */
	protected _filter { get };

	protected _attributes;

	/**
	 * Phalcon\Assets\Inline constructor
	 *
	 * @param string type
	 * @param string content
	 * @param boolean filter
	 * @param array attributes
	 */
	public function __construct(string type, string content, boolean filter = true, attributes = null)
	{
		let this->_type = type,
			this->_content = content,
			this->_filter = filter;
		if typeof attributes == "array" {
			let this->_attributes = attributes;
		}
	}

	/**
	 * Sets the inline's type
	 */
	public function setType(string type) -> <ResourceInterface>
	{
		let this->_type = type;
		return this;
	}

	/**
	 * Sets if the resource must be filtered or not
	 */
	public function setFilter(boolean filter) -> <ResourceInterface>
	{
		let this->_filter = filter;
		return this;
	}

	/**
	 * Sets extra HTML attributes
	 */
	public function setAttributes(array attributes) -> <ResourceInterface>
	{
		let this->_attributes = attributes;
		return this;
	}

	/**
	 * returns extra HTML attributes
	 */
	public function getAttributes() -> array | null
	{
		return this->_attributes;
	}

	/**
	 * Gets the resource's key.
	 */
	public function getResourceKey() -> string
	{
		var key;

		let key = this->getType() . ":" . this->getContent();

		return md5(key);
	}
}
