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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Query\Exceptions\InvalidResultsetRowClass;
use Phalcon\Mvc\Model\Query\Exceptions\ResultsetRowClassNotFound;
use Phalcon\Mvc\Model\QueryInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\CustomResultsetRow;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;
use stdClass;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class SetResultsetRowClassTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Mvc\Model\Query :: setResultsetRowClass() - fluent setter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-13
     * @issue  https://github.com/phalcon/cphalcon/issues/17337
     */
    public function testMvcModelQuerySetResultsetRowClass(): void
    {
        $query = new Query();

        $this->assertInstanceOf(
            QueryInterface::class,
            $query->setResultsetRowClass(CustomResultsetRow::class)
        );

        $this->assertSame(
            CustomResultsetRow::class,
            $query->getResultsetRowClass()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: setResultsetRowClass() - unknown class
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-13
     * @issue  https://github.com/phalcon/cphalcon/issues/17337
     */
    public function testMvcModelQuerySetResultsetRowClassNotFound(): void
    {
        $this->expectException(ResultsetRowClassNotFound::class);
        $this->expectExceptionMessage(
            "Resultset row class 'Not\\Existing\\Row' not found"
        );

        (new Query())->setResultsetRowClass('Not\Existing\Row');
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: setResultsetRowClass() - not a Row
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-13
     * @issue  https://github.com/phalcon/cphalcon/issues/17337
     */
    public function testMvcModelQuerySetResultsetRowClassNotRowSubclass(): void
    {
        $this->expectException(InvalidResultsetRowClass::class);

        (new Query())->setResultsetRowClass(stdClass::class);
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: setResultsetRowClass() - simple resultset
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-13
     * @issue  https://github.com/phalcon/cphalcon/issues/17337
     */
    public function testMvcModelQuerySetResultsetRowClassSimple(): void
    {
        (new InvoicesMigration(self::getPdoConnection()))
            ->insert(1, 1, 0, 'Title 1');

        $manager = $this->container->get('modelsManager');

        $query = $manager->createQuery(
            'SELECT inv_id, inv_title FROM ' . Invoices::class
        );
        $query->setResultsetRowClass(CustomResultsetRow::class);

        $result = $query->execute();
        $row    = $result->getFirst();

        $this->assertInstanceOf(CustomResultsetRow::class, $row);
        $this->assertSame('TITLE 1', $row->getUpperTitle());
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: setResultsetRowClass() - complex resultset
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-13
     * @issue  https://github.com/phalcon/cphalcon/issues/17337
     */
    public function testMvcModelQuerySetResultsetRowClassComplex(): void
    {
        (new CustomersMigration(self::getPdoConnection()))
            ->insert(1, 1, 'first', 'last');
        (new InvoicesMigration(self::getPdoConnection()))
            ->insert(1, 1, 1, 'Title 1');

        $manager = $this->container->get('modelsManager');

        $phql = 'SELECT ' . Customers::class . '.*, ' . Invoices::class . '.* '
            . 'FROM ' . Customers::class . ' '
            . 'JOIN ' . Invoices::class . ' '
            . 'ON ' . Invoices::class . '.inv_cst_id = ' . Customers::class . '.cst_id';

        $query = $manager->createQuery($phql);
        $query->setResultsetRowClass(CustomResultsetRow::class);

        $result = $query->execute();
        $row    = $result->getFirst();

        $this->assertInstanceOf(CustomResultsetRow::class, $row);
        $this->assertInstanceOf(
            Customers::class,
            $row->readAttribute(Customers::class)
        );
        $this->assertInstanceOf(
            Invoices::class,
            $row->readAttribute(Invoices::class)
        );
    }
}
