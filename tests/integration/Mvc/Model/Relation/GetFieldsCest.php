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

namespace Phalcon\Test\Integration\Mvc\Model\Relation;

use IntegrationTester;
use Phalcon\Mvc\Model\Relation;

/**
 * Class GetFieldsCest
 */
class GetFieldsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Relation :: getFields()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function mvcModelRelationGetFieldsString(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Relation - getFields() - string');

        $relation = new Relation(
            Relation::HAS_MANY,
            'RobotsParts',
            'id',
            'robots_id',
            [
                'reusable' => true, // cache related data
                'alias'    => 'mechanicalParts',
            ]
        );

        $I->assertEquals(
            'id',
            $relation->getFields()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\Relation :: getFields()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function mvcModelRelationGetFieldsArray(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Relation - getFields() - array');

        $relation = new Relation(
            Relation::HAS_MANY,
            'RobotsParts',
            [
                'type',
                'name',
            ],
            'robots_id',
            [
                'reusable' => true, // cache related data
                'alias'    => 'mechanicalParts',
            ]
        );

        $I->assertEquals(
            [
                'type',
                'name',
            ],
            $relation->getFields()
        );
    }
}
