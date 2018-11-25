<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use IntegrationTester;

class RollbackSavepointCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: rollbackSavepoint()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testRollbackSavepoint(IntegrationTester $I)
    {
        $I->skipTest("Need implementation");
    }
}
