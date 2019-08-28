<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test;


use Codeception\Test\Unit;
use Phalcon\Environment;
use UnitTester;

class EnvironmentTest extends Unit
{
    /** @var Environment  */
    private $testSubject = null;

    /** @var UnitTester */
    protected $tester;

    public function _before()
    {
        $this->testSubject = new Environment();
    }

    public function _after()
    {
        putenv('SOME_RANDOM_VALUE');
    }

    public function testDefaultValue()
    {
        $this->assertEquals(
            'blah',
            $this->testSubject->getValue('SOME_RANDOM_VALUE', 'blah')
        );
    }

    /**
     * @param $envValue
     * @param $expectedValue
     * @dataProvider _dpTestParseValues
     */
    public function testParseValues($envValue, $expectedValue)
    {
        putenv('SOME_RANDOM_VALUE=' . $envValue);

        $this->assertSame(
            $expectedValue,
            $this->testSubject->getValue('SOME_RANDOM_VALUE')
        );
    }

    public function _dpTestParseValues(): \Generator
    {
        yield 'Test Boolean - True - A' => [
            "true",
            true
        ];

        yield 'Test Boolean - True - B' => [
            "(true)",
            true
        ];

        yield 'Test Boolean - False - A' => [
            "false",
            false
        ];

        yield 'Test Boolean - False - B' => [
            "(false)",
            false
        ];

        yield 'Test Empty - A' => [
            "empty",
            ""
        ];

        yield 'Test Empty - B' => [
            "(empty)",
            ""
        ];

        yield 'Test Null - A' => [
            "null",
            null
        ];

        yield 'Test Null - B' => [
            "(null)",
            null
        ];

        yield 'Test Float' => [
            '1.2',
            1.2
        ];

        yield 'Test Alt Float' => [
            '1.0',
            1.0
        ];

        yield 'Test Integer' => [
            '1',
            1
        ];
    }
}
