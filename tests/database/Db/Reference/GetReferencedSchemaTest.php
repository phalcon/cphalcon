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
final class GetReferencedSchemaTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Reference :: getReferencedSchema()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbReferenceGetReferencedSchema(): void
    {
        $reference = new Reference(
            'field_fk',
            [
                'referencedSchema'  => 'invoicing',
                'referencedTable'   => 'products',
                'columns'           => ['product_code'],
                'referencedColumns' => ['code'],
            ]
        );

        $this->assertSame('invoicing', $reference->getReferencedSchema());

        $reference = new Reference(
            'field_fk',
            [
                'referencedTable'   => 'products',
                'columns'           => ['product_code'],
                'referencedColumns' => ['code'],
            ]
        );

        $this->assertNull($reference->getReferencedSchema());
    }
}
