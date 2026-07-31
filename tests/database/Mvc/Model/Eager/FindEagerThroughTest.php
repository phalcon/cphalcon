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
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\OrdersMigration;
use Phalcon\Tests\Support\Migrations\OrdersProductsFieldsOneMigration;
use Phalcon\Tests\Support\Migrations\ProductsMigration;
use Phalcon\Tests\Support\Models\OrdersMultiple;
use Phalcon\Tests\Support\Models\OrdersProductsFieldsOne;
use Phalcon\Tests\Support\Models\Products;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Support\Traits\QueryCounterTrait;
use PHPUnit\Framework\Attributes\Group;

/**
 * Through-relations are loaded in two steps rather than with a join: one query
 * for the intermediate pairs, one for the referenced rows. A join would
 * multiply parent rows and would need a synthetic key column in the select
 * list to attribute them back.
 *
 * The seeding idiom mirrors RelationsTest.php:187-231.
 */
#[Group('phql')]
final class FindEagerThroughTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use QueryCounterTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();

        $orders   = new OrdersMigration($connection);
        $products = new ProductsMigration($connection);
        $link     = new OrdersProductsFieldsOneMigration($connection);

        $orders->insert(10, 'order-ten', 5);
        $orders->insert(11, 'order-eleven', 5);
        $orders->insert(12, 'order-twelve', 5);

        $products->insert(20, 'product-twenty', 10);
        $products->insert(21, 'product-twentyone', 10);

        // order 10 -> products 20 and 21; order 11 -> product 20;
        // order 12 -> nothing
        $link->insert(1, 10, 20, 1);
        $link->insert(2, 10, 21, 1);
        $link->insert(3, 11, 20, 1);

        // the intermediate model is queried too, so its MetaData has to be
        // warmed as well or its DESCRIBE lands inside the recorded window
        $this->warmMetaData(
            [
                OrdersMultiple::class,
                OrdersProductsFieldsOne::class,
                Products::class,
            ]
        );
    }

    /**
     * Three queries - parents, intermediate pairs, referenced rows -
     * regardless of parent count, returning the same rows as the lazy path.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerHasManyToMany(): void
    {
        $lazy = $this->collect();

        $this->attachQueryCounter($this->getService('db'));

        $eager = $this->collect(['productsFieldsOne']);

        $this->assertSame([10 => [20, 21], 11 => [20], 12 => []], $eager);
        $this->assertSame($lazy, $eager);
        $this->assertQueryCount(3);
    }

    /**
     * A parent with no intermediate rows receives an empty resultset rather
     * than null, so callers can iterate unconditionally.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerHasManyToManyEmptyParent(): void
    {
        $orders = OrdersMultiple::find(
            [
                'conditions' => 'ord_id = 12',
                'eager'      => ['productsFieldsOne'],
            ]
        );

        $order   = $orders->getFirst();
        $related = $order->getRelated('productsFieldsOne');

        $this->assertInstanceOf(Simple::class, $related);
        $this->assertSame(0, $related->count());
    }

    /**
     * Product ids per order.
     *
     * @param array $eager eager spec, or an empty array for the lazy path
     *
     * @return array<int, array<int, int>>
     */
    private function collect(array $eager = []): array
    {
        $params = ['order' => 'ord_id'];

        if ([] !== $eager) {
            $params['eager'] = $eager;
        }

        $collected = [];
        foreach (OrdersMultiple::find($params) as $order) {
            $ids = [];
            foreach ($order->getRelated('productsFieldsOne') as $product) {
                $ids[] = (int) $product->prd_id;
            }

            sort($ids);

            $collected[(int) $order->ord_id] = $ids;
        }

        return $collected;
    }
}
