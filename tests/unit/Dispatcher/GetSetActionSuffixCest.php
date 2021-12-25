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

class GetSetActionSuffixCest
{
    /**
     * Tests Phalcon\Dispatcher :: getActionSuffix()/setActionSuffix()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-17
     */
    public function dispatcherGetSetActionSuffix(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getActionSuffix()/setActionSuffix()');

        $dispatcher = new Dispatcher();

        $expected = 'Action';
        $actual   = $dispatcher->getActionSuffix();
        $I->assertEquals($expected, $actual);

        $dispatcher->setActionSuffix('two');

        $expected = 'two';
        $actual   = $dispatcher->getActionSuffix();
        $I->assertEquals($expected, $actual);
    }
}
