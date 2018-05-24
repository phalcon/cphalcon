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

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tag;
use Phalcon\Mvc\View;
use IntegrationTester;

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

        $I->removeFilesWithoutErrors([
            PATH_DATA . 'views/layouts/test10.volt.php',
            PATH_DATA . 'views/test10/children.extends.volt.php'
        ]);

        $view = new View();
        $view->setViewsDir(PATH_DATA . 'views/');

        $volt = new Compiler($view);

        //extends
        $volt->compileFile(
            PATH_DATA . 'views/test10/children.extends.volt',
            PATH_DATA . 'views/test10/children.extends.volt.php'
        );

        $compilation = file_get_contents(PATH_DATA . 'views/test10/children.extends.volt.php');

        expect($compilation)->equals('<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"><html lang="en"><html xmlns="http://www.w3.org/1999/xhtml"><head><style type="text/css">.important { color: #336699; }</style><title>Index - My Webpage</title></head><body><div id="content"><h1>Index</h1><p class="important">Welcome on my awesome homepage.</p></div><div id="footer">&copy; Copyright 2012 by <a href="http://domain.invalid/">you</a>.</div></body>');
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

        $I->removeFilesWithoutErrors([
            PATH_DATA . 'views/partials/header.volt.php',
            PATH_DATA . 'views/partials/footer.volt.php',
            PATH_DATA . 'views/test10/import.volt.php'
        ]);

        $view = new View();
        $view->setViewsDir(PATH_DATA . 'views/');

        $volt = new Compiler($view);
        //extends
        $volt->compileFile(
            PATH_DATA . 'views/test10/import.volt',
            PATH_DATA . 'views/test10/import.volt.php'
        );

        $compilation = file_get_contents(PATH_DATA . 'views/test10/import.volt.php');

        expect($compilation)->equals('<div class="header"><h1>This is the header</h1></div><div class="footer"><p>This is the footer</p></div>');
    }

    /**
     * Tests Compiler::compileFile test case to compile imported files recursively
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldCompileImportRecursiveFiles(IntegrationTester $I)
    {
        $I->wantToTest('Compile import recursive files');

        $I->removeFilesWithoutErrors([
            PATH_DATA . 'views/partials/header3.volt.php',
            PATH_DATA . 'views/partials/header2.volt.php',
            PATH_DATA . 'views/test10/import2.volt.php'
        ]);

        $view = new View();
        $view->setViewsDir(PATH_DATA . 'views/');

        $volt = new Compiler($view);

        //extends
        $volt->compileFile(
            PATH_DATA . 'views/test10/import2.volt',
            PATH_DATA . 'views/test10/import2.volt.php'
        );

        $compilation = file_get_contents(PATH_DATA . 'views/test10/import2.volt.php');

        expect($compilation)->equals('<div class="header"><h1>This is the title</h1></div>');
    }
}
