<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\Metadata\Memory;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Users;

class CriteriaCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    /**
     * Tests Criteria::inWhere with empty array.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10676
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-08-11
     */
    public function shouldExecuteInWhereQueryWithEmptyArray(IntegrationTester $I)
    {
        $criteria = Users::query()->inWhere(Users::class . '.id', []);

        $I->assertEquals(Users::class . '.id != ' . Users::class . '.id', $criteria->getWhere());
        $I->assertInstanceOf(Simple::class, $criteria->execute());
    }

    /**
     * Tests work with limit / offset
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12419
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-12-18
     */
    public function shouldCorrectHandleLimitAndOffset(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check the test data');
        $examples = $this->getLimitOffset();
        foreach ($examples as $item) {
            $limit    = $item[0];
            $offset   = $item[1];
            $expected = $item[2];
            /** @var \Phalcon\Mvc\Model\Criteria $query */
            $query = Users::query();
            $query->limit($limit, $offset);

            $actual = $query->getLimit();
            $I->assertEquals($expected, $actual);
        }
    }

    private function getLimitOffset(): array
    {
        return [
            [-7, null, 7],
            ["-7234", null, 7234],
            ["18", null, 18],
            ["18", 2, ['number' => 18, 'offset' => 2]],
            ["-1000", -200, ['number' => 1000, 'offset' => 200]],
            ["1000", "-200", ['number' => 1000, 'offset' => 200]],
            ["0", "-200", null],
            ["%3CMETA%20HTTP-EQUIV%3D%22refresh%22%20CONT ENT%3D%220%3Burl%3Djavascript%3Aqss%3D7%22%3E", 50, null],
        ];
    }
}
