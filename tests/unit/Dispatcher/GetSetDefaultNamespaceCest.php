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

class GetSetDefaultNamespaceCest
{
    /**
     * Tests Phalcon\Dispatcher :: getDefaultNamespace()/setDefaultNamespace()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-17
     */
    public function dispatcherGetSetDefaultNamespace(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getDefaultNamespace()/setDefaultNamespace()');

        $dispatcher = new Dispatcher();

        $actual = $dispatcher->getDefaultNamespace();
        $I->assertEmpty($actual);

        $dispatcher->setDefaultNamespace('two');

        $expected = 'two';
        $actual   = $dispatcher->getDefaultNamespace();
        $I->assertEquals($expected, $actual);
    }
}
