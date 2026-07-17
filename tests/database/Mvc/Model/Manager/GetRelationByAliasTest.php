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

use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\RelationInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesDetail;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetRelationByAliasTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: getRelationByAlias()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelManagerGetRelationByAlias(): void
    {
        $manager = new Manager();
        $manager->setDI($this->container);

        $invoice = new Invoices();

        // No alias registered yet.
        $this->assertFalse($manager->getRelationByAlias(Invoices::class, 'detail'));

        $manager->addHasOne($invoice, 'inv_id', InvoicesDetail::class, 'inv_id', ['alias' => 'detail']);

        $relation = $manager->getRelationByAlias(Invoices::class, 'detail');

        $this->assertInstanceOf(RelationInterface::class, $relation);
        $this->assertSame('inv_id', $relation->getFields());
    }
}
