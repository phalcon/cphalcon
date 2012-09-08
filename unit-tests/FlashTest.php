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

class FlashTest extends PHPUnit_Framework_TestCase {

	public function testFlash(){

		$message = 'sample message';

		ob_start();
		Phalcon_Flash::error($message);
		$flash = ob_get_clean();
		$this->assertEquals($flash, '<div class="errorMessage">sample message</div>'.PHP_EOL);

		ob_start();
		Phalcon_Flash::error($message, 'alert alert-error');
		$flash = ob_get_clean();
		$this->assertEquals($flash, '<div class="alert alert-error">sample message</div>'.PHP_EOL);

		ob_start();
		Phalcon_Flash::success($message);
		$flash = ob_get_clean();
		$this->assertEquals($flash, '<div class="successMessage">sample message</div>'.PHP_EOL);

		ob_start();
		Phalcon_Flash::success($message, 'alert alert-success');
		$flash = ob_get_clean();
		$this->assertEquals($flash, '<div class="alert alert-success">sample message</div>'.PHP_EOL);

		ob_start();
		Phalcon_Flash::notice($message);
		$flash = ob_get_clean();
		$this->assertEquals($flash, '<div class="noticeMessage">sample message</div>'.PHP_EOL);

		ob_start();
		Phalcon_Flash::notice($message, 'alert alert-notice');
		$flash = ob_get_clean();
		$this->assertEquals($flash, '<div class="alert alert-notice">sample message</div>'.PHP_EOL);

		ob_start();
		Phalcon_Flash::warning($message);
		$flash = ob_get_clean();
		$this->assertEquals($flash, '<div class="warningMessage">sample message</div>'.PHP_EOL);

		ob_start();
		Phalcon_Flash::warning($message, 'alert alert-warning');
		$flash = ob_get_clean();
		$this->assertEquals($flash, '<div class="alert alert-warning">sample message</div>'.PHP_EOL);

	}

}