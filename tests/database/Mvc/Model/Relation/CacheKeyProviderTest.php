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

namespace Phalcon\Tests\Database\Mvc\Model\Relation;

use PDO;
use Phalcon\Contracts\Mvc\Model\Relation\CacheKeyProvider;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\CustomersCacheKeyProvider;
use Phalcon\Tests\Support\Models\InvoicesCacheKeyProvider;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function uniqid;

final class CacheKeyProviderTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelManagerCacheKeyProviderImplemented(): void
    {
        $model = new InvoicesCacheKeyProvider();

        $this->assertInstanceOf(CacheKeyProvider::class, $model);
    }

    /**
     * Models that implement CacheKeyProvider must return a stable unique key
     * so that the reusable records cache is shared across different PHP object
     * instances representing the same database row.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelManagerCacheKeyProviderUniqueKey(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $custId    = 50;
        $firstName = uniqid('cust-', true);
        $lastName  = uniqid('cust-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custId, 1, $firstName, $lastName);

        $invoiceId = 60;
        $title     = uniqid('inv-', true);

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert($invoiceId, $custId, 1, $title);

        /**
         * Load the customer and navigate to invoices, then back to the
         * customer via the reusable relation. The two customer objects must
         * share the same reusable cache entry, so getRelated() returns the
         * cached result rather than issuing a new query.
         */
        $customer = CustomersCacheKeyProvider::findFirst($custId);

        $this->assertNotNull($customer);
        $this->assertInstanceOf(CacheKeyProvider::class, $customer);

        $expectedKey = CustomersCacheKeyProvider::class . ':' . $custId;
        $this->assertSame($expectedKey, $customer->getUniqueKey());

        /** @var InvoicesCacheKeyProvider $invoice */
        $invoice = $customer->getRelated('invoices')->getFirst();

        $this->assertNotNull($invoice);
        $this->assertInstanceOf(CacheKeyProvider::class, $invoice);

        $expectedInvoiceKey = InvoicesCacheKeyProvider::class . ':' . $invoiceId;
        $this->assertSame($expectedInvoiceKey, $invoice->getUniqueKey());

        /**
         * Navigate back to the customer via the invoice's hasOne relation.
         * The reusable cache should be hit because InvoicesCacheKeyProvider returns a
         * stable key via getUniqueKey(), so the same cache entry is used for
         * every InvoicesCacheKeyProvider instance with the same inv_id.
         */
        $relatedCustomer = $invoice->getRelated('customer');

        $this->assertNotNull($relatedCustomer);
        $this->assertInstanceOf(CustomersCacheKeyProvider::class, $relatedCustomer);
        $this->assertSame($custId, (int) $relatedCustomer->cst_id);
    }
}
