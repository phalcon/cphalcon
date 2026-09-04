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

use PDO;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\OrdersMigration;
use Phalcon\Tests\Support\Migrations\OrdersProductsFieldsMultCompMigration;
use Phalcon\Tests\Support\Migrations\ProductsMigration;
use Phalcon\Tests\Support\Models\OrdersMultiple;
use Phalcon\Tests\Support\Models\OrdersProductsFieldsMultComp;
use Phalcon\Tests\Support\Models\Products;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

/**
 * The reuse key of a through-relation is built from every field the relation
 * covers, so a compound relation neither crashes nor shares a key.
 *
 * @see https://github.com/phalcon/cphalcon/issues/17560
 */
#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ReusableCompositeRelationTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();

        $orders   = new OrdersMigration($connection);
        $products = new ProductsMigration($connection);
        $link     = new OrdersProductsFieldsMultCompMigration($connection);

        $orders->insert(10, 'order-ten', 5);
        $orders->insert(11, 'order-eleven', 5);

        $products->insert(20, 'product-twenty', 5);
        $products->insert(21, 'product-twentyone', 5);

        // order 10 -> product 20; order 11 -> product 21
        $link->insert(10, 20, 1, 5, 5);
        $link->insert(11, 21, 1, 5, 5);
    }

    /**
     * A compound through-relation marked reusable resolves instead of raising
     * a `TypeError` on the reuse key.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-04
     */
    public function testMvcModelManagerReusableCompositeRelation(): void
    {
        $manager = $this->container->get('modelsManager');
        $order   = new OrdersMultiple();

        $manager->addHasManyToMany(
            $order,
            ['ord_id', 'ord_status_flag'],
            OrdersProductsFieldsMultComp::class,
            ['oxp_ord_id', 'oxp_ord_status_flag'],
            ['oxp_prd_id', 'oxp_prd_status_flag'],
            Products::class,
            ['prd_id', 'prd_status_flag'],
            [
                'alias'    => 'reusableComposite',
                'reusable' => true,
            ]
        );

        $first = OrdersMultiple::findFirst(
            [
                'conditions' => 'ord_id = :id:',
                'bind'       => ['id' => 10],
            ]
        );

        $related = $first->getRelated('reusableComposite');

        $this->assertInstanceOf(Simple::class, $related);
        $this->assertCount(1, $related);

        $expected = 20;
        $actual   = (int) $related[0]->prd_id;
        $this->assertSame($expected, $actual);
    }

    /**
     * Two records of the same compound relation do not share a reuse key.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-04
     */
    public function testMvcModelManagerReusableCompositeRelationKeyIsPerRecord(): void
    {
        $manager = $this->container->get('modelsManager');
        $order   = new OrdersMultiple();

        $manager->addHasManyToMany(
            $order,
            ['ord_id', 'ord_status_flag'],
            OrdersProductsFieldsMultComp::class,
            ['oxp_ord_id', 'oxp_ord_status_flag'],
            ['oxp_prd_id', 'oxp_prd_status_flag'],
            Products::class,
            ['prd_id', 'prd_status_flag'],
            [
                'alias'    => 'reusablePerRecord',
                'reusable' => true,
            ]
        );

        $ten = OrdersMultiple::findFirst(
            [
                'conditions' => 'ord_id = :id:',
                'bind'       => ['id' => 10],
            ]
        );

        $eleven = OrdersMultiple::findFirst(
            [
                'conditions' => 'ord_id = :id:',
                'bind'       => ['id' => 11],
            ]
        );

        $expected = 20;
        $actual   = (int) $ten->getRelated('reusablePerRecord')[0]->prd_id;
        $this->assertSame($expected, $actual);

        $expected = 21;
        $actual   = (int) $eleven->getRelated('reusablePerRecord')[0]->prd_id;
        $this->assertSame($expected, $actual);
    }
}
