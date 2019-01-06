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

use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt\Compiler;

/**
 * Phalcon\Test\Integration\Mvc\View\Engine\Volt\CompilerFilesCest
 *
 * Test working Compiler with files
 *
 * @package Phalcon\Test\Integration\Mvc\View\Engine\Volt
 */
class CompilerFilesCest
{
    /**
     * Tests Compiler::compileFile test case to compile extended files
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldCompileExtendsFile(IntegrationTester $I)
    {
        $I->wantToTest('Compile extended files');

        $I->safeDeleteFile(dataFolder('fixtures/views/layouts/extends.volt.php'));
        $I->safeDeleteFile(dataFolder('fixtures/views/extends/children.extends.volt.php'));

        $view = new View();
        $view->setViewsDir(dataFolder('fixtures/views/'));

        $volt = new Compiler($view);

        //extends
        $volt->compileFile(
            dataFolder('fixtures/views/extends/children.extends.volt'),
            dataFolder('fixtures/views/extends/children.extends.volt.php')
        );

        $compilation = file_get_contents(dataFolder('fixtures/views/extends/children.extends.volt.php'));
        $expected    = '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">'
            . '<html lang="en"><html xmlns="http://www.w3.org/1999/xhtml">'
            . '<head><style type="text/css">.important { color: #336699; }</style>'
            . '<title>Index - My Webpage</title></head><body>'
            . '<div id="content"><h1>Index</h1><p class="important">Welcome on my awesome homepage.</p>'
            . '</div><div id="footer">&copy; Copyright 2012 by <a href="http://domain.invalid/">you</a>.'
            . '</div></body>';
        $I->assertEquals($expected, $compilation);
    }

    /**
     * Tests Compiler::compileFile test case to compile imported files
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldCompileImportFile(IntegrationTester $I)
    {
        $I->wantToTest('Compile imported files');

        $I->safeDeleteFile(dataFolder('fixtures/views/partials/header.volt.php'));
        $I->safeDeleteFile(dataFolder('fixtures/views/partials/footer.volt.php'));
        $I->safeDeleteFile(dataFolder('fixtures/views/extends/import.volt.php'));

        $view = new View();
        $view->setViewsDir(dataFolder('fixtures/views/'));

        $volt = new Compiler($view);
        //extends
        $volt->compileFile(
            dataFolder('fixtures/views/extends/import.volt'),
            dataFolder('fixtures/views/extends/import.volt.php')
        );

        $compilation = file_get_contents(dataFolder('fixtures/views/extends/import.volt.php'));
        $expected    = '<div class="header"><h1>This is the header</h1></div>'
            . '<div class="footer"><p>This is the footer</p></div>';
        $I->assertEquals($expected, $compilation);
    }

    /**
     * Tests Compiler::compileFile test case to compile imported files
     * recursively
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldCompileImportRecursiveFiles(IntegrationTester $I)
    {
        $I->wantToTest('Compile import recursive files');

        $I->safeDeleteFile(dataFolder('fixtures/views/partials/header3.volt.php'));
        $I->safeDeleteFile(dataFolder('fixtures/views/partials/header2.volt.php'));
        $I->safeDeleteFile(dataFolder('fixtures/views/extends/import2.volt.php'));

        $view = new View();
        $view->setViewsDir(dataFolder('fixtures/views/'));

        $volt = new Compiler($view);

        //extends
        $volt->compileFile(
            dataFolder('fixtures/views/extends/import2.volt'),
            dataFolder('fixtures/views/extends/import2.volt.php')
        );

        $compilation = file_get_contents(dataFolder('fixtures/views/extends/import2.volt.php'));
        $expected    = '<div class="header"><h1>This is the title</h1></div>';
        $I->assertEquals($expected, $compilation);
    }
}
