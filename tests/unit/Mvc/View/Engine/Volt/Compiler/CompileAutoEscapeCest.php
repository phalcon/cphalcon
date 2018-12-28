<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\View\Engine\Volt\Compiler;

use UnitTester;

/**
 * Class CompileAutoEscapeCest
 */
class CompileAutoEscapeCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compileAutoEscape()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineVoltCompilerCompileAutoEscape(UnitTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt\Compiler - compileAutoEscape()');
        $I->skipTest('Need implementation');
    }
}
