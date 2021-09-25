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

namespace Phalcon\Tests\Fixtures\Traits;

use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use PHPUnit\Framework\Assert;

use function uniqid;

trait RecordsTrait
{
    /**
     * @param int $number
     *
     * @return false|float
     */
    private function getFibonacci(int $number)
    {
        return round((((sqrt(5) + 1) / 2) ** $number) / sqrt(5));
    }

    /**
     * @param InvoicesMigration $migration
     * @param int               $count
     * @param string            $invId
     * @param int               $custId
     * @param string            $prefix
     * @param int               $pad
     */
    private function insertDataInvoices(
        InvoicesMigration $migration,
        int $count,
        string $invId = null,
        int $custId,
        string $prefix,
        int $pad = 0
    ) {
        $title = uniqid($prefix . '-', true);
        for ($counter = 1; $counter <= $count; $counter++) {
            $result = $migration->insert(
                $invId,
                $custId,
                1,
                $title,
                $this->getFibonacci($pad + $counter)
            );

            if (!$result) {
                $table  = $migration->getTable();
                $driver = $migration->getDriverName();
                Assert::fail(
                    sprintf("Failed to insert row #%d into table '%s' using '%s' driver", $counter, $table, $driver)
                );
            }
        }
    }
}
