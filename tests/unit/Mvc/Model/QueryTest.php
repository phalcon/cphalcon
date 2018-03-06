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

use Phalcon\DiInterface;
use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Transaction;
use Phalcon\Test\Module\UnitTest;

/**
 * Phalcon\Test\Unit\Mvc\Model\QueryTest
 *
 * Tests the Phalcon\Mvc\Model\Query component
 *
 * @package Phalcon\Test\Unit\Mvc\Model
 */
class QueryTest extends UnitTest
{
    /**
     * @var DiInterface
     */
    private $di;

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        /** @var \Phalcon\Mvc\Application $app */
        $app = $this->tester->getApplication();
        $this->di = $app->getDI();
    }

    /**
     * @test
     */
    public function checkIfTransactionIsSet()
    {
        $this->specify(
            "Check if transaction has been set",
            function () {
                $transaction = new Transaction($this->di);
                $query = new Query(null, $this->di);
                $query->setTransaction($transaction);

                expect($query->getTransaction(), $transaction);
            }
        );
    }

    public function testSelectParsing()
    {
        $this->specify(
            "SELECT PHQL queries don't work as expected",
            function ($phql, $expected) {
                $query = new Query($phql);
                $query->setDI($this->di);

                expect($query->parse())->equals($expected);
            },
            [
                "examples" => require PATH_FIXTURES . 'query/select_parsing.php'
            ]
        );
    }

    /**
     * Tests Query::parse insert
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
     * @since  2017-01-24
     */
    public function shouldInsertParsing()
    {
        $this->specify(
            "INSERT PHQL queries don't execute insert query",
            function ($params, $expected) {
                $query = new Query($params['query']);
                $query->setDI($this->di);

                expect($query->parse())->equals($expected);
            },
            [
                'examples' => include PATH_FIXTURES . 'mvc/model/query_test/data_to_insert_parsing.php'
            ]
        );
    }

    /**
     * Tests Query::parse update
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
     * @since  2017-01-24
     */
    public function shouldUpdateParsing()
    {
        $this->specify(
            "UPDATE PHQL queries don't execute update query",
            function ($params, $expected) {
                $query = new Query($params['query']);
                $query->setDI($this->di);

                expect($query->parse())->equals($expected);
            },
            [
                'examples' => include PATH_FIXTURES . 'mvc/model/query_test/data_to_update_parsing.php'
            ]
        );
    }

    /**
     * Tests Query::parse delete
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
     * @since  2017-01-24
     */
    public function shouldDeleteParsing()
    {
        $this->specify(
            "DELETE PHQL queries don't work as expected",
            function ($params, $expected) {
                $query = new Query($params['query']);
                $query->setDI($this->di);

                expect($query->parse())->equals($expected);
            },
            [
                'examples' => include PATH_FIXTURES . 'mvc/model/query_test/data_to_delete_parsing.php'
            ]
        );
    }
}
