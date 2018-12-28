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

namespace Phalcon\Test\Unit\Dispatcher;

use UnitTester;

/**
 * Class DispatchCest
 */
class DispatchCest
{
    /**
     * Tests Phalcon\Dispatcher :: dispatch()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dispatcherDispatch(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - dispatch()');
        $I->skipTest('Need implementation');
    }
}
