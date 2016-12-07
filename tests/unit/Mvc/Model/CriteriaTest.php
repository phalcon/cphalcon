<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\Di;
use Phalcon\Test\Models\Users;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\Model\Metadata\Memory;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Mvc\Model\Transaction\Failed;
use Phalcon\Test\Proxy\Mvc\Model\Transaction\Manager as TransactionManager;

/**
 * \Phalcon\Test\Unit\Mvc\Model\CriteriaTest
 * Tests the Phalcon\Mvc\Model\Criteria component
 *
 * @copyright (c) 2011-2016 Phalcon Team
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
     * @issue  10676
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-08-11
     */
    public function testShouldExecuteInWhereQueryWithEmptyArray()
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
     * Tests Criteria::execute with a transaction passed
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testCriteriaExecuteWithTransaction() {
        $this->specify(
            'The Criteria::execute with a transaction passed as parameter does not work as expected',
            function() {
                $criteria = Users::query()->inWhere(Users::class . '.id', []);
                $tm = new TransactionManager();
                $transaction = $tm->get(true);

                expect($criteria->getWhere())->equals(Users::class . '.id != ' . Users::class . '.id');
                expect($criteria->execute($transaction))->isInstanceOf(Simple::class);
            }
        );
    }
}
