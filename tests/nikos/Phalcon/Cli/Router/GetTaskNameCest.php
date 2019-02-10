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
 * Class GetTaskNameCest
 */
class GetTaskNameCest
{
    /**
     * Tests Phalcon\Cli\Router :: getTaskName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function cliRouterGetTaskName(UnitTester $I)
    {
        $I->wantToTest('Cli\Router - getTaskName()');
        $I->skipTest('Need implementation');
    }
}
