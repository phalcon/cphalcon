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
use Phalcon\Tests\Fixtures\Http\Message\StreamFixture;
use UnitTester;

class GetMetadataCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: getMetadata()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamGetMetadata(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - getMetadata()');
        $fileName = dataDir('assets/stream/mit.txt');
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
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-10
     */
    public function httpMessageStreamGetMetadataByKey(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Stream - getMetadata() - by key - ' . $example[0]);
        $fileName = dataDir('assets/stream/mit.txt');
        $handle   = fopen($fileName, 'rb');
        $stream   = new Stream($handle);

        $actual = $stream->getMetadata($example[0]);
        $I->assertEquals($example[1], $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: getMetadata() - invalid handle
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-10
     */
    public function httpMessageStreamGetMetadataInvalidHandle(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - getMetadata() - invalid handle');
        $stream = new StreamFixture('php://memory', 'rb');
        $stream->setHandle(null);

        $actual = $stream->getMetadata();
        $I->assertNull($actual);
    }

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
            ['uri', dataDir('assets/stream/mit.txt'),],
            ['unknown', [],],
        ];
    }
}
