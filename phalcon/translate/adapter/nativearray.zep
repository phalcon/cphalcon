
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Adapter;

use Phalcon\Translate\Exception;
use Phalcon\Translate\Adapter;

/**
 * Phalcon\Translate\Adapter\NativeArray
 *
 * Allows to define translation lists using PHP arrays
 */
class NativeArray extends Adapter implements \ArrayAccess
{

	protected _translate;

	/**
	 * Phalcon\Translate\Adapter\NativeArray constructor
	 */
	public function __construct(array! options)
	{
		var data;

		parent::__construct(options);

		if !fetch data, options["content"] {
			throw new Exception("Translation content was not provided");
		}

		if typeof data !== "array" {
			throw new Exception("Translation data must be an array");
		}

		let this->_translate = data;
	}

	/**
	 * Returns the translation related to the given key
	 */
	public function query(string! index, placeholders = null) -> string
	{
		var translation;

		if !fetch translation, this->_translate[index] {
			let translation = index;
		}

		return this->replacePlaceholders(translation, placeholders);
	}

	/**
	 * Check whether is defined a translation key in the internal array
	 */
	public function exists(string! index) -> bool
	{
		return isset this->_translate[index];
	}
}
