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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset;

use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 * Shared fixture for the Resultset method tests.
 *
 * A single base test per method drives the three resultset shapes through a
 * data provider ('simple' / 'complex' / 'empty') instead of one stub file per
 * shape, mirroring the MetaData adapter consolidation.
 */
trait ResultsetFixtureTrait
{
    use DiTrait;

    /**
     * Seeds the deterministic fixture shared by every resultset method test:
     *  - 3 customers (customer 3 has no invoices)
     *  - 3 invoices (inv 1 -> cst 1, inv 2 & 3 -> cst 2)
     *
     * Row counts that fall out of it:
     *  - simple  Invoices::find()               -> 3
     *  - complex Customers left join Invoices   -> 4 (1 + 2 + 1 empty match)
     *  - empty   Invoices::find() with no match -> 0
     */
    protected function seedResultsetFixture(): void
    {
        $connection         = self::getConnection();
        $customersMigration = new CustomersMigration($connection);
        $invoicesMigration  = new InvoicesMigration($connection);

        $customersMigration->insert(1, 0, 'cst-first-1', 'cst-last-1');
        $customersMigration->insert(2, 0, 'cst-first-2', 'cst-last-2');
        $customersMigration->insert(3, 0, 'cst-first-3', 'cst-last-3');

        $invoicesMigration->insert(1, 1, 0, 'inv-title-1');
        $invoicesMigration->insert(2, 2, 0, 'inv-title-2');
        $invoicesMigration->insert(3, 2, 0, 'inv-title-3');
    }

    /**
     * Builds the requested resultset shape from the seeded fixture.
     */
    protected function getResultset(string $type): ResultsetInterface
    {
        if ('complex' === $type) {
            return Customers::query()
                ->columns(
                    [
                        Customers::class . '.*',
                        'invoice.*',
                    ]
                )
                ->leftJoin(
                    Invoices::class,
                    'invoice.inv_cst_id = ' . Customers::class . '.cst_id',
                    'invoice'
                )
                ->execute();
        }

        if ('empty' === $type) {
            return Invoices::find(['conditions' => 'inv_id < 0']);
        }

        return Invoices::find();
    }
}
