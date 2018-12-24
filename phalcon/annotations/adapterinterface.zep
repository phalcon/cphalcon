
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use Phalcon\Annotations\Reflection;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\ReaderInterface;

/**
 * Phalcon\Annotations\AdapterInterface
 *
 * This interface must be implemented by adapters in Phalcon\Annotations
 */
interface AdapterInterface
{
	/**
	 * Sets the annotations parser
	 */
	public function setReader(<ReaderInterface> reader);

	/**
	 * Returns the annotation reader
	 */
	public function getReader() -> <ReaderInterface>;

	/**
	 * Parses or retrieves all the annotations found in a class
	 */
	public function get(string className) -> <Reflection>;

	/**
	 * Returns the annotations found in all the class' methods
	 */
	public function getMethods(string className) -> array;

	/**
	 * Returns the annotations found in a specific method
	 */
	public function getMethod(string className, string methodName) -> <Collection>;

	/**
	 * Returns the annotations found in all the class' methods
	 */
	public function getProperties(string className) -> array;

	/**
	 * Returns the annotations found in a specific property
	 */
	public function getProperty(string className, string propertyName) -> <Collection>;
}
