
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

use Phalcon\Tag\Select;
use Phalcon\Forms\Element;

/**
 * Phalcon\Forms\Element\Select
 *
 * Component SELECT (choice) for forms
 */
class Select extends Element
{

	protected _optionsValues;

	/**
	 * Phalcon\Forms\Element constructor
	 *
	 * @param object|array options
	 * @param array attributes
	 */
	public function __construct(string name, options = null, attributes = null)
	{
		let this->_optionsValues = options;
		parent::__construct(name, attributes);
	}

	/**
	 * Set the choice's options
	 *
	 * @param array|object options
	 */
	public function setOptions(var options) -> <Element>
	{
		let this->_optionsValues = options;
		return this;
	}

	/**
	 * Returns the choices' options
	 *
	 * @return array|object
	 */
	public function getOptions()
	{
		return this->_optionsValues;
	}

	/**
	 * Adds an option to the current options
	 *
	 * @param array option
	 */
	public function addOption(var option) -> <Element>
	{
		var key, value;

		if typeof option == "array" {
			for key, value in option {
				let this->_optionsValues[key] = value;
			}
		} else {
			let this->_optionsValues[] = option;
		}

		return this;
	}

	/**
	 * Renders the element widget returning html
	 */
	public function render(array attributes = []) -> string
	{
		/**
		 * Merged passed attributes with previously defined ones
		 */
		return Select::selectField(this->prepareAttributes(attributes), this->_optionsValues);
	}
}
