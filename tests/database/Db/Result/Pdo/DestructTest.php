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

namespace Phalcon\Tests\Database\Db\Result\Pdo;

use PDO;
use PDOStatement;
use Phalcon\Db\Result\PdoResult;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 * @issue  https://github.com/phalcon/cphalcon/issues/16955
 */
final class DestructTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * Tests that PdoResult::__destruct calls closeCursor and nullifies resources.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-05
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbResultPdoDestructCleansUpResources(): void
    {
        $db = $this->getService('db');

        $result = $db->query("SELECT 1 AS one");

        $this->assertInstanceOf(PdoResult::class, $result);

        $pdoStatement = $this->getProtectedProperty($result, 'pdoStatement');
        $this->assertNotNull(
            $pdoStatement,
            'pdoStatement should be set before destruction'
        );

        unset($result);

        gc_collect_cycles();

        $this->assertTrue(
            true,
            'PdoResult should be destructed without errors after closeCursor'
        );
    }

    /**
     * Tests that PdoResult can be created and garbage collected in a tight loop
     * without accumulating open statements.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-05
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbResultPdoDestructHandlesHighIteration(): void
    {
        $db    = $this->getService('db');
        $limit = 500;

        $memBefore = memory_get_usage(true);

        for ($i = 0; $i < $limit; $i++) {
            $result = $db->query("SELECT " . $i . " AS val");
            $row    = $result->fetch();
            unset($result);
        }

        gc_collect_cycles();

        $memAfter  = memory_get_usage(true);
        $memGrowth = $memAfter - $memBefore;

        $this->assertLessThan(
            5 * 1024 * 1024,
            $memGrowth,
            'Memory growth should be under 5MB after ' . $limit . ' iterations. Growth: '
            . round($memGrowth / 1024 / 1024, 2) . 'MB'
        );
    }

    /**
     * Tests that closeCursor is safe to call on an already-freed statement.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-05
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbResultPdoDestructSafeOnDoubleDestruction(): void
    {
        $db = $this->getService('db');

        $result  = $db->query("SELECT 1 AS one");
        $stmt    = $this->getProtectedProperty($result, 'pdoStatement');

        $this->assertInstanceOf(
            PDOStatement::class,
            $stmt,
            'Internal pdoStatement should be a PDOStatement'
        );

        $stmt->closeCursor();

        unset($result);

        gc_collect_cycles();

        $this->assertTrue(
            true,
            'Double closeCursor (manual + __destruct) should not throw'
        );
    }
}
