<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter;

use IntegrationTester;

class ListTablesCest
{
    /**
     * Tests Phalcon\Db\Adapter :: listTables()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterListTables(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter - listTables()");
        $I->skipTest("Need implementation");
    }
}
