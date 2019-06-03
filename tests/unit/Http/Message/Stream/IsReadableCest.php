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
use function logsDir;
use UnitTester;

class IsReadableCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: isReadable()
     *
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since        2019-02-10
     */
    public function httpMessageStreamIsReadable(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Stream - isReadable() - ' . $example[0]);

        $fileName = dataDir('assets/stream/bill-of-rights-empty.txt');

        $stream = new Stream($fileName, $example[0]);

        $I->assertEquals(
            $example[1],
            $stream->isReadable()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: isReadable() - with "x"
     *
     * @dataProvider getExamplesX
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since        2019-02-10
     */
    public function httpMessageStreamIsReadableWithX(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Stream - isReadable() with "x" - ' . $example[0]);

        $fileName = $I->getNewFileName();
        $fileName = logsDir($fileName);

        $stream = new Stream($fileName, $example[0]);

        $I->assertEquals(
            $example[1],
            $stream->isReadable()
        );
    }

    private function getExamplesX(): array
    {
        return [
            ['w', false],
            ['wb', false],
            ['w+', true],
            ['w+b', true],
            ['x', false],
            ['xb', false],
            ['x+', true],
            ['x+b', true],
        ];
    }

    private function getExamples(): array
    {
        return [
            ['a', false],
            ['ab', false],
            ['a+', true],
            ['a+b', true],
            ['c', false],
            ['cb', false],
            ['c+', true],
            ['c+b', true],
            ['r', true],
            ['rb', true],
            ['r+', true],
            ['r+b', true],
        ];
    }
}
