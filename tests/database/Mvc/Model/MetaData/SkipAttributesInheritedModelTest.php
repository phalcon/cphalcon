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

namespace Phalcon\Tests\Database\Mvc\Model\MetaData;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\InvoicesSkipCreate;
use Phalcon\Tests\Support\Models\InvoicesSkipCreateExtended;
use Phalcon\Tests\Support\Traits\DiTrait;

final class SkipAttributesInheritedModelTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests that skipAttributes() called in a parent model's initialize() does
     * not prematurely initialize metadata for an inheriting child model using
     * the parent's source table, corrupting the child's attribute list.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16544
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-30
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelMetadataSkipAttributesDoesNotCorruptInheritedModelMetadata(): void
    {
        $adapter = $this->newService('metadataMemory');
        $adapter->setDi($this->container);
        $adapter->reset();

        $this->container->setShared('modelsMetadata', $adapter);

        $parent = new InvoicesSkipCreate();
        $child  = new InvoicesSkipCreateExtended();

        /**
         * Parent attributes must come from co_invoices
         */
        $expected = [
            'inv_id',
            'inv_cst_id',
            'inv_status_flag',
            'inv_title',
            'inv_total',
            'inv_created_at',
        ];
        $actual   = $adapter->getAttributes($parent);
        $this->assertSame($expected, $actual);

        /**
         * Child attributes must come from co_customers, not co_invoices.
         * With the bug, this returns the invoice columns instead.
         */
        $expected = [
            'cst_id',
            'cst_status_flag',
            'cst_name_last',
            'cst_name_first',
        ];
        $actual   = $adapter->getAttributes($child);
        $this->assertSame($expected, $actual);

        /**
         * skipAttributes() registered in the parent's initialize() must still
         * be honored on the child after the fix.
         */
        $expected = ['inv_created_at' => null];
        $actual   = $adapter->getAutomaticCreateAttributes($child);
        $this->assertSame($expected, $actual);
    }
}
