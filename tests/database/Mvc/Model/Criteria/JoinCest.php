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
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Customers;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\Robot;
use Phalcon\Test\Models\RobotPart;

/**
 * Class JoinCest
 */
class JoinCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: join()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group common
     */
    public function mvcModelCriteriaJoin(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - join()');

        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $criteria
            ->setModelName(Invoices::class)
            ->join(Customers::class, 'inv_cst_id = cst_id', 'customer')
        ;

        $builder = $criteria->createBuilder();

        $I->assertInstanceOf(Builder::class, $builder);

        $expected = 'SELECT [Phalcon\Test\Models\Invoices].* '
            . 'FROM [Phalcon\Test\Models\Invoices] '
            . 'JOIN [Phalcon\Test\Models\Customers] AS [customer] ON inv_cst_id = cst_id';
        $actual   = $builder->getPhql();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: join() and use ManyToMany with
     * Multiple schemas
     *
     * @issue  14716
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     *
     * @group mysql
     */
    public function mvcModelCriteriaJoinManyToManyMultipleSchema(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - join() and use ManyToMany with Multiple schemas');

        $this->setDatabase($I);
        
        /**
         * The following test needs to skip sqlite because I think
         * we can't create multiple schemas with sqlite
         */
        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $builder = $criteria->createBuilder();
        $builder->from(Robot::class);
        $builder->join(RobotPart::class);

        $expected = 'SELECT `robot`.`robot_id`, `robot`.`robot_name` '
            . 'FROM `public`.`robot`  '
            . 'INNER JOIN `private`.`robot_to_robot_part` '
            . 'ON `robot`.`robot_id` = `robot_to_robot_part`.`robot_id` '
            . 'INNER JOIN `public`.`robot_part` '
            . 'ON `robot_to_robot_part`.`robot_part_id` = `robot_part`.`robot_part_id`';
        $actual   = $builder->getQuery()->getSql();

        $I->assertEquals($expected, $actual['sql']);
    }
}
