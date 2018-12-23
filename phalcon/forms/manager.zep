
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms;

/**
 * Phalcon\Forms\Manager
 */
class Manager
{

	protected _forms;

	/**
	 * Creates a form registering it in the forms manager
	 *
	 * @param object entity
	 */
	public function create(string name, entity = null) -> <Form>
	{
		var form;

		let form = new Form(entity),
			this->_forms[name] = form;

		return form;
	}

	/**
	 * Returns a form by its name
	 */
	public function get(string name) -> <Form>
	{
		var form;
		if !fetch form, this->_forms[name] {
			throw new Exception("There is no form with name='" . name . "'");
		}
		return form;
	}

	/**
	 * Checks if a form is registered in the forms manager
	 */
	public function has(string name) -> bool
	{
		return isset this->_forms[name];
	}

	/**
	 * Registers a form in the Forms Manager
	 */
	public function set(string name, <Form> form) -> <FormManager>
	{
		let this->_forms[name] = form;
		return this;
	}

}
