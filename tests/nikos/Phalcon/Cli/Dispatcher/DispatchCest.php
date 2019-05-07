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

class DispatchCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: dispatch()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function cliDispatcherDispatch(UnitTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - dispatch()');

        $I->skipTest('Need implementation');
    }
}
