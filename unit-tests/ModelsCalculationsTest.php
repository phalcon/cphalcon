<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

use PHPUnit\Framework\TestCase;

class ModelsCalculationsTest extends TestCase
{
	public function setUp()
	{
		spl_autoload_register(array($this, 'modelsAutoloader'));
	}

	public function tearDown()
	{
		spl_autoload_unregister(array($this, 'modelsAutoloader'));
	}

	public function modelsAutoloader($className)
	{
		if (file_exists('unit-tests/models/'.$className.'.php')) {
			require 'unit-tests/models/'.$className.'.php';
		}
	}

	protected function _getDI()
	{

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		return $di;
	}

	/**
	 * @medium
	 */
	public function testCalculationsMysql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		$this->_executeTestsNormal();
		$this->_executeTestsRenamed();

	}

	/**
	 * @medium
	 */
	public function testCalculationsPostgresql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configPostgresql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		}, true);

		$this->_executeTestsNormal(
		    2196,
            2194,
            995386020.00,
            994819000.00,
            453272.32,
            453427.07
        );
		$this->_executeTestsRenamed(
            2196,
            2194,
            995386020.00,
            994819000.00,
            453272.32,
            453427.07
        );

	}

	/**
	 * @medium
	 */
	public function testCalculationsSqlite()
	{
		require 'unit-tests/config.db.php';
		if (empty($configSqlite)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
		}, true);

		$this->_executeTestsNormal();
		$this->_executeTestsRenamed();
	}

	protected function _executeTestsNormal(
        $total_rows = 2180,
        $estado_rows = 2178,
        $cupo_sum = 995066020.00,
        $a_sum = 994499000.00,
        $cupo_average = 456452.30,
        $a_average = 456611.11
    ) {

		//Count calculations
		$rowcount = Personnes::count();
		$this->assertEquals($rowcount, $total_rows);

		$rowcount = Personnes::count(array('distinct' => 'estado'));
		$this->assertEquals($rowcount, 2);

		$rowcount = Personnes::count("estado='A'");
		$this->assertEquals($rowcount, $estado_rows);

		$group = Personnes::count(array("group" => "estado"));
		$this->assertEquals(2, count($group));

		$group = Personnes::count(array("group" => "estado", "order" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => $estado_rows, 'I' => 2);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], $row->rowcount);
		}

		$this->assertEquals($group[0]->rowcount, $estado_rows);
		$this->assertEquals($group[1]->rowcount, 2);

		$group = Personnes::count(array("group" => "estado"));
		$this->assertEquals(2, count($group));

		$group = Personnes::count(array("group" => "ciudad_id"));
		$this->assertEquals(285, count($group));

		$group = Personnes::count(array("group" => "ciudad_id", "order" => "rowcount DESC"));
		$this->assertEquals($group[0]->rowcount, 727);

		//Summatory
		$total = Personnes::sum(array("column" => "cupo"));
		$this->assertEquals($cupo_sum, $total);

		$total = Personnes::sum(array("column" => "cupo", "conditions" => "estado='I'"));
		$this->assertEquals(567020.00, $total);

		$group = Personnes::sum(array("column" => "cupo", "group" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => $a_sum, 'I' => 567020.00);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], $row->sumatory);
		}

		$group = Personnes::sum(array("column" => "cupo", "group" => "ciudad_id", "order" => "sumatory DESC"));
		$this->assertEquals($group[0]->sumatory, 358467690.00);

		//Average
		$total = Personnes::average(array("column" => "cupo"));
		$this->assertEquals($cupo_average, sprintf("%.2f", $total));

		$total = Personnes::average(array("column" => "cupo", "conditions" => "estado='I'"));
		$this->assertEquals(283510.00, $total);

		$group = Personnes::average(array("column" => "cupo", "group" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => $a_average, 'I' => 283510.00);
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

	protected function _executeTestsRenamed(
	    $total_rows = 2180,
        $estado_rows = 2178,
        $cupo_sum = 995066020.00,
        $a_sum = 994499000.00,
        $cupo_average = 456452.30,
        $a_average = 456611.11
    ) {

		//Count calculations
		$rowcount = Pessoas::count();
		$this->assertEquals($rowcount, $total_rows);

		$rowcount = Pessoas::count(array('distinct' => 'estado'));
		$this->assertEquals($rowcount, 2);

		$rowcount = Pessoas::count("estado='A'");
		$this->assertEquals($rowcount, $estado_rows);

		$group = Pessoas::count(array("group" => "estado"));
		$this->assertEquals(2, count($group));

		$group = Pessoas::count(array("group" => "estado", "order" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => $estado_rows, 'I' => 2);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], $row->rowcount);
		}

		$this->assertEquals($group[0]->rowcount, $estado_rows);
		$this->assertEquals($group[1]->rowcount, 2);

		$group = Pessoas::count(array("group" => "estado"));
		$this->assertEquals(2, count($group));

		$group = Pessoas::count(array("group" => "cidadeId"));
		$this->assertEquals(285, count($group));

		$group = Pessoas::count(array("group" => "cidadeId", "order" => "rowcount DESC"));
		$this->assertEquals($group[0]->rowcount, 727);

		//Summatory
		$total = Pessoas::sum(array("column" => "credito"));
		$this->assertEquals($cupo_sum, $total);

		$total = Pessoas::sum(array("column" => "credito", "conditions" => "estado='I'"));
		$this->assertEquals(567020.00, $total);

		$group = Pessoas::sum(array("column" => "credito", "group" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => $a_sum, 'I' => 567020.00);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], $row->sumatory);
		}

		$group = Pessoas::sum(array("column" => "credito", "group" => "cidadeId", "order" => "sumatory DESC"));
		$this->assertEquals($group[0]->sumatory, 358467690.00);

		//Average
		$total = Pessoas::average(array("column" => "credito"));
		$this->assertEquals($cupo_average, sprintf("%.2f", $total));

		$total = Pessoas::average(array("column" => "credito", "conditions" => "estado='I'"));
		$this->assertEquals(283510.00, $total);

		$group = Pessoas::average(array("column" => "credito", "group" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => $a_average, 'I' => 283510.00);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], sprintf("%.2f", $row->average));
		}

		$group = Pessoas::average(array("column" => "credito", "group" => "cidadeId", "order" => "average DESC"));
		$this->assertEquals($group[0]->average, 996200.00);

		//Maximum
		$max = Pessoas::maximum(array("column" => "cidadeId"));
		$this->assertEquals($max, 302172);

		$max = Pessoas::maximum(array("column" => "cidadeId", "conditions" => "estado='I'"));
		$this->assertEquals($max, 127591);

		$group = Pessoas::maximum(array("column" => "cidadeId", "group" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => 302172, 'I' => 127591);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], $row->maximum);
		}

		$group = Pessoas::maximum(array("column" => "cidadeId", "group" => "estado", "order" => "maximum DESC"));
		$this->assertEquals($group[0]->maximum, 302172);

		//Minimum
		$max = Pessoas::minimum(array("column" => "cidadeId"));
		$this->assertEquals($max, 20404);

		$max = Pessoas::minimum(array("column" => "cidadeId", "conditions" => "estado='I'"));
		$this->assertEquals($max, 127591);

		$group = Pessoas::minimum(array("column" => "cidadeId", "group" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => 20404, 'I' => 127591);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], $row->minimum);
		}

		$group = Pessoas::minimum(array("column" => "cidadeId", "group" => "estado", "order" => "minimum DESC"));
		$this->assertEquals($group[0]->minimum, 127591);

		$group = Pessoas::minimum(array("column" => "cidadeId", "group" => "estado", "order" => "minimum ASC"));
		$this->assertEquals($group[0]->minimum, 20404);

	}


}
