<?php
/**
 * Model.php
 * Mvc_Model_Calculation_Helper_Model
 *
 * Helper for the \Phalcon\Mvc\Model calculations
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

class Mvc_Model_Calculation_Helper_Model extends Phalcon_Test_ModelTestCase
{
    /**
     * Sets the environment for this test suite
     *
     * @return Phalcon\DI|void
     */
    public function setUp()
    {
        parent::setUp();

        // Setup the table with 120 records
        $this->populateTable('customers', 120);
    }

    /**
     * Destructor
     */
    public function tearDown()
    {
        $this->emptyTable('customers');

        parent::tearDown();
    }

    /**
     * Tests the count on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testCount()
    {
        $expected = 120;
        $actual   = Customers::count();

        $this->assertEquals($expected, $actual,'Count is incorrect');
    }

    /**
     * Tests the count distinct on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testCountDistinct()
    {
        $expected = 2;
        $actual   = Customers::count(array('distinct' => 'status'));

        $this->assertEquals($expected, $actual,'Count distinct is incorrect');
    }

    /**
     * Tests the count with where on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testCountWhere()
    {
        $expected = 60;
        $actual   = Customers::count(array("status = 'A'"));

        $this->assertEquals($expected, $actual,'Count with where is incorrect');
    }

    /**
     * Tests the count with group on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testCountGroup()
    {
        $expected = 5;
        $actual   = Customers::count(array('group' => 'customer_id'));

        $this->assertEquals(
            $expected,
            count($actual),
            'Count with group is incorrect'
        );
    }

    /**
     * Tests the count with group and order on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testCountGroupOrder()
    {
        $results  = Customers::count(
                        array(
                            'group' => 'status',
                            'order' => 'status'
                        )
        );

        $expected = 2;
        $actual   = count($results);

        $this->assertEquals(
            $expected,
            $actual,
            'Count with group order is incorrect'
        );

        $expected = 60;
        $actual   = $results[0]->rowcount;

        $this->assertEquals(
            $expected,
            $actual,
            'Count with group order status (key) is incorrect'
        );

        $expected = 60;
        $actual   = $results[1]->rowcount;

        $this->assertEquals(
            $expected,
            $actual,
            'Count with group order status (key) is incorrect'
        );
    }

    /**
     * Tests the count with group and order on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testCountGroupOrderRowcount()
    {
        $results  = Customers::count(
                        array(
                            'group' => 'customer_id',
                            'order' => 'rowcount DESC'
                        )
        );

        $expected = 5;
        $actual   = count($results);

        $this->assertEquals(
            $expected,
            $actual,
            'Count with group order is incorrect'
        );

        $expected = 24;
        $actual   = $results[0]->rowcount;

        $this->assertEquals(
            $expected,
            $actual,
            'Count with group order status (key) is incorrect'
        );
    }

    /**
     * Tests the sumatory on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testSumatory()
    {
        $this->_countable('sum', 960.00);
    }

    /**
     * Tests the sumatory with conditions on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testSumatoryWithConditions()
    {
        $this->_countableWithConditions('sum', 630.00);
    }

    /**
     * Tests the sumatory with conditions on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testSumatoryGroup()
    {
        $this->_countableGroup('sum', 'sumatory', 2, 630.00, 330.00);
    }

    /**
     * Tests the sumatory group order on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testSumatoryGroupOrderSumatory()
    {
        $this->_countableGroupOrder('sum', 'sumatory', 192.00);
    }

    /**
     * Tests the average on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testAverage()
    {
        $this->_countable('average', 8.00);
    }

    /**
     * Tests the average with conditions on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testAverageWithConditions()
    {
        $this->_countableWithConditions('average', 10.50);
    }

    /**
     * Tests the average with conditions on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testAverageGroup()
    {
        $this->_countableGroup('average', 'average', 2, 10.50, 5.50);
    }

    /**
     * Tests the average group order on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testAverageGroupOrderAverage()
    {
        $this->_countableGroupOrder('average', 'average', 8.00);
    }

    /**
     * Tests the maximum on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testMaximum()
    {
        $this->_countable('maximum', 10.50);
    }

    /**
     * Tests the maximum with conditions on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testMaximumWithConditions()
    {
        $this->_countableWithConditions('maximum', 10.50);
    }

    /**
     * Tests the maximum with conditions on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testMaximumGroup()
    {
        $this->_countableGroup('maximum', 'maximum', 2, 10.50, 5.50);
    }

    /**
     * Tests the maximum group order on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testMaximumGroupOrderMaximum()
    {
        $this->_countableGroupOrder('maximum', 'maximum', 10.50);
    }

    /**
     * Tests the minimum on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testMinimum()
    {
        $this->_countable('minimum', 5.50);
    }

    /**
     * Tests the minimum with conditions on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testMinimumWithConditions()
    {
        $this->_countableWithConditions('minimum', 10.50);
    }

    /**
     * Tests the minimum with conditions on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testMinimumGroup()
    {
        $this->_countableGroup('minimum', 'minimum', 2, 10.50, 5.50);
    }

    /**
     * Tests the minimum group order on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testMinimumGroupOrderMinimum()
    {
        $this->_countableGroupOrder('minimum', 'minimum', 5.50);
    }


    /**
     * Private helper to test a countable on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    private function _countable($function, $expected)
    {
        $pFunc    = ucfirst($function);
        $actual   = Customers::$function(
            array('column' => 'credit_line')
        );

        $this->assertEquals($expected, $actual, $pFunc . ' incorrect');
    }

    /**
     * Private helper to test a countable with conditions on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    private function _countableWithConditions($function, $expected)
    {
        $pFunc    = ucfirst($function);
        $actual   = Customers::$function(
            array(
                'column'     => 'credit_line',
                'conditions' => "status = 'A'",
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            $pFunc . ' with conditions incorrect'
        );
    }

    /**
     * Private helper to test a countable group on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    private function _countableGroup($function, $condition, $avg_one, $avg_two, $avg_three)
    {
        $pFunc    = ucfirst($function);
        $results  = Customers::$function(
            array(
                'column' => 'credit_line',
                'group'  => 'status',
            )
        );

        $actual = count($results);

        $this->assertEquals(
            $avg_one,
            $actual,
            $pFunc . ' with group incorrect'
        );

        $actual = $results[0]->$condition;

        $this->assertEquals(
            $avg_two,
            $actual,
            'Average with group (key) incorrect'
        );

        $actual   = $results[1]->$condition;

        $this->assertEquals(
            $avg_three,
            $actual,
            'Average with group (key) incorrect'
        );
    }

    /**
     * Private helper to test a countable group order on a model
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    private function _countableGroupOrder($function, $condition, $expected)
    {
        $pFunc    = ucfirst($function);
        $results  = Customers::$function(
            array(
                'column' => 'credit_line',
                'group'  => 'customer_id',
                'order'  => $condition . ' DESC',
            )
        );

        $actual   = $results[0]->$condition;

        $this->assertEquals(
            $expected,
            $actual,
            $pFunc . ' with group (key) order sumatory incorrect'
        );
    }

}