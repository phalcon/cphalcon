<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

class ModelsManagerTest extends PHPUnit_Framework_TestCase {

	public function testManager(){

		$modelsDir = 'unit-tests/models/';

		$modelManager = new Phalcon_Model_Manager();
		$modelManager->setModelsDir($modelsDir);

		$this->assertEquals($modelManager->getModelsDir(), $modelsDir);

		$isModel = $modelManager->isModel('NoExiste');
		$this->assertFalse($isModel);

		$isModel = $modelManager->isModel('Personas');
		$this->assertTrue($isModel);

		$Personas = $modelManager->getModel('Personas');
		$this->assertEquals(get_class($Personas), 'Personas');

		$Prueba = new Prueba($modelManager);
		$this->assertEquals(get_class($Prueba), 'Prueba');

	}

}