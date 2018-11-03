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

namespace Phalcon\Test\Integration\Mvc\View\Engine;

use Phalcon\Di;
use Phalcon\Tag;
use Phalcon\Mvc\View;
use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt;

/**
 * Phalcon\Test\Integration\Mvc\View\Engine\VoltCest
 *
 * Test work Volt template engine
 *
 * @package Phalcon\Test\Integration\Mvc\View\Engine
 */
class VoltCest
{
    /**
     * Tests Volt::render
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-29
     */
    public function shouldVoltRenderWithSetOption(IntegrationTester $I)
    {
        $I->wantToTest('Set option and render simple view');

        $view = new View();
        $volt = new Volt($view, new Di());

        $volt->setOptions([
            'compiledPath' => PATH_CACHE,
            'compiledSeparator' => '.',
            'compiledExtension' => '.compiled'
        ]);

        //Render simple view
        $view->start();
        $volt->render(PATH_DATA . 'views/test10/index.volt', ['song' => 'Lights'], true);
        $view->finish();

        $path = PATH_CACHE . $I->preparePathToFileWithDelimiter(TESTS_PATH . '_data', '.') . '.views.test10.index.volt.compiled';

        $I->assertTrue(file_exists($path));
        $I->assertEquals(file_get_contents($path), 'Hello <?= $song ?>!');
        $I->assertEquals($view->getContent(), 'Hello Lights!');
        $I->removeFilesWithoutErrors([
            $path,
        ]);
    }
}
