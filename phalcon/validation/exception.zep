
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

 namespace Phalcon;

 /**
 * Phalcon\Validation
 *
 * Allows to validate data using validators
 */
class Validation extends Phalcon\DI\Injectable
{
	protected _data;

	protected _entity;

	protected _validators;

	protected _filters;

	protected _messages;

	protected _values;

	/**
	 * Phalcon\Validation constructor
	 *
	 * @param array validators
	 */
	public function __construct(validators=null)
	{

		if validators === null {
			if typeof validators !== "array" {
				throw new Phalcon\Validation\Exception("Validators must be an array");
			}
			let this->_validators = validators;
		}

		/**
		 * Check for an 'initialize' method
		 */
		if method_exists(this, "initialize") {
			this->initialize();
		}
	}