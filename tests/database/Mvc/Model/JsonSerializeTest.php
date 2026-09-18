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
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Mvc\Model\Row;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function json_decode;
use function json_encode;
use function uniqid;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class JsonSerializeTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelJsonSerialize(): void
    {
        $invoice = new Invoices();
        $invoice->assign(
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 2,
                'inv_status_flag' => 1,
                'inv_title'       => 'json title',
                'inv_total'       => 100.00,
            ]
        );

        $serialized = $invoice->jsonSerialize();

        $this->assertIsArray($serialized);
        $this->assertEquals(1, $serialized['inv_id']);
        $this->assertEquals('json title', $serialized['inv_title']);

        // json_encode() uses jsonSerialize() under the hood
        $decoded = json_decode(json_encode($invoice), true);

        $this->assertEquals(1, $decoded['inv_id']);
        $this->assertEquals('json title', $decoded['inv_title']);
    }

    /**
     * A resultset encodes to the same records that toArray() returns.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-08
     */
    public function testMvcModelJsonSerializeResultset(): void
    {
        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 0, uniqid('inv-'));
        $migration->insert(2, 1, 1, uniqid('inv-'));

        $invoices = Invoices::find();

        $this->assertInstanceOf(Simple::class, $invoices);

        $decoded = json_decode(json_encode($invoices), true);

        $this->assertIsArray($decoded);
        $this->assertCount(2, $decoded);
        $this->assertEquals($invoices->toArray(), $decoded);
    }

    /**
     * A Row that a PHQL query produces encodes to the same array that
     * toArray() returns.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-08
     */
    #[Group('phql')]
    public function testMvcModelJsonSerializeRow(): void
    {
        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 0, uniqid('inv-'));

        $result = $this->getService('modelsManager')
                       ->executeQuery(
                           'SELECT inv_id FROM ' . Invoices::class . ' LIMIT 1'
                       )
        ;

        $this->assertInstanceOf(Simple::class, $result);

        foreach ($result as $row) {
            $this->assertInstanceOf(Row::class, $row);

            $decoded = json_decode(json_encode($row), true);

            $this->assertIsArray($decoded);
            $this->assertEquals($row->toArray(), $decoded);
            $this->assertEquals(1, $decoded['inv_id']);
        }
    }
}
