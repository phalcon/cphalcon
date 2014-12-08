<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

class ApplicationMvcTest extends PHPUnit_Framework_TestCase
{

	public function testApplicationSingleModule()
	{

		// Creates the autoloader
		$loader = new \Phalcon\Loader();

		$loader->registerDirs(array(
			'unit-tests/controllers/'
		));

		$loader->register();

		$_GET['_url'] = '/test2';

		$di = new Phalcon\DI\FactoryDefault();

		$di->set('view', function() {
			$view = new \Phalcon\Mvc\View();
			$view->setViewsDir('unit-tests/views/');
			return $view;
		});

		$application = new Phalcon\Mvc\Application();
		$application->setDi($di);
		$this->assertEquals($application->handle()->getContent(), '<html>here</html>'.PHP_EOL);

		$loader->unregister();
	}

	private function _getModulesDi()
	{
		Phalcon\DI::reset();

		$di = new Phalcon\DI\FactoryDefault();

		$di->set('router', function(){

			$router = new Phalcon\Mvc\Router(false);

			$router->add('/index', array(
			 'controller' => 'index',
				'action' => 'index',
				'module' => 'frontend',
				'namespace' => 'Frontend\Controllers\\'
			));

			$router->add('/login', array(
				'controller' => 'login',
				'module' => 'backend',
				'namespace' => 'Backend\Controllers\\'
			));

			$router->add('/forward', array(
				'controller' => 'index',
				'action' => 'forward',
				'module' => 'frontend',
				'namespace' => 'Frontend\Controllers\\'
			));

			return $router;
		});
		return $di;
	}

	public function testApplicationModulesDefinition()
	{
		$modules = array(
			'frontend' => array(
				'path' => 'unit-tests/modules/frontend/Module.php',
				'className' => 'Frontend\Module',
			),
			'backend' => array(
				'path' => 'unit-tests/modules/backend/Module.php',
				'className' => 'Backend\Module',
			),
		);

		/**
		 * frontend
		 */
		$_GET['_url'] = '/index';
		$di = $this->_getModulesDi();

		$application = new Phalcon\Mvc\Application();
		$application->setDi($di);
		$application->registerModules($modules);

		$this->assertEquals($application->handle()->getContent(), '<html>here</html>'.PHP_EOL);

		$registeredModules = $application->getModules();
		//All modules initialized
		$this->assertTrue($registeredModules['frontend']->initialized);
		$this->assertTrue($registeredModules['backend']->initialized);
		//In used modules registered services
		$this->assertTrue($registeredModules['frontend']->servicesRegistered);
		$this->assertFalse($registeredModules['backend']->servicesRegistered);

		//unregister autoloaders of modules for future tests
		$di->get('backendLoader')->unregister();
		$di->get('frontendLoader')->unregister();

		/**
		 * backend
		 */
		$_GET['_url'] = '/login';
		$di = $this->_getModulesDi();

		$application = new Phalcon\Mvc\Application();
		$application->setDi($di);
		$application->registerModules($modules);

		$this->assertEquals($application->handle()->getContent(), '<html>here login</html>'.PHP_EOL);

		$registeredModules = $application->getModules();
		//All modules initialized
		$this->assertTrue($registeredModules['frontend']->initialized);
		$this->assertTrue($registeredModules['backend']->initialized);
		//In used modules registered services
		$this->assertFalse($registeredModules['frontend']->servicesRegistered);
		$this->assertTrue($registeredModules['backend']->servicesRegistered);

		//unregister autoloaders of modules for future tests
		$di->get('backendLoader')->unregister();
		$di->get('frontendLoader')->unregister();

		/**
		 * forward from frontend to backend
		 */
		$_GET['_url'] = '/forward';
		$di = $this->_getModulesDi();

		$application = new Phalcon\Mvc\Application();
		$application->setDi($di);
		$application->registerModules($modules);

		$this->assertEquals($application->handle()->getContent(), '<html>here login</html>'.PHP_EOL);

		$registeredModules = $application->getModules();
		//All modules initialized
		$this->assertTrue($registeredModules['frontend']->initialized);
		$this->assertTrue($registeredModules['backend']->initialized);
		//In used modules registered services (frontend forwards to backend, so both modules registered)
		$this->assertTrue($registeredModules['frontend']->servicesRegistered);
		$this->assertTrue($registeredModules['backend']->servicesRegistered);

		//unregister autoloaders of modules for future tests
		$di->get('backendLoader')->unregister();
		$di->get('frontendLoader')->unregister();
	}

