<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Dispatcher;

use UnitTester;

class GetPreviousNamespaceNameCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: getPreviousNamespaceName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcDispatcherGetPreviousNamespaceName(UnitTester $I)
    {
        $I->wantToTest("Mvc\Dispatcher - getPreviousNamespaceName()");
        $I->skipTest("Need implementation");
    }
}
