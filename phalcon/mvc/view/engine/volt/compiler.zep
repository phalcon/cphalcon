
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

namespace Phalcon\Mvc\View\Engine\Volt;

/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler
 *
 * This class reads and compiles Volt templates into PHP plain code
 *
 *<code>
 *	$compiler = new \Phalcon\Mvc\View\Engine\Volt\Compiler();
 *
 *	$compiler->compile('views/partials/header.volt');
 *
 *	require $compiler->getCompiledTemplatePath();
 *</code>
 */
class Compiler implements Phalcon\Di\InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _view;

	protected _options;

	protected _arrayHelpers;

	protected _level = 0;

	protected _foreachLevel = 0;

	protected _blockLevel = 0;

	protected _exprLevel = 0;

	protected _extended = false;

	protected _autoescape = false;

	protected _extendedBlocks;

	protected _currentBlock;

	protected _blocks;

	protected _forElsePointers;

	protected _loopPointers;

	protected _extensions;

	protected _functions;

	protected _filters;

	protected _macros;

	protected _prefix;

	protected _currentPath;

	protected _compiledTemplatePath;

	/**
	 * Phalcon\Mvc\View\Engine\Volt\Compiler
	 *
	 * @param Phalcon\Mvc\ViewInterface view
	 */
	public function __construct(view=null)
	{
		if typeof view == "object" {
			let this->_view = view;
		}
	}

	/**
	 * Sets the dependency injector
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets the compiler options
	 *
	 * @param array options
	 */
	public function setOptions(options)
	{
		let this->_options = options;
	}

	/**
	 * Sets a single compiler option
	 *
	 * @param string option
	 * @param mixed value
	 */
	public function setOption(string! option, value)
	{
		let this->_options[option] = value;
	}

	/**
	 * Compiles a template into a file applying the compiler options
	 * This method does not return the compiled path if the template was not compiled
	 *
	 *<code>
	 *	$compiler->compile('views/layouts/main.volt');
	 *	require $compiler->getCompiledTemplatePath();
	 *</code>
	 *
	 * @param  string  templatePath
	 * @param  boolean extendsMode
	 * @return string|array
	 */
	public function compile(string! templatePath, boolean extendsMode=false)
	{

	}

	/**
	 * Returns the path to the last compiled template
	 *
	 * @return string
	 */
	public function getCompiledTemplatePath() -> string
	{
		return this->_compiledTemplatePath;
	}

}