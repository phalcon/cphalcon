<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Dispatcher;

use Phalcon\Mvc\Dispatcher;
use UnitTester;

class GetSetReturnedValueCest
{
    /**
     * Tests Phalcon\Dispatcher :: getReturnedValue()/setReturnedValue()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-17
     */
    public function dispatcherGetReturnedValue(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getReturnedValue()/setReturnedValue()');

        $dispatcher = new Dispatcher();

        $actual = $dispatcher->getReturnedValue();
        $I->assertEmpty($actual);

        $dispatcher->setReturnedValue('two');

        $expected = 'two';
        $actual   = $dispatcher->getReturnedValue();
        $I->assertEquals($expected, $actual);
    }
}
