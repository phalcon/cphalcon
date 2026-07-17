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
final class ConstructTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Mvc\Model\Relation :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelRelationConstruct(): void
    {
        $relation = new Relation(
            Relation::BELONGS_TO,
            'RefModel',
            'inv_cst_id',
            'cst_id',
            ['alias' => 'customer']
        );

        $this->assertSame(Relation::BELONGS_TO, $relation->getType());
        $this->assertSame('RefModel', $relation->getReferencedModel());
        $this->assertSame('inv_cst_id', $relation->getFields());
        $this->assertSame('cst_id', $relation->getReferencedFields());
        $this->assertSame(['alias' => 'customer'], $relation->getOptions());
    }
}
