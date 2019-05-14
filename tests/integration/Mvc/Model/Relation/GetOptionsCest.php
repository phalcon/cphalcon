<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Relation;

use IntegrationTester;
use Phalcon\Mvc\Model\Relation;

/**
 * Class GetOptionsCest
 */
class GetOptionsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Relation :: getOptions()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-18
     */
    public function mvcModelRelationGetOptions(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Relation - getOptions()');

        $options = [
            'reusable' => true, // cache related data
            'alias'    => 'mechanicalParts',
        ];

        $relation = new Relation(
            Relation::HAS_MANY,
            'RobotsParts',
            'id',
            'robots_id',
            $options
        );

        $I->assertEquals(
            $options,
            $relation->getOptions()
        );
    }
}
