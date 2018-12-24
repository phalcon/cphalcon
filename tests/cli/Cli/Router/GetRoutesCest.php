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

namespace Phalcon\Test\Cli\Cli\Router;

use CliTester;

/**
 * Class GetRoutesCest
 */
class GetRoutesCest
{
    /**
     * Tests Phalcon\Cli\Router :: getRoutes()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliRouterGetRoutes(CliTester $I)
    {
        $I->wantToTest('Cli\Router - getRoutes()');
        $I->skipTest('Need implementation');
    }
}
