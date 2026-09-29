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

namespace Phalcon\Tests\Benchmarks\Db;

use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Db\Enum;
use Phalcon\Tests\Benchmarks\Apps\Rest\Fixture;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class PdoBench
{
    private Sqlite $connection;

    public function setUp(): void
    {
        $this->connection = new Sqlite(['dbname' => (new Fixture())->database()]);
    }

    /**
     * 20 rows with the row fetch loop of the adapter.
     */
    public function benchFetchAll(): void
    {
        $rows = $this->connection->fetchAll(
            'SELECT id, name, type, year FROM robots ORDER BY id LIMIT 20',
            Enum::FETCH_ASSOC
        );

        if (20 !== count($rows) || 'Robot 20' !== $rows[19]['name']) {
            throw new RuntimeException('fetchAll() returned an unexpected value');
        }
    }

    /**
     * One row with a bound parameter.
     */
    public function benchFetchOneBound(): void
    {
        $row = $this->connection->fetchOne(
            'SELECT name FROM robots WHERE id = :id',
            Enum::FETCH_ASSOC,
            ['id' => 7]
        );

        if ('Robot 7' !== ($row['name'] ?? null)) {
            throw new RuntimeException('fetchOne() returned an unexpected value');
        }
    }
}
