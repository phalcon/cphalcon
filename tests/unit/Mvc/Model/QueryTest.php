<?php
namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\Di;
use Phalcon\Mvc\Model\Query;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Mvc\Model\Transaction\Manager as TransactionManager;


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
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        $di = $this->tester->getApplication()->getDI();

        $di->set('modelsManager', function() {
            return new Manager;
        });

        $di->set('modelsMetadata', function() {
            return new Memory;
        });

        Di::setDefault($di);
    }


    /**
     * Tests Query::__construct behaviour
     *
     * @issue 12409
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
     * helper method DRY -> any object should be reflectable
     *
     * @param Object $object
     * @param string $propertyName
     * @return mixed
     */
    private function getUnaccessableObjectProperty($object, $propertyName)
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
     * Tests Query::__construct behaviour
     *
     * @issue 12409
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2016-11-28
     */
    public function testQueryConstructorWithoutPHQL() {
        $this->specify(
            'The Query::__construct sets _phql in the object',
            function() {
                $q = new Query();
                $testValue = $this->getUnaccessableObjectProperty($q, '_phql');


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
                $enableImplicitJoins = $this->getUnaccessableObjectProperty($q, '_enableImplicitJoins');
                expect(true)->equals($enableImplicitJoins);
            }
        );
    }
}