<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Codeception\Example;
use Phalcon\Support\Helper\Str\Decrement;
use UnitTester;

/**
 * Class DecrementCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class DecrementCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: decrement() - string
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrDecrement(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - decrement()');

        $object   = new Decrement();
        $expected = $example['expected'];
        $actual   = $object($example['source'], $example['separator']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    protected function getExamples()
    {
        return [
            ['source' => "file_2", 'expected' => "file_1", "separator" => "_"],
            ['source' => "file_1", 'expected' => "file", "separator" => "_"],
            ['source' => "file_3", 'expected' => "file_2", "separator" => "_"],
            ['source' => "file _1", 'expected' => "file ", "separator" => "_"],
            ['source' => "file-1", 'expected' => "file", "separator" => "-"],
        ];
    }
}
