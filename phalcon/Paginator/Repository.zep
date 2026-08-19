
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator;

use JsonSerializable;
use Phalcon\Contracts\Paginator\PaginatorTypes;

/**
 * Repository of current state Phalcon\Paginator\AdapterInterface::paginate()
 *
 * @phpstan-import-type paginator_aliases from PaginatorTypes
 * @phpstan-import-type paginator_properties from PaginatorTypes
 */
class Repository implements RepositoryInterface, JsonSerializable
{
    /**
     * @var paginator_aliases
     */
    protected array aliases = [];

    /**
     * @var paginator_properties
     */
    protected array properties = [];

    public function __get(string property) -> var | null
    {
        var method;

        let method = "get" . camelize(
            this->getRealNameProperty(property)
        );

        if method_exists(this, method) {
            return this->{method}();
        }

        /**
         * A notice is shown if the property is not defined
         */
        trigger_error(
            "Access to undefined property " . get_class(this) . "::" . property
        );

        return null;
    }

    /**
     * @return paginator_aliases
     */
    public function getAliases() -> array
    {
        return this->aliases;
    }

    public function getCurrent() -> int
    {
        return this->getProperty(self::PROPERTY_CURRENT_PAGE, 0);
    }

    public function getFirst() -> int
    {
        return this->getProperty(self::PROPERTY_FIRST_PAGE, 0);
    }

    public function getItems() -> var
    {
        return this->getProperty(self::PROPERTY_ITEMS, null);
    }

    public function getLast() -> int
    {
        return this->getProperty(self::PROPERTY_LAST_PAGE, 0);
    }

    public function getLimit() -> int
    {
        return this->getProperty(self::PROPERTY_LIMIT, 0);
    }

    public function getNext() -> int
    {
        return this->getProperty(self::PROPERTY_NEXT_PAGE, 0);
    }

    public function getPrevious() -> int
    {
        return this->getProperty(self::PROPERTY_PREVIOUS_PAGE, 0);
    }

    public function getTotalItems() -> int
    {
        return this->getProperty(self::PROPERTY_TOTAL_ITEMS, 0);
    }

    /**
     * @return paginator_properties
     */
    public function jsonSerialize() -> array
    {
        return this->properties;
    }

    /**
     * @param paginator_aliases $aliases
     */
    public function setAliases(array aliases) -> <RepositoryInterface>
    {
        let this->aliases = aliases;

        return this;
    }

    /**
     * @param paginator_properties $properties
     */
    public function setProperties(array properties) -> <RepositoryInterface>
    {
        let this->properties = properties;

        return this;
    }

    /**
     * Gets value of property by name
     *
     * The repository is filled by the adapters, which store an int under every
     * property that has an int default, so callers passing one are handed an
     * int back.
     *
     * @phpstan-return ($defaultValue is int ? int : mixed)
     */
    protected function getProperty(string property, var defaultValue = null) -> var
    {
        var value;

        if !fetch value, this->properties[property] {
            let value = defaultValue;
        }

        return value;
    }

    /**
     * Resolve alias property name
     */
    protected function getRealNameProperty(string property) -> string
    {
        var name;

        if !fetch name, this->aliases[property] {
            return property;
        }

        return name;
    }
}
