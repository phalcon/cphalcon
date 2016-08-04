
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
use Phalcon\DiInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalcon\Mvc\Application as ApplicationInterface;

/**
 * Class Phalcon\Factory
 *
 * Global container for gets instance DI (internal or from application, or default).
 * And also for gets instance Application.
 *
 * <code>
 * 	// Gets Service instance from DI
 * 	$service1 = Phalcon\Factory::di()->get(SERVICE_NAME);
 * 	$service2 = Phalcon\Factory::getSERVICENAME();
 *
 * 	// Gets Application instance
 *	$app Phalcon\Factory::app();
 * </code>
 */
abstract class Factory
{
	protected static _app;

	protected static _di;

	/**
	 * Returns global Application instance
	 */
	public static function app() -> <ApplicationInterface>
	{
		if typeof self::_app != "object" {
			throw new Exception("Application isn't registered in the global container");
		}

		return self::_app;
	}

	/**
	 * Returns global Dependency Injector
	 */
	public static function di(<DiInterface> external_di = null) -> <DiInterface>
	{
		if external_di {
			return external_di;
		}

		 if self::_di {
		 	return self::_di;
		 }

		 if self::_app {
		 	self::_app->getDI();
		 }

		return Di::getDefault();
	}

	/**
	 * Sets global Dependency Injector
	 */
	public static function setDI(<DiInterface> di) -> void
	{
		let self::_di = di;
	}

	/**
	 * Returns global Event Manager
	 */
	public static function eventsManager() -> <EventsManagerInterface>
	{
		return self::di()->get("eventsManager");
	}

	/**
	 * Sets global Application instance
	 */
	public static function setApplication(<ApplicationInterface> application) -> void
	{
		let self::_app = application;
	}

	/**
	 * Returns Service instance from global DI
	 */
	public static function __callStatic(string! method, array arguments)
	{
		if starts_with(method, "get") {
			return self::di()->get(lcfirst(substr(method, 3)), arguments);
		}

		throw new Exception("The static method '" . method . "' doesn't exist");
	}
}
