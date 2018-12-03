<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Paginator\Adapter\Model;

use IntegrationTester;

class SetLimitCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\Model :: setLimit()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorAdapterModelSetLimit(IntegrationTester $I)
    {
        $I->wantToTest("Paginator\Adapter\Model - setLimit()");
        $I->skipTest("Need implementation");
    }
}
