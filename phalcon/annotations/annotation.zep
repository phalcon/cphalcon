
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

namespace Phalcon\Annotations;

/**
* Phalcon\Annotations\Annotation
*
* Represents a single annotation in an annotations collection
*/
class Annotation
{

	/**
	 * Annotations's Name
	 * @var string
	 */
	protected _name;

	/**
	 * Annotations's Arguments
	 * @var string
	 */
	protected _arguments;

	/**
	 * Annotations's ExprArguments
	 * @var string
	 */
	protected _exprArguments;

	/**
	 * Phalcon\Annotations\Annotation constructor
	 *
	 * @param array reflectionData
	 */
 	public function __construct(reflectionData)
	{
  		var name, exprArguments, argument, expr, resolvedArgument, arguments;

		if typeof reflectionData != "array" {
			throw new Phalcon\Annotations\Exception("Reflection data must be an array");
		}

		let this->_name = reflectionData["name"];

		/**
		 * Process annotation arguments
		 */
		if fetch exprArguments, reflectionData["arguments"] {
			for argument in exprArguments {
				let resolvedArgument =  this->getExpression(argument["expr"]);
				if fetch name, argument["name"] {
					let arguments = name[resolvedArgument];
	   			} else {
					let arguments = resolvedArgument;
				}
			}
			let this->_arguments = arguments;
			let this->_exprArguments = exprArguments;
		}
 	}

	/**
	 * Returns the annotation's name
	 *
	 * @return string
	 */
	public function getName()
	{
		return this->_name;
	}

	/**
	 * Resolves an annotation expression
	 *
	 * @param array expr
	 * @return mixed
	 */
	public function getExpression(expr)
	{
		var value, items, item, resolvedItem, arrayValue, name;

		if typeof expr != "array" {
			throw new Phalcon\Annotations\Exception("The expression is not valid");
		}

		switch expr["type"] {
			case 301:
			case 302:
			case 303:
			case 307:
				let value = expr["value"];
				break;
   			case 304:
				let value = null;
				break;
			case 305:
				let value = false;
				break;
			case 306:
				let value = true;
				break;
			case 308:
				for item in expr["items"] {
					let resolvedItem = this->getExpression(item["expr"]);
					if fetch name, item["name"] {
						let arrayValue = name[resolvedItem];
					} else {
						let arrayValue[] = resolvedItem;
					}
				}
				return arrayValue;
			case 300:
				return new Phalcon\Annotations\Annotation(expr);
   			default:
				throw new Phalcon\Annotations\Exception("The expression ". type. " is unknown");
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
	 *
	 * @return int
	 */
	public function numberArguments()
	{
		return count(this->_arguments);
	}

	/**
	 * Returns an argument in a specific position
	 *
	 * @param int position
	 * @return mixed
	 */
	public function getArgument(int position)
	{
		var arguments;
		let arguments = this->_arguments;
		if isset arguments[position] {
			return arguments[position];
		}
	}

	/**
	 * Returns an argument in a specific position
	 *
	 * @param int position
	 * @return mixed
	 */
	public function hasArgument(int position)
	{
		var arguments;
		let arguments = this->_arguments;
		return isset arguments[position];
	}

	/**
	 * Returns a named argument
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getNamedArgument(name)
	{
		var arguments, argument;
		let arguments = this->_arguments;
		if fetch argument, arguments[name] {
   			return argument;
  		}
 	}

}
