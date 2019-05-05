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

namespace Phalcon\Test\Cli\Cli\Router\Route;

use CliTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliRouterRouteConstruct(CliTester $I)
    {
        $I->wantToTest('Cli\Router\Route - __construct()');

        $I->skipTest('Need implementation');
    }
}
