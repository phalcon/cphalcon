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
 | Authors: Stanislav Kiryukhin <korsar.zn@gmail.com>                     |
 +------------------------------------------------------------------------+
 */
namespace Phalcon\Paginator;

/**
 * Phalcon\Paginator\Repository
 *
 * Repository of current state Phalcon\Paginator\AdapterInterface::getPaginate()
 */
class Repository implements RepositoryInterface
{
	protected _properties = [];
	protected _aliases = [];

	/**
	 * {@inheritdoc}
	 */
	public function setProperties(array properties) -> <Repository>
	{
		let this->_properties = properties;
		return this;
	}

	/**
	 * {@inheritdoc}
	 */
	public function setAliases(array aliases) -> <Repository>
	{
		let this->_aliases = aliases;
		return this;
	}

	/**
	 * {@inheritdoc}
	 */
	public function getAliases() -> array
	{
		return this->_aliases;
	}

	/**
	 * {@inheritdoc}
	 */
	public function getItems() -> var
	{
		return this->getProperty(self::PROPERTY_ITEMS, null);
	}
	
	/**
	 * {@inheritdoc}
	 */
	public function getTotalItems() -> int
	{
		return this->getProperty(self::PROPERTY_TOTAL_ITEMS, 0);
	}

	/**
	 * {@inheritdoc}
	 */
	public function getLimit() -> int
	{
		return this->getProperty(self::PROPERTY_LIMIT, 0);
	}

	/**
	 * {@inheritdoc}
	 */
	public function getFirst() -> int
	{
		return this->getProperty(self::PROPERTY_FIRST_PAGE, 0);
	}

	/**
	 * {@inheritdoc}
	 */
	public function getPrevious() -> int
	{
		return this->getProperty(self::PROPERTY_PREVIOUS_PAGE, 0);
	}

	/**
	 * {@inheritdoc}
	 */
	public function getCurrent() -> int
	{
		return this->getProperty(self::PROPERTY_CURRENT_PAGE, 0);
	}

	/**
	 * {@inheritdoc}
	 */
	public function getNext() -> int
	{
		return this->getProperty(self::PROPERTY_NEXT_PAGE, 0);
	}

	/**
	 * {@inheritdoc}
	 */
	public function getLast() -> int
	{
		return this->getProperty(self::PROPERTY_LAST_PAGE, 0);
	}

	/**
	 * {@inheritdoc}
	 */
	public function __get(string property)
	{
		var method;
		let method = "get" . camelize(this->getRealNameProperty(property));

		if method_exists(this, method) {
			return this->{method}();
		}

		/**
		 * A notice is shown if the property is not defined
		 */
		trigger_error("Access to undefined property " . get_class(this) . "::" . property);
		return null;
	}

	/**
	 * Gets value of property by name
	 */
	protected function getProperty(string property, var defaultValue = null) -> var
	{
		return isset this->_properties[property] ? this->_properties[property] : defaultValue;
	}

	/**
	 * Resolve legacy alias for compatibility with version 2.0.x
	 */
	protected function getRealNameProperty(string property) -> string
	{
		var aliases;
		let aliases = this->getAliases();

		if isset aliases[property] {
			return aliases[property];
		}

		/**
		 * Resolve legacy alias to maintain compatibility with version 2.0.x
		 */
		array legacyAliases = [
			"first" 	: self::PROPERTY_FIRST_PAGE,
			"before" 	: self::PROPERTY_PREVIOUS_PAGE,
			"current" 	: self::PROPERTY_CURRENT_PAGE,
			"next" 		: self::PROPERTY_NEXT_PAGE,
			"last" 		: self::PROPERTY_LAST_PAGE
		];

		if isset legacyAliases[property] {
			return legacyAliases[property];
		}

		return property;
	}
}
