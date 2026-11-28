<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Query\Builder;

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class ConstructTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryBuilderConstruct(): void
    {
        $params = [
            'models'     => Invoices::class,
            'columns'    => ['inv_id', 'inv_title'],
            'conditions' => 'inv_id > 5',
            'group'      => ['inv_status_flag'],
            'having'     => 'inv_id < 100',
            'order'      => ['inv_title'],
            'limit'      => 10,
            'offset'     => 15,
        ];

        $builder = new Builder($params);

        $this->assertSame(Invoices::class, $builder->getFrom());
        $this->assertSame(['inv_id', 'inv_title'], $builder->getColumns());
        $this->assertSame('inv_id > 5', $builder->getWhere());
        $this->assertSame(['inv_status_flag'], $builder->getGroupBy());
        $this->assertSame('inv_id < 100', $builder->getHaving());
        $this->assertSame(['inv_title'], $builder->getOrderBy());
        $this->assertSame(10, $builder->getLimit());
        $this->assertSame(15, $builder->getOffset());
    }

    /**
     * Empty "bind" and "bindTypes" arrays in the parameters must not be
     * changed by the constructor.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17725
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryBuilderConstructEmptyBindKeepsSource(): void
    {
        $params = [
            'models'    => Invoices::class,
            'bind'      => [],
            'bindTypes' => [],
        ];

        ob_start();
        debug_zval_dump($params);
        $expected = ob_get_clean();

        new Builder($params);

        ob_start();
        debug_zval_dump($params);
        $actual = ob_get_clean();

        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryBuilderConstructLimitAndOffset(): void
    {
        $params = [
            'models' => Invoices::class,
            'limit'  => 10,
            'offset' => 15,
        ];

        $builderLimitAndOffset = new Builder($params);

        $params = [
            'models' => Invoices::class,
            'limit'  => [10, 15],
        ];

        $builderLimitWithOffset = new Builder($params);

        $expectedPhql = 'SELECT [' . Invoices::class . '].* FROM [' . Invoices::class . '] LIMIT :APL0: OFFSET :APL1:';

        $expected = $expectedPhql;
        $actual   = $builderLimitAndOffset->getPhql();
        $this->assertEquals($expected, $actual);

        $expected = $expectedPhql;
        $actual   = $builderLimitWithOffset->getPhql();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryBuilderConstructWithDi(): void
    {
        $params = [
            'models'     => Invoices::class,
            'columns'    => ['inv_id', 'inv_title', 'inv_status_flag'],
            'conditions' => 'a > 5',
            'group'      => ['type', 'source'],
            'having'     => 'b < 5',
            'order'      => ['name', 'created'],
            'limit'      => 10,
            'offset'     => 15,
        ];

        $builder = new Builder($params, $this->container);

        $expected = $this->container;
        $actual   = $builder->getDI();
        $this->assertEquals($expected, $actual);
    }
}
