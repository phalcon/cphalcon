<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt;

use DateTime;
use Phalcon\Di;
use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Tag;
use Phalcon\Mvc\Url;
use Phalcon\Escaper;
use Phalcon\Forms\Form;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Forms\Element\Password;
use Phalcon\Mvc\View\Engine\Volt\Compiler;

/**
 * Phalcon\Test\Integration\Mvc\View\Engine\Volt\CompilerCest
 *
 * Test Compiler template engine
 *
 * @package Phalcon\Test\Integration\Mvc\View\Engine\Volt
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

        $I->removeFilesWithoutErrors([
            PATH_DATA . 'views/layouts/test10.volt.php',
            PATH_DATA . 'views/test10/index.volt.php',
            PATH_DATA . 'views/test10/other.volt.php'
        ]);

        $di = new Di();

        $view = new View();
        $view->setDI($di);
        $view->setViewsDir(PATH_DATA . 'views/');

        $view->registerEngines([
            '.volt' => 'Phalcon\Mvc\View\Engine\Volt'
        ]);

        $view->setParamToView('song', 'Rock n roll');

        $view->start();
        $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
        $view->render('test10', 'index');
        $view->finish();
        expect($view->getContent())->equals('Hello Rock n roll!');

        $view->setParamToView('some_eval', true);

        $view->start();
        $view->setRenderLevel(View::LEVEL_LAYOUT);
        $view->render('test10', 'index');
        $view->finish();
        expect($view->getContent())->equals('Clearly, the song is: Hello Rock n roll!.' . PHP_EOL);

        //Refreshing generated view
        file_put_contents(PATH_DATA . 'views/test10/other.volt', '{{song}} {{song}}');

        $view->setParamToView('song', 'Le Song');

        $view->start();
        $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
        $view->render('test10', 'other');
        $view->finish();
        expect($view->getContent())->equals('Le Song Le Song');

        $view->start();
        $view->setRenderLevel(View::LEVEL_LAYOUT);
        $view->render('test10', 'other');
        $view->finish();
        expect($view->getContent())->equals('Clearly, the song is: Le Song Le Song.' . PHP_EOL);

        //Change the view
        file_put_contents(PATH_DATA . 'views/test10/other.volt', 'Two songs: {{song}} {{song}}');

        $view->start();
        $view->setRenderLevel(View::LEVEL_LAYOUT);
        $view->render('test10', 'other');
        $view->finish();
        expect($view->getContent())->equals('Clearly, the song is: Two songs: Le Song Le Song.' . PHP_EOL);
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

        $I->removeFilesWithoutErrors([
            PATH_DATA . 'views/macro/hello.volt.php',
            PATH_DATA . 'views/macro/conditionaldate.volt.php',
            PATH_DATA . 'views/macro/my_input.volt.php',
            PATH_DATA . 'views/macro/error_messages.volt.php',
            PATH_DATA . 'views/macro/related_links.volt.php',
            PATH_DATA . 'views/macro/strtotime.volt.php',
        ]);

        Di::reset();
        Tag::setDocType(Tag::XHTML5);

        $view = new View;
        $di = new Di;
        $di->set('escaper', function () {
            return new Escaper;
        });
        $di->set('tag', function () {
            return new Tag;
        });
        $di->set('url', function () {
            return (new Url)->setBaseUri('/');
        });

        $view->setDI($di);

        $view->setViewsDir(PATH_DATA . 'views/');

        $view->registerEngines([
            '.volt' => function ($view, $di) {
                $volt = new Volt($view, $di);
                $compiler = $volt->getCompiler();
                $compiler->addFunction('strtotime', 'strtotime');
                return $volt;
            }
        ]);

        $view->start();
        $view->render('macro', 'hello');
        $view->finish();
        expect($view->getContent())->equals('Hello World');

        $view->start();
        $view->render('macro', 'conditionaldate');
        $view->finish();
        expect($view->getContent())->equals(sprintf('from <br/>%s, %s UTC', date('Y-m-d'), date('H:i')));

        $view->start();
        $view->render('macro', 'my_input');
        $view->finish();
        expect($view->getContent())->equals('<p><input type="text" id="name" name="name" class="input-text" /></p>');

        $view->start();
        $view->render('macro', 'error_messages');
        $view->finish();
        expect($view->getContent())->equals('<div><span class="error-type">Invalid</span><span class="error-field">name</span><span class="error-message">The name is invalid</span></div>');

        $view->setVar(
            'links',
            [
                (object) [
                    'url' => 'localhost',
                    'text' => 'Menu item',
                    'title' => 'Menu title'
                ]
            ]
        );
        $view->start();
        $view->render('macro', 'related_links');
        $view->finish();
        expect($view->getContent())->equals('<ul><li><a href="/localhost" title="Menu title">Menu item</a></li></ul>');

        $view->setVar('date', new DateTime());
        $view->start();
        $view->render('macro', 'strtotime');
        $view->finish();

        $content = $view->getContent();
        $content = explode('%', $content);

        expect($content)->count(3);
        expect($content[0])->equals($content[1]);
        expect($content[1])->equals($content[2]);
        expect($content[2])->equals($content[0]);

        $I->removeFilesWithoutErrors([
            PATH_DATA . 'views/macro/hello.volt.php',
            PATH_DATA . 'views/macro/conditionaldate.volt.php',
            PATH_DATA . 'views/macro/my_input.volt.php',
            PATH_DATA . 'views/macro/error_messages.volt.php',
            PATH_DATA . 'views/macro/related_links.volt.php',
            PATH_DATA . 'views/macro/strtotime.volt.php',
        ]);
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

        $I->removeFilesWithoutErrors([
            PATH_DATA . 'views/macro/list.volt.php',
            PATH_DATA . 'views/macro/form_row.volt.php',
        ]);

        Di::reset();
        $view = new View;
        $di = new Di;
        Tag::setDocType(Tag::XHTML5);
        $di->set('escaper', function () {
            return new Escaper;
        });
        $di->set('tag', function () {
            return new Tag;
        });
        $di->set('url', function () {
            return (new Url)->setBaseUri('/');
        });

        $view->setDI($di);
        $view->setViewsDir(PATH_DATA . 'views/');
        $view->registerEngines([
            '.volt' => function ($view, $di) {
                return new Volt($view, $di);
            }
        ]);
        $object = new \stdClass();
        $object->foo = "bar";
        $object->baz = "buz";
        $object->pi  = 3.14;
        $object->ary = ["some array"];
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

        expect($actual)->equals($expected);

        $form = new Form;
        $form->add(new Password('password'));
        $view->setVar('formLogin', $form);
        $view->start();
        $view->render('macro', 'form_row');
        $view->finish();
        $actual =<<<FORM
<div class="form-group">
    <label class="col-sm-2 control-label" for="password">password:</label>
    <div class="col-sm-6"><input type="password" id="password" name="password" class="form-control " /></div>
</div>
FORM;

        expect($actual)->equals($view->getContent());

        $I->removeFilesWithoutErrors([
            PATH_DATA . 'views/macro/list.volt.php',
            PATH_DATA . 'views/macro/form_row.volt.php',
        ]);
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
        $compiled = $volt->compileString('{% for i in 1..5 %}{{ loop.self.index }}{% endfor %}');
        ob_start();
        eval('?>'.$compiled);

        $result = ob_get_clean();

        expect($result)->equals('12345');
    }
}
