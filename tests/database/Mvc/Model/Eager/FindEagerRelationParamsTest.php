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
 * A relation may declare conditions of its own. Ignoring them under eager
 * loading returns every child rather than the filtered set - wrong data that a
 * query-count assertion alone would never catch, which is why every test here
 * compares against the lazy result.
 */
#[Group('phql')]
final class FindEagerRelationParamsTest extends AbstractDatabaseTestCase
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

        $customers->insert(1, 0, 'cst-first-1', 'cst-last-1');
        $customers->insert(2, 0, 'cst-first-2', 'cst-last-2');
        $customers->insert(3, 0, 'cst-first-3', 'cst-last-3');

        // a deliberate spread of statuses so paid / unpaid / inactive each
        // select a different subset
        $invoices->insert(1, 1, Invoices::STATUS_PAID, 'inv-title-1');
        $invoices->insert(2, 1, Invoices::STATUS_UNPAID, 'inv-title-2');
        $invoices->insert(3, 2, Invoices::STATUS_PAID, 'inv-title-3');
        $invoices->insert(4, 2, Invoices::STATUS_PAID, 'inv-title-4');
        $invoices->insert(5, 2, Invoices::STATUS_INACTIVE, 'inv-title-5');
        $invoices->insert(6, 3, Invoices::STATUS_UNPAID, 'inv-title-6');

        $this->warmMetaData([Customers::class, Invoices::class]);
    }

    /**
     * Options written on the eager spec merge the same way, so a caller can
     * narrow a relation without declaring a second one.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerNodeConditions(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $eager = $this->collect(
            'invoices',
            [
                'invoices' => [
                    'conditions' => 'inv_id > 3',
                ],
            ]
        );

        $this->assertSame([1 => [], 2 => [4, 5], 3 => [6]], $eager);
        $this->assertQueryCount(2);
    }

    /**
     * Relation params and node options both apply - the two conditions are
     * ANDed rather than one replacing the other.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerNodeConditionsMergeWithParams(): void
    {
        $eager = $this->collect(
            'paidInvoices',
            [
                'paidInvoices' => [
                    'conditions' => 'inv_id > 3',
                ],
            ]
        );

        // paid = [1, 3, 4]; inv_id > 3 narrows it to [4]
        $this->assertSame([1 => [], 2 => [4], 3 => []], $eager);
    }

    /**
     * A relation declaring an array of params - Customers::paidInvoices, with
     * 'inv_status_flag = :paid:' - must select the same rows eagerly as it
     * does lazily.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRelationParamsArray(): void
    {
        $lazy = $this->collect('paidInvoices');

        $this->attachQueryCounter($this->getService('db'));

        $eager = $this->collect('paidInvoices', ['paidInvoices']);

        $this->assertSame([1 => [1], 2 => [3, 4], 3 => []], $eager);
        $this->assertSame($lazy, $eager);
        $this->assertQueryCount(2);
    }

    /**
     * Closure params are supported too. Relation::getParams() invokes the
     * closure (Relation.zep:206) and it takes no arguments, so evaluating it
     * once per batch rather than once per record cannot change the result.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRelationParamsClosure(): void
    {
        $lazy  = $this->collect('unpaidInvoices');
        $eager = $this->collect('unpaidInvoices', ['unpaidInvoices']);

        $this->assertSame([1 => [2], 2 => [], 3 => [6]], $eager);
        $this->assertSame($lazy, $eager);
    }

    /**
     * Invoice ids per customer for the given relation.
     *
     * @param string $alias relation to read
     * @param array  $eager eager spec, or an empty array for the lazy path
     *
     * @return array<int, array<int, int>>
     */
    private function collect(string $alias, array $eager = []): array
    {
        $params = ['order' => 'cst_id'];

        if ([] !== $eager) {
            $params['eager'] = $eager;
        }

        $collected = [];
        foreach (Customers::find($params) as $customer) {
            $ids = [];
            foreach ($customer->getRelated($alias) as $invoice) {
                $ids[] = (int) $invoice->inv_id;
            }

            sort($ids);

            $collected[(int) $customer->cst_id] = $ids;
        }

        return $collected;
    }
}
