<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\Stream;

use Codeception\Example;
use Phalcon\Http\Message\Stream;
use UnitTester;

/**
 * Class IsSeekableCest
 */
class IsSeekableCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: isSeekable()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamIsSeekable(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Stream - isSeekable() - ' . $example[0]);
        $fileName = $I->getNewFileName();
        $fileName = outputFolder('/tests/logs/' . $fileName);

        $stream = new Stream($fileName, $example[0]);
        $I->assertEquals($example[1], $stream->isSeekable());
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
//            ['r',  true],
//            ['r+', true],
            ['w',  true],
            ['w+', true],
            ['a',  true],
            ['a+', true],
            ['x',  true],
            ['x+', true],
            ['c',  true],
            ['c+', true],
        ];
    }
}
