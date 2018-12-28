
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate;

use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorInterface;
use Phalcon\Translate\Interpolator\AssociativeArray;

/**
 * Phalcon\Translate\Adapter
 *
 * Base class for Phalcon\Translate adapters
 */
abstract class Adapter implements AdapterInterface
{
	/**
	* @var Phalcon\Translate\InterpolatorInterface
	*/
	protected _interpolator;

	public function __construct(array! options)
	{
		var interpolator;

		if !fetch interpolator, options["interpolator"] {
			let interpolator = new AssociativeArray();
		}
		this->setInterpolator(interpolator);
	}

	public function setInterpolator(<InterpolatorInterface> interpolator) -> <Adapter>
	{
		let this->_interpolator = interpolator;
		return this;
	}

	/**
	 * Returns the translation string of the given key
	 *
	 * @param array   placeholders
	 */
	public function t(string! translateKey, placeholders = null) -> string
	{
		return this->{"query"}(translateKey, placeholders);
	}

	/**
	 * Returns the translation string of the given key (alias of method 't')
	 *
	 * @param array   placeholders
	 */
	public function _(string! translateKey, placeholders = null) -> string
	{
		return this->{"query"}(translateKey, placeholders);
	}

	/**
	 * Sets a translation value
	 *
	 * @param string value
	 */
	public function offsetSet(var offset, var value) -> void
	{
		throw new Exception("Translate is an immutable ArrayAccess object");
	}

	/**
	 * Check whether a translation key exists
	 */
	public function offsetExists(var translateKey) -> bool
	{
		return this->{"exists"}(translateKey);
	}

	/**
	 * Unsets a translation from the dictionary
	 */
	public function offsetUnset(var offset) -> void
	{
		throw new Exception("Translate is an immutable ArrayAccess object");
	}

	/**
	 * Returns the translation related to the given key
	 */
	public function offsetGet(var translateKey) -> var
	{
		return this->{"query"}(translateKey, null);
	}

	/**
	 * Replaces placeholders by the values passed
	 */
	protected function replacePlaceholders(string! translation, placeholders = null) -> string
	{
		return this->_interpolator->{"replacePlaceholders"}(translation, placeholders);
	}
}
