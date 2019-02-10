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
 * Class SetEventsManagerCest
 */
class SetEventsManagerCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: setEventsManager()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function cliDispatcherSetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - setEventsManager()');
        $I->skipTest('Need implementation');
    }
}
