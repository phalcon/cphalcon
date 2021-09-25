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

namespace Phalcon\Tests\Unit\Helper\Str;

use Codeception\Example;
use Phalcon\Helper\Str;
use UnitTester;

class IncrementCest
{
    /**
     * Tests Phalcon\Helper\Str :: increment()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-04-06
     * @dataProvider strProvider
     */
    public function helperStrIncrementSimpleString(UnitTester $I, Example $example)
    {
        $I->wantToTest('Helper\Str - increment()');
        $actual = Str::increment($example['source'], $example['separator']);
        $I->assertEquals($example['expected'], $actual);
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
