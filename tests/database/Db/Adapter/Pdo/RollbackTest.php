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

use PDO;
use PDOException;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Db\Enum;
use Phalcon\Db\Exceptions\NoActiveTransaction;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;
use ReflectionObject;

final class RollbackTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @return array<string, array{0: int}>
     */
    public static function getStaleLevelExamples(): array
    {
        return [
            'level 1' => [1],
            'level 2' => [2],
        ];
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: rollback()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoRollback(): void
    {
        $connection = self::getPdoConnection();
        $db         = $this->container->get('db');

        new InvoicesMigration($connection);

        $this->assertTrue($db->begin());
        $this->assertTrue(
            $db->insertAsDict(
                'co_invoices',
                [
                    'inv_cst_id'      => 1,
                    'inv_status_flag' => 1,
                    'inv_title'       => 'rollback test',
                    'inv_total'       => 1.0,
                ]
            )
        );
        $this->assertTrue($db->rollback());
        $this->assertFalse($db->isUnderTransaction());

        $row = $db->fetchOne(
            'SELECT inv_title FROM co_invoices WHERE inv_title = ?',
            Enum::FETCH_ASSOC,
            ['rollback test']
        );
        $this->assertEmpty($row);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: rollback() - failure reduces the
     * transaction level
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17546
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoRollbackFailureReducesLevel(): void
    {
        $pdo = $this->getMockBuilder(PDO::class)
            ->disableOriginalConstructor()
            ->onlyMethods(['inTransaction', 'rollBack'])
            ->getMock();

        $pdo->method('inTransaction')->willReturn(true);
        $pdo->method('rollBack')
            ->willThrowException(new PDOException('rollback failed'));

        $db  = new Sqlite(['dbname' => ':memory:']);
        $ref = new ReflectionObject($db);
        $ref->getProperty('pdo')->setValue($db, $pdo);
        $ref->getProperty('transactionLevel')->setValue($db, 1);

        try {
            $db->rollback();
            $this->fail('PDOException was not thrown');
        } catch (PDOException $exception) {
            $this->assertSame('rollback failed', $exception->getMessage());
        }

        $this->assertSame(0, $db->getTransactionLevel());
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: rollback() - savepoint failure reduces
     * the transaction level
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17546
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoRollbackSavepointFailureReducesLevel(): void
    {
        $connection = self::getPdoConnection();
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
                    'inv_title'       => 'rollback savepoint test',
                    'inv_total'       => 1.0,
                ]
            )
        );
        $this->assertTrue($db->begin());

        // Release the savepoint but do not change the transaction level
        $db->releaseSavepoint($db->getNestedTransactionSavepointName());

        try {
            $db->rollback();
            $this->fail('PDOException was not thrown');
        } catch (PDOException $exception) {
            $this->assertNotEmpty($exception->getMessage());
        }

        $this->assertSame(1, $db->getTransactionLevel());
        $this->assertTrue($db->isUnderTransaction());

        $this->assertTrue($db->rollback());
        $this->assertSame(0, $db->getTransactionLevel());
        $this->assertFalse($db->isUnderTransaction());

        $row = $db->fetchOne(
            'SELECT inv_title FROM co_invoices WHERE inv_title = ?',
            Enum::FETCH_ASSOC,
            ['rollback savepoint test']
        );
        $this->assertEmpty($row);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: rollback() - stale transaction level
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17546
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getStaleLevelExamples')]
    public function testDbAdapterPdoRollbackStaleTransactionLevelThrows(int $level): void
    {
        $db = $this->container->get('db');

        for ($counter = 0; $counter < $level; $counter++) {
            $db->begin();
        }

        $db->getInternalHandler()->commit();

        $this->assertSame($level, $db->getTransactionLevel());

        try {
            $db->rollback();
            $this->fail('NoActiveTransaction was not thrown');
        } catch (NoActiveTransaction $exception) {
            $this->assertSame(
                'There is no active transaction',
                $exception->getMessage()
            );
        }

        $this->assertSame(0, $db->getTransactionLevel());
    }
}
