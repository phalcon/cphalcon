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

function phalcon_prepare_virtual_path($path, $separator) {
	$virtual_str = '';

	if (!is_string($path) || !is_string($separator)) {
		if (is_string($path)) {
			return $path;
		} else {
			return "";
		}
	}

	for ($i = 0; $i < strlen($path); $i++) {
		$ch = $path[$i];
		if ($ch == '\0') {
			break;
		}
		if ($ch == '/' || $ch == '\\' || $ch == ':') {
			$virtual_str .= $separator;
		} else {
			$virtual_str .= strtolower($ch);
		}
	}

	return $virtual_str;
}

class ViewEnginesCompilerTest extends PHPUnit_Framework_TestCase
{
	public function testCompilerFile()
	{
		@unlink('unit-tests/views/test17/index.compiler.php');

		$di = new Phalcon\DI();
		$view = new Phalcon\Mvc\View();

		$compiler = new Phalcon\Mvc\View\Engine\Compiler($view, $di);

		$compiler->setOptions(array(
			"compiledSource" => function($viewCode) {
				preg_match_all('|\${[a-z]+}|', $viewCode, $matches);
				foreach ($matches as $value) {
					$viewCode = str_replace($value[0], '<?php echo $' . substr($value[0], 2, -1). '; ?>', $viewCode);
				}
				return $viewCode;
			}
		));

		//Simple file
		$compiler->compileFile('unit-tests/views/test17/index.compiler', 'unit-tests/views/test17/index.compiler.php');

		$compilation = file_get_contents('unit-tests/views/test17/index.compiler.php');
		$this->assertEquals($compilation, 'Hello <?php echo $song; ?>!'."\n");
	}

	public function testCompilerFileOptions()
	{
		@unlink('unit-tests/views/test17/index.compiler.php');
		@unlink('unit-tests/cache/unit-tests.views.test17.index.compiler.compiled');

		$di = new Phalcon\DI();
		$view = new Phalcon\Mvc\View();

		$compiler = new Phalcon\Mvc\View\Engine\Compiler($view, $di);

		$compiler->setOptions(array(
			"compiledPath" => "unit-tests/cache/",
			"compiledSeparator" => ".",
			"compiledExtension" => ".compiled",
			"compiledSource" => function($viewCode) {
				preg_match_all('|\${[a-z]+}|', $viewCode, $matches);
				foreach ($matches as $value) {
					$viewCode = str_replace($value[0], '<?php echo $' . substr($value[0], 2, -1). '; ?>', $viewCode);
				}
				return $viewCode;
			},
		));

		//Render simple view
		$view->start();
		$compiler->render('unit-tests/views/test17/index.compiler', array('song' => 'Lights'), true);
		$view->finish();

		$path = 'unit-tests/cache/' . phalcon_prepare_virtual_path(realpath("unit-tests/"), ".") . '.views.test17.index.compiler.compiled';

		$this->assertTrue(file_exists($path));
		$this->assertEquals(file_get_contents($path), 'Hello <?php echo $song; ?>!'."\n");
		$this->assertEquals($view->getContent(), "Hello Lights!\n");

	}

	public function testCompilerEngine()
	{
		@unlink('unit-tests/views/test17/index.compiler.php');

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.compiler' => function($view, $di) {
				$compiler = new Phalcon\Mvc\View\Engine\Compiler($view, $di);
				$compiler->setOptions(array(
					"compiledSource" => function($viewCode) {
						preg_match_all('|\${[a-z]+}|', $viewCode, $matches);
						foreach ($matches as $value) {
							$viewCode = str_replace($value[0], '<?php echo $' . substr($value[0], 2, -1). '; ?>', $viewCode);
						}
						return $viewCode;
					},
				));
				return $compiler;
			}
		));

		$view->setVar('song', 'Lights');

		$view->start();
		$view->render('test17', 'index');
		$view->finish();

		$this->assertEquals($view->getContent(), "Hello Lights!\n");
	}

	public function testCompilerParkdown()
	{
		// require_once __DIR__ . '/../Parsedown.php';

		if (!class_exists('Parsedown')) {
			$this->markTestSkipped('Compiler Parsedown engine could not be found');
			return false;
		}

		@unlink('unit-tests/views/test17/index.md.php');

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.md' => function($view, $di) {
				$compiler = new Phalcon\Mvc\View\Engine\Compiler($view, $di);
				$compiler->setOptions(array(
					"compiledSource" => function($viewCode) {
						$parsedown = new Parsedown();
						return $parsedown->text($viewCode);
					},
				));
				return $compiler;
			}
		));

		$view->start();
		$view->render('test17', 'index');
		$view->finish();

		$this->assertEquals($view->getContent(), "<h1>Header</h1>\n<p>Hello <em>Parsedown</em>!</p>");
	}

}
