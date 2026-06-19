<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Query\Builder;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class MemoryUsageTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private InvoicesMigration $invoiceMigration;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $this->invoiceMigration = new InvoicesMigration(self::getConnection());
        $this->invoiceMigration->clear();
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    #[Group('sqlite')]
    public function testMvcModelQueryBuilderExecuteMemoryUsage(): void
    {
        gc_enable();

        $di = $this->container;

        // Warm-up to avoid one-time allocations affecting the assertion.
        $di->get('modelsManager')->createBuilder()
            ->addFrom(Invoices::class)
            ->getQuery()
            ->execute();
        gc_collect_cycles();

        $before     = memory_get_usage(true);
        $iterations = 5000;

        for ($i = 0; $i < $iterations; $i++) {
            $di->get('modelsManager')->createBuilder()
                ->addFrom(Invoices::class)
                ->getQuery()
                ->execute();

            $di->get('modelsManager')->createBuilder()
                ->addFrom(Invoices::class)
                ->getQuery()
                ->execute();

            $di->getShared('modelsManager')->__destruct();
            gc_collect_cycles();
        }

        $after         = memory_get_usage(true);
        $allowedGrowth = 1024 * 1024;

        $this->assertLessThanOrEqual(
            $before + $allowedGrowth,
            $after,
            sprintf(
                'Memory increased too much after %d iterations. before=%s after=%s',
                $iterations,
                $this->humanizeMemory($before),
                $this->humanizeMemory($after)
            )
        );
    }

    private function humanizeMemory(int $memory): string
    {
        $result = $memory / 1024 / 1024;

        return round($result, 2) . 'MB';
    }
}
