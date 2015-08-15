<?php
/**
 * EngineTest.php
 * \Phalcon\Mvc\View\Engine\Volt\CompilerTest
 *
 * Tests the Phalcon\Mvc\View\Engine\Volt\Compiler component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Lajos Bencz <lazos@lazos.me>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Mvc\View\Engine\Volt;

use Phalcon\DI as PhDI;
use \Phalcon\Mvc\View\Engine\Volt\Compiler as PhVoltCompiler;
use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class CompilerTest extends TBase {

	/** @var PhVoltCompiler */
	protected $voltEngine;

	public function _before() {
		parent::_before();

		$this->voltEngine = new PhVoltCompiler();
	}

	/**
	 * Tests the self property of loop context
	 *
	 * @author Lajos Bencz <lazos@lazos.me>
	 * @since  2015-08-15
	 */
	public function testLoopContextSelf() {

		$compiled = $this->voltEngine->compileString('{% for i in 1..5 %}{{ loop.self.index }}{% endfor %}');
		ob_start();
		eval('?>'.$compiled);
		$result = ob_get_clean();
		$this->assertEquals('12345', $result);

	}

}