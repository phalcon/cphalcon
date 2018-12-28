
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

/**
 * Phalcon\Db\IndexInterface
 *
 * Interface for Phalcon\Db\Index
 */
interface IndexInterface
{
	/**
	 * Gets the index name
	 */
	public function getName() -> string;

	/**
	 * Gets the columns that corresponds the index
	 */
	public function getColumns() -> array;

	/**
	 * Gets the index type
	 */
	public function getType() -> string;

	/**
	 * Restore a Phalcon\Db\Index object from export
	 */
	public static function __set_state(array! data) -> <IndexInterface>;

}
