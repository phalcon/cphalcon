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
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
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
	 * @param string name
	 * @param object entity
	 * @return Phalcon\Forms\Form
	 */
	public function create(name = null, entity = null) -> <Form>
	{
		var form;

		if typeof name != "string" {
			throw new Exception("The form name must be string");
		}

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
	public function has(string name) -> boolean
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
