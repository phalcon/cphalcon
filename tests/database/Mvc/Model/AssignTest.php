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

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Transaction\Manager;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Migrations\SourcesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesMap;
use Phalcon\Tests\Support\Models\InvoicesWithSetters;
use Phalcon\Tests\Support\Models\Sources;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function uniqid;

final class AssignTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection));
    }

    public function tearDown(): void
    {
        Settings::reset();

        $this->tearDownDatabase();
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelAssign(): void
    {
        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');
        $data  = [
            'inv_id'          => 1,
            'inv_cst_id'      => 2,
            'inv_status_flag' => 3,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new Invoices();
        $invoice->assign($data);

        $this->assertEquals(
            1,
            $invoice->readAttribute('inv_id')
        );
        $this->assertEquals(
            2,
            $invoice->readAttribute('inv_cst_id')
        );
        $this->assertEquals(
            3,
            $invoice->readAttribute('inv_status_flag')
        );
        $this->assertEquals(
            $title,
            $invoice->readAttribute('inv_title')
        );
        $this->assertEquals(
            100.12,
            $invoice->readAttribute('inv_total')
        );
        $this->assertEquals(
            $date,
            $invoice->readAttribute('inv_created_at')
        );

        $this->assertEquals(
            $data,
            $invoice->toArray()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelAssignAutoPrimary(): void
    {
        $data = [
            'inv_cst_id'      => 2,
            'inv_status_flag' => 3,
            'inv_title'       => uniqid('inv-'),
            'inv_total'       => 100.12,
            'inv_created_at'  => date('Y-m-d H:i:s'),
        ];

        $invoice = new Invoices();
        $invoice->assign($data, array_keys($data));

        $this->assertArrayHasKey('inv_id', $invoice->toArray());
        $this->assertEmpty($invoice->toArray()['inv_id']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelAssignIncomplete(): void
    {
        $title   = uniqid('inv-');
        $invoice = new Invoices();
        $invoice->assign(
            [
                'inv_id'    => 1,
                'inv_title' => $title,
            ]
        );

        $this->assertEquals(
            [
                'inv_id'          => 1,
                'inv_cst_id'      => null,
                'inv_status_flag' => null,
                'inv_title'       => $title,
                'inv_total'       => null,
                'inv_created_at'  => null,
            ],
            $invoice->toArray()
        );
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16617
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-02
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelAssignReservedSetterColumn(): void
    {
        $connection = self::getPdoConnection();
        (new SourcesMigration($connection));

        $value  = uniqid('src-');
        $record = new Sources();
        $record->assign(
            [
                'id'       => 1,
                'username' => 'darth',
                'source'   => $value,
            ]
        );

        $this->assertSame(1, $record->readAttribute('id'));
        $this->assertSame('darth', $record->readAttribute('username'));
        $this->assertSame($value, $record->readAttribute('source'));
        $this->assertSame('co_sources', $record->getSource());
    }

    /**
     * assign() calls a matching setter by default. `disableAssignSetters`
     * makes it write the property directly instead.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12645
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-23
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelAssignSettersDisabled(): void
    {
        $invoice = new InvoicesWithSetters();
        $invoice->assign(['inv_title' => 'test']);

        $this->assertSame('SET:test', $invoice->inv_title);

        Model::setup(['disableAssignSetters' => true]);

        $invoice = new InvoicesWithSetters();
        $invoice->assign(['inv_title' => 'test']);

        $this->assertSame('test', $invoice->inv_title);
    }

    /**
     * The white list keeps every field outside it unassigned, and the data
     * column map renames the incoming keys before the white list applies.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-08
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelAssignWhiteList(): void
    {
        $invoice = new Invoices();
        $invoice->assign(
            [
                'inv_cst_id' => 2,
                'inv_title'  => 'white list',
            ],
            ['inv_title']
        );

        $this->assertSame('white list', $invoice->inv_title);
        $this->assertNull($invoice->inv_cst_id);

        /**
         * A key that is not an attribute of the model never reaches it.
         */
        $invoice = new Invoices();
        $invoice->assign(
            [
                'field1' => 'one',
                'field2' => 'two',
            ]
        );

        $this->assertObjectNotHasProperty('field1', $invoice);
        $this->assertObjectNotHasProperty('field2', $invoice);

        /**
         * The third argument renames the keys first, so the white list holds
         * the model attribute name and not the incoming one.
         */
        $invoice = new Invoices();
        $invoice->assign(
            [
                'cstIdFromClient' => 2,
                'titleFromClient' => 'renamed',
            ],
            ['inv_title'],
            [
                'cstIdFromClient' => 'inv_cst_id',
                'titleFromClient' => 'inv_title',
            ]
        );

        $this->assertSame('renamed', $invoice->inv_title);
        $this->assertNull($invoice->inv_cst_id);
    }

    /**
     * With a column map in place, assign() and its white list both work on the
     * mapped attribute names.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-08
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelAssignWithColumnMap(): void
    {
        $invoice = new InvoicesMap();
        $invoice->assign(
            [
                'title' => 'mapped title',
                'total' => 100.12,
            ]
        );

        $this->assertSame('mapped title', $invoice->title);
        $this->assertSame(100.12, $invoice->total);

        $invoice = new InvoicesMap();
        $invoice->assign(
            [
                'title' => 'mapped title',
                'total' => 100.12,
            ],
            ['title']
        );

        $this->assertSame('mapped title', $invoice->title);
        $this->assertNull($invoice->total);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/15739
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelAssignWithTransaction(): void
    {
        $title       = uniqid('inv-');
        $manager     = new Manager();
        $transaction = $manager->get();
        $invoice     = new Invoices();
        $invoice->setTransaction($transaction);
        $invoice->assign(
            [
                'inv_id'    => 1,
                'inv_title' => $title,
            ]
        );

        $result = $invoice->create();
        $this->assertTrue($result);

        $result = $transaction->commit();
        $this->assertTrue($result);

        $result = $invoice->delete();
        $this->assertTrue($result);
    }
}
