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

class FlashTest extends PHPUnit_Framework_TestCase
{

	public function testFlashDirectImplicitFlushHtml()
	{

		$messageText = 'sample message';

		$flash = new Phalcon\Flash\Direct();

		ob_start();
		$flash->error($messageText);
		$flash->success($messageText);
		$flash->notice($messageText);
		$flash->warning($messageText);
		$content = ob_get_contents();
		ob_end_clean();

		$this->assertEquals($content,
			'<div class="errorMessage">sample message</div>'.PHP_EOL.
			'<div class="successMessage">sample message</div>'.PHP_EOL.
			'<div class="noticeMessage">sample message</div>'.PHP_EOL.
			'<div class="warningMessage">sample message</div>'.PHP_EOL
		);

	}

	public function testFlashDirectImplicitFlushHtmlArray()
	{

		$messageText = array('sample message 1', 'sample message 2');

		$flash = new Phalcon\Flash\Direct();

		ob_start();
		$flash->error($messageText);
		$flash->success($messageText);
		$content = ob_get_contents();
		ob_end_clean();

		$this->assertEquals($content,
			'<div class="errorMessage">sample message 1</div>'.PHP_EOL.
			'<div class="errorMessage">sample message 2</div>'.PHP_EOL.
			'<div class="successMessage">sample message 1</div>'.PHP_EOL.
			'<div class="successMessage">sample message 2</div>'.PHP_EOL
		);

	}

	public function testFlashDirectNoImplicitFlushHtml()
	{

		$messageText = 'sample message';

		$flash = new Phalcon\Flash\Direct();
		$flash->setImplicitFlush(false);

		$message = $flash->error($messageText);
		$this->assertEquals($message, '<div class="errorMessage">sample message</div>'.PHP_EOL);

		$message = $flash->success($messageText);
		$this->assertEquals($message, '<div class="successMessage">sample message</div>'.PHP_EOL);

		$message = $flash->notice($messageText);
		$this->assertEquals($message, '<div class="noticeMessage">sample message</div>'.PHP_EOL);

		$message = $flash->warning($messageText);
		$this->assertEquals($message, '<div class="warningMessage">sample message</div>'.PHP_EOL);

	}

	public function testFlashDirectNoImplicitFlushHtmlArray()
	{

		$messageText = array('sample message 1', 'sample message 2');

		$flash = new Phalcon\Flash\Direct();
		$flash->setImplicitFlush(false);

		$message = $flash->error($messageText);
		$this->assertEquals($message,
			'<div class="errorMessage">sample message 1</div>'.PHP_EOL.
			'<div class="errorMessage">sample message 2</div>'.PHP_EOL
		);

		$message = $flash->success($messageText);
		$this->assertEquals($message,
			'<div class="successMessage">sample message 1</div>'.PHP_EOL.
			'<div class="successMessage">sample message 2</div>'.PHP_EOL
		);

	}

	public function testFlashDirectNoImplicitFlushNoHtml()
	{

		$messageText = 'sample message';

		$flash = new Phalcon\Flash\Direct();
		$flash->setImplicitFlush(false);
		$flash->setAutomaticHtml(false);

		$message = $flash->error($messageText);
		$this->assertEquals($message, 'sample message');

		$message = $flash->success($messageText);
		$this->assertEquals($message, 'sample message');

		$message = $flash->notice($messageText);
		$this->assertEquals($message, 'sample message');

		$message = $flash->warning($messageText);
		$this->assertEquals($message, 'sample message');

	}

	public function testFlashDirectCssClasses()
	{

		$messageText = 'sample message';

		$flash = new Phalcon\Flash\Direct(array(
			'error' => 'alert alert-error',
			'success' => 'alert alert-success',
			'notice' => 'alert alert-notice',
			'warning' => 'alert alert-warning'
		));

		ob_start();
		$flash->error($messageText);
		$flash->success($messageText);
		$flash->notice($messageText);
		$flash->warning($messageText);
		$content = ob_get_contents();
		ob_end_clean();

		$this->assertEquals($content,
			'<div class="alert alert-error">sample message</div>'.PHP_EOL.
			'<div class="alert alert-success">sample message</div>'.PHP_EOL.
			'<div class="alert alert-notice">sample message</div>'.PHP_EOL.
			'<div class="alert alert-warning">sample message</div>'.PHP_EOL
		);

	}



}