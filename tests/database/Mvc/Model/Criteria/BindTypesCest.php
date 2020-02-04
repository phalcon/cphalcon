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

namespace Phalcon\Test\Database\Mvc\Model\Criteria;

use DatabaseTester;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class BindTypesCest
 */
class BindTypesCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: bindTypes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     */
    public function mvcModelCriteriaBindTypes(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - bindTypes()');


        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $criteria->bindTypes(
            [
                'one',
                'two',
            ]
        );

        $actual = $criteria->getParams();
        $I->assertArrayHasKey('bindTypes', $actual);

        $expected = [
            'one',
            'two',
        ];
        $actual   = $actual['bindTypes'];
        $I->assertEquals($expected, $actual);
    }
}
