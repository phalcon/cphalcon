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


class ViewEnginesVoltTest extends PHPUnit_Framework_TestCase
{

	public function testVoltParser()
	{

		$volt = new \Phalcon\Mvc\View\Engine\Volt\Compiler();

		$intermediate = $volt->parse('');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 0);

		//Comments
		$intermediate = $volt->parse('{# hello #}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 0);

		$intermediate = $volt->parse('{# hello #}{# other comment #}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 0);

		//Common Expressions
		$intermediate = $volt->parse('hello');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('{{ "hello" }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('{{ "hello" }}{{ "hello" }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('{{ "hello" }}-{{ "hello" }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('-{{ "hello" }}{{ "hello" }}-');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->parse('-{{ "hello" }}-{{ "hello" }}-');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 5);

		$intermediate = $volt->parse('Some = {{ 100+50 }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('Some = {{ 100-50 }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('Some = {{ 100*50 }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('Some = {{ 100/50 }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('Some = {{ 100%50 }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('Some = {{ 100~50 }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		//Array acccess
		$intermediate = $volt->parse('{{ a[0 ]}}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('{{ a[0 ][1]}}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('{{ a[0]["hello"] }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('{{ a[0][1.2][false][true] }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		//Attribute access
		$intermediate = $volt->parse('{{ a.b }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('{{ a.b.c }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		//Ranges
		$intermediate = $volt->parse('{{ 1..100 }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse('{{ "Z".."A" }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse("{{ 'a'..'z' }}");
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse("{{ 'a' .. 'z' }}");
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		//Calling functions
		$intermediate = $volt->parse("{{ contents() }}");
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse("{{ link_to('hello', 'some-link') }}");
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse("{{ form('action': 'save/products', 'method': 'post') }}");
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$intermediate = $volt->parse("{{ form('action': 'save/products', 'method': other_func(1, 2, 3)) }}");
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		//if statement
		$intermediate = $volt->parse('{% if a==b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% if a!=b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% if a<b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% if a>b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% if a<=b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% if a>=b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% if a===b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% if a!==b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% if a==b and c==d %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% if a==b or c==d %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% if a==b %} hello {% else %} not hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->parse('{% if a==b %} {% if c==d %} hello {% endif %} {% else %} not hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->parse('{% if a==b %} hello {% else %} {% if c==d %} not hello {% endif %} {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		//for statement
		$intermediate = $volt->parse('{% for a in b %} hello {% endfor %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->parse('{% for a in b[0] %} hello {% endfor %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->parse('{% for a in b.c %} hello {% endfor %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->parse('{% for a in 1..10 %} hello {% endfor %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->parse('{% for a in 1..10 %} {% for b in 1..10 %} hello {% endfor %} {% endfor %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		//set statement
		$intermediate = $volt->parse('{% set a = 1 %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% set a.x = 1 %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% set a.x = 1.2 %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->parse('{% set a.x = 1.2+1*(20/b) and c %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		//Mixed
		$intermediate = $volt->parse('{# some comment #}{{ "hello" }}{# other comment }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

	}

	public function testVoltCompiler(){

		$volt = new \Phalcon\Mvc\View\Engine\Volt\Compiler();

		$compilation = $volt->compileString('');
		$this->assertEquals($compilation, '');

		//Comments
		$compilation = $volt->compileString('{# hello #}');
		$this->assertEquals($compilation, '');

		$compilation = $volt->compileString('{# hello #}{# other comment #}');
		$this->assertEquals($compilation, '');

		//Common Expressions
		$compilation = $volt->compileString('hello');
		$this->assertEquals($compilation, 'hello');

		$compilation = $volt->compileString('{{ "hello" }}');
		$this->assertEquals($compilation, "<?php echo 'hello'; ?>");

		$compilation = $volt->compileString('{{ "hello" }}{{ "hello" }}');
		$this->assertEquals($compilation, "<?php echo 'hello'; ?><?php echo 'hello'; ?>");

		$compilation = $volt->compileString('{{ "hello" }}-{{ "hello" }}');
		$this->assertEquals($compilation, "<?php echo 'hello'; ?>-<?php echo 'hello'; ?>");

		$compilation = $volt->compileString('-{{ "hello" }}{{ "hello" }}-');
		$this->assertEquals($compilation, "-<?php echo 'hello'; ?><?php echo 'hello'; ?>-");

		$compilation = $volt->compileString('-{{ "hello" }}-{{ "hello" }}-');
		$this->assertEquals($compilation, "-<?php echo 'hello'; ?>-<?php echo 'hello'; ?>-");

		$compilation = $volt->compileString('Some = {{ 100+50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 + 50; ?>");

		$compilation = $volt->compileString('Some = {{ 100-50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 - 50; ?>");

		$compilation = $volt->compileString('Some = {{ 100*50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 * 50; ?>");

		$compilation = $volt->compileString('Some = {{ 100/50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 / 50; ?>");

		$compilation = $volt->compileString('Some = {{ 100%50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 % 50; ?>");

		$compilation = $volt->compileString('Some = {{ 100~50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 . 50; ?>");

		//Array acccess
		$compilation = $volt->compileString('{{ a[0 ]}}');
		$this->assertEquals($compilation, '<?php echo $a[0]; ?>');

		$compilation = $volt->compileString('{{ a[0 ] [ 1]}}');
		$this->assertEquals($compilation, '<?php echo $a[0][1]; ?>');

		$compilation = $volt->compileString('{{ a[0]  [ "hello"] }}');
		$this->assertEquals($compilation, '<?php echo $a[0][\'hello\']; ?>');

		$compilation = $volt->compileString('{{ a[0] [1.2] [false] [true] }}');
		$this->assertEquals($compilation, '<?php echo $a[0][1.2][false][true]; ?>');

		//Attribute access
		$compilation = $volt->compileString('{{ a.b }}');
		$this->assertEquals($compilation, '<?php echo $a->b; ?>');

		$compilation = $volt->compileString('{{ a.b.c }}');
		$this->assertEquals($compilation, '<?php echo $a->b->c; ?>');

		//Ranges
		$compilation = $volt->compileString('{{ 1..100 }}');
		$this->assertEquals($compilation, '<?php echo range(1, 100); ?>');

		$compilation = $volt->compileString('{{ "Z".."A" }}');
		$this->assertEquals($compilation, '<?php echo range(\'Z\', \'A\'); ?>');

		$compilation = $volt->compileString("{{ 'a'..'z' }}");
		$this->assertEquals($compilation, '<?php echo range(\'a\', \'z\'); ?>');

		$compilation = $volt->compileString("{{ 'a' .. 'z' }}");
		$this->assertEquals($compilation, '<?php echo range(\'a\', \'z\'); ?>');

		//Calling functions
		$compilation = $volt->compileString("{{ content() }}");
		$this->assertEquals($compilation, '<?php echo $this->getContent(); ?>');

		$compilation = $volt->compileString("{{ link_to('hello', 'some-link') }}");
		$this->assertEquals($compilation, '<?php echo Phalcon\Tag::linkTo(array(\'hello\', \'some-link\')); ?>');

		$compilation = $volt->compileString("{{ form('action': 'save/products', 'method': 'post') }}");
		$this->assertEquals($compilation, '<?php echo Phalcon\Tag::form(array(\'action\' => \'save/products\', \'method\' => \'post\')); ?>');

		//if statement
		/*$intermediate = $volt->compileString('{% if a==b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% if a!=b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% if a<b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% if a>b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% if a<=b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% if a>=b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% if a===b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% if a!==b %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% if a==b and c==d %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% if a==b or c==d %} hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% if a==b %} hello {% else %} not hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->compileString('{% if a==b %} {% if c==d %} hello {% endif %} {% else %} not hello {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->compileString('{% if a==b %} hello {% else %} {% if c==d %} not hello {% endif %} {% endif %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		//for statement
		$intermediate = $volt->compileString('{% for a in b %} hello {% endfor %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->compileString('{% for a in b[0] %} hello {% endfor %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->compileString('{% for a in b.c %} hello {% endfor %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->compileString('{% for a in 1..10 %} hello {% endfor %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		$intermediate = $volt->compileString('{% for a in 1..10 %} {% for b in 1..10 %} hello {% endfor %} {% endfor %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 4);

		//set statement
		$intermediate = $volt->compileString('{% set a = 1 %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% set a.x = 1 %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% set a.x = 1.2 %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		$intermediate = $volt->compileString('{% set a.x = 1.2+1*(20/b) and c %}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 3);

		//Mixed
		$intermediate = $volt->compileString('{# some comment #}{{ "hello" }}{# other comment }}');
		$this->assertTrue(is_array($intermediate));
		$this->assertEquals(count($intermediate), 2);

		$volt->compile('unit-tests/views/layouts/test10.volt', 'unit-tests/views/layouts/test10.volt.php');*/

	}

	public function testVoltEngine()
	{

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.volt' => 'Phalcon\Mvc\View\Engine\Volt'
		));

		$view->setParamToView('song', 'Rock n roll');

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_ACTION_VIEW);
		$view->render('test10', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Hello Rock n roll!');

		$view->setParamToView('some_eval', true);

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_LAYOUT);
		$view->render('test10', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Clearly, the song is: Hello Rock n roll!.'."\n");

	}

}
