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

namespace Phalcon\Test\Unit\Cli\Dispatcher;

use UnitTester;

/**
 * Class SetTaskNameCest
 */
class SetTaskNameCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: setTaskName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliDispatcherSetTaskName(UnitTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - setTaskName()');
        $I->skipTest('Need implementation');
    }
}
