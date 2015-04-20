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

use Phalcon\Mvc\View\Engine\Markdown;

if (!function_exists('phalcon_prepare_virtual_path')) {
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
}

function phalcon_get_markdown($name) {
	$file = __DIR__ . '/views/markdown/' . $name;
	if (is_file($file)) {
		return file_get_contents($file);
	}
	return null;
}

function phalcon_markdown_blockcode($text, $lang, $attr) {
	return (string)$lang . ':' . (string)$text;
}

function phalcon_markdown_before($code) {
	return "# Before Compile\n" . $code;
}

function phalcon_markdown_after($markdown) {
	$compiled = $markdown->getCompiled();
	$markdown->afterCompile = array('compiled' => $compiled);
}

class ViewEnginesMarkdownTest extends PHPUnit_Framework_TestCase
{
	public function testMarkdownParserBasics()
	{
		$markdown = new Markdown\Compiler();

		$intermediate = $markdown->parse('');
		$this->assertEmpty($intermediate);

		//Paragraphs, Headers, Blockquotes
		phalcon_get_markdown('test01.md');
		$intermediate = $markdown->parse(phalcon_get_markdown('test01.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test01.html'));

		//Phrase Emphasis
		$intermediate = $markdown->parse(phalcon_get_markdown('test02.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test02.html'));

		//Lists
		$intermediate = $markdown->parse(phalcon_get_markdown('test03.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test03.html'));

		$intermediate = $markdown->parse(phalcon_get_markdown('test03-1.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test03.html'));

		$intermediate = $markdown->parse(phalcon_get_markdown('test03-2.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test03.html'));

		$intermediate = $markdown->parse(phalcon_get_markdown('test04.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test04.html'));

		$intermediate = $markdown->parse(phalcon_get_markdown('test05.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test05.html'));

		//Links
		$intermediate = $markdown->parse(phalcon_get_markdown('test06.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test06.html'));

		//Optionally, you may include a title attribute in the parentheses:
		$intermediate = $markdown->parse(phalcon_get_markdown('test07.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test07.html'));

		//Reference-style links
		$intermediate = $markdown->parse(phalcon_get_markdown('test08.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test08.html'));

		//The title attribute is optional.
		$intermediate = $markdown->parse(phalcon_get_markdown('test09.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test09.html'));

		//Images
		$intermediate = $markdown->parse(phalcon_get_markdown('test10.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test10.html'));

		$intermediate = $markdown->parse(phalcon_get_markdown('test11.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test11.html'));

		//Code
		$intermediate = $markdown->parse(phalcon_get_markdown('test12.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test12.html'));

		$intermediate = $markdown->parse(phalcon_get_markdown('test13.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test13.html'));
	}

	public function testMarkdownCompilerFile()
	{
		@unlink('unit-tests/views/markdown/test14.md.php');

		$markdown = new Markdown\Compiler();

		//Simple file
		$markdown->compileFile('unit-tests/views/markdown/test14.md', 'unit-tests/views/markdown/test14.md.php');

		$compilation = file_get_contents('unit-tests/views/markdown/test14.md.php');
		$this->assertEquals($compilation, phalcon_get_markdown('test14.html'));
	}

	public function testMarkdownEngine()
	{
		@unlink('unit-tests/views/markdown/action/index.md.php');

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/markdown/');

		$view->registerEngines(array(
			'.md' => 'Phalcon\Mvc\View\Engine\Markdown'
		));

		$view->start();
		$view->render('action', 'index');
		$view->finish();

		$this->assertEquals($view->getContent(), phalcon_get_markdown('action/index.html'));
	}

	public function testMarkdownParserOption()
	{
		$markdown = new Markdown\Compiler();

		//Fenced Code
		$intermediate = $markdown->parse(phalcon_get_markdown('test15.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test15.html'));

		//Special Attribute
		$compileOption = $markdown->getOption('compileOption');
		$this->assertEquals($compileOption, array(
			Markdown::TABLES, Markdown::FENCED_CODE, Markdown::AUTOLINK,
			Markdown::STRIKETHROUGH, Markdown::NO_INTRA_EMPHASIS,
			Markdown::TASK, Markdown::SCRIPT_TAGS));

		$option = $compileOption;
		$option[] = Markdown::SPECIAL_ATTRIBUTE;
		$markdown->setOption('compileOption', $option);

		$intermediate = $markdown->parse(phalcon_get_markdown('test16.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test16.html'));

		//Meta Block
		$option = $compileOption;
		$option[] = Markdown::META_BLOCK;
		$markdown->setOption('compileOption', $option);

		$intermediate = $markdown->parse(phalcon_get_markdown('test17.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test17.html'));

		$meta = <<<EOT
  author: user
  title: Readme markdown parser

EOT;
		$this->assertEquals($meta, $markdown->getMeta());

		$intermediate = $markdown->parse(phalcon_get_markdown('test18.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test18.html'));

		$meta = <<<EOT
  block-1: first block
 block-2: second block 
 block-3: third block 

EOT;
		$this->assertEquals($meta, $markdown->getMeta());

		//Toc
		$option = $compileOption;
		$option[] = Markdown::SPECIAL_ATTRIBUTE;
		$option[] = Markdown::TOC;
		$markdown->setOption('compileOption', $option);

		$intermediate = $markdown->parse(phalcon_get_markdown('test19.md'));

		$this->assertEquals($intermediate, phalcon_get_markdown('test19.html'));

		$toc = <<<EOT
<ul>
<li>
<a href="#a">a</a>
<ul>
<li>
<a href="#b">B</a>
<ul>
<li>
<a href="#id">c</a>
</li>
</ul>
</li>
</ul>
</li>
<li>
<a href="#test-code">test <code>code</code></a>
</li>
</ul>

EOT;

		$this->assertEquals($toc, $markdown->getToc());

	}

	public function testMarkdownOverrideRender()
	{
		$markdown = new Markdown\Compiler();

		$markdown->setOption('compileRender', array(
			'blockcode' => 'phalcon_markdown_blockcode')
		);

		$intermediate = $markdown->parse(phalcon_get_markdown('test20.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test20.html'));
	}

	public function testMarkdownBeforeCompile()
	{
		$markdown = new Markdown\Compiler();

		$markdown->setOption('beforeCompile', 'phalcon_markdown_before');

		$intermediate = $markdown->parse(phalcon_get_markdown('test21.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test21.html'));
	}

	public function testMarkdownAfterCompile()
	{
		$markdown = new Markdown\Compiler();

		$markdown->setOption('afterCompile', 'phalcon_markdown_after');

		$intermediate = $markdown->parse(phalcon_get_markdown('test22.md'));
		$this->assertEquals($intermediate, phalcon_get_markdown('test22.html'));

		$this->assertArrayHasKey('compiled', $markdown->afterCompile);
		$this->assertEquals($markdown->afterCompile['compiled'], phalcon_get_markdown('test22.html'));
	}

}
