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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class GetNestedTransactionSavepointNameTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: getNestedTransactionSavepointName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoGetNestedTransactionSavepointName(): void
    {
        $db = $this->container->get('db');

        $db->setNestedTransactionsWithSavepoints(true);

        $this->assertSame('PHALCON_SAVEPOINT_0', $db->getNestedTransactionSavepointName());
        $db->begin();
        $this->assertSame('PHALCON_SAVEPOINT_1', $db->getNestedTransactionSavepointName());
        $db->begin();
        $this->assertSame('PHALCON_SAVEPOINT_2', $db->getNestedTransactionSavepointName());
        $db->rollback();
        $db->rollback();
    }
}
