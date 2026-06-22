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

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ExistsHasOneTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelManagerExistsHasOne(): void
    {
        $manager   = $this->container->get('modelsManager');
        $invoice   = new Invoices();
        $referenced = 'Phalcon\Tests\Support\Models\InvoicesDetail';

        $this->assertFalse(
            $manager->existsHasOne(Invoices::class, $referenced)
        );

        $manager->addHasOne(
            $invoice,
            'inv_id',
            $referenced,
            'inv_id',
            ['alias' => 'detail']
        );

        $this->assertTrue(
            $manager->existsHasOne(Invoices::class, $referenced)
        );
    }
}
