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

class GetSetHasParamCest
{
    /**
     * Tests Phalcon\Dispatcher :: getParam()/setParam()/hasParam()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-17
     */
    public function dispatcherGetSetHasParam(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getParam()/setParam()/hasParam()');

        $dispatcher = new Dispatcher();

        $actual = $dispatcher->hasParam('one');
        $I->assertFalse($actual);

        $dispatcher->setParam('one', 'two');

        $actual = $dispatcher->hasParam('one');
        $I->assertTrue($actual);

        $expected = 'two';
        $actual   = $dispatcher->getParam('one');
        $I->assertEquals($expected, $actual);
    }
}
