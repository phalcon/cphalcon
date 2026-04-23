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

final class GetReferencedModelTest extends AbstractDatabaseTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function testMvcModelRelationGetReferencedModel(): void
    {
        $relation = new Relation(
            Relation::HAS_MANY,
            'RobotsParts',
            'id',
            'robots_id',
            [
                'reusable' => true,
                'alias'    => 'mechanicalParts',
            ]
        );

        $expected = 'RobotsParts';
        $actual   = $relation->getReferencedModel();
        $this->assertSame($expected, $actual);
    }
}
