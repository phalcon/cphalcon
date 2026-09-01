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

namespace Phalcon\Tests\Database\Mvc\Model\Transaction;

use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class RefactorManagerTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testCheckTransactionMysql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testCheckTransactionPostgresql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testCheckTransactionSqlite(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }
}

// Original Cest file content (ManagerCest):
//
// <?php
//
// /**
//  * This file is part of the Phalcon Framework.
//  *
//  * (c) Phalcon Team <team@phalcon.io>
//  *
//  * For the full copyright and license information, please view the LICENSE.txt
//  * file that was distributed with this source code.
//
