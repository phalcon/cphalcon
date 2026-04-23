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

final class GetParamsTest extends AbstractDatabaseTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function testMvcModelRelationGetParams(): void
    {
        $options = [
            'reusable' => true,
            'alias'    => 'mechanicalParts',
            'params'   => [
                'conditions' => 'robotTypeId = :type:',
                'bind'       => [
                    'type' => 4,
                ],
            ],
        ];

        $relation = new Relation(
            Relation::HAS_MANY,
            'RobotsParts',
            'id',
            'robots_id',
            $options
        );

        $expected = $options['params'];
        $actual   = $relation->getParams();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function testMvcModelRelationGetParamsWhenNoneSet(): void
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

        $this->assertFalse($relation->getParams());
    }
}
