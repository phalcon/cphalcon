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

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Tag;
use function cacheFolder;
use function dataFolder;

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

        $view         = new View();
        $volt         = new Volt($view, new Di());
        $baseFile     = dataFolder('fixtures/views/extends/index');
        $renderFile   = $baseFile . '.volt';
        $compiledFile = $I->preparePathToFileWithDelimiter($baseFile, '.')
            . '.volt.compiled';
        $compiledFile = cacheFolder($compiledFile);

        $volt->setOptions(
            [
                'compiledPath'      => cacheFolder(),
                'compiledSeparator' => '.',
                'compiledExtension' => '.compiled',
            ]
        );

        //Render simple view
        $view->start();
        $volt->render($renderFile, ['song' => 'Lights'], true);
        $view->finish();

        $I->assertTrue(file_exists($compiledFile));
        $I->assertEquals(file_get_contents($compiledFile), 'Hello <?= $song ?>!');
        $I->assertEquals($view->getContent(), 'Hello Lights!');
        $I->safeDeleteFile($compiledFile);
    }
}
