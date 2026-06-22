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

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function json_decode;
use function json_encode;

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

        $connection = self::getConnection();
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
}
