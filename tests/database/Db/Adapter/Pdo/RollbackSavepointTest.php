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

use Phalcon\Db\Enum;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class RollbackSavepointTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: rollbackSavepoint()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoRollbackSavepoint(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        new InvoicesMigration($connection);

        $db->setNestedTransactionsWithSavepoints(true);
        $this->assertTrue($db->begin());
        $this->assertTrue(
            $db->insertAsDict(
                'co_invoices',
                [
                    'inv_cst_id'      => 1,
                    'inv_status_flag' => 1,
                    'inv_title'       => 'before sp',
                    'inv_total'       => 1.0,
                ]
            )
        );
        $this->assertTrue($db->createSavepoint('sp1'));
        $this->assertTrue(
            $db->insertAsDict(
                'co_invoices',
                [
                    'inv_cst_id'      => 1,
                    'inv_status_flag' => 1,
                    'inv_title'       => 'after sp',
                    'inv_total'       => 1.0,
                ]
            )
        );
        $this->assertTrue($db->rollbackSavepoint('sp1'));
        $this->assertTrue($db->commit());

        $before = $db->fetchOne(
            'SELECT inv_title FROM co_invoices WHERE inv_title = ?',
            Enum::FETCH_ASSOC,
            ['before sp']
        );
        $this->assertSame('before sp', $before['inv_title']);

        $after = $db->fetchOne(
            'SELECT inv_title FROM co_invoices WHERE inv_title = ?',
            Enum::FETCH_ASSOC,
            ['after sp']
        );
        $this->assertEmpty($after);
    }
}
