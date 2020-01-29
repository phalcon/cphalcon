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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt;

use DateTime;
use IntegrationTester;
use Phalcon\Di;
use Phalcon\Escaper;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Form;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tag;
use Phalcon\Url;
use stdClass;

/**
 * Phalcon\Test\Integration\Mvc\View\Engine\Volt\CompilerCest
 *
 * Test Compiler template engine
 */
class CompilerCest
{
    /**
     * Test to correct create content
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldCreateContent(IntegrationTester $I)
    {
        $I->wantToTest('Compile import recursive files');
        $I->skipTest('TODO - Check me');

        $I->safeDeleteFile(
            dataDir('fixtures/views/layouts/extends.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/extends/index.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/extends/other.volt.php')
        );

        $di = new Di();

        $view = new View();

        $view->setDI($di);

        $view->setViewsDir(
            dataDir('fixtures/views/')
        );

        $view->registerEngines(
            [
                '.volt' => Volt::class,
            ]
        );

        $view->setParamToView('song', 'Rock n roll');


        $view->start();

        $view->setRenderLevel(
            View::LEVEL_ACTION_VIEW
        );

        $view->render('extends', 'index');

        $view->finish();


        $I->assertEquals(
            'Hello Rock n roll!',
            $view->getContent()
        );

        $view->setParamToView('some_eval', true);


        $view->start();

        $view->setRenderLevel(
            View::LEVEL_LAYOUT
        );

        $view->render('extends', 'index');

        $view->finish();


        $I->assertEquals(
            'Clearly, the song is: Hello Rock n roll!.' . PHP_EOL,
            $view->getContent()
        );

        // Refreshing generated view
        $I->writeToFile(
            dataDir('fixtures/views/extends/other.volt'),
            '{{song}} {{song}}'
        );

        $view->setParamToView('song', 'Le Song');

        $view->start();

        $view->setRenderLevel(
            View::LEVEL_ACTION_VIEW
        );

        $view->render('extends', 'other');

        $view->finish();

        $I->assertEquals(
            'Le Song Le Song',
            $view->getContent()
        );

        $view->start();

        $view->setRenderLevel(
            View::LEVEL_LAYOUT
        );

        $view->render('extends', 'other');

        $view->finish();

        $I->assertEquals(
            'Clearly, the song is: Le Song Le Song.' . PHP_EOL,
            $view->getContent()
        );


        // Change the view
        $I->writeToFile(
            dataDir('fixtures/views/extends/other.volt'),
            'Two songs: {{song}} {{song}}'
        );

        $view->start();

        $view->setRenderLevel(
            View::LEVEL_LAYOUT
        );

        $view->render('extends', 'other');

        $view->finish();

        $I->assertEquals(
            'Clearly, the song is: Two songs: Le Song Le Song.' . PHP_EOL,
            $view->getContent()
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/layouts/extends.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/extends/index.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/extends/other.volt.php')
        );
    }

    /**
     * Test to correct create content with macros
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldCorrectWorkWithVoltMacros(IntegrationTester $I)
    {
        $I->wantToTest('Volt macros');

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/hello.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/conditionaldate.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/my_input.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/error_messages.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/related_links.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/strtotime.volt.php')
        );

        Di::reset();

        Tag::setDocType(
            Tag::XHTML5
        );

        $view = new View();
        $di   = new Di();

        $di->set(
            'escaper',
            function () {
                return new Escaper();
            }
        );

        $di->set(
            'tag',
            function () {
                return new Tag();
            }
        );

        $di->set(
            'url',
            function () {
                return (new Url())->setBaseUri('/');
            }
        );

        $view->setDI($di);

        $view->setViewsDir(
            dataDir('fixtures/views/')
        );

        $view->registerEngines(
            [
                '.volt' => function ($view) {
                    $volt = new Volt($view, $this);

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
        $I->assertEquals($expected, $actual);


        $view->start();
        $view->render('macro', 'conditionaldate');
        $view->finish();

        $expected = sprintf('from <br/>%s, %s UTC', date('Y-m-d'), date('H:i'));
        $actual   = $view->getContent();
        $I->assertEquals($expected, $actual);


        $view->start();
        $view->render('macro', 'my_input');
        $view->finish();

        $expected = '<p><input type="text" id="name" name="name" class="input-text" /></p>';
        $actual   = $view->getContent();
        $I->assertEquals($expected, $actual);


        $view->start();
        $view->render('macro', 'error_messages');
        $view->finish();

        $expected = '<div><span class="error-type">Invalid</span><span class="error-field">name</span>'
            . '<span class="error-message">The name is invalid</span></div>';
        $actual   = $view->getContent();
        $I->assertEquals($expected, $actual);


        $view->setVar(
            'links',
            [
                (object) [
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
        $I->assertEquals($expected, $actual);


        $view->setVar('date', new DateTime());
        $view->start();
        $view->render('macro', 'strtotime');
        $view->finish();

        $content = $view->getContent();
        $content = explode('%', $content);

        $I->assertCount(3, $content);
        $I->assertEquals($content[0], $content[1]);
        $I->assertEquals($content[1], $content[2]);
        $I->assertEquals($content[2], $content[0]);


        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/hello.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/conditionaldate.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/my_input.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/error_messages.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/related_links.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/strtotime.volt.php')
        );
    }

    /**
     * Test to correct create content with macros with object
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldAcceptObjectToVoltMacros(IntegrationTester $I)
    {
        $I->wantToTest('Volt macros can accept objects');

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/list.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/form_row.volt.php')
        );

        Di::reset();

        $view = new View();
        $di   = new Di();

        Tag::setDocType(
            Tag::XHTML5
        );

        $di->set(
            'escaper',
            function () {
                return new Escaper();
            }
        );

        $di->set(
            'tag',
            function () {
                return new Tag();
            }
        );

        $di->set(
            'url',
            function () {
                return (new Url())->setBaseUri('/');
            }
        );

        $view->setDI($di);
        $view->setViewsDir(dataDir('fixtures/views/'));
        $view->registerEngines([
            '.volt' => function ($view) {
                return new Volt($view, $this);
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

        $I->assertEquals($expected, $actual);


        $form = new Form();

        $form->add(
            new Password('password')
        );

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

        $I->assertEquals(
            $expected,
            $view->getContent()
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/list.volt.php')
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/macro/form_row.volt.php')
        );
    }

    /**
     * Test to correct compile string use loop
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldLoopContext(IntegrationTester $I)
    {
        $I->wantToTest('Volt Loop context');

        $volt = new Compiler();

        $compiled = $volt->compileString(
            '{% for i in 1..5 %}{{ loop.self.index }}{% endfor %}'
        );

        ob_start();

        eval(
            '?>' . $compiled
        );

        $result = ob_get_clean();

        $I->assertEquals('12345', $result);
    }
}
