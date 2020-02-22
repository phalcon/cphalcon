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

namespace Phalcon\Test\Unit\Http\Message\Stream;

use Phalcon\Http\Message\Stream;
use UnitTester;
use function dataDir;

class SetStreamCest
{
    /**
     * Unit Tests Phalcon\Http\Message\Stream :: setStream()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function httpMessageStreamSetStream(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - setStream()');

        $fileName = dataDir('assets/stream/mit-empty.txt');
        $stream   = new Stream($fileName, 'rb');

        $actual   = $stream->read(10);
        $I->assertEmpty($actual);

        $fileName = dataDir('assets/stream/mit.txt');
        $stream->setStream($fileName, 'rb');

        $stream->seek(64);
        $expected = 'Permission is hereby granted, free of charge, to any '
            . 'person obtaining a copy of this software and associated '
            . 'documentation files (the "Software"), to deal in the '
            . 'Software without restriction, including without limitation '
            . 'the rights to use, copy, modify, merge, publish, distribute, '
            . 'sublicense, and/or sell copies of the Software, and to permit '
            . 'persons to whom the Software is furnished to do so, subject '
            . 'to the following conditions:';
        $actual   = $stream->read(432);
        $I->assertEquals($expected, $actual);
    }
}
