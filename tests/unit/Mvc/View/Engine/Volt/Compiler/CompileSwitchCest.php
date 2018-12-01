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

class CompileSwitchCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compileSwitch() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineVoltCompilerCompileSwitchEmpty(UnitTester $I)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - compileSwitch()");

        $viewFile    = env('PATH_DATA') . 'fixtures/views/switch-case/simple-usage.volt';
        $compileFile = $viewFile . '.php';
        $volt        = new Compiler();
        $volt->compileFile($viewFile, $compileFile);

        $actual   = file_get_contents($compileFile);
        $expected = "<?php switch (\$username): ?>\n" .
            "<?php case 'Jim': ?>\n" .
            "Hello username\n" .
            "<?php case 'Nik': ?>\n" .
            "<?= \$username ?>!\n" .
            "<?php break; ?>\n" .
            "<?php default: ?>\n" .
            "Who are you?\n" .
            "<?php endswitch ?>\n";
        $I->assertEquals($expected, $actual);
        $I->safeDeleteFile($compileFile);
    }
}
