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

namespace Phalcon\Tests\Database\Mvc\Model\Binder;

use Phalcon\Mvc\Model\Binder;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class BindToHandlerTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 101);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelBinderBindToHandler(): void
    {
        $handler = new class {
            public function action(Invoices $invoice): void
            {
            }
        };

        $binder = new Binder();

        $bound = $binder->bindToHandler(
            $handler,
            [1],
            'bindCacheKey',
            'action'
        );

        $this->assertIsArray($bound);
        $this->assertInstanceOf(Invoices::class, $bound[0]);
        $this->assertEquals(1, $bound[0]->readAttribute('inv_id'));
    }
}
