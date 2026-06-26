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

namespace Phalcon\Tests\Database\Db\Reference;

use Phalcon\Db\Reference;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ConstructTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Reference :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbReferenceConstruct(): void
    {
        $reference = new Reference(
            'field_fk',
            [
                'referencedSchema'  => 'invoicing',
                'referencedTable'   => 'products',
                'columns'           => ['product_type', 'product_code'],
                'referencedColumns' => ['type', 'code'],
                'schema'            => 'public',
                'onDelete'          => 'CASCADE',
                'onUpdate'          => 'RESTRICT',
            ]
        );

        $this->assertSame('field_fk', $reference->getName());
        $this->assertSame('products', $reference->getReferencedTable());
        $this->assertSame('invoicing', $reference->getReferencedSchema());
        $this->assertSame('public', $reference->getSchemaName());
        $this->assertSame(
            ['product_type', 'product_code'],
            $reference->getColumns()
        );
        $this->assertSame(['type', 'code'], $reference->getReferencedColumns());
        $this->assertSame('CASCADE', $reference->getOnDelete());
        $this->assertSame('RESTRICT', $reference->getOnUpdate());
    }
}
