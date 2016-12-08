<?php
namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\Di;
use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Transaction;
use Phalcon\Test\Models\Users;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\Metadata\Memory;
use Phalcon\Mvc\Model\Transaction\Manager as TransactionManager;

/**
 * \Phalcon\Test\Unit\Mvc\Model\QueryTest
 * Tests the Phalcon\Mvc\Model\Query Object
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Jakob Oberhummer <cphalcon@chilimatic.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class QueryTest extends UnitTest
{
    /**
     * helper method DRY -> any object should be reflectable
     *
     * @param Object $object
     * @param string $propertyName
     * @return mixed
     */
    protected function getInaccessableObjectProperty($object, $propertyName)
    {
        if (!$object || !$propertyName) {
            throw new \InvalidArgumentException('Object or property has to be passed');
        }

        $reflectionClass = new \ReflectionClass($object);
        $reflectionProperty = $reflectionClass->getProperty($propertyName);
        $reflectionProperty->setAccessible(true);
        return $reflectionProperty->getValue($object);
    }

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        $di = $this->tester->getApplication()->getDI();

        $di->set('modelsManager', function() {
            return new Manager();
        });

        $di->set('modelsMetadata', function() {
            return new Memory();
        });

        $di->set('transactionManager', function() {
            return new TransactionManager();
        });

        Di::setDefault($di);
    }


    /**
     * Tests Query::__construct behaviour
     *
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testQueryConstructorWithPHQLString() {
        $this->specify(
            'The Query::__construct sets _phql string in the object',
            function() {
                $query = 'SELECT 1';
                $q = new Query($query);

                $queryReflection = new \ReflectionClass($q);
                $phqlReflection = $queryReflection->getProperty('_phql');
                $phqlReflection->setAccessible(true);
                $testValue = $phqlReflection->getValue($q);

                expect($testValue)->equals($query);
            }
        );
    }



    /**
     * Tests Query::__construct behaviour
     *
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testQueryConstructorWithoutPHQL() {
        $this->specify(
            'The Query::__construct sets _phql in the object',
            function() {
                $q = new Query();
                $testValue = $this->getInaccessableObjectProperty($q, '_phql');


                expect($testValue)->equals(null);
            }
        );
    }


    /**
     * Tests Query::__construct behaviour
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testIfQueryConstructorSetsDI() {
        $this->specify(
            'The Query::__construct sets DI in the object',
            function() {
                $q = new Query(null, Di::getDefault());
                expect(Di::getDefault())->equals($q->getDI());
            }
        );
    }

    /**
     * Tests Query::__construct behaviour
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testConstructorSetsImplicitJoins() {
        $this->specify(
            'The Query::__construct sets DI in the object',
            function() {
                $options = [
                    'enable_implicit_joins' => true
                ];
                $q = new Query(null, Di::getDefault(), $options);
                $enableImplicitJoins = $this->getInaccessableObjectProperty($q, '_enableImplicitJoins');
                expect(true)->equals($enableImplicitJoins);
            }
        );
    }

    /**
     * Tests Query::setBindParams default behaviour
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testSetBindParams() {
        $this->specify(
            'The Query::setBindParams sets bind params',
            function() {
                $bindParams = [
                    'myField' => 1,
                    'myOtherField' => 'test'
                ];

                $q = new Query(null, Di::getDefault());
                $q->setBindParams($bindParams);

                expect($bindParams)->equals($q->getBindParams());
            }
        );
    }

    /**
     * Tests Query::setBindParams default behaviour
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testSetBindParamsMerge() {
        $this->specify(
            'The Query::setBindParams union merge',
            function() {
                $bindParams = [
                    'myField' => 1,
                    'myOtherField' => 'test'
                ];

                $mergeParams = [
                    'myField' => 12,
                    'myThirdField' => 14
                ];

                $result = [
                    'myField' => 1,
                    'myOtherField' => 'test',
                    'myThirdField' => 14
                ];

                $q = new Query(null, Di::getDefault());
                $q->setBindParams($bindParams);
                $q->setBindParams($mergeParams, true);

                expect($result)->equals($q->getBindParams());
            }
        );
    }

    /**
     * Tests Query::setType
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testSetType() {
        $this->specify(
            'The Query::setType ',
            function() {
                $q = new Query(null, Di::getDefault());
                $q->setType(1);

                expect(1)->equals($q->getType());
            }
        );
    }


    /**
     * Tests Query::set unique row
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testSetUniqueRow() {
        $this->specify(
            'The Query::setUniqueRow',
            function() {
                $q = new Query(null, Di::getDefault());
                $q->setUniqueRow(true);

                expect(true)->equals($q->getUniqueRow());
            }
        );
    }

    /**
     * Tests Query::getTransactionConnection
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testGetTransactionConnectionWithNoModelTransaction() {
        $this->specify(
            'The Query::getTransaction should return the connection of the query transaction',
            function() {
                $q = new Query(null, Di::getDefault());
                $q->setUniqueRow(true);
                /**
                 * @var TransactionManager $transactionManager
                 */
                $transactionManager = DI::getDefault()->get('transactionManager');
                $transaction = $transactionManager->getOrCreateTransaction();
                $q->setTransaction($transaction);
                $model = new Users();

                expect($transaction->getConnection())->equals($q->getTransactionConnection($model));
            }
        );
    }

    /**
     * Tests Query::getTransactionConnection
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testGetTransactionConnectionWithModelTransaction() {
        $this->specify(
            'The Query::getTransactionConnection should return the transaction of the query object',
            function() {
                $q = new Query(null, Di::getDefault());
                $q->setUniqueRow(true);
                /**
                 * @var TransactionManager $transactionManager
                 */
                $transactionManager = DI::getDefault()->get('transactionManager');
                $transaction = $transactionManager->getOrCreateTransaction();
                $q->setTransaction($transaction);
                $model = new Users();
                $modelTransaction = new Transaction(DI::getDefault());
                $model->setTransaction($modelTransaction);

                expect($transaction->getConnection())->equals($q->getTransactionConnection($model));
            }
        );
    }

    /**
     * Tests Query::getTransactionConnection
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testGetTransactionConnectionWithModelTransactionButNoQueryTransaction() {
        $this->specify(
            'The Query::getTransactionConnection should return the connection of the model transaction',
            function() {
                $q = new Query(null, Di::getDefault());
                $q->setUniqueRow(true);

                /**
                 * @var TransactionManager $transactionManager
                 */
                $transactionManager = DI::getDefault()->get('transactionManager');
                $model = new Users();
                $modelTransaction = $transactionManager->getOrCreateTransaction();
                $model->setTransaction($modelTransaction);
                expect($modelTransaction->getConnection())->equals($q->getTransactionConnection($model));
            }
        );
    }


    /**
     * Tests Query::getReadConnection
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testGetReadConnectionWithModelTransactionButNoQueryTransaction() {
        $this->specify(
            'The Query::getReadConnection should return the connection of the model transaction',
            function() {
                $q = new Query(null, Di::getDefault());
                $q->setUniqueRow(true);

                /**
                 * @var TransactionManager $transactionManager
                 */
                $transactionManager = DI::getDefault()->get('transactionManager');
                $model = new Users();
                $modelTransaction = $transactionManager->getOrCreateTransaction();
                $model->setTransaction($modelTransaction);
                expect($modelTransaction->getConnection())->equals($q->getReadConnection($model, [], [], []));
            }
        );
    }

    /**
     * Tests Query::getReadConnection
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testGetReadConnectionWithModelTransactionAndQueryTransaction() {
        $this->specify(
            'The Query::getReadConnection should return connection of the transaction of the query object',
            function() {
                $q = new Query(null, Di::getDefault());
                $q->setUniqueRow(true);
                /**
                 * @var TransactionManager $transactionManager
                 */
                $transactionManager = DI::getDefault()->get('transactionManager');
                $transaction = $transactionManager->getOrCreateTransaction();
                $q->setTransaction($transaction);
                $model = new Users();
                $modelTransaction = new Transaction(DI::getDefault());
                $model->setTransaction($modelTransaction);

                expect($transaction->getConnection())->equals($q->getReadConnection($model, [], [], []));
            }
        );
    }

    /**
     * Tests Query::getReadConnection
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testGetReadConnectionWithNoModelTransactionButQueryTransaction() {
        $this->specify(
            'The Query::getReadConnection should return the connection of the query transaction',
            function() {
                $q = new Query(null, Di::getDefault());
                $q->setUniqueRow(true);
                /**
                 * @var TransactionManager $transactionManager
                 */
                $transactionManager = DI::getDefault()->get('transactionManager');
                $transaction = $transactionManager->getOrCreateTransaction();
                $q->setTransaction($transaction);
                $model = new Users();

                expect($transaction->getConnection())->equals($q->getReadConnection($model, [], [], []));
            }
        );
    }


    /**
     * Tests Query::getReadConnection
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testGetWriteConnectionWithModelTransactionButNoQueryTransaction() {
        $this->specify(
            'The Query::getWriteConnection should return the connection of the model transaction',
            function() {
                $q = new Query(null, Di::getDefault());
                $q->setUniqueRow(true);

                /**
                 * @var TransactionManager $transactionManager
                 */
                $transactionManager = DI::getDefault()->get('transactionManager');
                $model = new Users();
                $modelTransaction = $transactionManager->getOrCreateTransaction();
                $model->setTransaction($modelTransaction);
                expect($modelTransaction->getConnection())->equals($q->getWriteConnection($model, [], [], []));
            }
        );
    }

    /**
     * Tests Query::getWriteConnection
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testGetWriteConnectionWithModelTransactionAndQueryTransaction() {
        $this->specify(
            'The Query::getWriteConnection should return connection of the transaction of the query object',
            function() {
                $q = new Query(null, Di::getDefault());
                $q->setUniqueRow(true);
                /**
                 * @var TransactionManager $transactionManager
                 */
                $transactionManager = DI::getDefault()->get('transactionManager');
                $transaction = $transactionManager->getOrCreateTransaction();
                $q->setTransaction($transaction);
                $model = new Users();
                $modelTransaction = new Transaction(DI::getDefault());
                $model->setTransaction($modelTransaction);

                expect($transaction->getConnection())->equals($q->getWriteConnection($model, [], [], []));
            }
        );
    }

    /**
     * Tests Query::getWriteConnection
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testGetWriteConnectionWithNoModelTransactionButQueryTransaction() {
        $this->specify(
            'The Query::getReadConnection should return the connection of the query transaction',
            function() {
                $q = new Query(null, Di::getDefault());
                $q->setUniqueRow(true);
                /**
                 * @var TransactionManager $transactionManager
                 */
                $transactionManager = DI::getDefault()->get('transactionManager');
                $transaction = $transactionManager->getOrCreateTransaction();
                $q->setTransaction($transaction);
                $model = new Users();

                expect($transaction->getConnection())->equals($q->getWriteConnection($model, [], [], []));
            }
        );
    }
}