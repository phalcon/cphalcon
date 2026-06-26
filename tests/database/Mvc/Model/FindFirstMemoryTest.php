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

namespace Phalcon\Tests\Database\Mvc\Model;

use PDO;
use Phalcon\Mvc\Model\Query;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

use function memory_get_usage;
use function gc_collect_cycles;

/**
 * Tests that findFirst in a high-iteration loop does not cause
 * unbounded memory growth or segmentation faults.
 *
 * @issue  https://github.com/phalcon/cphalcon/issues/16955
 *
 * @group phql
 */
final class FindFirstMemoryTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);

        for ($i = 1; $i <= 200; $i++) {
            $migration->insert($i, null, 0, 'title-' . $i);
        }

        Query::clean();
    }

    public function tearDown(): void
    {
        Query::clean();
        $this->tearDownDatabase();
    }

    /**
     * Tests findFirst with numeric PK in a loop does not leak memory.
     *
     * Since findFirst($id) uses bound parameter (:APK0:), the PHQL is
     * identical per call — only 1 cache entry per model. This verifies
     * that the ORM properly releases resources between iterations.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-05
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelFindFirstHighIterationWithNumericPk(): void
    {
        $iterations = 1000;
        $memBefore  = memory_get_usage(true);

        for ($i = 1; $i <= $iterations; $i++) {
            $id    = (($i - 1) % 200) + 1;
            $invoice = Invoices::findFirst($id);
            unset($invoice);
        }

        gc_collect_cycles();

        $memAfter  = memory_get_usage(true);
        $memGrowth = $memAfter - $memBefore;

        $this->assertLessThan(
            10 * 1024 * 1024,
            $memGrowth,
            'Memory growth should be under 10MB after ' . $iterations
            . ' findFirst iterations. Growth: '
            . round($memGrowth / 1024 / 1024, 2) . 'MB'
        );
    }

    /**
     * Tests findFirst with unique conditions per iteration triggers cache eviction.
     *
     * Each iteration produces a unique PHQL string, which would previously
     * cause unbounded cache growth. The cache eviction mechanism should keep
     * memory bounded.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-05
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelFindFirstHighIterationWithUniqueConditions(): void
    {
        $iterations = 500;
        $memBefore  = memory_get_usage(true);

        for ($i = 1; $i <= $iterations; $i++) {
            $id = (($i - 1) % 200) + 1;

            Invoices::findFirst(
                [
                    'conditions' => 'inv_id = ' . $id . ' AND inv_status_flag = 0',
                ]
            );
        }

        gc_collect_cycles();

        $memAfter  = memory_get_usage(true);
        $memGrowth = $memAfter - $memBefore;

        $this->assertLessThan(
            10 * 1024 * 1024,
            $memGrowth,
            'Memory growth should be under 10MB after ' . $iterations
            . ' unique-condition findFirst iterations. Growth: '
            . round($memGrowth / 1024 / 1024, 2) . 'MB'
        );
    }
}
