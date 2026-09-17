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

use PDOException;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

final class BeginTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @return array<string, array{0: string}>
     */
    public static function getStaleExamples(): array
    {
        return [
            'commit outside the adapter' => ['commit'],
            'reconnect'                  => ['connect'],
        ];
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: begin()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoBegin(): void
    {
        $db = $this->container->get('db');

        $this->assertFalse($db->isUnderTransaction());
        $this->assertTrue($db->begin());
        $this->assertTrue($db->isUnderTransaction());
        $this->assertSame(1, $db->getTransactionLevel());

        $db->rollback();
        $this->assertFalse($db->isUnderTransaction());
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: begin() - stale transaction level
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17546
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getStaleExamples')]
    public function testDbAdapterPdoBeginResetsStaleTransactionLevel(string $method): void
    {
        $db = $this->container->get('db');

        $this->assertTrue($db->begin());

        if ('commit' === $method) {
            $db->getInternalHandler()->commit();
        } else {
            $db->connect();
        }

        $this->assertSame(1, $db->getTransactionLevel());
        $this->assertFalse($db->isUnderTransaction());

        $this->assertTrue($db->begin());
        $this->assertSame(1, $db->getTransactionLevel());
        $this->assertTrue($db->isUnderTransaction());

        $this->assertTrue($db->rollback());
        $this->assertSame(0, $db->getTransactionLevel());
        $this->assertFalse($db->isUnderTransaction());
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: begin() - savepoint failure restores
     * the transaction level
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17546
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoBeginSavepointFailureRestoresLevel(): void
    {
        $db = $this->getMockBuilder(Sqlite::class)
            ->setConstructorArgs([['dbname' => ':memory:']])
            ->onlyMethods(['createSavepoint'])
            ->getMock();

        $db->method('createSavepoint')
            ->willThrowException(new PDOException('savepoint failed'));

        $db->setNestedTransactionsWithSavepoints(true);

        $this->assertTrue($db->begin());

        try {
            $db->begin();
            $this->fail('PDOException was not thrown');
        } catch (PDOException $exception) {
            $this->assertSame('savepoint failed', $exception->getMessage());
        }

        $this->assertSame(1, $db->getTransactionLevel());
        $this->assertTrue($db->isUnderTransaction());

        $this->assertTrue($db->rollback());
        $this->assertSame(0, $db->getTransactionLevel());
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: begin() - transaction started outside
     * the adapter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17546
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoBeginWithTransactionOutsideAdapterThrows(): void
    {
        $db  = $this->container->get('db');
        $pdo = $db->getInternalHandler();

        $pdo->beginTransaction();

        try {
            $db->begin();
            $this->fail('PDOException was not thrown');
        } catch (PDOException $exception) {
            $this->assertSame(
                'There is already an active transaction',
                $exception->getMessage()
            );
        }

        $this->assertSame(0, $db->getTransactionLevel());
        $this->assertTrue($db->isUnderTransaction());

        $pdo->rollBack();
    }
}
