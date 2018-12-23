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

/**
 * Class GetPatternCest
 */
class GetPatternCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: getPattern()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliRouterRouteGetPattern(UnitTester $I)
    {
        $I->wantToTest('Cli\Router\Route - getPattern()');
        $I->skipTest('Need implementation');
    }
}
