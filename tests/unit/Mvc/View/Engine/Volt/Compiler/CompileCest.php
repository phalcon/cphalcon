<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use UnitTester;

class CompileCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compile() - extends
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-01-29
     */
    public function mvcViewEngineVoltCompilerCompileExtends(UnitTester $I)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - compile() - extends");
        $I->skipTest('TODO = figure out the paths of the extended files');
        $viewFile     = dataFolder('fixtures/views/templates/c.volt');
        $compiledFile = $viewFile . '.php';

        $volt = new Compiler();
        $volt->compile($viewFile);

        $expected = "[A[###[B]###]]";
        $actual   = trim(file_get_contents($compiledFile));
        $I->assertEquals($expected, $actual);
        $I->safeDeleteFile(dataFolder('fixtures/views/templates/a.volt%%e%%.php'));
        $I->safeDeleteFile(dataFolder('fixtures/views/templates/b.volt%%e%%.php'));
        $I->safeDeleteFile($compiledFile);
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compile() - extends blocks
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineVoltCompilerCompileExtendsBlocks(UnitTester $I)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - compile() - extends blocks");
        $I->skipTest('TODO = figure out the paths of the extended files');
        $viewFile     = dataFolder('fixtures/views/compiler/children.volt');
        $compiledFile = $viewFile . '.php';
        $expected     = '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">'
            . '<html lang="en"><html xmlns="http://www.w3.org/1999/xhtml"><head>'
            . '<style type="text/css">.important { color: #336699; }</style>'
            . '<title>Index - My Webpage</title></head><body><div id="content">'
            . '<h1>Index</h1><p class="important">Welcome on my awesome homepage.</p></div>'
            . '<div id="footer">&copy; Copyright 2012 by '
            . '<a href="http://domain.invalid/">you</a>.</div></body>';

        $volt = new Compiler();
        $volt->compile($viewFile);

        $actual = trim(file_get_contents($compiledFile));
        $I->assertEquals($expected, $actual);
        $I->safeDeleteFile(dataFolder('fixtures/views/compiler/parent.volt%%e%%.php'));
        $I->safeDeleteFile($compiledFile);
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compile() - extends two
     * blocks
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineVoltCompilerCompileExtendsTwoBlocks(UnitTester $I)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - compile() - extends two blocks");
        $I->skipTest('TODO = figure out the paths of the extended files');
        $viewFile     = dataFolder('fixtures/views/compiler/children2.volt');
        $compiledFile = $viewFile . '.php';
        $expected     = '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">'
            . '<html lang="en"><html xmlns="http://www.w3.org/1999/xhtml"><head>'
            . '<style type="text/css">.important { color: #336699; } </style> '
            . '<link rel="stylesheet" href="style.css" /> <title>Index - My Webpage</title></head>'
            . '<body><div id="content"><h1>Index</h1><p class="important">Welcome to my awesome homepage.</p>'
            . '</div><div id="footer">&copy; Copyright 2012 by'
            . ' <a href="http://domain.invalid/">you</a>.</div></body>';

        $volt = new Compiler();
        $volt->compile($viewFile);

        $actual = trim(file_get_contents($compiledFile));
        $I->assertEquals($expected, $actual);
        $I->safeDeleteFile(dataFolder('fixtures/views/compiler/parent.volt%%e%%.php'));
        $I->safeDeleteFile($compiledFile);
    }
}
