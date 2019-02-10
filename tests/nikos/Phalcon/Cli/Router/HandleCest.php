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

namespace Phalcon\Test\Unit\Cli\Router;

use UnitTester;

/**
 * Class HandleCest
 */
class HandleCest
{
    /**
     * Tests Phalcon\Cli\Router :: handle()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function cliRouterHandle(UnitTester $I)
    {
        $I->wantToTest('Cli\Router - handle()');
        $I->skipTest('Need implementation');
    }
}
