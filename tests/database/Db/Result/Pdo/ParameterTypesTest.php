<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Db\Result\Pdo;

use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Db\Enum;
use Phalcon\Db\Result\PdoResult;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;
use stdClass;
use TypeError;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/847
 */
#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ParameterTypesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const SQL = 'SELECT inv_id FROM co_invoices ORDER BY inv_id';

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $migration = new InvoicesMigration(self::getPdoConnection());
        $migration->insert(1, 1, 1, 'title 1', 101);
        $migration->insert(2, 1, 1, 'title 2', 102);
    }

    /**
     * A null bindParams re-executes the statement with PDO::query() in
     * dataSeek(), as in cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/847
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDbResultPdoDataSeekNullBindParams(): void
    {
        $result = $this->getResult(null);
        $result->dataSeek(1);

        /** @var array{inv_id: int|string} $row */
        $row = $result->fetch(Enum::FETCH_ASSOC);

        $this->assertSame(2, (int) $row['inv_id']);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/847
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDbResultPdoFetchAllConstructorArgs(): void
    {
        $this->assertCount(
            2,
            $this->getResult([])->fetchAll(Enum::FETCH_CLASS, stdClass::class, null)
        );

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage('Argument #3 must be of type ?array, string given');

        $this->getResult([])->fetchAll(Enum::FETCH_CLASS, stdClass::class, 'x');
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/847
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDbResultPdoSetFetchModeColumnInt(): void
    {
        $result = $this->getResult([]);

        $this->assertTrue($result->setFetchMode(Enum::FETCH_COLUMN, 0));
        $this->assertSame(1, (int) $result->fetch());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/847
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDbResultPdoSetFetchModeNull(): void
    {
        $this->expectException(TypeError::class);
        $this->expectExceptionMessage('Argument #2 must be of type int, null given');

        $this->getResult([])->setFetchMode(Enum::FETCH_COLUMN, null);
    }

    private function getResult(mixed $bindParams): PdoResult
    {
        /** @var AdapterInterface $db */
        $db        = $this->container->get('db');
        $statement = $db->getInternalHandler()->query(self::SQL);

        return new PdoResult($db, $statement, self::SQL, $bindParams);
    }
}
