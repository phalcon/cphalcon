<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Unit;

use Phalcon\Test\Module\UnitTest;
use Codeception\Specify;
use Codeception\TestCase\Test;
use Phalcon\IteratorAware;
use ArrayIterator;
use UnitTester;

/**
 * Phalcon\Test\Unit\IteratorAwareTest
 *
 * Tests the Phalcon\IteratorAware component
 *
 * @package   Phalcon\Test\Unit
 */
class IteratorAwareTest extends UnitTest
{
    use Specify;

    /**
     * UnitTester Object
     * @var UnitTester
     */
    protected $tester;

    /**
     * Tests ArrayUtils::iteratorToArray. Test catching an exception.
     *
     * @expectedException \Exception
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-10-04
     */
    public function shouldCatchAnException()
    {
        $iteratorAware = new IteratorAware();

        $this->specify(
            "Method should return an exception",
            function ($data) use ($iteratorAware) {
                $iteratorAware->iteratorToArray($data);
            },
            [
                'examples' => [
                    ['fooBar'],
                    [123456],
                    [true],
                ]
            ]
        );
    }

    /**
     * Tests ArrayUtils::iteratorToArray. Testing array without recursion.
     *
     * @dataProvider providerArray
     * @param array $array
     * @param array $array
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-10-04
     */
    public function shouldReturnArrayFromArrayWithoutRecursing($array, $expected)
    {
        $iteratorAware = new IteratorAware();

        $this->assertEquals(
            $expected,
            $iteratorAware->iteratorToArray($array, false),
            'Arrays are different'
        );
    }

    /**
     * Tests ArrayUtils::iteratorToArray. Testing iterator without recursion.
     * @param array $array
     * @param array $array
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-10-04
     */
    public function shouldReturnArrayIteratorArrayWithoutRecursing()
    {
        $iteratorAware = new IteratorAware();

        $this->specify(
            'test',
            function ($array, $expected) use ($iteratorAware) {
                $iterator = new ArrayIterator($array);

                expect($iteratorAware->iteratorToArray($iterator, false))->equals($expected);
            },
            [
                'examples' => [
                    [
                        [
                            0 =>'foo',
                            1 => 'bar',
                            2 => new ArrayIterator(['test'])
                        ],
                        [
                            0 =>'foo',
                            1 => 'bar',
                            2 => new ArrayIterator(['test'])
                        ]
                    ],
                ]
            ]
        );
    }

    /**
     * Tests ArrayUtils::iteratorToArray. Testing array.
     *
     * @dataProvider providerArray
     * @param array $array
     * @param array $array
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-10-04
     */
    public function shouldReturnArrayFromArray($array, $expected)
    {
        $iteratorAware = new IteratorAware();

        $this->assertEquals(
            $expected,
            $iteratorAware->iteratorToArray($array, true),
            'Arrays are different'
        );
    }

    /**
     * Tests ArrayUtils::iteratorToArray. Testing iterator.
     *
     * @dataProvider providerArray
     * @param array $array
     * @param array $array
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-10-04
     */
    public function shouldReturnArrayFromIterator($array, $expected)
    {
        $iteratorAware = new IteratorAware();
        $iterator = new ArrayIterator($array);

        $this->assertEquals(
            $expected,
            $iteratorAware->iteratorToArray($iterator, true),
            'Arrays are different'
        );
    }

    public function providerArray()
    {
        return require PATH_FIXTURES . 'IteratorAware/array_utils.php';
    }
}
