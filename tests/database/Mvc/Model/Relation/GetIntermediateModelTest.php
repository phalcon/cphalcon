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
final class GetIntermediateModelTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Mvc\Model\Relation :: getIntermediateModel()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelRelationGetIntermediateModel(): void
    {
        $relation = new Relation(Relation::HAS_MANY_THROUGH, 'RefModel', 'id', 'ref', []);

        $relation->setIntermediateRelation('int_fields', 'IntermediateModel', 'int_ref');

        $this->assertSame('IntermediateModel', $relation->getIntermediateModel());
    }
}
