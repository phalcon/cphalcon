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

namespace Phalcon\Tests\Database\Mvc\Model\Eager;

use PDO;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Support\Traits\QueryCounterTrait;
use PHPUnit\Framework\Attributes\Group;

/**
 * Composite keys use OR-grouped equality rather than a row-value IN predicate,
 * because (a, b) IN ((1, 2)) is not supported uniformly across MySQL,
 * PostgreSQL and SQLite.
 *
 * Customers.php:128 declares 'invoicesMultipleFields' over
 * ['cst_id', 'cst_status_flag'] -> ['inv_cst_id', 'inv_status_flag'], so the
 * status has to match as well as the customer.
 */
#[Group('phql')]
final class FindEagerCompositeKeysTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use QueryCounterTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();

        $customers = new CustomersMigration($connection);
        $invoices  = new InvoicesMigration($connection);

        $customers->insert(1, Invoices::STATUS_PAID, 'cst-first-1', 'cst-last-1');
        $customers->insert(2, Invoices::STATUS_UNPAID, 'cst-first-2', 'cst-last-2');
        $customers->insert(3, Invoices::STATUS_PAID, 'cst-first-3', 'cst-last-3');

        // only invoices matching BOTH the customer and the status belong to
        // the composite relation
        $invoices->insert(1, 1, Invoices::STATUS_PAID, 'inv-title-1');
        $invoices->insert(2, 1, Invoices::STATUS_UNPAID, 'inv-title-2');
        $invoices->insert(3, 2, Invoices::STATUS_UNPAID, 'inv-title-3');
        $invoices->insert(4, 2, Invoices::STATUS_PAID, 'inv-title-4');
        $invoices->insert(5, 3, Invoices::STATUS_UNPAID, 'inv-title-5');

        $this->warmMetaData([Customers::class, Invoices::class]);
    }

    /**
     * A two-column relation costs the same two queries and selects the same
     * rows as the lazy path. Matching on only the first column would pull in
     * invoices 2, 3 and 5.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerCompositeKeys(): void
    {
        $lazy = $this->collect();

        $this->attachQueryCounter($this->getService('db'));

        $eager = $this->collect(['invoicesMultipleFields']);

        // cst 1 is paid -> inv 1; cst 2 is unpaid -> inv 3; cst 3 is paid but
        // its only invoice is unpaid -> none
        $this->assertSame([1 => [1], 2 => [3], 3 => []], $eager);
        $this->assertSame($lazy, $eager);
        $this->assertQueryCount(2);
    }

    /**
     * Invoice ids per customer for the composite relation.
     *
     * @param array $eager eager spec, or an empty array for the lazy path
     *
     * @return array<int, array<int, int>>
     */
    private function collect(array $eager = []): array
    {
        $params = ['order' => 'cst_id'];

        if ([] !== $eager) {
            $params['eager'] = $eager;
        }

        $collected = [];
        foreach (Customers::find($params) as $customer) {
            $ids = [];
            foreach ($customer->getRelated('invoicesMultipleFields') as $invoice) {
                $ids[] = (int) $invoice->inv_id;
            }

            sort($ids);

            $collected[(int) $customer->cst_id] = $ids;
        }

        return $collected;
    }
}
