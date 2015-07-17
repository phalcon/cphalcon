<?php
/**
 * TranslateIndexedArrayReplacerTest.php
 * \Phalcon\Translate\Replacer\IndexedArray
 *
 * Tests the \Phalcon\Translate\Replacer\IndexedArray component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Translate\Interpolator;

use Phalcon\Translate\Adapter\NativeArray as PhTTranslateAdapterNativeArray;
use Phalcon\Translate\Interpolator\IndexedArray;
use \Codeception\TestCase\Test as CdTest;
use \Codeception\Specify as CdSpecify;

class TranslateIndexedArrayInterpolatorTest extends CdTest
{
	use CdSpecify;

	private $config = null;

	/**
	 * Initialize data for the tests
	 */
	public function _before()
	{
		$this->config = [
			'ru' => [
				'Hello!'          => 'Привет!',
				'Hello %s %s %s!' => 'Привет, %s %s %s!',
			],
		];
	}

	public function testIndexedArrayInterpolator()
	{
		$this->specify(
			"Translator with IndexedArray interpolator",
			function () {

				$language   = $this->config['ru'];
				$params	 = ['content' => $language, 'interpolator' => new IndexedArray()];
				$translator = new PhTTranslateAdapterNativeArray($params);

				$expected = 'Привет, John D. Doe!';
				$actual = $translator->_(
					'Hello %s %s %s!',
					[
						'John',
						'D.',
						'Doe',
					]
				);
				expect($actual)->equals($expected);
			}
		);
	}
}
