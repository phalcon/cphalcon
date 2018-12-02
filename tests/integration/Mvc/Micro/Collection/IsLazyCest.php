<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Micro\Collection;

use IntegrationTester;

class IsLazyCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: isLazy()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroCollectionIsLazy(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Micro\Collection - isLazy()");
        $I->skipTest("Need implementation");
    }
}
