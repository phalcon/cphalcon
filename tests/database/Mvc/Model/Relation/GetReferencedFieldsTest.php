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

namespace Phalcon\Tests\Database\Mvc\Model\Relation;

use Phalcon\Mvc\Model\Relation;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetReferencedFieldsTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Mvc\Model\Relation :: getReferencedFields()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelRelationGetReferencedFields(): void
    {
        $relation = new Relation(
            Relation::HAS_MANY,
            'RefModel',
            'id',
            ['ref_a', 'ref_b'],
            []
        );

        $this->assertSame(['ref_a', 'ref_b'], $relation->getReferencedFields());
    }
}
