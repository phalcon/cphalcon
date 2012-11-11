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
    public function testCount()
    {
        $this->populateTable('customers', 120);
        
        $count = Customers::count();
        $this->assertEquals($count, 120, 'Count is incorrect');

    }

    public function testAll()
    {
        $this->populateTable('customers', 120);

        $rowcount = Customers::count(array('distinct' => 'status'));
        $this->assertEquals($rowcount, 2);

        $rowcount = Customers::count("status='A'");
        $this->assertEquals($rowcount, 2178);

        $group = Customers::count(array("group" => "status"));
        $this->assertEquals(2, count($group));

        $group = Customers::count(array("group" => "status", "order" => "status"));
        $this->assertEquals(2, count($group));

        $results = array('A' => 2178, 'I' => 2);
        foreach($group as $row){
            $this->assertEquals($results[$row->status], $row->rowcount);
        }

        $this->assertEquals($group[0]->rowcount, 2178);
        $this->assertEquals($group[1]->rowcount, 2);

        $group = Customers::count(array("group" => "status"));
        $this->assertEquals(2, count($group));

        $group = Customers::count(array("group" => "customer_id"));
        $this->assertEquals(285, count($group));

        $group = Customers::count(array("group" => "customer_id", "order" => "rowcount DESC"));
        $this->assertEquals($group[0]->rowcount, 727);

        //Summatory
        $total = Customers::sum(array("column" => "credit_line"));
        $this->assertEquals(995066020.00, $total);

        $total = Customers::sum(array("column" => "credit_line", "conditions" => "status='I'"));
        $this->assertEquals(567020.00, $total);

        $group = Customers::sum(array("column" => "credit_line", "group" => "status"));
        $this->assertEquals(2, count($group));

        $results = array('A' => 994499000.00, 'I' => 567020.00);
        foreach($group as $row){
            $this->assertEquals($results[$row->status], $row->sumatory);
        }

        $group = Customers::sum(array("column" => "credit_line", "group" => "customer_id", "order" => "sumatory DESC"));
        $this->assertEquals($group[0]->sumatory, 358467690.00);

        //Average
        $total = Customers::average(array("column" => "credit_line"));
        $this->assertEquals(456452.30, sprintf("%.2f", $total));

        $total = Customers::average(array("column" => "credit_line", "conditions" => "status='I'"));
        $this->assertEquals(283510.00, $total);

        $group = Customers::average(array("column" => "credit_line", "group" => "status"));
        $this->assertEquals(2, count($group));

        $results = array('A' => 456611.11, 'I' => 283510.00);
        foreach($group as $row){
            $this->assertEquals($results[$row->status], sprintf("%.2f", $row->average));
        }

        $group = Customers::average(array("column" => "credit_line", "group" => "customer_id", "order" => "average DESC"));
        $this->assertEquals($group[0]->average, 996200.00);

        //Maximum
        $max = Customers::maximum(array("column" => "customer_id"));
        $this->assertEquals($max, 302172);

        $max = Customers::maximum(array("column" => "customer_id", "conditions" => "status='I'"));
        $this->assertEquals($max, 127591);

        $group = Customers::maximum(array("column" => "customer_id", "group" => "status"));
        $this->assertEquals(2, count($group));

        $results = array('A' => 302172, 'I' => 127591);
        foreach($group as $row){
            $this->assertEquals($results[$row->status], $row->maximum);
        }

        $group = Customers::maximum(array("column" => "customer_id", "group" => "status", "order" => "maximum DESC"));
        $this->assertEquals($group[0]->maximum, 302172);

        //Minimum
        $max = Customers::minimum(array("column" => "customer_id"));
        $this->assertEquals($max, 20404);

        $max = Customers::minimum(array("column" => "customer_id", "conditions" => "status='I'"));
        $this->assertEquals($max, 127591);

        $group = Customers::minimum(array("column" => "customer_id", "group" => "status"));
        $this->assertEquals(2, count($group));

        $results = array('A' => 20404, 'I' => 127591);
        foreach($group as $row){
            $this->assertEquals($results[$row->status], $row->minimum);
        }

        $group = Customers::minimum(array("column" => "customer_id", "group" => "status", "order" => "minimum DESC"));
        $this->assertEquals($group[0]->minimum, 127591);

        $group = Customers::minimum(array("column" => "customer_id", "group" => "status", "order" => "minimum ASC"));
        $this->assertEquals($group[0]->minimum, 20404);

    }
}