<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Router\Route;

use CliTester;

class GetRouteIdCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: getRouteId()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterRouteGetRouteId(CliTester $I)
    {
        $I->wantToTest('Cli\Router\Route - getRouteId()');
        $I->skipTest('Need implementation');
    }
}
