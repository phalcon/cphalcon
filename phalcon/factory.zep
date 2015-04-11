
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
 |          Stanislav Kiryukhin <korsar.zn@gmail.com>                     |
 +------------------------------------------------------------------------+
*/
namespace Phalcon;

use Phalcon\Di;

/**
 * Phalcon\Filter\Exception
 *
 * Exceptions thrown in Phalcon\Filter will use this class
 *
 */
abstract class Factory
{
	protected static _app;

	/**
	 * Returns global Application instance
	 */
	public static function app() -> <Phalcon\Mvc\Application>
	{
		if typeof self::_app != "object" {
			throw new Exception("Application isn't registered in the global container");
		}

		return self::_app;
	}

	/**
	 * Returns global Dependency Injector
	 */
	public static function di() -> <Phalcon\DiInterface>
	{
		if isset self::_app {
			return self::_app->getDI();
		} else {
			return Di::getDefault();
		}
	}

	/**
	 * Returns global Event Manager
	 */
	public static function eventsManager() -> <Phalcon\Events\ManagerInterface>
	{
		return self::di()->get("eventsManager");
	}

	/**
	 * Sets global Application instance
	 */
	public static function setApplication(<Phalcon\Mvc\Application> application) -> void
	{
		let self::_app = application;
	}

	/**
	 * Returns Service instance from global DI
	 */
	public static function __callStatic(string! method, array! arguments)
	{
		return self::di()->get(method, arguments);
	}
}
