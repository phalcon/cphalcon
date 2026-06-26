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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class CustomOperatorSqlTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private $invoiceMigration;

    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();
        $this->invoiceMigration = new InvoicesMigration(self::getConnection());
    }

    /**
     * Accessor must bind tighter than '=': ("i"."inv_title" ->> 'a') = 'b'.
     */
    #[Group('pgsql')]
    public function testAccessorBindsTighterThanEquals(): void
    {
        $phql = sprintf(
            "SELECT i.inv_id FROM [%s] AS i WHERE i.inv_title ->> 'a' = 'b'",
            Invoices::class
        );

        $sql = (new Query($phql, $this->container))->getSql()['sql'];

        $this->assertMatchesRegularExpression('/->>\s*\'a\'\s*=\s*\'b\'/', $sql);
    }

    #[Group('pgsql')]
    #[Group('mysql')]
    #[Group('sqlite')]
    public function testJsonGetEmitted(): void
    {
        $phql = sprintf(
            "SELECT i.inv_id FROM [%s] AS i WHERE i.inv_title ->> 'a' = 'b'",
            Invoices::class
        );

        $result = (new Query($phql, $this->container))->getSql();

        $this->assertStringContainsString('->>', $result['sql']);
    }

    #[Group('pgsql')]
    public function testPostgresEmitsContains(): void
    {
        $phql = sprintf(
            "SELECT i.inv_id FROM [%s] AS i WHERE i.inv_title @> 'x'",
            Invoices::class
        );

        $result = (new Query($phql, $this->container))->getSql();

        $this->assertStringContainsString('"i"."inv_title" @> \'x\'', $result['sql']);
    }

    #[Group('mysql')]
    #[Group('sqlite')]
    public function testUnsupportedOperatorThrows(): void
    {
        $phql = sprintf(
            "SELECT i.inv_id FROM [%s] AS i WHERE i.inv_title @@ 'x'",
            Invoices::class
        );

        $this->expectExceptionMessage("Operator '@@' is not supported");

        (new Query($phql, $this->container))->getSql();
    }
}
