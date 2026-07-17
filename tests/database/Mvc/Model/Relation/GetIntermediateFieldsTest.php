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
final class GetIntermediateFieldsTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Mvc\Model\Relation :: getIntermediateFields()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelRelationGetIntermediateFields(): void
    {
        $relation = new Relation(Relation::HAS_MANY_THROUGH, 'RefModel', 'id', 'ref', []);

        $relation->setIntermediateRelation(['int_a', 'int_b'], 'IntermediateModel', 'int_ref');

        $this->assertSame(['int_a', 'int_b'], $relation->getIntermediateFields());
    }
}
