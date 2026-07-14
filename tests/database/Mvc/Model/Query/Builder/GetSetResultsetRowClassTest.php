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

namespace Phalcon\Tests\Database\Mvc\Model\Query\Builder;

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Query\BuilderInterface;
use Phalcon\Mvc\Model\Query\Exceptions\ResultsetRowClassNotFound;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\CustomResultsetRow;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetSetResultsetRowClassTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: setResultsetRowClass() - fluent
     * setter and default value
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-14
     * @issue  https://github.com/phalcon/cphalcon/pull/17340
     */
    public function testMvcModelQueryBuilderSetResultsetRowClass(): void
    {
        $builder = new Builder();

        $this->assertSame('', $builder->getResultsetRowClass());

        $this->assertInstanceOf(
            BuilderInterface::class,
            $builder->setResultsetRowClass(CustomResultsetRow::class)
        );

        $this->assertSame(
            CustomResultsetRow::class,
            $builder->getResultsetRowClass()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getQuery() - forwards the custom
     * resultset row class to the produced query
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-14
     * @issue  https://github.com/phalcon/cphalcon/pull/17340
     */
    public function testMvcModelQueryBuilderResultsetRowClassSimple(): void
    {
        (new InvoicesMigration(self::getPdoConnection()))
            ->insert(1, 1, 0, 'Title 1');

        $manager = $this->getService('modelsManager');

        $builder = $manager
            ->createBuilder()
            ->columns('inv_id, inv_title')
            ->from(Invoices::class)
        ;
        $builder->setResultsetRowClass(CustomResultsetRow::class);

        $result = $builder->getQuery()->execute();
        $row    = $result->getFirst();

        $this->assertInstanceOf(CustomResultsetRow::class, $row);
        $this->assertSame('TITLE 1', $row->getUpperTitle());
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getQuery() - validation of the
     * custom resultset row class is deferred to the produced query
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-14
     * @issue  https://github.com/phalcon/cphalcon/pull/17340
     */
    public function testMvcModelQueryBuilderResultsetRowClassNotFound(): void
    {
        $manager = $this->getService('modelsManager');

        $builder = $manager
            ->createBuilder()
            ->columns('inv_id, inv_title')
            ->from(Invoices::class)
        ;

        // The builder stores the value without validation ...
        $builder->setResultsetRowClass('Not\Existing\Row');

        // ... the underlying query validates it when it is built.
        $this->expectException(ResultsetRowClassNotFound::class);
        $this->expectExceptionMessage(
            "Resultset row class 'Not\\Existing\\Row' not found"
        );

        $builder->getQuery();
    }
}
