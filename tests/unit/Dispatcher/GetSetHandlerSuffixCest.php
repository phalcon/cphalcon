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

class GetSetHandlerSuffixCest
{
    /**
     * Tests Phalcon\Dispatcher :: getHandlerSuffix()/setHandlerSuffix()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-17
     */
    public function dispatcherGetSetHandlerSuffix(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getHandlerSuffix()/setHandlerSuffix()');

        $dispatcher = new Dispatcher();

        $expected = 'Controller';
        $actual = $dispatcher->getHandlerSuffix();
        $I->assertEquals($expected, $actual);

        $dispatcher->setHandlerSuffix('two');

        $expected = 'two';
        $actual   = $dispatcher->getHandlerSuffix();
        $I->assertEquals($expected, $actual);
    }
}
