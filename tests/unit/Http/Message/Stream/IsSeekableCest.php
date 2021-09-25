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

namespace Phalcon\Tests\Unit\Http\Message\Stream;

use Codeception\Example;
use Phalcon\Http\Message\Stream;
use UnitTester;

use function logsDir;

class IsSeekableCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: isSeekable()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-10
     */
    public function httpMessageStreamIsSeekable(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Stream - isSeekable() - ' . $example[0]);

        $fileName = dataDir('assets/stream/mit-empty.txt');

        $stream = new Stream($fileName, $example[0]);

        $I->assertEquals(
            $example[1],
            $stream->isSeekable()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: isSeekable() - with "x"
     *
     * @dataProvider getExamplesX
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-10
     */
    public function httpMessageStreamIsSeekableWithX(UnitTester $I, Example $example)
    {
        $I->wantToTest(
            'Http\Message\Stream - isSeekable() with "x" - ' . $example[0]
        );

        $fileName = $I->getNewFileName();
        $fileName = logsDir($fileName);

        $stream = new Stream($fileName, $example[0]);

        $I->assertEquals(
            $example[1],
            $stream->isSeekable()
        );
    }

    private function getExamplesX(): array
    {
        return [
            ['wb', true],
            ['w+', true],
            ['w+b', true],
            ['x', true],
            ['xb', true],
            ['x+', true],
            ['x+b', true],
        ];
    }

    private function getExamples(): array
    {
        return [
            ['a', true],
            ['ab', true],
            ['a+', true],
            ['a+b', true],
            ['c', true],
            ['cb', true],
            ['c+', true],
            ['c+b', true],
            ['r', true],
            ['rb', true],
            ['r+', true],
            ['r+b', true],
            ['w', true],
        ];
    }
}
