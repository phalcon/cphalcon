<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Binder;

use IntegrationTester;

class GetCacheCest
{
    /**
     * Tests Phalcon\Mvc\Model\Binder :: getCache()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelBinderGetCache(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Binder - getCache()");
        $I->skipTest("Need implementation");
    }
}
