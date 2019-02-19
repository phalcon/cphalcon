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
 * Class IsWritableCest
 */
class IsWritableCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: isWritable()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-10
     */
    public function httpMessageStreamIsWritable(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Stream - isWritable() - ' . $example[0]);
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $stream   = new Stream($fileName, $example[0]);
        $I->assertEquals($example[1], $stream->isWritable());
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: isWritable() - with "x"
     *
     * @dataProvider getExamplesX
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-10
     */
    public function httpMessageStreamIsWritableWithX(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Stream - isWritable() with "x" - ' . $example[0]);
        $fileName = $I->getNewFileName();
        $fileName = outputFolder('tests/stream/' . $fileName);
        $stream   = new Stream($fileName, $example[0]);
        $I->assertEquals($example[1], $stream->isWritable());
    }

    /**
     * @return array
     */
    private function getExamplesX(): array
    {
        return [
            ['x', true],
            ['x+', true],
        ];
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            ['a', true],
            ['a+', true],
            ['c', true],
            ['c+', true],
            ['r', false],
            ['r+', true],
            ['w', true],
            ['w+', true],
        ];
    }
}
