<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\DiInterface;
use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Transaction;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Models\Robotters;
use Phalcon\Test\Models\Some\Products as SomeProducts;

/**
 * \Phalcon\Test\Unit\Mvc\Model\QueryTest
 * Tests the Phalcon\Mvc\Model\Query component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class QueryTest extends UnitTest
{
    /**
     * @var DiInterface
     */
    private $di;

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
            ["examples" => require PATH_FIXTURES . 'query/select_parsing.php']
        );
    }

    public function testInsertParsing()
    {
        $this->specify(
            "INSERT PHQL queries don't work as expected",
            function () {
                $expected = array(
                    'model' => Robots::class,
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 322,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'NULL',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some robot',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1945',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robots::class . ' VALUES (NULL, \'some robot\', 1945)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => strtolower(Robots::class),
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 322,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'NULL',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some robot',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1945',
                            ),
                        ),
                    ),
                );
                $query = new Query('insert into ' . strtolower(Robots::class) . ' values (null, \'some robot\', 1945)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => SomeProducts::class,
                    'table' => 'le_products',
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'Some name',
                            ),
                        ),
                        array(
                            'type' => 259,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '100.15',
                            ),
                        ),
                        array(
                            'type' => 350,
                            'value' => array(
                                'type' => 'functionCall',
                                'name' => 'current_date',
                            ),
                        ),
                        array(
                            'type' => 350,
                            'value' => array(
                                'type' => 'functionCall',
                                'name' => 'now',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . SomeProducts::class . ' VALUES ("Some name", 100.15, current_date(), now())');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => Robots::class,
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 356,
                            'value' => array(
                                'type' => 'parentheses',
                                'left' => array(
                                    'type' => 'binary-op',
                                    'op' => '*',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '+',
                                        'left' => array(
                                            'type' => 'literal',
                                            'value' => '1',
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '1000',
                                        ),
                                    ),
                                    'right' => array(
                                        'type' => 'placeholder',
                                        'value' => ':le_id',
                                    ),
                                ),
                            ),
                        ),
                        array(
                            'type' => 350,
                            'value' => array(
                                'type' => 'functionCall',
                                'name' => 'CONCAT',
                                'arguments' => array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '\'some\'',
                                    ),
                                    array(
                                        'type' => 'literal',
                                        'value' => '\'robot\'',
                                    ),
                                ),
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '2011',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robots::class . ' VALUES ((1+1000*:le_id:), CONCAT(\'some\', \'robot\'), 2011)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => Robots::class,
                    'table' => 'robots',
                    'fields' => array(
                        'name',
                        'type',
                        'year',
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'a name',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'virtual',
                            ),
                        ),
                        array(
                            'type' => 273,
                            'value' => array(
                                'type' => 'placeholder',
                                'value' => ':0',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robots::class . ' (name, type, year) VALUES (\'a name\', \'virtual\', ?0)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => Robotters::class,
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 322,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'NULL',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some robot',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1945',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robotters::class . ' VALUES (NULL, \'some robot\', 1945)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => strtolower(Robotters::class),
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 322,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'NULL',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some robot',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1945',
                            ),
                        ),
                    ),
                );
                $query = new Query('insert into ' . strtolower(Robotters::class) . ' values (null, \'some robot\', 1945)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => Robotters::class,
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 356,
                            'value' => array(
                                'type' => 'parentheses',
                                'left' => array(
                                    'type' => 'binary-op',
                                    'op' => '*',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '+',
                                        'left' => array(
                                            'type' => 'literal',
                                            'value' => '1',
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '1000',
                                        ),
                                    ),
                                    'right' => array(
                                        'type' => 'placeholder',
                                        'value' => ':le_id',
                                    ),
                                ),
                            ),
                        ),
                        array(
                            'type' => 350,
                            'value' => array(
                                'type' => 'functionCall',
                                'name' => 'CONCAT',
                                'arguments' => array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '\'some\'',
                                    ),
                                    array(
                                        'type' => 'literal',
                                        'value' => '\'robot\'',
                                    ),
                                ),
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '2011',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robotters::class . ' VALUES ((1+1000*:le_id:), CONCAT(\'some\', \'robot\'), 2011)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => Robotters::class,
                    'table' => 'robots',
                    'fields' => array(
                        'theName',
                        'theType',
                        'theYear',
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'a name',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'virtual',
                            ),
                        ),
                        array(
                            'type' => 273,
                            'value' => array(
                                'type' => 'placeholder',
                                'value' => ':0',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robotters::class . ' (theName, theType, theYear) VALUES (\'a name\', \'virtual\', ?0)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);
            }
        );
    }

    public function testUpdateParsing()
    {
        $this->specify(
            "UPDATE PHQL queries don't work as expected",
            function () {
                $expected = array(
                    'tables' => array(
                        'robots',
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' SET name = \'some name\'');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        'robots',
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' SET ' . Robots::class . '.name = \'some name\'');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        'le_products',
                    ),
                    'models' => array(
                        SomeProducts::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'le_products',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . SomeProducts::class . ' SET ' . SomeProducts::class . '.name = "some name"');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'le_products',
                            null,
                            'p',
                        ),
                    ),
                    'models' => array(
                        SomeProducts::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'p',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . SomeProducts::class . ' p SET p.name = "some name"');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        'robots',
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'year',
                            'balias' => 'year',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1990',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' SET ' . Robots::class . '.name = \'some name\', ' . Robots::class . '.year = 1990');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'le_products',
                            null,
                            'p',
                        ),
                    ),
                    'models' => array(
                        SomeProducts::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'p',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                        array(
                            'type' => 'qualified',
                            'domain' => 'p',
                            'name' => 'year',
                            'balias' => 'year',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1990',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . SomeProducts::class . ' p SET p.name = "some name", p.year = 1990');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        'robots',
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'year',
                            'balias' => 'year',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                        array(
                            'type' => 43,
                            'value' => array(
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'YEAR',
                                    'arguments' => array(
                                        array(
                                            'type' => 'functionCall',
                                            'name' => 'current_date',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'year',
                                    'balias' => 'year',
                                ),
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' SET ' . Robots::class . '.name = \'some name\', ' . Robots::class . '.year = YEAR(current_date()) + ' . Robots::class . '.year');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'year',
                            'balias' => 'year',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                        array(
                            'type' => 43,
                            'value' => array(
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'YEAR',
                                    'arguments' => array(
                                        array(
                                            'type' => 'functionCall',
                                            'name' => 'current_date',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'year',
                                    'balias' => 'year',
                                ),
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' AS r SET r.name = \'some name\', r.year = YEAR(current_date()) + r.year');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' AS r SET r.name = \'some name\' WHERE r.id > 100');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'year',
                            'balias' => 'year',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                        array(
                            'type' => 42,
                            'value' => array(
                                'type' => 'binary-op',
                                'op' => '*',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'year',
                                    'balias' => 'year',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '2',
                                ),
                            ),
                        ),
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '<=',
                        'left' => array(
                            'type' => 'binary-op',
                            'op' => '>',
                            'left' => array(
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'id',
                            ),
                            'right' => array(
                                'type' => 'binary-op',
                                'op' => 'AND',
                                'left' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                                'right' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                            ),
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '200',
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' as r set r.name = \'some name\', r.year = r.year*2 where r.id > 100 and r.id <= 200');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        strtolower(Robots::class),
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'literal',
                            'value' => '10',
                        ),
                    ),
                );
                $query = new Query('update ' . strtolower(Robots::class) . ' as r set r.name = \'some name\' LIMIT 10');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'literal',
                            'value' => '10',
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' r SET r.name = \'some name\' LIMIT 10');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'literal',
                            'value' => '10',
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' AS r SET r.name = \'some name\' WHERE r.id > 100 LIMIT 10');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                // Issue 1011
                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'placeholder',
                            'value' => ':1',
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' r SET r.name = \'some name\' LIMIT ?1');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);
            }
        );
    }

    public function testDeleteParsing()
    {
        $this->specify(
            "DELETE PHQL queries don't work as expected",
            function () {
                $expected = array(
                    'tables' => array(
                        'robots',
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class);
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' AS r WHERE r.id > 100');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' r WHERE r.id > 100');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' as r WHERE r.id > 100');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'literal',
                            'value' => '10',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' r LIMIT 10');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'literal',
                            'value' => '10',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' r WHERE r.id > 100 LIMIT 10');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                // Issue 1011
                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'placeholder',
                            'value' => ':limit',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' r WHERE r.id > 100 LIMIT :limit:');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);
            }
        );
    }
}
