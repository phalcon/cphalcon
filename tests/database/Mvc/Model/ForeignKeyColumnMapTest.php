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

use Phalcon\Mvc\Model\Relation;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

/**
 * A composite virtual foreign key names every field it covers, and a model
 * without a column map does not look for a case-insensitive variant.
 *
 * @see https://github.com/phalcon/cphalcon/issues/17558
 */
#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ForeignKeyColumnMapTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private bool $caseInsensitive = false;
    private bool $columnRenaming  = true;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        new CustomersMigration(self::getPdoConnection());
        new InvoicesMigration(self::getPdoConnection());

        $this->columnRenaming  = (bool) Settings::get('orm.column_renaming');
        $this->caseInsensitive = (bool) Settings::get('orm.case_insensitive_column_map');
    }

    public function tearDown(): void
    {
        Settings::set('orm.column_renaming', $this->columnRenaming);
        Settings::set('orm.case_insensitive_column_map', $this->caseInsensitive);

        parent::tearDown();
    }

    /**
     * With column renaming off there is no column map, so the
     * case-insensitive lookup is skipped instead of crashing.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-03
     */
    public function testMvcModelAssignWithoutColumnMap(): void
    {
        Settings::set('orm.column_renaming', false);
        Settings::set('orm.case_insensitive_column_map', true);

        $invoice = new Invoices();
        $invoice->assign(
            [
                'inv_title' => 'no column map',
                'inv_total' => 2.0,
            ]
        );

        $expected = 'no column map';
        $actual   = $invoice->inv_title;
        $this->assertSame($expected, $actual);
    }

    /**
     * A composite foreign key that is not satisfied reports every field it
     * covers instead of raising a `TypeError`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-03
     */
    public function testMvcModelCompositeForeignKeyMessage(): void
    {
        $manager = $this->container->get('modelsManager');
        $invoice = new Invoices();

        $manager->addBelongsTo(
            $invoice,
            ['inv_cst_id', 'inv_status_flag'],
            Customers::class,
            ['cst_id', 'cst_status_flag'],
            [
                'alias'      => 'compositeProbe',
                'foreignKey' => [
                    'action' => Relation::ACTION_RESTRICT,
                ],
            ]
        );

        $invoice->inv_cst_id      = 9999;
        $invoice->inv_status_flag = 8888;
        $invoice->inv_title       = 'composite probe';
        $invoice->inv_total       = 1.0;
        $invoice->inv_created_at  = date('Y-m-d H:i:s');

        $this->assertFalse($invoice->save());

        $messages = $invoice->getMessages();
        $this->assertNotEmpty($messages);

        $expected = 'inv_cst_id, inv_status_flag';
        $actual   = $messages[0]->getField();
        $this->assertSame($expected, $actual);

        $expected = 'ConstraintViolation';
        $actual   = $messages[0]->getType();
        $this->assertSame($expected, $actual);
    }
}