	public function testApplicationModulesInstances()
	{
		require_once 'unit-tests/modules/frontend/Module.php';
		require_once 'unit-tests/modules/backend/Module.php';

		/**
		 * frontend
		 */
		$_GET['_url'] = '/index';
		$di = $this->_getModulesDi();

		$application = new Phalcon\Mvc\Application();
		$application->setDi($di);
		$application->registerModules(array(
			'frontend' => new Frontend\Module(),
			'backend' => new Backend\Module(),
		));

		$this->assertEquals($application->handle()->getContent(), '<html>here</html>'.PHP_EOL);

		$registeredModules = $application->getModules();
		//All modules initialized
		$this->assertTrue($registeredModules['frontend']->initialized);
		$this->assertTrue($registeredModules['backend']->initialized);
		//In used modules registered services
		$this->assertTrue($registeredModules['frontend']->servicesRegistered);
		$this->assertFalse($registeredModules['backend']->servicesRegistered);

		//unregister autoloaders of modules for future tests
		$di->get('backendLoader')->unregister();
		$di->get('frontendLoader')->unregister();

		/**
		 * backend
		 */
		$_GET['_url'] = '/login';
		$di = $this->_getModulesDi();

		$application = new Phalcon\Mvc\Application();
		$application->setDi($di);
		$application->registerModules(array(
			'frontend' => new Frontend\Module(),
			'backend' => new Backend\Module(),
		));

		$this->assertEquals($application->handle()->getContent(), '<html>here login</html>'.PHP_EOL);

		$registeredModules = $application->getModules();
		//All modules initialized
		$this->assertTrue($registeredModules['frontend']->initialized);
		$this->assertTrue($registeredModules['backend']->initialized);
		//In used modules registered services
		$this->assertFalse($registeredModules['frontend']->servicesRegistered);
		$this->assertTrue($registeredModules['backend']->servicesRegistered);

		//unregister autoloaders of modules for future tests
		$di->get('backendLoader')->unregister();
		$di->get('frontendLoader')->unregister();

		/**
		 * forward from frontend to backend
		 */
		$_GET['_url'] = '/forward';
		$di = $this->_getModulesDi();

		$application = new Phalcon\Mvc\Application();
		$application->setDi($di);
		$application->registerModules(array(
			'frontend' => new Frontend\Module(),
			'backend' => new Backend\Module(),
		));

		$this->assertEquals($application->handle()->getContent(), '<html>here login</html>'.PHP_EOL);

		$registeredModules = $application->getModules();
		//All modules initialized
		$this->assertTrue($registeredModules['frontend']->initialized);
		$this->assertTrue($registeredModules['backend']->initialized);
		//In used modules registered services (frontend forwards to backend, so both modules registered)
		$this->assertTrue($registeredModules['frontend']->servicesRegistered);
		$this->assertTrue($registeredModules['backend']->servicesRegistered);

		//unregister autoloaders of modules for future tests
		$di->get('backendLoader')->unregister();
		$di->get('frontendLoader')->unregister();
	}

	public function testApplicationModulesDefinitionClosure()
	{

		// Creates the autoloader
		$loader = new \Phalcon\Loader();

		$loader->registerNamespaces(array(
			'Frontend\Controllers' => 'unit-tests/modules/frontend/controllers/',
			'Backend\Controllers' => 'unit-tests/modules/backend/controllers/'
		));

		$loader->register();

		$modules = array(
			'frontend' => function($di) {
				$di->set('view', function() {
					$view = new \Phalcon\Mvc\View();
					$view->setViewsDir('unit-tests/modules/frontend/views/');
					return $view;
				});
			},
			'backend' => function($di) {
				$di->set('view', function() {
					$view = new \Phalcon\Mvc\View();
					$view->setViewsDir('unit-tests/modules/backend/views/');
					return $view;
				});
			},
		);

		/**
		 * frontend
		 */
		$_GET['_url'] = '/index';

		$application = new Phalcon\Mvc\Application();
		$application->setDi($this->_getModulesDi());
		$application->registerModules($modules);

		$this->assertEquals($application->handle()->getContent(), '<html>here</html>'.PHP_EOL);

		/**
		 * backend
		 */
		$_GET['_url'] = '/login';

		$application = new Phalcon\Mvc\Application();
		$application->setDi($this->_getModulesDi());
		$application->registerModules($modules);

		$this->assertEquals($application->handle()->getContent(), '<html>here login</html>'.PHP_EOL);

		/**
		 * forward from frontend to backend
		 */
		$_GET['_url'] = '/forward';

		$application = new Phalcon\Mvc\Application();
		$application->setDi($this->_getModulesDi());
		$application->registerModules($modules);

		$this->assertEquals($application->handle()->getContent(), '<html>here login</html>'.PHP_EOL);


		$loader->unregister();
	}

}