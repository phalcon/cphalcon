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

class ForwardCest
{
    /**
     * Tests Phalcon\Dispatcher :: forward()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dispatcherForward(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - forward()');

        $I->skipTest('Need implementation');
    }
}
