
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Db;

/**
 * Interface for Phalcon\Db\Column
 */
interface ColumnInterface
{
    /**
     * Check whether field absolute to position in table
     */
    public function getAfterPosition() -> string;

    /**
     * Returns the type of bind handling
     */
    public function getBindType() -> int;

    /**
     * Returns default value of column
     */
    public function getDefault() -> var;

    /**
     * Returns column name
     */
    public function getName() -> string;

    /**
     * Returns column scale
     */
    public function getScale() -> int;

    /**
     * Returns column size
     */
    public function getSize() -> int | string;

    /**
     * Returns column type
     */
    public function getType() -> int;

    /**
     * Returns column type reference
     */
    public function getTypeReference() -> int;

    /**
     * Returns column type values
     */
    public function getTypeValues() -> array | string;


    /**
     * Check whether column has default value
     */
    public function hasDefault() -> bool;

    /**
     * Auto-Increment
     */
    public function isAutoIncrement() -> bool;

    /**
     * Check whether column have first position in table
     */
    public function isFirst() -> bool;

    /**
     * Not null
     */
    public function isNotNull() -> bool;

    /**
     * Check whether column have an numeric type
     */
    public function isNumeric() -> bool;

    /**
     * Column is part of the primary key?
     */
    public function isPrimary() -> bool;

    /**
     * Returns true if number column is unsigned
     */
    public function isUnsigned() -> bool;
}
