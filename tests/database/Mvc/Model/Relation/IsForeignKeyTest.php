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

final class IsForeignKeyTest extends AbstractDatabaseTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function testMvcModelRelationIsForeignKeyFalseWhenEmpty(): void
    {
        $relation = new Relation(
            Relation::HAS_MANY,
            'RobotsParts',
            'id',
            'robots_id',
            []
        );

        $this->assertFalse($relation->isForeignKey());
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function testMvcModelRelationIsForeignKeyFalseWhenExplicitlyFalse(): void
    {
        $relation = new Relation(
            Relation::HAS_MANY,
            'RobotsParts',
            'id',
            'robots_id',
            ['foreignKey' => false]
        );

        $this->assertFalse($relation->isForeignKey());
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function testMvcModelRelationIsForeignKeyFalseWhenEmptyArray(): void
    {
        $relation = new Relation(
            Relation::HAS_MANY,
            'RobotsParts',
            'id',
            'robots_id',
            ['foreignKey' => []]
        );

        $this->assertFalse($relation->isForeignKey());
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function testMvcModelRelationIsForeignKeyTrueWhenTrue(): void
    {
        $relation = new Relation(
            Relation::HAS_MANY,
            'RobotsParts',
            'id',
            'robots_id',
            ['foreignKey' => true]
        );

        $this->assertTrue($relation->isForeignKey());
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function testMvcModelRelationIsForeignKeyTrueWhenArray(): void
    {
        $relation = new Relation(
            Relation::HAS_MANY,
            'RobotsParts',
            'id',
            'robots_id',
            [
                'foreignKey' => [
                    'message' => 'The part_id does not exist on the Parts model',
                ],
            ]
        );

        $this->assertTrue($relation->isForeignKey());
    }
}
