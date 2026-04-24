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

use PDO;
use Phalcon\Mvc\Model;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesKeepSnapshots;
use Phalcon\Tests\Support\Models\InvoicesOnConstruct;
use Phalcon\Tests\Support\Models\InvoicesTypedProperties;
use Phalcon\Tests\Support\Traits\DiTrait;

use function date;
use function serialize;
use function uniqid;
use function unserialize;

final class SerializeTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSerialize(): void
    {
        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');
        $data  = [
            'inv_cst_id'      => 2,
            'inv_status_flag' => 3,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new Invoices();
        $invoice->assign($data);

        $result = $invoice->save();
        $this->assertNotFalse($result);

        $serialized = serialize($invoice);
        $newObject  = unserialize($serialized);

        $this->assertEquals(2, $newObject->inv_cst_id);
        $this->assertEquals(3, $newObject->inv_status_flag);
        $this->assertEquals($title, $newObject->inv_title);
        $this->assertEquals(100.12, $newObject->inv_total);
        $this->assertEquals($date, $newObject->inv_created_at);
    }

    /**
     * Tests that toArray() with a getter does not throw when a typed
     * non-nullable property is uninitialized (e.g. because cloneResultMap
     * skipped its assignment when the DB returned NULL for a NOT NULL column).
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/15711
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-22
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelToArrayWithUninitializedTypedPropertyAndGetter(): void
    {
        $base     = new InvoicesTypedProperties();
        $metadata = $base->getModelsMetaData();
        $colMap   = $metadata->getColumnMap($base);

        /**
         * Simulate a LEFT JOIN result where the primary key (NOT NULL in DB)
         * comes back as NULL. cloneResultMap() will skip the assignment for
         * inv_id, leaving the typed public int $inv_id uninitialized.
         */
        /** @var InvoicesTypedProperties $instance */
        $instance = Model::cloneResultMap(
            $base,
            [
                'inv_id'          => null,
                'inv_cst_id'      => 1,
                'inv_status_flag' => 0,
                'inv_title'       => 'test-title',
                'inv_total'       => 9.99,
                'inv_created_at'  => '2026-01-01 00:00:00',
            ],
            $colMap
        );

        /**
         * toArray() with useGetter=true (the default) will call getInvId().
         * getInvId() accesses the uninitialized typed $inv_id property.
         * After the fix this must return null instead of throwing.
         */
        $arr = $instance->toArray();

        $this->assertNull($arr['inv_id']);
        $this->assertSame('test-title', $arr['inv_title']);
    }

    /**
     * Tests that serialize()/unserialize() round-trips a model with typed
     * properties correctly when a NOT NULL DB column returned NULL (leaving
     * the typed property uninitialized). The unserialized instance must not
     * throw TypeError when the serialised value is null.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/15711
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-22
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSerializeUnserializeWithTypedNullProperty(): void
    {
        $title  = uniqid('inv-');
        $date   = date('Y-m-d H:i:s');
        $base   = new InvoicesTypedProperties();

        $invoice             = new InvoicesTypedProperties();
        $invoice->inv_id     = 99;
        $invoice->inv_title  = $title;
        $invoice->inv_total  = 50.0;
        $invoice->inv_created_at = $date;

        $serialized = serialize($invoice);
        /** @var InvoicesTypedProperties $restored */
        $restored = unserialize($serialized);

        $this->assertSame($title, $restored->inv_title);
        $this->assertSame(50.0, $restored->inv_total);
        $this->assertSame($date, $restored->inv_created_at);

        /**
         * Now simulate the unserialize path where null is stored for the
         * typed non-nullable property (because cloneResultMap skipped it).
         * The direct PHP serialize/unserialize cycle should not throw.
         */
        $raw        = unserialize(serialize($invoice));
        $serialized = $raw->serialize();

        /**
         * Tamper: inject null for inv_id to mimic what happens when toArray()
         * returns null for an uninitialized typed property.
         */
        $data               = unserialize($serialized);
        $data['attributes']['inv_id'] = null;
        $tamperedSerialized = serialize($data);

        $fresh = new InvoicesTypedProperties();
        $fresh->unserialize($tamperedSerialized);

        /**
         * After the fix, unserialize() must not throw TypeError. The value
         * of inv_id will be uninitialized or null but the object is usable.
         */
        $arr = $fresh->toArray();
        $this->assertNull($arr['inv_id']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-09
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSerializeWithDirtyState(): void
    {
        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');
        $data  = [
            'inv_cst_id'      => 2,
            'inv_status_flag' => 3,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new Invoices();
        $invoice->assign($data);
        $invoice->setDirtyState(0);

        $result = $invoice->save();
        $this->assertNotFalse($result);

        $serialized = serialize($invoice);

        /** @var Invoices $newObject */
        $newObject = unserialize($serialized);
        $this->assertEquals(0, $newObject->getDirtyState());
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/15906
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-23
     *
     * @group  mysql
     * @group  sqlite
     */
    public function testMvcModelUnserializeCallsOnConstruct(): void
    {
        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');

        $invoice                 = new InvoicesOnConstruct();
        $invoice->inv_cst_id     = 1;
        $invoice->inv_status_flag = 0;
        $invoice->inv_title      = $title;
        $invoice->inv_total      = 10.0;
        $invoice->inv_created_at = $date;
        $invoice->save();

        // old-style serialize/unserialize
        $serialized = $invoice->serialize();
        $restored   = new InvoicesOnConstruct();
        $restored->unserialize($serialized);

        $this->assertSame('initialized', $restored->onConstructLabel);

        // PHP 8 __serialize/__unserialize
        $phpSerialized = serialize($invoice);
        /** @var InvoicesOnConstruct $phpRestored */
        $phpRestored = unserialize($phpSerialized);

        $this->assertSame('initialized', $phpRestored->onConstructLabel);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/15837
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-23
     *
     * @group  mysql
     * @group  sqlite
     */
    public function testMvcModelUnserializeRestoresNullSnapshot(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        (new InvoicesMigration($connection))->insert(10, 1, 0, uniqid('inv-'));

        $invoice = InvoicesKeepSnapshots::findFirst(10);
        $this->assertNotFalse($invoice);

        // old-style serialize/unserialize
        $serialized = $invoice->serialize();
        $restored   = new InvoicesKeepSnapshots();
        $restored->unserialize($serialized);

        $this->assertIsArray($restored->getChangedFields());
        $this->assertEmpty($restored->getChangedFields());

        // PHP 8 __serialize/__unserialize
        $phpSerialized = serialize($invoice);
        /** @var InvoicesKeepSnapshots $phpRestored */
        $phpRestored = unserialize($phpSerialized);

        $this->assertIsArray($phpRestored->getChangedFields());
        $this->assertEmpty($phpRestored->getChangedFields());
    }
}
