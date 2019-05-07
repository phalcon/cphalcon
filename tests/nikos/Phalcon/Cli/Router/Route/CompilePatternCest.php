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

namespace Phalcon\Test\Unit\Cli\Router\Route;

use UnitTester;

class CompilePatternCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: compilePattern()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function cliRouterRouteCompilePattern(UnitTester $I)
    {
        $I->wantToTest('Cli\Router\Route - compilePattern()');

        $I->skipTest('Need implementation');
    }
}
