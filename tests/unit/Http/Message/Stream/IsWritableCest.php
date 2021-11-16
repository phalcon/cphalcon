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

class IsWritableCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: isWritable()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-10
     */
    public function httpMessageStreamIsWritable(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Stream - isWritable() - ' . $example[0]);

        $fileName = dataDir('assets/stream/mit-empty.txt');

        $stream = new Stream($fileName, $example[0]);

        $I->assertEquals(
            $example[1],
            $stream->isWritable()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: isWritable() - with "x"
     *
     * @dataProvider getExamplesX
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-10
     */
    public function httpMessageStreamIsWritableWithX(UnitTester $I, Example $example)
    {
        $I->wantToTest(
            'Http\Message\Stream - isWritable() with "x" - ' . $example[0]
        );

        $fileName = $I->getNewFileName();
        $fileName = logsDir($fileName);

        $stream = new Stream($fileName, $example[0]);

        $I->assertEquals(
            $example[1],
            $stream->isWritable()
        );
    }

    private function getExamplesX(): array
    {
        return [
            ['w', true],
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
            ['r', false],
            ['rb', false],
            ['r+', true],
            ['r+b', true],
        ];
    }
}
