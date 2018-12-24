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

/**
 * Class DelimiterCest
 */
class DelimiterCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: delimiter()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliRouterRouteDelimiter(CliTester $I)
    {
        $I->wantToTest('Cli\Router\Route - delimiter()');
        $I->skipTest('Need implementation');
    }
}
