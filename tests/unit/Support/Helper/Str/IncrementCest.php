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
use Phalcon\Support\Helper\Str\Increment;
use UnitTester;

/**
 * Class IncrementCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class IncrementCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: increment()
     *
     * @dataProvider strProvider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrIncrementSimpleString(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - increment()');

        $object   = new Increment();
        $expected = $example['expected'];
        $actual   = $object($example['source'], $example['separator']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    protected function strProvider()
    {
        return [
            ['source' => "file", 'expected' => "file_1", "separator" => "_"],
            ['source' => "file_1", 'expected' => "file_2", "separator" => "_"],
            ['source' => "file_2", 'expected' => "file_3", "separator" => "_"],
            ['source' => "file_", 'expected' => "file_1", "separator" => "_"],
            ['source' => "file ", 'expected' => "file _1", "separator" => "_"],
            ['source' => "file", 'expected' => "file-1", "separator" => "-"],
        ];
    }
}
