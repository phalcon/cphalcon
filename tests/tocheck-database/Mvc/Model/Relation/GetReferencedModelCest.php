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

namespace Phalcon\Tests\Integration\Mvc\Model\Relation;

use IntegrationTester;
use Phalcon\Mvc\Model\Relation;

/**
 * Class GetReferencedModelCest
 */
class GetReferencedModelCest
{
    /**
     * Tests Phalcon\Mvc\Model\Relation :: getReferencedModel()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function mvcModelRelationGetReferencedModel(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Relation - getReferencedModel()');

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
            'RobotsParts',
            $relation->getReferencedModel()
        );
    }
}
