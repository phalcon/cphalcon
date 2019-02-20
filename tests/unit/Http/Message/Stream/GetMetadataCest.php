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
 * Class GetMetadataCest
 */
class GetMetadataCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: getMetadata()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamGetMetadata(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - getMetadata()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $handle   = fopen($fileName, 'rb');
        $stream   = new Stream($handle);

        $expected = [
            'timed_out'    => false,
            'blocked'      => true,
            'eof'          => false,
            'wrapper_type' => 'plainfile',
            'stream_type'  => 'STDIO',
            'mode'         => 'rb',
            'unread_bytes' => 0,
            'seekable'     => true,
            'uri'          => $fileName,
        ];

        $actual = $stream->getMetadata();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: getMetadata() - by key
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-10
     */
    public function httpMessageStreamGetMetadataByKey(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Stream - getMetadata() - by key - ' . $example[0]);
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $handle   = fopen($fileName, 'rb');
        $stream   = new Stream($handle);

        $actual = $stream->getMetadata($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            ['timed_out', false,],
            ['blocked', true,],
            ['eof', false,],
            ['wrapper_type', 'plainfile',],
            ['stream_type', 'STDIO',],
            ['mode', 'rb',],
            ['unread_bytes', 0,],
            ['seekable', true,],
            ['uri', dataFolder('/assets/stream/bill-of-rights.txt'),],
            ['unknown', [],],
        ];
    }
}
