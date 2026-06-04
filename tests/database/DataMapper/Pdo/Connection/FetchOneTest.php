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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use PDO;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use PHPUnit\Framework\Attributes\DataProvider;

final class FetchOneTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionFetchOne(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $migration  = new InvoicesMigration(self::getConnection());
        $migration->clear();

        $result = $migration->insert(1);
        $this->assertEquals(1, $result);

        $all = $connection->fetchOne(
            'select * from co_invoices WHERE inv_id = ?',
            [
                0 => 1,
            ]
        );

        $this->assertIsArray($all);
        $this->assertEquals(1, $all['inv_id']);
        $this->assertArrayHasKey('inv_id', $all);
        $this->assertArrayHasKey('inv_cst_id', $all);
        $this->assertArrayHasKey('inv_status_flag', $all);
        $this->assertArrayHasKey('inv_title', $all);
        $this->assertArrayHasKey('inv_total', $all);
        $this->assertArrayHasKey('inv_created_at', $all);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionFetchOneNoResult(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $migration  = new InvoicesMigration(self::getConnection());
        $migration->clear();

        $result = $migration->insert(1);
        $this->assertEquals(1, $result);

        $all = $connection->fetchOne(
            'select * from co_invoices WHERE inv_id = ?',
            [
                0 => 7,
            ]
        );

        $this->assertIsArray($all);
        $this->assertEmpty($all);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    #[DataProvider('providerFetchOneBindTypes')]
    public function testDMPdoConnectionFetchOneBindTypes(
        string $label,
        string $condition,
        array $values
    ): void {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $migration  = new InvoicesMigration(self::getConnection());
        $migration->clear();

        $result = $migration->insert(1, 1, 1, 'test-1');
        $this->assertEquals(1, $result);

        $all = $connection->fetchOne(
            'select * from co_invoices WHERE ' . $condition,
            $values
        );

        $this->assertIsArray($all);
        $this->assertEquals(1, $all['inv_id']);
    }

    public static function providerFetchOneBindTypes(): array
    {
        return [
            [
                'numeric',
                'inv_id = ?',
                [0 => 1],
            ],
            [
                'named',
                'inv_id = :id',
                ['id' => 1],
            ],
            [
                'named boolean',
                'inv_status_flag = :status',
                [
                    'status' => true,
                ],
            ],
            [
                'named boolean with type',
                'inv_status_flag = :status',
                [
                    'status' => [true, PDO::PARAM_BOOL],
                ],
            ],
            [
                'named null',
                'inv_id = :id AND inv_status_flag IS NOT :status',
                [
                    'id'     => 1,
                    'status' => null,
                ],
            ],
            [
                'named null with type',
                'inv_id = :id AND inv_status_flag IS NOT :status',
                [
                    'id'     => [1, PDO::PARAM_INT],
                    'status' => [null, PDO::PARAM_NULL],
                ],
            ],
            [
                'named string',
                'inv_title = :title',
                [
                    'title' => 'test-1',
                ],
            ],
        ];
    }
}
