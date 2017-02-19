<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\Di;
use Phalcon\Test\Models\Users;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\Model\Metadata\Memory;
use Phalcon\Mvc\Model\Resultset\Simple;

/**
 * \Phalcon\Test\Unit\Mvc\Model\CriteriaTest
 * Tests the Phalcon\Mvc\Model\Criteria component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CriteriaTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        $di = $this->tester->getApplication()->getDI();

        $di->set('modelsManager', function () {
            return new Manager;
        });

        $di->set('modelsMetadata', function () {
            return new Memory;
        });

        Di::setDefault($di);
    }

    /**
     * Tests Criteria::inWhere with empty array.
     *
     * @test
     * @issue  10676
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-08-11
     */
    public function shouldExecuteInWhereQueryWithEmptyArray()
    {
        $this->specify(
            'The Criteria::inWhere with empty array does not work as expected',
            function () {
                $criteria = Users::query()->inWhere(Users::class . '.id', []);

                expect($criteria->getWhere())->equals(Users::class . '.id != ' . Users::class . '.id');
                expect($criteria->execute())->isInstanceOf(Simple::class);
            }
        );
    }

    /**
     * Tests work with limit / offset
     *
     * @test
     * @issue  12419
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-12-18
     */
    public function shouldCorrectHandleLimitAndOffset()
    {
        $this->specify(
            'The criteria object works with limit / offset incorrectly',
            function ($limit, $offset, $expected) {
                /** @var \Phalcon\Mvc\Model\Criteria $query */
                $query = Users::query();

                $query->limit($limit, $offset);

                expect($query->getLimit())->equals($expected);
            },
            ['examples' => $this->limitOffsetProvider()]
        );
    }

    protected function limitOffsetProvider()
    {
        return [
            [-7,      null,  7                                  ],
            ["-7234", null,  7234                               ],
            ["18",    null,  18                                 ],
            ["18",    2,     ['number' => 18, 'offset' => 2]    ],
            ["-1000", -200,  ['number' => 1000, 'offset' => 200]],
            ["1000", "-200", ['number' => 1000, 'offset' => 200]],
            ["0",    "-200", null                               ],
            ["%3CMETA%20HTTP-EQUIV%3D%22refresh%22%20CONT ENT%3D%220%3Burl%3Djavascript%3Aqss%3D7%22%3E", 50, null],
        ];
    }
}
