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
 * Class GetTemplatePathCest
 */
class GetTemplatePathCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: getTemplatePath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcViewEngineVoltCompilerGetTemplatePath(UnitTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt\Compiler - getTemplatePath()');
        $I->skipTest('Need implementation');
    }
}
