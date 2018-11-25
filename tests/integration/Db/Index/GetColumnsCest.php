<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Index;

use IntegrationTester;

class GetColumnsCest
{
    /**
     * Tests Phalcon\Db\Index :: getColumns()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbIndexGetColumns(IntegrationTester $I)
    {
        $I->wantToTest("Db\Index - getColumns()");
        $I->skipTest("Need implementation");
    }
}
