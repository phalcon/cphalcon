<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\Test\Models\Statistics;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\Model\ResultsetClassTest
 * Tests the Phalcon\Mvc\Model::getResultsetClass() component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Eugene Smirnov <ashpumpkin@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ResultsetClassTest extends UnitTest
{
	/**
	 * Checks if resultset class Simple is returned when getResultsetClass() mmethod is not defined
	 *
	 * @author Eugene Smirnov <ashpumpkin@gmail.com>
	 */
	public function testDefaultResultsetClass()
	{
		$this->specify(
			'Find() method should return the default resultset simple class if getResultsetClass() method is not presented in the model',
			function () {
				expect(Statistics\CityStats::find())->isInstanceOf('Phalcon\Mvc\Model\Resultset\Simple');
			}
		);
	}

	/**
	 * Checks if custom resultset object is returned when getResultsetClass() method is presented in model
	 *
	 * @author Eugene Smirnov <ashpumpkin@gmail.com>
	 */
	public function testCustomClassForResultset()
	{
		$this->specify(
			'Find() method should return custom resultset if getResultsetClass() method is presented in model',
			function () {
				expect(Statistics\AgeStats::find())->isInstanceOf('Phalcon\Test\Resultsets\Stats');
			}
		);
	}

	/**
	 * Checks if exception is thrown when custom resultset doesn\'t implement ResultsetInterface
	 *
	 * @author Eugene Smirnov <ashpumpkin@gmail.com>
	 */
	public function testExceptionOnBadInterface()
	{
		$this->specify(
			'Find() method should throw an exception if resultset doesn\'t implement interface',
			function () {
				Statistics\CountryStats::find();
			},
			['throws' => [
				'Phalcon\Mvc\Model\Exception',
				'Resultset class "Phalcon\Test\Models\Statistics\AgeStats" must be an implementation of Phalcon\Mvc\Model\ResultsetInterface'
			]]
		);
	}

	/**
	 * Checks if exception is thrown when resultset class doesn\'t exist
	 *
	 * @author Eugene Smirnov <ashpumpkin@gmail.com>
	 */
	public function testExceptionOnUnknownClass()
	{
		$this->specify(
			'Find() method should throw an exception if resultset class doesn\'t exist',
			function () {
				Statistics\GenderStats::find();
			},
			['throws' => [
				'Phalcon\Mvc\Model\Exception',
				'Resultset class "Not\Existing\Resultset\Class" not found'
			]]
		);
	}

}