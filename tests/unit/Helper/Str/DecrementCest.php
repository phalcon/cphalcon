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

class DecrementCest
{
    /**
     * Tests Phalcon\Helper\Str :: decrement() - string
     *
     * @author       Ruud Boon <https://github.com/ruudboon>
     * @since        2019-12-08
     * @dataProvider strProvider
     */
    public function helperStrDecrement(UnitTester $I, Example $example)
    {
        $I->wantToTest('Helper\Str - decrement()');
        $actual = Str::decrement($example['source'], $example['separator']);
        $I->assertEquals($example['expected'], $actual);
    }

    /**
     * @return array
     */
    protected function strProvider()
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
