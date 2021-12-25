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

class GetSetNamespaceNameCest
{
    /**
     * Tests Phalcon\Dispatcher :: getNamespaceName()/setNamespaceName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-17
     */
    public function dispatcherGetSetNamespaceName(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getNamespaceName()/setNamespaceName()');

        $dispatcher = new Dispatcher();

        $actual = $dispatcher->getNamespaceName();
        $I->assertEmpty($actual);

        $dispatcher->setNamespaceName('two');

        $expected = 'two';
        $actual   = $dispatcher->getNamespaceName();
        $I->assertEquals($expected, $actual);
    }
}
