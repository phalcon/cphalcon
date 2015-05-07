
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

namespace Phalcon\Annotations;

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Exception;

/**
 * Phalcon\Annotations\Annotation
 *
 * Represents a single annotation in an annotations collection
 */
class Annotation
{

	/**
	 * Annotation Name
	 * @var string
	 */
	protected _name;

	/**
	 * Annotation Arguments
	 * @var string
	 */
	protected _arguments;

	/**
	 * Annotation ExprArguments
	 * @var string
	 */
	protected _exprArguments;

	/**
	 * Phalcon\Annotations\Annotation constructor
	 */
	public function __construct(array! reflectionData)
	{
		var name, exprArguments, argument, resolvedArgument, arguments;

		let this->_name = reflectionData["name"];

		/**
		 * Process annotation arguments
		 */
		if fetch exprArguments, reflectionData["arguments"] {
			let arguments = [];
			for argument in exprArguments {
				let resolvedArgument =  this->getExpression(argument["expr"]);
				if fetch name, argument["name"] {
					let arguments[name] = resolvedArgument;
				} else {
					let arguments[] = resolvedArgument;
				}
			}
			let this->_arguments = arguments;
			let this->_exprArguments = exprArguments;
		}
	}

	/**
	 * Returns the annotation's name
	 */
	public function getName() -> string
	{
		return this->_name;
	}

	/**
	 * Resolves an annotation expression
	 *
	 * @param array expr
	 * @return mixed
	 */
	public function getExpression(array! expr)
	{
		var value, item, resolvedItem, arrayValue, name, type;

		let type = expr["type"];
		switch type {

			case PHANNOT_T_INTEGER:
			case PHANNOT_T_DOUBLE:
			case PHANNOT_T_STRING:
			case PHANNOT_T_IDENTIFIER:
				let value = expr["value"];
				break;

			case PHANNOT_T_NULL:
				let value = null;
				break;

			case PHANNOT_T_FALSE:
				let value = false;
				break;

			case PHANNOT_T_TRUE:
				let value = true;
				break;

			case PHANNOT_T_ARRAY:
				let arrayValue = [];
				for item in expr["items"] {
					let resolvedItem = this->getExpression(item["expr"]);
					if fetch name, item["name"] {
						let arrayValue[name] = resolvedItem;
					} else {
						let arrayValue[] = resolvedItem;
					}
				}
				return arrayValue;

			case PHANNOT_T_ANNOTATION:
				return new Annotation(expr);

			default:
				throw new Exception("The expression ". type. " is unknown");
		}

		return value;
	}

	/**
	 * Returns the expression arguments without resolving
	 *
	 * @return array
	 */
	public function getExprArguments()
	{
		return this->_exprArguments;
	}

	/**
	 * Returns the expression arguments
	 *
	 * @return array
	 */
	public function getArguments()
	{
		return this->_arguments;
	}

	/**
	 * Returns the number of arguments that the annotation has
	 */
	public function numberArguments() -> int
	{
		return count(this->_arguments);
	}

	/**
	 * Returns an argument in a specific position
	 *
	 * @param int|string position
	 * @return mixed
	 */
	public function getArgument(var position)
	{
		var argument;
		if fetch argument, this->_arguments[position] {
			return argument;
		}
	}

	/**
	 * Returns an argument in a specific position
	 *
	 * @param int|string position
	 * @return boolean
	 */
	public function hasArgument(var position) -> boolean
	{
		return isset this->_arguments[position];
	}

	/**
	 * Returns a named argument
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getNamedArgument(string! name)
	{
		var argument;
		if fetch argument, this->_arguments[name] {
			return argument;
		}
	}

	/**
	 * Returns a named parameter
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getNamedParameter(string! name)
	{
		return this->getNamedArgument(name);
	}
}
