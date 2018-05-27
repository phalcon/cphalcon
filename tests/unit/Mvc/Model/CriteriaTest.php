<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\Di;
use Phalcon\Test\Models\Users;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\Model\Metadata\Memory;
use Phalcon\Mvc\Model\Resultset\Simple;

/**
 * Phalcon\Test\Unit\Mvc\Model\CriteriaTest
 *
 * Tests the Phalcon\Mvc\Model\Criteria component
 *
 * @package Phalcon\Test\Unit\Mvc\Model
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
     * @issue  https://github.com/phalcon/cphalcon/issues/10676
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
     * @issue  https://github.com/phalcon/cphalcon/issues/12419
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
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/model/criteria_test/limit_offset_provider.php'
            ]
        );
    }
}
