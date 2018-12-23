
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

/**
 * Phalcon\Annotations\Reader
 *
 * Parses docblocks returning an array with the found annotations
 */
interface ReaderInterface
{

	/**
	 * Reads annotations from the class dockblocks, its methods and/or properties
	 */
	public function parse(string className) -> array;

	/**
	 * Parses a raw doc block returning the annotations found
	 */
	public static function parseDocBlock(string docBlock, file = null, line = null) -> array;
}
