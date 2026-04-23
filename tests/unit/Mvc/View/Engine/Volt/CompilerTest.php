<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalcon.io)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalcon.io so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use DateTime;
use Phalcon\Di\Di;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Form;
use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\TagFactory;
use Phalcon\Mvc\Url;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

use function dataDir;
use function file_put_contents;

/**
 * Phalcon\Tests\Unit\Mvc\View\Engine\Volt\CompilerTest extends AbstractUnitTestCase
 *
 * Test Compiler template engine
 */
class CompilerTest extends AbstractUnitTestCase
{
    /**
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldCreateContent(): void
    {
        $this->markTestSkipped('TODO - Check me');

        $this->clearFiles();

        Di::reset();
        $di   = new Di();
        $view = $this->setupServices($di);

        $view->registerEngines(
            [
                '.volt' => Volt::class,
            ]
        );

        $view->setParamToView('song', 'Rock n roll');


        $view->start();
        $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
        $view->render('extends', 'index');
        $view->finish();

        $expected = 'Hello Rock n roll!';
        $actual   = $view->getContent();
        $this->assertSame($expected, $actual);

        $view->setParamToView('some_eval', true);

        $view->start();
        $view->setRenderLevel(View::LEVEL_LAYOUT);
        $view->render('extends', 'index');
        $view->finish();


        $expected = 'Clearly, the song is: Hello Rock n roll!.' . PHP_EOL;
        $actual   = $view->getContent();
        $this->assertSame($expected, $actual);

        // Refreshing generated view
        file_put_contents(
            supportDir('assets/views/extends/other.volt'),
            '{{song}} {{song}}'
        );

        $view->setParamToView('song', 'Le Song');

        $view->start();
        $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
        $view->render('extends', 'other');
        $view->finish();

        $expected = 'Le Song Le Song';
        $actual   = $view->getContent();
        $this->assertSame($expected, $actual);

        $view->start();
        $view->setRenderLevel(View::LEVEL_LAYOUT);
        $view->render('extends', 'other');
        $view->finish();

        $expected = 'Clearly, the song is: Le Song Le Song.' . PHP_EOL;
        $actual   = $view->getContent();
        $this->assertSame($expected, $actual);

        // Change the view
        file_put_contents(
            supportDir('assets/views/extends/other.volt'),
            'Two songs: {{song}} {{song}}'
        );

        $view->start();
        $view->setRenderLevel(View::LEVEL_LAYOUT);
        $view->render('extends', 'other');
        $view->finish();

        $expected = 'Clearly, the song is: Two songs: Le Song Le Song.' . PHP_EOL;
        $actual   = $view->getContent();
        $this->assertSame($expected, $actual);

        $this->clearFiles();
    }

    /**
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function testMvcViewEngineVoltCompilerLoop(): void
    {
        $volt     = new Compiler();
        $compiled = $volt->compileString(
            '{% for i in 1..5 %}{{ loop.self.index }}{% endfor %}'
        );

        ob_start();

        eval('?>' . $compiled);

        $result = ob_get_clean();

        $this->assertEquals('12345', $result);
    }

    /**
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function testMvcViewEngineVoltCompilerMacros(): void
    {
        $this->clearFiles();

        Di::reset();
        $di   = new Di();
        $view = $this->setupServices($di);

        $view->registerEngines(
            [
                '.volt' => function ($view) use ($di) {
                    $volt = new Volt($view, $di);

                    $compiler = $volt->getCompiler();

                    $compiler->addFunction('strtotime', 'strtotime');

                    return $volt;
                },
            ]
        );

        $view->start();
        $view->render('macro', 'hello');
        $view->finish();

        $expected = 'Hello World';
        $actual   = $view->getContent();
        $this->assertEquals($expected, $actual);

        $view->start();
        $view->render('macro', 'conditionaldate');
        $view->finish();

        $expected = sprintf('from <br/>%s, %s UTC', date('Y-m-d'), date('H:i'));
        $actual   = $view->getContent();
        $this->assertEquals($expected, $actual);

        $view->start();
        $view->render('macro', 'my_input');
        $view->finish();

        $expected = '<p><input type="text" id="name" name="name" class="input-text" /></p>';
        $actual   = $view->getContent();
        $this->assertEquals($expected, $actual);

        $view->start();
        $view->render('macro', 'error_messages');
        $view->finish();

        $expected = '<div><span class="error-type">Invalid</span><span class="error-field">name</span>'
            . '<span class="error-message">The name is invalid</span></div>';
        $actual   = $view->getContent();
        $this->assertEquals($expected, $actual);

        $view->setVar(
            'links',
            [
                (object)[
                    'url'   => 'localhost',
                    'text'  => 'Menu item',
                    'title' => 'Menu title',
                ],
            ]
        );
        $view->start();
        $view->render('macro', 'related_links');
        $view->finish();

        $expected = '<ul><li><a href="/localhost" title="Menu title">Menu item</a></li></ul>';
        $actual   = $view->getContent();
        $this->assertEquals($expected, $actual);

        $view->setVar('date', new DateTime());
        $view->start();
        $view->render('macro', 'strtotime');
        $view->finish();

        $content = $view->getContent();
        $content = explode('%', $content);

        $this->assertCount(3, $content);
        $this->assertEquals($content[0], $content[1]);
        $this->assertEquals($content[1], $content[2]);
        $this->assertEquals($content[2], $content[0]);

        $this->clearFiles();
    }

    /**
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function testMvcViewEngineVoltCompilerMacrosWithObjects(): void
    {
        $this->clearFiles();

        Di::reset();
        $di   = new Di();
        $view = $this->setupServices($di);

        $view->registerEngines([
            '.volt' => function ($view) use ($di) {
                return new Volt($view, $di);
            },
        ]);

        $object      = new stdClass();
        $object->foo = 'bar';
        $object->baz = 'buz';
        $object->pi  = 3.14;
        $object->ary = ['some array'];
        $object->obj = clone $object;
        $view->setVar('object', $object);
        $view->start();
        $view->render('macro', 'list');
        $view->finish();
        ob_start();

        var_dump($object);

        $actual = ob_get_clean();

        // Trim xdebug first line (file path)
        $actual   = substr($actual, strpos($actual, 'class'));
        $expected = substr($view->getContent(), strpos($view->getContent(), 'class'));

        $this->assertEquals($expected, $actual);

        $escaper    = $di->get("escaper");
        $tagFactory = new TagFactory($escaper);

        $doctype     = $tagFactory->newInstance('doctype');
        $doctype(Doctype::XHTML5);

        $form       = new Form();
        $form->setTagFactory($tagFactory);

        $form->add(new Password('password'));
        $view->setVar('formLogin', $form);

        $view->start();
        $view->render('macro', 'form_row');
        $view->finish();

        $expected = <<<FORM
<div class="form-group">
    <label class="col-sm-2 control-label" for="password">password:</label>
    <div class="col-sm-6"><input type="password" id="password" name="password" class="form-control " /></div>
</div>
FORM;

        $actual = $view->getContent();
        $this->assertSame($expected, $actual);

        $this->clearFiles();
    }

    /**
     * @return void
     */
    private function clearFiles(): void
    {
        $this->safeDeleteFile(
            supportDir('assets/views/layouts/extends.volt.php')
        );

        $this->safeDeleteFile(
            supportDir('assets/views/extends/index.volt.php')
        );

        $this->safeDeleteFile(
            supportDir('assets/views/extends/other.volt.php')
        );

        $this->safeDeleteFile(
            supportDir('assets/views/macro/hello.volt.php')
        );

        $this->safeDeleteFile(
            supportDir('assets/views/macro/conditionaldate.volt.php')
        );

        $this->safeDeleteFile(
            supportDir('assets/views/macro/my_input.volt.php')
        );

        $this->safeDeleteFile(
            supportDir('assets/views/macro/error_messages.volt.php')
        );

        $this->safeDeleteFile(
            supportDir('assets/views/macro/related_links.volt.php')
        );

        $this->safeDeleteFile(
            supportDir('assets/views/macro/strtotime.volt.php')
        );

        $this->safeDeleteFile(
            supportDir('assets/views/macro/list.volt.php')
        );

        $this->safeDeleteFile(
            supportDir('assets/views/macro/form_row.volt.php')
        );
    }

    /**
     * Sets up a view with relevant services
     *
     * @return View
     */
    private function setupServices(Di $di): View
    {
        $escaper    = new Escaper();
        $tagFactory = new TagFactory($escaper);
        $view       = new View();

        $doctype    = $tagFactory->newInstance('doctype');
        $doctype(Doctype::XHTML5);

        $di->set("escaper", $escaper);
        $di->set("tag", $tagFactory);

        $di->set(
            "url",
            function () {
                return (new Url())->setBaseUri('/');
            }
        );
        $view->setDI($di);

        $view->setViewsDir(supportDir('assets/views/'));

        return $view;
    }
}
