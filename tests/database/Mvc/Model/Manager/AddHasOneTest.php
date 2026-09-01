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

use Phalcon\Mvc\Model\RelationInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class AddHasOneTest extends AbstractDatabaseTestCase
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
    public function testMvcModelManagerAddHasOne(): void
    {
        $manager = $this->container->get('modelsManager');
        $invoice = new Invoices();

        $relation = $manager->addHasOne(
            $invoice,
            'inv_id',
            'Phalcon\Tests\Support\Models\InvoicesDetail',
            'inv_id',
            ['alias' => 'detail']
        );

        $this->assertInstanceOf(RelationInterface::class, $relation);
        $this->assertSame('inv_id', $relation->getFields());
        $this->assertSame('inv_id', $relation->getReferencedFields());

        $found = $manager->getRelationByAlias(Invoices::class, 'detail');

        $this->assertInstanceOf(RelationInterface::class, $found);
    }
}
