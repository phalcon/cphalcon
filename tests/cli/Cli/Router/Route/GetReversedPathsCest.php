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
 * Class GetReversedPathsCest
 */
class GetReversedPathsCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: getReversedPaths()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliRouterRouteGetReversedPaths(CliTester $I)
    {
        $I->wantToTest('Cli\Router\Route - getReversedPaths()');
        $I->skipTest('Need implementation');
    }
}
