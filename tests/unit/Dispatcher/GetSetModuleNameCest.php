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

class GetSetModuleNameCest
{
    /**
     * Tests Phalcon\Dispatcher :: getModuleName()/setModuleName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-17
     */
    public function dispatcherGetSetModuleName(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getModuleName()/setModuleName()');

        $dispatcher = new Dispatcher();

        $actual = $dispatcher->getModuleName();
        $I->assertEmpty($actual);

        $dispatcher->setModuleName('two');

        $expected = 'two';
        $actual   = $dispatcher->getModuleName();
        $I->assertEquals($expected, $actual);
    }
}
