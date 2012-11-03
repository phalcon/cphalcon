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
        $count = Personnes::count();
        $this->assertEquals($count, 2180, 'Count is incorrect');

    }

    public function testAll()
    {
        $rowcount = Personnes::count(array('distinct' => 'estado'));
        $this->assertEquals($rowcount, 2);

        $rowcount = Personnes::count("estado='A'");
        $this->assertEquals($rowcount, 2178);

        $group = Personnes::count(array("group" => "estado"));
        $this->assertEquals(2, count($group));

        $group = Personnes::count(array("group" => "estado", "order" => "estado"));
        $this->assertEquals(2, count($group));

        $results = array('A' => 2178, 'I' => 2);
        foreach($group as $row){
            $this->assertEquals($results[$row->estado], $row->rowcount);
        }

        $this->assertEquals($group[0]->rowcount, 2178);
        $this->assertEquals($group[1]->rowcount, 2);

        $group = Personnes::count(array("group" => "estado"));
        $this->assertEquals(2, count($group));

        $group = Personnes::count(array("group" => "ciudad_id"));
        $this->assertEquals(285, count($group));

        $group = Personnes::count(array("group" => "ciudad_id", "order" => "rowcount DESC"));
        $this->assertEquals($group[0]->rowcount, 727);

        //Summatory
        $total = Personnes::sum(array("column" => "cupo"));
        $this->assertEquals(995066020.00, $total);

        $total = Personnes::sum(array("column" => "cupo", "conditions" => "estado='I'"));
        $this->assertEquals(567020.00, $total);

        $group = Personnes::sum(array("column" => "cupo", "group" => "estado"));
        $this->assertEquals(2, count($group));

        $results = array('A' => 994499000.00, 'I' => 567020.00);
        foreach($group as $row){
            $this->assertEquals($results[$row->estado], $row->sumatory);
        }

        $group = Personnes::sum(array("column" => "cupo", "group" => "ciudad_id", "order" => "sumatory DESC"));
        $this->assertEquals($group[0]->sumatory, 358467690.00);

        //Average
        $total = Personnes::average(array("column" => "cupo"));
        $this->assertEquals(456452.30, sprintf("%.2f", $total));

        $total = Personnes::average(array("column" => "cupo", "conditions" => "estado='I'"));
        $this->assertEquals(283510.00, $total);

        $group = Personnes::average(array("column" => "cupo", "group" => "estado"));
        $this->assertEquals(2, count($group));

        $results = array('A' => 456611.11, 'I' => 283510.00);
        foreach($group as $row){
            $this->assertEquals($results[$row->estado], sprintf("%.2f", $row->average));
        }

        $group = Personnes::average(array("column" => "cupo", "group" => "ciudad_id", "order" => "average DESC"));
        $this->assertEquals($group[0]->average, 996200.00);

        //Maximum
        $max = Personnes::maximum(array("column" => "ciudad_id"));
        $this->assertEquals($max, 302172);

        $max = Personnes::maximum(array("column" => "ciudad_id", "conditions" => "estado='I'"));
        $this->assertEquals($max, 127591);

        $group = Personnes::maximum(array("column" => "ciudad_id", "group" => "estado"));
        $this->assertEquals(2, count($group));

        $results = array('A' => 302172, 'I' => 127591);
        foreach($group as $row){
            $this->assertEquals($results[$row->estado], $row->maximum);
        }

        $group = Personnes::maximum(array("column" => "ciudad_id", "group" => "estado", "order" => "maximum DESC"));
        $this->assertEquals($group[0]->maximum, 302172);

        //Minimum
        $max = Personnes::minimum(array("column" => "ciudad_id"));
        $this->assertEquals($max, 20404);

        $max = Personnes::minimum(array("column" => "ciudad_id", "conditions" => "estado='I'"));
        $this->assertEquals($max, 127591);

        $group = Personnes::minimum(array("column" => "ciudad_id", "group" => "estado"));
        $this->assertEquals(2, count($group));

        $results = array('A' => 20404, 'I' => 127591);
        foreach($group as $row){
            $this->assertEquals($results[$row->estado], $row->minimum);
        }

        $group = Personnes::minimum(array("column" => "ciudad_id", "group" => "estado", "order" => "minimum DESC"));
        $this->assertEquals($group[0]->minimum, 127591);

        $group = Personnes::minimum(array("column" => "ciudad_id", "group" => "estado", "order" => "minimum ASC"));
        $this->assertEquals($group[0]->minimum, 20404);

    }
}